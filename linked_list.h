typedef struct n node; 


node *alloc_list(int v); 


void dealloc_list(node *no); 


void push_before_head(node *node_insert, node **head); 


void push_after_node(node *node_insert, node *new_node); 


node *find_node(int v,node *head); 


int pop_list(int v, node **head); 


void print_list(node *list); 