/**
 * next_permutation 求全排列
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int a[5];
char opt[5]= {' ','+','-','*','/'};

int F(int x,int k,int y){
	if(k == 1) return x + y;
	if(k == 2) return max(x,y) - min(x,y);
	if(k == 3) return x * y;
	return (y==0 || x<y || x%y!=0) ? -999999 : x/y; // 非法状态
}

void Out(int a ,int b ,int c ,int d ,int e ,int f ,int k1 ,int k2 ,int k3){
	printf("%d%c%d=%d\n",max(a,b),opt[k1],min(a,b),F(max(a,b),k1,min(a,b)));
	printf("%d%c%d=%d\n",max(c,d),opt[k2],min(c,d),F(max(c,d),k2,min(c,d)));
  	printf("%d%c%d=%d\n",max(e,f),opt[k3],min(e,f),F(max(e,f),k3,min(e,f)));
  	exit(0); //直接退出程序
}

void solve(){
	scanf("%d%d%d%d", &a[1],&a[2],&a[3],&a[4]);
	sort(a + 1 , a + 5);
	do{
		for(int i = 1 ; i <= 4 ; i ++)
			for(int j = 1 ; j <= 4 ; j++)
				for(int k = 1 ; k <= 4 ; k++)
					if(F(F(F(a[1],i,a[2]),j,a[3]),k,a[4])==24) //((a?b)?c)?d
						Out(a[1],a[2],F(a[1],i,a[2]),a[3],F(F(a[1],i,a[2]),j,a[3]),a[4],i,j,k);
					else if (F(F(a[1],i,a[2]),k,F(a[3],j,a[4])) == 24)//(a?b)?(c?d)
						Out(a[1],a[2],a[3],a[4],F(a[1],i,a[2]),F(a[3],j,a[4]),i,j,k);
	}while(next_permutation(a + 1 , a + 5)); //枚举所有的全排列
	puts("No answer!");
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
