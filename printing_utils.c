/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:26:33 by iraqi             #+#    #+#             */
/*   Updated: 2022/06/13 04:56:58 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_atoi(char str)
{
	int	number;

	number = 0;
	number = (number * 10) + ((int)str - '0');
	return (number);
}

static	void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

void	put_str(char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		write(1, &src[i], 1);
}

void	ft_putnbr(int nb)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb *= -1;
	}
	if (lnb > 9)
	{
		ft_putnbr(lnb / 10);
		ft_putnbr(lnb % 10);
	}
	else
		ft_putchar(lnb + 48);
}