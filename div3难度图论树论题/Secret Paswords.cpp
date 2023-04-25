#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int p[N];

int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n;
	vector<string> a(n);
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	vector<int> v[26];
	for(int i = 0 ; i < n ; i++){
		string s = a[i];

		map<int,int> mp;
		for(int j = 0 ; j < s.size() ; j++){
			if(!mp[s[j] - 'a']){
				mp[s[j] - 'a']++;
				v[s[j] - 'a'].push_back(i + 1);	
			}
		}
	}
  
	for(int i = 0 ; i < 26 ; i++){
		for(int j = 1 ; j < v[i].size() ; j++){
			int pa = find(v[i][j - 1]);
			int pb = find(v[i][j]);
            
			if(pa != pb){
				p[pa] = pb;
			}
		}
	}
  
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		if(i == find(i)) ans++;
		
	cout << ans << endl;
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