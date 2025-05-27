/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:16:31 by kationg           #+#    #+#             */
/*   Updated: 2025/05/27 12:37:35 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

void	signal_handler(int signum, siginfo_t *info, void *res)
{
	static unsigned char	character;
	static int				bits;

	(void)res;
	if (signum == SIGUSR1)
		character |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		write(STDOUT_FILENO, &character, 1);
		if (character == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		character = 0;
		bits = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID: %i\n", getpid());
	act.sa_sigaction = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
		pause();
	return (0);
}
