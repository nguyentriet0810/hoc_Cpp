#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

int n = 0;
void scan_array(void)   {
    int count = 0;
    while (n <= 0 || n > 1000) {
        if (count == 0) { 
            count++;
            printf("so luong phan tu can nhap:");
            scanf("%d",&n);
        } else {
            printf("nhap lai so luong phan tu:");
            scanf("%d",&n);
        }
    }
    return;
}

void find_max_min(int *arr, int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *arr, int n) {  //min to max
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int divide_and_conquer(int *arr, int left, int right, int target) {
    if (left > right) {
        printf("loi");
        return 0; // not found
    }   
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {   
        printf("phan tu %d o vi tri %d trong mang\n", target, mid);
        return 1; // found
    } else if (arr[mid] < target) {
        return divide_and_conquer(arr, mid + 1, right, target);
    } else {
        return divide_and_conquer(arr, left, mid - 1, target);
    }
    return 0;
}

int main(void) {
    //nhap mang
    scan_array();
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("nhap cac phan tu:\n");
    for(int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("cac phan tu vua nhap la:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //tim phan tu lon nhat va nho nhat
    int max, min;
    find_max_min(arr, n, &max, &min);
    printf("phan tu lon nhat: %d\n", max);
    printf("phan tu nho nhat: %d\n", min);  

    //sap xep mang
    sort_array(arr, n);
    printf("mang sau khi sap xep la:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }   
    printf("\n");

    //tim phan tu trong mang
    int target; 
    printf("nhap phan tu can tim trong mang:");
    scanf("%d",&target);
    if (!divide_and_conquer(arr, 0, n - 1, target)) {
        printf("khong tim thay phan tu %d trong mang\n", target);
    }

    free(arr);
    return 0;
}