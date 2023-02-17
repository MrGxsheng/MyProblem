/**
 * floyd 传递闭包
 * 及优化
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1010;
int n,m;
bool d[N][N];
bool st[N];

void Floyd(){
	for(int k = 0  ; k < n ; k++)
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				d[i][j] |= d[i][k] && d[k][j]; //i 连接k , k 连接 j 那么 i 可以连接 j

}

//获得最小的字符
char get_min(){
	//枚举最小的字符
	for(int i = 0 ; i < n ; i++){
		if(!st[i]){//如果该字符已经输出过则跳过
			bool flag = true;//判断是否有比 i字符更小的
			for(int j = 0 ; j < n ; j++) 
				if(!st[j] && d[j][i]){ //首先要保证比较的字符没有输出过 并且 j是小于i的
					flag = false;
					break;
				}
			if(flag){ //说明i是目前最小的 返回标记即可
				st[i] = true;
				return 'A' + i;
			}
		}
	}
}

//判断目前的排序 是否满足题意
int check(){
	//判断矛盾 当自己小于自己时 即为矛盾
	for(int i = 0 ; i < n ; i++)		
		if(d[i][i]) return 2;

	//判断当前排序是否包括所有元素
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < i ; j++)
			//如果 i 和 j 没有任何关系的话 即没有排序完
			if(!d[i][j] && !d[j][i]) return 0;
	//表示当前排序 已经能够将所有元素 有序的排好
	return 1;
}

//每次加a，b边的时候 只需要在添加 和a ,b有关的边
//不用每次都跑Floyd
//优化 复杂度 n^2
void solve(){
	cin >> n >> m;
	int type = 0 , t = 0;
	for(int i = 1 ; i <= m ; i++){
		char str[5];
		cin >> str;
		int a = str[0] - 'A' , b = str[2] - 'A';
		if(!type){
			d[a][b] = 1; //将a 和 b 连一条边
			//枚举连接a的左边 和 右边 
			//顺序： x a ...  b y
			for(int x = 0 ; x < n ; x ++){
				if(d[x][a]) d[x][b] = 1; //如果x 连接a 那么 x也可以连接b
				for(int y = 0 ; y < n ; y++){
					if(d[b][y]) d[a][y] = 1; //同上
					if(d[x][a] && d[b][y]) d[x][y] = 1; 
				}
				type = check(); // 判断当前排序的类型
				if(type) t = i; //记录最小值
			}
		}
	}

	if (!type) puts("Sorted sequence cannot be determined.");
    else if (type == 2) printf("Inconsistency found after %d relations.\n", t);
    else
    {
        printf("Sorted sequence determined after %d relations: ", t);
        for (int i = 0; i < n; i ++ ) printf("%c", get_min());
        printf(".\n");
    }
}

//Floyd 做 传递闭包 复杂度 n^3
void solve1(){
	cin >> n >> m;
	int type = 0 , t = 0;
	for(int i = 1 ; i <= m ; i++){
		char str[5];
		cin >> str;
		int a = str[0] - 'A' , b = str[2] - 'A';
		if(!type){
			d[a][b] = 1;
			Floyd(); // 添加边
			type = check();
			if(type) t = i;
			}
		}
	}

	if (!type) puts("Sorted sequence cannot be determined.");
    else if (type == 2) printf("Inconsistency found after %d relations.\n", t);
    else
    {
        printf("Sorted sequence determined after %d relations: ", t);
        for (int i = 0; i < n; i ++ ) printf("%c", get_min());
        printf(".\n");
    }
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
