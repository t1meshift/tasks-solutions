#include <iostream>
#include <vector>
#include <cmath>
 
 
using namespace std;
 
int part(vector<int> &a, int l, int r) {
    if (r-l > 0) {
        swap(a[l + rand() % (r - l)], a[l]);
    }
    int pivot = a[l];
    while (l != r)
    {
        if (a[l] > a[r])
        {
            swap(a[l], a[r]);
        }
        if (a[l] == pivot) r--;
        else l++;
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
    int n, k, kth_order;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    --k; //т.к. массив с нуля
 
    int l = 0;
    int r = arr.size()-1;
    while (true) {
        int m = part(arr, l, r);
        if (m == k) {
            kth_order = arr[m];
            break;
        } else if (m > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << kth_order;
    return 0;
}
