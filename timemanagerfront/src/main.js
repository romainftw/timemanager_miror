import './assets/main.css'
import 'bootstrap/dist/js/bootstrap.bundle'

import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
const app = createApp(App)
import Notifications from '@kyvg/vue3-notification'
app.use(router)
app.use(Notifications)
app.mount('#app')
