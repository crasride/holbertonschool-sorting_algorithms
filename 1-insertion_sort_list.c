#include "sort.h"

/**
* insertion_sort_list - sorts doubly linked list in ascending order
* using the Insertion sort
* @list : dobly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp;

	if (list == NULL)
		return;
	head = *list;

	while (head->next != NULL)
	{
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				tmp = head;
				if (head->prev != NULL)
					head->prev->next = tmp->next;
				head->next->prev = tmp->prev;
				head->prev = tmp->next;
				head->next = tmp->next->next;
				head->prev->next = tmp;

				if (head->next != NULL)
					head->next->prev = tmp;

				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
				head = *list;
				break;
			}
			head = head->next;
		}
	}
}
