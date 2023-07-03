#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 5000 + 10;
char s[N][N]={
    "******",
    "******",
    "******",
    "***...",
    "***...",
    "***..."
};

void solve(){
	int n;
    cin>>n;
    int len = 6;
    for(int i = 1 ; i < n ; ++i) {
        // [0,3*2^i)  -> [3*2^i,3*2^(i+1))
        for(int j = 0; j < 3 << i ; ++j)
            copy(s[j],s[j] + (3 << i),s[j] + (3 << i));
        for(int j = 0 ; j < 6 << i; ++j)
            for(int r = 0 ; r < 3 << i; ++r)
                s[r + (3 << i)][j] = s[r][j];
        for(int j = 0 ; j < 6 << i; ++j)
            for(int r = 0 ; r < 6 << i ; ++r) {
                if(j >= (3 << i) && r >= (3 << i)) continue;
                else s[r][j] = (int('*') + int('.') - s[r][j]);
            }
    }
    for(int i = 0 ; i < 3 << n ; ++i,cout<<'\n')
        for(int j = 0 ; j < 3 << n; ++j)
            cout<<s[i][j];
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