#include<iostream>
#include<string>
using namespace std;

const int max_produkKering = 50;

struct Produk {
    string namaProduk;
    double hargaProduk;
    int stokProduk;
};

Produk listProdukMakanan1[max_produkKering] = {
    {"NOVA Rabbit Food 1kg", 38000, 10},
    {"Takari Fish Food 100gr", 10000, 30},
    {"CAT CHOIZE Adult Salmon 800g", 30000, 24},
    {"CAT CHOIZE Adult Tuna 800g", 30000, 25},
    {"CAT CHOIZE Kitten Salmon with Milk 1kg", 30000, 24},
    {"CAT CHOIZE Kitten Tuna with Milk 1kg", 30000, 24},
    {"Bolt Mother & Kitten Salmon 500g", 14500, 28},
    {"BOLT Tuna Cat Food 1kg", 25000, 16},
    {"BOLT Salmon Cat Food 1kg", 25000, 16},
    {"Excel Cat Food 500gr", 15000, 40},
    {"FELIBITE CAT FOOD Tuna 500gr", 15000, 21},
    {"FELIBITE CAT FOOD Salmon 500gr", 15000, 20},
    {"Meo Cat Food Persian 6.8kg", 346500, 1},
    {"Cattie Care Cat Food 20kg", 561000, 1},
    {"UNIVERSAL WORLD PET KITTEN 20kg", 630000, 1}
};

int jumlahProduk = 15;

void line() {
    cout << "===========================================\n";
}

void tambahProduk() {
    cin.ignore();
    string namaProduk;
    double hargaProduk;
    int stokProduk;

    cout<<">>> Nama Produk\t\t: ";
    getline(cin, namaProduk);
    cout<<">>> Harga Produk (Rp)\t: ";
    cin>>hargaProduk;
    cout<<">>> Jumlah stok\t\t: ";
    cin>>stokProduk;

    listProdukMakanan1[jumlahProduk].namaProduk = namaProduk;
    listProdukMakanan1[jumlahProduk].hargaProduk = hargaProduk;
    listProdukMakanan1[jumlahProduk].stokProduk = stokProduk;
    jumlahProduk++;

    cout<<">>> Produk berhasil ditambahkan!\n";
}

void tampilkanProduk() {
    line();
    cout<<"DAFTAR PRODUK\n";
    line();
    cout<<"| No | Nama Produk\t\t\t| Harga\t\t| Stok |\n";
    cout<<"--------------------------------------------------------------\n";
    for (int i=0; i<jumlahProduk; i++) {
        cout<<"| "<<i+1<<" | "<<listProdukMakanan1[i].namaProduk<<"\t\t| Rp "<<listProdukMakanan1[i].hargaProduk<<" | "<<listProdukMakanan1[i].stokProduk<<" |\n";
    }
}

void editProduk() {
    int indexEdit;
    cout << ">>> Masukkan Nomor Produk yang ingin diedit: ";
    cin >> indexEdit;
    indexEdit--;

    if (indexEdit >= 0 && indexEdit < jumlahProduk) {
        cin.ignore();
        cout << ">>> Nama Produk Baru\t: ";
        getline(cin, listProdukMakanan1[indexEdit].namaProduk);
        cout << ">>> Harga Baru (Rp)\t: ";
        cin >> listProdukMakanan1[indexEdit].hargaProduk;
        cout << ">>> Stok Baru\t\t: ";
        cin >> listProdukMakanan1[indexEdit].stokProduk;

        cout << ">>> Data produk berhasil diperbarui!\n";
    } else {
        cout << ">>> Nomor produk tidak ditemukan.\n";
    }
}

void hapusProduk() {
    int indexHapus;
    char konfirHapus;

    cout << ">>> Masukkan Nomor Produk yang ingin dihapus: ";
    cin >> indexHapus;
    indexHapus--;

    if (indexHapus >= 0 && indexHapus < jumlahProduk) {
        cout << ">>> Apakah anda yakin ingin menghapus produk ini? (y/n): ";
        cin >> konfirHapus;

        if (konfirHapus == 'y' || konfirHapus == 'Y') {
            for (int i = indexHapus; i < jumlahProduk - 1; i++) {
                listProdukMakanan1[i] = listProdukMakanan1[i + 1];
            }
            jumlahProduk--;
            cout << ">>> Produk berhasil dihapus!\n";
        } else {
            cout << ">>> Penghapusan dibatalkan.\n";
        }
    } else {
        cout << ">>> Nomor produk tidak ditemukan.\n";
    }
}

void cariProduk() {
    string keyword;
    cin.ignore();
    cout << ">>> Masukkan kata kunci nama produk: ";
    getline(cin, keyword);

    bool ditemukan = false;
    line();
    cout << "Hasil Pencarian:\n";
    for (int i = 0; i < jumlahProduk; i++) {
        if (listProdukMakanan1[i].namaProduk.find(keyword) != string::npos) {
            cout << "- " << listProdukMakanan1[i].namaProduk
                 << " | Rp " << listProdukMakanan1[i].hargaProduk
                 << " | stok: " << listProdukMakanan1[i].stokProduk << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << ">>> Produk tidak ditemukan.\n";
    }
}

void menuManajemenProduk() {
    int pilMenu;
    do {
    	cout<<endl;
        line();
        cout << "MENU MANAJEMEN PRODUK\n";
        line();
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Semua Produk\n";
        cout << "3. Edit Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "6. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilMenu;
        cout<<endl;

        switch (pilMenu) {
            case 1: tambahProduk(); break;
            case 2: tampilkanProduk(); break;
            case 3: editProduk(); break;
            case 4: hapusProduk(); break;
            case 5: cariProduk(); break;
            case 6: cout << "Kembali ke menu utama...\n"; break;
            default: cout << ">>> Pilihan tidak valid!\n"; break;
        }
    } while (pilMenu != 6);
}

int main() {
    int pilSistem;

    do {
        line();
        cout << "SISTEM MANAJEMEN TOKO PERAWATAN HEWAN\n";
        line();
        cout << "1. Manajemen Produk\n";
        cout << "2. Manajemen Layanan\n";
        cout << "3. Keluar\n";
        cout << "Pilih Sistem: ";
        cin >> pilSistem;
        cout<<endl;

        switch (pilSistem) {
            case 1: menuManajemenProduk(); break;
            case 2: cout << ">>> Fitur layanan belum tersedia.\n"; break;
            case 3: cout << ">>> Terima kasih telah menggunakan sistem.\n"; break;
            default: cout << ">>> Pilihan tidak valid!\n"; break;
        }
    } while (pilSistem != 3);

    return 0;
}
