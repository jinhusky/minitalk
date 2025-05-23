/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:41:52 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 12:00:18 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/libft.h"

int signal_char(char c, int PID)
{
	int	i;
	int bits = 0;
	i = 0;
	while (bits < 8)
	{
		char temp = c >> i;
		if (temp % 2 == 0)
			kill(PID, SIGUSR1);
		else 
			kill(PID, SIGUSR2);
		i++;
		bits++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{

	if (argc != 3)
	{
		ft_printf("Usage: ./minitalk (PID) message");
		exit(1);
	}
	int PID = ft_atoi(argv[1]);
	char *mssg = argv[2];

	while (*mssg)
	{
		signal_char(*mssg, PID);
		usleep(100);
		mssg++;
	}

}
