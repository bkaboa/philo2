#include "Includes/philo.h"

u_int16_t	ft_strlen(const t_string str)
{
	t_string	temp;

	temp = str;
	while (((u_int8_t)*temp & UINT8_MAX) != 0)
		temp++;
	return (temp - str);
}

t_err_string	ft_atoi(t_string str, u_int32_t *atoi)
{
	if (str[0] == '-')
		return (NEGATIVE_ARG);
	if (str[0] == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (ARG_TOO_BIG);
	if (ft_strlen(str) == 10 && str[9] > '5')
		return (ARG_TOO_BIG);
	while (*str)
	{
		if ('0' < *str || *str > '9')
			return (WRONG_ARG_M);
		atoi = atoi * 10 + (*str - 48);
	}
	return (NULL);
}

u_int32_t	get_time(void)
{
	static struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

bool	write_error(t_err_string err_str)
{
	if (err_str)
	{
		write(1, err_str, ft_strlen(err_str));
		return (false);
	}
	return (true);
}
