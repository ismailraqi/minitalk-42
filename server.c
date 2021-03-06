/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:28 by iraqi             #+#    #+#             */
/*   Updated: 2022/06/13 05:02:41 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	on_shaking_hands(int c_pid)
{
	if (sig_data.counter == 7)
	{
		if (kill(c_pid, SIGUSR1) == -1)
			(exit(EXIT_FAILURE), put_str("Client pid does not exist"));
		put_str("CONNECTION ESTABLISHED\n");
		sig_data.is_hands_shaken = 1;
		sig_data.pid = c_pid;
		sig_data.counter = 0;
		sig_data.len_done = 0;
		return;
	}
	sig_data.counter++;
}

void	cath_msg_len(int c_pid, int signo)
{
	if (sig_data.counter == 32)
		(sig_data.len_done = 1, sig_data.counter = 0);
	if (c_pid == sig_data.pid)
	{
		enQueue(sig_data.queue, signo);
		//TODO exit and clear the queue
		sig_data.counter++;
	}
}

void	sig_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;

	if (!sig_data.is_hands_shaken && signo == SIGUSR2)
		on_shaking_hands(siginfo->si_pid);
	if (sig_data.is_hands_shaken)
	{
		if (!sig_data.len_done)
		{
			if (signo == SIGUSR1)
				cath_msg_len(siginfo->si_pid, 1);
			if (signo == SIGUSR2)
				cath_msg_len(siginfo->si_pid, 0);
		}
		if (sig_data.len_done)
		{
			if(decoding_msg_len())
				(put_str("Msg len = "),ft_putnbr(sig_data.msg_len));
		}
	}
}

int	main(int ac, char **av)
{
	struct sigaction t_sigaction;
	(void)av;

	if (ac != 1)
		exit(EXIT_FAILURE);
	printf("Processe ID = %d\n", getpid());
	put_str("Listening\n");
	t_sigaction.sa_flags = SA_NODEFER | SA_SIGINFO;
	sigemptyset(&t_sigaction.sa_mask);
	t_sigaction.sa_sigaction = sig_handler;
	sig_data.queue = createQueue();
	if(sigaction(SIGUSR1, &t_sigaction, NULL) == -1)
		put_str("Error in sigaction\n");
	if(sigaction(SIGUSR2, &t_sigaction, NULL) == -1)
		put_str("Error in sigaction\n");
	while (1)
		pause();
	return (0);
}