/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:48:00 by kationg           #+#    #+#             */
/*   Updated: 2025/05/25 02:02:23 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void signal_ack(int signum, siginfo_t *info, void *res)
{
	(void)res;
	if (signum == SIGUSR1)
		ft_printf("Message was received and acknowledged by %i", info->si_pid);
}

void send_char(int PID, char c)
{
	char	temp;
	int	i;

	i = 0;
	while (i < 8)
	{
		temp = c >> i;
		if (temp & 0x01)
			kill(PID, SIGUSR1);
		else 
			kill(PID, SIGUSR2);
		i++;
		usleep(5000);
	}
}
	
void send_mssg(int PID, char *mssg)
{
	while (*mssg)
	{
		send_char(PID, *mssg);
		mssg++;
	}
	send_char(PID, '\0');
}

int main(int argc, char *argv[])
{
	struct sigaction act;

	if (argc != 3)
	{
		ft_printf("Error! Usage:./client [PID] [message]");
		exit(1);
	}
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	//act.sa_sigaction = &signal_ack;
	sigaction(SIGUSR1, &act, NULL);
	int PID = ft_atoi(argv[1]);
	char *mssg = ft_strdup(argv[2]);
	send_mssg(PID, mssg);
	free(mssg);
}
