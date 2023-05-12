#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int a,b,c,d;
	scanf("%d:%d %d-%d",&a,&b,&c,&d);

	if (d != 1){
		cout << "05:05" << endl;
		return;
	}

	b += 5;
	if(b >= 60){
		a += 1;
		b -= 60;
	}
	if(b < 10){
		printf("0%d:0%d\n", a,b);
	}else 
		printf("0%d:%d\n", a,b);
	

}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	// T = 1;
	while(T--) solve();
	return 0;
}