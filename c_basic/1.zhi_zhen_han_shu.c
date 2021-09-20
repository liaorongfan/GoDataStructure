/*************************************************************************
	> File Name: zhi_zhen_han_shu.c
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Dec 2020 11:17:13 PM CST
 ************************************************************************/

#include<stdio.h>

//函数是拓展的数组，数组是压缩了的函数

long Triangle(long n){
    return n * (n + 1) / 2;
}

long Pentagonal(long n) {
    return n * (3 * n - 1) / 2;
}

long Hexagonal(long n ) {
    return n * (2 * n -1);
}

long binary_search(long (*num)(long), long n, long x) {
    long head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;  // 等价于 mid = ( head + tail ) / 2
        if ( num(mid) == x ) return mid;
        if ( num(mid) < x ) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main(){
    int n = 285;
    while(1) {
        n++;
        long val = Triangle(n);
        if (binary_search(Pentagonal, val, val) == -1) continue;
        if (binary_search(Hexagonal, val, val) == -1) continue;
        printf("%ld\n", val);
        break;
    }
    return 0;

}
