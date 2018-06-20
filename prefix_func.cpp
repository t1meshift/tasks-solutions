#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
 
 
using namespace std;
 
vector<int> p(string &s) {
    vector<int> p(s.size());
    p[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int k = p[i-1];
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            ++k;
        }
        p[i] = k;
    }
    return p;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string str;
    getline(cin, str);
 
    vector<int> prefs = p(str);
    int64_t p_sum = 0;
    for (int64_t i : prefs) {
        p_sum += i;
    }
    cout << p_sum;
    return 0;
}
