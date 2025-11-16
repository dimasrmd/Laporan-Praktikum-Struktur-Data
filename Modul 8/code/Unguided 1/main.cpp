#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Queue Dengan Alternatif 1" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);

    dequeue(Q); printInfo(Q);

    enqueue(Q,4); printInfo(Q);
    
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    // cout <<"\n" << Q.head << " " << Q.tail << " " << Q.count << endl;

    enqueue(Q,15); printInfo(Q);
    enqueue(Q,12); printInfo(Q);
    enqueue(Q,17); printInfo(Q);
    return 0;
}
