/*program used to demonstrate polynomial substraction
@Febin Sunny
1-10-2025
Rollno:27
*/

#include<stdio.h>

int a[10],b[10],c[10];             //decalring as global variable
int degree1,degree2,maxdegree;    //decalring as global variable

void display(int degree,int poly[]){    //function to display polynomial
    int i;
    for(i=degree;i>=0;i--){
        if(poly[i]==0)continue;
        if(i!=degree && poly[i] > 0){
            printf("+");
        }
        else if(poly[i]<0){
            printf("-");
        }
        if(poly[i]<0){
            printf("%d",-poly[i]);
        }
        else{
            printf("%d",poly[i]);
        }
        if(i>0){
            printf("x^%d",i);
        }

    }
}

void read(){  //function to read polynomial
    int i;
    printf("Enter the degree of first polynomial\n");
    scanf("%d",&degree1);
    printf("Enter the degree of second polynomial\n");
    scanf("%d",&degree2);

    printf("Enter the coefficients from constant term of first polynomial \n");
    for(i=0;i<=degree1;i++){   //Loop iterates in such a way that it reads from constant term to degree
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&a[i]);
    }
    printf("First polynomial is\n");
    display(degree1,a);

    printf("\nEnter the coefficients from constant term of second polynomial \n");
    for(i=0;i<=degree2;i++){   //Loop iterates in such a way that it reads from constant term to degree
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&b[i]);
    }
    printf("Second polynomial is\n");
   display(degree2,b);

}
void sub(){   //function to substract two polynomial
    int i;
    if(degree1>degree2){     // Find the maximum degree among both polynomials
        maxdegree=degree1;
    }
    else{
        maxdegree=degree2;
    }
    for(i=0;i<=maxdegree;i++){   //Substract coefficients of polynomials term by term
        int d=0,e=0;            // temporary variables to hold coefficients
        if(i<=degree1){        // take coefficient from first polynomial if term exists
            d=a[i]; 
        }
        if(i<=degree2){       // take coefficient from second polynomial if term exists
            e=b[i];
        }
        c[i]=d-e;             // store the sum of coefficients in result array
    }
    printf("\n Difference is \n");
    display(maxdegree,c);

}


int main(){
    read();
    sub();
    return 0;

}