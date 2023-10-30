
<template>

</template>

<script lang="ts">
import { defineComponent } from 'vue'
import axios from 'axios' 

/**
 * @component
 * @description Used for displaying, creating, modifying and deleting a working time
 * Do not confuse with WorkingTimes component
 * linked to the routes:
 * /workingTime/:userid (for creation) ;
 * /workingTime/:userid/:workingtimeid (for modification and deletion).
 */
export default defineComponent({
    name: 'WorkingTime',
    components: {

    },
    data() {

    },
    methods: {
        createWorkingTime() {

        },
        updateWorkingTime() {

        },
        deleteWorkingTime() {
            
        },
    },
    created() {
        axios.get(process.env.API_URL + '/workingTimes/:userId');
    },
})
</script>                       

<style></style>