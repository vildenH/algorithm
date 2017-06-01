#include <stdio.h>

int numberof1(int n) //常规解法
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
        {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int numberof1_2(int n) //最好解法
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
int main()
{
    int n = 15;
    printf("%d\n", numberof1(n));
    printf("%d\n", numberof1_2(n));
}