#include "listBase.h"

int main() {
    int choice = 0;
    string st;
    infotypeParent parent;
    infotypeChild child;
    List1 mahasiswa;
    List2 matakuliah;
    ListBase Base;
    connect R;
    createListParent(mahasiswa);
    createListChild(matakuliah);
    createListBase(Base);
    cout << "Selamat Datang di Mesin Otomatis!!" << endl;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. insert list nama"<<endl;
        cout<<"2. insert list mata kuliah"<<endl;
        cout<<"3. insert data mahasiswa yang mengambil mata kuliah dan nilainya"<<endl;
        cout<<"4. delete nama / mata kuliah mahasiswa"<<endl;
        cout<<"5. delete data mahasiswa dengan mata kuliah"<<endl;
        cout<<"6. print list mahasiswa"<<endl;
        cout<<"7. print list mata kuliah"<<endl;
        cout<<"8. print semua data mahasiswa dengan mata kuliah dan nilai"<<endl;
        cout<<"9. mencari median matkul"<<endl;
        cout<<"10. mencari rata-rata nilai matkul"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"input choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cleared();
            cout << "Masukkan ID anda : ";
            cin.get();
            getline(cin, parent.ID);
            cout << "Masukkan Nama anda : ";
            getline(cin, parent.nama);
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
            if (findElmParent(mahasiswa, parent.ID) != NULL && findElmChild(matakuliah, child.matkul) != NULL || findElmBase(Base, findElmParent(mahasiswa, parent.nama), findElmChild(matakuliah, child.matkul)) == NULL) {
                insertBase(Base, CreateElmBase(findElmParent(mahasiswa, parent.ID), findElmChild(matakuliah, child.matkul)));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, anda tidak terdaftar dalam mahasiswa atau mata kuliah tidak terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 4:
            cleared();
            cout << "Menghapus 1. mahasiswa / 2. matakuliah (pilih 1 / 2) : ";
            cin >> st;
            if (st == "1") {
                cleared();
                cout << "Masukkan ID : ";
                cin.get();
                getline(cin, parent.ID);
                deleteListParent(mahasiswa, parent.ID);
                deleteListBase(Base, findElmBase(Base, findElmParent(mahasiswa, parent.ID), NULL), NULL);
                cout << "Program Run Success! [Press Enter to Continue]. . .";
                cin.get();
            } else if (st == "2") {
                cleared();
                cout << "Masukkan mata kuliah : ";
                cin.get();
                getline(cin, child.matkul);
                deleteListChild(matakuliah, child.matkul);
                deleteListBase(Base, NULL, findElmBase(Base, NULL, findElmChild(matakuliah, child.matkul)));
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
            deleteListBase(Base, findElmBase(Base, findElmParent(mahasiswa, parent.ID), NULL), findElmBase(Base, NULL, findElmChild(matakuliah, child.matkul)));
            cin.get();
            break;
        case 6:
            cleared();
            printInfoParent(mahasiswa);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 7:
            cleared();
            printInfoChild(matakuliah);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 8:
            cleared();
            printInfoBase(Base);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 9:
            cleared();
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmBase(Base, NULL, findElmChild(matakuliah, child.matkul)) != NULL) {
                cout << nilaiMedianMatkul(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 10:
            cleared();
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmBase(Base, NULL, findElmChild(matakuliah, child.matkul)) != NULL) {
                cout << nilaiRerata(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 11:
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
