#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

Node* create_node(int value);
void push_front(Node** head, int value);
void remove_node(Node** head, int value);
Node* find_node(Node* head, int value);
void print_list(Node* head);
void free_list(Node* head);


#endif