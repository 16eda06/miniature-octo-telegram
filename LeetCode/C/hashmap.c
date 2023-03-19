#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HASH_CAPACITY 100

typedef struct node {
	int key;
	int value;
	struct node *next;
} node;

node* map[HASH_CAPACITY] = {NULL};

int hashcode(int num) {
	return (37 * num + 43) % HASH_CAPACITY;
}

void put(int key, int value) {
	int hash = hashcode(key);
	printf("\nhash(%d) = %d", key, hash);

	if (map[hash] == NULL) {
		map[hash] = malloc(sizeof(node));
		map[hash]->key = key;
		map[hash]->value = value;
	} else {
		node* current = map[hash];
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = malloc(sizeof(node));
		current->next->key = key;
		current->next->value = value;
	}
}

int get(int key) {
	int hash = hashcode(key);
	if (map[hash] != NULL) {
		node* current = map[hash];
		while(current != NULL) {
			if (current->key == key) {
				return current->value;
			}
			current = current->next;
		}
	}
	return INT_MIN;
}

void print_map() {
	int i=0;
	printf("\n-------------------------");
	printf("\n--- Printing Hash Map ---");
	printf("\n-------------------------");
	while (i<HASH_CAPACITY) {
		node* current = map[i];
		if (current != NULL) {
			printf("\n[%3d]=>",i);
		}
		while (current != NULL) {
			printf(" (%3d", map[i]->key);
			printf(",%3d)", map[i]->value);
			current = current->next;
		}
		i++;
	}
}

int main() {
	srand(time(NULL));
	int i = 0;
	while (i<200) {
		int k = rand() % 1000;
		int v = rand() % 1000;
		printf("\nput(%3d, %3d)", k, v);
		put(k,v);
		i++;
		print_map();
	}
}
