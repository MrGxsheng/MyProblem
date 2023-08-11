#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int HA, WA;
    cin >> HA >> WA;
    
    vector<string> A(HA);
    for (int i = 0; i < HA; i++) {
        cin >> A[i];
    }
    
    int HB, WB;
    cin >> HB >> WB;
    
    vector<string> B(HB);
    for (int i = 0; i < HB; i++) {
        cin >> B[i];
    }
    
    int HX, WX;
    cin >> HX >> WX;
    
    vector<string> X(HX);
    for (int i = 0; i < HX; i++) {
        cin >> X[i];
    }
    
    for (int ia = -10; ia <= 10; ia++) {
        for (int ja = -10; ja <= 10; ja++) {
            for (int ib = -10; ib <= 10; ib++) {
                for (int jb = -10; jb <= 10; jb++) {
                    bool ok = true;
                    vector c(HX, string(WX, '.'));
                    for (int i = 0; i < HA; i++) {
                        for (int j = 0; j < WA; j++) {
                            int x = i + ia;
                            int y = j + ja;
                            if (A[i][j] == '#') {
                                if (x < 0 || x >= HX || y < 0 || y >= WX) {
                                    ok = false;
                                    continue;
                                }
                                c[x][y] = '#';
                            }
                        }
                    }
                    for (int i = 0; i < HB; i++) {
                        for (int j = 0; j < WB; j++) {
                            int x = i + ib;
                            int y = j + jb;
                            if (B[i][j] == '#') {
                                if (x < 0 || x >= HX || y < 0 || y >= WX) {
                                    ok = false;
                                    continue;
                                }
                                c[x][y] = '#';
                            }
                        }
                    }
                    if (ok && c == X) {
                        cout << "Yes\n";
                        return;
                    }
                }
            }
        }
    }
    
    cout << "No\n";
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