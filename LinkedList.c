#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node * next;
};


struct node * ptr;
struct node * first;
struct node * new;


void insertnode_to_end();
void takenode(struct node * ptr);
void display_linked_list();
void insertnode_to_start();
void insertnode_to_position(int position);
void delete_node();

int main(){
    int ch = 1;
    int position = 0;
    while (ch == 1){
        insertnode_to_end();
        printf("Press 1 To Add Another Node -> ");
        scanf("%d",&ch);
        printf("\n");
    };
    display_linked_list();
    delete_node();
    display_linked_list();
    
return 0;
}



void insertnode_to_end(){
    if (first == 0){
        first = (struct node *)malloc(sizeof(struct node));
        first->next = 0;
        takenode(first);
    }
    else {
        for(ptr = first; ptr->next != 0 ; ptr = ptr->next);
        new = (struct node *)malloc(sizeof(struct node));
        new->next = 0;
        ptr->next = new;
        takenode(new);
    }
}

void insertnode_to_start(){
    new = (struct node *)malloc(sizeof(struct node));
    new->next = first;
    takenode(new);
    first = new;
}

void insertnode_to_position(int position){
    int posi_counter = 1;
    for (ptr = first; posi_counter != position - 1; ptr = ptr->next){
        posi_counter++;
    }    
    new = (struct node *)malloc(sizeof(struct node));
    new->next = ptr->next;
    ptr->next = new;
    takenode(new);
}

void takenode(struct node * ptr){
    printf("\nEnter A Value To The Node : ");
    scanf("%d",&(ptr->num));
}

void display_linked_list(){
    for (ptr = first; ptr != 0; ptr = ptr->next){
        printf("| %d |",ptr->num);
    }
}

void delete_node(){
    int pos = 1;
    int counter = 1;
    struct node * temp;
    printf("\nEnter Node Position to be Delete : ");
    scanf("%d",&pos);
    for (ptr = first; counter < pos-1; counter++)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
}


//Another Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

struct node * first = NULL;
struct node * ptr = NULL;
struct node * new_ = NULL;

void display_list();
void insert_node_at_end();
struct node * new_node();
void insert_node_at_begin();


int main(){
    int repeat = 1;
    while (repeat == 1){
        insert_node_at_end();
        printf("\nPress 1 To Enter Another Node : ");
        scanf("%d",&repeat);
    }
    insert_node_at_position();
    display_list();

return 0;
}


struct node * new_node(){
        new_ = (struct node *)malloc(sizeof(struct node));
        printf("Enter Value Of Node : ");
        scanf("%d",&new_->value);
        new_->next = NULL;
    return new_;
}

void insert_node_at_end(){
    if (first == NULL){
        first = new_node();
        return;
    }
    for (ptr = first; ptr->next!=NULL; ptr = ptr->next);
    ptr->next = new_node();
}

void display_list(){
    for (ptr = first; ptr!= NULL; ptr = ptr->next){
        printf("| %d |",ptr->value);
    }
}

void insert_node_at_begin(){
    new_ = new_node();
    new_->next = first;
    first = new_;
}

void insert_node_at_position(){
    int position  = 0;
    printf("Position of Node : ");
    scanf("%d",&position);
    ptr = first;
    for (int i = 0; i < position - 2; ptr = ptr->next,i++);
    new_ = new_node();
    new_->next = ptr->next;
    ptr->next = new_;

}
