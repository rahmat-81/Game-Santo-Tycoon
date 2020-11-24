#include "graph.h"

void CreateGraph(infograph X, Graph *G) {
    //KAMUS
    adrNode P;
    //Algoritma
    FirstG(*G) = Nil;
    InsertNode(G, X, &P);
}


adrNode AlokNodeGraph (infograph X) {
    //KAMUS
    adrNode P;
    //Algoritma
    P = (adrNode) malloc (sizeof(NodeGraph));
    if (P!=Nil) {
        Id(P) = X;
        Trail(P) = Nil;
        NextG(P) = Nil;
    }
    return P;
}

void DeAlokNodeGraph (adrNode P) {
    free(P);
}


adrSuccNode AlokSuccNode(adrNode P) {
    //KAMUS
    adrSuccNode Pn;
    //Algoritma
    Pn = (adrSuccNode) malloc (sizeof(SuccNode));
    if(Pn != Nil) {
        NextG(Pn) = Nil;
        Succ(Pn) = P;
    }
    return Pn;    
}

void DealokSuccNode(adrSuccNode P) {
    free(P);
}

adrNode SearchNode(Graph G, infograph X) {
    //KAMUS
    adrNode P;
    boolean found;
    //Algoritma
    P = FirstG(G);
    found = false;
    while (P!=Nil && !found) {
        if (Id(P) == X) {
            found = true;
        }
        else{
            P = NextG(P);
        }
        
    }
    if (found) {
        return P;
    }
    else {
        return Nil;
    }
}


adrSuccNode SearchEdge (Graph G, infograph prec, infograph succ) {
    //KAMUS
    adrNode Pn;
    adrSuccNode P;
    boolean found;
    //Algoritma
    Pn = SearchNode(G, prec);
    found = false;
    if (Pn != Nil) {
        P = Trail(Pn);
        while (P != Nil) {
            if(Id(Succ(P)) == succ) {
                found = true;
            }
            else{
                P = NextG(P);
            }
        }
        if (found) {
            return P;
        }
        else {
            return Nil;
        }
    }
    else{
        return Nil;
    }
}

void InsertNode (Graph *G, infograph X, adrNode *Pn) {
    //Kamus
    adrNode P;
    //Algoritma
    *Pn = AlokNodeGraph(X);
    P = FirstG(*G);
    if (P!=Nil) {
        while (NextG(P) != Nil)
        {
            P = NextG(P);
        }
        NextG(P) = *Pn;       
    }
    else {
        FirstG(*G) = *Pn;
    }
}

void InsertEdge (Graph *G, infograph prec, infograph succ) {
    //KAMUS
    adrNode Pprec;
    adrNode Psucc;
    adrSuccNode P;
    //Algoritma
    if (SearchEdge(*G, prec, succ) == Nil) {
        Pprec = SearchNode(*G, prec);
        if (Pprec == Nil) {
            InsertNode(G, prec, &Pprec);
        }
        Psucc = SearchNode(*G, succ);
        if (Psucc == Nil) {
            InsertNode(G, succ, &Psucc);
        }

        P = Trail(Pprec);
        
        if (P != Nil) {
            while (NextG(P) != Nil) {
                P = NextG(P);
            }
            NextG(P) = AlokSuccNode(Psucc);
        }
        else {
            Trail(Pprec) = AlokSuccNode(Psucc);
        }
    }
}

void Connect(Graph *G, infograph N1, infograph N2) {
    InsertEdge(G, N1, N2);
    InsertEdge(G, N2, N1);
}

boolean isConnected (Graph G, infograph N1, infograph N2) {
    return(SearchEdge(G, N1, N2) != Nil) && (SearchEdge(G, N2, N1) != Nil);
}