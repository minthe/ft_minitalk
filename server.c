/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:57:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/01/17 15:57:08 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>

void	decode(int bit)
{
	static int		i;
	static char		str;

	if (i < 8)
	{
		str += (bit << i);
		i++;
	}
	if (i == 8)
	{
		if (str == '\0')
		{
			ft_printf("\n");
			i = 0;
			str = 0;
		}
		else
		{
			ft_printf("%c", str);
			i = 0;
			str = 0;
		}
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		decode(1);
	if (signum == SIGUSR2)
		decode(0);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
		pause();
	}
}
