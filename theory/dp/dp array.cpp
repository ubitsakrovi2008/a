#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Для  заданной  последовательности  чисел  A[1..N]  найти   длину  M максимальной
// подпоследовательности  элементов со  строго возрастающими значениями в порядке
// возрастания индексов.
// 5 6 3 4 7 2 8

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Без доп. памяти
    int cnt = 1, mx = 1;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1])
        {
            cnt++;
            mx = max(mx, cnt);
        }
        else
            cnt = 1;
    cout << mx << endl;

    // С доп. памятью (так зачастую удобнее и понятнее)
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            dp[i] = dp[i - 1] + 1;
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
