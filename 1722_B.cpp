#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	string s,s1;
	cin >> n >> s >> s1;
	int len = s.length();
	int len1 = s1.length();

	if(len != len1) {
		puts("No");
		return;
	}

	for(int i = 0 ; i < len ; i++){
		if(s[i] == 'R')
			if(s1[i] != 'R'){
				puts("NO");
				return;
			}
		if(s1[i] == 'R')
			if(s[i] != 'R'){
				puts("NO");
				return;
			}
	}
		
	

	puts("YES");

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
