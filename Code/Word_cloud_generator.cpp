#include <bits/stdc++.h>
using namespace std;

int total_word = 0;
int unique_word = 0;

class node
{
public:
    string s;
    int count;
    node *next;
    node *pre;
};

// Function to search for a node with a specific string value within a doubly linked list.
// It starts searching from both ends (head and last) simultaneously, moving towards the middle of the list.
node *searchnode(node *head, node *last, string s)
{
    node *tem = head;
    node *tem_pre = last;

    while (tem != NULL)
    {
        if (tem->s == s)
        {
            return tem;
        }

        if (tem_pre->s == s)
        {
            return tem_pre;
        }

        tem = tem->next;
        tem_pre = tem_pre->pre;
    }
    return NULL;
}
