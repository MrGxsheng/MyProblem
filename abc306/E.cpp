#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k;
void solve(){
	cin >> n >> k >> m;

	multiset<int> S,T;
	vector<int> A(n);

	for(int i = 0 ; i < n ; i++){
		if(i < k){
			S.insert(0);
		}else{
			T.insert(0);
		}
	}
	LL ans = 0;

	while (m--) {
        int X, Y;
        cin >> X >> Y;
        X--;
        if (S.find(A[X]) != S.end()) {
            S.extract(A[X]);
            ans -= A[X];
        } else {
            T.extract(A[X]);
        }
        A[X] = Y;
        S.insert(A[X]);
        ans += A[X];
        while (S.size() > k) {
            int x = *S.begin();
            T.insert(S.extract(x));
    

            ans -= x;
        }
        while (!S.empty() && !T.empty() && *S.begin() < *T.rbegin()) {
            int x = *S.begin();
            int y = *T.rbegin();
            ans += y - x;
            T.insert(S.extract(x));
            S.insert(T.extract(y));
        }
        cout << ans << "\n";
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