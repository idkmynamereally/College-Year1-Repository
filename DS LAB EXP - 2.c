

//PART 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct quad_eq{
    float a;
    float b;
    float c;
    float root_one;
    float root_two;
};

float root_of_eq(struct quad_eq QE,char ch);
void display_roots(struct quad_eq QE,int number);

int main()
{
    float sum_of_roots = 0;
    struct quad_eq common_root_eq;
    float common_root = 0;
    struct quad_eq eq1;
    struct quad_eq eq2;
    struct quad_eq given;
    float SOP = 0;
    printf("Coefficient of x^2 : ");
    scanf("%f",&given.a);
    printf("Coefficient of x : ");
    scanf("%f",&given.b);
    printf("Value of c : ");
    scanf("%f",&given.c);
    printf("Sum Of Product of The Roots : ");
    scanf("%f",&SOP);

    eq1.root_one = root_of_eq(given,'+');
    eq2.root_one = root_of_eq(given,'-');

    common_root_eq.a = 1;
    common_root_eq.b = 2*eq2.root_one;
    common_root_eq.c = ((2*eq1.root_one*eq2.root_one) - SOP);

    common_root = root_of_eq(common_root_eq,'+');

    if ( root_of_eq(common_root_eq,'+') < root_of_eq(common_root_eq,'-') )
        common_root = root_of_eq( common_root_eq , '-');

    eq1.root_two = common_root;
    eq2.root_two = common_root;

    sum_of_roots = eq1.root_one + eq1.root_two + eq2.root_one + eq2.root_two;

    display_quadratic(eq1,1);
    display_quadratic(eq2,2);
    printf("Sum Of Roots : %f", sum_of_roots);

    return 0;
}



float root_of_eq(struct quad_eq QE,char ch){
    float root = 0;
    float temp = 0;
    temp = sqrt( (QE.b*QE.b) - (4*QE.a*QE.c) );

    if (ch == '+'){
        root = (-QE.b + temp)/(2*QE.a);
    }

    else if (ch == '-'){
        root = (-QE.b - temp)/(2*QE.a);
    }
    return root;
}

void display_roots(struct quad_eq QE,int number){
    printf("Root 1 of Equation %d : %.2f\n",QE.root_one,number);
    printf("Root 1 of Equation %d : %.2f\n",QE.root_two,number);
}

void display_quadratic(struct quad_eq QE,int number){
    printf("Equation %d : (%.2f)x^2 + (%.2f)x + 0\n",number,QE.root_one,QE.root_two);
}
