/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:28 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/25 04:30:51 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	on_shaking_hands(int signo, int c_pid)
{
	static	int	counter;

	if (counter == 7)
	{
		sig_data.is_hands_shaken = 1;
		put_str("CONNECTION ETABLISHED\n");
		if (kill(c_pid, SIGUSR1) == -1)
			put_str("Client pid does not exist");
		return;
	}
	if (signo == SIGUSR2)
		counter++;
}

void	sig_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	
	if (sig_data.is_hands_shaken != 0)
	{
		if (signo == SIGUSR1)
			if (enqueue(1) != 0)
				exit(EXIT_FAILURE);
				// exit and clear the queue
		if (signo == SIGUSR2)
			if (enqueue(0) != 0)
				exit(EXIT_FAILURE);
				// exit and clear the queue
	}
	else
		on_shaking_hands(signo, siginfo->si_pid);
}

int	main(int ac, char **av)
{
	struct sigaction t_sigaction;
	(void)av;
	
	if (ac != 1)
		exit(EXIT_FAILURE);
	printf("Processe ID = %d\n", getpid());
	put_str("Listening\n");
	t_sigaction.sa_flags = SA_RESTART | SA_NODEFER | SA_SIGINFO;
	sigemptyset(&t_sigaction.sa_mask);
	t_sigaction.sa_sigaction = sig_handler;
	sig_data.queue = malloc(sizeof(t_queue));
	sig_data.queue->head = malloc(sizeof(t_node));
	sig_data.queue->tail = malloc(sizeof(t_node));
	if(sigaction(SIGUSR1, &t_sigaction, NULL) == -1)
		put_str("Error in sigaction\n");
	if(sigaction(SIGUSR2, &t_sigaction, NULL) == -1)
		put_str("Error in sigaction\n");
	while (1){};
	return (0);
}