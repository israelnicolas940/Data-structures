/*ADT linked list*/
typedef struct n node; 

/*Allocate some memory*/
node *alloc_list(int v); 

/*Free the memory allocated*/
void dealloc_list(node *no); 

/*Insert the node before the head*/
void push_before_head(node *node_insert, node **head); 

/*Insert the node after some other node*/
void push_after_node(node *node_insert, node *new_node); 

/*find the node with the value v*/
node *find_node(int v,node *head); 

/*Remove from the list the node with the value v*/
int pop_list(int v, node **head); 

/*Print the linked list, given the head node*/
void print_list(node *list); 