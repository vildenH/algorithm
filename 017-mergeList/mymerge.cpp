#include <iostream>
using namespace std;
struct ListNode
{
  public:
    int val;
    struct ListNode *next;
    //	ListNode(int x)
    //	:val(x), next(NULL)
    //    {
    //	}
};
ListNode *Merge(ListNode *pLeft, ListNode *pRight)
{

    ListNode *head = NULL;
    ListNode *left = pLeft;
    ListNode *right = pRight;
    if (left == NULL)
    {
        head = right;
        return head;
    }
    if (right == NULL)
    {
        head = left;
        return head;
    }
    if (left->val < right->val)
    {

        head = left;
        left = left->next;
        head->next = NULL;
    }
    else
    {
        head = right;
        right = right->next;
        head->next = NULL;
    }

    ListNode *cur = head;

    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {

            cur->next = left;
            left = left->next;
            cur = cur->next;
            cur->next = NULL;
        }
        else
        {
            cur->next = right;
            right = right->next;
            cur = cur->next;
            cur->next = NULL;
        }
    }
    if (left != NULL)
    {
        cur->next = left;
    }
    else
    {
        cur->next = right;
    }
    return head;
}
int main()
{
    ListNode left, right[3];

    left.val = 5;
    left.next = NULL;

    right[0].val = 1;
    right[0].next = &right[1];
    right[1].val = 2;
    right[1].next = &right[2];
    right[2].val = 4;
    right[2].next = NULL;

    ListNode *head = Merge(&left, right);
    while (head != NULL)
    {
        cout << head->val;
        head = head->next;
    }

    return 0;
}
