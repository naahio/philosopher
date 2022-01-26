/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:22:54 by marvin            #+#    #+#             */
/*   Updated: 2022/01/26 09:22:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

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
		data[i]
	}
}