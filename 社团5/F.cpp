#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	priority_queue<int , vector<int> , greater<int> > heap;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		heap.push(x);
	}

	int ans = 0;
	while(heap.size() > 1){
		int t = heap.top();
		heap.pop();
		int z = heap.top();
		heap.pop();
		ans += t + z;
		heap.push(t + z);
	}
	cout << ans << endl;
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