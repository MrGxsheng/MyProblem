#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
typedef long long LL;

const int N = 200010;
int n,m;
int a[N];
map<LL,LL> mp,mpp;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    
    LL ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] % m == 0) {
            ans += mpp[a[i] / m];
            mpp[a[i]] += mp[a[i] / m];
        }
        mp[a[i]]++;
    }
    
    cout << ans << endl;
}