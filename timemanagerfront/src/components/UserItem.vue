<script>
import axios from 'axios'
import config from '../../config'
import Modale from './ModaleItem.vue'
import WorkingTimes from './WorkingTimesItem.vue' // Modale
import MyNotifications from '../utils/notifications.js'

export default {
  name: 'UserItem',
  components: {
    modale: Modale,
    workingTimes: WorkingTimes
  },
  data() {
    return {
      users: [],
      newUser: {
        user: {
          username: '',
          email: '',
          role: ''
        }
      },
      editUser: {
        user: {
          username: '',
          email: ''
        }
      },
      editUserId: null,
      addingNewUser: false,
      showModale: false,
      modaleData: null,
      showModaleEditUser: false,
      options: [
        { value: 'employee', label: 'Employé' },
        { value: 'manager', label: 'Manager' },
        { value: 'teamLead', label: "Chef d'équipe" },
      ],
    }
  },
  methods: {
    goBack() {
      this.$router.go(-1) // Redirige l'utilisateur vers la page précédente
    },
    fetchUsers: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/users`)
        const users = await response.data.data
        this.users = users
        this.users.sort((a, b) => (a.id > b.id ? 1 : -1))
      } catch (error) {
        MyNotifications.error()
      }
    },
    deleteUser: async function (userID) {
      try {
        const response = await axios.delete(`${config.back_uri}/users/${userID}`)
        this.users = response && this.users.filter((user) => user.id !== userID)
        MyNotifications.success("L'utilisateur a bien été supprimé")
      } catch (error) {
        MyNotifications.error()
      }
    },
    clockAtWorkingTime: async function (userID) {
      try {
        const clock = {user_id: userID}
        const response = await axios.post(`${config.back_uri}/clocks`, {clock})

        if(response){ 
          MyNotifications.success("L'heure a été pointée pour l'utilisateur")
        }
      } catch (error) {
        MyNotifications.error()
      }
    },
    createNewUser: async function () {
      console.log("new user", this.newUser)
      try {
        const response = await axios.post(`${config.back_uri}/users`, this.newUser)
        this.users.push(response.data.data)
        this.newUser.user.username = ''
        this.newUser.user.email = ''
        const userKeys = Object.keys(this.newUser.user)
        userKeys.forEach(key => { // Reset all formFields
          this.newUser[key] = ""
        })
        this.addingUser()
        MyNotifications.success("L'utilisateur a été rajouté")
      } catch (error) {
        MyNotifications.error()
      }
    },
    updateUser: async function () {
      console.log('update')
      try {
        const response = await axios.put(
          `${config.back_uri}/users/${this.editUserId}`,
          this.editUser
        )
        console.log(response)
        this.fetchUsers()
        MyNotifications.success("L'utilisateur a été mis à jour")
        this.showModaleEditUser = !this.showModaleEditUser
      } catch (error) {
        MyNotifications.success("Impossible de mettre à jour l'utilisateur")
      }
    },
    addingUser: function () {
      this.addingNewUser = !this.addingNewUser
    },
    gotoUri: function (event) {
      console.log(event.target.getAttribute('href'))
      this.$router.push(event.target.getAttribute('href'))
    },
    toggleModale: function (userID) {
      this.modaleData = this.users.find((user) => user.id === userID)
      this.showModale = !this.showModale
    },
    toggleModaleEditUser: function (userID) {
      this.users.map((user) => {
        if (user.id === userID) {
          this.editUser.user.email = user.email
          this.editUser.user.username = user.username
        }
      })
      this.editUserId = userID
      this.showModaleEditUser = !this.showModaleEditUser
    }
  },
  created() {
    this.fetchUsers()
  }
}
</script>

<template>
  <section>
    <article class="d-flex justify-content-start align-items-center">
      <h1>Liste des utilisateurs</h1>
      <button class="btn ms-3" @click="addingUser">
        <i class="bi bi-plus-lg fs-6 text-info"></i>
      </button>
    </article>

    <article v-if="addingNewUser">
      <form @submit.prevent="createNewUser">
        <input
          type="text"
          v-model="newUser.user.username"
          class="form-control mt-4"
          placeholder="Nom"
          required
        />
        <input
          type="email"
          v-model="newUser.user.email"
          class="form-control mt-4"
          placeholder="Email"
          autocomplete="off"
          required
        />
        <input
          type="password"
          v-model="newUser.user.password"
          class="form-control mt-4"
          placeholder="Mot de passe"
          autocomplete="new-password"
          required
        />
        <select v-model="newUser.user.role" class="form-control mt-4 select-with-arrow" placeholder="Rôle" >
          <option v-for="option in options" :value="option.value" :key="option.value">{{ option.label }}</option>
        </select>
        <button class="btn btn-info col-12 mt-4" type="submit">Ajouter</button>
      </form>
    </article>

    <article class="mt-5">
      <table class="table">
        <thead>
          <tr>
            <th scope="col">Id</th>
            <th scope="col">Email</th>
            <th scope="col">Pseudo</th>
            <th scope="col" class="text-end"></th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="user in users" :key="user.id">
            <th>{{ user.id }}</th>
            <td>{{ user.email }}</td>
            <td>{{ user.username }}</td>
            <td class="text-end">
              <button type="button" class="btn ms-2" @click="toggleModale(user.id)">
                <i class="bi bi-clock"></i>
              </button>
              <RouterLink :to="`/chartManager/${user.id}`" class="btn">
                <i class="bi bi-graph-up"></i>
              </RouterLink>
              <button class="btn" @click="toggleModaleEditUser(user.id)">
                <i class="bi bi-pencil-square text-warning fs-5"></i>
              </button>
              <button class="btn ms-2" @click="deleteUser(user.id)">
                <i class="bi bi-trash3-fill text-danger"></i>
              </button>
              <button class="btn btn-outline-dark ms-2" @click="clockAtWorkingTime(user.id)">
                badger
              </button>
            </td>
          </tr>
        </tbody>
      </table>
    </article>

    <modale v-bind:show="showModale" v-bind:toggleModale="toggleModale">
      <workingTimes
        v-bind:userID="this.modaleData.id"
        v-bind:username="this.modaleData.username"/>
    </modale>

    <!-- edit user modale  -->
    <modale :show="showModaleEditUser" :toggleModale="toggleModaleEditUser">
      <form @submit.prevent="updateUser()">
        <input
          type="text"
          v-model="editUser.user.username"
          class="form-control mt-4"
          placeholder="Nom"
          required
        />
        <input
          type="email"
          v-model="editUser.user.email"
          class="form-control mt-4"
          placeholder="Email"
          required
        />
        <button class="btn btn-info col-12 mt-4" type="submit">Modifier</button>
      </form>
    </modale>
  </section>
</template>


<style>
.select-with-arrow::after {
  content: '\25BC'; 
  position: absolute;
  top: 50%;
  right: 10px;
  transform: translateY(-50%);
  pointer-events: none;
}
</style>