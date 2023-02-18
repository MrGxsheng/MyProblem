#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
struct Node
{
	int a ,b ,c ,d; 
}no[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= n ;  i++){
		int a , b ,c ,d;
		cin >> a >> b >> c >> d;
		no[i] = {a,b,c,d};
	}

	int x , y;
	cin >> x >> y;
	for(int i = n; i >= 1 ; i--){
		if(x >= no[i].a && y >= no[i].b && x <= no[i].c && y <= no[i].d) {
			cout  << i << endl;
			return;
		}else if(x >= no[i].a && y >= no[i].b && x <= no[i].c && y >= no[i].d) {
			cout  << i << endl;
			return;
		}
	}
	cout << -1 << endl;




}

 int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
