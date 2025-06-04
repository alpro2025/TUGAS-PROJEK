#include <iostream> 
#include <string>   
#include <vector>   
#include <iomanip>  


struct Produk {
    std::string nama; 
    std::string berat; 
    int harga;
};


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

int main() {
    
    std::vector<Produk> listProdukMakananKering = {
        {"Me-O Cat Food Chicken", "1.2 kg", 49500},
        {"Pro Plan Adult Cat Chicken", "7 kg", 897892},
        {"Blue Buffalo Sensitive Stomach Natural Adult Dry Cat Food", "6.35 kg", 4806696},
        {"WHISKAS Makanan Kering untuk Kucing Dewasa Pilih Rasa", "480 gr", 31300},
        {"WHISKAS ADULT TUNA CAT Dry Food", "1.2 kg", 79599},
        {"SCIENCE DIET ADULT CAT INDOOR", "1.5 kg", 285000},
        {"Royal Canin Veterinary Satiety Cat Weight Management", "3.5 kg", 639330},
        {"Me-O Makanan Kucing Kering Kitten Rasa Ikan Laut", "400 gr", 36900},
        {"Science Diet Cat R/D Weight Reduction Chicken Flavor", "1.81 kg", 355900},
        {"WHISKAS Makanan Kering untuk Kucing Dewasa Pilih Rasa", "1.2 kg", 70560},
        {"Purina Fancy Feast Wet Cat Food Variety Pack, Medleys White", "85 gr", 950000},
        {"Friskies Makanan Kucing Kering Adult Meaty Grills", "1.1 kg", 69900},
        {"Makanan Kucing Purina One Cat Food Repacking", "800 gr", 99653},
        {"Me-O Makanan Kucing Kering Adult Seafood", "1.2 kg", 64855},
        {"Cat Choize Makanan Kucing Kering Adult Rasa Tuna & Salmon", "500 gr", 28500},
        {"Royal Canin Persian 30", "2 kg", 373000},
        {"Royal Canin Indoor 27", "2 kg", 315000},
        {"Royal Canin Fit 32", "2 kg", 315000},
        {"Royal Canin Sensible 33", "2 kg", 315000},
        {"Royal Canin Exigent Protein Preference 42", "2 kg", 315000},
        {"Royal Canin Exigent Savour Sensation 35/30", "2 kg", 315000},
        {"Royal Canin Exigent Aromatic Attraction", "2 kg", 315000},
        {"Royal Canin Kitten 36", "2 kg", 341000},
        {"Royal Canin Mother & Babycat", "4 kg", 640000},
        {"Me-O Adult Tuna/Chicken/Beef", "1.5 kg", 65000},
        {"Me-O Kitten", "1.5 kg", 63000},
        {"Bolt Makanan Kucing Kering Rasa Tuna", "1 kg", 25000},
        {"Bolt Makanan Kucing Kering Rasa Tuna", "20 kg", 350000},
        {"Equilibrio Adult Cat", "7.5 kg", 500000},
        {"Equilibrio Kittens", "1.5 kg", 130000},
        {"Maxi Repack Chicken and Tuna", "1 kg", 25000},
        {"Maxi Repack Chicken and Tuna", "2 kg", 48000},
        {"Felibite Cat Food Freshpack", "500 gr", 13400},
        {"Felibite Cat Food", "1.5 kg", 40050},
        {"Felibite Cat Food Repacking", "1 kg", 18500},
        {"Felibite Makanan Kucing", "20 kg", 550000},
        {"Blackwood Cat Chicken Meal and Brown Rice Recipe", "1.82 kg", 174100},
        {"Blackwood Cat Duck Meal, Salmon Meal and Field Pea", "1.82 kg", 208800},
        {"Blackwood Cat Indoor Chicken Meal and Rice Recipe", "1.82 kg", 169700},
        {"Blackwood Kitten Chicken Meal and Rice Recipe", "1.82 kg", 182800},
        {"Happy Cat Adult Indoor", "4 kg", 312000},
        {"Vitakraft Cat Stick Mini", "180 gr", 80000},
        {"Kitchen Flavor Tuna Delight", "1.5 kg", 58500},
        {"Purina One Indoor Advantage", "3.5 kg", 410000},
        {"Alpo Dry Cat Food", "2 kg", 125000},
        {"Meow Mix Original Choice", "3.15 kg", 145000},
        {"SmartHeart Adult Cat Tuna", "1.2 kg", 43000},
        {"SmartHeart Kitten Chicken & Milk", "1.2 kg", 47000},
        {"Max Cat Adult Dry Food", "7 kg", 820000},
        {"Iams ProActive Health Hairball Care", "6.8 kg", 750000},
        {"Wellness CORE Grain-Free Indoor", "2.3 kg", 560000},
        {"Taste of the Wild Rocky Mountain", "2 kg", 490000},
        {"Dr. Elsey’s Cleanprotein Chicken", "6.6 kg", 1020000},
        {"Halo Holistic Chicken & Chicken Liver", "3 kg", 720000},
        {"Nature’s Variety Instinct Raw Boost", "2.7 kg", 875000},
        {"Go! Solutions Carnivore Grain-Free", "3.5 kg", 790000},
        {"Nutro Wholesome Essentials Indoor", "3.18 kg", 450000},
        {"AvoDerm Natural Chicken & Herring Meal", "2.3 kg", 385000},
        {"CANIDAE PURE Limited Ingredient Diet", "4.5 kg", 650000},
        {"Solid Gold Indigo Moon", "5.4 kg", 899000},
        {"Purina Cat Chow Naturals", "6.3 kg", 400000},
        {"Instinct Original Grain-Free", "2 kg", 530000},
        {"Blue Buffalo Wilderness", "2.3 kg", 620000},
        {"Natural Balance L.I.D. Chicken & Green Pea", "2.2 kg", 470000},
        {"American Journey Salmon Recipe", "3.2 kg", 590000},
        {"Rachael Ray Nutrish Indoor Complete", "6 kg", 550000},
        {"Nutrisource Cat & Kitten Chicken Meal", "2.2 kg", 510000},
        {"Farmina N&D Prime Chicken & Pomegranate", "2.5 kg", 720000},
        {"Ziwipeak Air-Dried Cat Food Beef Recipe", "1 kg", 910000},
        {"Tiki Cat Born Carnivore", "1.8 kg", 610000},
        {"FirstMate Chicken Meal with Blueberries", "2.3 kg", 580000},
        {"Now Fresh Grain-Free Adult", "3.6 kg", 870000},
        {"Annamaet Grain-Free Feline Sustain No. 29", "2.27 kg", 690000},
        {"Earthborn Holistic Primitive Feline", "2.5 kg", 540000},
        {"Wellness Complete Health Natural Dry Cat Food", "4.5 kg", 630000},
        {"Merrick Purrfect Bistro Grain-Free", "5.4 kg", 710000},
        {"Boreal Original Chicken Meal", "2.3 kg", 490000},
        {"Redbarn Air Dried Cat Food", "1.8 kg", 860000},
        {"Lotus Wholesome Chicken Recipe", "2.2 kg", 560000},
        {"Kasiks Cage-Free Chicken Meal", "2.2 kg", 520000},
        {"Dr. Tim’s Chase All Life Stages", "2.27 kg", 580000},
        {"Essence Ocean & Freshwater Recipe", "2.5 kg", 590000},
        {"Acana Bountiful Catch", "4.5 kg", 770000},
        {"Orijen Six Fish", "5.4 kg", 1100000},
        {"RAWZ Meal Free Dehydrated Chicken", "2.3 kg", 900000},
        {"Nature’s Logic Chicken Meal Feast", "2.2 kg", 580000},
        {"Fussie Cat Market Fresh Chicken & Turkey", "2.3 kg", 520000},
        {"Supreme Tiny Friends Farm", "1.5 kg", 430000},
        {"Evanger’s Grain-Free Meat Lover’s Medley", "2.2 kg", 620000},
        {"Nulo Freestyle Turkey & Duck", "2.5 kg", 740000},
        {"Open Farm Catch-of-the-Season Whitefish", "2.2 kg", 880000},
        {"Wysong Epigen 90", "2.3 kg", 810000},
        {"Black Hawk Original Chicken & Rice", "3 kg", 550000},
        {"Holis+ic Recipe Grain-Free", "2.3 kg", 610000},
        {"Addiction Grain-Free Duck Royale", "2 kg", 720000},
        {"Little BigPaw Gourmet Duck", "1.8 kg", 680000},
        {"Almo Nature Holistic Chicken & Rice", "2.3 kg", 490000},
        {"Nature Bridge Cat Food", "2.5 kg", 560000},
        {"Loyall Life Adult Cat Food", "2.2 kg", 470000},
        {"Life’s Abundance All Life Stage Cat Food", "2.3 kg", 890000},
        {"Vetdiet Adult Indoor Chicken Meal", "2.3 kg", 620000}
    };

   
    int jumlahProduk = listProdukMakananKering.size();

    std::cout << "Daftar Produk Makanan Kucing Kering (" << jumlahProduk << " produk):\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
    std::cout << std::left << std::setw(3) << "No." << "  "
              << std::left << std::setw(80) << "Nama Produk" << "  "
              << std::left << std::setw(10) << "Berat" << "  "
              << "Harga\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < jumlahProduk; i++) {
        std::cout << std::left << std::setw(3) << i + 1 << ". " // Nomor urut
                  << std::left << std::setw(80) << listProdukMakananKering[i].nama << " | "
                  << std::left << std::setw(10) << listProdukMakananKering[i].berat << " | Rp "
                  << formatHarga(listProdukMakananKering[i].harga) << "\n";
    }
    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    return 0;
}
