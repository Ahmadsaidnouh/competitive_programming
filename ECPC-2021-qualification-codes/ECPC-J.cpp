#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout << std::setprecision(10) << std::fixed;

    ui t;
    cin >> t;
    for (int m = 0; m < t; m++)
    {
        ui n;
        cin >> n;

        if(n == 1)
        {
            cout << "0" << "\n";
            break;
        }

        ui maxStr = 0;
        string strs[n];
        for (int i = 0; i < n; i++)
        {
            cin >> strs[i];

            maxStr = maxStr > strs[i].size() ? maxStr : strs[i].size();
        }

        vector<tuple<bool, int, int>> robots(n);
        for (int i = 0; i < n; i++)
        {
            cin >> get<1>(robots[i]) >> get<2>(robots[i]);
        }

        ull crashes = 0;
        ui x, y;
        map<pair<ll, ll>, ui> crashpoints;
        for (int i = 0; i < maxStr; i++)
        {
            // cout << "i = " << i << endl;
            map<pair<ll, ll>, ui> mp = crashpoints;
            for (int j = 0; j < n; j++)
            {
                if (i >= strs[j].size() || get<0>(robots[j]))
                {
                    continue;
                }
                else
                {
                    x = 0, y = 0;
                    if (strs[j][i] == 'U')
                        y = 1;
                    else if (strs[j][i] == 'D')
                        y = -1;
                    else if (strs[j][i] == 'L')
                        x = -1;
                    else
                        x = 1;
                    pair<ll, ll> point = make_pair(x + get<1>(robots[j]), y + get<2>(robots[j]));

                    try
                    {
                        mp.at(point);
                        get<0>(robots[mp[point]]) = true;
                        get<0>(robots[j]) = true;
                        try
                        {
                            crashpoints.at(point);
                        }
                        catch (const std::exception &e)
                        {
                            crashpoints[point] = j;
                        }

                        crashes++;
                        // cout << "crashes = " << crashes << endl;
                    }
                    catch (const std::exception &e)
                    {
                        // std::cerr << e.what() << '\n';
                        mp[point] = j;
                        get<1>(robots[j]) = point.first;
                        get<2>(robots[j]) = point.second;
                    }
                }
            }
            if (crashes == n)
                break;
        }
        cout << crashes + 1 << "\n";
    }

    return 0;
}