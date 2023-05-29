#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;

bool dfs(string s,int now,int k,vector<bool> book){	
	if(k == now){
		LL ans = 0 , sum = s[0] - '0'; //sum开始不为0，就使得一开始就有+号的情况能正好避免
		for(int j = 1 ; j < s.size() ; j++){
			if(!book[j]) sum = sum * 10 + s[j] - '0';
			else {
				ans += sum;
				sum = s[j] - '0';
			}
		}
		ans += sum;
		
		if(ans == n) return true;
		return false;
	}

	for(int j = 1 ; j < s.size() ; j++){
		if(!book[j]){
			book[j] = true;
			if(dfs(s,now,k + 1,book)) return true;
			book[j] = false;
		}
	}
	return false;
	
}

void solve(){
	string s;
	cin >> s >> n;
	for(int i = 0 ; i < s.size() ; i++){
		vector<bool> book(550,false);
		if(dfs(s,i,0,book)) {
			cout << i << endl;
			return;
		}
	}

	cout << -1 << endl;
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