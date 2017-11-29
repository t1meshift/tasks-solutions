#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n,m, ans = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> scene(n);
    vector<vector<int>> pref_row(n), pref_col(m);
    for (int i = 0; i < n; i++)
    {
        scene[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> scene[i][j];
            if (!j)
                pref_row[i].push_back(scene[i][j]);
            else
                pref_row[i].push_back(pref_row[i][j - 1] + scene[i][j]);

            if (!i)
                pref_col[j].push_back(scene[i][j]);
            else
                pref_col[j].push_back(pref_col[j][i - 1] + scene[i][j]);

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            if (scene[i][j]) continue;
            //light ^
            if (pref_col[j][i] > 0)
                ans++;
            //light \/
            if (pref_col[j][n-1] - pref_col[j][i] > 0)
                ans++;
            //light <
            if (pref_row[i][j] > 0)
                ans++;
            //light >
            if (pref_row[i][m-1] - pref_row[i][j] > 0)
                ans++;
        }
    }
    cout << ans;
}