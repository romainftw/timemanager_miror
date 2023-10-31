<template>
  <section>
    <h1>Horaire de travail de !!!</h1>
  </section>
</template>

<script>
import config from '../../config'
import axios from 'axios'
export default {
  name: 'workingTimes',
  data() {
    return {
      userID: null,
      workingTimes: []
    }
  },
  methods: {
    getWorkingTimes: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/workingtimes/${this.userID}`)
        console.log(response.data)
      } catch (error) {
        this.$notify({
          title: 'Erreur',
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    }
  },
  mounted() {},
  created() {
    this.userID = this.$route.params.userID
  }
}
</script>
