#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
 
#define MIN(a,b) ((a) < (b) ? (a) : (b))
 
using namespace std;
 
int n; // количество классов
int m; // количество моделей кондиционеров
vector<int> conds(1001, 1001); // индекс -- мощность, значение -- минимальная цена
set<int> watts_set; // доступный набор мощностей, конвертится в vector<int> watts
int total_cost = 0; // результат
vector<int> classes; // минимальная мощность кондиционера для каждого класса
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
 
    cin >> n;
    classes.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> classes[i];
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
        int bj, cj; // мощность и цена кондиционера
        cin >> bj >> cj;
        watts_set.insert(bj);
        conds[bj] = MIN(cj, conds[bj]);
    }
    vector<int> watts(watts_set.begin(), watts_set.end());
 
    for (int min_watt : classes) {
        int l = 0;
        int r = watts.size()-1;
        // отсекаем недостаточно мощные кондиционеры
        while (r-l > 0) {
            int m = (l+r)/2;
            if (watts[m] >= min_watt) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        l += watts[l] < min_watt;
        int min_cost = 1001;
        for (int i = l; i < watts.size(); ++i) {
            min_cost = MIN(conds[watts[i]], min_cost);
        }
        total_cost += min_cost;
    }
    cout << total_cost;
    return 0;
}
