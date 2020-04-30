#include "listParent.h"

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void createListParent(List1 &L) {
    L.first = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

// void generateID(List1 L, infotypeParent &P, int &jumlah) {           // fungsi auto generate NIM.
//     string nama, fakultas, jurusan, angkatan;
//     cout << "Masukkan nama anda : ";
//     cin >> nama;
//     cout << "Masukkan fakultas anda (Informatika, Industri, Elektro) : ";
//     cin >> fakultas;
//     jumlah++;
//     string id_x = "";
//     if (fakultas == "informatika" || fakultas == "Informatika") {
//         id_x += "130";
//         cout << "Masukkan jurusan anda (Informatika, komputer) : ";
//         cin >> jurusan;
//         if (jurusan == "informatika" || fakultas == "Informatika") {
//             id_x += '1';
//         } else if (jurusan == "komputer" || jurusan == "Komputer") {
//             id_x += '2';
//         }
//     } else if (fakultas == "Fisika" || fakultas == "fisika") {
//         id_x += "120";
//         cout << "Masukkan jurusan anda (fisika) : ";
//         cin >> jurusan;
//         if (jurusan == "fisika" || jurusan == "Fisika") {
//             id_x += '1';
//         }
//     } else {
//         id_x += "110";
//         cout << "Masukkan jurusan anda (telekomunikasi) : ";
//         cin >> jurusan;
//         if (jurusan == "telekomunikasi" || jurusan == "Telekomunikasi") { 
//             id_x += '1';
//         }
//     }
//     cout << "Masukkan anda angkatan berapa (2000 - 2999): ";
//     cin >> angkatan;
//     id_x += angkatan[2]; id_x += angkatan[3];
//     stringstream ss;
//     ss << jumlah;
//     string mahasiswa_ke = ss.str();
//     if (mahasiswa_ke.size() == 1) {
//         id_x += "000"; id_x += mahasiswa_ke;
//     } else if (mahasiswa_ke.size() == 2) {
//         id_x += "00"; id_x += mahasiswa_ke;
//     } else if (mahasiswa_ke.size() == 3) { 
//         id_x += "0"; id_x += mahasiswa_ke;
//     } else {
//         id_x += mahasiswa_ke;
//     }
//   
//     P.nama = nama;
//     P.ID = id_x;
//     cout << "Berikut ini adalah NIM anda : " << P.ID;
// }

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

address1 CreateElmParent(infotypeParent st) {
    address1 P = new parent;
    P -> info = st;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

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

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void insertAfterParent(List1 &L, address1 Prec, address1 P) {
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void insertlastParent(List1 &L, address1 P) {
    P -> next = L.first;
    P -> prev = L.first -> prev;
    L.first -> prev -> next = P;
    L.first -> prev = P;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

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

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void insertSortParent(List1 &L, infotypeParent st) {
    if (L.first == NULL) {
        insertFirstParent(L, CreateElmParent(st));
        cout << "Program Run Success! [Press Enter to Continue]. . .";
    } else if (L.first -> info.ID > st.ID && findElmParent(L, st.ID) == NULL) {
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
        cout << "Maaf, nama anda sudah terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";            
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

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

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteAfterParent(List1 &L, address1 Prec, address1 &P) {
    P = Prec -> next;
    P -> next -> prev = Prec;
    Prec -> next = P -> next;
    P -> next = NULL;
    P -> prev = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteLastParent(List1 &L, address1 &P) {
    P = L.first -> prev;
    P -> prev -> next = L.first;
    L.first -> prev = P -> prev;
    P -> next = NULL;
    P -> prev = NULL;
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void deleteListParent(List1 &L, string st) {
    address1 P = findElmParent(L, st);
    if (P != NULL) {
        if (P == L.first) {
            deleteFirstParent(L, P);
        } else if (P -> next != NULL && P -> prev != NULL) {
            deleteAfterParent(L, P -> prev, P);
        }
        delete P;
    }
}

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

void printInfoParent(List1 L) {
    address1 P = L.first;
    int i = 1;
    if (P != NULL) {
        do {
            cout << i << ". Nama\t: " << P -> info.nama << "\t||\tNIM\t: " << P -> info.ID << endl;
            P = P -> next;
            i++;
        } while (P != L.first);
    }
    cout << endl;
}