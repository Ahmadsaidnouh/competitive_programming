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
    for (int o = 0; o < t; o++)
    {
        string str, keys;
        cin >> str >> keys;

        map<char, bool> m;
        char ch;

        for (int i = 0; i < str.size(); i++)
        {
            ch = str[i];

            if(ch == 'k')
            continue;

            try
            {
                m.at(ch);
                if((i != str.size() - 1 && str[i + 1] != 'k') || i == str.size() - 1)
                {
                    m[ch] = false;
                }

            }
            catch(const std::exception& e)
            {
                if((i != str.size() - 1 && str[i + 1] != 'k') || i == str.size() - 1)
                {
                    m[ch] = false;
                }
                else
                {
                    m[ch] = true;
                }
                // std::cerr << e.what() << '\n';
            }
            
        }

        bool flag = true;

        for (int i = 0; i < keys.size(); i++)
        {
            try
            {
                m.at(keys[i]);
                if(m[keys[i]] == false)
                {
                    flag = false;
                    break;
                }
            }
            catch(const std::exception& e)
            {
                // std::cerr << e.what() << '\n';

            }
            
        }

        if(flag)
        {
            for (int i = 0; i < str.size(); i++)
            {
                if(str[i] != 'k')
                    cout << str[i];
            }
            cout << "\n";

        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
        
        

    }
    
    // string str;

    return 0;
}