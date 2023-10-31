<script>
import axios from 'axios'
import config from '../../config'
import { RouterLink } from 'vue-router'
export default {
  data() {
    return {
      users: [],
      newUser: {
        username: '',
        email: ''
      },
      editingUser: null
    }
  },
  methods: {
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
        console.log(`${config.back_uri}/users/${userID}`)
        console.log(response)
        // response && this.fetchUsers()
      } catch (error) {
        console.log(error)
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    editUser: async function (userID) {
      try {
        const response = await axios.post(`${config.back_uri}/users/${userID}`, this.editingUser)
      } catch (error) {
        console.log(error)
      }
    },
    openModal: function (userID) {
      this.editingUser = this.users.find((user) => user.id === userID)
    },
    closeModal: function () {
      this.editingUser = null
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
      <RouterLink to="/user/add" class="btn btn-info ms-3"
        ><i class="bi bi-plus-lg fs-6"></i
      ></RouterLink>
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
              <button class="btn btn-warning"><i class="bi bi-pencil-square"></i></button>
              <button class="btn btn-danger ms-2" @click="deleteUser(user.id)">
                <i class="bi bi-trash3-fill" @click="openModal(user.id)"></i>
              </button>
            </td>
          </tr>
        </tbody>
      </table>
    </article>
  </section>
</template>
