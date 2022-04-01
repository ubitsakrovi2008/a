#include <iostream>
#include<vector>


using namespace std;

// Ленивый обход
vector<int> v(31);
int fib(int n)
{
    if (v[n] == -1)
        v[n] = fib(n - 1) + fib(n - 2);
    return v[n];
}

int main()
{
    v.assign(31, -1);
    v[0] = 0;
    v[1] = 1;
    cout << fib(30) << endl;

    // Восходящее ДП (быстрее, но не всегда понятно, какие элементы понадобятся в будущем):
    // Прямой обход 
    vector<int> dp(31, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 30; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[30] << endl;
     // Можно запомниать не всё:
    int a = 0, b = 1, c;
    for (int i = 2; i <= 30; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << b << endl;

    // Обратный обход
    vector<int> dp2(31, 0);
    dp2[0] = 0;
    dp2[1] = 1;
    for (int i = 1; i < 30; i++)
    {
        dp2[i + 1] += dp2[i];
        if (i < 29)
            dp2[i + 2] += dp2[i];
    }
    cout << dp2[30] << endl;
}
