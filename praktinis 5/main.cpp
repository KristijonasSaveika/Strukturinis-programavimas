#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Strukt�ra kontaktams
struct Contact {
    int id;
    string vardas;
    string pavarde;
    string tlf;
};

vector<Contact> contacts;  // Dinamin� kontakt� saugojimo vieta
int nextId = 1;  // Pirmo kontakto ID pradinis numeris

// Funkcija darbui su dvima�iu masyvu
void handleTable() {
    int eil, stul;

    cout << "�veskite lentel�s eilu�i� skai�i�: ";
    cin >> eil;
    cout << "�veskite lentel�s stulpeli� skai�i�: ";
    cin >> stul;

    vector<vector<int>> table(eil, vector<int>(stul));

    cout << "�veskite lentel�s reik�mes:\n";
    for (int i = 0; i < eil; i++) {
        for (int j = 0; j < stul; j++) {
            cout << "Reik�m� [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> table[i][j];
        }
    }

    // Atspausdinti lentel�
    cout << "\nLentel�:\n";
    for (const auto& eil : table) {
        for (int val : eil) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Eilu�i� sumos
    cout << "\nEilu�i� sumos:\n";
    for (int i = 0; i < eil; i++) {
        int rowSum = 0;
        for (int j = 0; j < stul; j++) {
            rowSum += table[i][j];
        }
        cout << "Eilut� " << i + 1 << ": " << rowSum << endl;
    }

    // Stulpeli� sumos
    cout << "\nStulpeli� sumos:\n";
    for (int j = 0; j < stul; j++) {
        int colSum = 0;
        for (int i = 0; i < stul; i++) {
            colSum += table[i][j];
        }
        cout << "Stulpelis " << j + 1 << ": " << colSum << endl;
    }

    // Did�iausia reik�m�
    int maxVal = numeric_limits<int>::min();
    for (const auto& row : table) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
    }
    cout << "\nDid�iausia reik�m� lentel�je: " << maxVal << endl;
}

// Funkcijos darbui su kontaktais
void addContact() {
    Contact newContact;
    newContact.id = nextId++;
    cout << "�veskite vard�: ";
    cin >> newContact.vardas;
    cout << "�veskite pavard�: ";
    cin >> newContact.pavarde;
    cout << "�veskite telefono numer�: ";
    cin >> newContact.tlf;
    contacts.push_back(newContact);
    cout << "Kontaktas prid�tas!\n";
}

void printContacts() {
    if (contacts.empty()) {
        cout << "N�ra kontakt�!\n";
        return;
    }
    cout << "\nVisi kontaktai:\n";
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.id
             << ", Vardas: " << contact.vardas
             << ", Pavard�: " << contact.pavarde
             << ", Telefonas: " << contact.tlf << endl;
    }
}

void editContact() {
    int id;
    cout << "�veskite redaguojamo kontakto ID: ";
    cin >> id;
    for (auto& contact : contacts) {
        if (contact.id == id) {
            cout << "�veskite nauj� vard�: ";
            cin >> contact.vardas;
            cout << "�veskite nauj� pavard�: ";
            cin >> contact.pavarde;
            cout << "�veskite nauj� telefono numer�: ";
            cin >> contact.tlf;
            cout << "Kontaktas atnaujintas!\n";
            return;
        }
    }
    cout << "Kontaktas nerastas!\n";
}

void deleteContact() {
    int id;
    cout << "�veskite �alinamo kontakto ID: ";
    cin >> id;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->id == id) {
            contacts.erase(it);
            cout << "Kontaktas pa�alintas!\n";
            return;
        }
    }
    cout << "Kontaktas nerastas!\n";
}

int main() {
    system("chcp 1257 > null");
    int choice;

    do {
        cout << "\nPasirinkite veiksm�:\n";
        cout << "1. Darbas su lentel� (dvimatis masyvas)\n";
        cout << "2. Darbas su kontaktais\n";
        cout << "3. I�eiti\n";
        cout << "Pasirinkite veiksm�: ";
        cin >> choice;

        switch (choice) {
            case 1:
                handleTable();
                break;
            case 2: {
                int contactChoice;
                do {
                    cout << "\n1. Prid�ti kontakt�\n";
                    cout << "2. Atspausdinti visus kontaktus\n";
                    cout << "3. Redaguoti kontakt�\n";
                    cout << "4. Pa�alinti kontakt�\n";
                    cout << "5. Gr��ti � pagrindin� meniu\n";
                    cout << "Pasirinkite veiksm�: ";
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
