#include <iostream>
#include "inventory.h"

int main() {
    // 1. Inisialisasi Root
    adrNode root = NULL;
    infotype data;

    data.name = "Inventaris Kantor";
    data.stock = 0;
    createNode(data, root);

    // 2. Data Hardcoded (Untuk Pengujian)
    adrNode loc1, loc2, loc3;
    adrNode cat1, cat2, cat3, cat4;
    adrNode item;

    // Level 1: Lokasi
    data.name = "Ruang IT"; data.stock = 0;
    createNode(data, loc1); insertNode(root, loc1);

    data.name = "Pantry";   data.stock = 0;
    createNode(data, loc2); insertNode(root, loc2);

    data.name = "Gudang";   data.stock = 0;
    createNode(data, loc3); insertNode(root, loc3);

    // Level 2 & 3: Ruang IT
    // Kategori Laptop
    data.name = "Laptop"; data.stock = 0;
    createNode(data, cat1); insertNode(loc1, cat1);

        data.name = "Lenovo Thinkpad"; data.stock = 5;
        createNode(data, item); insertNode(cat1, item);

        data.name = "Macbook Pro";     data.stock = 3;
        createNode(data, item); insertNode(cat1, item);

    // Kategori Periferal
    data.name = "Periferal"; data.stock = 0;
    createNode(data, cat2); insertNode(loc1, cat2);

        data.name = "Mouse";    data.stock = 10;
        createNode(data, item); insertNode(cat2, item);

        data.name = "Keyboard"; data.stock = 8;
        createNode(data, item); insertNode(cat2, item);

    // Level 2 & 3: Pantry
    // Kategori Elektronik
    data.name = "Elektronik"; data.stock = 0;
    createNode(data, cat3); insertNode(loc2, cat3);

        data.name = "Kulkas";    data.stock = 1;
        createNode(data, item); insertNode(cat3, item);

        data.name = "Dispenser"; data.stock = 2;
        createNode(data, item); insertNode(cat3, item);

    // Level 2 & 3: Gudang
    // Kategori Alat Tulis
    data.name = "Alat Tulis"; data.stock = 0;
    createNode(data, cat4); insertNode(loc3, cat4);

        data.name = "Kertas A4"; data.stock = 50;
        createNode(data, item); insertNode(cat4, item);

        data.name = "Spidol";    data.stock = 20;
        createNode(data, item); insertNode(cat4, item);


    // 3. Menu Loop
    int choice;
    do {
        // [REVISI] Baris cout << string(3, '\n'); SUDAH DIHAPUS DISINI

        cout << "\n=== MENU UTAMA SISTEM INVENTARIS ===" << endl;
        cout << "1. Tampilkan Visualisasi Tree" << endl;
        cout << "2. Traversal Pre-Order" << endl;
        cout << "3. Traversal In-Order" << endl;
        cout << "4. Traversal Post-Order" << endl;
        cout << "5. Cari Barang (Search)" << endl;
        cout << "6. Fitur Unik: Total Stok Aset" << endl;
        cout << "7. Fitur Unik: Barang Terbanyak" << endl;
        cout << "8. Fitur Unik: Hitung Jumlah Node" << endl;
        cout << "9. Hapus Data (Delete)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";

        // Validasi Input Angka
        if (!(cin >> choice)) {
            cout << "Input harus angka!" << endl;
            cin.clear();
            clearBuffer();
            choice = -1;
            waitForEnter();
            continue;
        }
        clearBuffer(); // Membersihkan enter sisa input pilihan

        switch (choice) {
        case 1:
            cout << "\n--- Visualisasi Tree ---" << endl;
            printTree(root);
            waitForEnter();
            break;
        case 2:
            cout << "\n--- Pre-Order Traversal ---" << endl;
            printPreOrder(root);
            cout << "END" << endl;
            waitForEnter();
            break;
        case 3:
            cout << "\n--- In-Order Traversal ---" << endl;
            printInOrder(root);
            cout << "END" << endl;
            waitForEnter();
            break;
        case 4:
            cout << "\n--- Post-Order Traversal ---" << endl;
            printPostOrder(root);
            cout << "END" << endl;
            waitForEnter();
            break;
        case 5: {
            string target;
            cout << "\nMasukkan Nama Barang: ";
            getline(cin, target);

            adrNode result = findNode(root, target);
            if (result != NULL) {
                cout << "Ditemukan! " << result->info.name << " | Stok: " << result->info.stock << endl;
            } else {
                cout << "Barang '" << target << "' tidak ditemukan." << endl;
            }
            waitForEnter();
            break;
        }
        case 6:
            cout << "\nTotal Seluruh Stok Aset Kantor: " << countTotalAssetStock(root) << " unit." << endl;
            waitForEnter();
            break;
        case 7: {
            adrNode maxNode = root;
            findMaxStock(root, maxNode);
            cout << "\nBarang Terbanyak: " << maxNode->info.name << endl;
            cout << "Jumlah Stok: " << maxNode->info.stock << endl;
            waitForEnter();
            break;
        }
        case 8:
            cout << "\nTotal Node dalam Tree: " << countNodes(root) << endl;
            waitForEnter();
            break;
        case 9: {
            string target;
            cout << "\nMasukkan Nama Kategori/Barang yang akan dihapus: ";
            getline(cin, target);

            if (findNode(root, target) == NULL) {
                cout << "Data tidak ditemukan." << endl;
            } else {
                deleteNode(root, target);
                cout << "Proses penghapusan selesai." << endl;
                cout << "Silakan cek kembali di Menu 1." << endl;
            }
            waitForEnter();
            break;
        }
        case 0:
            cout << "Keluar program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            waitForEnter();
        }
    } while (choice != 0);

    return 0;
}
