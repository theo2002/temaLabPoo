
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;
//clasa pentru mebru al cast-ului
class CastMember
{
private:
    string foodType;

public:
    string name;
    string getFoodType()
    {
        return this->foodType;
    }
    //atribuire tip de dieta
    void assignFoodType(int randNum)
    {
        string dieta[3] = {"fara restrictii", "vegetarian", "flexitarian"};
        this->foodType = dieta[randNum];
    }
};
//clasa pentru actori si figuranti
class PlayingCast : public CastMember
{
public:
    string monsterType;
    //atribuire tip de monstru (in constructor)
    PlayingCast()
    {
        string monstrii[5] = {"Varcolac", "Vampir", "Sirena", "Clarvazator", "Om"};
        int max = 5;
        int randNum = rand() % max;

        this->monsterType = monstrii[randNum];
    }
};
//clasa pt compeltarea castului cu figuranti(in constructor)
class completeCast
{
public:
    completeCast()
    {
        int a = 0;
        int randNum1, randNum2;
        int max = 10; 
        srand(time(0));

        ifstream myFile;
        myFile.open("firstnames.txt");
        string firstNames[10];

        while (myFile.good())
        {
            getline(myFile, firstNames[a]); 
            a++;
        }
        myFile.close();
        a = 0;
        myFile.open("lastnames.txt");
        string lastNames[10];

        while (myFile.good())
        {
            getline(myFile, lastNames[a]); 
            a++;
        }
        myFile.close();

        string randomNames[132];
        for (int i = 0; i < 132; i++) 
        {

            randNum1 = rand() % max;
            randNum2 = rand() % max;

            randomNames[i] = firstNames[randNum1] + " " + lastNames[randNum2];
        }
        fstream fout;
        fout.open("wednesdayCast.csv", ios::out | ios::app);
        for (auto name : randomNames)
        {
            fout << name << ",figurant\n";
        }
        fout.close();
    }
    //identficare nr total de membrii in cast
    int count()
    {
        string filename = "wednesdayCast.csv"; // Name of the file

        string line1;  // To read each line from code
        int count = 0; // Variable to keep count of each line

        ifstream mFile(filename);
        if (mFile.is_open())
        {
            while (mFile.peek() != EOF)
            {
                getline(mFile, line1);
                count++;
            }
            mFile.close();
        }
        return count;
    }
};
// clasa de baza meniu
class Menu
{
public:
    string supaCiorba;
    string felPrincipal;
    string desert;
//atribuire fel de mancare
    string assignDish(string filename)
    {
        int a = 0;
        int randNum;
        int max = 10; // set the upper bound to generate the random number

        ifstream myFile;
        myFile.open(filename);
        string dishList[10];

        while (myFile.good())
        {
            getline(myFile, dishList[a]); 
            a++;
        }
        myFile.close();
        randNum = rand() % max;
        return dishList[randNum];
    }
//declarare atribuire pentru fiecare fel de mancare
    virtual void assignCiorba() = 0;
    virtual void assignFel() = 0;
    void assignDesert()
    {
        this->desert = assignDish("desert.txt");
    }
};
//clasa meniu fara restrictii
class DefaultMenu : public Menu
{
public:
    void assignCiorba()
    {
        this->supaCiorba = assignDish("supaCiorba.txt");
    }
    void assignFel()
    {
        this->felPrincipal = assignDish("felPrincipal.txt");
    }
};
//clasa meniu vegetarian
class VegMenu : public Menu
{
public:
    void assignCiorba()
    {
        this->supaCiorba = assignDish("supaCiorbaVeg.txt");
    }
    void assignFel()
    {
        this->felPrincipal = assignDish("felPrincipalVeg.txt");
    }
};
//clasa meniu flexitarian
class FlexMenu : public Menu
{
public:
    void assignCiorba()
    {
        this->supaCiorba = assignDish("supaCiorbaFlex.txt");
    }
    void assignFel()
    {
        this->felPrincipal = assignDish("felPrincipalVeg.txt");
    }
};
//clasa pentru calcularea costurilor
class Costs
{
public:
    int nrOfDays;
    //transmiterea ca parametru a numarului de zile pentru filmari in constructor
    Costs(int nrOfDays)
    {
        this->nrOfDays = nrOfDays;
    }
    //costul de transport
    int tansportationCost(int totalnr)
    {
        int nrOfBusses, busCost = 5680, totalCost, seats = 50;
        nrOfBusses = totalnr / seats;
        if (totalnr % seats != 0)
            nrOfBusses++;
        totalCost = 2 * nrOfBusses * busCost;
        return totalCost;
    }
    //costul pentru cazare
    int accomodationCost(int totalnr)
    {
        int nrfig = 132, nrinitcast = totalnr - nrfig, twoprice = 350, threeprice = 420, nrtwo, nrthree, costPerDay, totalCost;
        nrtwo = nrinitcast / 2;
        if (nrinitcast % 2 != 0)
            nrtwo++;
        nrthree = nrfig / 3;
        if (nrfig % 3 != 0)
            nrthree++;
        costPerDay = (nrtwo * twoprice) + (nrthree * threeprice);
        totalCost = costPerDay * nrOfDays;
        return totalCost;
    }
    //costul pentru machiaje
    int makeUpCost(vector<PlayingCast> Actori)
    {
        int vampNr = 0, varcNr = 0, sirNr = 0, clarNr = 0, omNr = 0;
        int vampPr = 230, varcPr = 555, sirPr = 345, clarPr = 157, omPr = 55;
        int costPerDay, totalCost;
        for (int i = 0; i < Actori.size(); i++)
        {
            if (Actori[i].monsterType == "Vampir")
                vampNr++;
            else if (Actori[i].monsterType == "Varcolac")
                varcNr++;
            else if (Actori[i].monsterType == "Sirena")
                sirNr++;
            else if (Actori[i].monsterType == "Clarvazator")
                clarNr++;
            else if (Actori[i].monsterType == "Varcolac")
                omNr++;
        }
        costPerDay = (vampNr * vampPr) + (varcNr * varcPr) + (sirNr * sirPr) + (clarNr * clarPr) + (omNr * omPr);
        totalCost = costPerDay * nrOfDays;
        return totalCost;
    }
    //costul pentru mancare
    int foodCost(vector<CastMember> Membs)
    {
        int defPr = 40, vegPr = 33, flexPr = 46;
        int defNr = 0, vegNr = 0, flexNr = 0;
        int costPerDay, totalCost;
        for (int i = 0; i < Membs.size(); i++)
        {
            if (Membs[i].getFoodType() == "fara restrictii")
                defNr++;
            else if (Membs[i].getFoodType() == "vegetarian")
                vegNr++;
            else if (Membs[i].getFoodType() == "flexitarian")
                flexNr++;
        }
        costPerDay = (defNr * defPr) + (vegNr * vegPr) + (flexNr * flexPr);
        totalCost = costPerDay * nrOfDays;
        return totalCost;
    }
    //costul pentru bauturi insa returnez doar costul pentru apa pentru ca asta scrie in cerinta ca trebuie sa afisez
    float drinksCost(int totalnr)
    {
        int qwaterPerPers = 1;
        float qcoffeePerPers = 0.5, qjuicePerPers = 0.8;
        int waterPr2L = 6, coffeePr1L = 30, juicePr2L = 8;
        int waterPrPerDay, coffeePrPerDay, juicePrPerDay;
        float drinksPrPerDay, totalCost;
        waterPrPerDay = (qwaterPerPers * totalnr) / (waterPr2L / 2);
        if (qwaterPerPers * totalnr % 2 != 0)
            waterPrPerDay += waterPr2L;
        coffeePrPerDay = (qcoffeePerPers * totalnr) / coffeePr1L;
        juicePrPerDay = int(qwaterPerPers * totalnr) / (juicePr2L / 2);
        if ((qwaterPerPers * totalnr) - int(qwaterPerPers * totalnr) > 0)
            juicePrPerDay += juicePr2L;
        drinksPrPerDay = waterPrPerDay + coffeePrPerDay + juicePrPerDay;
        totalCost = drinksPrPerDay * nrOfDays;
        return waterPrPerDay * nrOfDays;
    }
    //costul pentru inchirierea castelului
    float locationCost()
    {
        float costPerDay = 10000, totalCost = 0;
        for (int i = 0; i <= nrOfDays; i += 10)
        {
            totalCost = totalCost + 10 * costPerDay;
            costPerDay = costPerDay - ((2.0 / 100) * costPerDay);
        }
        return totalCost;
    }
    //transformare din lei in dolari la data de 07/01/2023
    float toDollar(int lei)
    {
        return lei / 4.65;
    }
    //afisare costuri in fisier
    void afisare(vector<PlayingCast> ActSiFig, vector<CastMember> Cast, int count)
    {
        fstream fout;
        fout.open("costuri.csv", ios::out | ios::app);
        fout << "Costuri pentru " << nrOfDays << " zile\n";
        fout << "Transport,Cazare,Machiaj,Mancare si Apa, Inchiriere spatiu\n";
        fout << fixed << this->toDollar(tansportationCost(count)) << "," << toDollar(this->accomodationCost(count)) << "," << toDollar(this->makeUpCost(ActSiFig)) << "," << toDollar(this->foodCost(Cast) + this->drinksCost(count)) << "," << toDollar(this->locationCost());
        fout << '\n';

        fout.close();
    }
};
//clasa generare si afisare meniuri la 3 zile
class MenuCreator
{
public:
    DefaultMenu dMenu;
    VegMenu vMenu;
    FlexMenu fMenu;
    int nrMenus;

    MenuCreator(int nrzile)
    {
        nrMenus = nrzile / 3;
        if (nrzile % 3 != 0)
            nrMenus++;
        string menu[nrMenus + 1][4];
        int k = 1;
        menu[0][0] = "interval meniu";
        menu[0][1] = "meniu normal";
        menu[0][2] = "meniu vegetarian";
        menu[0][3] = "meniu flexitarian";

        for (int i = 0; i < nrMenus; i++)
        {
            dMenu.assignCiorba();
            dMenu.assignFel();
            dMenu.assignDesert();
            menu[i + 1][0] = to_string(k) + "-" + to_string(k + 2);
            menu[i + 1][1] = dMenu.supaCiorba + " | " + dMenu.felPrincipal + " | " + dMenu.desert;
            vMenu.assignCiorba();
            vMenu.assignFel();
            vMenu.assignDesert();
            menu[i + 1][2] = vMenu.supaCiorba + " | " + vMenu.felPrincipal + " | " + vMenu.desert;
            fMenu.assignCiorba();
            fMenu.assignFel();
            fMenu.assignDesert();
            menu[i + 1][3] = fMenu.supaCiorba + " | " + fMenu.felPrincipal + " | " + fMenu.desert;
            k = k + 3;
        }

        fstream fout;
        fout.open("menu.csv", ios::out | ios::app);
        fout << "Meniu pentru " << nrzile << " zile\n";
        for (int i = 0; i <= nrMenus; i++)
        {
            fout << menu[i][0] << "," << menu[i][1] << "," << menu[i][2] << "," << menu[i][3];
            fout << '\n';
        }
        fout.close();
    }
    ~MenuCreator(){};
};
int main()
{

    completeCast Completare;
    int count = Completare.count();
    //citire fisier cu intregul cast
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file("wednesdayCast.csv", ios::in);
    try
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        //salvare cast intr un vector
            vector<CastMember> Insi;
            for (int i = 0; i < count; i++)
            {
                CastMember Ins;
                Ins.name = content[i][0];
                int randNum = rand() % 3;
                Ins.assignFoodType(randNum);
                Insi.push_back(Ins);
            }
            int countPlC = 0;
            //salvare actori si figuratie intr un vector
            vector<PlayingCast> ActoriSiFiguratie;
            for (int i = 0; i < count; i++)
            {
                string s1 = content[i][1];
                string s2 = "actor";
                string s3 = "figurant";
                class PlayingCast ActorSauFiguratie;
                if (s1.find(s2) != string::npos || s1.find(s3) != string::npos)
                {
                    ActorSauFiguratie.name = content[i][0];
                    ActoriSiFiguratie.push_back(ActorSauFiguratie);
                    countPlC++;
                }
            }
            class Costs Cheltuieli1(30);
            Cheltuieli1.afisare(ActoriSiFiguratie, Insi, countPlC);
            class Costs Cheltuieli2(45);
            Cheltuieli2.afisare(ActoriSiFiguratie, Insi, countPlC);
            class Costs Cheltuieli3(60);
            Cheltuieli3.afisare(ActoriSiFiguratie, Insi, countPlC);
            class Costs Cheltuieli4(100);
            Cheltuieli4.afisare(ActoriSiFiguratie, Insi, countPlC);

            MenuCreator Meniu1(30);
            MenuCreator Meniu2(45);
            MenuCreator Meniu3(60);
            MenuCreator Meniu4(100);
            
        }
        else
            throw 1;
    }
    catch (int x)
    {
        cout << "ceva nu merge";
    }

    return 0;
}
