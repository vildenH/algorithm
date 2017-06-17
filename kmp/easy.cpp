#include <stdio.h >
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    char t[100000];
    char p[100000];
    scanf("%s%s", p, t);
    cout << "p: " << p << endl;
    cout << "t: " << t << endl;
    int tlen = strlen(t);
    int plen = strlen(p);
    cout << "plen: " << plen << endl;
    cout << "tlen: " << tlen << endl;
    int index = -1;

    for (int i = 0; i < plen; i++)
    {
        int count = 0;
      
        for (int j = 0; j < tlen; j++)
        {
            if (p[i + j] == t[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == tlen)
        {
              index = i;
            break;
        }
    }
    if (index != -1)
    {
        cout << "position: " << index++<< endl;
    }
    else
    {
        cout << "no matches!" << endl;
    }
}