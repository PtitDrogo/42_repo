#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
} Node;


void insert_end(Node **root, int value);
void deallocate(Node **root);

int main(int argc, char const *argv[])
{
    Node *root = malloc(sizeof(Node));
    if (!root)
        return (1);
    Node *current = root;

    root->x = 15;
    root->next = NULL;
    insert_end(&root, 42);
    insert_end(&root, 422);
    insert_end(&root, 423);
    insert_end(&root, 424);
    while (current)
    {
        printf("%i\n", current->x);
        current = current->next;
    }
    deallocate(&root);
    return 0;
}

void insert_end(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    Node *current = *root;
    if (!new_node)
        return ;
    if (!(*root))
    {
        *root = new_node;
        //as we have seen in usecase.c this assume we set root;
    }    
    //set new node immediately (With NULL after !);
    new_node->next = NULL;
    new_node->x = value;

    while (current->next)
    {
        current = current->next;
    }
    // make new_node the last in list
    current->next = new_node;
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
    // free(root); //I dont do this because I just
    //malloced the first node and root here
    // is on the stack;
    return ;
}