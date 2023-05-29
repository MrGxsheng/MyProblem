#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,H,K;
void solve(){
	cin >> n >> m >> H >> K;
	string S;
	cin >> S;

	set<pair<int, int>> s;
	int x = 0 , y = 0;
	for(int i = 0 ; i < m ; i++){
		 int x,y;
		 cin >> x >> y;
		 s.emplace(x, y);
	}

	for(auto c : S){
		if (c == 'L') {
            x--;
        } else if (c == 'R') {
            x++;
        } else if (c == 'D') {
            y--;
        } else {
            y++;
        }
        H--;
        if (H < 0) {
            cout << "No" << endl;
            return;
        }
        if (H < K && s.count({x, y})) {
            s.erase({x, y});
            H = K;
        }
    }
    cout << "Yes" << endl;;


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