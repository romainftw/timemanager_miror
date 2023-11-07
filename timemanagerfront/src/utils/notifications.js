import { notify } from "@kyvg/vue3-notification";

export default class MyNotifications {
    static success (message) {
      return notify({
        type: 'success',
        text: message
      });
    }
    
      
    static error (message) {
      return notify({
        type: 'error',
        text: message || "Une erreur s'est produite"
      })
    }
}
