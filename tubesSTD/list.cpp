#include "list.h"

void createList1(List &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListCon(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

address CreateElm(string st) {
    address P = new child;
    P -> info = st;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

void insertList(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    }
}

connect CreateElmParent(address P, address Q) {
    connect R = new parent;
    R -> name = P;
    R -> matkul = Q;
    cout << "Masukkan Nilai Anda : ";
    float nilai = 0;
    cin >> nilai;
    R -> info.nilai = nilai;
    if (R -> info.nilai >= 80) {
        R -> info.Index = "A";
    } else if (R -> info.nilai < 80 && R -> info.nilai >= 70) {
        R -> info.Index = "AB";
    } else if (R -> info.nilai < 70 && R -> info.nilai >= 65) {
        R -> info.Index = "B";
    } else if (R -> info.nilai < 65 && R -> info.nilai >= 60) {
        R -> info.Index = "BC";
    } else if (R -> info.nilai < 60 && R -> info.nilai >= 50) {
        R -> info.Index = "C";
    } else if (R -> info.nilai < 50 && R -> info.nilai >= 40) {
        R -> info.Index = "D";
    } else {
        R -> info.Index = "E";
    }
    R -> next = NULL;
    R -> prev = NULL;
    return R;
}

void insertParent(ListParent &L, connect R) {
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        R -> next = L.first;
        L.first -> prev = R;
        L.first = R;
    }
}

void deleteList(List &L, string st) {
    address P = L.first;
    P = findElmChild(L, st);
    if (P -> prev == NULL) {
        L.first = P -> next;
        P -> next = NULL;
        P -> prev = NULL;
    } else if (P -> next != NULL && P -> prev != NULL) {
        address Q = P -> prev;
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

void deleteParentbyName(ListParent &L, connect P) {
    connect R = L.first;
    R = findElmParentbyName(L, P -> name -> info);
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

void deleteParentbyCourse(ListParent &L, connect P) {
    connect R = L.first;
    R = findElmParentbyCourse(L, P -> matkul -> info);
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

address findElmChild(List &L, string X) {
    address P = L.first;
    while (P != NULL && P -> info != X) {
        P = P -> next;
    }
    return P;
}

connect findElmParentAll(ListParent &L, address P, address Q) {
    connect R = L.first;
    while (R != NULL && (R -> matkul != Q || R -> name != P)) {
        R = R -> next;
    }
    return R;
}

connect findElmParentbyName(ListParent L, string x) {
    connect R = L.first;
    while (R != NULL && R -> name -> info != x) {
        R = R -> next;
    }
    return R;
}

connect findElmParentbyCourse(ListParent L, string x) {
    connect R = L.first;
    while (R != NULL && R -> matkul -> info != x) {
        R = R -> next;
    }
    return R;
}

void printInfoChild(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void printInfoParent(ListParent L) {
    connect P = L.first;
    while (P != NULL) {
        cout << P -> name -> info << " " << P -> matkul -> info << " " << P -> info.nilai << " " << P -> info.Index << endl;
        P = P -> next;
    }
    cout << endl;
}