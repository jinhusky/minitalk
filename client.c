/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:48:00 by kationg           #+#    #+#             */
/*   Updated: 2025/05/25 22:25:16 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

static t_status status = READY;

void signal_ack(int signum)
{
	if (signum == SIGUSR2)
		status = READY;
	else
	{
		status = READY;
		write(1, "HI", 2);
		write(STDOUT_FILENO, "Message received and acknowledged by server", 43);
	}
}

void send_char(int PID, char c)
{
	char	temp;
	int	i;

	i = 0;
	while (i < 8)
	{
		while(status == BUSY)
			usleep(50);
		status = BUSY;
		temp = c >> i;
		if (temp & 0x01)
			kill(PID, SIGUSR1);
		else 
			kill(PID, SIGUSR2);
		i++;
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
	act.sa_handler = &signal_ack;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	int PID = ft_atoi(argv[1]);
	char *mssg = argv[2];
	send_mssg(PID, mssg);
}
