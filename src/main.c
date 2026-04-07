#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *create_node(int value){
	struct Node *newNode = malloc(sizeof(struct Node));
	
	if (newNode == NULL) {
		printf("ERROR: Memory allocation failed. \n");
		return NULL;
	}
	
	newNode->data = value;
	newNode->next = NULL;
	
	printf("created new node: data = %d, next = NULL\n", value);
	
	return newNode;
	
}

void print_list(struct Node *head){
	struct Node *current = head;
	printf("Current list: ");
	
	while (current != NULL){
		printf("[%d|%p] -> ", current->data,(void*)current->next);
		current = current->next;
	}
	
	printf("NULL\n");
}

void insert_at_beginning(struct Node **head, int value){
	printf("\n---insert_at_beginning(%d) called ---\n", value);
	
	struct Node *newNode = create_node(value);
	
	if (newNode == NULL){
		return;
	}
	
	printf("before insertion, *head = %p\n", (void*)*head);
	
	newNode->next = *head;
	*head = newNode;
	
	printf("after insertion *head = %p\n", (void*)*head);
}


int main(void){
	
	struct Node *head = NULL;
	
	insert_at_beginning(&head, 10);
	print_list(head);
	
	insert_at_beginning(&head, 5);
	print_list(head);
	
	return 0;
}