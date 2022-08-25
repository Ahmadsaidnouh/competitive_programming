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
 
 
    ull n;
    cin >> n;

    char bin[100];
    int index = 0;
    while (n > 0)
    {
        if(n%2 == 0)
        {
            bin[index] = '0';
        }
        else
            bin[index] = '1';
        n /= 2;
        index++;
    }

    bin[index] = 0;
    ull sum = 0;
    int skip = index%2 == 0 ? 2 : 1;
    for (int i = 0; i < index; i += 2)
    {
        if(bin[index - i - skip] == '1' )
            sum++;
    }
    cout << sum;
    
    

    return 0;
}