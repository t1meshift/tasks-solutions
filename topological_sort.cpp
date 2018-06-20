#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
 
 
using namespace std;
vector<int> ans;
 
int dfs(vector<vector<int>> &g, vector<char> &used, int &v) {
    int result = true;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int dst = g[v][i];
        if (used[dst] == 1) {
            return false;
        } else if (used[dst] == 0){
            result = dfs(g, used, dst);
        }
    }
    used[v] = 2;
    ans.push_back(v);
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
    vector<char> used(n, 0);
 
    int src, dst;
    for (int i = 0; i < m; ++i) {
        cin >> src >> dst;
        g[src-1].push_back(dst-1);
    }
 
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            if (!dfs(g, used, i)) {
                cout << "-1";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
 
    for (int i : ans) {
        cout << i+1 << " ";
    }
    return 0;
}
