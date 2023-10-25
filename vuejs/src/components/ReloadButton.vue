<template>
    <button @click="parentReload">        
        <font-awesome-icon icon="fa-solid fa-rotate-right"/>
    </button>
</template>
  
<script>
    export default {
    methods: {
            parentReload() { 
                console.log("reload button")
                this.$emit('reload');
            }
        }
    }
</script>
  
<style>
</style>