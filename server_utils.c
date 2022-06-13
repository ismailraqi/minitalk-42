/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:49:52 by iraqi             #+#    #+#             */
/*   Updated: 2022/06/13 05:02:10 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

// int		enqueue(u_int8_t signal)
// {
// 	t_node *newNode;
// 	newNode = malloc(sizeof(t_node));
// 	if (!newNode)
// 		return (-1);
// 	newNode->signal = signal;
// 	newNode->next = NULL;
// 	if(sig_data.queue->head == NULL && sig_data.queue->tail == NULL)
// 	{
// 		sig_data.queue->head = sig_data.queue->tail = newNode;
// 		sig_data.node = newNode;
// 	}
// 	else
// 	{
// 		sig_data.queue->tail->next = newNode;
// 		sig_data.node = newNode;
// 	}
// 	usleep(50);
// 	return (0);
// }
// void	dequeue()
// {
// 	t_node *temp;
// 	temp = malloc(sizeof(t_node));
// 	if (!temp)
// 		(put_str("malloc dequeue error\n"), exit(EXIT_FAILURE));
// 	if(sig_data.queue->head == NULL)
// 		(put_str("Queue is Empty. Unable to perform dequeue\n"), free(temp), exit(EXIT_FAILURE));
// 	else
// 	{
// 		temp = sig_data.queue->head;
// 		sig_data.queue->head = sig_data.queue->head->next;
// 		put_str("called");
// 		if(sig_data.queue->head == NULL)
// 			sig_data.queue->tail = NULL;
// 		//free(temp);
// 	}
// }

int binary_converter(char *binary, int length)
{
	int decimal = 0;
	int position = 0;
	int index = length - 1;
	
	while (index >= 0)
	{
		decimal = decimal + (ft_atoi(binary[index])) * pow(2, position);
		index--;
		position++;
	}
	return (decimal);
}

int		decoding_msg_len(void)
{
	int		counter;
	int		index;
	char	*binStr;
	
	counter = 32;
	binStr = (char *) malloc(sizeof(char) * 33);
	if (!binStr)
		(put_str("(malloc) Error in decoding msg len\n"), exit(EXIT_FAILURE));
	binStr[counter] = '\0';
	index = 0;
	while (counter-- >= 0)
	{
		//TODO decoding binary to decimal
		if (sig_data.queue->head->signal == 1)
		{
			deQueue(sig_data.queue);
			binStr[index] = '1';
		}
		else if (sig_data.queue->head->signal == 0)
		{
			deQueue(sig_data.queue);
			binStr[index] = '0';
		}
		index++;
	}
	sig_data.msg_len = binary_converter(binStr, 33);
	sig_data.is_hands_shaken = 0;
	return (1);
}