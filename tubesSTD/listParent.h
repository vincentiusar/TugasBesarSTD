#include <iostream>

using namespace std;

struct infotypeParent {
    string nama;
    string ID;
};

typedef struct parent *address1;

struct parent {
    infotypeParent info;
    address1 next;
    address1 prev;
};

struct List1 {
    address1 first;
};

void createListParent(List1 &L);
address1 CreateElmParent(infotypeParent st);
void insertFirstParent(List1 &L, address1 P);
void insertAfterParent(List1 &L, address1 Prec, address1 P);
void insertLastParent(List1 &L, address1 P);
void insertSortParent(List1 &L, infotypeParent st);
void deleteFirstParent(List1 &L, address1 &P);
void deleteAfterParent(List1 &L, address1 Prec, address1 &P);
void deleteLastParent(List1 &L, address1 &P);
void deleteListParent(List1 &L, string st);
address1 findElmParent(List1 &L, string X);
void printInfoParent(List1 L);