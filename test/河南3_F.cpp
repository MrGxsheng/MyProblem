#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int d[8] = {0,2,8,8,18,18,32,32};
void solve(){
	cin >> n;
	int res = 0 ;
	int s = 0;
	for(int i = 1 ; i <= 7 ; i++){
        n -= d[i];
        if(n <= 0) {
            cout << i << endl;
            break;
        }

	} 

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
