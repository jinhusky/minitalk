/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:48:00 by kationg           #+#    #+#             */
/*   Updated: 2025/05/27 00:39:28 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static t_status status = READY;

void signal_ack(int signum)
{
	if (signum == SIGUSR2)
		status = READY;
	else
	{
		write(1, "HI", 2);
		write(STDOUT_FILENO, "Message received and acknowledged by server\n", 43);
		status = END;
	}
}

void send_char(int PID, char c)
{
	unsigned char temp;
	int	i;

	i = 0;
	while (i < 8)
	{
		while (status == BUSY)
			usleep(50);
		status = BUSY;
		temp = c >> i;
		if (temp & 0x01)
		{
			if (kill(PID, SIGUSR1) == -1)
			{
				ft_printf("client failed to send SIGUSR1 to %i server", PID);				
				exit(1);
			}
		}
		else
		{
			if (kill(PID, SIGUSR2) == -1)
			{
				ft_printf("client failed to send SIGUSR1 to %i server", PID);				
				exit(1);
			}
		}
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

int check_PID(char *PID)
{
	while (*PID)
	{
		if (!ft_isdigit(*PID))
			return (0);
		PID++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	struct sigaction act;

	if (argc != 3 || !check_PID(argv[1]))
	{
		ft_printf("Error! Usage:./client [PID] [message]");
		exit(1);
	}
	act.sa_handler = signal_ack;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	int PID = ft_atoi(argv[1]);
	char *mssg = ft_strdup(argv[2]);
	send_mssg(PID, mssg);
	while(status != END)
		usleep(50);
	free(mssg);
}
