#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> min_lex_partition(int n) {
    vector<int> partition;
    int i = 1;
    while (n > 0) {
        if (n - i > i) {
            partition.push_back(i);
            n -= i;
            i += 1;
        } else {
            partition.push_back(n);
            break;
        }
    }
    return partition;
}

void solve(){
    int n;
    cin >> n;
    vector<int> result = min_lex_partition(n);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}