#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int makeMaxHeap(int *num)
{
    return 0;
}
int showNum(vector<int> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }
}
int main()
{
    int num[] = {6, 5, 2, 1, 2, 7, 8, 10};
    vector<int> numVec(num, num + 7);
    showNum(numVec);
    cout << "helloworld!" << endl;
}