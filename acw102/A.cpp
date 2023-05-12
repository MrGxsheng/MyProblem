#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 111;
int main()
{
    int n;
    cin >> n;
    int ans;
    int c = 0;
    for(int i = 1 ; i <= n ; i++){
        int a;
        cin >> a;
        c |= a;
    }
    ans += c;
    c = 0;

    for(int i = 1 ; i <= n; i++){
        int b;
        cin >> b;
        c |= b;
    }
    cout << ans + c << endl;
}