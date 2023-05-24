#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++) cin >> s[i];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			for(auto dx : {-1,0,1})
				for(auto dy : {-1,0,1}){
					if(dx || dy){
						bool ok = true;
						for(int k = 0 ; k < 5 ; k++){
							int x = i + dx * k;
							int y = j + dy * k;
							if (!(0 <= x && x < n && 0 <= y && y < m && s[x][y] == "snuke"[k])) {
                                ok = false;
                            }
						}
                        if (ok) {
                            for (int k = 0; k < 5; k++) {
                                int x = i + dx * k;
                                int y = j + dy * k;
                                cout << x + 1 << " " << y + 1 << endl;
                            }
                            return;
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