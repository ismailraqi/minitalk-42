/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 05:02:21 by iraqi             #+#    #+#             */
/*   Updated: 2022/06/12 05:02:02 by iraqi            ###   ########.fr       */
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

int	send_bit(pid_t pid, int signo, useconds_t m_sec)
{
	if (kill(pid, signo) == -1)
		return (-1);
	usleep(m_sec);
	return (0);
}

int	send_msg_len_to_server(int msg_len, pid_t pid)
{
	int	i;
	int	k;
	
	i = 32;
	while (--i >= 0)
	{
		k = msg_len >> i;
		if (k & 1)
		{
			if (send_bit(pid, SIGUSR1, 500) != 0)
				return (-1);
		}
		else
			if (send_bit(pid, SIGUSR2, 500) != 0)
				return (-1);
	}
	return (0);
}

int	shake_hands(pid_t pid)
{
	int	byte;
	
	byte = -1;
	if (sig_data.is_hands_shaken != 1)
		while (++byte < 8)
			if (send_bit(pid, SIGUSR2, 100) != 0)
				return (0);
	usleep(700);
	return (sig_data.is_hands_shaken == 1);
}

int	pid_checker(pid_t pid)
{
	if (kill(pid, 0) == -1)
		return (-1);
	return (0);
}

pid_t	get_pid_from_arg(char *str)
{
	int		i;
	int		t;
	pid_t	s_id;
	
	if (!str)
		return (-1);
	i = 0;
	s_id = 0;
	t = -1 * (str[i] == '-') + (str[i] == '+');
	i += (t != 0);
	t += (t == 0);
	while (str[i] >= '0' && str[i] <= '9')
		s_id = (i++, 10 * s_id + (str[i - 1] - '0'));
	s_id *= t;
	if (s_id <= 0)
		(put_str("Invalid PID"), exit(EXIT_FAILURE));
	return (s_id);
}

void	c_sig_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	if (siginfo->si_pid == sig_data.pid)
		if (signo == SIGUSR1)
			sig_data.is_hands_shaken = 1;
	put_str("hands shaken\n");
	usleep(300);
	send_msg_len_to_server(sig_data.msg_len, sig_data.pid);
	// TODO: send msg bit by bit to the server ! and sleep program
	
}

int	main(int ac, char **av)
{
	struct	sigaction	sig;

	if (ac != 3)
		(put_str("Error in Arguments"), exit(EXIT_FAILURE));
	sig_data.msg_len = ft_strlen(av[2]);
	sig_data.pid = get_pid_from_arg(av[1]);
	sig.sa_flags = SA_RESTART | SA_NODEFER | SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = c_sig_handler;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		put_str("Error in sigaction\n");
	if (pid_checker(sig_data.pid) != 0 || shake_hands(sig_data.pid) != 0)
		exit(EXIT_FAILURE);
	pause();
}