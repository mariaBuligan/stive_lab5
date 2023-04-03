//
//  functii_1.h
//  tema_lab5
//
//  Created by Maria Buligan on 31.03.2023.
//



typedef struct stack{
    int date;
    struct stack *urm;
}STIVA;

typedef struct stack_char{
    char date;
    struct stack_char *urm;
}STIVA2;

void push(STIVA **s,int val,int capacity,int *top);
int pop (STIVA **s,int *top);
void stack_display(STIVA *s,int top);
int top(STIVA *s);
int isEmpty(STIVA *s);

void push_char(STIVA2 **s,char val,int capacity,int *top);
char pop_char (STIVA2 **s,int *top);
void stack_display_char(STIVA2 *s,int top);



