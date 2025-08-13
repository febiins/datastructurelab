#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int coeff;
    int expo;

}term;

term a[10],b[10],diff[10];
int n1,n2;

void display(term p[],int *n){

    for(int i=0;i<*n;i++){
        int c, e;
        c=p[i].coeff;
        e=p[i].expo;

        if(c==0){
            continue;
        }
        int ab= abs(c);
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
            }
            else{
                printf("%dx",ab);
            }
        }
        else{
            if(ab==1)
            {
                printf("x^%d",e);
            }
            else{
                printf("%dx^%d",ab,e);
            }
        }
    }

}


void read(){
    printf("\nEnter the number of terms of polygon one\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
         scanf("%d %d",&a[i].coeff,&a[i].expo);
    }
    display(a,&n1);

     printf("\nEnter the number of terms of polygon two\n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
         scanf("%d %d",&b[i].coeff,&b[i].expo);
    }
display(b,&n2);
   
}



void substraction(){
    term negative[10];
    int k=0,h=0,l=0;
    for(int i=0;i<n2;i++){
        negative[i].coeff=-b[i].coeff;
        negative[i].expo=b[i].expo;
    }
    while(k<n1 && h<n2){
        if(a[k].expo > negative[h].expo){
            diff[l++]=a[k++];
        }
        else if(a[k].expo < negative[h].expo){
            diff[l++]=negative[h++];
        }
        else{
            diff[l].coeff=a[k].coeff + negative[h].coeff;
            diff[l].expo=a[k].expo;
            h++;
            k++;
            l++;
    }
    
    }
    printf("Result is\n");
    display(diff,&l);
}

int main(){
    read();
    substraction();
}