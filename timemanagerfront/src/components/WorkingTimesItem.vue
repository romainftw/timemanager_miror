<template>
  <section>
    <h1>Horaire de travail de !!!</h1>
  </section>
</template>

<script>
export default {
  name: 'workingTimes',
  data() {
    return {
      userID: null,
      workingTimes: []
    }
  },
  mthods: {},
  mounted() {
    // this.userID = this.$router.params.userID
    console.log("user id", this.userID)
  }
}
</script>
