#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
double x,y,a,b;
void solve(){
	cin >> x >> y >> a >> b;

	double s = x * y;
	double ss = 0;
	double sa = 0;
	if(a > x && b > y){
		ss = a * b;
		cout << fixed << setprecision(9) << s / ss << endl;
		return;
	}
	if(a > x && y >= b){
		if(b <= y / 2){
		  ss = a * (y - b);
			 sa = x * (y - b);
		}else{
            ss = a * b;
			sa = x * b;
		}

		cout << fixed << setprecision(9) << sa / (s + ss - sa) << endl;
		return;
	}else if(b > y && a <= x){
		if(a <= x / 2){
            ss = (x - a) * b;
			sa = (x - a) * y;
		}else{
			ss = a * b;
			sa = a * y;
		}
        
		cout << fixed << setprecision(9) << sa / (s + ss - sa) << endl;
		return;
	}

	double ss1 = a * b;
	double ss2 = a * (y - b);
	double ss3 = (x - a) * b;
	double ss4 = (x - a) * (y - b);

	ss = max({ss1,ss2,ss3,ss4});

	cout << fixed << setprecision(9) << ss / s << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//        _                                    _  _  _         _                   
//       | |                                  (_)| || |       | |                  
//   ___ | |__    ___  _ __    __ _ __      __ _ | || |  __ _ | | __    ___  _ __  
//  / __|| '_ \  / _ \| '_ \  / _` |\ \ /\ / /| || || | / _` || |/ /   / __|| '_ \ 
//  \__ \| | | ||  __/| | | || (_| | \ V  V / | || || || (_| ||   <  _| (__ | | | |
//  |___/|_| |_| \___||_| |_| \__, |  \_/\_/  |_||_||_| \__,_||_|\_\(_)\___||_| |_|
//                             __/ |                                               
//                            |___/                                             
