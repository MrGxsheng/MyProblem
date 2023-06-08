#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	vector<string> s(10);
	for(int i = 0 ; i < 10 ; i++) cin >> s[i];

	int minx = 11 , maxx = -1;
	int miny = 11 , maxy = -1;
	for(int i = 0 ; i < 10 ; i++)
		for(int j = 0 ; j < 10 ; j++)
			if(s[i][j] == '#'){
				minx = min(minx,i + 1);
				maxx = max(maxx,i + 1);
				miny = min(miny,j + 1);
				maxy = max(maxy,j + 1);
			}
	cout << minx << ' ' << maxx << endl;
	cout << miny << ' ' << maxy << endl;
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