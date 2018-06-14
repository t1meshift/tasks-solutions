#include <iostream>
#include <vector>
#include <cmath>
 
 
using namespace std;
 
int n, xb, yb, xe, ye;
int field[100][100];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    cin >> n >> xb >> yb >> xe >> ye;
 
    vector<pair<int, int>> cells_to_see = { {yb-1, xb-1} };
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            field[i][j] = (a == '#' ? -1 : 0); //ставим стены
        }
    }
 
    while (!cells_to_see.empty()) {
        int j = cells_to_see.begin()->first; //y
        int k = cells_to_see.begin()->second; //x
        // spread left
        if (k-1 >= 0) {
            if (field[j][k-1] != -1) {
                if (j != yb-1 || k-1 != xb-1) {
                    if (field[j][k - 1] > (field[j][k] + 1) || field[j][k - 1] == 0) {
                        field[j][k - 1] = field[j][k] + 1;
                        cells_to_see.push_back({j, k - 1});
                    }
                }
            }
        }
        // spread right
        if (k+1 <= n-1) {
            if (field[j][k+1] != -1) {
                if (j != yb - 1 || k+1 != xb - 1) {
                    if (field[j][k + 1] > (field[j][k] + 1) || field[j][k + 1] == 0) {
                        field[j][k + 1] = field[j][k] + 1;
                        cells_to_see.push_back({j, k + 1});
                    }
                }
            }
        }
        //spread up
        if (j-1 >= 0) {
            if (field[j-1][k] != -1) {
                if (j-1 != yb-1 || k != xb-1) {
                    if (field[j - 1][k] > (field[j][k] + 1) || field[j - 1][k] == 0) {
                        field[j - 1][k] = field[j][k] + 1;
                        cells_to_see.push_back({j - 1, k});
                    }
                }
            }
        }
        //spread down
        if (j+1 <= n-1) {
            if (field[j+1][k] != -1) {
                if (j+1 != yb - 1 || k != xb - 1) {
                    if (field[j + 1][k] > (field[j][k] + 1) || field[j + 1][k] == 0) {
                        field[j + 1][k] = field[j][k] + 1;
                        cells_to_see.push_back({j + 1, k});
                    }
                }
            }
        }
        cells_to_see.erase(cells_to_see.begin());
    }
 
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;*/
 
    cout << field[ye-1][xe-1];
    return 0;
}
