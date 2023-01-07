//pro:ofera interfata simplificata
//contra:ascunde complexitatea sistemului sub o interfata simplificata si poate fi greu de ineteles
#include <iostream>

using namespace std;

class Engine
{
public:
    void start() { cout << "Engine on\n"; }
    void stop()
    { cout<<"Engine off\n";
    }
};

class Lights
{
public:
    void turnOn()
    {  cout << "Lights on\n";
    }
    void turnOff()
    {  cout << "Lights off\n";
    }
    
};

class Radio
{
public:
    void turnOn()
    {  cout << "Radio on\n";
    }
    void turnOff()
    {cout << "Radio off\n";
    }
    // ...
};

// Facade
class Car
{
private:
    Engine *engine_;
    Lights *lights_;
    Radio *radio_;

public:
    Car() : engine_(new Engine()), lights_(new Lights()), radio_(new Radio()) {}
    ~Car()
    {
        delete engine_;
        delete lights_;
        delete radio_;
    }

    void start()
    {
        engine_->start();
        lights_->turnOn();
        radio_->turnOn();
    }

    void stop()
    {
        engine_->stop();
        lights_->turnOff();
        radio_->turnOff();
    }
};

// Client
int main()
{
    Car *car = new Car();
    car->start();
    // ...
    car->stop();
    delete car;
    return 0;
}