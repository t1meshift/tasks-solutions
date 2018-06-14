#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
 
#define EXPONENT 9 //10^n
#define BASE ((uint32_t)pow(10, EXPONENT))
 
using namespace std;
 
vector<uint32_t> to_bigint(string str) {
    vector<uint32_t> result;
    for (int i = str.size(); i > 0; i -= EXPONENT)
        if (i < EXPONENT)
            result.push_back(atoi(str.substr(0, i).c_str()));
        else
            result.push_back(atoi(str.substr(i-EXPONENT, EXPONENT).c_str()));
    return result;
}
vector<uint32_t> add_bigint(vector<uint32_t> a, vector<uint32_t> b) {
    vector<uint32_t> result;
    auto it_a = a.begin(), it_b = b.begin();
    uint32_t carry = 0;
    while (it_a != a.end() || it_b != b.end() || carry) {
        uint32_t digit_val = carry;
        if (it_a != a.end())
            digit_val += *it_a;
        if (it_b != b.end())
            digit_val += *it_b;
 
        carry = digit_val / BASE;
        digit_val %= BASE;
 
        result.push_back(digit_val);
 
        if (it_a != a.end())
            ++it_a;
        if (it_b != b.end())
            ++it_b;
    }
    return result;
}
vector<uint32_t> mul_bigint(vector<uint32_t> a, vector<uint32_t> b) {
    vector<uint32_t> result(a.size()+b.size(), 0);
 
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0, carry = 0; j < b.size() || carry; ++j) {
            uint64_t curr_digit = result[i+j] + a[i] * 1ull * (j < b.size() ? b[j] : 0) + carry;
            result[i+j] = (uint32_t) (curr_digit % BASE);
            carry = (uint32_t) (curr_digit / BASE);
        }
    }
 
    while (result.size() > 1 && !result.back()) {
        result.pop_back();
    }
    return result;
}
vector<uint32_t> pow_bigint(vector<uint32_t> base, uint32_t exponent) {
    vector<uint32_t> result = to_bigint("1");
    while (exponent) {
        if (exponent & 1) {
            result = mul_bigint(result, base);
        }
        base = mul_bigint(base, base);
        exponent >>= 1;
    }
    return result;
}
 
string bigint_to_str(vector<uint32_t> a) {
    ostringstream ss;
    if (a.empty())
        ss << "0";
    else
        ss << a.back();
 
    for (int i = a.size()-2; i >= 0; --i)
        ss << setw(EXPONENT) << setfill('0') << to_string(a[i]);
 
    string result(ss.str());
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string a, b;
    vector<uint32_t> operand1, result;
    uint32_t operand2;
 
    cin >> a >> operand2;
    operand1 = to_bigint(a);
 
    result = pow_bigint(operand1, operand2);
 
    cout << bigint_to_str(result);
 
    return 0;
}
