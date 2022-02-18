#include <stdio.h>
#include <stdlib.h>

void sum_of_arr(int * arr, int * size);
void display(int * arr, int  size);
void insert(int * arr, int * size);
void delete_(int * arr, int * size);
void copy(int * arr1, int * arr2, int * sizea1, int* sizea2);
void merge(int * arr1,int * arr2, int * arr3,int *sizea1,int* sizea2,int * sizea3);

int main(){

int * arr1;
int * arr2;
int * arr3;
int sizea1,sizea2,sizea3;
printf("Enter Size Of Array 1 = ");
scanf("%d",&sizea1);
printf("Enter Size Of Array 2 = ");
scanf("%d",&sizea2);
arr1 = (int *)malloc(sizea1 * sizeof(int));
arr2 = (int *)malloc(sizea2 * sizeof(int));

printf("Enter Array Elements of Array 1 -> ");
    for (int i = 0 ; i < sizea1; i++){
        scanf("%d",&arr1[i]);
    }
printf("Enter Array Elements of Array 2 -> ");
    for (int i = 0 ; i < sizea2; i++){
        scanf("%d",&arr2[i]);
    }

char character;
    again:
    printf ("\n\nChoose What Action Do You Want TO Perform\nSum Of Array - (1)\nInsert A Element - (2) \nDelete a Element - (3)\nCopy Array 1 to 2 - (4)\nMerge Arrray 1 & 2 - (5)\nDisplay Array - (6)\nquit - (7)\n\nSelection = ");
    scanf("%c",&character);
    scanf("%c",&character);
    printf("\n\n");
    switch (character){
        case '1' : sum_of_arr(arr1, &sizea1);
                   break;
        case '2' : insert(arr1 , &sizea1);
                   break;
        case '3' : delete_(arr1, &sizea1);
                   break;
        case '4' : copy(arr1,arr2,&sizea1,&sizea2);
                   printf("Array 2 -->> ");
                   display(arr2,sizea2);
                   break;
        case '5' : printf("Array 3 -->> ");
                   merge(arr1,arr2,arr3,&sizea1,&sizea2,&sizea3);
                   break;
        case '6' : printf("Array 1 -->> ");
                   display(arr1,sizea1);
                   break;
        case '7' : goto quit;
    }
    goto again;
    quit:
    return 0;
}

void sum_of_arr(int * arr,int * size){
    int sum = 0;
    for (int i = 0; i < *size; i++){
        sum = sum + arr[i];
    }
    printf("Sum Of Array -> %d",sum);
}

void insert(int * arr, int * size){
    int temp[*size];

    for (int i = 0; i < *size; i++){
        temp[i] = arr[i];
    }
    arr = realloc(arr,(*size+1) * sizeof(int));
    int n = 0;
    int index = 0;
    display(arr,*size);
    printf("\nEnter Position To Enter New Element -> ");
    scanf("%d",&index);
    printf("\nEnter Value of New Element -> ");
    scanf("%d",&n);
    int j =0;
    arr[index] = n;
    for (int i = 0; i < *size+1; i++){
        if (i == index){
            continue;
        }
        arr[i] = temp[j];
        j++;
    }
    *size = *size + 1;
    display(arr,*size);
}

void delete_(int * arr,int * size){
    display(arr,*size);
    int index = 0;
    int j = 0;
    printf("\nEnter The Element no. to Delete -> ");
    scanf("%d",&index);
    index--;
    int * temp = (int *)malloc(*size * sizeof(int));
    for(int i = 0 ; i < *size; i++){
        temp[i] = arr[i];
    }
    arr = realloc(arr, (*size-1) * sizeof(int) );

    for (int i = 0; i < *size; i++){
        if(i == index)
            continue;
        arr[j] = temp[i];
        j++;
    }

    *size = *size - 1;
}
void copy (int * arr1, int * arr2, int* sizea1, int* sizea2){
    for (int i = 0; i < *sizea1 ; i++){
        arr2[i] = arr1[i];
    }
}

void merge (int * arr1, int * arr2,int * arr3,int* sizea1, int *sizea2, int * sizea3){
    int totalsize = *sizea1 + *sizea2;
    int j =0;
    arr3 = (int *)malloc(totalsize * sizeof(int));
    for (int i = 0; i < totalsize; i++){
        if(i < *sizea1){
            arr3[i] = arr1[i];
            continue;
        }
        arr3[i] = arr2[j];
        j++;
    }
    *sizea3 = totalsize;
    display(arr3,*sizea3);
}

void display(int * arr, int size){
    for (int i = 0; i < size; i++){
        printf("| %d |",arr[i]);
    }
}

