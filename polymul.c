#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int coeff;
    int expo;
}poly;

poly a[10],b[10],add[10];
int n1,n2,nr;

void display(poly p[], int *n) {
    for (int i = 0; i < *n; i++) {
        int c = p[i].coeff;
        int e = p[i].expo;

        if (c == 0) continue; // skip terms with 0 coeff

        // Sign printing
        if (i != 0) { // not first term
            if (c > 0) printf("+");
            else printf("-");
        } else { // first term
            if (c < 0) printf("-");
        }

        int ab = abs(c); // absolute value for printing

        // Coefficient & exponent printing
        if (e == 0) {
            printf("%d", ab);
        } else if (e == 1) {
            if (ab == 1) printf("x");
            else printf("%dx", ab);
        } else {
            if (ab == 1) printf("x^%d", e);
            else printf("%dx^%d", ab, e);
        }
    }
    printf("\n");
}

void read(){
    printf("Enter the number of terms of first polygon\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d %d",&a[i].coeff,&a[i].expo);
        
    }
    display(a,&n1);

     printf("\nEnter the number of terms of second polygon\n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d %d",&b[i].coeff,&b[i].expo);
        
    }
    display(b,&n2);

}



void multipliction(){
    int i=0,j=0,k=0;

   for(i=0;i<n1;i++){
    for(j=0;j<n2;j++){
        add[k].coeff=a[i].coeff*b[j].coeff;
        add[k].expo=a[i].expo + b[j].expo;
        k++;
    }
   }
     nr = k;
   for(int i=0;i<nr;i++){
    for(int j=i+1;j<nr;j++){
        if(add[i].expo == add[j].expo){
            add[i].coeff += add[j].coeff;

            // Shift remaining terms left
            for(int l=j;l<nr-1;l++){
                add[l] = add[l+1];
            }
            nr--;  // reduce number of terms
            j--;   // check this index again after shift
        }
    }
}
        
        display(add,&nr);
    }


int main(){
    read();
    multipliction();
    return 0;

}