#include "listChild.h"

void createListChild(List2 &L) {
    L.first = NULL;
}

address2 CreateElmChild(infotypeChild st) {
    address2 P = new child;
    P -> info = st;
    P -> next = NULL;
    return P;
}

void insertFirstChild(List2 &L, address2 P) {
    P -> next = L.first;
    L.first = P;
}

void insertAfterChild(List2 &L, address2 Prec, address2 P) {
    P -> next = Prec -> next;
    Prec -> next = P;
}

void insertLastChild(List2 &L, address2 P) {
    L.last -> next = P;
    L.last = P;
}

void insertSortChild(List2 &L, infotypeChild st) {
    address2 P = L.first, Q;
    if (P == NULL) {
        insertFirstChild(L, CreateElmChild(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (P -> info.kodeMatkul > st.kodeMatkul && findElmChild(L, st.kodeMatkul) == NULL) {
        insertFirstChild(L, CreateElmChild(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (findElmChild(L, st.kodeMatkul) == NULL) {
        while (P != NULL && P -> info.kodeMatkul < st.kodeMatkul) {
            Q = P;
            P = P -> next; 
        }
        if (P != L.last) {
            insertAfterChild(L, Q, CreateElmChild(st));
        } else {
            insertLastChild(L, CreateElmChild(st));
        }
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else {
        cout << "Maaf, mata kuliah sudah terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
    }
}

address2 findElmChild(List2 &L, string X){
    address2 P = L.first;
    while (P != NULL && P -> info.kodeMatkul != X) {
        P = P -> next;
    }
    return P;
}

void deleteFirstChild(List2 &L, address2 &P) {
    P = L.first;
    L.first = P -> next;
    P -> next = NULL;
}

void deleteAfterChild(List2 &L, address2 Prec, address2 &P) {
    P -> next = Prec -> next;
    Prec -> next = P -> next;
}

void deleteLastChild(List2 &L, address2 &P) {
    address2 Q = L.first;
    while (Q -> next -> next != NULL) {
        Q = Q -> next;
    }
    P = Q -> next;
    Q -> next = NULL;
    L.last = Q;
}

void deleteListChild(List2 &L, string st) {
    if (L.first != NULL) { 
        address2 P = findElmChild(L, st);
        if (P == L.first) {
            deleteFirstChild(L, P);
        } else if (P -> next != NULL) {
            P = L.first;
            address2 Q;
            while (P != NULL && P -> info.kodeMatkul != st) {
                Q = P;
                P = P -> next;
            }
            deleteAfterChild(L, Q, P);
        } else if (P = L.last) {
            deleteLastChild(L, P);
        }
        delete P;
    }
}

void printInfoChild(List2 L) {
    address2 P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << i << ". Mata Kuliah\t: " << P -> info.matkul << "\t||\tKode\t: " << P -> info.kodeMatkul << endl;
        P = P -> next;
        i++;
    }
    cout << endl;
}