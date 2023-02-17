#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 510 , M = N * N / 2;
int n,m,k;
PII q[M];
int p[M];
struct Edge{
	int a ,b;
	double w;
	bool operator< (const Edge &t ) const{
		return w < t.w;
	}
}e[M];


int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

double get_dist(PII a , PII b){
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

void solve(){
	cin >> k >> n;
	for(int i = 0 ; i < n ;i++) cin >> q[i].x >> q[i].y;
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < i ; j++)
			e[m++] = {i,j,get_dist(q[i],q[j])};

	sort(e,e + m);

	int cnt = n;
	double res = 0;
	for(int i = 0 ;  i < m ; i++){
		int pa = find(e[i].a);
		int pb = find(e[i].b);
		if(pa != pb){
			p[pa] = pb;
			cnt--;
			res = e[i].w;
		}
		if(cnt <= k) break;
	}
	printf("%.2lf",res);
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
