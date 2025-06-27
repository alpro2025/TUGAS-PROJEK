#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Produk {
    std::string nama;
    std::string berat;
    int harga;
    int stok;
};

// Fungsi untuk memformat harga ke format 1.000.000
std::string formatHarga(int harga) {
    std::string sHarga = std::to_string(harga);
    std::string formattedHarga = "";
    int count = 0;
    for (int i = sHarga.length() - 1; i >= 0; i--) {
        formattedHarga.insert(0, 1, sHarga[i]);
        count++;
        if (count % 3 == 0 && i != 0) {
            formattedHarga.insert(0, 1, '.');
        }
    }
    return formattedHarga;
}

// Menampilkan semua produk
void tampilkanProduk(const std::vector<Produk>& produkList) {
    std::cout << "\n=== DAFTAR SEMUA PRODUK (" << produkList.size() << " item) ===\n";
    std::cout << std::left << std::setw(4) << "No."
              << std::setw(60) << "Nama Produk"
              << std::setw(12) << "Berat"
              << std::setw(15) << "Harga"
              << std::setw(6) << "Stok" << "\n";
    std::cout << "----------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < produkList.size(); i++) {
        std::cout << std::setw(4) << i + 1
                  << std::setw(60) << produkList[i].nama
                  << std::setw(12) << produkList[i].berat
                  << "Rp " << std::setw(12) << formatHarga(produkList[i].harga)
                  << std::setw(6) << produkList[i].stok << "\n";
    }
}

// Menampilkan produk dengan stok sedikit (<5) dan sedang (5–10)
void tampilkanProdukStokSedikitSedang(const std::vector<Produk>& produkList) {
    bool adaSedikit = false, adaSedang = false;

    std::cout << "\n=== PRODUK DENGAN STOK SEDIKIT (<5) ===\n";
    for (const auto& produk : produkList) {
        if (produk.stok < 5) {
            std::cout << std::setw(60) << produk.nama
                      << std::setw(12) << produk.berat
                      << "Rp " << std::setw(10) << formatHarga(produk.harga)
                      << std::setw(6) << produk.stok << "\n";
            adaSedikit = true;
        }
    }
    if (!adaSedikit) std::cout << "Tidak ada produk dengan stok < 5.\n";

    std::cout << "\n=== PRODUK DENGAN STOK SEDANG (5–10) ===\n";
    for (const auto& produk : produkList) {
        if (produk.stok >= 5 && produk.stok <= 10) {
            std::cout << std::setw(60) << produk.nama
                      << std::setw(12) << produk.berat
                      << "Rp " << std::setw(10) << formatHarga(produk.harga)
                      << std::setw(6) << produk.stok << "\n";
            adaSedang = true;
        }
    }
    if (!adaSedang) std::cout << "Tidak ada produk dengan stok 5–10.\n";
}

int main() {
    std::vector<Produk> listProduk = {
        {"Me-O Cat Food Chicken", "1.2 kg", 49500, 12},
        {"Pro Plan Adult Cat Chicken", "7 kg", 897892, 4},
        {"Blue Buffalo Sensitive Stomach", "6.35 kg", 4806696, 2},
        {"WHISKAS Dewasa Pilih Rasa", "480 gr", 31300, 10},
        {"SCIENCE DIET INDOOR", "1.5 kg", 285000, 8},
        {"Me-O Kitten Ikan Laut", "400 gr", 36900, 5},
        {"Royal Canin Satiety", "3.5 kg", 639330, 3},
        {"Felibite Freshpack", "500 gr", 13400, 20},
        {"Maxi Repack Tuna", "2 kg", 48000, 1},
        {"Solid Gold Indigo Moon", "5.4 kg", 899000, 6}
        // Kamu bisa menambahkan 100+ data lainnya di sini
    };

    int pilihan;
    do {
        std::cout << "\n=== MENU UTAMA ===\n";
        std::cout << "1. Tampilkan semua produk\n";
        std::cout << "2. Tampilkan produk dengan stok sedikit dan sedang\n";
        std::cout << "3. Keluar\n";
        std::cout << "Pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanProduk(listProduk);
                break;
            case 2:
                tampilkanProdukStokSedikitSedang(listProduk);
                break;
            case 3:
                std::cout << "Terima kasih telah menggunakan aplikasi!\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}

