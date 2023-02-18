#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
map<int,int> mp;
vector<int> alls(200010); //***** 存储所有待离散化的值
// 二分求出对应的离散化的值 
int find(int x) //找到第一个>=x的位置 
{
    int l=0,r=alls.size()-1;
    while(l<r) 
    {
        int mid = l+r>>1;
		if(alls[mid]>=x) r=mid;
		else l=mid+1;
    } 
    return r+1; //映射到 1~n,不 +1的话就是 0~n 
}

void solve(){
	cin >> n >> m;
	vector<int> a(n + 1);

	vector<int> aa[n + 1];
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		alls[i] = a[i];
		mp[a[i]] ++;
	}

	
	sort( alls.begin(),alls.end() ); //将所有的值排序
	alls.erase( unique( alls.begin(),alls.end()),alls.end()); //去掉重复元素

	
	for(int i = 1 ; i <= n ; i++)
		aa[find(a[i])].push_back(i);
	
	while(m--){
		int x,y;
		cin >> x >> y;
		if(y > mp[x]) cout << -1 << endl;
		else cout << aa[find(x)][y - 1] << endl;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
