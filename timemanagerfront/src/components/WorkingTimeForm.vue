<!-- 
  Add and edit form for working time
-->

<template>
  <div>
    <section class="row justify-content-center">
      <div class="col-12">
        <form @submit.prevent="createWorkingTime">
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
import MyNotifications from '../utils/notifications'

export default {
  name: 'workingTime',
  components: {
    modal: Modal
  },
  props: ["userId"],
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
    console.log(this.userId)
    //if(id){ // Edit form
    //  this.buttonText = "Modifier",
    //  this.showWorkingTime.workingtime.start = this.start
    //  this.showWorkingTime.workingtime.end = this.end
    //}
  },
  methods: {
    getWorkingTime: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/workingtimes/${this.workingTimeId}`)
        this.showWorkingTime.workingtime = response.data.data
      } catch (error) {
        MyNotifications.error("Impossible de récupérer l'horaire")
      }
    },
    createWorkingTime: async function () {
      try {
        console.log(this.showWorkingTime)
        const response = await axios.post(`${config.back_uri}/workingtimes`, this.showWorkingTime)
        this.data.workingtime.start = ''
        this.data.workingtime.end = ''
        this.successCbk('Les horaires ont été ajoutées')
      } catch (error) {
        MyNotifications.error("Une erreur s'est produite")
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
        MyNotifications.error("Impossible de mettre à jour l'horaire de travail")
      }
    },
    successCbk (msg) {
      MyNotifications.success(msg)
      this.$emit('callback');
    },
  },
  created() {
    this.data.workingtime.user_id = parseInt(this.userId)
    this.username = this.$route.params.name
    this.workingTimeId = this.$route.params.id
    this.showWorkingTime.workingtime.user_id = this.userId

    //this.getWorkingTime()
  }
}

</script>
<style lang=""></style>
