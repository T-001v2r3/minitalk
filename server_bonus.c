/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:10:55 by gperfeit          #+#    #+#             */
/*   Updated: 2023/02/19 00:09:57 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_handler(int sig, siginfo_t *info, void *ucontent)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)ucontent;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_sigaction = &message_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
}
