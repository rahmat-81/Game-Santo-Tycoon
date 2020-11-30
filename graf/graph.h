#ifndef _GRAPH_H
#define _GRAPH_H


#define MaxBuilding 100
#define Nil NULL

#include "boolean.h"
#include "listlinier.h"

typedef char infotypeGraph;
typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
    infotypeGraph Gedung;
    List Link;
    addressGraph Next;
} ElmtGraph;
typedef struct {
    addressGraph First;
} Graph;

#define InfoGedung(G) (G).Gedung
#define NextGraph(G) (G).Next
#define Link(G) (G).Link
#define First(G) (G).First

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang             */
/* F.S. Terbentuk graph kosong */

boolean IsGraphEmpty(Graph G);
/* Mengirimkan true jika graph kosong */

addressGraph AlokasiGraph(infotypeGraph X);
/* Mengirimkan addressGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressGraph tidak nil, dan misalnya */
/* menghasilkan P, maka InfoGraph(P)=X, NextGraph(P)=NULL, dan Link(P) berisi list kosong */
/* Jika alokasi gagal, mengirimkan NULL */

void initGraph(Graph *G, int n);
/* I. S. Graph G sembarang, n adalah jumlah building/ jumlah elemen parent list
   F. S. Terbentuk Graph n elemen dan link tiap elemen berupa empty list */

void PrintGraph(Graph G);
/* I.S. Graph mungkin kosong */
/* F.S. Jika Graph tidak kosong, isi info Graph dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Graph kosong : menulis [] */


void AddLink(Graph *G, infotypeGraph n, infotypeGraph p);
/* I. S. Graph G terdefinisi, n dan p pasti tidak lebih dari jumlah building
   F. S. Link dari elemen n bertambah dengan p, dan sebaliknya (soalnya bolak balik)
   contoh :
   1 2->3
   2 1
   3 1
   Add(&G, 2, 3) 
   1 2->3
   2 1->3
   3 1->3 */

void PrintLink(Graph G, infotypeGraph X);

boolean IsLinked(Graph G, infotypeGraph n, infotypeGraph p);
/* Mengembalikan true jika pada link n ada p */

addressGraph SearchGraph(Graph G, infotypeGraph X);

#endif

