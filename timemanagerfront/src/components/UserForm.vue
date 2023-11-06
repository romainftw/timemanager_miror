<template>
  <div>
    <section class="row justify-content-center">
      <div class="col-12">
        <form @submit.prevent="updateWorkingTime">
          <input 
            type="datetime-local" 
            class="form-control mt-4"
            placeholder="Nom" required />
          <input 
            type="datetime-local" 
            class="form-control mt-4"
            placeholder="Email" required />
          <input 
            type="datetime-local" 
            class="form-control mt-4"
            placeholder="Password" required />
          <button class="btn btn-info col-12 mt-4" type="submit">Ajouter</button>
        </form>
      </div>
    </section>
  </div>
</template>
  
  
<script>
import axios from 'axios'
import config from '../../config'
import Modal from './ModaleItem.vue'
import { formatDate } from '../../functions'

export default {
  name: 'workingTime',
  components: {
    modal: Modal
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
      }
    }
  },
  methods: {
    goBack() {
      this.$router.go(-1) // Redirige l'utilisateur vers la page précédente
    },
    toggleModale: function () {
      this.show = !this.show
    },
    toggleEditModale: function () {
      this.showEditModal = !this.showEditModal
    },

    formattedDate: function (date) {
      return formatDate(date, 'D MMMM YYYY [à] hh:mm A')
    }
  },
  created() {
    this.userID = this.$route.params.userID
    this.data.workingtime.user_id = parseInt(this.userID)
    this.username = this.$route.params.name
    this.workingTimeId = this.$route.params.id
    this.showWorkingTime.workingtime.user_id = this.userID
  }
}
</script>


<style lang=""></style>
  