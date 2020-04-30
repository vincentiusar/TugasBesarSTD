#include <iostream>
#include <cstdlib>      // for clear screen
#include <fstream>      // for create txt file
#include "listParent.h"
#include "listChild.h"

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

using namespace std;

struct infotypeRelation {
    float kuis;
    float uts;
    float uas;
    float rerata;
    string Index;
};

typedef struct Relation *connect;

struct Relation {
    address1 name;
    address2 matkul;
    connect next;
    connect prev;
    infotypeRelation info;
};

struct ListRelation {
    connect first;
    connect last;
};

void createListRelation(ListRelation &L);
connect CreateElmRelation(address1 P, address2 Q);
void insertRelation(ListRelation &L, connect R);
void deleteFirstRelation(ListRelation &L, connect &R);
void deleteAfterRelation(ListRelation &L, connect Prec, connect &P);
void deleteLastRelation(ListRelation &L, connect &R);
void callDeleteRelation(ListRelation &L, connect &R);
void deleteListRelation1(ListRelation &L, connect P, connect Q);
void deleteListRelation2(ListRelation &L, connect P, connect Q);
connect findElmRelation1(ListRelation &L, address1 P, address2 Q);
connect findElmRelation2(ListRelation &L, address1 P, address2 Q);
void printAllRelation(ListRelation L, List1 P, List2 Q);
void printChildofParent(ListRelation L, List1 P, List2 Q, string ID);

//-----------------------

float nilaiMedianMatkul(ListRelation L, string st);
float nilaiRerata(ListRelation L, string st);
void hitungIndex(connect &R);
void printData(connect R, address1 P, address2 Q);
void toText(ListRelation L, List1 P, List2 Q);
void cleared();