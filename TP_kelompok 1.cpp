#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 10; // Maksimal jumlah item

struct Produk {
    string nama;
    double harga;
    int stok;
};

struct Layanan {
    string nama;
    double harga;
    int durasi; // dalam menit
};

Produk produk[MAX_ITEMS] = {
    {"Makanan Kucing", 25000, 100},
    {"Mainan Anjing", 15000, 50},
    {"Shampoo Hewan", 30000, 30},
    {"Vitamin Hewan", 20000, 20},
    {"Kandang Mini", 50000, 10},
    {"Makanan Anjing", 27000, 80},
    {"Mainan Kucing", 12000, 60},
    {"Obat Cacing", 15000, 40},
    {"Kuku Hewan", 10000, 70},
    {"Pakaian Hewan", 35000, 25}
};

Layanan layanan[MAX_ITEMS] = {
    {"Grooming", 50000, 60},
    {"Vaksinasi", 75000, 45},
    {"Penitipan Harian", 60000, 480},
    {"Pelatihan Dasar", 80000, 120},
    {"Pemeriksaan Kesehatan", 70000, 30},
    {"Pembersihan Kandang", 20000, 30},
    {"Pemotongan Kuku", 15000, 15},
    {"Pemberian Obat", 10000, 10},
    {"Penyemprotan Kutu", 25000, 20},
    {"Pemeriksaan Gigi", 30000, 25}
};

void tampilkanMenuProduk() {
    cout << "\n--- Daftar Produk ---\n";
    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << i + 1 << ". " << produk[i].nama << " - Rp" << fixed << setprecision(2) << produk[i].harga << " | Stok: " << produk[i].stok << endl;
    }
}

void tampilkanMenuLayanan() {
    cout << "\n--- Daftar Layanan ---\n";
    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << i + 1 << ". " << layanan[i].nama << " - Rp" << fixed << setprecision(2) << layanan[i].harga << " | Durasi: " << layanan[i].durasi << " menit" << endl;
    }
}

void pesanProduk() {
    int pilihan, jumlah;
    cout << "Pilih produk yang ingin dipesan (1-" << MAX_ITEMS << "): ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan > MAX_ITEMS) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    cout << "Masukkan jumlah: ";
    cin >> jumlah;
    if (jumlah > produk[--pilihan].stok) {
        cout << "Stok tidak mencukupi.\n";
    } else {
        produk[pilihan].stok -= jumlah;
        cout << "Pesanan berhasil! Total: Rp" << fixed << setprecision(2) << produk[pilihan].harga * jumlah << endl;
    }
}

void pesanLayanan() {
    int pilihan;
    cout << "Pilih layanan yang ingin dipesan (1-" << MAX_ITEMS << "): ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan > MAX_ITEMS) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    cout << "Pesanan berhasil! Total: Rp" << fixed << setprecision(2) << layanan[--pilihan].harga << endl;
}

void menuUtama() {
    int pilihan;
    do {
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Pesan Produk\n";
        cout << "2. Pesan Layanan\n";
        cout << "3. Keluar Program\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanMenuProduk();
                pesanProduk();
                break;
            case 2:
                tampilkanMenuLayanan();
                pesanLayanan();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan layanan kami!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);
}

int main() {
    menuUtama();
    return 0;
}




