/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:11:10 by gperfeit          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:22 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
	{
		send_message(pid, message[i]);
		i++;
	}
	send_message(pid, message[i]);
}
