/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:18:23 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 13:30:11 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

void signal_handler(int signum, siginfo_t *pid, void *context)
{
	static unsigned char character;
	(void) context;
	static int bits = 0;
	if (signum == SIGUSR1)
	{
		character <<= 1;
		character |= 0;
		write(1, "received 0 bit\n", 15);
		kill(pid->si_pid, SIGUSR1);
	}
	else
	{
		character <<= 1;
		character |= 1;
		kill(pid->si_pid, SIGUSR2);
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", (char)character);
		bits = 0;
		character = 0;
	}
}

int main(void)
{
	ft_printf("%i", getpid());
	struct sigaction act;
	act.sa_sigaction = &signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}
