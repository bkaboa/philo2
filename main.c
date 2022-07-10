#include "Includes/philo.h"

static bool	init_thread(t_rules *rules)
{
	u_int16_t	i;

	i = 0;
	while (i < rules->philo_args->n_philo)
	{
		pthread
	return (true);
}

int main(int argc, char **argv)
{
	t_rules		rules;

	argv[argc] = NULL;
	if (init_all(argc, argv, &rules) == false)
		return (1);
	if (init_thread(&rules) == false)
		return (1);
	return (0);
}

