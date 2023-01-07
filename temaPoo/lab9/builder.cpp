//pro: cod usor de urmarit si inteles, facil in a realiza mai multe variante cu acelasi cod usor modificat
//contra: multe tipuri de clase, adauga inca un nivel de abstractizare
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Burger{
    public:
    vector<string> ingrediente;
    void listaIngrediente() {
        cout<<"Burger-ul contine:\n";
        for(string ingredient : ingrediente){
            cout<<ingredient<<'\n';
        }
        cout<<'\n';
        }
};

class Angajat{
    public:
    virtual ~Angajat(){}
    virtual void puneChifla()=0;
    virtual void puneSos()=0;
    virtual void puneSalata()=0;
    virtual void puneRosii()=0;
    virtual void puneCarne()=0;
    virtual void puneBranza()=0;
    virtual void puneMuraturi()=0;
    virtual void puneCeapa()=0;

};
class AngajatBK: public Angajat{
    private:
    Burger* burger;
    public:
    AngajatBK(){
        this->Reset();
    }
    ~AngajatBK(){
        delete burger;
    }
    void Reset(){
        this->burger = new Burger();
    }
    void puneChifla(){
        this->burger->ingrediente.push_back("Chifla cu seminte");
    }
    void puneSos(){
        this->burger->ingrediente.push_back("Mustar de Tecuci");
    }
     void puneSalata(){
        this->burger->ingrediente.push_back("Salata Jilava");
    }
    void puneRosii(){
        this->burger->ingrediente.push_back("Rosii Drobeta");
    }
     void puneCarne(){
        this->burger->ingrediente.push_back("Carne BK");
    }
    void puneBranza(){
        this->burger->ingrediente.push_back("Branza Cheddar");
    }
     void puneMuraturi(){
        this->burger->ingrediente.push_back("Muraturi Olympia");
    }
     void puneCeapa(){
        this->burger->ingrediente.push_back("Ceapa rosie de Buzau");
    }

    Burger* aduceBurger(){
        Burger* result = this->burger;
        this->Reset();
        return result;
    }
};
class Director{
    private:
     Angajat* angajat;
     public:
     Director(Angajat* angajat){
        this->angajat=angajat;
     }
     void schimbaAngajat(Angajat* angajat){
        this->angajat=angajat;
     }

     void facemBurger(string fel){
        this->angajat->puneChifla();
        if(fel =="clasic"){
            this->angajat->puneSos();
            this->angajat->puneSalata();
            this->angajat->puneRosii();
            this->angajat->puneCarne();
            this->angajat->puneBranza();
            this->angajat->puneMuraturi();
            this->angajat->puneCeapa();

        }
        else if(fel =="fara sos"){
            this->angajat->puneSalata();
            this->angajat->puneRosii();
            this->angajat->puneCarne();
            this->angajat->puneBranza();
            this->angajat->puneMuraturi();
            this->angajat->puneCeapa();
        }
         else  if(fel =="vegetarian"){
            this->angajat->puneSos();
            this->angajat->puneSalata();
            this->angajat->puneRosii();
            this->angajat->puneBranza();
            this->angajat->puneMuraturi();
            this->angajat->puneCeapa();
        }

     }
     

};
int main(){

AngajatBK* angajat = new AngajatBK();
Director* sef = new Director(angajat);

sef->facemBurger("clasic");
Burger *burger = angajat->aduceBurger();
burger->listaIngrediente();

delete angajat;

angajat = new AngajatBK();
sef->schimbaAngajat(angajat);

sef->facemBurger("vegetarian");
burger=angajat->aduceBurger();
burger->listaIngrediente();
    return 0;
}