#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
  int x,y;
	cin>>x>>y;
	int c1=0,c2=0;
	while(x>2)x=(x-1)/2,c1++;
	while(y>2)y=(y-1)/2,c2++;
	cout<<(c1==c2?"Bob\n":"Alice\n");

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}