#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &a[i]);
        // 除去 2, 3 的质因子
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }

    for (int i = 1; i < n; i ++ )
        if (a[i] != a[i - 1])
        {
            puts("No");
            return 0;
        }
    puts("Yes");

    return 0;
}

