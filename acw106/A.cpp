#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
    cin >> n >> m;
    string s;
    cin >> s;
    while(m--){
          int l,r;
          char x,y;
          cin >> l >> r >> x >> y;
          l--,r--;
          for(int i = l ; i <= r ; i++){
            if(s[i] == x) s[i] = y;
          }
    }
    cout << s << endl;
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