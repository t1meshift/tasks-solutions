#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
#define EXPONENT 9 //10^n
#define BASE ((uint32_t)pow(10, EXPONENT))
 
using namespace std;
 
vector<uint32_t> to_bigint(string str) {
    vector<uint32_t> result;
    int32_t i = str.size();
    while ((i -= EXPONENT) >= -EXPONENT) {
        uint32_t digit = 0;
        if (i < 0) {
            i += EXPONENT;
            int32_t k = 1;
            while (i-k >= 0) {
                digit += (str[i - k] - '0') * pow(10, (k++) - 1);
            }
            if (digit)
                result.push_back(digit);
            break;
        } else {
            for (int32_t k = EXPONENT-1; k >= 0; --k) {
                digit += (str[i + k] - '0')*pow(10, EXPONENT-k-1);
            }
            result.push_back(digit);
        }
    }
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
 
string bigint_to_str(vector<uint32_t> a) {
    string result;
    if (a.empty())
        return "0";
    for (int32_t i = a.size()-1; i >= 0; --i) {
        if (i != a.size()-1) {
            uint32_t trail = BASE/10;
            while (trail > 0) {
                if (a[i] < trail) {
                    result.append("0");
                    trail /= 10;
                } else break;
            }
        }
        result.append(to_string(a[i]));
    }
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    string a, b;
    vector<uint32_t> operand1, operand2, result;
 
    cin >> a >> b;
    operand1 = to_bigint(a);
    operand2 = to_bigint(b);
 
    result = add_bigint(operand1, operand2);
 
    cout << bigint_to_str(result);
 
    return 0;
}
