#include "list.h"

void createListBase(ListBase &L) {
    L.first = NULL;
    L.last = NULL;
}

address2 CreateElmChild(string matkul, string dosen) {
    address2 P = new child;
    P -> info.matkul = matkul;
    P -> info.dosen = dosen;
    P -> next = NULL;
    return P;
}

connect CreateElmBase(address1 P, address2 Q) {
    connect R = new Base;
    R -> name = P;
    R -> matkul = Q;
    cout << "Masukkan Nilai Kuis Anda : ";
    cin >> R -> info.kuis;
    cout << "Masukkan Nilai UTS Anda : ";
    cin >> R -> info.uts;
    cout << "Masukkan Nilai UAS Anda : ";
    cin >> R -> info.uas;
    hitungIndex(R);
    R -> next = NULL;
    R -> prev = NULL;
    return R;
}

void insertBase(ListBase &L, connect R) {
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        R -> next = L.first;
        L.first -> prev = R;
        L.first = R;
    }
}

void deleteBasebyName(ListBase &L, connect P) {
    connect R = L.first;
    R = findElmBasebyName(L, P -> name -> info.nama);
    if (R -> prev == NULL) {
        L.first = R -> next;
        R -> next = NULL;
        R -> prev = NULL;
    } else if (R -> next != NULL && R -> prev != NULL) {
        connect Q = R -> prev;
        Q -> next = R -> next;
        R -> next -> prev = Q;
        R -> next = NULL;
        R -> prev = NULL; 
    } else {
        L.last = R -> prev;
        R -> prev = NULL;
        L.last -> next = NULL;
    }
}

void deleteBasebyCourse(ListBase &L, connect P) {
    connect R = L.first;
    R = findElmBasebyCourse(L, P -> matkul -> info.matkul);
    if (R -> prev == NULL) {
        L.first = R -> next;
        R -> next = NULL;
        R -> prev = NULL;
    } else if (R -> next != NULL && R -> prev != NULL) {
        connect Q = R -> prev;
        Q -> next = R -> next;
        R -> next -> prev = Q;
        R -> next = NULL;
        R -> prev = NULL; 
    } else {
        L.last = R -> prev;
        R -> prev = NULL;
        L.last -> next = NULL;
    }
}

connect findElmBaseAll(ListBase &L, address1 P, address2 Q) {
    connect R = L.first;
    while (R != NULL && (R -> matkul != Q || R -> name != P)) {
        R = R -> next;
    }
    return R;
}

connect findElmBasebyName(ListBase L, string x) {
    connect R = L.first;
    while (R != NULL && R -> name -> info.nama != x) {
        R = R -> next;
    }
    return R;
}

connect findElmBasebyCourse(ListBase L, string x) {
    connect R = L.first;
    while (R != NULL && R -> matkul -> info.matkul != x) {
        R = R -> next;
    }
    return R;
}

void printInfoBase(ListBase L) {
    connect P = L.first;
    while (P != NULL) {
        cout << P -> name -> info.nama << " " << P -> name -> info.ID << " " << P -> matkul -> info.matkul << " " << P -> matkul -> info.dosen << " " << P -> info.kuis << " " << P -> info.uts << " " << P -> info.uas << " " << nilaiRerata(L, P -> name -> info.nama) << P -> info.Index << endl;
        P = P -> next;
    }
    cout << endl;
}