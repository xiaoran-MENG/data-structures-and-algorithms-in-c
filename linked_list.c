#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linked_list.h"

Node *create_node(int value)
{
    Node* node = malloc(sizeof *node);
    if (!node) 
    {
        perror("Failed to create node");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void push_front(Node **head, int value)
{
    Node* node = create_node(value);
    node->next = *head;
    *head = node;
}

void remove_node(Node **head, int value)
{
    Node* cursor = *head;
    Node* previous = NULL;
    while (cursor)
    {
        if (cursor->value == value)
        {
            if (previous)
            {
                previous->next = cursor->next;
            }
            else
            {
                *head = cursor->next;
            }

            free(cursor);
            return;
        }

        previous = cursor;
        cursor = cursor->next;
    }
}

Node *find_node(Node *head, int value)
{
    while (head)
    {
        if (head->value == value)
        {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void print_list(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->value);
        head = head->next;
    }

    printf("\n");
}

void free_list(Node *head)
{
    Node* node = NULL;
    while (head)
    {
        node = head;
        head = head->next;
        free(node);
    }
}
