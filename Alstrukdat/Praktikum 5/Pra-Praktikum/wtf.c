#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Struktur data untuk memetakan kata bilangan ke angka
typedef struct {
    char *word;
    int value;
} WordToNumber;

// Kamus bilangan dasar
WordToNumber basicNumbers[] = {
    {"nol", 0}, {"satu", 1}, {"dua", 2}, {"tiga", 3},
    {"empat", 4}, {"lima", 5}, {"enam", 6}, {"tujuh", 7},
    {"delapan", 8}, {"sembilan", 9}, {"sepuluh", 10},
    {"sebelas", 11}, {"dua belas", 12}, {"tiga belas", 13},
    {"empat belas", 14}, {"lima belas", 15}, {"enam belas", 16},
    {"tujuh belas", 17}, {"delapan belas", 18}, {"sembilan belas", 19},
    {"dua puluh", 20}, {"tiga puluh", 30}, {"empat puluh", 40},
    {"lima puluh", 50}, {"enam puluh", 60}, {"tujuh puluh", 70},
    {"delapan puluh", 80}, {"sembilan puluh", 90}
};

// Kamus kelipatan besar
WordToNumber multiplier[] = {
    {"seratus", 100}, {"ratus", 100}, {"seribu", 1000}, {"ribu", 1000}
};

// Fungsi untuk mencocokkan kata dengan bilangan dasar
int get_basic_number(char *word) {
    for (int i = 0; i < sizeof(basicNumbers) / sizeof(WordToNumber); i++) {
        if (strcmp(word, basicNumbers[i].word) == 0) {
            return basicNumbers[i].value;
        }
    }
    return -1; // Tidak ditemukan
}

// Fungsi untuk mencocokkan kata dengan kelipatan
int get_multiplier(char *word) {
    for (int i = 0; i < sizeof(multiplier) / sizeof(WordToNumber); i++) {
        if (strcmp(word, multiplier[i].word) == 0) {
            return multiplier[i].value;
        }
    }
    return 1; // Default multiplier 1 jika tidak ditemukan
}

// Fungsi utama untuk mengubah kata bilangan ke angka
void convert_to_number(char *sentence) {
    char *token;
    char buffer[1000] = ""; // Buffer untuk hasil akhir
    char temp[100] = "";    // Buffer sementara untuk bilangan
    int number = 0;
    int current_value = 0;
    int multiplier_value = 1;
    int found_number = 0;

    token = strtok(sentence, " ");

    while (token != NULL) {
        int basic_value = get_basic_number(token);
        int mult_value = get_multiplier(token);

        if (basic_value != -1) {
            current_value += basic_value;
            found_number = 1;
        } else if (mult_value > 1) {
            current_value *= mult_value;
        } else {
            if (found_number) {
                number += current_value * multiplier_value;
                sprintf(temp, "%d ", number);
                strcat(buffer, temp);
                number = 0;
                current_value = 0;
                multiplier_value = 1;
                found_number = 0;
            }
            strcat(buffer, token);
            strcat(buffer, " ");
        }

        token = strtok(NULL, " ");
    }

    // Jika masih ada angka yang belum ditambahkan ke buffer
    if (found_number) {
        number += current_value * multiplier_value;
        sprintf(temp, "%d", number);
        strcat(buffer, temp);
    }

    printf("%s\n", buffer);
}

int main() {
    char input[1000];

    // Ambil input dari pengguna
    printf("Masukkan kalimat: ");
    fgets(input, sizeof(input), stdin);

    // Menghapus newline di akhir kalimat
    input[strcspn(input, "\n")] = 0;

    // Panggil fungsi untuk mengubah kalimat
    convert_to_number(input);

    return 0;
}
