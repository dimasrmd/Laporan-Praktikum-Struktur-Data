#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S) {
    S.TOP = Nil;
}

bool kosong(stack S) {
    return S.TOP == Nil;
}

bool penuh(stack S) {
    return S.TOP == max-1;
}

void push(stack &S, infotype x) {
    if (!penuh(S)) {
        S.TOP++;
        S.info[S.TOP] = x;
    } else {
        cout << "Stack penuh. " << x << "tidak dapat di-push." << endl;
    }
}

infotype pop(stack &S) {
    infotype x = -999;
    if (!kosong(S)) {
        x = S.info[S.TOP];
        S.TOP--;
    } else {
        cout << "Stack kosong! tidak dapat melakukan pop" << endl;
    };
    return x;
}

void printInfo(stack S) {
    if (kosong(S)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(stack &S) {
    if (kosong(S)) {
        cout << "Stack kosong!" << endl;
    } else {
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

/* Tambahan untuk unguided 2 */
void pushAscending(stack &S, infotype x) {
    if (penuh(S)) {
        cout << "Stack penuh!" << x << "tidak di-input ke stack." << endl;
    } else {
        stack temp1;
        createStack(temp1);
        while (!kosong(S) && S.info[S.TOP] <= x) {
            push(temp1, pop(S));
        }
        push(S, x);
        while(!kosong(temp1)) {
            push(S, pop(temp1));
        }
    }
}