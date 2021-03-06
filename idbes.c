//PART 1
//
#include <stdio.h>
#include <stdlib.h>

struct complex_no{
    float real_part;
    float image_part;
};

struct complex_no add (struct complex_no c1, struct complex_no c2);
void display_complex (struct complex_no c1);
void display_complex (struct complex_no c1);
void insert_complex (struct complex_no * c1,int number);

int main()
{
    struct complex_no c1 , c2;
    insert_complex(&c1,1);
    insert_complex(&c2,2);
    display_complex(c1);
    display_complex(c2);
    add(c1,c2);
    return 0;
}

struct complex_no add (struct complex_no c1, struct complex_no c2){
    struct complex_no added;
    added.real_part = c1.real_part + c2.real_part;
    added.image_part = c1.image_part + c2.image_part;
    printf("Complex 1 + Complex 2 = %.1f + (%.1f)i\n",added.real_part,added.image_part);
    return added;
};

void display_complex (struct complex_no c1){
    printf("%.1f + (%.1f)i\n",c1.real_part,c1.image_part);
}

void insert_complex (struct complex_no * c1,int number){
    printf("Enter Real Part of Number %d : ",number);
    scanf("%f",&c1->real_part);
    printf("Enter Imaginary Part of Number %d : ",number);
    scanf("%f",&c1->image_part);
}


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
void display_quadratic(struct quad_eq QE,int number);

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
    display_roots(eq1,1);
    display_roots(eq2,2);

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
    printf("\nRoot 1 of Equation %d : %.2f\n",number,QE.root_one);
    printf("Root 1 of Equation %d : %.2f\n",number,QE.root_two);
}

void display_quadratic(struct quad_eq QE,int number){
    printf("Equation %d : (%.2f)x^2 + (%.2f)x + 0\n",number,QE.root_one,QE.root_two);
}
