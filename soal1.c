#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

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
            int valid_kiri = 0;
            int valid_kanan = 0;
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

            if(valid_kanan != 0 && valid_kiri != 0) {
                recovered = floor(((double)valid_kanan + (double)valid_kiri) / 2.0f);
            }
            else if(valid_kanan != 0) {
                recovered = valid_kanan;
            }
            else if(valid_kiri != 0) { 
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

