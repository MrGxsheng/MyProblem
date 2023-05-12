#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int depth[N];
int fa[N];
int sonum[N];
void solve(){
	cin >> n >> m;

	int minn = 0 , k = 0 , d = 1, sum = 0;

	while(sum + d <= n){
		minn += k * d;
		sum += d;
		d *= 2;
		++k;
	}

	minn += (n - sum) * k;
	int maxn = n * (n - 1) / 2;
	if(m < minn || m > maxn){
		cout << "No" << endl;
		return;
	}

	cout << "YES" << endl;

	depth[1] = 0;
	for(int i = 2 ; i <= n ; i++){
		fa[i] = i - 1;
		sonum[i - 1]  = 1;
		depth[i] = depth[fa[i]] + 1;
	}
	sonum[n] = 0;
	int num = maxn - m;
	priority_queue<PII> q;

	q.push({depth[n],n});

	while(num)
	{
		int u=q.top().second;
		q.pop();
		int maxnn=-5007,maxd;
		for(int i=1;i<=n;++i)
		{
			if(sonum[i]>1)
			continue;
			int c=depth[u]-depth[i]-1;
			if(c>maxnn&&c<=num)
			{
				maxnn=c;
				maxd=i;
			}
		}
		num-=maxnn;
		--sonum[fa[u]];
		if(!sonum[fa[u]])
		q.push(make_pair(depth[fa[u]],fa[u]));
		fa[u]=maxd;
		depth[u]=depth[fa[u]]+1;
		++sonum[fa[u]];
		q.push(make_pair(depth[u],u));
	}

	for(int i = 2 ; i <= n ; i++) cout << fa[i] << ' ';
	cout << endl;
	

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}