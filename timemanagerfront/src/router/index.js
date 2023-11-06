import { createRouter, createWebHistory } from 'vue-router'
import LoginView from '../views/LoginView.vue'
import HomeView from '../views/HomeView.vue'
import UserView from '../views/UserView.vue'
import WorkingTimes from '../views/WorkingTimes.vue'
import WorkingTime from '../components/workingTimeItem.vue'
import ChartManager from '../components/ChartManager.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/login',
      name: 'login',
      component: LoginView,
      meta: { requiresAuth: false }
    },
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
      path: '/workingTime',
      name: 'workingTime',
      component: WorkingTime
    },
    {
      path: '/workingTime/:userID/:id/:name',
      name: 'workingTime',
      component: WorkingTime
    },
    {
      path: '/chartManager/:userID',
      name: 'chartManager',
      component: ChartManager
    },
    {
      path: '/workingTimes/:userID',
      name: 'workingTimes',
      component: WorkingTimes,
      props: true
    },
    {
      path: '/workingTimes/',
      name: 'workingTimes',
      component: WorkingTimes,
      props: true
    }
  ]
})

function isAuthenticated() {
  const token = sessionStorage.getItem('token') || null; 
  return token !== null;
}

router.beforeEach((to, from, next)=>{
  if (!to.matched.some(record => record.meta.requiresAuth === false)) {
    console.log("router beforeach", isAuthenticated)
    if (!isAuthenticated()) {
      next({
        path: '/login',
        query: { redirect: to.fullPath },
      });
    } else {
      next(); 
    }
  } else {
    next(); 
  }
})

export default router
