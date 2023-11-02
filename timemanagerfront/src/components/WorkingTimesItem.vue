<template>
  <section>
    <h5>Horaire de travail de {{ username }}</h5>
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
          <tr v-if="workingTimes.length === 0">
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
              <RouterLink
                :to="`/workigTime/${userID}/${workingtime.id}/${username}`"
                class="btn btn-outline-dark"
              >
                Voir
              </RouterLink>
            </td>
          </tr>
        </tbody>
      </table>
    </article>
  </section>
</template>

<script steup>
import config from '../../config'
import axios from 'axios'
import { formatDate } from '../../functions'
import { RouterLink } from 'vue-router'
import { watchEffect } from 'vue'
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
    },
    formattedDate: function (date) {
      return formatDate(date)
    }
    // deleteWorkingTime: async function (id) {
    //   try {
    //     const response = await axios.delete(`${config.back_uri}/workingtimes/${id}`)
    //     this.workingTimes = this.workingTimes.filter((workingtime) => workingtime.id !== id)
    //     this.$notify({
    //       text: 'Les horaires ont été supprimées',
    //       type: 'success'
    //     })
    //   } catch (error) {
    //     this.$notify({
    //       text: "Une erreur s'est produite",
    //       type: 'error'
    //     })
    //   }
    // }
  },
  mounted() {},
  created() {
    this.getWorkingTimes(this.userID)
  }
}
</script>
