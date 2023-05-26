#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string str;
    while(cin >> str){
        map<char, int> mp;
        vector<int> v;
        int idx = 0;
        for(int i = 0; i < str.size(); i ++ ){
            if(!mp.count(str[i])) mp[str[i]] = ++ idx;
            v.push_back(mp[str[i]]);
        }
         
        int res = 0, sum = 0, n = str.size();
        for(auto x : v) res ^= x, sum += x;
        if(sum == n * v[0]) cout << n << endl;
        else{
            if(res) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }

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