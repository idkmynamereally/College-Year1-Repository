#include <stdio.h>
#include <stdlib.h>

int arr_element (int r,int c,int * arr1,int * arr2, int * size1,int * size2);
void arr_multiply (int * arr1, int * arr2, int * sizea1,int * sizea2);

int main(){
    int * arr1;
    int * arr2;
    int sizea1[2];
    int sizea2[2];
    printf("Enter No. Of Rows in Matrix 1 -> ");
    scanf("%d",&sizea1[0]);
    printf("Enter No. Of Columns in Matrix 1 -> ");
    scanf("%d",&sizea1[1]);
    printf("Enter No. Of Rows in Matrix 2 -> ");
    scanf("%d",&sizea2[0]);
    printf("Enter No. Of Columns in Matrix 2 -> ");
    scanf("%d",&sizea2[1]);

    arr1 = malloc((sizea1[0] * sizea1[1]) * sizeof(int));
    arr2 = malloc((sizea2[0] * sizea2[1]) * sizeof(int));

    for (int i = 0; i < (sizea1[0]*sizea1[1]); i++){
        printf("Enter Element [%d] of Matrix 1 -> ",i);
        scanf("%d",&arr1[i]);
    }

    for (int i = 0; i < (sizea2[0]*sizea2[1]); i++){
        printf("Enter Element [%d] of Matrix 2 -> ",i);
        scanf("%d",&arr2[i]);
    }

    char ch;
    printf("\nMatrix 1 x Matrix 2 - (1)\nMatrix 2 x Matrix 1 - (2)\nSelection = ");
    scanf("%c",&ch);
    scanf("%c",&ch);

    switch (ch){
        case '1' :  arr_multiply(arr1,arr2,sizea1,sizea2);
                    break;
        case '2' :  arr_multiply(arr2,arr1,sizea2,sizea1);
                    break;
    }
    return 0;
}


void arr_multiply (int * arr1, int * arr2, int * sizea1,int * sizea2){
    if (sizea1[1] != sizea2[0]){
        printf("\nMatrix Multiplication isn't Possible as Number of Columns in Matrix 1 are not equal to Number of Rows in Matrix 2\n");
        return;
    }

    for (int i = 0; i < sizea1[0]; i++){
        for (int j = 0; j < sizea2[1]; j++){
            printf("%d ",arr_element(i,j,arr1,arr2,sizea1,sizea2));
        }
        printf("\n");
    }
}

int arr_element (int r,int c,int * arr1,int * arr2, int * size1,int * size2){
    int element = 0;
    r = r*(size1[1]);
    for (int i = 0; i < size1[1]; i++){
         element = element + (arr1[r] * arr2[c]);
         r++;
         c = c + size2[1];
    }
    return element;
}
