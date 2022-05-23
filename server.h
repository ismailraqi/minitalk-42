/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:26 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/23 23:25:26 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_node
{
	u_int8_t		signal;
	struct s_node	*next;
}				t_node;

typedef	struct	s_queue {
	t_node	*head;
	t_node	*tail;
}				t_queue;

typedef	struct	s_sig_data
{
	pid_t	pid;
	int		msg_len;
	int		is_hands_shaken;
	t_node	*node;
	t_queue	*queue;
}				t_sdata;


t_sdata	sig_data;

void	put_str(char *src);

#endif