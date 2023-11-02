<template>
  <div>
    <button class="btn mb-5" @click="goBack"><i class="bi bi-arrow-left-short"></i> Retour</button>
    <h1 class="text-center mb-5">Ajouter des horaires pour {{ username }}</h1>
    <section class="row justify-content-center">
      <div class="col-12 col-md-8">
        <form @submit.prevent="createWorkingTime">
          <input
            type="datetime-local"
            v-model="data.workingtime.start"
            class="form-control mt-4"
            placeholder="Nom"
            required
          />
          <input
            type="datetime-local"
            v-model="data.workingtime.end"
            class="form-control mt-4"
            placeholder="Email"
            required
          />

          <button class="btn btn-info col-12 mt-4" type="submit">Ajouter</button>
        </form>
      </div>
    </section>
  </div>
</template>
<script>
import axios from 'axios'
import config from '../../config'

export default {
  name: 'workingTime',
  data() {
    return {
      userID: null,
      username: '',
      data: {
        workingtime: {
          start: '',
          end: '',
          user_id: null
        }
      }
    }
  },
  methods: {
    createWorkingTime: async function () {
      console.log(this.data)
      try {
        const response = await axios.post(`${config.back_uri}/workingtimes`, this.data)
        console.log(response)
        this.$notify({
          text: 'Les horaires ont été ajoutées',
          type: 'success'
        })
        // this.goBack()
      } catch (error) {
        this.$notify({
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    updateWorkingTime: function () {},
    deleteWorkingTime: function () {},
    goBack() {
      this.$router.go(-1) // Redirige l'utilisateur vers la page précédente
    }
  },
  created() {
    this.userID = this.$route.params.userID
    this.data.workingtime.user_id = parseInt(this.userID)
    this.username = this.$route.params.name
    console.log(this.userID)
  }
}
</script>
<style lang=""></style>
