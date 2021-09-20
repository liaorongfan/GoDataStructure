/*************************************************************************
	> File Name: 20.sum_of_two_num.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Sep 2021 01:46:58 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int n, t, num[1000005];


int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    //define two pointers
    int l = 0, r = n - 1;
    while (l < r) {
        // find required two numbers, print their indexes and return
        if (num[l] + num[r] == t) {
            cout << l << " " << r << endl;  
            return 0;
        }
        if (num[l] + num[r] < t) {
            l++;
        } else {
            r--;
        }
    }
    // no satisfied numbers
    cout << -1 << endl;
    


    return 0;
}
