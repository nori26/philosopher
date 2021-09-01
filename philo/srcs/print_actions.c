#include "philo.h"

void	actions(t_data *data, int action, int64_t sleeptime)
{
	if (print_status((t_print){data, action}))
		return ;
	mymsleep(sleeptime, data);
}

int64_t	print_status(t_print p)
{
	return (mtx_do_func(&p, &p.data->phi->output, print));
}

int64_t	print(t_print *p)
{
	if (!is_alive(p->data) || !is_hungry(p->data))
		return (1);
	printf(p->data->phi->format[p->action],
		timestamp(p->data, p->action), p->data->phi->width, p->data->num);
	return (0);
}

int64_t	timestamp(t_data *data, int action)
{
	if (action == EAT)
		return (store_start_time(data));
	else
		return (get_msec());
}

void	mymsleep(int64_t msec, t_data *data)
{
	register int64_t	sleeptime;
	register int64_t	start;

	if (!msec)
		return ;
	start = get_usec();
	sleeptime = msec * 1000;
	while (get_usec() - start < sleeptime - 1000 && continue_simulation(data))
		usleep(1000);
	sleeptime = start + sleeptime - get_usec();
	if (sleeptime > 0 && continue_simulation(data))
		usleep(sleeptime);
}
