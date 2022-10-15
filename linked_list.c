#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <linked_list.h>

typedef struct n{ 
    int v; 
    struct n *prox; 
}; 

node* alloc_list(int v){
    node *novo_no = (node*)malloc(sizeof(node)); 
    novo_no->v = v; 
    novo_no->prox = NULL; 
    return novo_no;  
} 

void dealloc_list(node *no){ 
    node *temp = no; 
    if(temp->prox){ 
        temp = temp->prox;
        dealloc(temp);  
    } 
    free(temp); 
    temp = NULL; 
}

void push_before_head(node *node_insert, node **head){ 
    node_insert->prox = *head;  
    *head  = node_insert;   
} 

void push_after_node(node *node_insert, node *new_node){ 
    new_node->prox = node_insert->prox; 
    node_insert->prox = new_node; 
 
}

node *find_node(int v,node *head){ 
    node *temp = head; 
    while(temp){ 
        if(temp->v == v) return temp; 
        temp = temp->prox; 
    }
    return NULL;
}


int pop_list(int v, node **head){ 
    node *temp = find_node(v, *head); 
    node *list = *head; 
    int x = INT_MIN;
    if (temp){
        while(list->prox != temp)  list = list->prox; 
        list->prox = temp->prox; 
        x = temp->v; 
        dealloc(temp); 
    }
    return x; 
}

void print_list(node *list){
    node *temp = list; 
    while(temp){ 
        printf("%d - ",temp->v);
        temp = temp->prox; 
    }
    printf("\n");
}

int main(){ 
    node *list =  alloc(10);
    node *list2 = alloc(20);  
    node *list3 = alloc(30); 
    push_before_head(list2,&list); 
    push_after_node(list->prox,list3); 
    print_list(list); 
    int a = pop_head(30,&list); 
    
    print_list(list); 

    return 0; 
}