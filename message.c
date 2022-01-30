/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naahio <naahio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:37:11 by naahio            #+#    #+#             */
/*   Updated: 2022/01/30 01:42:58 by naahio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_nbr_len(long n)
{
    int size;

    size = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        size++;
    while (n)
    {
        n /= 10;
        size++;
    }
    return (size);
}

void    ft_charfill(char *buff, char *str, int *i)
{
    int j;

    j = 0;
    while (str[j])
    {
        buff[(*i)] = str[j];
        j++;
        (*i++);
    }
}


void	ft_numfill(char *buffer, long nbr, int *i)
{
	long	div;

	if (nbr == 0)
	{
		buffer[(*i)++] = '0';
		return ;
	}
	div = 1000000000;
	while (nbr / div == 0)
		div = div / 10;
	while (div > 0)
	{
		buffer[(*i)++] = nbr / div + '0';
		nbr = nbr % div;
		div = div / 10;
	}
}

void	ft_message(long time, int who, char *what)
{
	char	buffer[50];
	long	stamp;
	int		size;
	int		i;

	stamp = ft_time() - time;
	size = ft_nbrlen(stamp) + ft_nbrlen(who) + ft_strlen(what) + 4;
	i = 0;
	ft_numfill(buffer, stamp, &i);
	buffer[i++] = ' ';
	buffer[i++] = '#';
	ft_numfill(buffer, who, &i);
	buffer[i++] = ' ';
	if (who == 0)
		i -= 3;
	ft_charfill(buffer, what, &i);
	buffer[i++] = '\n';
	buffer[i++] = '\0';
	write(1, buffer, size);
}