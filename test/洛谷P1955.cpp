/*
	离散化+并查集
*/
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,top;

struct node
{
	int x,y,e;
	bool operator< (const node &w ) const{
		return e > w.e;
	}
}a[N];

int p[N],b[N];
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
void solve(){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	top = 0;
	cin >> n;
	for(int i = 1 ; i <= N ; i++) p[i] = i;

	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i].x >> a[i].y >> a[i].e;
		b[++top] = a[i].x;
		b[++top] = a[i].y;
	}

	sort(b , b + 1 + top);

	//algorithm中的函数，把数组去重，然后返回末尾指针。这里减一个b就可以表示b现在的大小了
	int tott = unique(b + 1 ,b + 1 + top) - b;
	for(int i = 1; i <= n ; i++){
		a[i].x = lower_bound(b + 1 , b + 1 + tott , a[i].x) - b;
		a[i].y = lower_bound(b + 1 , b + 1 + tott , a[i].y) - b;
	}

	sort(a + 1 , a + 1 + n);
	bool st = true;

	for(int i = 1 ; i <= n ; i++){
		if(a[i].e == 1 ){
			int pa = find(a[i].x);
			int pb = find(a[i].y);
			p[pa] = pb;
		}else{
			int pa = find(a[i].x);
			int pb = find(a[i].y);
			if(pa == pb){
				st = false;
				break;
			}
		}
	}

	if(st) puts("YES");
	else puts("NO");
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

