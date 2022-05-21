/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 05:02:21 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/21 05:06:34 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
int	ft_strlen(char *src)
{
	int	i;
	int	j;
	
	i = -1;
	j = 0;
	while (src[++i])
		j++;
	return (j);
}

int	main(int ac, char **av)
{
	int	msg_len;
	
	if (ac != 2)
		exit(EXIT_FAILURE);
	msg_len = ft_strlen(av[1]);
	
}