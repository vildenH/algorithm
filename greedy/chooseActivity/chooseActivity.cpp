#include <stdio.h>
#include <iostream>
using namespace std;

template <class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[]);

const int N = 11;

int main()
{
    //从下标1存储活动开始时间
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};

    int f[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    bool A[N + 1];
    cout << "各活动开始时间,结束时间为" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << "[" << i << "] : "
             << "(" << s[i] << "),(" << f[i] << ")" << endl;
    }
    GreedySelector(N, s, f, A);
    cout << "最大相容活动子集为:" << endl;
    for (int i = 1; i <= N; i++)
    {
        if (A[i])
        {
            cout << "[" << i << "] : "
                 << "(" << s[i] << "),(" << f[i] << ")" << endl;
        }
    }

    return 0;
}

template <class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[])
{
    A[1] = true;
    int j = 1; //记录最近一次加入A中的活动

    // 检查当动i是否与当前已选择的活动相容
    for (int i = 2; i <= n; i++)
    {
        if (s[i] >= f[j])
        {
            A[i] = true;
            j = i;
        }
        else
        {
            A[i] = false;
        }
    }
}