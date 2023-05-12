#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
struct node{
	int x,y;
}a[16];
set<PII> st;
int n,m;
int ans,res = 0x3f3f3f3f;
map<PII,vector<int>> mp;
int gcd(int x,int y){
	if(x == 0) return 1;
	return y ? gcd(y, y % x) : x;
}

void f(int t1,int t2){
	PII p1,p2;

	int x = a[t1].x - a[t2].x, y = a[t1].y - a[t2].y;
	int g = gcd(abs(y),abs(x));

	if(!x) p1 = {1,0};
	else if(!y) p1 = {0,1};
	else {
		if(y < 0) p1 = {-y / g , -x / g};
		else p1 = {y / g , x / g};
	}

	for(int i = 1 ; i <= n ; i++){
		if(i != t1 && i != t2){
			int x = a[i].x - a[t1].x, y = a[i].y - a[t1].y;
			int g = gcd(abs(y),abs(x));
			
			if(!x) p2 = {1,0};
			else if(!y) p2 = {0,1};
			else 
				if(y < 0) p2 = {-y / g , -x / g};
				else p2 = {y / g , x / g};
			if(p1 == p2){
				mp[{t1,t2}].push_back(i);
			}
		}
	}

}

int vis[16];

void ak(int x, int y){ // 连接
	for(auto i : mp[{x,y}])
		vis[i] = 1;
}

void ak2(int x, int y){ // 不连接
	for(auto i : mp[{x,y}])
		vis[i] = 0;
}

void dfs(){
	int p = 0;
	if(ans < res){
		for(int i = 1 ; i <= n ; i++)
			if(!vis[i]) p++;
		if(p == 1) {
			res = min(ans + 1, res);
			return;
		}else if(p == 0){
			res = ans;
			return;
		}
	}


	if(ans >= res) return;

	// 找两个没连线的点
	int p1 = 0 , p2 = 0;
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i] && !p1) p1 = i;
		else if(!vis[i] && p1 && !p2) p2 = i;
		if(p1 && p2) break;
	}

	if(p1 > p2) swap(p1,p2);

	ak(p1,p2);
	vis[p1] = 1;
	vis[p2] = 1;
	ans++;

	dfs();

	ak2(p1,p2);
	vis[p1] = 0;
	vis[p2] = 0;
	ans--;
}


void solve(){
	cin >> n;
	if(n <= 2){
		cout << 1 << endl;
		return;
	}

	for(int i = 1 ; i <= n ; i++){
		int t1,t2;
		cin >> t1 >> t2;
		if(st.count({t1,t2})){
			n--,i--;
			continue;
		}
		st.insert({t1,t2});
		a[i].x = t1;
		a[i].y = t2;
	}

	for(int i = 1 ; i <= n ; i++)
		for(int j = i + 1 ; j <= n ; j++)
			f(i,j);

	dfs();
	cout << res << endl;
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