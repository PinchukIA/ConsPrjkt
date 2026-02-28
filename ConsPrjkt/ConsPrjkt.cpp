#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>


double UnregularRechnung(int pzFront, int pzBord, int pzHinten, int pzGeschwindigkeit, int pzKaliber, double entfernung)
{
    double doPzFront = static_cast<double>(pzFront) / 100; // Дециметры
    double doPzBoard = static_cast<double>(pzBord) / 100; // Дециметры
    double doPzHinten = static_cast<double>(pzHinten) / 100; // Дециметры
    double doPzGeschwindigkeit = static_cast<double>(pzGeschwindigkeit); // Метры в секунду
    double doPzKaliber = static_cast<double>(pzKaliber) / 100; // Дециметры

    double treffer = doPzGeschwindigkeit * pow(2000.0 / (2000.0 + entfernung), 0.28); // Скорость встречи снаряда с целью



    return 0;
}
double RegularRechnung(int pzFront, int pzBord, int pzHinten, int pzGeschwindigkeit, int pzKaliber, double entfernung)
{
    double doPzFront = static_cast<double>(pzFront) / 100; // Дециметры
    double doPzBoard = static_cast<double>(pzBord) / 100; // Дециметры
    double doPzHinten = static_cast<double>(pzHinten) / 100; // Дециметры
    double doPzGeschwindigkeit = static_cast<double>(pzGeschwindigkeit); // Метры в секунду
    double doPzKaliber = static_cast<double>(pzKaliber) / 100; // Дециметры
    double base = 2000.0 / (2000.0 + entfernung);

    double treffer = doPzGeschwindigkeit * pow(base, 0.65); // Скорость встречи снаряда с целью


    return 0;
}

int main()
{
    using namespace std;

    int PzNum;
    ifstream iFile;
    string line = "";
    iFile.open("input.csv");
    
    getline(iFile, line);
    string pzName;
    int pzFront, pzBord, pzHinten, pzGeschwindigkeit, pzMasse, pzKaliber;

    cout << "Gib mir nummer des Tanks (1 - 30): ";
    cin >> PzNum;

    for (int i = 1; i < PzNum - 1; i++) {
        getline(iFile, line);
    }
    
    getline(iFile, line);
    stringstream ss(line);
    string cell;

    getline(ss, cell, ','); pzName = cell;
    getline(ss, cell, ','); pzFront = stoi(cell);
    getline(ss, cell, ','); pzBord = stoi(cell);
    getline(ss, cell, ','); pzHinten = stoi(cell);
    getline(ss, cell, ','); pzGeschwindigkeit = stoi(cell);
    getline(ss, cell, ','); pzMasse = stoi(cell);
    getline(ss, cell, ','); pzKaliber = stoi(cell);

    cout << "Tank: " << pzName << endl;
    cout << "Front: " << pzFront << "mm" << endl;
    cout << "Bord: " << pzBord << "mm" << endl;
    cout << "Hinten: " << pzHinten << "mm" << endl;
    cout << "Geschossgeschwindigkeit: " << pzGeschwindigkeit << "m/c" << endl;
    cout << "Geschossmasse: " << pzMasse << "kg" << endl;
    cout << "Kaliber: " << pzKaliber << "mm" << endl;

    cout << "Geben Sie die Entfernung zum Ziel ein(m): ";
    double entfernung;
    cin >> entfernung;
    
    if (pzName == "Pz.Kpfw. V Panther" || pzName == "Jagdpanther") {
        cout << "Zum Zeitpunkt der Kollision hat das Geschoss eine Geschwindigkeit von " << UnregularRechnung(pzFront, pzBord, pzHinten, pzGeschwindigkeit, pzKaliber, entfernung) << " m/c" << endl;
    }
    else
    {
        cout << "Geschoss hat " << RegularRechnung(pzFront, pzBord, pzHinten, pzGeschwindigkeit, pzKaliber, entfernung) 
            << " m/c Geschwindigkeit" << endl;
    }


    iFile.close();
    return 0;
}
