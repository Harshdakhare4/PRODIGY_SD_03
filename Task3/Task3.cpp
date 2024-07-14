#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

void loadContacts() {  //loads contacts from contact.txt in the vector for reading.
    ifstream infile("contacts.txt");
    if (infile.is_open()) {
        Contact contact;
        while (infile >> contact.name >> contact.phone >> contact.email) {
            contacts.push_back(contact);
        }
        infile.close();
    }
}

void saveContacts() {
    ofstream outfile("contacts.txt");
    if (outfile.is_open()) {
        for (const auto& contact : contacts) {   //auto keyword guesses the data type of contacts
            outfile << contact.name << " " << contact.phone << " " << contact.email << endl;
        }
        outfile.close();
    }
}

void addContact() {
    Contact contact;
    cout << "Enter name: ";
    cin >> contact.name;
    cout << "Enter phone number: ";
    cin >> contact.phone;
    cout << "Enter email address: ";
    cin >> contact.email;
    contacts.push_back(contact);
    saveContacts();
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << " - " << contacts[i].email << endl;
    }
}

void editContact() {
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        Contact& contact = contacts[index - 1];
        cout << "Editing contact: " << contact.name << " - " << contact.phone << " - " << contact.email << endl;
        cout << "Enter new name (leave blank to keep current): ";
        string newName;
        cin.ignore();
        getline(cin, newName);
        if (!newName.empty()) {
            contact.name = newName;
        }
        cout << "Enter new phone number (leave blank to keep current): ";
        string newPhone;
        getline(cin, newPhone);
        if (!newPhone.empty()) {
            contact.phone = newPhone;
        }
        cout << "Enter new email address (leave blank to keep current): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) {
            contact.email = newEmail;
        }
        saveContacts();
        cout << "Contact updated successfully!" << endl;
    } else {
        cout << "Invalid contact number!" << endl;
    }
}

void deleteContact() {
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + index - 1);
        saveContacts();
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Invalid contact number!" << endl;
    }
}

int main() {
    loadContacts();
    int choice = 0;

    while (choice != 5) {
        cout << "\n************Contact Management System**************" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
