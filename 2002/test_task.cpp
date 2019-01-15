#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
    bool status;

public:
    User()
    {
        username = "";
        password = "";
        status = false;
    }

    User(string _username, string _password, bool _status)
    {
        username = _username;
        password = _password;
        status = _status;
    }

    User(User& value)
    {
        username = value.username;
        password = value.password;
        status = value.status;
    }

    void setName(const string _username)
    {
        username = _username;
    }
    void setPassword(const string _password)
    {
        password = _password;
    }
    void setStatus(bool _status)
    {
        status = _status;
    }

    string getName()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    bool getStatus()
    {
        return status;
    }
};

struct Data {
    User data;
    Data* next;
};

class Database {
private:
    Data* start;
    int members_count;

public:
    Database()
    {
        start = NULL;
        members_count = 0;
    }

    void addMember(User& value)
    {
        members_count++;
        if (members_count == 1) {
            start = new Data;
            start->data.setName(value.getName());
            start->data.setPassword(value.getPassword());
            start->data.setStatus(value.getStatus());
            start->next = NULL;
        }
        else {
            Data* iter = start;
            Data* place;
            while (value.getName() > iter->data.getName()) {
                if (iter->next == NULL) {
                    Data* last = new Data;
                    last->data.setName(value.getName());
                    last->data.setPassword(value.getPassword());
                    last->data.setStatus(value.getStatus());
                    last->next = NULL;
                    iter->next = last;
                    return;
                }
                else {
                    place = iter;
                    iter = iter->next;
                }
            }

            if (iter == start) {
                Data* first = new Data;
                first->data.setName(value.getName());
                first->data.setPassword(value.getPassword());
                first->data.setStatus(value.getStatus());
                first->next = start;
                start = first;
            }
            else {
                place->next = new Data;
                place->next->data.setName(value.getName());
                place->next->data.setPassword(value.getPassword());
                place->next->data.setStatus(value.getStatus());
                place->next->next = iter;
            }
        }
    }

    void printDatabase() const
    {
        Data* iter = start;
        while (iter != NULL) {
            cout << iter->data.getName() << " " << iter->data.getPassword() << " " << iter->data.getStatus() << endl;
            iter = iter->next;
        }

        cout << "Total members: " << members_count << endl;
    }

    User& findMember(string _username)
    {
        Data* iter = start;
        while (iter != NULL) {
            if (iter->data.getName() == _username)
                return iter->data;
            else
                iter = iter->next;
        }
        User* def = new User("", "", false);
        return *def;
    }
};

int main()
{
    Database database;
    int n;
    string operation, username, password;
    User* current;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> operation;
        cin >> username;
        if (operation != "logout")
            cin >> password;
        current = &database.findMember(username);
        if (current->getName() == "" && (operation == "login" || operation == "logout")) {
            cout << "fail: no such user" << endl;
            continue;
        }
        if (operation == "register" && current->getName() != "") {
            cout << "fail: user already exists" << endl;
            continue;
        }
        else if (operation == "register") {
            current->setName(username);
            current->setPassword(password);
            database.addMember(*current);
            cout << "success: new user added" << endl;
            continue;
            cout << "IDK";
        }
        else if (operation == "login") {

            if (current->getPassword() != password)
                cout << "fail: incorrect password" << endl;
            else if (current->getStatus() == true)
                cout << "fail: already logged in" << endl;
            else {
                current->setStatus(true);
                cout << "success: user logged in" << endl;
            }
        }
        else if (operation == "logout") {
            if (current->getStatus() == false)
                cout << "fail: already logged out" << endl;
            else {
                cout << "success: user logged out" << endl;
                current->setStatus(false);
            }
        }
    }

    return 0;
}
