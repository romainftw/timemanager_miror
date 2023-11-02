<script>
import axios from 'axios'
import config from '../../config'
import { RouterLink } from 'vue-router'
import Modale from './ModaleItem.vue'
import WorkingTimes from './WorkingTimesItem.vue'
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
          email: ''
        }
      },
      addNewUser: false,
      showModale: false,
      modaleData: null
    }
  },
  methods: {
    goBack() {
      this.$router.go(-1) // Redirige l'utilisateur vers la page précédente
    },
    fetchUsers: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/users`)

        console.log(response)
        const users = await response.data.data
        this.users = users
      } catch (error) {
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    deleteUser: async function (userID) {
      try {
        const response = await axios.delete(`${config.back_uri}/users/${userID}`)
        this.users = response && this.users.filter((user) => user.id !== userID)
      } catch (error) {
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    createNewUser: async function () {
      console.log(this.newUser)
      try {
        const response = await axios.post(`${config.back_uri}/users`, this.newUser)
        console.log(response)
        this.users.push(response.data.data)
        this.newUser.user.username = ''
        this.newUser.user.email = ''
        this.addUser()
        this.$notify({
          text: "L'utilisateur a été rajouté",
          type: 'success'
        })
      } catch (error) {
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    addUser: function () {
      this.addNewUser = !this.addNewUser
    },

    gotoUri: function (event) {
      console.log(event.target.getAttribute('href'))
      this.$router.push(event.target.getAttribute('href'))
    },
    toggleModale: function (userID) {
      this.modaleData = this.users.find((user) => user.id === userID)
      this.showModale = !this.showModale
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
      <button class="btn ms-3" @click="addUser">
        <i class="bi bi-plus-lg fs-6 text-info"></i>
      </button>
    </article>
    <article v-if="addNewUser">
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
          required
        />
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
              <button class="btn">
                <i class="bi bi-pencil-square text-warning fs-5"></i>
              </button>
              <button class="btn ms-2" @click="deleteUser(user.id)">
                <i class="bi bi-trash3-fill text-danger"></i>
              </button>
            </td>
          </tr>
        </tbody>
      </table>
    </article>

    <modale v-bind:show="showModale" v-bind:toggleModale="toggleModale"
      ><workingTimes
        v-bind:userID="this.modaleData.id"
        v-bind:username="this.modaleData.username"
      ></workingTimes>
    </modale>
  </section>
</template>
