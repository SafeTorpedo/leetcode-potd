#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *start = NULL;
        ListNode *end = list1;

        for (int index = 0; index < b; index++)
        {
            if (index == a - 1)
            {
                start = end;
            }
            end = end->next;
        }
        start->next = list2;

        ListNode *tail = list2;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = end->next;
        end->next = NULL;

        return list1;
    }
};