#include<stdio.h>
#include<stdlib.h>

typedef struct poly{
    int coeff;
    int expo;
}poly;

poly a[10];
void readpoly(){
    int n;
    printf("Enter the number of terms\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].coeff,&a[i].expo);
    }

    int i;
    for(i=0;i<n;i++){
        int c,e;
        c=a[i].coeff;
        e=a[i].expo;
        
        if(c==0)
            continue;
        int ab=abs(c);
        if(i!=0){
            if(c>0){
                printf("+");
            }
            else{
                printf("-");
            }
        }
        else{
            if(c<0){
                printf("-");
            }
        }
        if(e==0){
            printf("%d",ab);
        }
        else if(e==1){
            if(ab==1){
                printf("x");
            }else{
                printf("%dx",ab);
            }

        }else{
            if(ab==1){
                printf("x^%d",e);
             }
           else{
            printf("%dx^%d",ab,e);
           }
        }

    }

}

int main(){
    readpoly();
}