#include "stack.h"
#include <iostream>
using namespace std;

int main () {
    stack S;
    createStack(S);
    cout << "Halo dunia!" << endl;

    push(S, 17); // 17
    push(S, 42); // 42, 17
    push(S, 8);  // 8, 42, 17
    pop(S);      // 42, 17
    push(S, 99); // 99, 42, 17
    push(S, 23); // 23, 99, 42, 17
    push(S, 61); // 61, 23, 99, 42, 17
    push(S, 7);  // 7, 61, 23, 99, 42, 17
    pop(S);      // 61, 23, 99, 42, 17
    push(S, 34); // 34, 61, 23, 99, 42, 17
    push(S, 50); // 50, 34, 61, 23, 99, 42, 17
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}