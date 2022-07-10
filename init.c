# include "Includes/philo.h"

static void	init_philos(t_rules *rules)
{
	u_int16_t	i;

	i = 0;
	while (i < rules->philo_arg->n_philo - 1)
	{
		rules->philos[i].r_fork = i;
		rules->philos[i].l_fork = (i + 1) % rules->philo_arg->n_philo;
		rules->philos[i].n_eat = 0;
		rules->philos[i].philo_id = i;
		rules->philos[i].rules = rules;
		rules->philo[i].philo_arg = &(rules->philo_arg);
		pthread_mutex_init(&(rules->philos[i].mutex), NULL);
		pthread_mutex_init(&(rules->philos[i].eat_mutex), NULL);
		pthread_mutex_lock(&(rules->philos[i].eat_mutex));
		++i;
	}
}

static void	init_mutex_rules(t_rules *rules)
{
	u_int16_t	i;

	i = 0;
	pthread_mutex_init(&(rules->message_m), NULL);
	rules->fork_m = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
	while (i < rules->n_philo)
		pthread_mutex_init(&(rules->fork_m[i++]), NULL);
}

static bool	philo_arg_assign(t_philo_args *philo_args, char **argv)
{
	if (write_error(ft_atoi(argv[1], philo_arg->n_philo)) == false)
		return (false);
	if (write_error(ft_atoi(argv[2], philo_arg->n_philo)) == false)
		return (false);
	if (write_error(ft_atoi(argv[3], philo_arg->n_philo)) == false)
		return (false);
	if (write_error(ft_atoi(argv[4], philo_arg->n_philo)) == false)
		return (false);
	if (argv[5])
	{
		if (write_error(ft_atoi(argv[5], philo_arg->n_philo)) == false)
			return (false);
	}

	return (true);
}

bool	init_all(int argc, char **argv, t_rules *rules)
{	
	t_philo_args	philo_args;

	philos->philo_args = &philo_args;
	if (argc != 5 || argc != 6)
		return (write_error(WRONG_N_ARG_M));
	if (philo_arg_assign(philos->philo_args, argv) == false)
		return (false);
	if (!(rules->philo = malloc(sizeof(t_philos) * rules->philo_arg->n_philo)))
		return (write_error(MALLOC_ERROR));
	init_philos(rules);
	init_mutex_rules(rules);
	return (true);
}
