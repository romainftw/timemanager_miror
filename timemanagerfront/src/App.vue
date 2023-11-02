<script setup>
import { RouterLink, RouterView } from 'vue-router'
import UserView from './views/UserView.vue'
</script>

<template>
  <header>
    <nav class="navbar navbar-expand-lg navbar-light bg-white">
      <div class="container-fluid">
        <button
          class="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarSupportedContent"
          aria-controls="navbarSupportedContent"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
          <ul class="navbar-nav m-auto mb-2 mb-lg-0">
            <li class="nav-item">
              <RouterLink to="/" class="nav-link active" aria-current="page">Accueil</RouterLink>
            </li>
            <li class="nav-item">
              <RouterLink to="/user" class="nav-link active" aria-current="page"
                >Utilisateurs</RouterLink
              >
            </li>
            <li class="nav-item">
              <RouterLink to="/workigTimes" class="nav-link active" aria-current="page"
                >Horaires</RouterLink
              >
            </li>
          </ul>
          <li class="d-flex">
            <button class="btn btn-outline-info" type="submit">Badger</button>
          </li>
        </div>
      </div>
    </nav>
  </header>
  <main class="container mt-5">
    <RouterView />
    <notifications />
  </main>
</template>

<style scoped></style>
