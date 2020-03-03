#include "listParent.h"


void createListParent(List1 &L) {
    L.first = NULL;
}

address1 CreateElmParent(infotypeParent st) {
    address1 P = new parent;
    P -> info = st;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

void insertFirstParent(List1 &L, address1 P) {
    if (L.first == NULL) {
        L.first = P;
        P -> next = P;
        P -> prev = P;
    } else {
        P -> next = L.first;
        P -> prev = L.first -> prev;
        L.first -> prev -> next = P;
        L.first -> prev = P;
        L.first = P;
    }
}

void insertAfterParent(List1 &L, address1 Prec, address1 P) {
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

void insertlastParent(List1 &L, address1 P) {
    P -> next = L.first;
    P -> prev = L.first -> prev;
    L.first -> prev -> next = P;
    L.first -> prev = P;
}

address1 findElmParent(List1 &L, string X) {
    if (L.first != NULL) {
        address1 P = L.first;
        do {
            P = P -> next;
        } while (P != L.first && P -> info.ID != X);
        if (P == L.first && P -> info.ID != X) {
            return NULL;
        } else {
            return P;
        }
    }
    return NULL;
}

void insertSortParent(List1 &L, infotypeParent st) {
    if (L.first == NULL) {
        insertFirstParent(L, CreateElmParent(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (L.first -> info.ID > st.ID && findElmParent(L, st.ID)) {
        insertFirstParent(L, CreateElmParent(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (findElmParent(L, st.ID) == NULL) {
        address1 P = L.first;
        do {
            P = P -> next;
        } while (P != L.first && P -> info.ID < st.ID);
        insertAfterParent(L, P -> prev, CreateElmParent(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else {
        cout << "Maaf, mata kuliah sudah terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";            
    }
}

void deleteFirstParent(List1 &L, address1 &P) {
    if (L.first -> next == L.first) {
        P = L.first;
        P -> next = NULL;
        P -> prev = NULL;
        L.first = NULL;
    } else {
        P = L.first;
        L.first = P -> next;
        L.first -> prev = P -> prev;
        P -> prev -> next = L.first;
        P -> next = NULL;
        P -> prev = NULL;
    }
}

void deleteAfterParent(List1 &L, address1 Prec, address1 &P) {
    P = Prec -> next;
    P -> next -> prev = Prec;
    Prec -> next = P -> next;
    P -> next = NULL;
    P -> prev = NULL;
}

void deleteLastParent(List1 &L, address1 &P) {
    P = L.first -> prev;
    P -> prev -> next = L.first;
    L.first -> prev = P -> prev;
    P -> next = NULL;
    P -> prev = NULL;
}

void deleteListParent(List1 &L, string st) {
    address1 P = findElmParent(L, st);
    if (P != NULL) {
        if (P = L.first) {
            deleteFirstParent(L, P);
        } else if (P -> next != NULL && P -> prev != NULL) {
            deleteAfterParent(L, P -> prev, P);
        }
    }
}

void printInfoParent(List1 L) {
    address1 P = L.first;
    do {
        cout << P -> info.nama << " " << P -> info.ID << endl;
        P = P -> next;
    } while (P != L.first);
    cout << endl;
}