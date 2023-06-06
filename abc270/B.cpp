#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int X,Y,Z;
	cin >> X >> Y >> Z;
	
	if(X < 0){
		X = -X;
		Y = -Y;
		Z = -Z;
	}

	if(Y < 0 || Y > X){
		cout << X << endl;
	}else if(Z < Y){
		cout << abs(Z) + X - Z << endl;
	}else cout << -1 << endl;

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