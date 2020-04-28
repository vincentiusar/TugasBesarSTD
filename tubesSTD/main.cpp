#include "listBase.h"

// Nama     : Vincentius Arnold fridolin
// NIM      : 1301190221

int main() {
    int choice = 0;// unix_code = 0;   // unix_code : kode unik jumlah mahasiswa yang ada.
    string st;
    address1 P; address2 Q;
    infotypeParent parent;
    infotypeChild child;
    List1 mahasiswa;
    List2 matakuliah;
    ListBase Base;
    connect R;
    createListParent(mahasiswa);
    createListChild(matakuliah);
    createListBase(Base);
    cout << "|| PROGRAM MAHASISWA DAN MATA KULIAH ||\n\nProgram ini menyatakan hubungan mahasiswa dengan mata kuliah.\nIsi dari data mahasiswa adalah NIM dan nama.\nSementara isi data dari mata kuliah adalah kode matakuliah dan matakuliah.\nKeduanya dihubungkan oleh List relasi yang berisi pointer ke parent, child,\ndan di dalam list relasi terdapat 3 nilai integer serta index (nilai).\n\nDemikian penjelasan singkat ini.\n\n[Press Enter to Continue]. . .";
    cin.get();
    do {
        cleared();
        cout << "Menu" << endl;
        cout << "1. Insert list nama" << endl;
        cout << "2. Insert list mata kuliah" << endl;
        cout << "3. Insert data mahasiswa yang mengambil mata kuliah dan nilainya" << endl;
        cout << "4. Delete nama / mata kuliah mahasiswa" << endl;
        cout << "5. Delete data mahasiswa yang mengambil mata kuliah" << endl;
        cout << "6. Mencari data mahasiswa dan menampilkan data" << endl;
        cout << "7. Print mahasiswa terdaftar / mata kuliah terdaftar / Data Lengkap Mahasiswa" << endl;
        cout << "8. Mencari median kodeMatkul" << endl;
        cout << "9. Mencari rata-rata nilai kodeMatkul" << endl;
        cout << "10. Export data mahasiswa ke dalam .txt" << endl;
        cout << "0. Exit" << endl;
        cout << "input choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cleared();
            // Penggunaan generateID untuk menggenerate NIM sendiri. Namun 
            // ketika menggenerate ID, terdapat 2 sudut pandang. Pertama jika
            // kita memandang bahwa nama misal "kevin" sudah terdaftar, maka tidak
            // boleh ada kevin lagi yang terdaftar. Kedua jika kita memandang nama 
            // "kevin" pertama adalah seorang bernama kevin, kemudian ketika ada
            // nama "kevin" didaftarkan lagi, maka kevin tersebut bukan kevin yang
            // tadi sudah mendaftar. Sehingga dampaknya adalah dalam List adalah ada
            // data yang bernama sama, tetapi berbeda orang.
            // generateID(mahasiswa, parent, unix_code);
            cout << "Masukkan nama anda : ";
            cin.get();
            getline(cin, parent.nama);
            cout << "Masukkan NIM anda : ";
            getline(cin, parent.ID);
            insertSortParent(mahasiswa, parent);
            cin.get();
            break;
        case 2:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin.get();
            getline(cin, child.matkul);
            cout << "Masukkan kode matkul : ";
            getline(cin, child.kodeMatkul);
            insertSortChild(matakuliah, child);
            cin.get();
            break;
        case 3:
            cleared();
            cout << "Masukkan ID anda : ";
            cin.get();
            getline(cin, parent.ID);
            printInfoChild(matakuliah);
            cout << "Masukkan kode mata kuliah anda : ";
            getline(cin, child.kodeMatkul);
            P = findElmParent(mahasiswa, parent.ID);
            Q = findElmChild(matakuliah, child.kodeMatkul);
            R = findElmBase2(Base, P, Q);
            if (P != NULL && Q != NULL && R == NULL) {
                insertBase(Base, CreateElmBase(P, Q));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
                cin.get();
            } else {
                cout << "Maaf, anda tidak terdaftar dalam mahasiswa atau mata kuliah tidak terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            break;
        case 4:
            cleared();
            cout << "Menghapus 1. mahasiswa / 2. matakuliah \n(pilih 1 / 2) : ";
            cin >> st;
            if (st == "1") {
                cleared();
                cout << "Masukkan ID : ";
                cin.get();
                getline(cin, parent.ID);
                P = findElmParent(mahasiswa, parent.ID);
                if (P != NULL) {
                    R = findElmBase1(Base, P, NULL);
                    deleteListParent(mahasiswa, parent.ID);
                    while (R != NULL) {
                        deleteListBase1(Base, R, NULL);
                        R = findElmBase1(Base, P, NULL);
                    }
                    cout << "Program Run Success! [Press Enter to Continue]. . .";
                } else {
                    cout << "Maaf, NIM tidak ditemukan!\nProgram Run Success! [Press Enter to Continue]. . .";
                }
                cin.get();
            } else if (st == "2") {
                cleared();
                printInfoChild(matakuliah);
                cout << "Masukkan kode mata kuliah : ";
                cin.get();
                getline(cin, child.kodeMatkul);
                Q = findElmChild(matakuliah, child.kodeMatkul);
                if (Q != NULL) {
                    R = findElmBase1(Base, NULL, Q);
                    deleteListChild(matakuliah, child.kodeMatkul);
                    while (R != NULL) {
                        deleteListBase1(Base, NULL, R);
                        R = findElmBase1(Base, NULL, Q);
                    }
                    cout << "Program Run Success! [Press Enter to Continue]. . .";
                } else {
                    cout << "Maaf, Kode matkul tidak ditemukan!\nProgram Run Success! [Press Enter to Continue]. . .";
                }
                cin.get();
            } else {
                cout << "Maaf. Anda pilih apa?\n\n";
                cout << "Program Run Success! [Press Enter to Continue]. . .";
                cin.get();
            }
            break;
        case 5:
            cleared();
            cout << "Masukkan ID : ";
            cin.get();
            getline(cin, parent.ID);
            printInfoChild(matakuliah);
            cout << "Masukkan kode matkul : ";
            getline(cin, child.kodeMatkul);
            P = findElmParent(mahasiswa, parent.ID);
            Q = findElmChild(matakuliah, child.kodeMatkul);
            deleteListBase2(Base, findElmBase1(Base, P, NULL), findElmBase1(Base, NULL, Q));
            cin.get();
            break;
        case 6:
            cleared();
            cout << "Masukkan ID mahasiswa : "; cin >> parent.ID;
            P = findElmParent(mahasiswa, parent.ID);
            cout << "Masukkan kode mata kuliah : "; cin >> child.kodeMatkul;
            Q = findElmChild(matakuliah, child.kodeMatkul);
            R = findElmBase2(Base, P, Q);
            if (R != NULL) {
                cout << "Data ditemukan!" << endl;
                printData(R, P, Q);
                cout << "Program Run Success! [Press Enter to Continue]. . .";
                cin.get();
            } else {
                cout << "Maaf, data tidak ditemukan\nProgram Run Success! [Press Enter to Continue]. . .";
                cin.get();
            }
            cin.get();
            break;
        case 7:
            cleared();
            cout << "1. Mencetak List Mahasiswa / 2. Mata Kuliah / 3. Data Lengkap Mahasiswa \n(1 / 2 / 3) : ";
            cin >> st;
            if (st == "1") {
                printInfoParent(mahasiswa);
            } else if (st == "2") {
                printInfoChild(matakuliah);
            } else if (st == "3") {
                cout << "1. Print All Relation / 2. Print data dari seorang mahasiswa (1 / 2) : "; cin >> st;
                if (st == "1") {
                    printAllRelation(Base, mahasiswa, matakuliah);
                } else if (st == "2") {
                    cout << "Masukkan ID mahasiswa : "; cin >> st;
                    printChildofParent(Base, mahasiswa, matakuliah, st);
                }
            }
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 8:
            cleared();
            printInfoChild(matakuliah);
            cout << "Masukkan kode mata kuliah : ";
            cin.get();
            getline(cin, child.kodeMatkul);
            Q = findElmChild(matakuliah, child.kodeMatkul);
            if (findElmBase1(Base, NULL, Q) != NULL) {
                cout << nilaiMedianMatkul(Base, child.kodeMatkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            break;
        case 9:
            cleared();
            printInfoChild(matakuliah);
            cout << "Masukkan kode mata kuliah : ";
            cin.get();
            getline(cin, child.kodeMatkul);
            if (findElmBase1(Base, NULL, findElmChild(matakuliah, child.kodeMatkul)) != NULL) {
                cout << nilaiRerata(Base, child.kodeMatkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            break;
        case 10: 
            cleared();
            toText(Base, mahasiswa, matakuliah);
            break;
        case 11:
            cleared();
            printInfoParent(mahasiswa);
            printInfoChild(matakuliah);
            printAllRelation(Base, mahasiswa, matakuliah);
            cin.get();
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
        }
        if (choice == 0) {
            break;
        }
    } while (true);
}
