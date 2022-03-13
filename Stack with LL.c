#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * next;
};

struct node * top = NULL;
struct node * ptr = NULL;
struct node *newmaal = NULL;

int isStackEmpty();
void take_node_value(struct node * nodule);
void push();
struct node * pop();
void displayStack ();

int main(){
    int check = 1;
    while (check == 1){
        push();
        displayStack();
        printf("Enter 1 to Push Another Value or 2 to Pop a Value : ");
        scanf("%d",&check);
    }
    while (check == 2){
        pop();
        displayStack();
        printf("Enter 2 to Pop Another Value : ");
        scanf("%d",&check);
    }

return 0;
}

int isStackEmpty(){
    if (top == NULL)
        return 1;
    else
        return 0;
}

void take_node_value(struct node * nodule){
    printf("Enter Node Value to Push: ");
    scanf("%d",&nodule->value);
    nodule->next = NULL;
}

void push(){
    if (isStackEmpty()){
        top = (struct node *)malloc(sizeof(struct node));
        take_node_value(top);
        return;
    }
    newmaal = (struct node *)malloc(sizeof(struct node));
    take_node_value(newmaal);
    newmaal->next = top;
    top = newmaal;
}

struct node * pop(){
    struct node * temp = top;
    top = top->next;
    printf("\nVALUE POPPED : %d\n\n",temp->value);
    return temp;
};

void displayStack (){
    for (ptr = top; ptr != NULL; ptr = ptr->next){
        printf("\t| %d |\n",ptr->value);
    }
}
