#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 200010;
int n,m;
vector<int> b[N]; //3
map<PII,int> mp;
map<PII,int> mpp;
void solve(){
	cin >> n >> m;
	vector<int> a[n]; //2
	while(m--){
		int op,x,y;
		cin >> op >> x;
		if(op == 1){
			cin >> y;
			if(!mpp[{x,y}]) b[x].push_back(y);
			mpp[{x,y}]++;
			y--;
			a[y].push_back(x);
			// mp[{x,y}]++;
			
		}else if(op == 2){
			x--;
			sort(a[x].begin() , a[x].end());
			for(auto z : a[x]) cout << z << ' ';
			cout << endl;
		}else{
			sort(b[x].begin(),b[x].end());
			for(auto z : b[x]) cout << z << ' ';
			cout << endl;
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