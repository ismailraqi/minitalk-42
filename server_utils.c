/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:49:52 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/24 00:00:33 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	enqueue(u_int8_t signal)
{
	t_node *newNode;
	
	newNode = malloc(sizeof(t_node));
	if (!newNode)
		return (-1);
	newNode->signal = signal;
	newNode->next = NULL;

	//if it is the first node
	if(sig_data.queue->head == NULL && sig_data.queue->tail == NULL)
		//make both front and rear points to the new node
		sig_data.queue->head = sig_data.queue->tail = newNode;
	else
	{
		//add newnode in rear->next
		sig_data.queue->tail->next = newNode;
		//make the new node as the rear node
		sig_data.queue->tail = newNode;
	}
}

void dequeue()
{
	//used to free the first node after dequeue
	t_node *temp;

	if(sig_data.queue->head == NULL)
		 printf("Queue is Empty. Unable to perform dequeue\n");
	else
	{
		//take backup
		temp = sig_data.queue->head;
		//make the front node points to the next node
		//logically removing the front element
		sig_data.queue->head = sig_data.queue->head->next;
		//if front == NULL, set rear = NULL
		if(sig_data.queue->head == NULL)
			sig_data.queue->tail = NULL;
	   //free the first node
	   free(temp);
	}

}