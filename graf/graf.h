#ifndef _GRAF_H
#define _GRAF_H

// #define Nil NULL

#include "../boolean/boolean.h"
#include "../matrix/mapmatrix.h"
typedef struct{
    int NBVertex; /* jumlah node pada matrix */
    int** Edges;
} AdjacencyMATRIX;

#define NBVertex(G) (G).NBVertex
#define Edges(G,i,j) (G).Edges[(i)][(j)]

void CreateEmptyGraph(AdjacencyMATRIX *G);
/* membuat graf kosong dengan implementasi adjaacency matrix */

void CreateGraph(AdjacencyMATRIX *G, int NbVertex);
/* membuat graf dengan ukuran NbVertex x NbVertex, dan bernilai 0 untuk semua arcs[i][j] */

void DealokasiGraf(AdjacencyMATRIX *G);

void CreateEdge(AdjacencyMATRIX *G, int Vertex1, int Vertex2);
/* membuat edges antara vertex 1 dan vertex 2 */

void RemoveEdge(AdjacencyMATRIX *G, int Vertex1, int Vertex2);
/* remove edges antara vertex 1 dan vertex 2 */

boolean IsConnected(AdjacencyMATRIX G, int Vertex1, int Vertex2);
/* menunjukkan apakah vertex 1 dan vertex 2 terhubung */

void NeighborsList(AdjacencyMATRIX G, int Vertex, int* jumlahneighbor);
/* menunjukkan jalan yang dapat dituju dari vertex tersebut */

void PrintGraph(AdjacencyMATRIX G);
/* mencetak matriks graf */

void ConvertMatrixToGraph(MATRIX M, AdjacencyMATRIX *G);

#endif