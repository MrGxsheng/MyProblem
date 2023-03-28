#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
char mp[50][50];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]>='1'&&mp[i][j]<='9'){
				for(int a=1;a<=n;a++){
					for(int b=1;b<=m;b++){
						if(abs(a-i)+abs(b-j)>mp[i][j]-'0') continue;
						if(mp[a][b]=='#') mp[a][b]='.';
					}
				}
				mp[i][j]='.';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j];
		}
		cout<<"\n";
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