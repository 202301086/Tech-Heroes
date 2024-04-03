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


void makenodes(node *&head, node *&last, string &s)
{
    head = new node;
    head->s = "";
    head->count = 0;
    head->next = NULL;
    head->pre = NULL;
    last = head;

    int i = 0;
    string tem = "";
    while (i < s.size())
    {
        while (isspace(s[i]))
        { 
            i++;
        }
       
        while (!isspace(s[i]) && i < s.size())
        {
            tem += s[i];
            i++;
        }
      
        if (isspace(s[i]) && isspace(s[i - 1]) && !isspace(s[i + 1]))     
        {
            break;
        }

        tem = lower_string(tem);    

        total_word++;
        
        node *p = searchnode(head, last, tem);   // If node not found, create new node and append to end of linked list
        if (p == NULL)
        {
            node *k = new node;
            k->s = tem;
            k->count = 1;
            k->next = NULL;
            k->pre = last;
            last->next = k;
            last = k;
            unique_word++;
        }
        else
        {
            p->count++;                          // If found, increment the count
        }
        tem = "";
        i++;
    }
}


void delete_space_string(node *&head, node *&last)     //   This function will delete node which contain space or new line character
{
    node *tem = head;
    node *tem_pre = last;

    while (tem != tem_pre)      // loop will run As both will point at same node at middle of linkedlist Time complecity will be O(log(n))
    {
        if (tem->next != NULL && isspace(tem->next->s[0]))   // check first character of string is space or \n if it then delete this node
        { 
            node *space_node = tem->next;

            if (tem->next == last)                        
            {
                last = tem;
                tem->next = NULL;
            }
            else
            {
                node *p = tem->next->next;
                tem->next = p;
                p->pre = tem;
            }

            delete space_node;   
            space_node = NULL;
        }

        if (tem_pre->pre != NULL && isspace(tem_pre->pre->s[0]))    // same as above but start from last check from previous node
        {
            node *space_node = tem_pre->pre;

            if (tem_pre->pre == head)
            {
                head = tem_pre->next;
                head->pre = NULL;
            }
            else
            {
                node *p = tem_pre->pre->pre;
                tem_pre->pre = p;
                p->next = tem_pre;
            }

            delete space_node;
            space_node = NULL;

        }

        tem = tem->next;
        tem_pre = tem_pre->pre;
    }
}
    
