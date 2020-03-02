#include "list.h"

int main() {
    int choice = 0;
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
        cout<<"4. delete nama mahasiswa"<<endl;
        cout<<"5. delete mata kuliah"<<endl;
        cout<<"6. delete data mahasiswa dengan mata kuliah"<<endl;
        cout<<"7. print list mahasiswa"<<endl;
        cout<<"8. print list mata kuliah"<<endl;
        cout<<"9. print semua data mahasiswa dengan mata kuliah dan nilai"<<endl;
        cout<<"10. mencari median matkul"<<endl;
        cout<<"11. mencari rata-rata nilai matkul"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"input choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cleared();
            cout << "Masukkan nama : ";
            cin.get();
            getline(cin, parent.nama);
            cout << "Masukkan kelas anda : ";
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
            cout << "Masukkan nama anda : ";
            getline(cin, parent.nama);
            cout << "Anda mengambil mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmParent(mahasiswa, parent.nama) != NULL && findElmChild(matakuliah, child.matkul) != NULL && findElmBaseAll(Base, findElmParent(mahasiswa, parent.nama), findElmChild(matakuliah, child.matkul)) == NULL) {
                insertBase(Base, CreateElmBase(findElmParent(mahasiswa, parent.nama), findElmChild(matakuliah, child.matkul)));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, anda tidak terdaftar dalam mahasiswa atau mata kuliah tidak terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 4:
            cleared();
            cout << "Masukkan nama : ";
            getline(cin, parent.nama);
            if (findElmParent(mahasiswa, parent.nama) != NULL) {
                deleteListParent(mahasiswa, parent.nama);
                if (findElmBasebyName(Base, parent.nama) != NULL) {
                    deleteBasebyName(Base, findElmBasebyName(Base, parent.nama));
                }
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 5:
            cleared();
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmChild(matakuliah, child.matkul) != NULL) {
                deleteListChild(matakuliah, child.matkul);
                if (findElmBasebyCourse(Base, child.matkul) != NULL) {
                    deleteBasebyName(Base, findElmBasebyCourse(Base, child.matkul));
                }
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 6:
            cleared();
            cout << "Masukkan nama : ";
            getline(cin, parent.nama);
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            R = findElmBaseAll(Base, findElmParent(mahasiswa, parent.nama), findElmChild(matakuliah, child.matkul));
            if (R != NULL) {
                deleteBasebyName(Base, R);
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 7:
            cleared();
            printInfoParent(mahasiswa);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 8:
            cleared();
            printInfoChild(matakuliah);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 9:
            cleared();
            printInfoBase(Base);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 10:
            cleared();
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmBasebyCourse(Base, child.matkul) != NULL) {
                cout << nilaiMedianMatkul(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 11:
            cleared();
            cout << "Masukkan mata kuliah : ";
            getline(cin, child.matkul);
            if (findElmBasebyCourse(Base, child.matkul) != NULL) {
                cout << nilaiRerata(Base, child.matkul);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 12:
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