/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:58:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/01/17 15:58:39 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	itoa(char *s)
{
	int		ret;

	ret = 0;
	while (*s)
	{
		ret = (ret * 10) + (*s - '0');
		s++;
	}
	return (ret);
}

void	encode(char *pid, char *s)
{
	char			*str;
	static int		i;
	static int		x;

	str = s;
	while (str[i])
	{
		while (x < 8)
		{
			if ((str[i] & 1) == 0)
			{
				kill(itoa(pid), SIGUSR2);
				usleep(50);
			}
			if ((str[i] & 1) == 1)
			{
				kill(itoa(pid), SIGUSR1);
				usleep(50);
			}
			str[i] = str[i] >> 1;
			x++;
		}
	x = 0;
	i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || argv[1] <= 0)
	{
		ft_printf("\nPlease provide the Server-PID and 1 String.\n\n");
		return (0);
	}
	if (kill(itoa(argv[1]), 0))
	{
		ft_printf("\nPlease provide the correct Server-PID.\n\n");
		return (0);
	}
	encode(argv[1], argv[2]);
	return (0);
}
