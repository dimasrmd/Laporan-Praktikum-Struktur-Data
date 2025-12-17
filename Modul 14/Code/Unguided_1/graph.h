#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph (Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
void printBFS(Graph G, adrNode N);
void printDFS(Graph G, adrNode N);

// struktur Queue
typedef struct queue *adrQueue;
struct queue {
    adrNode G; // info yang dibawah
    adrQueue next;
};

struct queueList {
    adrQueue head;
    adrQueue Tail;
};

void createQueue(queueList &Q);
bool isEmpty(queueList Q);
void enqueue(queueList &Q, adrNode G);
adrNode dequeue(queueList &Q);

// Struktur Stack
typedef struct stack *adrStack;
struct stack {
    adrNode G;
    adrStack next;
};

struct stackList {
    adrStack top;
    adrStack bottom;
};

void createListStack(stackList &S);
adrStack createStackNode(stackList &S, adrNode G);
bool isEmptyStack(stackList S);
void push(stackList &S, adrNode G);
adrNode pop(stackList &S);

#endif