#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>


double UnregularRechnung(double pzFrontS, double pzBordS, double pzHintenS, double pzGeschwindigkeitS, double pzMasseS, double pzKaliberS, double entfernung)
{
    double doPzFront = pzFrontS / 100; // Дециметры
    double doPzBoard = pzBordS / 100; // Дециметры
    double doPzHinten = pzHintenS / 100; // Дециметры
    double doPzGeschwindigkeit = pzGeschwindigkeitS; // Метры в секунду
    double doPzKaliber = pzKaliberS / 100; // Дециметры

    double treffer = doPzGeschwindigkeit * pow(2000.0 / (2000.0 + entfernung), 0.28); // Скорость встречи снаряда с целью

    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasseS, 0.71) / pow(doPzKaliber, 1.07));

    return deMarre;
}

double ChaffeRechnung(double pzFrontS, double pzBordS, double pzHintenS, double pzGeschwindigkeitS, double pzMasseS, double pzKaliberS, double entfernung)
{
    double doPzFront = pzFrontS / 100; // Дециметры
    double doPzBoard = pzBordS / 100; // Дециметры
    double doPzHinten = pzHintenS / 100; // Дециметры
    double doPzGeschwindigkeit = pzGeschwindigkeitS; // Метры в секунду
    double doPzKaliber = pzKaliberS / 100; // Дециметры
    
    double base = 2000.0 / (2000.0 + entfernung);

    double treffer = doPzGeschwindigkeit * pow(base, 0.75); // Скорость встречи снаряда с целью

    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasseS, 0.71) / pow(doPzKaliber, 1.07));

    return deMarre;
}

double RegularRechnung(double pzFrontS, double pzBordS, double pzHintenS, double pzGeschwindigkeitS, double pzMasseS, double pzKaliberS, double entfernung)
{
    double doPzFront = pzFrontS / 100; // Дециметры
    double doPzBoard = pzBordS / 100; // Дециметры
    double doPzHinten = pzHintenS / 100; // Дециметры
    double doPzGeschwindigkeit = pzGeschwindigkeitS; // Метры в секунду
    double doPzKaliber = pzKaliberS / 100; // Дециметры
    
    double base = 2000.0 / (2000.0 + entfernung);

    double treffer = doPzGeschwindigkeit * pow(base, 0.65); // Скорость встречи снаряда с целью

    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasseS, 0.71) / pow(doPzKaliber, 1.07));

    return deMarre;
}


int main()
{
    using namespace std;

    int PzNumS, PzNumZ;
    ifstream iFile;
    string lineS = "";
    iFile.open("input.csv");
    
    getline(iFile, lineS);
    string pzNameS;
    double pzFrontS, pzBordS, pzHintenS, pzGeschwindigkeitS, pzKaliberS, pzMasseS;

    cout << "Auswahl eines schiessenden Panzers (1 - 30): ";
    cin >> PzNumS;

    for (int i = 1; i < PzNumS - 1; i++) {
        getline(iFile, lineS);
    }
    
    getline(iFile, lineS);
    stringstream ss(lineS);
    string cell;

    getline(ss, cell, ','); pzNameS = cell;
    getline(ss, cell, ','); pzFrontS = stod(cell);
    getline(ss, cell, ','); pzBordS = stod(cell);
    getline(ss, cell, ','); pzHintenS = stod(cell);
    getline(ss, cell, ','); pzGeschwindigkeitS = stod(cell);
    getline(ss, cell, ','); pzMasseS = stod(cell);
    getline(ss, cell, ','); pzKaliberS = stod(cell);

    cout << "Tank: " << pzNameS << endl;
    cout << "Front: " << pzFrontS << "mm" << endl;
    cout << "Bord: " << pzBordS << "mm" << endl;
    cout << "Hinten: " << pzHintenS << "mm" << endl;
    cout << "Geschossgeschwindigkeit: " << pzGeschwindigkeitS << "m/c" << endl;
    cout << "Geschossmasse: " << pzMasseS << "kg" << endl;
    cout << "Kaliber: " << pzKaliberS << "mm" << endl;

    
    iFile.clear();    // Сброс флагов ошибок
    iFile.seekg(0);
    string line = "";

    getline(iFile, line);
    string pzNameZ;
    double pzFrontZ, pzBordZ, pzHintenZ, pzGeschwindigkeitZ, pzKaliberZ, pzMasseZ;

    cout << "Auswahl eines ZeilPanzers (1 - 30): ";
    cin >> PzNumZ;

    for (int i = 1; i < PzNumZ - 1; i++) {
        getline(iFile, line);
    }

    getline(iFile, line);
    stringstream ss2(line);

    getline(ss2, cell, ','); pzNameZ = cell;
    getline(ss2, cell, ','); pzFrontZ = stod(cell);
    getline(ss2, cell, ','); pzBordZ = stod(cell);
    getline(ss2, cell, ','); pzHintenZ = stod(cell);
    getline(ss2, cell, ','); pzGeschwindigkeitZ = stod(cell);
    getline(ss2, cell, ','); pzMasseZ = stod(cell);
    getline(ss2, cell, ','); pzKaliberZ = stod(cell);

    cout << "Tank: " << pzNameZ << endl;
    cout << "Front: " << pzFrontZ << "mm" << endl;
    cout << "Bord: " << pzBordZ << "mm" << endl;
    cout << "Hinten: " << pzHintenZ << "mm" << endl;
    cout << "Geschossgeschwindigkeit: " << pzGeschwindigkeitZ << "m/c" << endl;
    cout << "Geschossmasse: " << pzMasseZ << "kg" << endl;
    cout << "Kaliber: " << pzKaliberZ << "mm" << endl;

    


    cout << "Geben Sie die Entfernung zum Ziel ein(m): ";
    double entfernung;
    cin >> entfernung;
    
    if (pzNameS.find("Panther") != string::npos || pzNameS.find("Jagdpanther") != string::npos) {
        
        cout << "\nAntwort nach der Formel de Marra: " << UnregularRechnung(pzFrontS, pzBordS, pzHintenS, 
            pzGeschwindigkeitS, pzMasseS, pzKaliberS, entfernung) << endl;
    }
    else if (pzNameS.find("Chaffee") != string::npos) {
        cout << "\nAntwort nach der Formel de Marra: " << ChaffeRechnung(pzFrontS, pzBordS, pzHintenS, pzGeschwindigkeitS, pzMasseS, pzKaliberS, entfernung) << endl;
    }
    else
    {
        cout << "\nAntwort nach der Formel de Marra: " << RegularRechnung(pzFrontS, pzBordS, pzHintenS, pzGeschwindigkeitS, pzMasseS, pzKaliberS, entfernung) << endl;
    }

    iFile.close();
    return 0;
}