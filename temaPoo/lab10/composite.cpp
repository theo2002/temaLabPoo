//pro:putem introduce obiecte noi fara a strica codul existent.
//contra:Poate fi dificil de implementat un obiect nou a carui functionalitate difera prea mult.

#include <iostream>

using namespace std;

class Component
{
public:
    virtual void doWork() = 0;
};

class Pencil : public Component
{
public:
    void doWork()
    {
        cout << "With the Pencil you can draw" << endl;
    }
};

class Eraser : public Component
{
public:
    void doWork()
    {
        cout << "With the Eraser you can erase" << endl;
    }
};

class Notebook : public Component
{
public:
    void doWork()
    {
        cout << "On the Notebook you can write" << endl;
    }
};

class Book : public Component
{
public:
    void doWork()
    {
        cout << "From the Book you can read" << endl;
    }
};

class SchoolBag : public Component
{
private:
    Component *components[10];
    int k = 0;

public:
    void doWork()
    {
        for (int i = 0; i < k; i++)
        {
            components[i]->doWork();
        }
    }

    void add(Component *component)
    {
        if (k < 10)
        {
            components[k] = component;
            k++;
        }
    }

    void remove(Component *component)
    {
        if (k > 0)
            k--;
    }
};

int main()
{

    SchoolBag *schoolbag = new SchoolBag();
    SchoolBag *buzunar = new SchoolBag();
    buzunar->add(new Pencil());
    buzunar->add(new Eraser());

    SchoolBag *buzunar2 = new SchoolBag();
    buzunar2->add(new Pencil());
    buzunar2->add(new Eraser());
    buzunar2->add(new Notebook());

    schoolbag->add(buzunar);
    schoolbag->add(buzunar2);

    schoolbag->doWork();

    return 0;
}