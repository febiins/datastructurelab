#include<stdio.h>
#include<stdlib.h>

typedef struct polygon{
    int coeff;
    int expo;
}term;
term a[10];
term b[10];
term add[10];
term sub[10];
int n1,n2;
void read(){
    printf("Enter the number of terms\n");
    scanf("%d %d",&n1,&n2);
    printf("Enter the first polynomial\n");
    for(int i=0;i<n1;i++){
    scanf("%d %d",&a[i].coeff,&a[i].expo);
    }
     printf("Enter the second polynomial\n");
    for(int i=0;i<n2;i++){
    scanf("%d %d",&b[i].coeff,&b[i].expo);
    }
}
void printpoly(term p[],int n){
   
        int c,e;
        for(int i=0;i<n;i++){
            c=a[i].coeff;
            e=a[i].expo;

            if(c==0)continue;
            int a=abs(c);
            if(i!=0){
                if(c>0){
                    printf("+");
                }else{
                    printf("-");
                }
                else{
                    if(c<0){
                        printf("-");
                    }
                }
                if(e==0){
                    printf("%d",a);
                }
                else if(e==1){
                    if(a==1){
                        printf("x");
                    }
                    else{
                        printf("%dx",a);
                }

                }else{
                    if(a==1){
                        printf("x^%d",e);
                    }else{
                        printf("%dx^%d",a,e);
                    }
                }
            }
        }
}

void add(term a[],term b[],term add[],int n1,int n2,int *nr){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i].expo > b[j].expo){
            add[k++]=a[i++];
        }
        else if(a[i].expo < b[j].expo){
            add[k++]=b[j++];
        }
        else{
            add[k].coeff=a[i].coeff + b[j].coeff;
            add[k].expo=a[i].expo;
            k++;
            i++;
            j++;
        }

    }
    while(i<n1)add[k++]=a[i++]; 
    while(j<n2)add[k++]=b[j++];
    *nr=k; 
}
void sub(term a[],term b[],term sub[],int n1,int n2,int *nr){
    term nb[10];
    for(int i=0;i<n2;i++){

        nb[i].coeff=-b[i].coeff;
        nb[i].expo=b[i].expo;
    }
    add(a, nb, sub, n1, n2, nr);

}


int main() {
    int ns, nd;
    read();

    add(a, b, add, n1, n2, &ns);
    sub(a, b, sub, n1, n2, &nd);

    printf("First Polynomial: ");
    printpoly(a, n1);
    printf("Second Polynomial: ");
    printpoly(b, n2);
    printf("Sum: ");
    printpoly(add, ns);
    printf("Difference: ");
    printpoly(sub, nd);

    return 0;
}