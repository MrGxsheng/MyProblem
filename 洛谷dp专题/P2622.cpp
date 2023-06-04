#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void solve(){
	cin >> n >> m;
	vector a(m + 1,vector<int>(n + 1));

	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j];

	vector<bool> vis(1 << n,false);
	queue<PII> q;
	q.push({(1 << n) - 1,0});
	vis[(1 << n) - 1] = true;


    int ss;
    
    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        if(u.first == 0){
        	cout << u.second << endl;
        	return;
        }//若状态为0，则返回当前步数
        
        for(int i = 1 ; i <= m ; i++){
            ss = u.first;
            for(int j = 1 ; j <= n ; j++)//由于开关对所有灯都影响，所以每个灯都遍历
            {
                if(a[i][j] == 1 && (ss & ( 1<< j - 1)) ) ss ^= ( 1<< j - 1);
                else if(a[i][j] == -1 && !(ss & (1 << j - 1)) ) ss |= (1 << j - 1);
            }//位运算解释如上文本
            
            if(!vis[ss])//若该状态未访问，就加入队列
            {
                q.push({ss,u.second+1});
                vis[ss] = true;
            }
        }
    }

	cout << -1 << endl;
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