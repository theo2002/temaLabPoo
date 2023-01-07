//pro:usor de adaugat obiecte noi, usor de schimbat implementarea obiectelor
//contra: numar mare de clase, adauga inca un nivel de abstractizare
#include <iostream>

using namespace std;
class Volan
{
public:
    virtual void adauga() = 0;
};
class VolanClasic : public Volan
{

    void adauga()
    {
        cout << "Volan clasic\n";
    }
};
class VolanSport : public Volan
{

    void adauga()
    {
        cout << "Volan Sport\n";
    }
};
class Motor
{
public:
    virtual void adauga() = 0;
};
class MotorMic : public Motor
{
public:
    void adauga()
    {
        cout << "Motor de baza\n";
    }
};
class MotorMare : public Motor
{
public:
    void adauga()
    {
        cout << "Motor sport\n";
    }
};
class Scaune
{
public:
    virtual void adauga() = 0;
};
class ScauneClasice : public Scaune
{
public:
    void adauga()
    {
        cout << "Scaune de baza\n";
    }
};
class ScauneSport : public Scaune
{
public:
    void adauga()
    {
        cout << "Scaune Sport\n";
    }
};
class FabricareMasina
{
public:
    virtual Volan *puneVolan() = 0;
    virtual Motor *puneMotor() = 0;
    virtual Scaune *puneScaune() = 0;
};
class FabricareMasinaDeBaza : public FabricareMasina
{
public:
    Volan *puneVolan()
    {
        return new VolanClasic;
    }
    Motor *puneMotor()
    {
        return new MotorMic;
    }
    Scaune *puneScaune()
    {
        return new ScauneClasice;
    }
};
class FabricareMasinaSport : public FabricareMasina
{
public:
    Volan *puneVolan()
    {
        return new VolanSport;
    }
    Motor *puneMotor()
    {
        return new MotorMare;
    }
    Scaune *puneScaune()
    {
        return new ScauneSport;
    }
};
int main()
{
    FabricareMasina *LinieAsamblare;
    Volan *Volan;
    Motor *Motor;
    Scaune *Scaune;

    LinieAsamblare = new FabricareMasinaDeBaza;
    Volan = LinieAsamblare->puneVolan();
    Volan->adauga();
    Motor = LinieAsamblare->puneMotor();
    Motor->adauga();
    Scaune = LinieAsamblare->puneScaune();
    Scaune->adauga();

    LinieAsamblare = new FabricareMasinaSport;
    Volan = LinieAsamblare->puneVolan();
    Volan->adauga();
    Motor = LinieAsamblare->puneMotor();
    Motor->adauga();
    Scaune = LinieAsamblare->puneScaune();
    Scaune->adauga();

    return 0;
}
