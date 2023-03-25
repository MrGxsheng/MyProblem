#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200010;

int n,k,a,b,q;
int c1[N],c2[N];
int d[N];

int lowbit (int x) {
    return x & -x;
}
void modify (int c[],int x,int d) {
    for (int i = x;i <= n;i += lowbit (i)) c[i] += d;
}
int query (int c[],int x) {
    int ans = 0;
    for (int i = x;i;i -= lowbit (i)) ans += c[i];
    return ans;
}


int main()
{
    cin >> n >> k >> a >> b >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x,y;
            cin >> x >> y;
            if (d[x] < a) {
                if (d[x] + y >= a) modify (c1,x,a - d[x]);
                else modify (c1,x,y);
            }
            if (d[x] < b) {
                if (d[x] + y >= b) modify (c2,x,b - d[x]);
                else modify (c2,x,y);
            }
            d[x] += y;
        }
        else {
            int p;
            cin >> p;
            cout << query (c2,p - 1) + query (c1,n) - query (c1,p + k - 1) << endl;
        }
    }
    return 0;

}