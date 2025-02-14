#include <stdio.h>
#include <math.h>

#define MAHALLE_SAYISI 3
#define KRITER_SAYISI 5

const char *mahalleler[MAHALLE_SAYISI] = {"Karakas Mahallesi", "Karacaibrahim Mahallesi", "Bademlik Mahallesi"};

// Mahalle kriter deðerler
double veriler[MAHALLE_SAYISI][KRITER_SAYISI] = {
    {850, 6, 3200000, 4, 8},   // Karakaþ
    {1300, 5, 2600000, 3, 9},  // Karacaibrahim
    {700, 7, 2900000, 5, 7}    // Bademlik
};

// Kriter aðýrlýklarý
double agirliklar[KRITER_SAYISI] = {0.3, 0.2, -0.2, -0.1, 0.3};

// Softmax hesaplama 
void softmax(double *arr, int size, double *result) {
    double sum_exp = 0.0;
    
    // Maksimum deðeri
    double max_val = arr[0];
    int i = 1;
    do {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i++;
    } while (i < size);

    // Softmax hesaplama 
    i = 0;
    do {
        result[i] = exp(arr[i] - max_val); 
        sum_exp += result[i];
        i++;
    } while (i < size);

    // Normalize et
    i = 0;
    do {
        result[i] /= sum_exp;
        i++;
    } while (i < size);
}

int main() {
    double skorlar[MAHALLE_SAYISI] = {0}; // Mahallelerin toplam skoru

    int j = 0;
  
    do {
        double kriter_verileri[MAHALLE_SAYISI];  // O kriter için tüm mahalle veriler
        double softmax_degerleri[MAHALLE_SAYISI]; // O kriter için softmax sonuçlar

        // Softmax hesaplanýyor
        int i = 0;
        do {
            kriter_verileri[i] = veriler[i][j];
            i++;
        } while (i < MAHALLE_SAYISI);

        // Softmax uygulanýyor
        softmax(kriter_verileri, MAHALLE_SAYISI, softmax_degerleri);

        // Skorlar hesaplanýyor
        i = 0;
        do {
            skorlar[i] += softmax_degerleri[i] * agirliklar[j];
            i++;
        } while (i < MAHALLE_SAYISI);

        j++;
    } while (j < KRITER_SAYISI);

    // En iyi mahalleyi bulalým
    int en_iyi_index = 0;
    int i = 1;
    do {
        if (skorlar[i] > skorlar[en_iyi_index]) {
            en_iyi_index = i;
        }
        i++;
    } while (i < MAHALLE_SAYISI);

    // Mahallelerin skorlarýný yazdýrýyoruz
    printf("Mahallelerin Toplam Skorlari:\n");
    i = 0;
    do {
        printf("%s: %.4f\n", mahalleler[i], skorlar[i]);
        i++;
    } while (i < MAHALLE_SAYISI);

    printf("\nEn uygun toplu tasima hatti icin onerilen mahalle: %s\n", mahalleler[en_iyi_index]);

    return 0;
}

