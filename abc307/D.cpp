#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    vector<string> s{""};
    vector<char> p;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            p.push_back('(');
            s.push_back("");
        } else if (S[i] == ')') {
            if (!p.empty() && p.back() == '(') {
                p.pop_back();
                s.pop_back();
            } else {
                p.push_back(')');
                s.push_back("");
            }
        } else {
            s.back() += S[i];
        }
    }
    
    auto t = s[0];
    for (int i = 0; i < p.size(); i++) {
        t += p[i];
        t += s[i + 1];
    }
    cout << t << "\n";
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