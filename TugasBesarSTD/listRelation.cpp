#include "listRelation.h"

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void createListRelation(ListRelation &L) {
    L.first = NULL;
    L.last = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

connect CreateElmRelation(address1 P, address2 Q) {
    connect R = new Relation;
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

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void insertRelation(ListRelation &L, connect R) {
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        L.last -> next = R;
        R -> prev = L.last;
        L.last = R;
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteFirstRelation(ListRelation &L, connect &R) {
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

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteAfterRelation(ListRelation &L, connect Prec, connect &P) {
    P = Prec -> next;
    Prec -> next = P -> next;
    P -> next -> prev = Prec;
    P -> next = NULL;
    P -> prev = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteLastRelation(ListRelation &L, connect &R) {
    R = L.last;
    L.last = R -> prev;
    L.last -> next = NULL;
    R -> prev = NULL;
    R -> next = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void callDeleteRelation(ListRelation &L, connect &R) {
    if (R == L.first) {
        deleteFirstRelation(L, R);
    } else if (R -> next != NULL && R -> prev != NULL) {
        deleteAfterRelation(L, R -> prev, R);
    } else if (R == L.last) {
        deleteLastRelation(L, R);
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteListRelation1(ListRelation &L, connect P, connect Q) {
    if (P == NULL && Q == NULL) {
        cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (Q == NULL) {
        if (P != NULL) {
            cleared();
            callDeleteRelation(L, P);
            delete P;
        }
    } else if (P == NULL) {
        if (Q != NULL) {    
            cleared();
            callDeleteRelation(L, Q);
            delete Q;
        }
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteListRelation2(ListRelation &L, connect P, connect Q) {
    if (P != NULL && Q != NULL) {    
        connect R = findElmRelation2(L, P -> name, Q -> matkul);
        if (R != NULL) {
            callDeleteRelation(L, R);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
        }
        delete R;
    } else {
        cout << "Maaf, data tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

connect findElmRelation1(ListRelation &L, address1 P, address2 Q) {
    if (Q == NULL) {
        connect R = L.first;
        while (R != NULL && R -> name != P) {
            R = R -> next;
        }
        return R;
    } else if (P == NULL) {
        connect R = L.first;
        while (R != NULL && R -> matkul != Q) {
            R = R -> next;
        }
        return R;
    }
    return NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

connect findElmRelation2(ListRelation &L, address1 P, address2 Q) {
    if (P != NULL && Q != NULL) {
        connect R = L.first;
        while (R != NULL && (R -> matkul != Q || R -> name != P)) {
            R = R -> next;
        }
        return R;
    }
    return NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void printAllRelation(ListRelation L, List1 P, List2 Q) {
    address2 Q1; address1 P1 = P.first;
    int i = 1;
    cout << "Berikut data Parent dan setiap child untuk parent tersebut : " << endl;
    do {
        cout << i++ << ".\nNIM\t\t\t: " << P1 -> info.ID << "\nNama\t\t\t: " << P1 -> info.nama << endl;
        cout << "Mengambil mata kuliah dengan data sebagai berikut : " << endl << endl;
        int j = 1;
        for (connect R = L.first; R != NULL; R = R -> next) {
            if (R -> name == P1) {
                cout << j++ << ". \nMata Kuliah\t\t: " << R -> matkul -> info.matkul << "\nKode Matkul\t\t: " << R -> matkul -> info.kodeMatkul << "\nNilai Kuis\t\t: " << R -> info.kuis << "\nNilai UTS\t\t: " << R -> info.uts << "\nNilai UAS\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t: " << R -> info.Index << endl << endl;
            }
        }
        P1 = P1 -> next;
        cout << "----------------------------------" << endl;
    } while (P1 != P.first);
    cout << endl;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void printChildofParent(ListRelation L, List1 P, List2 Q, string ID) {
    address1 P1 = findElmParent(P, ID);
    for (connect R = L.first; R != NULL; R = R -> next) {
        int j = 1;
        cout << P1 -> info.nama << "Mengambil mata kuliah : " << endl << endl;
        if (R -> name == P1) {
            cout << j++ << ". Mata Kuliah\t\t: " << R -> matkul -> info.matkul << "\nKode Matkul\t\t: " << R -> matkul -> info.kodeMatkul << "\nNilai Kuis\t\t: " << R -> info.kuis << "\nNilai UTS\t\t: " << R -> info.uts << "\nNilai UAS\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t: " << R -> info.Index << endl << endl;
        }
    }
}