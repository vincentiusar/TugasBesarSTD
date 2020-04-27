#include "listBase.h"

void hitungIndex(connect &R) {
    float rata = (R -> info.kuis * (0.2) + R -> info.uts * (0.4) + R -> info.uas * (0.4));
    if (rata >= 80) {
        R -> info.Index = "A";
    } else if (rata < 80 && rata >= 70) {
        R -> info.Index = "AB";
    } else if (rata < 70 && rata >= 65) {
        R -> info.Index = "B";
    } else if (rata < 65 && rata >= 60) {
        R -> info.Index = "BC";
    } else if (rata < 60 && rata >= 50) {
        R -> info.Index = "C";
    } else if (rata < 50 && rata >= 40) {
        R -> info.Index = "D";
    } else {
        R -> info.Index = "E";
    }
    R -> info.rerata = rata;
}

float nilaiMedianMatkul(ListBase L, string st) {
    float arr[100] = {0};
    int i = 0;
    connect P = L.first;
    while (P != NULL) {
        if (P -> matkul -> info.matkul == st) {
            arr[i] = (P -> info.kuis * (0.2) + P -> info.uts * (0.4) + P -> info.uas * (0.4));
            i++;
        }
        P = P -> next;
    }
    if (i % 2 == 1) {
        return arr[i/2];
    } else {
        return (arr[i/2] + arr[i/2 - 1]) / 2;
    }
}

float nilaiRerata(ListBase L, string st) {
    connect P = L.first;
    float sum = 0;
    int nData = 0;
    while (P != NULL) {
        if (P -> matkul -> info.matkul == st) {
            sum += (P -> info.kuis * (0.2) + P -> info.uts * (0.4) + P -> info.uas * (0.4));
            nData++;
        }
        P = P -> next;
    }
    if (nData != 0) {
        return sum / nData;
    } else {
        return 0;
    }
}

void printData(connect R, address1 P, address2 Q) {
    cout << "Berikut data anda : " << endl; 
    cout << "Nama\t\t\t" << P -> info.nama << "\nMata Kuliah\t\t: " << Q -> info.matkul << "\nNilai Kuis\t\t: " << R -> info.kuis << "\nNilai UTS\t\t: " << R -> info.uts << "\nNilai UAS\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t: " << R -> info.Index << endl;
}

void cleared() {
    system("cls");
}

void toText(ListBase L, List1 P, List2 Q) {
    string myfilename;
    cout << "Masukkan nama file : "; cin >> myfilename; 
    ofstream myfile(myfilename + ".txt", ofstream::trunc);
    address2 Q1; address1 P1 = P.first;
    int i = 1;
    myfile << "Berikut data Parent dan setiap child untuk parent tersebut : " << endl << endl;
    do {
        myfile << i++ << ".\nNIM\t\t\t\t: " << P1 -> info.ID << "\nNama\t\t\t: " << P1 -> info.nama << endl;
        myfile << "Mengambil mata kuliah dengan data sebagai berikut : " << endl << endl;
        int j = 1;
        for (connect R = L.first; R != NULL; R = R -> next) {
            if (R -> name == P1) {
                myfile << j++ << ". \nMata Kuliah\t\t\t: " << R -> matkul -> info.matkul << "\nKode Matkul\t\t\t: " << R -> matkul -> info.kodeMatkul << "\nNilai Kuis\t\t\t: " << R -> info.kuis << "\nNilai UTS\t\t\t: " << R -> info.uts << "\nNilai UAS\t\t\t: " << R -> info.uas << "\nNilai Keseluruhan\t: " << R -> info.rerata << "\nIndex\t\t\t\t: " << R -> info.Index << endl << endl;
            }
        }
        P1 = P1 -> next;
        myfile << "----------------------------------" << endl;
    } while (P1 != P.first);
    myfile << endl;
    myfile.close();
}