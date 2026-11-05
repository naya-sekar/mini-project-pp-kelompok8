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
