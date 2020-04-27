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
        L.last -> next = R;
        R -> prev = L.last;
        L.last = R;
    }
}

void deleteFirstBase(ListBase &L, connect &R) {
    if (L.first == L.last) {
        R = L.first;
        L.last = NULL;
        L.first = NULL;
    } else {
        R = L.first;
        L.first = R -> next;
        L.first -> prev = NULL;
        R -> next = NULL;
        R -> prev = NULL;
    }
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
    if (R == L.first) {
        deleteFirstBase(L, R);
    } else if (R -> next != NULL && R -> prev != NULL) {
        deleteAfterBase(L, R -> prev, R);
    } else if (R == L.last) {
        deleteLastBase(L, R);
    }
}

void deleteListBase1(ListBase &L, connect P, connect Q) {
    if (P == NULL && Q == NULL) {
        cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (Q == NULL) {
        if (P != NULL) {
            cleared();
            callDeleteBase(L, P);
            delete P;
        }
    } else if (P == NULL) {
        if (Q != NULL) {    
            cleared();
            callDeleteBase(L, Q);
            delete Q;
        }
    }
}

void deleteListBase2(ListBase &L, connect P, connect Q) {
    if (P != NULL && Q != NULL) {    
        connect R = findElmBase2(L, P -> name, Q -> matkul);
        if (R != NULL) {
            callDeleteBase(L, R);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
        }
        delete R;
    } else {
        cout << "Maaf, data tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
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

void printAllRelation(ListBase L, List1 P, List2 Q) {
    address2 Q1;
    int i = 1;
    cout << "Berikut data Parent dan setiap child untuk parent tersebut : " << endl;
    for (address1 P1 = P.first; P1 != NULL; P1 = P1 -> next) {
        cout << i++ << ".\nNama\t\t\t: " << P1 -> info.ID << "\nNIM\t\t\t: " << P1 -> info.nama << endl;
        cout << "Mengambil mata kuliah dengan data sebagai berikut : ";
        int j = 1;
        for (connect R = L.first; R != NULL; R = R -> next) {
            if (R -> name == P1) {
                cout << j++ << ". Mata Kuliah\t\t: " << R -> matkul -> info.matkul << "\nKode Matkul\t\t\t: " << R -> matkul -> info.kodeMatkul << "\nNilai Kuis\t\t: " << R -> info.kuis << "\nNilai UTS\t\t: " << R -> info.uts << "\nNilai UAS\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t: " << R -> info.Index << endl << endl;
            }
        }
    }
    cout << endl;
}

void printChildofParent(ListBase L, List1 P, List2 Q, string ID) {
    address1 P1 = findElmParent(P, ID);
    for (connect R = L.first; R != NULL; R = R -> next) {
        int j = 1;
        cout << P1 -> info.nama << "Mengambil mata kuliah : " << endl;
        if (R -> name == P1) {
            cout << j++ << ". Mata Kuliah\t\t: " << R -> matkul -> info.matkul << "\nKode Matkul\t\t\t: " << R -> matkul -> info.kodeMatkul << "\nNilai Kuis\t\t: " << R -> info.kuis << "\nNilai UTS\t\t: " << R -> info.uts << "\nNilai UAS\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t: " << R -> info.Index << endl << endl;
        }
    }
}