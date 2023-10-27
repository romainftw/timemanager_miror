
<template>

</template>

<script lang="ts">
import { defineComponent } from 'vue'

/**
 * @component
 * @description Used to declare hours worked
 * – connected to the /clock/:username route
 */
export default defineComponent({
    name: 'ClockManager',
    components: {
    },
    data() {
        let startDateTime: Date = new Date();
        let clockIn: boolean = false;
        return {
            startDateTime,
            clockIn
        }
    },
    methods: {
        refresh() {
            this.startDateTime = new Date();
        },
        clock() {
            this.clockIn = !this.clockIn;
        }
    },
    created() {
    },
})
</script>                       

<style></style>