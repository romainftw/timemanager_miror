<template>
  <div>
    <section class="row justify-content-center">
      <div class="col-12">
        <form @submit.prevent="updateWorkingTime">
          <input type="datetime-local" v-model="showWorkingTime.workingtime.start" class="form-control mt-4" placeholder="Nom" required />
          <input type="datetime-local" v-model="showWorkingTime.workingtime.end" class="form-control mt-4" placeholder="Email" required />
          <button class="btn btn-info col-12 mt-4" type="submit">{{ buttonText }}</button>
        </form>
      </div>
    </section>
  </div>
</template>
  

<script>
import axios from 'axios'
import config from '../../config'
import Modal from './ModaleItem.vue'

export default {
  name: 'workingTime',
  components: {
    modal: Modal
  },
  props: {
    id: workingTimeId,
    start,
    end
  },
  data() {
    return {
      userID: null,
      username: '',
      workingTimeId: null,
      show: false,
      showEditModal: false,
      showWorkingTime: {
        workingtime: {
          start: '',
          end: '',
          user_id: null
        }
      },
      data: {
        workingtime: {
          start: '',
          end: '',
          user_id: null
        }
      },
      buttonText: "Ajouter"
    }
  },
  created() {
    if(id){ // Edit form
      this.buttonText = "Modifier",
      this.showWorkingTime.workingtime.start = this.start
      this.showWorkingTime.workingtime.end = this.end
    }
  },
  methods: {
    getWorkingTime: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/workingtimes/${this.workingTimeId}`)
        this.showWorkingTime.workingtime = response.data.data
      } catch (error) {
        this.$notify({
          text: "impossible de récupérer l'horaire",
          type: 'error'
        })
      }
    },
    createWorkingTime: async function () {
      console.log(this.data)
      try {
        const response = await axios.post(`${config.back_uri}/workingtimes`, this.data)
        this.data.workingtime.start = ''
        this.data.workingtime.end = ''
        this.successCbk('Les horaires ont été ajoutées')
      } catch (error) {
        this.$notify({
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
    updateWorkingTime: async function () {
      try {
        const response = await axios.put(
          `${config.back_uri}/workingtimes/${this.workingTimeId}`,
          this.showWorkingTime
        )
        this.showWorkingTime.workingtime = response.data.data
        this.successCbk('Les horaires ont été modifiées')
      } catch (error) {
        this.$notify({
          text: "Impossible de mettre à jour l'horaire de travail",
          type: 'error'
        })
      }
    },
    successCbk (msg) {
      this.$notify({
          text: msg,
          type: 'success'
        })
        this.$emit('callback');
    },
  },
  created() {
    this.userID = this.$route.params.userID
    this.data.workingtime.user_id = parseInt(this.userID)
    this.username = this.$route.params.name
    this.workingTimeId = this.$route.params.id
    this.showWorkingTime.workingtime.user_id = this.userID

    this.getWorkingTime()
  }
}

</script>
<style lang=""></style>
  