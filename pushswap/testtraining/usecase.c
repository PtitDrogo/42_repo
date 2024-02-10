#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char *x;
	struct Node *next;
} Node;

void insert_end(Node **root, char *value);
void deallocate(Node **root);



int main(int argc, char *argv[])
{
	int i;
	Node *root;
	Node *current;

	// root = malloc(sizeof(Node));
	// if (!root)
	// 	return (1);
	i = 1;
	root = NULL;
	while (i < argc)
	{
		insert_end(&root, argv[i]);
		i++;
	}
	current = root;
	// I traverse the list everytime i add something,
	// probably why the libft function is the way it is
	while (current)
	{
		printf("%s\n", current->x);
		current = current->next;
	}
	deallocate(&root);
	return 0;
}

void insert_end(Node **root, char *value)
{
	Node *new_node = malloc(sizeof(Node));
	Node *current;
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->x = value;
	//set new node immediately (With NULL after !);
	if (!(*root))
	{
		*root = new_node;
		return ;
	}    

	current = *root;
	while (current->next)
	{
		current = current->next;
	}
	// make new_node the last in list
	current->next = new_node;
	return ;
}

void deallocate(Node **root)
{
    Node *current = *root;
    Node *memory_to_free;
    
    while (current)
    {
        memory_to_free = current;
        current = current->next;
        free(memory_to_free);
    }
    // free(*root);
    return ;
}