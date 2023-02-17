#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m;
vector<LL> a(1000);
void init(){
	a[1] = 1;
	a[0] = 0;
	for(int i = 2 ; i <= 88 ; i++) a[i] = a[i - 1] + a[i - 2];
}

void solve(){
	cin >> n;
    LL res = a[88];
    LL id = 1;
    for(int i = 1 ; i <= 88 ; i++){
        id = i;
        if(n <= a[i]) break;
    }
    if(id == 1) cout << 1 << endl;
    else if(abs(a[id] - n ) > abs(a[id - 1] - n)){
        if(a[id - 1] == 1) cout << 1 << endl;
        else cout << id - 1 << endl;
        }else cout << id << endl;
}

int main(){
	int T;
	cin >> T;
	init();
	while(T--) solve();
	return 0;
}
