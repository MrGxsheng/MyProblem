#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 5000010;
int n,m;
int primes[N],cnt;
bool st[N];
int p[N];
int a[N];
int si[N];
int nmp[N];


void get_primes(int n){
	for(int i = 2 ; i <= n ; i++){
		if(st[i]) continue;
		primes[cnt++] = i;
        nmp[i] = i;
		for(int j = i + i ; j <= n ; j += i)
			st[j] = true;
		
	}
}

int gcd(int a,int b){
	return b ? gcd(b,a % b) : a;
}

bool check(int x)
{
    int y=0;
    for(int i=0;i<cnt;i++)
    {
        if(x % primes[i] == 0)
        {
            while(x % primes[i]==0)x /= primes[i];
            y++;
        }
        if(y >= 2) return true;
    }
    return y >= 2;
}

int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}


void solve(){
	int res = 1;
	cin >> n;
	get_primes(3000);
	for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        p[i] = i;
        si[i] = 1;

    }

	for(int i = 1 ; i <= n - 1 ; i ++){
		int x,y;
		cin >> x >> y;
		int pa = find(x);
		int pb = find(y);
		int t = gcd(a[x],a[y]);
		if(!check(t)) continue;
		if(pa != pb){
			p[pa] = pb;
			si[pb] += si[pa];
            si[pa] = si[pb];
		}
		res = max(res,si[pb]);
	}

	cout << res << endl;


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

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
