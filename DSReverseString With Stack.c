#include <stdio.h>
#include <stdlib.h>

char * stack = NULL;
int top = -1;

void push (char letter);
void pop();

int main()
{
    char stringy [100];
    stack = (char *)malloc(100*sizeof(char));
    printf("Enter a String : ");
    scanf("%s",stringy);

    char letter = '1';
    for (int i = 0 ; letter != '\0'; i++){
        letter = stringy[i];
        push(letter);
    }

    top--;
    for (top; top != -1; top){
        pop();
    }
    return 0;
}

void push(char letter){
    top++;
    stack[top] = letter;
}

void pop(){
    printf("%c",stack[top]);
    top--;
}
