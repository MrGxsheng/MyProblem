#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,c;
struct node
{
    int a,b,w;
    bool operator<(const node &t)const
    {
        return w<t.w;
    }
}e[N];

int fa[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)return ;
    fa[x]=y;
}
bool check(int mid)
{
    for(int i=1;i<=n;i++)fa[i]=i;
    vector<int> v;
    for(int i=1;i<=m;i++)
    {
        if(e[i].w<=mid)
        {
            merge(e[i].a,e[i].b);
        }
        else
        {
            int a=e[i].a,b=e[i].b,w=e[i].w;
            if(find(a)!=find(b))
            {
                v.push_back(w);
                merge(a,b);
            }
        }
    }
    int sum=0;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i]*(i+1);
    }
    return sum<=c;
}
void solve(){
	cin >> n >> m >> c;
	for(int i = 1 ; i <= m ; i++){
        int a,b,w;
        a--,b--;
        cin >> a >> b >> w;
        e[i] = {a,b,w};
    }

    sort(e + 1 ,e + 1 + m);
    int l = 0 , r = 1e18;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}