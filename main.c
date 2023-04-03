

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "functii_1.h"


int secv_crescatoare(STIVA *s,int varf){
    int l=0, lmax=0;
    int x,y;
    
    x=pop(&s, &varf);
    while(varf>=0){
        y=pop(&s, &varf);
        
        if(x<y)l++;
        else l=0;
        
        if(l>lmax)lmax=l;
        x=y;
    }
    return lmax;
}

void Reverse_Polish_Notation(STIVA2 **nr,STIVA2 **op, char v[],char v2[], int *top, int capacity,int *top2, int capacity2){
    int i=0,j=0;
    while (i<7){
        if(v[i]<=57 && v[i]>=48){
            push_char(&(*nr), v[i], capacity, &(*top));
        }
        else {
            if(v[i]=='*' || v[i]=='-' || v[i]=='+'  || v[i]=='/' )
                push_char(&(*op), v[i], capacity2, &(*top2));
            if(v[i]==40){
                while(v[i]!=41){
                    if(v[i]<=57 && v[i]>=48) push_char(&(*nr), v[i], capacity, &(*top));
                    if(v[i]==42 || v[i]==43 || v[i]==47  || v[i]==45 )push_char(&(*op), v[i], capacity2, &(*top2));
                    if(*top>=1) {
                        v2[j]=pop_char(&(*nr),&(*top)) ; j++;
                        v2[j]=pop_char(&(*nr),&(*top)) ; j++;
                        v2[j]=pop_char(&(*op),&(*top)) ; j++;
                        }
                    i++;
                }
            }
        }
        if(*top>=1) {
            v2[j]=pop_char(&(*nr),&(*top)) ; j++;
            v2[j]=pop_char(&(*nr),&(*top)) ; j++;
            v2[j]=pop_char(&(*op),&(*top)) ; j++;
            }
        i++;
    }
}


void push_coada(STIVA **s,STIVA **s2,int *top1,int *top2,int capacity, int capacity2,int val){
    if(*top1==-1)push(&(*s), val, capacity, &(*top1));
    else {
        while(!isEmpty(*s)) push(&(*s2), pop(&(*s), &(*top1)), capacity2, &(*top2));
        push(&(*s), val, capacity, &(*top1));
        while(!isEmpty(*s2)) push(&(*s), pop(&(*s2), &(*top2)), capacity, &(*top1));
    }
}

void pop_coada(STIVA **s,STIVA **s2,int *top1,int *top2,int capacity, int capacity2){
    
    
    
}

int main() {
    
   /* STIVA *s=(STIVA*)malloc(sizeof(STIVA));
    s=NULL;
    int v1[]={10,1,2,5,4,-3,7,8,5},v2[]={5,8,7,-3,4,3,2,1,10},v3[]={1,2,3,4,5,6,7,8,9};
    int capacity=9,varf=-1;
    
    for(int i=0;i<9;i++){
        push(&s, v3[i], capacity, &varf);
    }
    stack_display(s, varf);
    int l=secv_crescatoare(s, varf);
   
    if(l==0)
        printf("Toate numerele din stiva sunt ordonate descrescator.\n");
    else
        printf("Secventa cea mai lunga de nr crescatoare este de %d.\n",l);
    
    return 0;
    
    */     //problema 1
    
    
    STIVA2 *s=(STIVA2*)malloc(sizeof(STIVA2));
    STIVA2 *s2=(STIVA2*)malloc(sizeof(STIVA2));
    s=NULL;
    s2=NULL;
    char v[]="3+2*5+1",v2[]="(3+2-1)*5";
    char ecuatie[100];
    int top=-1,capacity=100;
    int top2=-1,capacity2=100;
        
    Reverse_Polish_Notation(&s,&s2, v, ecuatie, &top, capacity, &top2, capacity2);
    printf("RPN:%s\n",ecuatie);
    return 0;
    
         //pr 2 ????
    
    
 /*    STIVA *s=(STIVA*)malloc(sizeof(STIVA));
     STIVA *s2=(STIVA*)malloc(sizeof(STIVA));
     s=NULL;
     s2=NULL;
    int top1=-1,capacity=10;
    int top2=-1,capacity2=10;

    push_coada(&s, &s2, &top1, &top2, capacity, capacity2, 1);
    push_coada(&s, &s2, &top1, &top2, capacity, capacity2, 2);
    push_coada(&s, &s2, &top1, &top2, capacity, capacity2, 3);
    push_coada(&s, &s2, &top1, &top2, capacity, capacity2, 4);
    pop(&s, &top1);
    
    stack_display(s, top1);
    return 0;                //problema 5

  */
}
