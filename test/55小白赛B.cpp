#include <algorithm>
#include <iostream>
 
using namespace std;
 
signed main()
{
    long long a, b;
    cin >> a >> b;
    long long c = 0;
    for (int i = 62; i >= 0; i -- )
        if ((((a >> i) & 1) && (b >> i & 1)) ||(!(a >> i & 1) && !(b >> i & 1)))
            c += (long long)1 << i;
    cout << c << endl;
}