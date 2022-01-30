/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naahio <naahio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:26:47 by marvin            #+#    #+#             */
/*   Updated: 2022/01/30 01:36:29 by naahio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static	int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\f'
		||c == '\v' || c == '\n' || c == '\r' );
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
	{
		printf("too few argument function !\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("invalid argument !\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_get_time()
{
	struct timeval time_val;

	gettimeofday(&time_val, NULL);
	return (time_val.tv_sec * 1000 + time_val.tv_usec / 1000);
}

void	ft_usleep(int len)
{
	long long time;

	time = ft_get_time();
	while (ft_get_time() < time + len)
		usleep(len);
}

