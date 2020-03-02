#include <iostream>
#include <cstdlib>
#include "listParent.h"
#include "listChild.h"

using namespace std;

struct infotypeBase {
    float kuis;
    float uts;
    float uas;
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
void deleteBasebyName(ListBase &L, connect P);
void deleteBasebyCourse(ListBase &L, connect P);
connect findElmBaseAll(ListBase &L, address1 P, address2 Q);
connect findElmBasebyName(ListBase L, string X);
connect findElmBasebyCourse(ListBase L, string x);
void printInfoBase(ListBase L);
float nilaiMedianMatkul(ListBase L, string st);
float nilaiRerata(ListBase L, string st);
void hitungIndex(connect &R);
void cleared();