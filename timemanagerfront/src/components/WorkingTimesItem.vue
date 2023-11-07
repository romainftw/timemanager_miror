<!-- 

  Modale pour afficher la liste des horaires de travail d'un utilisateur avec la possibilité d'ajouter un horaire
  Workingtimes for one user modal

-->

<template>
  <section>
    <h5>Horaires de travail de {{ username }}</h5>

    <button class="btn" @click="toggleWorkingTimeModal">
        <i class="bi bi-plus-square text-info"></i>
    </button>
    
    <modal :show="show" >
    </modal>

    <article class="mt-5">
      <table class="table">
        <thead>
          <tr>
            <th scope="col">Du</th>
            <th scope="col">Au</th>
            <th scope="col" class="text-end"></th>
          </tr>
        </thead>
        <tbody>
          <tr v-if="workingTimes.length === 0" class="ml-5">
            pas encore définies
          </tr>
          <tr v-for="workingtime in workingTimes" :key="workingtime.id">
            <td>
              {{ formattedDate(workingtime.start) }}
            </td>
            <td>{{ formattedDate(workingtime.end) }}</td>
            <td class="text-end">
              <!-- <button class="btn"><i class="bi bi-pencil-square text-warning"></i></button>
              <button class="btn ms-2" @click="deleteWorkingTime(workingtime.id)">
                <i class="bi bi-trash3-fill text-danger"></i>
              </button> -->
              <RouterLink :to="`/workingTime/${userID}/${workingtime.id}/${username}`" class="btn btn-outline-dark">
                Voir
              </RouterLink>
            </td>
          </tr>
        </tbody>
      </table>
    </article>
  </section>
</template>

<script>
import config from '../../config'
import axios from 'axios'
import { formatDate } from '../../functions'
import { RouterLink } from 'vue-router'

export default {
  name: 'workingTimes',
  props: ['userID', 'username'],
  data() {
    return {
      workingTimes: []
    }
  },

  methods: {
    getWorkingTimes: async function () {
      if(!this.userID) {
        try {
          const response = await axios.get(`${config.back_uri}/workingtimes`)
          this.workingTimes = response.data.data
          console.log(response.data)
        } catch (error) {
          this.$notify({
            title: 'Erreur',
            text: "Une erreur s'est produite",
            type: 'error'
          })
        }
      } else {
        try {
          const response = await axios.get(`${config.back_uri}/workingtime_by_user/${this.userID}`)
          this.workingTimes = response.data.data
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
    toggleWorkingTimeModal: function () {
      this.showEditModal = !this.showEditModal
    },
    formattedDate: function (date) {
      return formatDate(date, 'D MMMM YYYY [à] hh:mm A')
    }
  },
  mounted() {},
  created() {
    this.getWorkingTimes(this.userID)
  }
}
</script>
