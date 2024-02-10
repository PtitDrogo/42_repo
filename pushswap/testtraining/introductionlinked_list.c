// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node 
// {
//     int x;
//     struct Node   *next;
// } Node;

// int main(int argc, char *argv[])
// {
//     Node root;
//     root.x = 15;
//     root.next = malloc(sizeof(Node));
//     root.next->x = -2;
//     root.next->next = NULL;
//     Node    *curr = &root;
//     while (curr != NULL)
//     {
//         printf("%d\n", curr->next);
//         curr = curr->next;
//     }
//     return (0);
// }