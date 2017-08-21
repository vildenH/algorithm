#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory.h>
using namespace std;
int nums[100]; //数组内值表示皇后在i行放置的位置
int n = 4;
int ans = 0;
void print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j == nums[i])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isConflict(int val) //true 有冲突 false无冲突
{
    for (int i = 0; i < val; i++)
    {
        if (nums[i] == nums[val] || (abs(nums[val] - nums[i]) == abs(val - i)))
        {
            return true;
        }
    }
    return false;
}

int eightQueen(int row)
{

    if (row == n)
    {
        print();
        ans++;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        nums[row] = i;
        if ((isConflict(row)==false))
        {
            eightQueen(row + 1);
        }
    }
}

int main()
{
    memset(nums, 0, sizeof(nums));
    eightQueen(0);
    cout << "ans= " << ans << endl;
}