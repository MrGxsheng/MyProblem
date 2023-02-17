/**
 * A*算法
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, string> PIS;
const int N = 1000010;
int n,m;
string star;
string en;

//求曼哈顿距离
int f(string state)
{
    int res = 0;
    for (int i = 0; i < 9; i ++ )
        if (state[i] != 'x')
        {
            int v = state[i] - '1';
            res += abs(v / 3 - i / 3) + abs(v % 3 - i % 3);
        }

    return res;
}


int bfs(){
	int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
	unordered_map<string,int> dist;
	unordered_map<string,bool> st;
	priority_queue<PIS, vector<PIS>, greater<PIS>> heap;


	heap.push({f(star),star});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		string state = t.y;
		if(st[state]) continue;
		st[state] = true;

		int step = dist[state];
		int x,y;
		for(int i = 0 ; i < state.size() ; i++){
			if(state[i] == '0'){
				x = i / 3;
				y = i % 3;
				break;
			}
		}
		for(int i = 0 ; i < 4 ; i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
			swap(state[x * 3 + y],state[a * 3 + b]);
			if(!dist.count(state) || dist[state] > step + 1){
				dist[state] = step + 1;
				heap.push({dist[state] + f(state) , state});
			}
			swap(state[x * 3 + y],state[a * 3 + b]);
		}
	}
	return dist[en];
}

void solve(){
	cin >> star;
	en = "123804765";
	cout << bfs() << endl;
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
