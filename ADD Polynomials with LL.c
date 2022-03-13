#include <stdio.h>
#include <stdlib.h> //DEGREE PROBLEM

struct node{
    int coefficient;
    struct node * next;
    int degree;
};

struct node * first1 = NULL;
struct node * ptr = NULL;
struct node * newmaal = NULL;
struct node * added = NULL;
struct node * first2 =  NULL;

void insert_given_at_end(int done,struct node ** first_address,int degree);
void insert_at_end(struct node ** first_address,int degree);
void add_polynomial(struct node * first,struct node * second);
void make_polynomial(int degree,struct node ** first);
void print_polynomial(int degree,struct node ** first);

int main()
{
    int degree1 = 0;
    int degree2 = 0;
    printf("Enter Degree of Polynomial : ");
    scanf("%d",&degree1);

    make_polynomial(degree1,&first1);
    printf("\nPolynomial 1 : ");
    print_polynomial(degree1,&first1);


    printf("\nEnter Degree of Polynomial : ");
    scanf("%d",&degree2);


    make_polynomial(degree2,&first2);
    printf("\nPolynomial 2 : ");
    print_polynomial(degree2,&first2);
    printf("\n ");
    print_polynomial(degree1,&first1);
    printf(" ");
    print_polynomial(degree2,&first2);
    printf(" + \n____________________________________________\n");
    add_polynomial(first1,first2);

return 0;
}

void insert_at_end(struct node ** first_address,int degree){

    if (*first_address == NULL){
        *first_address = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&((*first_address)->coefficient));
        (*first_address)->next = NULL;
        (*first_address)->degree = degree;
    return;
    }

    for (ptr = *first_address; ptr->next != NULL; ptr = ptr->next);
    newmaal = (struct node *)malloc(sizeof(struct node));
    newmaal->next = NULL;
    scanf("%d",&newmaal->coefficient);
    ptr->next = newmaal;
    newmaal->degree = degree;
}

void make_polynomial(int degree,struct node ** first){

    for (int i = degree; i!=-1; i--){
        if (i == 0){
            printf("Enter Coefficient of c : ");
            insert_at_end(first,i);
        return;
        }
        printf("Enter Coefficient of x^%d : ",i);
        insert_at_end(first,i);
    }
}

void print_polynomial(int degree,struct node ** first){
    ptr = (*first);
    for (int i = degree;i != -1; i--,ptr=ptr->next){

        if (ptr->coefficient == 0)
            continue;
        if (i == 0){
            printf("%d = 0\n",ptr->coefficient);
            continue;
        }
        printf("%dx^%d + ",ptr->coefficient,i);
    }
}

void add_polynomial(struct node * first,struct node * second){
    struct node * ptr1 = first;
    struct node * ptr2 = second;

    if (ptr1->degree != ptr2->degree){
        if (ptr1->degree > ptr2->degree){
            for (ptr1; ptr1->degree!= ptr2->degree; ptr1= ptr1->next){
                insert_given_at_end(ptr1->coefficient,&added,ptr1->degree);
            }
        }
        else {
            for (ptr2; ptr2->degree!= ptr1->degree; ptr2= ptr2->next)
                insert_given_at_end(ptr2->coefficient,&added,ptr2->degree);
        }
    }

    for (ptr1; ptr1!=NULL ; ptr1 = ptr1->next,ptr2 = ptr2->next){
        insert_given_at_end(ptr1->coefficient+ptr2->coefficient,&added,ptr1->degree);
    }
    print_polynomial(added->degree,&added);
}

void insert_given_at_end(int done,struct node ** first_address,int degree){

    if (*first_address == NULL){
        *first_address = (struct node *)malloc(sizeof(struct node));
        (*first_address)->coefficient = done;
        (*first_address)->next = NULL;
        (*first_address)->degree = degree;
    return;
    }

    for (ptr = *first_address; ptr->next != NULL; ptr = ptr->next);
    newmaal = (struct node *)malloc(sizeof(struct node));
    newmaal->next = NULL;
    newmaal->coefficient = done;
    ptr->next = newmaal;
    newmaal->degree = degree;
}
