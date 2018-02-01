#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * Return: none
 * @list: list of pointers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *mover, *storage, *next, *prev;

	tmp = (*list)->next;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			prev = tmp->prev; storage = tmp->next;
			next = storage->next; tmp->next = next;
			tmp->prev = storage; storage->next = tmp;
			storage->prev = prev;
			if (prev != NULL)
				prev->next = storage;
			if (next != NULL)
				next->prev = tmp;
			if (tmp->prev != NULL)
				mover = tmp->prev;
			tmp = tmp->prev; print_list(*list);
		}
		mover = tmp; tmp = tmp->next;
		while (mover->prev != NULL)
		{
			if (mover->n < mover->prev->n)
			{
				storage = mover->prev; next = mover->next;
				prev = storage->prev; mover->prev = prev;
				mover->next = storage; storage->next = next;
				storage->prev = mover;
				if (next != NULL)
					next->prev = storage;
				if (prev != NULL)
					prev->next = mover;
				if (mover->prev == NULL)
					*list = mover;
				print_list(*list);
			}
			else
				break;
		}
	}
}
