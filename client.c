/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:41:52 by kationg           #+#    #+#             */
/*   Updated: 2025/05/23 00:45:56 by kationg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "libft/libft.h"



int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./minitalk (FID) message");
		exit(0);
	}
	int PID = ft_atoi(argv[1]);
	ft_printf("%i",PID);

}
