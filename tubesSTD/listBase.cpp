#include "listBase.h"

void createListBase(ListBase &L) {
    L.first = NULL;
    L.last = NULL;
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

void deleteFirstBase(ListBase &L, connect &R) {
    R = L.first;
    L.first = R -> next;
    L.first -> prev = NULL;
    R -> next = NULL;
    R -> prev = NULL;
}

void deleteAfterBase(ListBase &L, connect Prec, connect &P) {
    P = Prec -> next;
    Prec -> next = P -> next;
    P -> next -> prev = Prec;
    P -> next = NULL;
    P -> prev = NULL;
}

void deleteLastBase(ListBase &L, connect &R) {
    R = L.last;
    L.last = R -> prev;
    L.last -> next = NULL;
    R -> prev = NULL;
    R -> next = NULL;
}

void callDeleteBase(ListBase &L, connect &R) {
    if (R = L.first) {
        deleteFirstBase(L, R);
    } else if (R -> next != NULL && R -> prev != NULL) {
        deleteAfterBase(L, R -> prev, R);
    } else if (R = L.last) {
        deleteLastBase(L, R);
    }
}

void deleteListBase1(ListBase &L, connect P, connect Q) {
    if (P == NULL && Q == NULL) {
        cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (Q == NULL) {
        connect R = findElmBase1(L, P -> name, NULL);
        if (R != NULL) {
            callDeleteBase(L, R);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
        } else {
            cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
        }
    } else if (P == NULL) {
        connect R = findElmBase1(L, NULL, Q -> matkul);
        if (R != NULL) {    
            callDeleteBase(L, R);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
        } else {
            cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
        }
    } 
}

void deleteListBase2(ListBase &L, connect P, connect Q) {
    if (P != NULL && Q != NULL) {    
        connect R = findElmBase2(L, P -> name, Q -> matkul);
        if (R != NULL) {
            callDeleteBase(L, R);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
        } else {
            cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
        }
    }
}

connect findElmBase1(ListBase &L, address1 P, address2 Q) {
    if (Q == NULL) {
        connect R = L.first;
        while (R != NULL && R -> name -> info.ID != P -> info.ID) {
            R = R -> next;
        }
        return R;
    } else if (P == NULL) {
        connect R = L.first;
        while (R != NULL && R -> matkul -> info.matkul != Q -> info.matkul) {
            R = R -> next;
        }
        return R;
    }
    return NULL;
}

connect findElmBase2(ListBase &L, address1 P, address2 Q) {
    if (P != NULL && Q != NULL) {
        connect R = L.first;
        while (R != NULL && (R -> matkul != Q || R -> name != P)) {
            R = R -> next;
        }
        return R;
    }
    return NULL;
}

void printInfoBase(ListBase L) {
    connect P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << i << ".\nNama\t\t\t: " << P -> name -> info.nama << "\nNIM\t\t\t: " << P -> name -> info.ID << "\nMata Kuliah\t\t: " << P -> matkul -> info.matkul << "\nDosen\t\t\t: " << P -> matkul -> info.dosen << "\nNilai Kuis\t\t: " << P -> info.kuis << "\nNilai UTS\t\t: " << P -> info.uts << "\nNilai UAS\t\t: " << P -> info.uas << "\nNilai Keseluruhan\t: " << P -> info.rerata << "\nIP\t\t\t: " << P -> info.Index << endl << endl;
        P = P -> next;
        i++;
    }
    cout << endl;
}