#include "list.h"

float nilaiMedianMatkul(ListBase L, string st) {
    float arr[100] = {0};
    int i = 0;
    connect P = L.first;
    while (P != NULL) {
        if (P -> matkul -> info == st) {
            arr[i] = P -> info.nilai;
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
        if (P -> matkul -> info == st) {
            sum += P -> info.nilai;
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