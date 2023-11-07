<script>
import axios from 'axios'
import config from '../../config'

export default {
  data() {
    return {
      user: {
        email: '',
        password: ''
      },
    }
  },
  methods: {
    login: async function () {
      const data = this.user;

      try {
        const response = await axios.post(`${config.back_uri}/login/`, data)
        console.log(response.data)
        sessionStorage.setItem('token', response.data.token)
        this.$router.push('/')
        MyNotifications.success('Connexion réussie')
        // this.goBack()
      } catch (error) {
        if(error.response.status === 401){
          MyNotifications.error("Identifiants incorrects")
        } else {
          MyNotifications.error("Erreur lors de la requête au serveur")
        }
      }
    },
    goBack() {
      this.$router.go(-1)
    }
  },
}
</script>


<template>
  <section>
    <div class="container">
      <div class="row justify-content-center">
        <div class="col-md-6">
          <div class="card">
            <div class="card-header">Connexion</div>
            <div class="card-body">
              <form @submit.prevent="login" autocomplete="off">
                <div class="form-group">
                  <label for="email">Nom d'utilisateur :</label>
                  <input type="text" class="form-control" id="email" v-model="user.email" />
                </div>
                <div class="form-group">
                  <label for="password">Mot de passe :</label>
                  <input type="password" class="form-control" id="password" v-model="user.password" />
                </div>  
                <button type="submit" class="btn btn-primary mt-3 ml-auto right-0 text-right">Se connecter</button>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
</template>
