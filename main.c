/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naahio <naahio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:22:54 by marvin            #+#    #+#             */
/*   Updated: 2022/01/28 03:22:48 by naahio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	eat(void *param)
{
	
}

void	death(void *param)
{

}

void	do_action(void	*param)
{
	pthread_t	turn;
	t_data		*data;

	data = (t_data *)param;
	pthread_create(&turn, NULL, death, data);
	if (data->me % 2 == 0)
		ft_usleep((float)data->time_to_eat * 0.9 + 1);
	while (data->numb_of_time_to_eat == -1 || data->numb_of_time_to_eat > data->numb_of_eating)
	{
		pthread_mutex_lock(&data->fork);
		msg(data->time_to_start, data->me, "got Fork");
		pthread_mutex_lock(data->prev);
		msg(data->time_to_start, data->me, "got Fork");
		data->last_eating_time = ft_get_time();
		msg(data->time_to_start, data->me, "is Eating");
		ft_usleep(data->time_to_eat);
		pthread_mutex_unlock(&data->fork);
		pthread_mutex_unlock(&data->prev);
		data->numb_of_eating++;
		msg(data->time_to_start, data->me, "is Sleeping");
		ft_usleep(data->time_to_sleep);
		msg(data->time_to_sleep, data->me, "is Thinking");
	}
}

void	set_ation(t_data *data)
{
	pthread_mutex_t	status;
	pthread_mutex_t	meal;
	pthread_t		turn;
	int				i;

	data[0].prev = &data[data[0].philo_numb - 1].fork;
	pthread_mutex_init(&status, NULL);
	pthread_mutex_init(&meal, NULL);
	pthread_mutex_lock(&status);
	i = 0;
	while (i < data[0].philo_numb)
	{
		data[i].status = &status;
		data[i].meals = &meal;
		pthread_create(&turn, NULL, do_action, &data[i++]);
	}
	if (data[0].philo_numb > -1)
		pthread_create(&turn, NULL, eat, &data[0]);
	pthread_mutex_lock(&status);
	i = 0;
	while (i < data[0].philo_numb)
		pthread_mutex_destroy(&data[i++].fork);
	pthread_mutex_destroy(&status);
	pthread_mutex_destroy(&meal);
	free(data);
}

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
			data[i].prev = &data[i - 1].fork;
		if (argc == 6)
			data[i].numb_of_time_to_eat = ft_atoi(argv[5]);
		data[i].philo_numb = ft_atoi(argv[1]);
		data[i].time_to_die = ft_atoi(argv[2]);
		data[i].time_to_eat = ft_atoi(argv[3]);
		data[i].time_to_sleep = ft_atoi(argv[4]);
		data[i].time_to_start = get_time();
		data[i].last_eating_time = data[i].time_to_start;
		data[i].numb_of_eating = 0;
		data[i].me = i + 1;
		i++;
	}
	set_action(data);
	return (0);
}