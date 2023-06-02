#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
char g[250][250];
char c[250][250];
char z[250][250];
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) cin >> g[i];
    c[0][0] = '.';
    int k = 1;

    while(m--){
        for(int i = 0 ; i < k ; i++)
            for(int j = 0 ; j < k ; j++){
                for(int a = 0 ; a < n ; a++)
                    for(int b = 0 ; b < n ; b++){
                        char v = '*';
                        if(c[i][j] == '.') v = g[a][b];
                        z[i * n + a][j * n + b] = v;
                    }

            }
        memcpy(c,z,sizeof c);
        k *= n;
    }

    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < k ; j++){
            cout << c[i][j];

        }
        cout << endl;
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