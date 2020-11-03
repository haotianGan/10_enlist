#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
    //Declaring list:
    printf("1. Printing empty list: \n");
    print_list(NULL);
    printf("\n\n2. Adding 0-9 to the list\n\n");
    struct node *list = new_node(0, "hi");
    int i = 1;
    for(i; i < 10; i++) {
        list = insert_front(list, i, "hi");
    }
    print_list(list);
    printf("\n\n3. Removing 9 from the list\n");
    list = remove_node(list, 9);
    print_list(list);
    printf("\n\n4. Removing 0 from the list\n");
    list = remove_node(list, 0);
    print_list(list);
    printf("\n\n5. Removing 5 from the list\n");
    list = remove_node(list, 5);
    print_list(list);
    printf("\n\n6. Removing 4 from the list\n");
    list = remove_node(list, 4);
    print_list(list);
    printf("\n\n7. Freeing list\n");
    list = free_list(list);
    
}