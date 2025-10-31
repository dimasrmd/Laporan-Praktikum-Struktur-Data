#include "stack.h"
using namespace std;

void createStack(stack &S) {
    S.TOP = Nil;
}

bool isFull(stack S) {
    return S.TOP == max-1;
}

bool kosong(stack S) {
    return S.TOP == Nil; // nil disni adalah -1
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.TOP++;
        S.info[S.TOP] = x;
    } else {
        cout << "Stack penuh!"<< x << "tidak dapat dimasukkan" << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;
    if (!kosong(S)) {
        x = S.info[S.TOP];
        S.TOP--;
    } else {
        cout << "Stack kosong, tidak bisa melakukan pop" << endl;
    }
    return x;
}

void printInfo(stack S) {
    if (kosong(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0 ; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(stack &S) {
    if (!kosong(S)) {
        stack temp1, temp2;
        createStack(temp1); createStack(temp2);

        while (!kosong(S)) {
            push(temp1, pop(S));
        }

        while (!kosong(temp1)) {
            push(temp2, pop(temp1));
        }

        while (!kosong(temp2)) {
            push(S, pop(temp2));
        }
    }
}