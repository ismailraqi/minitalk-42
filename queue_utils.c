/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 04:09:14 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/28 02:10:53 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_node *newNode(u_int8_t signal)
{
	t_node* temp;
	
	temp = (t_node*) malloc(sizeof(t_node));
	if (!temp)
		return (NULL);
	temp->signal = signal;
	temp->next = NULL;
	return temp;
}

t_queue* createQueue()
{
	t_queue* queue;
	
	queue = (t_queue *) malloc(sizeof(t_queue));
	if (!queue)
		return (NULL); //TODO DO someting here
	queue->head = queue->tail = NULL;
	return queue;
}

void enQueue(t_queue* queue, int signal)
{
	t_node* temp;
	
	temp = newNode(signal);
	if (!temp)
		return; //TODO exit here
	if (queue->tail == NULL && queue->head == NULL) {
		queue->head = queue->tail = temp;
		return;
	}
	queue->tail->next = temp;
	queue->tail = temp;
}

void deQueue(t_queue* queue)
{

	t_node* temp;
	if (queue->head == NULL)
		return;
	temp = queue->head;
	queue->head = queue->head->next;
	if (queue->head == NULL)
		queue->tail = NULL;
	if (temp)
		free(temp);
}
