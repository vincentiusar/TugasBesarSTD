#include "list.h"

void createListParent(List1 &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(List2 &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListBase(ListBase &L) {
    L.first = NULL;
    L.last = NULL;
}

address1 CreateElmParent(string st) {
    address1 P = new parent;
    P -> info = st;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

address2 CreateElmChild(string st) {
    address2 P = new child;
    P -> info = st;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

connect CreateElmBase(address1 P, address2 Q) {
    connect R = new Base;
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

void insertListParent(List1 &L, address1 P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    }
}

void insertListChild(List2 &L, address2 P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first -> prev = P;
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
    address2 P = L.first;
    P = findElmChild(L, st);
    if (P -> prev == NULL) {
        L.first = P -> next;
        P -> next = NULL;
        P -> prev = NULL;
    } else if (P -> next != NULL && P -> prev != NULL) {
        address2 Q = P -> prev;
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

void deleteBasebyName(ListBase &L, connect P) {
    connect R = L.first;
    R = findElmBasebyName(L, P -> name -> info);
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
    R = findElmBasebyCourse(L, P -> matkul -> info);
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
    while (P != NULL && P -> info != X) {
        P = P -> next;
    }
    return P;
}

address2 findElmChild(List2 &L, string X) {
    address2 P = L.first;
    while (P != NULL && P -> info != X) {
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
    while (R != NULL && R -> name -> info != x) {
        R = R -> next;
    }
    return R;
}

connect findElmBasebyCourse(ListBase L, string x) {
    connect R = L.first;
    while (R != NULL && R -> matkul -> info != x) {
        R = R -> next;
    }
    return R;
}

void printInfoParent(List1 L) {
    address1 P = L.first;
    while (P != NULL) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void printInfoChild(List2 L) {
    address2 P = L.first;
    while (P != NULL) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void printInfoBase(ListBase L) {
    connect P = L.first;
    while (P != NULL) {
        cout << P -> name -> info << " " << P -> matkul -> info << " " << P -> info.nilai << " " << P -> info.Index << endl;
        P = P -> next;
    }
    cout << endl;
}