#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAKS = 100;

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
    int jumlah;

    do {
        cout << "Jumlah orang (minimal 1): ";
        cin >> jumlah;
    } while (jumlah < 1 || jumlah > MAKS);

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama orang ke-" << i + 1 << ": ";
        cin >> nama[i];
        cout << "Total pesanan pribadi: ";
        cin >> pribadi[i];
        cout << "Uang muka (DP): ";
        cin >> dp[i];
    }

    int idxPenalang;
    do {
        string namaPenalang;
        cout << "Nama penalang (harus ada di daftar): ";
        cin >> namaPenalang;
        idxPenalang = cariIndeks(nama, jumlah, namaPenalang);
        if (idxPenalang == -1) cout << "Nama tidak ditemukan, coba lagi.\n";
    } while (idxPenalang == -1);

    double totalBersama, persenDiskon, persenPajak;
    cout << "Total pesanan bersama: ";
    cin >> totalBersama;
    do {
        cout << "Diskon (%) 0-100: ";
        cin >> persenDiskon;
    } while (persenDiskon < 0 || persenDiskon > 100);
    cout << "Pajak dan layanan (%): ";
    cin >> persenPajak;

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