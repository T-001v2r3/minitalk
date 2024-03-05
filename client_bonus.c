/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:11:10 by gperfeit          #+#    #+#             */
/*   Updated: 2023/02/19 00:17:48 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_confirm(int sig)
{
	(void)sig;
	ft_printf("Message sent successfully!\n");
	exit(1);
}

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
		usleep(80);
	}
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	char				*message;
	struct sigaction	action;

	action.sa_handler = &message_confirm;
	sigaction(SIGUSR1, &action, NULL);
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
	while (1)
	{
		pause();
	}
}
