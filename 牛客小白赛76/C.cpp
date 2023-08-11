#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
    int n, m;
    cin >> n >> m;
    if(n <= m) {
        cout << -1 << endl;
        return;
    }
    if(n - m > m){
        cout << m << ' ' << n - m << endl;
        return;
    }else{
        for(int i = m + 1 ; i <= n - m ; i++)
            if((n - i) % i == m){
                cout << n - i << ' ' << i << endl;
                return;
            }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    // T = 1;
    while(T--) solve();
    return 0;
}