#include "graph.h"

int main () {
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A'); InsertNode(G, 'B'); InsertNode(G, 'C'); 
    InsertNode(G, 'D'); InsertNode(G, 'E'); InsertNode(G, 'F');
    InsertNode(G, 'G'); InsertNode(G, 'H');

    adrNode N1, N2;

    // Nyambungin A ke C
    N1 = findNode(G, 'A'); N2 = findNode(G, 'C');
    ConnectNode(G, N1, N2);

    // Nyambungin A ke B
    N1 = findNode(G, 'A'); N2 = findNode(G, 'B');
    ConnectNode(G, N1, N2);
    
    // Nyambungin B ke E
    N1 = findNode(G, 'B'); N2 = findNode(G, 'E');
    ConnectNode(G, N1, N2);
    
    // Nyambungin B ke D
    N1 = findNode(G, 'B'); N2 = findNode(G, 'D');
    ConnectNode(G, N1, N2);
    
    // Nyambungin C ke G
    N1 = findNode(G, 'C'); N2 = findNode(G, 'G');
    ConnectNode(G, N1, N2);

    // Nyambungin C ke F
    N1 = findNode(G, 'C'); N2 = findNode(G, 'F');
    ConnectNode(G, N1, N2);
    
    // Nyambungin D ke H
    N1 = findNode(G, 'D'); N2 = findNode(G, 'H');
    ConnectNode(G, N1, N2);
    
    // Nyambungin E ke H
    N1 = findNode(G, 'E'); N2 = findNode(G, 'H');
    ConnectNode(G, N1, N2);

    // Nyambungin F ke H
    N1 = findNode(G, 'F'); N2 = findNode(G, 'H');
    ConnectNode(G, N1, N2);

    // Nyambungin G ke H
    N1 = findNode(G, 'G'); N2 = findNode(G, 'H');
    ConnectNode(G, N1, N2);

    PrintInfoGraph(G);
    N1 = findNode(G, 'A');
    printBFS(G, N1);
    
    cout << endl;
    
    N1 = findNode(G, 'A');
    printDFS(G, N1);
}