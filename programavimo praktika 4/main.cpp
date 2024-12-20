#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

const int MENU_SIZE = 8;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

// Funkciju deklaracijos
void getData(menuItemType menuList[]);
void showMenu(const menuItemType menuList[]);
void printCheck(const menuItemType menuList[], int quantities[]);

int main() {
    setlocale(LC_ALL, "lt_LT.UTF-8");
    menuItemType menuList[MENU_SIZE];
    int quantities[MENU_SIZE] = {0};
    int choice, portion;

    getData(menuList);

    cout << "Sveiki atvyke i restorana „Kolegijos maistas“!\n";

    do {
        showMenu(menuList);
        cout << "Pasirinkite patiekalo numeri (0 baigti uzsakyma): ";
        cin >> choice;

        if (choice > 0 && choice <= MENU_SIZE) {
            cout << "Iveskite norimu porciju kieki: ";
            cin >> portion;

            if (portion > 0) {
                quantities[choice - 1] += portion;
            } else {
                cout << "Netinkamas porciju kiekis!\n";
            }
        } else if (choice != 0) {
            cout << "Netinkamas pasirinkimas!\n";
        }
    } while (choice != 0);

    printCheck(menuList, quantities);

    return 0;
}

// Funkcija uzpildyti meniu duomenis
void getData(menuItemType menuList[]) {
    menuList[0] = {"Kiausiniene", 1.45};
    menuList[1] = {"Kiaulienos sonine su keptu kiausiniu", 2.45};
    menuList[2] = {"Keksiukas su vysnia", 0.99};
    menuList[3] = {"Prancuziskas skrebutis", 1.99};
    menuList[4] = {"Vaisiu salotos", 2.49};
    menuList[5] = {"Pusryciu dribsniai", 0.69};
    menuList[6] = {"Kava", 0.50};
    menuList[7] = {"Arbata", 0.75};
}

// Funkcija rodyti meniu
void showMenu(const menuItemType menuList[]) {
    cout << "\n--- Pusryciu meniu ---\n";
    for (int i = 0; i < MENU_SIZE; i++) {
        cout << i + 1 << ". " << setw(40) << left << menuList[i].menuItem
             << setw(6) << right << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
    }
    cout << "0. Baigti uzsakyma\n";
}

// Funkcija spausdinti sąskaitą
void printCheck(const menuItemType menuList[], int quantities[]) {
    double subtotal = 0.0;
    ofstream receipt("saskaita.txt");

    cout << "\n--- Saskaita ---\n";
    receipt << "--- Saskaita ---\n";

    for (int i = 0; i < MENU_SIZE; i++) {
        if (quantities[i] > 0) {
            double itemTotal = quantities[i] * menuList[i].menuPrice;
            subtotal += itemTotal;

            cout << quantities[i] << " " << setw(44) << left << menuList[i].menuItem
                 << setw(1) << right << fixed << setprecision(2) << itemTotal << "€\n";

            receipt << quantities[i] << " " << setw(44) << left << menuList[i].menuItem
                    << setw(1) << right << fixed << setprecision(2) << itemTotal << "€\n";
        }
    }

    double tax = subtotal * 0.21;
    double total = subtotal + tax;

    cout << setw(46) << left << "Mokesciai"
         << setw(1) << right << fixed << setprecision(2) << tax << "€\n";

    cout << setw(46) << left << "Galutine suma"
         << setw(1) << right << fixed << setprecision(2) << total << "€\n";

    receipt << setw(46) << left << "Mokesciai"
            << setw(1) << right << fixed << setprecision(2) << tax << "€\n";

    receipt << setw(46) << left << "Galutine suma"
            << setw(1) << right << fixed << setprecision(2) << total << "€\n";

    receipt.close();

    cout << "\nSaskaita issaugota faile 'saskaita.txt'.\n";
}