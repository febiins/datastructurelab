#include<stdio.h>
#include<stdlib.h>

 typedef struct poly{
    int coeff;
    int exponen;
} term;
term a[10];
int n;
void read(){
    int i;
    printf("\nEnter the number of terms\n");
    scanf("%d",&n);
    printf("Enter the polynomial\n");
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].coeff,&a[i].exponen);
    }

}

void print(){
    int c,e;
    for(int i=0;i<n;i++){
         c=a[i].coeff;
         e=a[i].exponen;
         
         if(c==0)
            continue;
        int a =abs(c);
         
         if(i!=0){
         if(c>0){
            printf("+");
         }else{
            printf("-");
         }
        }else{
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
            }else{
                printf("%dx",a);
            }
         }
         else{
            if (a==1){
            printf("x^%d",e);
            }
         else{
            printf("%dx^%d",a,e);
         }

    }
   
}
}

int main(){
    read();
    print();
    return 0;
}