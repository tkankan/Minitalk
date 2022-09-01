/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkankan <tkankan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:53:37 by tkankan           #+#    #+#             */
/*   Updated: 2022/08/30 15:35:53 by tkankan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

void	signal_arrived(int a)
{
	static int	b = 128;
	static char	nstr;

	if (a == SIGUSR1)
		nstr += b;
	b = b / 2;
	if (b == 0)
	{
		write(1, &nstr, 1);
		b = 128;
		nstr = 0;
	}
}

int	main(void)
{
	write(1, "Server Pid:", 11);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_arrived);
	signal(SIGUSR2, signal_arrived);
	while (1)
	{
		pause();
	}
}
