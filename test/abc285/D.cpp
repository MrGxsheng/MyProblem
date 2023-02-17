#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	set<string> st;
	vector<string> s(n),t(n);
	vector<string> adj[N];
	map<string ,int> mp;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] >> t[i];
		st.insert(s[i]);
		st.insert(t[i]);
	}

	int cnt = 0;
	for(auto x : st){
		mp[x] = cnt++;
	}
	vector<int> idx(cnt);
	vector<vector<int>> edge(cnt);
	for(int i = 0 ; i < n ; i++){
		int a = mp[s[i]];
		int b = mp[t[i]];
		edge[a].push_back(b);
		idx[b]++;
	}


	queue<int> q;
	for(int i = 0 ; i < cnt ; i++)
		if(!idx[i]) q.push(i);

	while(q.size()){
		auto it = q.front();
		q.pop();
		cnt--;
		for(auto x : edge[it]){
			if(--idx[x] == 0){
				q.push(x);
			}
		}
	}

	if(cnt) cout << "No" << endl;
	else cout << "Yes" << endl;
		
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

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//        _                                    _  _  _         _                   
//       | |                                  (_)| || |       | |                  
//   ___ | |__    ___  _ __    __ _ __      __ _ | || |  __ _ | | __    ___  _ __  
//  / __|| '_ \  / _ \| '_ \  / _` |\ \ /\ / /| || || | / _` || |/ /   / __|| '_ \ 
//  \__ \| | | ||  __/| | | || (_| | \ V  V / | || || || (_| ||   <  _| (__ | | | |
//  |___/|_| |_| \___||_| |_| \__, |  \_/\_/  |_||_||_| \__,_||_|\_\(_)\___||_| |_|
//                             __/ |                                               
//                            |___/                                             
