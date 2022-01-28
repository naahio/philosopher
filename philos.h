/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naahio <naahio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:23:20 by marvin            #+#    #+#             */
/*   Updated: 2022/01/28 02:22:32 by naahio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t *fork;
    pthread_mutex_t *status;
    pthread_mutex_t *meals;
    pthread_mutex_t *prev;
    long            time_to_start;
    int             me;
    int             last_eating_time;
    int             philo_numb;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             numb_of_eating;
    int             numb_of_time_to_eat;
}t_data;

int	ft_atoi(char *str);
int	check_argv(int argc, char **argv);

#endif