#ifndef GAME_H
#define GAME_H
#include "boolean/boolean.h"
#include "graf/graf.h"
#include "komponen/komponen.h"
#include "listdinamis/listdinamispoint.h"
#include "listdinamis/listardin.h"
#include "matrix/mapmatrix.h"
#include "mesinkata/mesinkata.h"
#include "mesinkar/mesinkar.h"
#include "order/order.h"
#include "point/point.h"
#include "queue/Queue.h"
#include "stack/stack.h"
#include "command/command.h"
#include <string.h>

void InisiasiCommand();
void UiAwal();
char IntToChar(int i);
void ListPointtoMatrix(ListPoint list, MATRIX *M);
void CheckOrder(Queue Q);
void Shop (List* shop, List* Inventory, int* saldo);
void AddComponent(Stack *S, List* Inventory);
List CreateShopList();
void End_Day(Queue* OrderQueue, List Shop, int jmlorang);
void RemoveComponent(Stack *S, List* Inventory);
void Deliver(POINT player, int NomorGedung, ListPoint Customer, List* Inventory, Queue* Q, int* Saldo);
void Status(int Saldo, Queue Order, List Inventory, POINT player, ListPoint Point, boolean startedbuild);
void FinishBuild(Stack Inventory, Order order, List* InventoryPlayer, boolean* startbuild);
void Move (POINT* player, AdjacencyMATRIX Graf, ListPoint Point);
void StartBuild (ListPoint listpoint, POINT Player, Queue order, boolean* startbuild, Stack* newbuild);
void MapPlayer (MATRIX M, POINT player);

#endif
