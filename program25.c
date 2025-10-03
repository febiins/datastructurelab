/*program used to read and display polynomial 
@Febin Sunny
1-10-2025
Rollno:27
*/


#include<stdio.h>
int poly[20];   //decalring as global variable
int degree;     //decalring as global variable

void read(){     //function for reading the polynomial terms 
    int i;
    printf("Enter the degree of polynomial\n");
    scanf("%d",&degree);
    printf("Enter the coefficients from constant term \n");
    for(i=0;i<=degree;i++){   //Loop iterates in such a way that it reads from constant term to degree
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&poly[i]);
    }

}

void dispaly(){      // Function to display polynomial in standard form
    int i;
    for(i=degree;i>=0;i--){      // Loop prints terms from highest degree down to constant
        if(poly[i]==0)continue;  //skips if coefficient is zero
        if(i!=degree && poly[i]>0){    // Handles signs of polynomial
            printf("+");
        }
        else if(poly[i]<0){ 
            printf("-");
        }
        if(poly[i]<0){      // print coefficients
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

int main(){
    read();
    dispaly();
    return 0;
}