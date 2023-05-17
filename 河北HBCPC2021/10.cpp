#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;



void solve(){
	 string s;
	 cin >> s;
	 int index = s.find('+');
	 if(index != string::npos){
	 	string a = s.substr(0,index);
	 	string b = s.substr(index + 1);
	 	cout << stoi(a) + 20 * stoi(b)<< endl;
	 }else{
	 	cout << max(stoi(s),0) << endl;
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