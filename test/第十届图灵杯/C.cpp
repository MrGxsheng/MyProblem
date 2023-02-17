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
/**定义一个点类*/
struct Point
{
    float x;
    float y;
    Point(){};
    Point(float x,float y):x(x),y(y){};
};

/**求取三角形面积*/
float GetTriangleArea(const Point &A,const Point &B,const Point &C)
{
    Point AB,BC;
    float Area;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;//分别求取向量AB的，xy坐标
    BC.x = C.x - B.x;
    BC.y = C.y - B.y;//分别求取向量BC的，xy坐标
    Area = abs((AB.x * BC.y) - (AB.y * BC.x)) / 2.0f; //由AB、BC向量根据公式求得三角形面积
    return Area;
}

/**判断点P是否在三角形内部*/
bool IsInTriangle(const Point &A,const Point &B,const Point &C,const Point &P)
{
    float SABC,SABP,SACP,SBCP;
    SABC = GetTriangleArea(A,B,C);//求三角形ABC的面积
    SABP = GetTriangleArea(A,B,P);
    SACP = GetTriangleArea(A,C,P);
    SBCP = GetTriangleArea(B,C,P);//求取点P分别与三个点所形成的面积
    if(SABC == SABP + SACP + SBCP)
        return true;
    else
        return false;
}

void solve(){
	Point A,B,C,P;
	A.x = A.y = 0;
	cin >> B.x, B.y = 0;
	cin >> C.x >> C.y;
	cin >> P.x >> P.y;
	if(GetTriangleArea(A,B,C) == 0)	cout << "no\n";
	else if(GetTriangleArea(A,B,P) == 0 ||GetTriangleArea(A,C,P) == 0||GetTriangleArea(B,C,P) == 0)	cout << "no\n";
	else if(IsInTriangle(A,B,C,P))	cout << "yes\n";
	else	cout << "no\n";
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

