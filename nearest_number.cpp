#include <iostream>
#include <vector>
#include <cmath>
#include <set>

// Ближайшее число

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, curr_num;
    set<pair<int, int>> stack;
    vector<int> ans;
    pair<int, int> curr, t;
    cin >> n;
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> curr_num;
        curr = make_pair(curr_num, i);
        ans[i] = curr.first; // Если ближайшего не найдётся
        while (!stack.empty() && (t = *stack.begin()).first < curr.first) // Ищем меньшие числа, для которых ближайшее ещё не найдено
        {
            ans[t.second] = curr.first;
            stack.erase(stack.begin()); // Нашли, удаляем из стека за ненадобностью
        }
        stack.insert(curr); // А текущее добавляем, так как для него ближайшее ещё не считано с ввода
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
