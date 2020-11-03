#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node *Node){
    printf("[");
    while(Node){
        printf("{ID: %d, Name: %s}", Node->id, Node->name);
        Node = Node -> next;
    }
    printf("]");
}

//Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
//The second argument should match whatever data you contain in your nodes.
//Returns a pointer to the beginning of the list.
struct node * insert_front(struct node *existing_list, int ID, char *string){
    struct node *new_front;
    new_front = malloc(sizeof(struct node));

    strncpy(new_front -> name, string, sizeof(string)-1);
    new_front -> id = ID;
    new_front -> next = existing_list;

    return new_front;
}

//Should take a pointer to a list as a parameter 
//and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).
struct node * free_list(struct node *Node){
    struct node *start = Node;
    struct node *ahead = start->next;
    printf("Freed: {ID: %d, Name: %s} \n", start->id, start->name);
    free(start);
    while(ahead){
        start = ahead;
        ahead = start->next;
        printf("Freed: {ID: %d, Name: %s} \n", start->id, start->name);
        free(start);
    }
    
    return Node;
}


//Remove the node containing data from the list pointed to by front.
//If data is not in the list, nothing is changed.
//Returns a pointer to the beginning of the list.

struct node * remove_node(struct node *front, int data){
    if(data == front->id) {
        struct node *output = front->next;
        free(front);
        return output;
    }

    struct node *previous = front;
    struct node *current = front->next;
    while(current){
        if (current->id == data){
            previous->next = current->next;
            free(current);
            return front;
        }
        previous = current;
        current = previous -> next;
    }
    
    return front;
}

//Create new node function (past homework)
struct node * new_node(int ID, char *string){
    struct node *new_front;
    new_front = malloc(sizeof(struct node));

    strncpy(new_front -> name, string, sizeof(string)-1);
    new_front -> id = ID;
    new_front -> next = NULL;

    return new_front;
}
