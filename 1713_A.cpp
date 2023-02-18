#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 1e9
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	int maxv = 0,minv = 0,maxy = 0,miny = 0;


	for(int i = 1 ; i <= n ; i++){
		int x , y;
		cin >> x >> y;
		if(x == 0){
			maxy = max(maxy,y);
			miny = min(miny,y);
		}else if(y == 0){
			maxv = max(maxv,x);
			minv = min(minv,x);
		}
	}
	

	cout << (maxv - minv + maxy - miny) * 2 << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
