#include <iostream>
#include <cstdlib>

using namespace std;

struct infotype {
    float nilai;
    string Index;
};

typedef struct child *address;
typedef struct parent *connect;

struct child {
    string info;
    address next;
    address prev;
};

struct parent {
    address name;
    address matkul;
    connect next;
    connect prev;
    infotype info;
};

struct List {
    address first;
    address last;
};

struct ListParent {
    connect first;
    connect last;
};

void createList1(List &L);
void createListCon(ListParent &L);
address CreateElm(string st);
connect CreateElmParent(address P, address Q);
void insertList(List &L, address P);
void insertParent(ListParent &L, connect R);
void deleteList(List &L, string st);
void deleteParentbyName(ListParent &L, connect P);
void deleteParentbyCourse(ListParent &L, connect P);
address findElmChild(List &L, string X);
connect findElmParentAll(ListParent &L, address P, address Q);
connect findElmParentbyName(ListParent L, string X);
connect findElmParentbyCourse(ListParent L, string x);
void printInfoChild(List L);
void printInfoParent(ListParent L);
float nilaiMedianMatkul(ListParent L, string st);
float nilaiRerata(ListParent L, string st);
void cleared();