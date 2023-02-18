#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

void solve(){
	cin >> n;
	vector<int> a(n),b(n),v;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
	}

	cin >> m;
	vector<array<int,3>> qry(m);
	for(int i = 0 ; i < m ; i++){
		int o;
		cin >> o;
		if(o == 1){
			int x,y;
			cin >> x >> y;
			x--;
			v.push_back(y);
			qry[i] = {o,x,y};
		}else if(o == 2){
			int x,y;
			cin >> x >> y;
			x--;
			qry[i] = {o,x,y};
		}else{
			int x,y;
			cin >> x;
			qry[i] = {o,x};
		}
	}


	sort(v.begin(), v.end(), greater());
	int M = v.size();

	Fenwick<int> fc(M);
	Fenwick<LL> fs(M);

	for(int i = 0 ; i < n ; i++){
		a[i] = lower_bound(v.begin(), v.end(),a[i],greater()) - v.begin();
		fc.add(a[i],b[i]);
		fs.add(a[i],1ll * v[a[i]] * b[i]);
	}

	for(auto [o,x,y] : qry){
		if(o == 1){
			y = lower_bound(v.begin(), v.end(),y,greater()) - v.begin();
			fc.add(a[x],-b[x]);
			fs.add(a[x],-1ll * v[a[x]] * b[x]);
			a[x] = y;
			fc.add(a[x],b[x]);
			fs.add(a[x],1ll * v[a[x]] * b[x]);
		}else if(o == 2){
			fc.add(a[x],-b[x]);
			fs.add(a[x],-1ll * v[a[x]] * b[x]);
			b[x] = y;
			fc.add(a[x],b[x]);
			fs.add(a[x],1ll * v[a[x]] * b[x]);
		}else{
			int j = fc.kth(x);
			int c = fc.sum(j);

			if(c < x && j == M){
				cout << -1 << endl;
			}else{
				LL ans = fs.sum(j);
				if(c < x) ans += 1ll * (x - c) * v[j];
				cout << ans << endl;
			}
		}
	}
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

//        _                                    _  _  _         _                   
//       | |                                  (_)| || |       | |                  
//   ___ | |__    ___  _ __    __ _ __      __ _ | || |  __ _ | | __    ___  _ __  
//  / __|| '_ \  / _ \| '_ \  / _` |\ \ /\ / /| || || | / _` || |/ /   / __|| '_ \ 
//  \__ \| | | ||  __/| | | || (_| | \ V  V / | || || || (_| ||   <  _| (__ | | | |
//  |___/|_| |_| \___||_| |_| \__, |  \_/\_/  |_||_||_| \__,_||_|\_\(_)\___||_| |_|
//                             __/ |                                               
//                            |___/                                             
