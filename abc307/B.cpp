#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                auto S = s[i] + s[j];
                if (S == string(S.rbegin(), S.rend())) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
	cout << "No" << endl;
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