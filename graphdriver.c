#include "graph.c"

int main () {
    Graph G;
    adrNode P;
    int i, X;
    CreateGraph(2, &G);
    for (i = 1; i <= 3; i++) {
        scanf(" %d", &X);
        InsertNode(&G, X, &P);
    }
    P = SearchNode(G, 1945);
    if (P == Nil) {
        printf("gada\n");
    }
    InsertEdge(&G, 2, 9);
    P = FirstG(G);
    while (P != Nil) {
        printf("print vertex/node %d\n", Id(P));
        P = NextG(P);
    }
    return 0;
}