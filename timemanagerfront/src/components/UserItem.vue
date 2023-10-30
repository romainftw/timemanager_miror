<script>
import axios from 'axios'

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
        const response = await axios.get(`http://localhost:4000/api/users`)
        console.log(response)
        const users = await response.data.data
        this.users = users
      } catch (error) {
        console.log(error)
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
      <button class="btn ms-2"><i class="bi bi-plus-circle-fill text-warning"></i></button>
    </article>
    <article></article>
  </section>
</template>
