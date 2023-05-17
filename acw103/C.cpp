#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int prime[N];
bool st[N];
int cnt;
void get_primes(){
    for(int i = 2 ; i <= n ; i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j = 0 ; prime[j] <= n / i ; j++){
            st[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve(){
    cin >> n;
    get_primes();
    vector<int> ans;
    for(int i = 0; i < cnt; i++) {
        for(int j = prime[i]; j <= n; j *= prime[i]) {
            ans.push_back(j);
        }
    }
    printf("%d\n", ans.size());
    for(int x: ans) printf("%d ", x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    // cin >> T;
    T = 1;
    while(T--) solve();
    return 0;
}