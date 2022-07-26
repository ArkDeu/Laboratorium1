#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class osoba
{
public:
    osoba();
    ~osoba();
    static int aktualnie_w_systemie;
    static int id_ostatniego;
    int id;
    int wiek;
    string imie;
    string nazwisko;
    string plec;
    string miasto;
    osoba(string imie, string nazwisko = "brak", int wiek = 0);
    static void info();
    void przedstaw();
};

int osoba::aktualnie_w_systemie;
int osoba::id_ostatniego;

osoba::osoba()
{
    imie = "";
    nazwisko = "";
    wiek = 0;
    aktualnie_w_systemie++;
    id_ostatniego++;
    id = id_ostatniego;
}

void osoba::info()
{
    cout << "dotychczas utworzono:" << osoba::id_ostatniego << "obiektow" << endl;
    cout << "obecnie w systemie mamy: " << osoba::aktualnie_w_systemie << "obiektow" << endl;
}

int main()
{
    std::ifstream ifs;

    string temp;
    ifstream wejscie("plik.txt");
    getline(wejscie, temp);
    osoba::id_ostatniego = atoi(temp.c_str());
    osoba::aktualnie_w_systemie = 0;

    ofstream wyjscie("plik.txt", ios::trunc);
    wyjscie << osoba::id_ostatniego;

    ifs.close();
    return 0;
}