#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node* next;
} node_t;

void print_list(node_t* head) {
	printf("Here goes the list\n");
	while (head != NULL) {
		printf("%d\n", head->val);
		head = head->next;
	}
}

node_t* push(node_t* head, int value) {
	printf("here1");
	if (head == NULL) {
		head = (node_t*)malloc(sizeof(node_t));
		printf("here1");
		head->val = value;
	} else {
		node_t *current = head;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = (node_t*)malloc(sizeof(node_t));
		current->next->val = value;
	}
	return head;
}

int main(){
	node_t *head = NULL;

	int i = 0;
	while (i<5) {
		head = push(head, i);
		i++;
	}
	print_list(head);
	// print_list(head);
}
