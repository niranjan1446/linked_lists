#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void push(struct node** head_ref,int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	
}
void print_linked_list(struct node* head)
{
	struct node* temp = head;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}	
}
void reverse_linked_list(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
    
    if(*head_ref == NULL)
        return;
    
    first = (*head_ref);
    rest = first->next;
    
    if(rest == NULL)
        return;
    
    reverse_linked_list(&rest);
    
    first->next->next = first;
    
    first->next = NULL;
    
    *head_ref = rest;
}

int main(void) {
	struct node* head = NULL;
	push(&head,20);
	push(&head,32);
	push(&head,42);
	push(&head,82);
	printf("Linked list:\n");
	printf("\nPrinting linked list\n");
	print_linked_list(head);
	reverse_linked_list(&head);
	printf("\nPrinting in reverse\n");
	print_linked_list(head);
	return 0;
}
