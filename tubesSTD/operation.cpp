#include "list.h"

void hitungIndex(connect R) {
    float rata = (R -> info.kuis * (20 /100) + R -> info.uts * (40 / 100) + R -> info.uas * (40 / 100));
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
}

float nilaiMedianMatkul(ListBase L, string st) {
    float arr[100] = {0};
    int i = 0;
    connect P = L.first;
    while (P != NULL) {
        if (P -> matkul -> info.matkul == st) {
            arr[i] = (P -> info.kuis * (20 /100) + P -> info.uts * (40 / 100) + P -> info.uas * (40 / 100));
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
            sum += (P -> info.kuis * (20 /100) + P -> info.uts * (40 / 100) + P -> info.uas * (40 / 100));
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

void cleared() {
    system("cls");
}