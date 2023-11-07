<script>
import axios from 'axios'
import config from '../../config'

export default {
  data() {
    return {
      user: {
        email: '',
        password: ''
      }
    }
  },
  methods: {
    login: async function () {
      sessionStorage.setItem('token', "fake_token")
      this.$router.push('/')
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
              <form @submit="login" autocomplete="off">
                <div class="form-group">
                  <label for="username">Nom d'utiliddddsateur :</label>
                  <input type="text" class="form-control" id="username" v-model="username" />
                </div>
                <div class="form-group">
                  <label for="password">Mot de passe :</label>
                  <input type="password" class="form-control" id="password" v-model="password" />
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
