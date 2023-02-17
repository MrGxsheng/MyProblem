#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];
int prime[N], cnt;
bool st[N];

void change(int p)
{
    for(int i = p;i <= m;i += p) prime[i] = true;
}
void solve()
{
    cin >> n >> m;
    set <int> st;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == 1) continue;
        prime[a[i]] = true;
        for(int j = 2;j <= sqrt(a[i]);j++) 
            if(a[i] % j == 0) {
                if(!st.count(j)) {
                    change(j);
                    st.insert(j);
                }
                if(!st.count(a[i] / j)) {
                    change(a[i] / j);
                    st.insert(j);
                }
            }
    }
    vector <int> ans;
    for(int i = 1;i <= m;i++) 
        if(!prime[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x:ans) cout << x << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	 int T;
	T = 1;
	// cin >> T;
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
