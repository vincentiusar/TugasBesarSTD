#include "listBase.h"

int main() {
    int choice = 0;// unix_code = 0;
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
    cout << "Selamat Datang di Mesin Otomatis!!\nPenjelasan Nanti Dibuat\n\n[Press Enter to Continue]. . .";
    cin.get();
    do {
        cleared();
        cout<<"Menu"<<endl;
        cout<<"1. insert list nama"<<endl;
        cout<<"2. insert list mata kuliah"<<endl;
        cout<<"3. insert data mahasiswa yang mengambil mata kuliah dan nilainya"<<endl;
        cout<<"4. delete nama / mata kuliah mahasiswa"<<endl;
        cout<<"5. delete data mahasiswa dengan mata kuliah"<<endl;
        cout<<"6. print mahasiswa terdaftar / mata kuliah terdaftar / Data Lengkap Mahasiswa"<<endl;
        cout<<"7. mencari median matkul"<<endl;
        cout<<"8. mencari rata-rata nilai matkul"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"input choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cleared();
            // Penggunaan generateID untuk menggenerate NIM sendiri. Namun terjadi 
            // bug karena ketika menggenerate ID, jika nama, jurusan, fakultas, dan
            // angkatan sudah pernah ada, maka tidak akan terjadi generate ID.
            // Sehingga dampaknya adalah dalam List adalah dipastikan tidak ada
            // data yang memiliki ID sama.
            //generateID(mahasiswa, parent, unix_code);
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
            cout << "Masukkan dosen anda : ";
            getline(cin, child.dosen);
            insertSortChild(matakuliah, child);
            cin.get();
            break;
        case 3:
            cleared();
            cout << "Masukkan ID anda : ";
            cin.get();
            getline(cin, parent.ID);
            cout << "Anda mengambil mata kuliah : ";
            getline(cin, child.matkul);
            P = findElmParent(mahasiswa, parent.ID);
            Q = findElmChild(matakuliah, child.matkul);
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
                R = findElmBase1(Base, P, NULL);
                deleteListParent(mahasiswa, parent.ID);
                while (R != NULL) {
                    deleteListBase1(Base, R, NULL);
                    R = findElmBase1(Base, P, NULL);
                }
                cin.get();
            } else if (st == "2") {
                cleared();
                cout << "Masukkan mata kuliah : ";
                cin.get();
                getline(cin, child.matkul);
                Q = findElmChild(matakuliah, child.matkul);
                R = findElmBase1(Base, P, NULL);
                deleteListChild(matakuliah, child.matkul);
                while (R != NULL) {
                    deleteListBase1(Base, NULL, R);
                    R = findElmBase1(Base, NULL, Q);
                }
                cout << "Program Run Success! [Press Enter to Continue]. . .";
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
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            P = findElmParent(mahasiswa, parent.ID);
            Q = findElmChild(matakuliah, child.matkul);
            deleteListBase2(Base, findElmBase1(Base, P, NULL), findElmBase1(Base, NULL, Q));
            cin.get();
            break;
        case 6:
            cleared();
            cout << "1. Mencetak List Mahasiswa / 2. Mata Kuliah / 3. Data Lengkap Mahasiswa \n(1 / 2 / 3) : ";
            cin >> st;
            if (st == "1") {
                printInfoParent(mahasiswa);
            } else if (st == "2") {
                printInfoChild(matakuliah);
            } else if (st == "3") {
                printInfoBase(Base);
            }
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 7:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin.get();
            getline(cin, child.matkul);
            if (findElmBase1(Base, NULL, findElmChild(matakuliah, child.matkul)) != NULL) {
                cout << nilaiMedianMatkul(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            break;
        case 8:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin.get();
            getline(cin, child.matkul);
            if (findElmBase1(Base, NULL, findElmChild(matakuliah, child.matkul)) != NULL) {
                cout << nilaiRerata(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            break;
        case 9:
            cleared();
            printInfoParent(mahasiswa);
            printInfoChild(matakuliah);
            printInfoBase(Base);
            cin.get();
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
        }
        if (choice == 0) {
            break;
        }
    } while (true);
}
