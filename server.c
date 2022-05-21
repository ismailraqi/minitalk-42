/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:25:28 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/21 05:00:05 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	if (signo == SIGUSR1)
	{
		put_str("handler actived\n");
		printf("siginfo content %d", siginfo->si_signo);
	}
}

int main(int ac, char **av)
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
	if(sigaction(SIGUSR1, &t_sigaction, NULL) == -1)
		put_str("Error in sigaction\n");
	pause();
	return (0);
}