#include "philo.h"

void	actions(t_data *data, int action, int64_t sleeptime)
{
	if (print_status((t_print){data, action}))
		return ;
	mymsleep(sleeptime);
}

int64_t	print_status(t_print p)
{
	return (mtx_do_func(&p, &p.data->phi->output, print));
}

int64_t	print(t_print *p)
{
	if (p->data->phi->dead || !is_hungry(p->data))
		return (1);
	printf(p->data->phi->format[p->action],
		timestamp(p->data, p->action), p->data->phi->width, p->data->num);
	return (0);
}

int64_t	timestamp(t_data *data, int action)
{
	if (action == EAT)
		return (start_time_init(data));
	else
		return (get_msec());
}
