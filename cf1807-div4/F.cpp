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
int n,m;
int t;
int solve(int n,int m,int sx,int sy,int tx,int ty,string s)
{
	int dx,dy;
	if(s[0]=='D')dx=1;
	else dx=-1;
	if(s[1]=='R')dy=1;
	else dy=-1;
	int res=0;
	while(1){
		if(sx==tx&&sy==ty)return res;
		int f=0;
		if(sx+dx>n||sx+dx<1)dx=-dx,f++,res++;
		if(sy+dy>m||sy+dy<1)dy=-dy,f++,res++;
		res-=(f==2);
		sx+=dx,sy+=dy;
		if(res>n*m+5)return -1;
	}
}
int main()
{
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
    	int n,m,sx,sy,tx,ty;
    	string s;
    	cin>>n>>m>>sx>>sy>>tx>>ty>>s;
    	int res=solve(n,m,sx,sy,tx,ty,s);
    	cout<<res<<endl;
	}
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
