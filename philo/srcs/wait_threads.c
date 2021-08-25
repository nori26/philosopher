// #include "philo.h"

// int	wait_end_of_simulation(t_data *data)
// {
// 	if (wait_thread(data, PH))
// 		return (1);
// 	pthread_mutex_unlock(&data->phi->end_of_simulation);
// 	if (wait_thread(data, DC))
// 		return (1);
// 	return (0);
// }

// int	wait_thread(t_data *data, int idx)
// {
// 	int64_t	i;

// 	i = 0;
// 	while (i < data[0].phi->num_of_phi)
// 		if (pthread_join(data[i++].th[idx], NULL))
// 			return (1);
// 	return (0);
// }
