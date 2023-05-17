#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int a,b,c;
    cin >> a >> b >> c;
    bool st = false;
    for(int i = 0 ; i <= 1000 ; i++)
        for(int j = 0 ; j <= 1000 ; j++)
            if(!st && a * i + b * j == c){
                cout << "Yes" << endl;
                st = true;
                break;
            }
    if(!st)
        cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}