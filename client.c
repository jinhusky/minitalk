/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:41:52 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 00:08:41 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/libft.h"


void send_char(char *message, int PID)
{
	int	i;
	i = 0;
	while (message[i])
	{

		if ()

		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./minitalk (FID) \"message\"")
		exit(0);
	}
	send_signal(argv[2], argv[1]);

}
