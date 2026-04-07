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

void insert_at_end(struct Node **head, int value){
	printf("\n--- insert_at_end(%d) called ---\n", value);
	
	struct Node *newNode = create_node(value);
	
	if (newNode == NULL){
		return;
	}
	
	if (*head == NULL) {
		printf("List is empty, new node becomes head. \n");
		*head = newNode;
		return;
	}
	
	struct Node *current = *head;
	
	printf("Traversing list...\n");
	
	while (current->next != NULL) {
		printf("At node with data = %d\n", current->data);
		current = current->next;
	}
	
	printf("last node found: %d\n", current->data);
	current->next = newNode;
	
	printf("New node inserted at end.\n");
}

void insert_after_value(struct Node *head, int target, int value){
	printf("\n--- insert_after_value(target=%d, value=%d) ---\n", target, value);
	
	if (head == NULL){
		printf("List is empty. Cannot insert. \n");
		return;
	}
	
	struct Node *current = head;
	
	while (current != NULL && current->data != target) {
		printf("Checking node: %d\n", current->data);
		current = current->next;
	}
	
	if (current == NULL){
		printf("Value %d not found.\n", target);
		return;
	}
	
	printf("Target found at node with data = %d\n", current->data);
	
	struct Node *newNode = create_node(value);
	
	if (newNode == NULL){
		return;
	}
	
	newNode->next = current->next;
	current->next = newNode;
	
	printf("Inserted %d after %d\n", value, target);
}

int main(void){
	
	struct Node *head = NULL;
	
	insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
	
    print_list(head);

    insert_after_value(head, 20, 25);
    print_list(head);
	
	return 0;
}