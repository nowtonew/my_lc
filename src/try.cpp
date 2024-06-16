#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *cur = dummyHead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    cur = dummyHead->next;
    delete dummyHead;
    return cur;
}

ListNode *cut(ListNode *head, int n)
{
    ListNode *cur = head;
    while (cur && --n)
    {
        cur = cur->next;
    }
    if (!cur)
        return nullptr;
    ListNode *nxt = cur->next;
    cur->next = nullptr;
    return nxt;
}

ListNode *sortList(ListNode *head)
{
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *pre;
    ListNode *cur = head;
    int len = 0;
    while (cur)
    {
        ++len;
        cur = cur->next;
    }
    for (int i = 1; i < len; i *= 2)
    {
        cur = dummyHead->next;
        pre = dummyHead;
        while (cur)
        {
            ListNode *left = cur;
            ListNode *right = cut(left, i);
            cur = cut(right, i);
            pre->next = merge(left, right);
            while (pre->next)
            {
                pre = pre->next;
            }
        }
    }
    cur = dummyHead->next;
    delete dummyHead;
    return cur;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    int n;
    while (cin >> n)
    {
        ListNode *node = new ListNode(n);
        cur->next = node;
        cur = cur->next;
        if (getchar() == '\n')
            break;
    }
    ListNode *ans = sortList(head->next);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
