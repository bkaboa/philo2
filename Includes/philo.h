#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

# define IS_THINKING	0
# define IS_TAKING_FORK	1
# define IS_EATING		2
# define IS_SLEEPING	3

# define INT32_MIN		INT_MIN
# define INT32_MAX		INT_MAX
# define UINT32_MAX		UINT_MAX
# define UINT16_MAX		USHRT_MAX
# define UINT8_MAX		UCHAR_MAX

# define WRONG_N_ARG_M	"invalid number of arguments\n"
# define WRONG_ARG_M	"only number are expected\n"
# define NEGATIVE_ARG	"all arg must be positive number\n"
# define ARG_TOO_BIG	"all arg must be inferior to int max\n"
# define MALLOC_ERROR	"malloc error\n"
# define THINK_M		"think\n"
# define EAT_M			"eat\n"
# define SLEEP_M		"sleep\n"
# define DIED_M			"dead\n"

typedef	char*		t_string;
typedef u_int32_t	t_time;
typedef u_int8_t	t_errno;
typedef char*		t_err_string;

typedef struct s_philo_args
{
	u_int32_t			n_philo;
	t_time				time_to_die;
	t_time				time_to_eat;
	t_time				time_to_sleep;
	t_time				n_must_eat;
}	t_philo_args;

typedef struct s_rules
{
	u_int32_t			all_ate;
	t_time				time_statrt;
	pthread_mutex_t		message_m;
	pthread_mutex_t		*fork_m;
	t_philo_args		*philo_arg;
	struct s_philo		*philos;
}	t_rules;

typedef struct s_philos
{
	u_int16_t			philo_id;
	u_int16_t			r_fork;
	u_int16_t			l_fork;
	u_int32_t			n_eat;
	bool				one_philo_is_dead;
	t_time				time_monitor;
	t_rules				*rules;
	t_philo_args		*philo_arg;
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_mutex;
}	t_philos;

/*
 ******************************	init.c			***
*/
bool	init_all(int argc, char **argv, t_rules *rules);

/*
 ******************************	utils.c			***
*/
t_errno		ft_atoi(t_string str, u_int32_t *ret);
u_int16_t	ft_strlen(t_string str);
bool		write_error(t_err_string err_str);
u_int32_t	get_time(void);

#endif
