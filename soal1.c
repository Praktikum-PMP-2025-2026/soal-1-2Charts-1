/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2026/2027
 *  Modul               : 02 - Data Manipulation and External File
 *  Hari dan Tanggal    : Senin, 20 April 2026
 *  Nama (NIM)          : Arvin Fauzan Badri (13224072)
 *  Nama File           : soal1.c
 *  Deskripsi           : Soal 2. Memulihkan elemen array yang hilang, lalu mencari jumlah maksimum subarray 
 * 
 */

#include <stdio.h>
#include <stdlib.h>


int m_floor(double x) {
    int i = (int)x;
    if (x < 0 && x != i) {
        return i - 1;
    }
    return i;
}

int main(void) {
    int num_count, nums[1024 * 1024];

    scanf("%d", &num_count);

    for(int i = 0; i < num_count; ++i) {
        scanf("%d", &nums[i]);
    }

    if(nums[0] == -1) {
        for(int i = 1; i < num_count; ++i) {
            if(nums[i] != -1) {
                nums[0] = nums[i];
                break;
            }
        }
        if(nums[0] == -1) nums[0] = 0;
    }

    if(nums[num_count-1] == -1) {
        for(int i = num_count-1; i >= 0; --i) {
            if(nums[i] != -1) {
                nums[num_count-1] = nums[i];
                break;
            }
        }
        if(nums[num_count-1] == -1) nums[num_count-1] = 0;
    }

    for(int i = 1; i < num_count-1; ++i) {
        if(nums[i] == -1) {
            int valid_kiri = -1;
            int valid_kanan = -1;
            int recovered = 0;

            for(int j = i+1; j < num_count; ++j) {
                if(nums[j] != -1) {
                    valid_kanan = nums[j];
                    break;
                }
            }

            for(int j = i-1; j >= 0; --j) {
                if(nums[j] != -1) {
                    valid_kiri = nums[j];
                    break;
                }
            }

            if(valid_kanan != -1 && valid_kiri != -1) {
                recovered = m_floor(((double)valid_kanan + (double)valid_kiri) / 2.0f);
            }
            else if(valid_kanan != -1) {
                recovered = valid_kanan;
            }
            else if(valid_kiri != -1) { 
                recovered = valid_kiri;
            }

            nums[i] = recovered;
        }
    }

    printf("RECOVERED ");
    for(int i = 0; i < num_count; ++i) {
        printf("%d", nums[i]);
        if(i != num_count-1) printf(" ");
    }
    printf("\n");


    int max_sum = 0;
    for(int i = 0; i < num_count; ++i) {
        if(nums[i] >= 0) {
            max_sum += nums[i];
        }
    }

    if(max_sum == 0) {
        max_sum = nums[0];
        for(int i = 1; i < num_count; ++i) {
            if(max_sum < nums[i]) {
                max_sum = nums[i];
            }
        }
    }
    printf("MAX_SUM %d\n", max_sum);

    return 0;
}

