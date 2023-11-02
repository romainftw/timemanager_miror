import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import UserView from '../views/UserView.vue'
import WorkingTimes from '../views/WorkingTimes.vue'
import WorkingTime from '../components/workigTimeItem.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView
    },
    {
      path: '/user',
      name: 'user',
      component: UserView
    },
    {
      path: '/workigTime',
      name: 'workigTime',
      component: WorkingTime
    },
    {
      path: '/workigTime/:userID/:name',
      name: 'workigTime',
      component: WorkingTime
    },
    {
      path: '/workingTimes/:userID',
      name: 'workingTimes',
      component: WorkingTimes,
      props: true
    }
  ]
})

export default router
