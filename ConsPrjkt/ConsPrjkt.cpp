#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <limits>



using namespace std; // Добавил для удобства

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
void waitForEnter() {
    cout << "\nTap Enter...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
void clearScreen() {
    system("cls");
}


int main()
{
    int PzNumS = 0, PzNumZ = 0; 

    int choice;
    double pzFrontS = 0, pzBordS = 0, pzHintenS = 0, pzGeschwindigkeitS = 0, pzKaliberS = 0, pzMasseS = 0;
    double pzFrontZ = 0, pzBordZ = 0, pzHintenZ = 0, pzGeschwindigkeitZ = 0, pzKaliberZ = 0, pzMasseZ = 0;
    string pzNameS, pzNameZ; 
    double entfernung = 0; 
    double Geschwindigkeit = 0, pzMasse = 0, pzKaliber = 0; 
    double pzFront = 0, pzBord = 0, pzHinten = 0;

    do {
        clearScreen();
        cout << "\n--- Hauptmenu ---\n";
        cout << "1. Tech list \n";
        cout << "2. Tank shooting \n";
        cout << "3. Tank target\n";
        cout << "4. Enter the distance\n";
        cout << "5. Make a calculation\n";
        cout << "0. Exit\n";
        cout << "Seine Wahl: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            clearScreen();
            cout << "\n========== Tech list ==========\n\n";

            cout << "1.  T-34-85" << "\t\t\t" << "16. M24 Chaffee" << endl;
            cout << "2.  KV-1 (1941)" << "\t\t\t" << "17. M3 Stuart" << endl;
            cout << "3.  IS-2" << "\t\t\t" << "18. M26 Pershing" << endl;
            cout << "4.  IS-3" << "\t\t\t" << "19. M18 Hellcat" << endl;
            cout << "5.  BT-7" << "\t\t\t" << "20. Churchill Mk VII" << endl;
            cout << "6.  T-26" << "\t\t\t" << "21. Cromwell Mk IV" << endl;
            cout << "7.  Pz.Kpfw. VI Tiger I" << "\t\t" << "22. Valentine Mk IX" << endl;
            cout << "8.  Pz.Kpfw. V Panther" << "\t\t" << "23. Matilda II" << endl;
            cout << "9.  Pz.Kpfw. VI Tiger II" << "\t" << "24. SOMUA S-35" << endl;
            cout << "10. Pz.Kpfw. IV Ausf. H" << "\t\t" << "25. Char B1 bis" << endl;
            cout << "11. Pz.Kpfw. III Ausf. L" << "\t" << "26. Renault R35" << endl;
            cout << "12. Jagdpanther" << "\t\t\t" << "27. Pz.Kpfw. 38(t) Ausf. G" << endl;
            cout << "13. StuG III Ausf. G" << "\t\t" << "28. T-25 (Skoda)" << endl;
            cout << "14. M4A1 Sherman" << "\t\t" << "29. M3 Lee" << endl;
            cout << "15. M4A3E2 Sherman Jumbo" << "\t" << "30. Pz.Kpfw. II Ausf. L" << endl;

            waitForEnter();
   
            break;
        }

        case 2:
        {
            clearScreen();
            ifstream iFile;
            string lineS = "";
            iFile.open("input.csv");

            getline(iFile, lineS);

            cout << "Choice of a shooting tank (1 - 30): ";
            cin >> PzNumS;

            for (int i = 1; i < PzNumS; i++) {
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

            cout << "===== Information about a shooting tank =====" << endl;
            cout << "Tank: " << pzNameS << endl;
            cout << "Front: " << pzFrontS << "mm" << endl;
            cout << "Bord: " << pzBordS << "mm" << endl;
            cout << "Behind: " << pzHintenS << "mm" << endl;
            cout << "Speed of a projectile: " << pzGeschwindigkeitS << "m/c" << endl;
            cout << "Mass of a projectile: " << pzMasseS << "kg" << endl;
            cout << "Caliber: " << pzKaliberS << "mm" << endl;

            Geschwindigkeit = pzGeschwindigkeitS;
            pzMasse = pzMasseS;
            pzKaliber = pzKaliberS;
            iFile.close();

            waitForEnter();
            break;
        }
        case 3:
        {
            clearScreen();
            ifstream iFile;
            string line = "";
            iFile.open("input.csv");
            getline(iFile, line);

            cout << "\n\nChoice of a target tank (1 - 30): ";
            cin >> PzNumZ;

            for (int i = 1; i < PzNumZ; i++) {
                getline(iFile, line);
            }

            getline(iFile, line);
            stringstream ss2(line);
            string cell;

            getline(ss2, cell, ','); pzNameZ = cell;
            getline(ss2, cell, ','); pzFrontZ = stod(cell);
            getline(ss2, cell, ','); pzBordZ = stod(cell);
            getline(ss2, cell, ','); pzHintenZ = stod(cell);
            getline(ss2, cell, ','); pzGeschwindigkeitZ = stod(cell);
            getline(ss2, cell, ','); pzMasseZ = stod(cell);
            getline(ss2, cell, ','); pzKaliberZ = stod(cell);

            cout << "===== Information about a target tank =====" << endl;
            cout << "Tank: " << pzNameZ << endl;
            cout << "Front: " << pzFrontZ << "mm" << endl;
            cout << "Bord: " << pzBordZ << "mm" << endl;
            cout << "Behind: " << pzHintenZ << "mm" << endl;
            cout << "Speed of a projectile: " << pzGeschwindigkeitZ << "m/c" << endl;
            cout << "Mass of a projectile: " << pzMasseZ << "kg" << endl;
            cout << "Caliber: " << pzKaliberZ << "mm" << endl;

            pzFront = pzFrontZ;
            pzBord = pzBordZ;
            pzHinten = pzHintenZ;
            iFile.close();
            waitForEnter();
            break;
        }
        case 4:
        {
            clearScreen();
            cout << "Enter the distance to the tank (m): ";
            cin >> entfernung;
            break;
        }
        case 5:
        {
            clearScreen();
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
                {"\nFrontal armor", pzFrontZ},
                {"Bord armor", pzBordZ},
                {"Back side", pzHintenZ}
            };

            for (const auto& p : projektionen) {
                cout << p.name << ": ";
                if (PzDurch * 100 - 7 > p.wert) {
                    cout << "Target destroyed!\n";
                }
                else {
                    cout << "No damage\n";
                }
            }

            ofstream daten("resultat.txt");
            daten << "Choosing a technique:" << "\n=========================" << endl;
            daten << "Tank shooter: " << pzNameS << endl;
            daten << "Target tank: " << pzNameZ << endl;
            daten << "Distanz: " << entfernung << "m" << endl;
            daten << "\nCalculation results:" << "\n=========================" << endl;
            daten << "Front: " << (PzDurch * 100 - 7 > pzFrontZ ? "Target destroyed!" : "No damage") << endl;
            daten << "Bord: " << (PzDurch * 100 - 7 > pzBordZ ? "Target destroyed!" : "No damage") << endl;
            daten << "Behind: " << (PzDurch * 100 - 7 > pzHintenZ ? "Target destroyed!" : "No damage") << endl;

            daten.close();
            waitForEnter();
            break;
        }
        case 0:
            cout << "The command is completed" << endl;
            break;
        default:
            cout << "Mistake! Enter the correct number" << endl;
        }
    } while (choice != 0);

    return 0;
}