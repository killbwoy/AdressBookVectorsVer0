#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Contact {
    int id;
    string name;
    string surname;
    string phoneNum;
    string email;
    string adress;
};
char checkChoice() {
    string input;
    char sign = {0};

    while(true) {
        cin.sync();
        getline(cin,input);
        if(input.length() == 1) {
            sign = input[0];
            break;
        } else {
            cout << "Enter correct number !" << endl;
        }
    }
    return sign;
}
string readLine() {
    string line;
    cin.sync();
    getline(cin,line);
    return line;
}
void addContact(vector<Contact> &people) {

    string name, surname, phoneNum, email, adress;
    Contact person;

    if(people.size() == 0) {
        person.id = 1;
    } else {
        person.id = people[people.size() - 1].id + 1;
    }
    system("cls");
    cout << "-------- ADDING NEW PERSON -------" << endl;
    cout << "==================================" << endl;
    cout << "Enter the name: ";
    person.name = readLine();
    cout << "Enter the surname: ";
    person.surname = readLine();
    cout << "Enter phone number: ";
    person.phoneNum = readLine();
    cout << "Enter email: ";
    person.email = readLine();
    cout << "Enter adress: ";
    person.adress = readLine();

    people.push_back(person);

    fstream file;
    file.open("adressbook.txt", ios::out | ios::app);
    if(file.good()) {
        file << person.id << "|" << person.name << "|" << person.surname << "|" << person.phoneNum << "|" << person.email << "|" << person.adress << "|" << endl;
        file.close();
    }
    cout << endl;
    cout << "Person has been successfully added to contacts" << endl;
    Sleep(2000);
}
void loadNotepad(vector <Contact> &people) {
    string dataInLine = "";
    Contact person;
    fstream file;
    file.open("adressbook.txt", ios::in);

    if(file.good()) {
        while(getline(file, dataInLine)) {
            string individalPersonalData = "";
            int singlePersonNumber = 1;
            for(int i = 0; i < dataInLine.length(); i++) {
                if(dataInLine[i] != '|') {
                    individalPersonalData += dataInLine[i];
                } else {
                    switch(singlePersonNumber) {
                    case 1:
                        person.id = stoi(individalPersonalData);
                        break;
                    case 2:
                        person.name = individalPersonalData;
                        break;
                    case 3:
                        person.surname = individalPersonalData;
                        break;
                    case 4:
                        person.phoneNum = individalPersonalData;
                        break;
                    case 5:
                        person.email = individalPersonalData;
                        break;
                    case 6:
                        person.adress = individalPersonalData;
                        break;
                    }
                    individalPersonalData = "";
                    singlePersonNumber++;
                }
            }
            people.push_back(person);
        }
    }
    file.close();
}
void displayAllContact(vector <Contact> &people) {

    Contact person;
    system("cls");
    cout << "----- DISPLAYING ALL CONTACTS ----" << endl;
    cout << "==================================" << endl;

    for(int i = 0; i < people.size(); i++) {
        cout << "ID number: " << "\t" << people[i].id << endl;
        cout << "Name: " << "\t" << "\t" << people[i].name << endl;
        cout << "Surname: " << "\t" << people[i].surname << endl;
        cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
        cout << "Email: " << "\t" << "\t" << people[i].email << endl;
        cout << "Adress: " << "\t" << people[i].adress << endl;
        cout << "- - - - - - - - - - - - - - - - " << endl;
    }
    system("pause");
}
void searchByName(vector <Contact> &people) {

    Contact person;
    string searchingName = "";
    system("cls");
    cout << "-------- SEARCHING BY NAME -------" << endl;
    cout << "==================================" << endl;
    cout << "Enter a name to show people: " << endl;
    cin >> searchingName;
    int i = 0;
    int nameNumber = 0;

    while(i < people.size()) {
        if(people[i].name == searchingName) {
            cout << "ID number" << "\t" << people[i].id << endl;
            cout << "Name: " << "\t" << "\t" << people[i].name << endl;
            cout << "Surname: " << "\t" << people[i].surname << endl;
            cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
            cout << "Email: " << "\t" << "\t" << people[i].email << endl;
            cout << "Adress: " << "\t" << people[i].adress << endl;
            cout << "- - - - - - - - - - - - - - - - " << endl;
            nameNumber++;
        }
        i++;
    }
    if(nameNumber == 0) {
        cout << "None person with that name" << endl;
    }
    system("pause");
}
void searchBySurname(vector <Contact> &people) {

    Contact person;
    string searchingSurname = "";
    system("cls");
    cout << "------ SEARCHING BY SURNAME ------" << endl;
    cout << "==================================" << endl;
    cout << "Enter a surname to show people: " << endl;
    cin >> searchingSurname;
    int i = 0;
    int surnameNumber = 0;

    while(i < people.size()) {
        if(people[i].surname == searchingSurname) {
            cout << "ID number" << "\t" << people[i].id << endl;
            cout << "Name: " << "\t" << "\t" << people[i].name << endl;
            cout << "Surname: " << "\t" << people[i].surname << endl;
            cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
            cout << "Email: " << "\t" << "\t" << people[i].email << endl;
            cout << "Adress: " << "\t" << people[i].adress << endl;
            cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
            surnameNumber++;
        }
        i++;
    }
    if(surnameNumber == 0) {
        cout << "None person with that surname" << endl;
    }
    system("pause");
}
void saveAfterChange(vector<Contact> &people) {

    vector <Contact> ::iterator itr = people.begin();
    fstream fileAfterChange;
    fileAfterChange.open("adressbook.txt", ios::out | ios::trunc);
    if (fileAfterChange.good()) {
        for (itr; itr != people.end(); itr++) {
            fileAfterChange << itr->id << "|" << itr->name << "|" << itr->surname << "|" << itr->phoneNum << "|" << itr->email << "|" << itr->adress << "|" << endl;
        }
        fileAfterChange.close();
    }
}
void modifingData (vector <Contact> &people) {

    int id2modify;
    char modifyChoice;
    string newName, newSurname, newPhoneNum, newEmail, newAdress;
    Contact person;
    system("cls");
    cout << "------- MODIFING A CONTACT -------" << endl;
    cout << "==================================" << endl;
    cout << "Enter ID Number to change data:" << endl;
    cin >> id2modify;

    cout << "Chose information to edit (1/2/3/4/5 or 6): " << endl;
    cout << "1. Name" << endl;
    cout << "2. Surname" << endl;
    cout << "3. Phone Number" << endl;
    cout << "4. E-mail" << endl;
    cout << "5. Adress" << endl;
    cout << "6. Return" << endl;
    cin >> modifyChoice;

    switch(modifyChoice) {
    case '1':
        cout << "Set a new Name: ";
        cin >> newName;
        people[id2modify - 1].name = newName;
        break;
    case '2':
        cout << "Set a new surname: ";
        cin >> newSurname;
        people[id2modify - 1].surname = newSurname;
        break;
    case '3':
        cout << "Set a new phone number: ";
        cin.sync();
        getline(cin,newPhoneNum);
        people[id2modify - 1].phoneNum = newPhoneNum;
        break;
    case '4':
        cout << "Set a new email: ";
        cin >> newEmail;
        people[id2modify - 1].email = newEmail;
        break;
    case '5':
        cout << "Set a new adress: ";
        cin.sync();
        getline(cin,newAdress);
        people[id2modify - 1].adress = newAdress;
        break;
    case '6':
        return 0;
    }
    vector <Contact> ::iterator itr = people.begin();
    for(itr; itr !=people.end(); ++itr) {
        if(itr->id == id2modify) {
            cout << endl;
            cout << "Contact was changed as below:" << endl;
            cout << itr->id << "|" << itr->name << "|" << itr->surname << "|" << itr->phoneNum << "|" << itr->email << "|" << itr->adress << "|" << endl;
            Sleep(2000);
            saveAfterChange(people);
        }
    }
}
void deletePerson (vector <Contact> &people) {

    Contact person;
    int choseID;
    char confirmChoice;

    cout << "Enter person's ID to delete: ";
    cin.sync();
    cin >> choseID;
    cin.sync();
    vector <Contact> ::iterator itr = people.begin();
    for(itr; itr !=people.end(); ++itr) {
        if(itr->id == choseID) {
            cout << itr->id << "|" << itr->name << "|" << itr->surname << "|" << itr->phoneNum << "|" << itr->email << "|" << itr->adress << "|" << endl;
            Sleep(1000);
            cout << endl;
            cout << "Are you sure about deleting contact (y) ? : ";
            cin >> confirmChoice;
            if(confirmChoice == 'y') {
                people.erase(itr);
                cout << "Contact was deleted";
                Sleep(1000);
                saveAfterChange(people);
            } else if(confirmChoice != 'y') {
                cout << "Deleting was not confirm";
                Sleep(1000);
            }
            break;
        }
    }
}
int main() {

    char choice;
    vector <Contact> people;

    loadNotepad(people);

    while(true) {
        system("cls");
        cout<<"=================================="<<endl;
        cout<<"---------- ADRESS BOOK -----------"<<endl;
        cout<<"=================================="<<endl;
        cout << "   MENU:" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Find person by name" << endl;
        cout << "3. Find person by surname" << endl;
        cout << "4. Display all contacts" << endl;
        cout << "5. Delete contact" << endl;
        cout << "6. Modify contact" << endl;
        cout << "9. Exit program" << endl << endl;
        cout << "Chose option :  ";

        choice = checkChoice();
        switch(choice) {
        case '1':
            addContact(people);
            break;
        case '2':
            searchByName(people);
            break;
        case '3':
            searchBySurname(people);
            break;
        case '4':
            displayAllContact(people);
            break;
        case '5':
            deletePerson(people);
            break;
        case '6':
            modifingData(people);
            break;
        case '9':
            exit(0);
        }
    }
    return 0;
}
