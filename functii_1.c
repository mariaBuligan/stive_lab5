//
//  functii_1.c
//  tema_lab5
//
//  Created by Maria Buligan on 31.03.2023.
//

#include "functii_1.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int isEmpty(STIVA *s){
    return s==NULL;
}
void push(STIVA **s,int val,int capacity,int *top){
    STIVA *new=(STIVA*)malloc(sizeof(STIVA));
    if(*top >= capacity -1){
        printf("Stack overflow\n");
    }
    else{
       // printf("am pus %d\n",val);
        *top= *top+1;
        new->date=val;
        new->urm=*s;
        *s=new;
    }
}

int pop (STIVA **s,int *top){
    int top_val=INT_MIN;

    if(isEmpty(*s)){
       // printf("Stiva este goala\n");
        ;
    }
    else{
        //printf("am scos %d\n",(*s)->date);
        STIVA *temp=(*s);
        *top=*top -1;
        top_val=(*s)->date;
        *s=(*s)->urm;
        free(temp);
    }
    return top_val;
}

void concatenare_stiva(STIVA **s,STIVA *s2, int *capacity,int capacity_2, int *top,int top_2){
    *capacity=*capacity+capacity_2;

    while(top_2>=0){
        int x;
        x=pop(&s2, &top_2);
        push(&(*s), x, *capacity, &(*top));
    }
}

void citire_stiva(STIVA **s,int capacity,int *top){
    for(int i=0;i<capacity;i++){
        int x;
        scanf("%d",&x);
        push(&(*s), x, capacity,&(*top));
    }
}

void stack_display(STIVA *s,int top){
    while(s!=NULL){
        printf("%d ",s->date);
        s=s->urm;
    }
    printf("\n");
}
int top(STIVA *s){
    return s->date;
}

void push_char(STIVA2 **s,char val,int capacity,int *top){
    STIVA2 *new=(STIVA2*)malloc(sizeof(STIVA2));
    if(*top >= capacity -1){
        printf("Stack overflow\n");
    }
    else{
       // printf("am pus %d\n",val);
        *top= *top+1;
        new->date=val;
        new->urm=*s;
        *s=new;
    }
}

char pop_char (STIVA2 **s,int *top){
    char top_val=32;

    if(*top<0){
        printf("Stiva este goala\n");
    }
    else{
        //printf("am scos %d\n",(*s)->date);
        STIVA2 *temp=(*s);
        *top=*top -1;
        top_val=(*s)->date;
        *s=(*s)->urm;
        free(temp);
    }
    return top_val;
}

void stack_display_char(STIVA2 *s,int top){
    while(s!=NULL){
        printf("%c ",s->date);
        s=s->urm;
    }
    printf("\n");
}


