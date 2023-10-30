<script setup>
import { RouterLink, RouterView } from 'vue-router'
import UserView from './views/UserView.vue'
</script>

<template>
  <header>
    <nav class="navbar navbar-expand-lg navbar-light bg-white">
      <div class="container-fluid">
        <a class="navbar-brand" href="#">Timemanager</a>
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
                >Accueil</RouterLink
              >
            </li>
            <li class="nav-item">
              <RouterLink class="nav-link" to="/about">About</RouterLink>
            </li>
          </ul>
        </div>
      </div>
    </nav>
  </header>
  <main class="container mt-5">
    <UserView />
    <RouterView />
  </main>
  <!-- <footer>
    <div class="text-center position-absolute bottom-0 d-flex justify-content-center">
      <p class="text-center">timemanager &copy; tous droit réserver</p>
    </div>
  </footer> -->
</template>

<style scoped></style>
