import moment from 'moment'
import 'moment/locale/fr'

moment.locale('fr')

export const formatDate = (date = Date.now()) => {
  return moment(date).format('D MMMM YYYY [à] hh:mm A')
}
