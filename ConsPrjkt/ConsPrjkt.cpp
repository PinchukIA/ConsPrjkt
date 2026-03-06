#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>


double UnregularRechnung(double pzGeschwindigkeit, double pzMasse, double pzKaliber, double entfernung)
{
    double doPzGeschwindigkeit = pzGeschwindigkeit; // Метры в секунду
    double doPzKaliber = pzKaliber / 100; // Дециметры

    double treffer = doPzGeschwindigkeit * pow(2000.0 / (2000.0 + entfernung), 0.28); // Скорость встречи снаряда с целью

    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasse, 0.71) / pow(doPzKaliber, 1.07));

    return deMarre;
}

double ChaffeRechnung(double pzGeschwindigkeit, double pzMasse, double pzKaliber, double entfernung)
{
    double doPzGeschwindigkeit = pzGeschwindigkeit; // Метры в секунду
    double doPzKaliber = pzKaliber / 100; // Дециметры
    
    double base = 2000.0 / (2000.0 + entfernung);
    double treffer = doPzGeschwindigkeit * pow(base, 0.75); // Скорость встречи снаряда с целью
    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasse, 0.71) / pow(doPzKaliber, 1.07));

    return deMarre;
}

double RegularRechnung(double pzGeschwindigkeit, double pzMasse, double pzKaliber, double entfernung)
{
    double doPzGeschwindigkeit = pzGeschwindigkeit; // Метры в секунду
    double doPzKaliber = pzKaliber / 100; // Дециметры
    
    double base = 2000.0 / (2000.0 + entfernung);
    double treffer = doPzGeschwindigkeit * pow(base, 0.65); // Скорость встречи снаряда с целью
    double deMarre = pow(treffer / 2000.0, 1.43) * (pow(pzMasse, 0.71) / pow(doPzKaliber, 1.07));

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

    cout << "===== Informationen zum Schiesspanzer =====" << endl;
    cout << "Tank: " << pzNameS << endl;
    cout << "Front: " << pzFrontS << "mm" << endl;
    cout << "Bord: " << pzBordS << "mm" << endl;
    cout << "Hinten: " << pzHintenS << "mm" << endl;
    cout << "Geschossgeschwindigkeit: " << pzGeschwindigkeitS << "m/c" << endl;
    cout << "Geschossmasse: " << pzMasseS << "kg" << endl;
    cout << "Kaliber: " << pzKaliberS << "mm" << endl;

    double Geschwindigkeit = pzGeschwindigkeitS;
    double pzMasse = pzMasseS;
    double pzKaliber = pzKaliberS;


    iFile.clear();    // Сброс флагов ошибок
    iFile.seekg(0);
    string line = "";

    getline(iFile, line);
    string pzNameZ;
    double pzFrontZ, pzBordZ, pzHintenZ, pzGeschwindigkeitZ, pzKaliberZ, pzMasseZ;

    cout << "\n\nAuswahl eines ZeilPanzers (1 - 30): ";
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

    cout << "===== Informationen zum Zieltank =====" << endl;
    cout << "Tank: " << pzNameZ << endl;
    cout << "Front: " << pzFrontZ << "mm" << endl;
    cout << "Bord: " << pzBordZ << "mm" << endl;
    cout << "Hinten: " << pzHintenZ << "mm" << endl;
    cout << "Geschossgeschwindigkeit: " << pzGeschwindigkeitZ << "m/c" << endl;
    cout << "Geschossmasse: " << pzMasseZ << "kg" << endl;
    cout << "Kaliber: " << pzKaliberZ << "mm" << endl;

    double pzFront = pzFrontZ;
    double pzBord = pzBordZ;
    double pzHinten = pzHintenZ;

    cout << "Geben Sie die Entfernung zum Ziel ein(m): ";
    double entfernung;
    cin >> entfernung;
    double PzDurch;

    if (pzNameS.find("Panther") != string::npos || pzNameS.find("Jagdpanther") != string::npos) {
        PzDurch = UnregularRechnung(Geschwindigkeit, pzMasse, pzKaliber, entfernung);
        
    }
    else if (pzNameS.find("Chaffee") != string::npos) {
        PzDurch = ChaffeRechnung(Geschwindigkeit, pzMasse, pzKaliber, entfernung);
    }
    else { 
        PzDurch = RegularRechnung(Geschwindigkeit, pzMasse, pzKaliber, entfernung);
    }
    struct Projektion {
        string name;
        double wert;
    } projektionen[] = {
        {"Frontalrustung", pzFrontZ},
        {"Bordpanzer", pzBordZ},
        {"Rustungsruckseite", pzHintenZ}
    };

    for (const auto& p : projektionen) {
        cout << p.name << ": ";
        if (PzDurch * 100 - 7 > p.wert) {
            cout << "Durchschlag!\n";
        }
        else {
            cout << "kein Schaden\n";
        }
    }

    ofstream daten("resultat.txt");
    daten << "Choosing a technique:" << "\n=========================" << endl;
    daten << "Tank shooter: " << pzNameS << endl;
    daten << "Target tank: " << pzNameZ << endl;
    daten << "Distanz: " << entfernung << " m" << endl;
    daten << "\nCalculation results:" << "\n=========================" << endl;
    daten << "Front: " << (PzDurch * 100 - 7 > pzFrontZ ? "Durchschlag" : "Kein Schaden") << endl;
    daten << "Bord: " << (PzDurch * 100 - 7 > pzBordZ ? "Durchschlag" : "Kein Schaden") << endl;
    daten << "Hinten: " << (PzDurch * 100 - 7 > pzHintenZ ? "Durchschlag" : "Kein Schaden") << endl;


    daten.close();

    iFile.close();
    return 0;
}