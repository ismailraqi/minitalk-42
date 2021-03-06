/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:26 by iraqi             #+#    #+#             */
/*   Updated: 2022/06/13 04:56:34 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

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
	int		counter;
	pid_t	pid;
	int		msg_len;
	int		len_done;
	int		is_hands_shaken;
	t_node	*node;
	t_queue	*queue;
}				t_sdata;


t_sdata	sig_data;

void		put_str(char *src);
t_node 		*newNode(u_int8_t signal);
t_queue* 	createQueue();
void 		enQueue(t_queue* queue, int signal);
void 		deQueue(t_queue* queue);
int			decoding_msg_len(void);
pid_t		get_pid_from_arg(char *str);
void		ft_putnbr(int nb);
int			ft_atoi(char str);

#endif