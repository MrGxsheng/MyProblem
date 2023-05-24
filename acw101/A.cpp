#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	double a,b,c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(6);
    double z = (-1 * b - sqrt(b * b - 4 * a * c) ) / (2 * a);
    double zz = (-1 * b + sqrt(b * b - 4 * a * c) ) / (2 * a);
    if(z < zz) swap(z,zz);

    cout << z << endl;
    cout << zz << endl;
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