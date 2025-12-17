#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode alokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) { // Kaya linked list biasa
    adrNode P = alokasiNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void ConnectNode(Graph &G, adrNode N1, adrNode N2) { // Ini baru graph, sebelum gunakan ini nanti find node dulu
   if (N1 != NULL && N2 != NULL) {
        adrEdge jembatanBaru = new ElmEdge; // buat jembatan baru
        jembatanBaru->Node = N2; // sambungin jembatan ke tujuan
        jembatanBaru->next = N1->firstEdge; // sambungin jembatan ke asal
        N1->firstEdge = jembatanBaru; // asal nyambung ke jembatan
   }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " Terhubung ke: ";
        adrEdge jembatan = P->firstEdge;
        while (jembatan != NULL) {
            cout << jembatan->Node->info << " ";
            jembatan = jembatan->next;
        }
        cout << endl;
        P = P->next;
    }
}

// Bagian queue
bool isEmpty(queueList Q) {
    return Q.head == NULL;
}

void createQueue(queueList &Q) {
    Q.head = NULL;
    Q.Tail = NULL;
}

adrQueue alokasiQueue(adrNode G) {
    adrQueue P = new queue;
    P->G = G;
    P->next = NULL;
    return P;
}

void enqueue(queueList &Q, adrNode G) {
    adrQueue P = alokasiQueue(G);
    if (isEmpty(Q)) {
        Q.head = P;
        Q.Tail = P;
    } else {
        Q.Tail->next = P;
        Q.Tail = P;
    }
}

adrNode dequeue(queueList &Q) {
    if (isEmpty(Q)) return NULL;
    adrQueue P = Q.head;
    adrNode val = P->G;
    Q.head = Q.head->next;     // <-- geser head ke elemen berikutnya
    if (Q.head == NULL) {
        Q.Tail = NULL;         // <-- jika kosong, tail juga NULL
    }
    delete P;
    return val;
}

void printBFS(Graph G, adrNode N) {
    if (N == NULL) {
        cout << "Start tidak ditemukan." << endl;
        return;
    }

    for (adrNode P = G.first; P != NULL; P = P->next) {
        P->visited = 0;
    } // buat semua node belum terkunjungi dulu

    queueList Q;
    createQueue(Q);

    enqueue(Q, N);
    cout << "BFS dari " << N->info << ": ";

    while (!isEmpty(Q)) {
        adrNode x = dequeue(Q);
        if (x->visited == 0) {
            x->visited = 1; // sudah terkunjungi
            cout << x->info << " ";
            
            // untuk menelusuri semua cabang dari suatu node
            adrEdge e = x->firstEdge;
            while (e != NULL) {
                adrNode w = e->Node;
                if (w->visited == 0) {
                    enqueue(Q, w);
                }
                e = e->next;
            }
        }
    }
    cout << endl;
}

// bagian stack
void createListStack(stackList &S) {
    S.top = NULL;
    S.bottom = NULL;
}

adrStack createStackNode(stackList &S, adrNode G) {
    adrStack P = new stack;
    P->G = G;
    P->next = NULL;
    return P;
}

bool isEmptyStack(stackList S) {
    return S.top == NULL;
}

void push(stackList &S, adrNode G) {
    if (G == NULL) return;
    adrStack P = createStackNode(S, G);
    if (isEmptyStack(S)) {
        S.top = S.bottom = P;
    } else {
        S.top->next = P;
        S.top = P;
    }
}

adrNode pop(stackList &S) {
    if (isEmptyStack(S)) return NULL;
    adrStack prev = S.bottom;
    if (S.top == prev) { // cuma punya 1 elemen
        adrNode info = S.top->G;
        delete S.top;
        S.top = S.bottom = NULL;
        return info;
    }

    while (prev->next != S.top) {
        prev = prev->next;
    }
    adrNode info = S.top->G;
    delete S.top;
    prev->next = NULL;
    S.top = prev;
    return info;
}

void printDFS(Graph G, adrNode N) {
    if (N == NULL) {
        cout << "Start tidak ditemukan." << endl;
        return;
    }

    for (adrNode X = G.first; X != NULL; X = X->next) {
        X->visited = 0;
    }

    stackList S;
    createListStack(S);
    push(S, N);

    cout << "DFS dari " << N->info << ": ";

    while (!isEmptyStack(S)) {
        adrNode info = pop(S);
        if (info->visited == 0) {
            info->visited = 1;
            cout << info->info << " ";

            adrEdge e = info->firstEdge;
            while (e != NULL) {
                adrNode c = e->Node;
                if (c->visited == 0) {
                    push(S, c);
                }
                e = e->next;
            }
        }
    }
    cout << endl;
}