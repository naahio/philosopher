/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naahio <naahio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:22:54 by marvin            #+#    #+#             */
/*   Updated: 2022/01/26 02:19:58 by naahio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	if (!check_argv(argc, argv) || !ft_atoi(argv[1]))
		return (0);
	data = malloc(sizeof(t_data) * ft_atoi(argv[1]));
	if (!data)
		return (0);
	i = 0;
	while (i <ft_atoi(argv[1]))
	{
		pthread_mutex_init(&data[i].fork, NULL);
		data[i].prev = NULL;
		if (i != 0)
			data[i].prev = $data[i - 1].fork;
		if (argc == 6)
			data[i].numb_of_time_to_eat = ft_atoi(argv[5]);
		data[i].philo_numb = ft_atoi(argv[1]);
		data[i].time_to_die = ft_atoi(argv[2]);
		data[i].time_to_eat = ft_atoi(argv[3]);
		data[i].time_to_sleep = ft_atoi(argv[4]);
		data[i].time_to_start = get_time();
		data[i].prev_eat = data[i].time_to_start;
		data[i].numb_of_eating = 0;
		data[i].me = i + 1;
		i++;
	}
	philosopher(data);
	return (0);
}