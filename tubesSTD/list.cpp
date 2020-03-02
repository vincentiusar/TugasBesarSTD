#include "list.h"

void createListChild(List2 &L) {
    L.first = NULL;
    L.last = NULL;
}

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

void insertListChild(List2 &L, address2 P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first = P;
    }
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

void deleteListParent(List1 &L, string st) {
    address1 P = L.first;
    P = findElmParent(L, st);
    if (P -> prev == NULL) {
        L.first = P -> next;
        P -> next = NULL;
        P -> prev = NULL;
    } else if (P -> next != NULL && P -> prev != NULL) {
        address1 Q = P -> prev;
        Q -> next = P -> next;
        P -> next -> prev = Q;
        P -> next = NULL;
        P -> prev = NULL; 
    } else {
        L.last = P -> prev;
        P -> prev = NULL;
        L.last -> next = NULL;
    }
}

void deleteListChild(List2 &L, string st) {
    address2 P;
    while (findElmChild(L, st) != NULL) {
        if (findElmChild(L, st) == L.first) {
            P = L.first;
            L.first = P -> next;
            P -> next = NULL;
            delete(P);
        } else {
            address2 Q = L.first;
            while (P -> next -> next != NULL) {

            }
        }
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

address1 findElmParent(List1 &L, string X) {
    address1 P = L.first;
    while (P != NULL && P -> info.nama != X) {
        P = P -> next;
    }
    return P;
}

address2 findElmChild(List2 &L, string X) {
    address2 P = L.first;
    while (P != NULL && P -> info.matkul != X) {
        P = P -> next;
    }
    return P;
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

void printInfoParent(List1 L) {
    address1 P = L.first;
    while (P != NULL) {
        cout << P -> info.nama << " " << P -> info.ID << endl;
        P = P -> next;
    }
    cout << endl;
}

void printInfoChild(List2 L) {
    address2 P = L.first;
    while (P != NULL) {
        cout << P -> info.matkul << " " << P -> info.dosen << endl;
        P = P -> next;
    }
    cout << endl;
}

void printInfoBase(ListBase L) {
    connect P = L.first;
    while (P != NULL) {
        cout << P -> name -> info.nama << " " << P -> name -> info.ID << " " << P -> matkul -> info.matkul << " " << P -> matkul -> info.dosen << " " << P -> info.kuis << " " << P -> info.uts << " " << P -> info.uas << " " << nilaiRerata(L, P -> name -> info.nama) << P -> info.Index << endl;
        P = P -> next;
    }
    cout << endl;
}