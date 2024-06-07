#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void inputTreeData(vector<string>& namaSimpul, vector<vector<int>>& bobot, int& jumlahSimpul) {
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cin.ignore(); // Mengabaikan newline setelah memasukkan angka

    namaSimpul.resize(jumlahSimpul);
    bobot.assign(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silahkan masukkan nama simpul\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        getline(cin, namaSimpul[i]);
    }

    cout << "Silahkan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }
}

void displayMatrix(const vector<string>& namaSimpul, const vector<vector<int>>& bobot) {
    int jumlahSimpul = namaSimpul.size();
    
    cout << "\n";
    cout << setw(15) << "";
    for (const auto& nama : namaSimpul) {
        cout << setw(15) << nama;
    }
    cout << "\n";
    
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(15) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << setw(15) << bobot[i][j];
        }
        cout << "\n";
    }
}

int main() {
    vector<string> namaSimpul;
    vector<vector<int>> bobot;
    int jumlahSimpul = 0;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Masukkan data tree\n";
        cout << "2. Tampilkan matriks jarak antar simpul\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputTreeData(namaSimpul, bobot, jumlahSimpul);
                break;
            case 2:
                displayMatrix(namaSimpul, bobot);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
                break;
        }
    } while (pilihan != 3);

    return 0;
}
