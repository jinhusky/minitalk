/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:16:31 by kationg           #+#    #+#             */
/*   Updated: 2025/05/27 00:24:53 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <unistd.h>

void signal_handler(int signum, siginfo_t *info, void *res)
{
	static int character;
	static int bits;
	
	(void)res;
	if (signum == SIGUSR1)
		character |= (0x01 << bits);
	bits++;
	kill(info->si_pid, SIGUSR2);
	//send signal to client to tell that its ready to receive the next signal
	if (bits == 8)
	{
		write(STDOUT_FILENO, &character, 1);
		if (character == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			//send receipt back to client to acknowledge that the message was received
			kill(info->si_pid, SIGUSR1);
		}
		character = 0;
		bits = 0;
	}
}

int main(void)
{
	ft_printf("PID: %i\n", getpid());

	struct sigaction act;
	act.sa_sigaction = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
    //temporarily add SIGUSR1 to block list so that while SIGUSR2 sigaction is running it wait until SIGUSR2 handler return before receiving SIGUSR1
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while(1)
	{
		pause();
	}
	return (0);
}
