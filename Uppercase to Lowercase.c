#include <stdio.h>
#include <stdlib.h>

int main(){
    char * string;
    int size = 0;
    printf("Enter Size Of String -> ");
    scanf("%d",&size);
    string = (char *)malloc(size*sizeof(int));
    printf("Enter String -> ");
    scanf("%s",string);
    for (int i = 0; string[i] != '\0';i++){
        if ((string[i] < 97) && (string[i] > 64)){
            string[i] = string[i] + 32;
        }
    }
    printf("%s",string);

return 0;
}
