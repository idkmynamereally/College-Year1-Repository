#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node * next;
};


struct node * ptr;
struct node * first;
struct node * new;

void delete_node_at_start();
void insertnode_to_end();
void takenode(struct node * ptr);
void display_linked_list();
void insertnode_to_start();
void insertnode_to_position();
void delete_node();
void delete_node_at_end();
void insert_nodes();

int main(){
    insertnode_to_start();
    display_linked_list();

    int choice = 0;
    again:
    printf("Insert Nodes - 1\nDelete Nodes - 2\nQuit - 3\nChoice : ");
    scanf("%d",&choice);
    switch (choice){
    case 1 : insert_nodes();
             break;
    case 2 : delete_nodes();
             break;
    case 3 : return;
    }
    goto again;

return 0;
}


void insert_nodes(){
    int ch = 0;
    printf("Insert at Beginning - 1\nInsert at position - 2\nInsert at End - 3\nInsertion Choice : ");
    scanf("%d",&ch);

    switch(ch){
    case 1 :
            while (ch == 1){
            insertnode_to_start();
            display_linked_list();
            printf("Press 1 To Add Another Node To Beginning -> ");
            scanf("%d",&ch);
            printf("\n");
            }
            break;

    case 2 :
            while (ch == 2){
            insertnode_to_position();
            display_linked_list();
            printf("Press 2 To Add Another Node at Position -> ");
            scanf("%d",&ch);
            printf("\n");
            }
            break;
    case 3 :
            while (ch == 3){
            insertnode_to_end();
            display_linked_list();
            printf("Press 3 To Add Another Node to end -> ");
            scanf("%d",&ch);
            printf("\n");
            };
    }
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

void delete_nodes(){
    int ch = 0;
    printf("Delete at Beginning - 1\nDelete at position - 2\nDelete at End - 3\nDeletion Choice : ");
    scanf("%d",&ch);

    switch(ch){
    case 1 :
            while (ch == 1){
            delete_node_at_start();
            display_linked_list();
            printf("Press 1 To Delete Another Node To Beginning -> ");
            scanf("%d",&ch);
            printf("\n");
            }
            break;
    case 2 :
            while (ch == 2){
            delete_node();
            display_linked_list();
            printf("Press 2 To Delete Another Node to The Position -> ");
            scanf("%d",&ch);
            printf("\n");
            }
            break;
    case 3 :
            while (ch == 3){
            delete_node_at_end();
            display_linked_list();
            printf("Press 3 To Delete Another Node at end -> ");
            scanf("%d",&ch);
            printf("\n");
            };
    }
}


void insertnode_to_start(){
    new = (struct node *)malloc(sizeof(struct node));
    new->next = first;
    takenode(new);
    first = new;
}

void insertnode_to_position(){
    int position = 0;
    printf("Enter a Position to Insert at : ");
    scanf("%d",&position);
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
    printf("Enter A Value To The Node : ");
    scanf("%d",&(ptr->num));
}

void display_linked_list(){
    for (ptr = first; ptr != 0; ptr = ptr->next){
        printf("| %d |",ptr->num);
    }
    printf("\n");
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

void delete_node_at_start(){
    struct node * temp;
    temp = first->next;
    free(first);
    first = temp;
}

void delete_node_at_end(){
    int sec_last = 0;
    for (ptr = first; ptr->next!= NULL; ptr = ptr->next){
        sec_last++;
    };
    free(ptr);
    ptr = first;
    for (int i = 0; i<sec_last-1 ; ptr = ptr->next,i++);
    ptr->next = NULL;
}
