/*************************************************************************
	> File Name: 8.unstable_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Jan 2021 05:31:05 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, (sizeof(int) * n));\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void selective_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[x];  //z为基准值
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];  //将y指针处的值放到x处后x再加1
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
    return ;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}



int main() {
    srand(time(0));
    #define max_n 20
    int arr[max_n];
    randint(arr, max_n);
    TEST(arr, max_n, selective_sort, num, max_n);
    TEST(arr, max_n, quick_sort, num, 0, max_n - 1);
    return 0;
}
