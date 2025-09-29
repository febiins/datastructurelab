#include<stdio.h>
int poly[20];
int degree;

void read(){
    int i;
    printf("Enter the degree of polynomial\n");
    scanf("%d",&degree);
    for(i=0;i<degree;i++){
        scanf("%d",&poly[i]);
    }

}

void dispaly(){
    int i;
    for(i=degree;i>=0;i--){
        if(poly[i]==0)continue;
        
    }
}

int main(){
    return 0;
}