
<template>

</template>

<script lang="ts">
import { defineComponent } from 'vue'
import axios from 'axios' 

/**
 * @component
 * @description Used to display the working times recorded by the API
 */
export default defineComponent({
    name: 'WorkingTimes',
    components: {
    },
    data() {

    },
    methods: {
        
    },
    created() {
        axios.get(process.env.API_URL + '/workingTimes/:userId');
    },
})
</script>                       

<style></style>