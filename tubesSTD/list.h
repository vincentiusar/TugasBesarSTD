#include <iostream>
#include <cstdlib>
#include "listParent.h"

using namespace std;

struct infotypeChild {
    string matkul;
    string dosen;
};

struct infotypeBase {
    float kuis;
    float uts;
    float uas;
    string Index;
};

typedef struct child *address2;
typedef struct Base *connect;

struct child {
    infotypeChild info;
    address2 next;
};

struct Base {
    address1 name;
    address2 matkul;
    connect next;
    connect prev;
    infotypeBase info;
};

struct List2 {
    address2 first;
    address2 last;
};

struct ListBase {
    connect first;
    connect last;
};

void createListChild(List2 &L);
void createListBase(ListBase &L);
address2 CreateElmChild(string matkul, string dosen);
connect CreateElmBase(address1 P, address2 Q);
void insertListParent(List1 &L, address1 P);
void insertListChild(List2 &L, address2 P);
void insertBase(ListBase &L, connect R);
void deleteListParent(List1 &L, string st);
void deleteListChild(List2 &L, string st);
void deleteBasebyName(ListBase &L, connect P);
void deleteBasebyCourse(ListBase &L, connect P);
address1 findElmParent(List1 &L, string X);
address2 findElmChild(List2 &L, string X);
connect findElmBaseAll(ListBase &L, address1 P, address2 Q);
connect findElmBasebyName(ListBase L, string X);
connect findElmBasebyCourse(ListBase L, string x);
void printInfoParent(List1 L);
void printInfoChild(List2 L);
void printInfoBase(ListBase L);
float nilaiMedianMatkul(ListBase L, string st);
float nilaiRerata(ListBase L, string st);
void hitungIndex(connect &R);
void cleared();