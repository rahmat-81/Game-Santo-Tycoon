#include<stdio.h>
#include<stdlib.h>
#include "graf.h"

// typedef struct{
//     int NBVertex; /* jumlah node pada matrix */
//     int** Edges;
// } AdjacencyMATRIX;

// #define NBVertex(G) (G).NBVertex
// #define Edges(G,i,j) (G).Edges[(i)][(j)]


void CreateEmptyGraph(AdjacencyMATRIX *G)
/* membuat graf kosong dengan implementasi adjaacency matrix */
{
    NBVertex(*G) = 0;
    G->Edges = NULL;
}

void CreateGraph(AdjacencyMATRIX *G, int NbVertex)
/* membuat graf dengan ukuran NbVertex x NbVertex, dan bernilai 0 untuk semua arcs[i][j] */
{
    int i, j;
    CreateEmptyGraph(G);
    
    NBVertex(*G) = NbVertex;
    /* inisialisasi matriks integer */
    G->Edges = (int* *) malloc(NbVertex * sizeof(int*));
    for(i = 0; i < NBVertex(*G); i++){
        G->Edges[i] = (int *) malloc (NbVertex * sizeof(int));
    }

    for(i = 0; i < NbVertex; i++){
        for(j = 0; j < NbVertex; j++){
            Edges(*G, i, j) = 0; /* inisialisasi dengan 0 */
        }
    }

}

void DealokasiGraf(AdjacencyMATRIX *G)
{
    free(G);
}

void CreateEdge(AdjacencyMATRIX *G, int Vertex1, int Vertex2)
/* membuat edges antara vertex 1 dan vertex 2 */
{
    if(Vertex1 >= 0 && Vertex1 <= NBVertex(*G) && Vertex2 >= 0 && Vertex2 <= NBVertex(*G) && Edges(*G,Vertex1, Vertex2) == 0){
        Edges(*G,Vertex1, Vertex2) = 1;
        Edges(*G, Vertex2, Vertex1) = 1;
    }
}

void RemoveEdge(AdjacencyMATRIX *G, int Vertex1, int Vertex2)
/* remove edges antara vertex 1 dan vertex 2 */
{
    if(Vertex1 >= 0 && Vertex1 <= NBVertex(*G) && Vertex2 >= 0 && Vertex2 <= NBVertex(*G) && Edges(*G,Vertex1, Vertex2) > 0){
        Edges(*G,Vertex1, Vertex2) = 0;
        Edges(*G, Vertex2, Vertex1) = 0;
    }
}

boolean IsConnected(AdjacencyMATRIX G, int Vertex1, int Vertex2)
/* menunjukkan apakah vertex 1 dan vertex 2 terhubung */
{
    return Edges(G, Vertex1, Vertex2) > 0;
}

void NeighborsList(AdjacencyMATRIX G, int Vertex, int* jumlahneighbor)
/* menunjukkan jalan yang dapat dituju dari vertex tersebut */
{
    int i, nomor_depan;
    nomor_depan = 1;
    printf("Daftar lokasi yang dapat dicapai:\n");
    for(i = 0; i < NBVertex(G); i++){
        if(Edges(G, i, Vertex) > 0){
            if (i==0){
                printf("%d. Base\n", nomor_depan);
            }
            else if (i==1){
                printf("%d. Shop\n", nomor_depan);
            }
            else{
                printf("%d. Pelanggan %d\n", nomor_depan, i-1);
            }
            
            nomor_depan++;
        }
    }
    *jumlahneighbor = nomor_depan - 1;
    printf("\n");
}

void PrintGraph(AdjacencyMATRIX G)
/* mencetak matriks graf */
{
  int i, j;

  for (i = 0 ; i < NBVertex(G) ; i++) {
    for (j = 0 ; j < NBVertex(G) ; j++) {
      printf("%d ", Edges(G, i, j));
    }
    printf("\n");
  }
  printf("\n");
}

void ConvertMatrixToGraph(MATRIX M, AdjacencyMATRIX* G)
{
    int i, j;
    for(i = 0; i < NBrsEff(M); i++){
        for(j = 0; j < NKolEff(M); j++){
            // G.Edges[i][j] = (Elmt(M,i,j)) - '0'; /* ubah char jadi int */
            Edges(*G, i, j) = Elmt(M,i,j) - '0';
        }   
    }
}
