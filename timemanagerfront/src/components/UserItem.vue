<script>
import axios from 'axios'
import config from '../../config'
export default {
  data() {
    return {
      users: [],
      newUser: {
        username: '',
        email: ''
      }
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
        //const response = await axios.delete(`${config.back_uri}/users/${userID}`)
        
        const headers = {
          'Content-Type': 'application/json'
        };
        axios({
          method: 'delete',
          url: `${config.back_uri}/users/${userID}`, 
          headers: headers 
        })
          .then(response => {
            this.fetchUsers();
            console.log('Réponse de l\'API :', response.data);
          })
          .catch(error => {
            console.error('Erreur de l\'API :', error);
          });

        
        //console.log(`${config.back_uri}/users/${userID}`)
        //console.log(response)
        // response && this.fetchUsers()
      } catch (error) {
        console.log(error)
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
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
      <button class="btn btn-info ms-3"><i class="bi bi-plus-lg fs-6"></i></button>
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
                <i class="bi bi-trash3-fill"></i>
              </button>
            </td>
          </tr>
        </tbody>
      </table>
    </article>
  </section>
</template>
