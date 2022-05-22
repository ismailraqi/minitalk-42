/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:26 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/22 21:01:21 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_sig_data
{
	pid_t	pid;
	int		msg_len;
	int		is_hands_shaken;
}				t_sdata;

t_sdata	sig_data;

void	put_str(char *src);

#endif