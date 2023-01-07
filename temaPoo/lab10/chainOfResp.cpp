//pro: putem controla ordinea handle requesturilor, putem introduce noi handleri fara a strica codul existent.
//contra:unele requesturi pot fi ignorate, ramase nehandleruite.

#include <iostream>

using namespace std;

class Handler
{
public:
    virtual void handleRequest(string request) = 0;
    virtual Handler *nextHandler(Handler *handler) = 0;
};

class BaseHandler : public Handler
{
private:
    Handler *next;

public:
    Handler *nextHandler(Handler *handler)
    {
        next = handler;

        return handler;
    }
    void handleRequest(string request)
    {
        if (next != NULL)
        {
            next->handleRequest(request);
        }
    }
};

class CasierBanca : public BaseHandler
{
public:
    void handleRequest(string request)
    {
        if (request == "depunere")
        {
            cout << "Casier Banca: Ma ocup de depunere!" << endl;
        }
        else
        {
            BaseHandler::handleRequest(request);
        }
    }
};

class ManagerBanca : public BaseHandler
{
public:
    void handleRequest(string request)
    {
        if (request == "imprumut")
        {
            cout << "Manager Banca: Ma ocup de imprumut!" << endl;
        }
        else
        {
            BaseHandler::handleRequest(request);
        }
    }
};

class CEOBanca : public BaseHandler
{
public:
    void handleRequest(string request)
    {
        if (request == "cumparareBanca")
        {
            cout << "CEO Banca: Ma ocup de vanzarea bancii!" << endl;
        }
        else
        {
            BaseHandler::handleRequest(request);
        }
    }
};

int main()
{
    Handler *casierBanca = new CasierBanca();
    Handler *managerBanca = new ManagerBanca();
    Handler *ceoBanca = new CEOBanca();

    casierBanca->nextHandler(managerBanca)->nextHandler(ceoBanca);
    casierBanca->handleRequest("depunere");
    casierBanca->handleRequest("imprumut");
    casierBanca->handleRequest("cumparareBanca");

    return 0;
}