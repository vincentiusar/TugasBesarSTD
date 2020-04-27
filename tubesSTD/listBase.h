#include <iostream>
#include <cstdlib>
#include "listParent.h"
#include "listChild.h"

using namespace std;

struct infotypeBase {
    float kuis;
    float uts;
    float uas;
    float rerata;
    string Index;
};

typedef struct Base *connect;

struct Base {
    address1 name;
    address2 matkul;
    connect next;
    connect prev;
    infotypeBase info;
};

struct ListBase {
    connect first;
    connect last;
};

void createListBase(ListBase &L);
connect CreateElmBase(address1 P, address2 Q);
void insertBase(ListBase &L, connect R);
void deleteFirstBase(ListBase &L, connect &R);
void deleteAfterBase(ListBase &L, connect Prec, connect &P);
void deleteLastBase(ListBase &L, connect &R);
void callDeleteBase(ListBase &L, connect &R);
void deleteListBase1(ListBase &L, connect P, connect Q);
void deleteListBase2(ListBase &L, connect P, connect Q);
connect findElmBase1(ListBase &L, address1 P, address2 Q);
connect findElmBase2(ListBase &L, address1 P, address2 Q);
void printAllRelation(ListBase L, List1 P, List2 Q);
void printChildofParent(ListBase L, List1 P, List2 Q, string ID);

//-----------------------

float nilaiMedianMatkul(ListBase L, string st);
float nilaiRerata(ListBase L, string st);
void hitungIndex(connect &R);
void printReverse(List1 L);
void cleared();