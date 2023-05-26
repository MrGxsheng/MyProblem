#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0;i < n ; i++){
        if(s.substr(i,4) == "CCPC")
            ans++;
    }
    for(int i = 0 ; i < n ; i++){
        if(s.substr(i,3) == "CCP"&&s.substr(i,4) != "CCPC"){
            ans++;
            break;
        }
        if(s.substr(i,3) == "CCC"&&s.substr(i+1,4) != "CCPC"){
            ans++;
            break;
        }
       if((i == 0 && s.substr(i,3) == "CPC") || (s.substr(i,3) == "CPC"&&s.substr(i-1,4) != "CCPC")){
            ans++;
            break;
        }
    }
	cout << ans << endl;

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

