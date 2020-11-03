#ifndef NODEH
#define NODEH
struct node {
  int id;
  char name[200];
  struct node *next;
};

void print_list(struct node *Node);

struct node * insert_front(struct node *existing_list, int ID, char *string);

struct node * free_list(struct node *Node);

struct node * remove_node(struct node *front, int data);

struct node * new_node(int ID, char *string);

#endif