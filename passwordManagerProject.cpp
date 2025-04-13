#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PASSWORDS = 100;

class PasswordManager {
private:
    string websites[MAX_PASSWORDS];
    string passwords[MAX_PASSWORDS];
    int count;

public:
    PasswordManager() : count(0) {}

    void addPassword(const string& website, const string& password) {
        if (count < MAX_PASSWORDS) {
            websites[count] = website;
            passwords[count] = password;
            count++;
            cout << "Password for " << website << " added successfully." << endl;
        } else {
            cout << "Password storage is full!" << endl;
        }
    }

    void getPassword(const string& website) {
        for (int i = 0; i < count; i++) {
            if (websites[i] == website) {
                cout << "Password for " << website << ": " << passwords[i] << endl;
                return;
            }
        }
        cout << "No password found for " << website << endl;
    }

    void removePassword(const string& website) {
        for (int i = 0; i < count; i++) {
            if (websites[i] == website) {
                // Shift remaining passwords to fill the gap
                for (int j = i; j < count - 1; j++) {
                    websites[j] = websites[j + 1];
                    passwords[j] = passwords[j + 1];
                }
                count--;
                cout << "Password for " << website << " removed successfully." << endl;
                return;
            }
        }
        cout << "No password found for " << website << endl;
    }

    string generatePassword(int length) {
        char characters[] = "aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPSOVERTHELAZYDOG0123456789";
        int charSize = sizeof(characters) - 1; // Exclude the null character
        srand(time(0));

        string password = "";
        for (int i = 0; i < length; i++) {
            int randomIndex = rand() % charSize;
            password += characters[randomIndex];
        }
        return password;
    }
};

int main() {
    PasswordManager manager;
    int choice;
    string website, password;
    int length;

    do {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password\n";
        cout << "2. Get Password\n";
        cout << "3. Remove Password\n";
        cout << "4. Generate Random Password and Add\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter website: ";
                cin >> website;
                cout << "Enter password: ";
                cin >> password;
                manager.addPassword(website, password);
                break;
            case 2:
                cout << "Enter website: ";
                cin >> website;
                manager.getPassword(website);
                break;
            case 3:
                cout << "Enter website: ";
                cin >> website;
                manager.removePassword(website);
                break;
            case 4:
                cout << "Enter website: ";
                cin >> website;
                cout << "Enter desired password length: ";
                cin >> length;
                password = manager.generatePassword(length);
                cout << "Generated Password: " << password << endl;
                manager.addPassword(website, password);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}