/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkankan <tkankan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:00:36 by tkankan           #+#    #+#             */
/*   Updated: 2022/08/30 15:32:32 by tkankan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = (i * 10) + (*str - 48);
		str++;
	}
	return (i);
}

void	sendsignal(int pid, char *str)
{
	int	say;

	while (*str)
	{
		say = 8;
		while (say--)
		{
			if ((*str >> say) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
		str++;
	}
}

int	main(int ac, char **ag)
{
	if (ac != 3)
		write(1, "Ac error!\n", 10);
	else
		sendsignal(ft_atoi(ag[1]), ag[2]);
}
