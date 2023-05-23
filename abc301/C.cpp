#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string S, T;
    cin >> S >> T;
	map<char, int> cs, ct;
    for (auto c : S) {
        cs[c]++;
    }
    for (auto c : T) {
        ct[c]++;
    }
    
    string a = "atcoder";
    int extra = 0;
    for (int c = 'a'; c <= 'z'; c++) {
        if (cs[c] != ct[c]) {
            if (a.find(c) == -1) {
                cout << "No\n";
                return;
            }
            if (cs[c] < ct[c]) {
                extra += ct[c] - cs[c];
            }
        }
    }
    if (extra <= cs['@']) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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