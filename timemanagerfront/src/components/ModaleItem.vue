<template>
  <section class="bloc-modale" v-if="show">
    <div class="overlay" @click="toggleModale"></div>
    <div class="modale card">
      <div class="modale-content">
        <slot></slot>
      </div>
      <button class="btn-close-modale btn" @click="toggleModale">
        <i class="bi bi-x-square-fill text-danger"></i>
      </button>
    </div>
  </section>
</template>
<script>
export default {
  name: 'Modale',
  props: ['show', 'toggleModale']
}
</script>
<style scoped>
.bloc-modale {
  display: flex;
  justify-content: center;
  align-items: center;
}
.overlay {
  background-color: rgba(0, 0, 0, 0.6);
}
.overlay,
.bloc-modale {
  position: fixed;
  top: 0;
  bottom: 0;
  right: 0;
  left: 0;
}
.modale {
  position: relative;
  padding: 50px;
  overflow-y: auto;
  max-width: 80%;
  max-height: 90%;
}

.btn-close-modale {
  position: absolute;
  top: 10px;
  right: 10px;
}
</style>
