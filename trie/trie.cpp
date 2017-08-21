#include <iostream>  
#include <cstdio>  
using namespace std;  
  
const int maxn = 256;//  
typedef struct TrieNode  
{  
    int cp;  
    TrieNode *next[maxn];  
}TrieNode;  
TrieNode *root;  
TrieNode *p;  
int cnt;  
void trie_init()  
{  
    int i;  
    root = new TrieNode;  
    for(i=0; i<maxn; i++)  
        root->next[i] = NULL;  
    root->cp = -1;  
}  
void trie_insert(char *word)  
{  
    p = root;  
    int i;  
    while(*word != '\0')  
    {  
        if(p->next[*word] == NULL)// 直接以 *word 字符对应的ASCII作为next数组的指针  
        {  
            TrieNode *cur = new TrieNode;  
            for(i=0; i<maxn; i++)  
                cur->next[i] = NULL;  
                cur->cp = 0;  
            p->next[*word] = cur;  
        }  
        p = p->next[*word];  
        word ++;  
    }  
    p->cp ++;  
}  
void trie_travel(TrieNode *cur)  
{  
    static char worddump[31];  
    static int pos;// 静态变量：静态局部变量存在全局数据区，他直到函数结束也不会消失 ，  
    //每次重新调用声明静态变量的函数时，也不会为其重新分配空间，它始终保留在全局数据区，直到程序运行结束  
    int i;  
    if(cur->cp !=0)  
    {  
        cout << "**";  
        worddump[pos] = '\0';  
        if(worddump[0])// 排除root的干扰，当然，要是不要这一句判断的话，要cur->cp > 0;  
            printf("%s %0.4f\n", worddump, ((float)cur->cp*100)/(float)cnt);  
    }  
    for(i=0; i<maxn; i++)  
    {  
        if(cur->next[i] != NULL)  
        {  
            worddump[pos] = i;  
            pos++;// 加一 为下一准备  
            trie_travel(cur->next[i]);  
            pos--;// 输出一个单词，回退一个  
        }  
    }  
}  
  
int main()  
{  
    char s[31];  
    cnt = 0;  
    trie_init();  
    while(gets(s))  
    {  
        trie_insert(s);  
        cnt ++;  
        if(cnt==29) break;  
    }  
    trie_travel(root);  
    return 0;  
}  