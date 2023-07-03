#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int n1,m1,n2,m2;
	cin >> n1 >> m1;
	vector a(n1,vector<int>(m1));
	for(int i = 0 ; i < n1 ; i++)
		for(int j = 0 ; j < m1 ; j++)
			cin >> a[i][j];

	cin >> n2 >> m2;
	vector b(n2,vector<int>(m2));
	for(int i = 0 ; i < n2 ; i++)
		for(int j = 0 ; j < m2 ; j++)
			cin >> b[i][j];

	for(int s = 0 ; s < (1 << n1) ; s++)
		for(int t = 0 ; t < (1 << m1 ) ; t++)
			if(__builtin_popcount(s) == n2 && __builtin_popcount(t) == m2){
				vector<int> x,y;
				for(int i = 0 ; i < n1 ; i++)
					if(s >> i & 1)
						x.push_back(i);
				for(int i = 0 ; i < m1 ; i++)
					if(t >> i & 1)
						y.push_back(i);

				if([&]() {
					for(int i = 0 ; i < n2 ; i++)
						for(int j = 0 ; j < m2 ; j++)
							if(a[x[i]][y[j]] != b[i][j])
								return false;
					return true;
				}()){
					cout << "Yes" << endl;
					return;
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