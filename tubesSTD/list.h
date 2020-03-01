#include <iostream>
#include <cstdlib>

using namespace std;

struct infotypeParent {
    string nama;
    string kelas;
};

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
typedef struct parent *address1;
typedef struct Base *connect;

struct parent {
    infotypeParent info;
    address1 next;
    address1 prev;
};

struct child {
    infotypeChild info;
    address2 next;
    address2 prev;
};

struct Base {
    address1 name;
    address2 matkul;
    connect next;
    connect prev;
    infotypeBase info;
};

struct List1 {
    address1 first;
    address1 last;
};

struct List2 {
    address2 first;
    address2 last;
};

struct ListBase {
    connect first;
    connect last;
};

void createListParent(List1 &L);
void createListChild(List2 &L);
void createListBase(ListBase &L);
address1 CreateElmParent(string nama, string kelas);
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
void hitungIndex(connect R);
void cleared();