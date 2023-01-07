//pro:Putem adauga tipuri noi de subscriberi fara sa schimbam publisherul.
//contra:subscriberii sunt notificati in ordinea in care au fost adaugati.

#include <iostream>
#include <vector>

using namespace std;

class Subscriber
{
public:
    virtual void update(string message) = 0;
};

class Account1 : public Subscriber
{
public:
    void update(string message)
    {
        cout << "Account 1 has been notified: " << message << endl;
    }
};

class Account2 : public Subscriber
{
public:
    void update(string message)
    {
        cout << "Account 2 has been notified: " << message << endl;
    }
};

class Publisher
{
private:
    vector<Subscriber *> subscribers;
    string latestMessage;

public:
    void addSubscriber(Subscriber *subscriber)
    {
        subscribers.push_back(subscriber);
    }
    void unsubscribe(Subscriber *subscriber)
    {
        for (int i = 0; i < subscribers.size(); i++)
        {
            if (subscribers[i] == subscriber)
            {
                subscribers.erase(subscribers.begin() + i);
            }
        }
    }
    void notifySubscribers()
    {
        for (int i = 0; i < subscribers.size(); i++)
        {
            subscribers[i]->update(this->latestMessage);
        }
    }
    void setLatestMessage(string message)
    {
        latestMessage = message;
        notifySubscribers();
    }
};

int main()
{

    Publisher youtube;

    youtube.addSubscriber(new Account1);
    youtube.addSubscriber(new Account2);
    youtube.addSubscriber(new Account1);
    youtube.addSubscriber(new Account2);

    youtube.setLatestMessage("New video is available!");
    youtube.setLatestMessage("New app is available!");

    return 0;
}