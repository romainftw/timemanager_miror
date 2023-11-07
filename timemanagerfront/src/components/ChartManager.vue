<template>
  <div class="d-flex justify-content-center">
    <div>
      <!-- <h5>Statistique des horaire du </h5> -->
      <section class="d-flex justify-content-center">
        <Bar
          id="month_hours_chart"
          :options="chartOptions"
          :data="chartMonthData"
          v-if="chartMonthData"
        />
        <div v-else>impossible de récupérer les horaires de travail du mois courant</div>
      </section>
      <div class="row mt-5">
        <section class="col-12 col-md-6 mt-3">
          <Pie
            id="day_hours_chart"
            :options="chartOptions"
            :data="chartDayData"
            v-if="chartDayData"
          />
          <div v-else>impossible de récupérer les horaires de travail du jours</div>
        </section>
        <section class="col-12 col-md-6 mt-3">
          <Doughnut
            id="day_hours_chart"
            :options="chartOptions"
            :data="chartWeekData"
            v-if="chartWeekData"
          />
          <div v-else>impossible de récupérer les horaires de travail de cete semaine</div>
        </section>
      </div>
    </div>
  </div>
</template>
<script>
import axios from 'axios'
import config from '../../config'
import { formatDate } from '../../functions'
import { Bar, Pie, Doughnut } from 'vue-chartjs'
import {
  Chart as ChartJS,
  Title,
  Tooltip,
  Legend,
  BarElement,
  CategoryScale,
  LinearScale,
  ArcElement
} from 'chart.js'
import MyNotifications from '../utils/notifications'

ChartJS.register(ArcElement, Title, Tooltip, Legend, BarElement, CategoryScale, LinearScale)
export default {
  name: 'ChartManager',
  components: {
    Bar: Bar,
    Pie: Pie,
    Doughnut: Doughnut
  },
  data() {
    return {
      userID: null,
      chartWeekData: null,
      chartMonthData: null,
      chartDayData: null,
      chartOptions: {
        responsive: true
      }
    }
  },
  methods: {
    getWorkingHoursByMonth: async function () {
      try {
        const response = await axios.get(
          `${config.back_uri}/workingtimes/month_by_user/${this.userID}`
        )

        const workingHoursData = response.data.data
        this.chartMonthData = {
          labels: workingHoursData.map((data) => formatDate(data.date, 'D MMMM YYYY')),
          datasets: [
            {
              label: 'Heures de travail pour le mois courant ',
              backgroundColor: '#CB7DA9',
              data: workingHoursData.map((data) => data.total_hours)
            }
          ]
        }
      } catch (error) {
        MyNotifications.error('Impossible de récupérer les données par mois')
      }
    },
    getWorkingHoursByDay: async function () {
      try {
        const response = await axios.get(
          `${config.back_uri}/workingtimes/day_by_user/${this.userID}`
        )
        this.chartDayData = {
          labels: ["Heures de travail aujourd'hui"],
          datasets: [
            {
              backgroundColor: ['#6D1145'],
              data: [response.data.data]
            }
          ]
        }
      } catch (error) {
        MyNotifications.error('Impossible de récupérer les données du jour')
      }
    },
    getWorkingHoursByWeek: async function () {
      try {
        const response = await axios.get(
          `${config.back_uri}/workingtimes/week_by_user/${this.userID}`
        )
        const workingWeekData = response.data.data

        this.chartWeekData = {
          labels: workingWeekData.map((data) => formatDate(data.date, 'D MMMM YYYY')),
          datasets: [
            {
              backgroundColor: [
                '#feb07c',
                '#f9ce90',
                '#f9f1da',
                '#b8d1c0',
                '#af97c7',
                '#ec9bb0',
                '#e8ae4a'
              ],
              data: workingWeekData.map((data) => data.total_hours)
            }
          ]
        }
      } catch (error) {
        MyNotifications.error('Impossible de récupérer les données de cette semaine')
      }
    }
  },
  created() {
    this.userID = this.$route.params.userID
    this.getWorkingHoursByMonth(), this.getWorkingHoursByDay(), this.getWorkingHoursByWeek()
  }
}
</script>
<style lang=""></style>
