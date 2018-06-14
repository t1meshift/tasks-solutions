#include <iostream>
#include <vector>
#include <cmath>
 
 
using namespace std;
 
int64_t n, p, c, x;
 
int credit_paid(int64_t payment) {
    int64_t debt = c;
    int64_t afterpay = debt - payment;
    long double gain = 1.0 + p / 100.0;
 
    if (afterpay * gain >= debt) {
        return 0;
    }
    for (int i = 0; i < 12 * n; ++i) {
        if (afterpay * gain >= debt) {
            return 0;
        }
        if (debt <= 0) {
            return 1;
        }
        debt = (int64_t) ceil(afterpay * gain);
        afterpay = debt - payment;
    }
    if (debt <= 0) {
        return 1;
    } else {
        return 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    cin >> n >> p >> c;
    int64_t l = 1, r = c;
    while (r-l > 1) {
        x = (l + r) / 2;
        if (credit_paid(x)) {
            r = x;
        } else {
            l = x;
        }
    }
    x = credit_paid(l) ? l : r;
 
    cout << x;
    return 0;
}
