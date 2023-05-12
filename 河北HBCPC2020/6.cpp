#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100;
int n,m;

struct Node{
	int hp,attack,mp,id;
	bool operator<(const Node &E) const{
		return id < E.id;
	}
}node[N];
queue<node> q,qq;
void solve(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string s;
		int x;
		cin >> s >> x;
		if(s == "Gigi"){
			q.push({900,65,100,i + 1});
		}else if(s == "Nick"){
			q.push({900,65,100,i + 1});
		}else if(s == 'Thai'){
			q.push({900,65,100,i + 1});
		}else 			q.push({900,65,100,i + 1});

	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}