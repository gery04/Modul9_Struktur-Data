#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;
    
    // Meminta pengguna untuk memasukkan jumlah simpul
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cin.ignore(); // Mengabaikan newline setelah memasukkan angka
    
    vector<string> namaSimpul(jumlahSimpul);
    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    
    // Meminta pengguna untuk memasukkan nama-nama simpul
    cout << "Silahkan masukkan nama simpul\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        getline(cin, namaSimpul[i]);
    }
    
    // Meminta pengguna untuk memasukkan bobot antar simpul
    cout << "Silahkan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }
    
    // Menampilkan matriks jarak antar simpul
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
    
    return 0;
}
