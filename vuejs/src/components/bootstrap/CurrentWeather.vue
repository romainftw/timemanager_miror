
<template>
    <div>
        <h2>
            Météo actuelle à {{ weather.town }}
        </h2>
        Température: {{ weather.temperature }}°
        <br>
        Date: {{ weather.date }}
    </div>
    <ReloadButton :reload="reloadData"/>
</template>

<script lang="ts">
import { defineComponent } from 'vue'
import ReloadButton from './ReloadButton.vue';

// Bootstrap component
export default defineComponent({

    name: 'CurrentWeather',
    components: {
        ReloadButton
    },
    data() {
        return {
            weather: {
                town: 'Brest',
                temperature: 56,
                date: getFrenchDate()
            }
        };
    },
    methods: {
        reloadData() {
            this.weather.temperature = randomNumber();
        }
    }
})

function getFrenchDate() :string{
    const date = new Date();
    const day = date.getDate();
    const month = date.getMonth() + 1;
    const year = date.getFullYear();
    return `${day.toString().padStart(2, '0')}/${month.toString().padStart(2, '0')}/${year}`;
}

function randomNumber() :number{
    const min = -20;
    const max = 50;
    const nombreAleatoire = Math.random() * (max - min) + min;
    return Math.round(nombreAleatoire);
}   

</script>

<style></style>