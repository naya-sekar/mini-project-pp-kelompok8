#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAKS = 100;

// ---------- Input yang aman ----------

// Baca satu baris, buang spasi/\r di ujung. Kalau input habis, hentikan program.
string ambilBaris(const string& pesan) {
    cout << pesan;
    string s;
    if (!getline(cin, s)) {
        cout << "\nInput berakhir (EOF), program dihentikan.\n";
        exit(1);
    }
    size_t awal = s.find_first_not_of(" \t\r\n");
    if (awal == string::npos) return "";
    size_t akhir = s.find_last_not_of(" \t\r\n");
    return s.substr(awal, akhir - awal + 1);
}

string bacaNama(const string& pesan) {
    string s;
    do {
        s = ambilBaris(pesan);
        if (s.empty()) cout << "Nama tidak boleh kosong.\n";
    } while (s.empty());
    return s;
}

double bacaDouble(const string& pesan, double minimal, double maksimal) {
    while (true) {
        string baris = ambilBaris(pesan);
        istringstream iss(baris);
        double nilai;
        if ((iss >> nilai) && iss.eof() && nilai >= minimal && nilai <= maksimal) {
            return nilai;
        }
        cout << "Input tidak valid (harus angka " << minimal << "-" << maksimal
             << "), coba lagi.\n";
    }
}

int bacaInt(const string& pesan, int minimal, int maksimal) {
    while (true) {
        string baris = ambilBaris(pesan);
        istringstream iss(baris);
        int nilai;
        if ((iss >> nilai) && iss.eof() && nilai >= minimal && nilai <= maksimal) {
            return nilai;
        }
        cout << "Input tidak valid (bilangan bulat " << minimal << "-" << maksimal
             << "), coba lagi.\n";
    }
}

// ---------- Perhitungan ----------

double bagiRata(double totalBersama, int jumlahOrang) {
    return totalBersama / jumlahOrang;
}

double hitungDiskon(double dasar, double persenDiskon) {
    return dasar * persenDiskon / 100;
}

double tambahPajak(double nilai, double persen) {
    return nilai * (1 + persen / 100);
}

// Bulatkan ke atas ke satuan rupiah. Toleransi 1e-6 menahan error floating point
long long bulatkanKeAtas(double nilai) {
    return (long long) ceil(nilai - 1e-6);
}

int cariIndeks(string nama[], int jumlah, const string& dicari) {
    for (int i = 0; i < jumlah; i++) {
        if (nama[i] == dicari) return i;
    }
    return -1;
}

void tampilkanHasil(string nama[], long long tagihan[], int jumlah, int idxPenalang) {
    cout << "\n=== HASIL PEMBAGIAN TAGIHAN ===\n";
    long long totalMasuk = 0;

    for (int i = 0; i < jumlah; i++) {
        if (i == idxPenalang) continue;
        if (tagihan[i] <= 0) {
            cout << nama[i] << " sudah lunas\n";
        } else {
            cout << nama[i] << " transfer Rp" << tagihan[i]
                 << " ke " << nama[idxPenalang] << "\n";
            totalMasuk += tagihan[i];
        }
    }

    cout << "\nBagian " << nama[idxPenalang] << " (penalang): Rp"
         << tagihan[idxPenalang] << "\n";
    cout << "Total diterima penalang: Rp" << totalMasuk << "\n";
}

int main() {
    string nama[MAKS];
    double pribadi[MAKS], dp[MAKS];
    long long tagihan[MAKS];

    int jumlah = bacaInt("Jumlah orang (1-100): ", 1, MAKS);

    for (int i = 0; i < jumlah; i++) {
        nama[i]    = bacaNama("Nama orang ke-" + to_string(i + 1) + ": ");
        pribadi[i] = bacaDouble("Total pesanan pribadi: ", 0, 1e12);
        dp[i]      = bacaDouble("Uang muka (DP): ", 0, 1e12);
    }

    int idxPenalang;
    do {
        string namaPenalang = bacaNama("Nama penalang (harus ada di daftar): ");
        idxPenalang = cariIndeks(nama, jumlah, namaPenalang);
        if (idxPenalang == -1) cout << "Nama tidak ditemukan, coba lagi.\n";
    } while (idxPenalang == -1);

    double totalBersama = bacaDouble("Total pesanan bersama: ", 0, 1e12);
    double persenDiskon = bacaDouble("Diskon (%) 0-100: ", 0, 100);
    double persenPajak  = bacaDouble("Pajak dan layanan (%): ", 0, 100);

    double bagian = bagiRata(totalBersama, jumlah);
    for (int i = 0; i < jumlah; i++) {
        double dasar  = pribadi[i] + bagian;
        double diskon = hitungDiskon(dasar, persenDiskon);
        double akhir  = tambahPajak(dasar - diskon, persenPajak);
        tagihan[i] = bulatkanKeAtas(akhir) - (long long) dp[i];
    }

    tampilkanHasil(nama, tagihan, jumlah, idxPenalang);
    return 0;
}