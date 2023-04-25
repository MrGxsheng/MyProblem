#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> n >> s;
	if(n % 2 == 1){
        cout << -1 << "\n";
        return;
    }
    vector<int> d(26, 0);
    int sum = 0;
    int ma = -1, mt = -1;
    for(int i = 0; i < n/2; i++){
        if(s[i] == s[n - i - 1]){
            d[s[i]-'a']++;
            sum++;
            if(d[s[i] - 'a'] > ma){
                ma = d[s[i]-'a'];
                mt = s[i] - 'a';
            }
        }
    }
    int mleft = 0;
    for(int j = 0; j < 26; j++){
        if(d[j] != ma) continue;
        int left = 0;
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-i-1] && s[i]-'a' != mt && s[n-i-1]-'a' != mt){
                left++;
            }
        }
        mleft = max(mleft, left);
    }
    
    // cout << ma << " ... " << (sum - ma + left) << "\n";
    if(ma > (sum - ma + mleft)){
        cout << -1 << "\n";
    }else if(ma <= (sum - ma)){
        cout << (sum+1)/2 << "\n";
    }else{
        cout << ma << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}