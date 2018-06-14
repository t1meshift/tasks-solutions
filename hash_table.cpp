#include <iostream>
#include <vector>
#include <algorithm>
 
#define HT_SIZE 1000003
#define h(x) ((17*(x)+41)%(HT_SIZE))
 
using namespace std;
 
vector<long long> ht;
 
void ht_add(long long value) {
    long long hash = h(value);
    if (ht[hash] == 0 || ht[hash] == value) {
        ht[hash] = value;
    } else {
        for (int i = 1; i <= 50, hash+i < HT_SIZE; i++) {
            if (ht[hash+i] == 0) {
                ht[hash+i] = value;
                return;
            }
        }
    }
}
 
void ht_del(long long value) {
    long long hash = h(value);
    if (ht[hash] == 0 || ht[hash] == value) {
        ht[hash] = 0;
    } else {
        for (int i = 1; i <= 50, hash+i < HT_SIZE; i++) {
            if (ht[hash+i] == value) {
                ht[hash+i] = 0;
                return;
            }
        }
    }
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    ht.resize(HT_SIZE);
 
    long long num;
    while (cin >> num) {
        if (num > 0) {
            ht_add(num);
        }
        else if (num < 0) {
            ht_del(-num);
        }
        else break;
    }
    sort(ht.begin(), ht.end());
    for (long long &it : ht) {
        if (it != 0) {
            cout << it << ' ';
        }
    }
}
