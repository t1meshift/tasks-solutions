#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int part_size, time_cnt;
pair<int, int> curr_part;
vector<pair<int, int>> parts;
vector<int> stack;
vector<double> collides;
 
int main() {
    freopen("linear.in", "r", stdin);
    freopen("linear.out", "w", stdout);
 
    cin >> part_size;
 
    for (int i = 0; i < part_size; ++i) {
        cin >> curr_part.first >> curr_part.second;
        parts.push_back(curr_part);
    }
 
    for (int i = 0; i < part_size; ++i) {
        switch (parts[i].second) {
            case 1:
                stack.push_back(parts[i].first);
                break;
            case -1:
                if (stack.size() != 0) {
                    collides.push_back(abs(stack[stack.size()-1] - parts[i].first) / 2.);
                    stack.pop_back();
                }
                break;
        }
    }
    sort(collides.begin(), collides.end());
    cin >> time_cnt;
    for (int i = 0; i < time_cnt; ++i) {
        int t;
        cin >> t;
        if (collides.size() == 0) {
            cout << part_size << endl;
            continue;
        }
 
        int l = 0, r = collides.size();
        int m;
 
        while (r - l > 1) {
            m = (l + r) / 2;
            if (collides[m] > t) {
                r = m;
            } else {
                l = m;
            }
        }
 
        if ((l == 0) && (collides[0] > t)) {
            cout << part_size << endl;
        } else {
            cout << part_size - ((l + 1) * 2) << endl;
        }
    }
    return 0;
}
