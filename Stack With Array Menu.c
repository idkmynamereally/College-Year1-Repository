#include <stdio.h>
#include <stdlib.h>

int * stack = NULL;
int top = -1;


int main()
{
    int repeat = 1;
    int size;
    printf("Enter Size of Stack : ");
    scanf("%d",&size);
    stack = (int *)malloc(size*sizeof(int));

    while (repeat){
        printf("Push - 1\nPop - 2\nDisplay - 3\nExit - 4\n");
        scanf("%d",&repeat);
        switch (repeat){
        case 1 : push(size);
                 break;
        case 2 : pop(size);
                 break;
        case 3 : display();
                 break;
        case 4 : return 0;
        }
    }
    return 0;
}

void push(int size){
    if (top >= size-1){
        printf("\nStack is FULL...Returning\n\n");
        return;
    }
    top++;
    printf("Enter New Value To Push : ");
    scanf("%d",&stack[top]);
}

void pop(int size){
    if (top < 0){
        printf("\nStack is Empty...Returning\n\n");
        return;
    }
    printf("\nTop Element : %d\n\n",stack[top]);
    top--;
}

void display(){
    for (int i = top; i >= 0; i--){
        printf("\t[ %d ]\n",stack[i]);
    }
}
