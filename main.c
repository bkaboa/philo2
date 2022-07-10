#include "Includes/philo.h"

static bool	init_thread(t_rules *rules)
{


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

