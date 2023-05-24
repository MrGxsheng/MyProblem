#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
    stack<string> q;
    map<string,int> mp;
    for(int i = 0 ; i < n ; i++){
        string ss;
        cin >> ss;
        q.push(ss);
    }

    while(q.size()){
        string s = q.top();
        q.pop();
        if(!mp[s]){
            cout << s << endl;
            mp[s] = 1;
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