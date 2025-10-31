#ifndef STACK_H
#define STACK_H

#include <iostream>
#define max 20
#define Nil -1

typedef int infotype;

struct stack {
    int info[max];
    int TOP;
};

void createStack(stack &S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);

#endif