#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define INF 1e9
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
const int N = 200010;
int n,m,k;

int low,high;

bool check(int mid,vector<int> a,vector<int> b){
	bool found = false;
	for (int i = 0; i < n - 1; i++) {
	    int cnt = 0;
	    if (a[i] < mid) 
	      cnt += 1;

	    if (a[i + 1] < mid) 
	      cnt += 1;
	    

	    int val = (mid + 1) / 2;
	    cnt += (int) (lower_bound(b.begin(), b.end(), val) - b.begin());
	    if (a[i] < val) 
	      cnt -= 1;
	    
	    if (a[i + 1] < val) 
	      cnt -= 1;
	    
	    if (cnt <= k) {
	      found = true;
	      break;
	    }
  	}
  return found;
}

void solve(){
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
      cin >> a[i];
    
    
	vector<int> b = a;
    sort(b.begin(), b.end());

    low = 0, high = (int) 1e9;

    while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (check(mid,a,b)) low = mid;
      else  high = mid - 1;
    }
    cout << low << '\n';
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
