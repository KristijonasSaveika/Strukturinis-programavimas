#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Struktûra kontaktams
struct Contact {
    int id;
    string vardas;
    string pavarde;
    string tlf;
};

vector<Contact> contacts;  // Dinaminë kontaktø saugojimo vieta
int nextId = 1;  // Pirmo kontakto ID pradinis numeris

// Funkcija darbui su dvimaèiu masyvu
void handleTable() {
    int eil, stul;

    cout << "Áveskite lentelës eiluèiø skaièiø: ";
    cin >> eil;
    cout << "Áveskite lentelës stulpeliø skaièiø: ";
    cin >> stul;

    vector<vector<int>> table(eil, vector<int>(stul));

    cout << "Áveskite lentelës reikðmes:\n";
    for (int i = 0; i < eil; i++) {
        for (int j = 0; j < stul; j++) {
            cout << "Reikðmë [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> table[i][j];
        }
    }

    // Atspausdinti lentelæ
    cout << "\nLentelë:\n";
    for (const auto& eil : table) {
        for (int val : eil) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Eiluèiø sumos
    cout << "\nEiluèiø sumos:\n";
    for (int i = 0; i < eil; i++) {
        int rowSum = 0;
        for (int j = 0; j < stul; j++) {
            rowSum += table[i][j];
        }
        cout << "Eilutë " << i + 1 << ": " << rowSum << endl;
    }

    // Stulpeliø sumos
    cout << "\nStulpeliø sumos:\n";
    for (int j = 0; j < stul; j++) {
        int colSum = 0;
        for (int i = 0; i < stul; i++) {
            colSum += table[i][j];
        }
        cout << "Stulpelis " << j + 1 << ": " << colSum << endl;
    }

    // Didþiausia reikðmë
    int maxVal = numeric_limits<int>::min();
    for (const auto& row : table) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }
    cout << "\nDidþiausia reikðmë lentelëje: " << maxVal << endl;
}

// Funkcijos darbui su kontaktais
void addContact() {
    Contact newContact;
    newContact.id = nextId++;
    cout << "Áveskite vardà: ";
    cin >> newContact.vardas;
    cout << "Áveskite pavardæ: ";
    cin >> newContact.pavarde;
    cout << "Áveskite telefono numerá: ";
    cin >> newContact.tlf;
    contacts.push_back(newContact);
    cout << "Kontaktas pridëtas!\n";
}

void printContacts() {
    if (contacts.empty()) {
        cout << "Nëra kontaktø!\n";
        return;
    }
    cout << "\nVisi kontaktai:\n";
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.id
             << ", Vardas: " << contact.vardas
             << ", Pavardë: " << contact.pavarde
             << ", Telefonas: " << contact.tlf << endl;
    }
}

void editContact() {
    int id;
    cout << "Áveskite redaguojamo kontakto ID: ";
    cin >> id;
    for (auto& contact : contacts) {
        if (contact.id == id) {
            cout << "Áveskite naujà vardà: ";
            cin >> contact.vardas;
            cout << "Áveskite naujà pavardæ: ";
            cin >> contact.pavarde;
            cout << "Áveskite naujà telefono numerá: ";
            cin >> contact.tlf;
            cout << "Kontaktas atnaujintas!\n";
            return;
        }
    }
    cout << "Kontaktas nerastas!\n";
}

void deleteContact() {
    int id;
    cout << "Áveskite ðalinamo kontakto ID: ";
    cin >> id;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->id == id) {
            contacts.erase(it);
            cout << "Kontaktas paðalintas!\n";
            return;
        }
    }
    cout << "Kontaktas nerastas!\n";
}

int main() {
    system("chcp 1257 > null");
    int choice;

    do {
        cout << "\nPasirinkite veiksmà:\n";
        cout << "1. Darbas su lentelë (dvimatis masyvas)\n";
        cout << "2. Darbas su kontaktais\n";
        cout << "3. Iðeiti\n";
        cout << "Pasirinkite veiksmà: ";
        cin >> choice;

        switch (choice) {
            case 1:
                handleTable();
                break;
            case 2: {
                int contactChoice;
                do {
                    cout << "\n1. Pridëti kontaktà\n";
                    cout << "2. Atspausdinti visus kontaktus\n";
                    cout << "3. Redaguoti kontaktà\n";
                    cout << "4. Paðalinti kontaktà\n";
                    cout << "5. Gráþti á pagrindiná meniu\n";
                    cout << "Pasirinkite veiksmà: ";
                    cin >> contactChoice;

                    switch (contactChoice) {
                        case 1:
                            addContact();
                            break;
                        case 2:
                            printContacts();
                            break;
                        case 3:
                            editContact();
                            break;
                        case 4:
                            deleteContact();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Neteisingas pasirinkimas!\n";
                    }
                } while (contactChoice != 5);
                break;
            }
            case 3:
                cout << "Programa baigta.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas!\n";
        }
    } while (choice != 3);

    return 0;
}
