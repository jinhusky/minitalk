/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:16:31 by kationg           #+#    #+#             */
/*   Updated: 2025/05/25 02:00:43 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/ft_printf.h"
#include <signal.h>

void signal_handler(int signum, siginfo_t *info, void *res)
{
	static unsigned char character;
	static int bits;
	
	(void)res;
	if (signum == SIGUSR1)
		character |= (0x01 << bits);
	bits++;
	//send signal to client to tell that its ready to receive the next signal
	//kill(info->si_pid, SIGUSR2);
	if (bits == 8)
	{
		ft_printf("%c", character);
		if (character == 0x00)
		{
			ft_printf("\n");
			//ft_printf("Message recieved by server from %i", info->si_pid);
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
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_handler;
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while(1)
	{
		pause();
	}
	return (0);
}
