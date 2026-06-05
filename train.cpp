#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Passenger {
public:
    int id;
    string name;
    string password;

    Passenger(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
};

class TrainBookingSystem {
private:
    vector<Passenger> users;
    vector<Passenger> confirmed;

    queue<Passenger> rac;
    queue<Passenger> waiting;

    int nextId = 1;

    const int CONFIRMED_LIMIT = 2;
    const int RAC_LIMIT = 2;
    const int WAITING_LIMIT = 2;

public:

    void registerUser() {
        string name, password;

        cout << "Enter username: ";
        cin >> name;

        cout << "Enter password: ";
        cin >> password;

        Passenger p(nextId++, name, password);
        users.push_back(p);

        cout << "Registration Successful\n";
        cout << "User ID: " << p.id << endl;
    }

    Passenger* login() {
        string name, password;

        cout << "Username: ";
        cin >> name;

        cout << "Password: ";
        cin >> password;

        for(auto &u : users) {
            if(u.name == name && u.password == password) {
                cout << "Login Successful\n";
                return &u;
            }
        }

        cout << "Invalid Credentials\n";
        return nullptr;
    }

    void bookTicket(Passenger &p) {

        if(confirmed.size() < CONFIRMED_LIMIT) {
            confirmed.push_back(p);
            cout << "Confirmed Ticket Booked\n";
        }

        else if(rac.size() < RAC_LIMIT) {
            rac.push(p);
            cout << "Added to RAC\n";
        }

        else if(waiting.size() < WAITING_LIMIT) {
            waiting.push(p);
            cout << "Added to Waiting List\n";
        }

        else {
            cout << "No Tickets Available\n";
        }
    }

    void cancelTicket(int id) {

        bool found = false;

        for(auto it = confirmed.begin(); it != confirmed.end(); it++) {

            if(it->id == id) {

                confirmed.erase(it);
                found = true;

                cout << "Ticket Cancelled\n";

                if(!rac.empty()) {

                    Passenger racPassenger = rac.front();
                    rac.pop();

                    confirmed.push_back(racPassenger);

                    cout << racPassenger.name
                         << " moved from RAC to Confirmed\n";

                    if(!waiting.empty()) {

                        Passenger waitPassenger = waiting.front();
                        waiting.pop();

                        rac.push(waitPassenger);

                        cout << waitPassenger.name
                             << " moved from Waiting to RAC\n";
                    }
                }

                break;
            }
        }

        if(!found)
            cout << "Confirmed Ticket Not Found\n";
    }

    void displayStatus() {

        cout << "\n===== CONFIRMED =====\n";

        for(auto &p : confirmed)
            cout << p.id << " " << p.name << endl;

        cout << "\n===== RAC =====\n";

        queue<Passenger> tempRac = rac;

        while(!tempRac.empty()) {
            cout << tempRac.front().id << " "
                 << tempRac.front().name << endl;
            tempRac.pop();
        }

        cout << "\n===== WAITING =====\n";

        queue<Passenger> tempWait = waiting;

        while(!tempWait.empty()) {
            cout << tempWait.front().id << " "
                 << tempWait.front().name << endl;
            tempWait.pop();
        }
    }
};

int main() {

    TrainBookingSystem system;

    while(true) {

        cout << "\n1.Register\n";
        cout << "2.Login & Book Ticket\n";
        cout << "3.Cancel Ticket\n";
        cout << "4.Display Status\n";
        cout << "5.Exit\n";

        int choice;
        cin >> choice;

        switch(choice) {

        case 1:
            system.registerUser();
            break;

        case 2: {
            Passenger *user = system.login();

            if(user)
                system.bookTicket(*user);

            break;
        }

        case 3: {
            int id;

            cout << "Enter Passenger ID: ";
            cin >> id;

            system.cancelTicket(id);
            break;
        }

        case 4:
            system.displayStatus();
            break;

        case 5:
            return 0;
        }
    }
}