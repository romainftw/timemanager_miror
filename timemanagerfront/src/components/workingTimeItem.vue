<template>
  <div>
    <button class="btn mb-5" @click="goBack"><i class="bi bi-arrow-left-short"></i> Retour</button>
    <h5>
      Horaire de travail de {{ username }}

      <button class="btn" @click="toggleModale">
        <i class="bi bi-plus-square text-info"></i>
      </button>
    </h5>

    <!-- create new workingtime modal  -->
    <modal :show="show" :toggleModale="toggleModale">
      <section class="row justify-content-center">
        <div class="col-12">
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
    </modal>
    <!-- end  create new workingtime modal  -->

    <div v-if="showWorkingTime" class="d-flex align-items-baseline">
      <p>
        du {{ formattedDate(showWorkingTime.workingtime.start) }} au
        {{ formattedDate(showWorkingTime.workingtime.end) }}
      </p>
      <button class="btn ms-5">
        <i class="bi bi-pencil-square text-warning" @click="toggleEditModale"></i>
      </button>
      <button class="btn">
        <i class="bi bi-trash3-fill text-danger" @click="deleteWorkingTime"></i>
      </button>
    </div>

    <!-- edit workingtime modal -->
    <!-- Should be a separate component -->
    <modal :show="showEditModal" :toggleModale="toggleEditModale">
      <section class="row justify-content-center">
        <div class="col-12">
          <form @submit.prevent="updateWorkingTime">
            <input
              type="datetime-local"
              v-model="showWorkingTime.workingtime.start"
              class="form-control mt-4"
              placeholder="Nom"
              required
            />
            <input
              type="datetime-local"
              v-model="showWorkingTime.workingtime.end"
              class="form-control mt-4"
              placeholder="Email"
              required
            />
            <button class="btn btn-info col-12 mt-4" type="submit">Editer</button>
          </form>
        </div>
      </section>
    </modal>
    <!-- end edit workingtime modal  -->
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
    getWorkingTime: async function () {
      try {
        const response = await axios.get(`${config.back_uri}/workingtimes/${this.workingTimeId}`)
        this.showWorkingTime.workingtime = response.data.data
      } catch (error) {
        this.$notify({
          text: "imppssible de récupérer l'horaire",
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
    updateWorkingTime: async function () {
      try {
        const response = await axios.put(
          `${config.back_uri}/workingtimes/${this.workingTimeId}`,
          this.showWorkingTime
        )
        this.showWorkingTime.workingtime = response.data.data
        this.toggleEditModale()
        this.$notify({
          text: 'Les horaires ont été modifiées',
          type: 'success'
        })
      } catch (error) {
        this.$notify({
          text: "Impossible de mettre à jour l'horaire de travail",
          type: 'error'
        })
      }
    },
    deleteWorkingTime: async function () {
      try {
        const response = await axios.delete(`${config.back_uri}/workingtimes/${this.workingTimeId}`)
        this.showWorkingTime = null
        this.$notify({
          text: 'Les horaires ont été supprimées',
          type: 'success'
        })
      } catch (error) {
        this.$notify({
          text: "Une erreur s'est produite",
          type: 'error'
        })
      }
    },
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

    this.getWorkingTime()
  }
}
</script>
<style lang=""></style>
