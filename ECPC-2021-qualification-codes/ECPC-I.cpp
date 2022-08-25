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
    for (int i = 0; i < t; i++)
    {
        ui n, q;
        cin >> n >> q;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // vector<pair<ui, ui>> v1;
        vector<pair<ui, ui>> v2;
        ui a, b ,c;
        vector<ll> prefsum(n);
        for (int i = 0; i < q; i++)
        {
            cin >> a >> b >> c;
            ui maxInt = *max_element(arr + b - 1, arr + c);
            if(a == 1)
            {
                prefsum[a] += maxInt;
                if(b+1 < n)
                prefsum[b+1] -= maxInt;
            }
            else
            {
                v2.push_back(make_pair(b,c));
            }
        }
        ull sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += prefsum[i];
            prefsum[i] = sum;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = prefsum[i] - arr[i];
        }

        for (auto v : v2)
        {
            ll maxINt = *max_element(arr + v.first - 1, arr + v.second);
            cout << maxINt << "\n";
        }
        
        
        
        
    }
    
    return 0;
}