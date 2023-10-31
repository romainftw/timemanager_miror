<script>
import axios from 'axios'
import config from '../../config'
export default {
  data() {
    return {
      user: {
        username: '',
        email: ''
      }
    }
  },
  methods: {
    createNewUser: async function () {
      try {
        const response = await axios.post(`${config.back_uri}/users`, this.user)
        console.log(response)
        this.$notify({
          text: "L'utilisateur a été rajouté",
          type: 'success'
        })
        this.goBack()
      } catch (error) {
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    goBack() {
      this.$router.go(-1) // Redirige l'utilisateur vers la page précédente
    }
  }
}
</script>
<template>
  <section>
    <h1>créer un nouveau utilisateur</h1>
    <form @submit.prevent="createNewUser">
      <input type="text" v-model="user.name" placeholder="Nom" required />
      <input type="email" v-model="user.email" placeholder="Email" required />
      <button type="submit">Ajouter</button>
    </form>
  </section>
</template>
