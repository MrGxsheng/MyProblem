#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m,k;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(n==2)
    {
        cout<<"YES"<<endl;
        return;
    }
    while (m)
    {
        //判断每一位的数是几
        int x = m % n;

        //如果是n-1，那么我们让他进一位
        if (x >= n - 1)
        {
            m+=n;
        }
        //大于1但不为n-1的，输出no
        else if (x > 1)
        {
            cout << "NO" << endl;
            return;
        }
        //进入下一位查看情况
        m /= n;
    }
    cout << "YES" << endl;
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