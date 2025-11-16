#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.count == 0;
}

bool isFullQueue(Queue Q) {
    return Q.count == max;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (Q.count == 0) {
            Q.info[Q.tail] = x;
            Q.count++;
        } else {
            Q.tail = (1 + Q.tail) % max;
            Q.info[Q.tail] = x;
            Q.count++;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (Q.count == 0) {
        cout << "Queue Kosong!" << endl;
        return -999;
    } else {
        infotype x = Q.info[Q.head];
        Q.info[Q.head] = 0;
        Q.count--;
        if (Q.count != 0) Q.head = (Q.head + 1) % max;
        return x;
    }
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " - " << Q.tail << "\t : empty queue" << endl;
    } else {
        int i = Q.head;
        cout << Q.head << " - " << Q.tail << "\t : ";
        for (  int k = 0; k < Q.count; k++) {
            cout << Q.info[i] << " ";
            i = (i + 1) % max;
        }
        cout << endl;
    }
}