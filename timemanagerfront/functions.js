import moment from 'moment'
import 'moment/locale/fr'

moment.locale('fr')

// Utils functions

export const formatDate = (date = Date.now(), format) => {
  return moment(date).format(format) //'D MMMM YYYY [à] hh:mm A'
}
