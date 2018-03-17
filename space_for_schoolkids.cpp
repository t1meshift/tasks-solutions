#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
 
using namespace std;
 
string mins_to_str(int mins)
{
    string hh = "00:00";
    hh[0] = ((mins/60)/10) + '0';
    hh[1] = ((mins/60)%10) + '0';
    hh[3] = ((mins%60)/10) + '0';
    hh[4] = ((mins%60)%10) + '0';
    return hh;
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    vector<int> t(1440, 0);
    string time;
    int n;
    cin >> n;
    getline(cin, time);
    for (int i = 0; i < n; i++)
    {
        getline(cin, time);
        int time_ind = (time[4] - '0') + (time[3]-'0') * 10 + ((time[1] - '0') + (time[0] - '0') * 10)*60;
        t[time_ind]++;
    }
    bool free_period = false;
    int ind_start = -1, ind_end = -1;
    int i = 0;
    while (i < 1440)
    {
        if (t[i] == 0)
        {
            free_period = true;
            ind_start = i;
            ind_end = i;
            while ((++i < 1440) && (t[i] == 0));
            if (t[i-1] == 0)
                ind_end = i-1;
            string hh_start = mins_to_str(ind_start);
            if (ind_start == ind_end)
                cout << hh_start << endl;
            else
                cout << hh_start << " - " << mins_to_str(ind_end) << endl;
        }
        i++;
    }
    if (!free_period)
        cout << "NONE";
    return 0;
}
