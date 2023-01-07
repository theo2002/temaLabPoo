//pro: consum de memorie redus pentru mai multe instante ale aceleiasi clase(una activa), gestionare centralizata(o singura instanta)
//contra:greu de modificat si intretinut
#include <iostream>
using namespace std;
class Singleton {
    private: 
    static Singleton* ptrLaObiect;
    Singleton(){
        cout<<"Am facut obiect acum\n";
    }
    public:
    static Singleton* getInstance(){
        if(ptrLaObiect==NULL){
            ptrLaObiect = new Singleton();
        }
        else{
            cout<<"Ai obiect facut deja\n";
        }
        return ptrLaObiect;
    }
};
Singleton* Singleton::ptrLaObiect = NULL;
int main(){

Singleton* Obiect1 = Singleton::getInstance();
Obiect1->getInstance();
Singleton::getInstance();




    return 0;
}