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

node *Return_top_node(node *head, node *last)
{
    int max = 0;
    node *MaxNode = NULL;
    node *tem = head;
    node *tem_pre = last;

    while (tem != NULL)
    {
        if  (tem->count > max)
        {
            max = tem->count;
            MaxNode = tem;
        }
        if (tem_pre->count > max)
        {
            max = tem_pre->count;
            MaxNode = tem_pre;
        }
        tem = tem->next;
        tem_pre = tem_pre->pre;
        }

        return MaxNode;
    }

void print_top_k(node *head, node *last, int k)  //Function will print top k word which have maximum frequency
{
   cout <<"----->> Total word is = " << total_word << endl;  //Give total word in given document
    cout << "=====>> Unique word is = " << unique_word << endl;  //Give Total unique word in document

    if (k <= 0)
    {
        cout << "Enter valid number of word" << endl;
    }
    else if (unique_word < k)
    {
        cout << "unique words." << endl;

    for (int i = 1; i <= unique_word; i++)
    {
        node *p = Return_top_node(head, last);
        cout << p->s << " " << p->count << endl;

        p->count = 0;
    }
    }

    else
    {
        for (int i = 1; i <= k; i++)
        {
            node *max = Return_top_node(head, last);
            cout << max->s << " " << max->count << endl;

            max->count = 0;  //We will take max->count as zero so it will not see second time
        }
    }

node* delete_node(node* head,node* last,node* middle,node* tem){

    if(tem == head){
        node* tem1 = tem;
        head = head->next;
        head->pre = NULL;
        delete tem1;
    }else if(tem == last){
        node* tem1 = tem;
        last = last->pre;
        last->next = NULL;
        delete tem1;
    }else if(tem == middle){
        node* tem1 = tem;
        middle = middle->pre;
        middle->next = NULL;
        delete tem1;
    }else{
        node* tem1 = tem;
        tem->pre->next = tem->next;
        tem->next->pre = tem->pre;
        delete tem1;
    }

    return tem;
    
}


void delete_nodes(node *&head, node *&last)       // Function for deallocate memory
{
    node *tem = head;
    node* tem_pre = last;

    while (tem != tem_pre)              // Start loop as both node made same at middle of linkedlist Time complecity will be O(log(n))
    {

        head = head->next;           // increment to next node and for last go to previous node
        last = last->pre;

        delete tem;
        delete tem_pre;

        tem = head;
        tem_pre = last;
    }

    head = NULL;
    last = NULL;
}



int main()
{
    string filepath;
    cout << "Enter file name : ";
    getline(cin, filepath);


    ifstream file(filepath); // Attempt to open the file directly for debugging

    if (!file.is_open())
    {
        cerr << "Unable to open the file." << endl;
        return 1;
    }
    else
    {
        cout << "File opened successfully." << endl;
        file.close(); // Close the file if opened successfully
    }

    node *head = NULL;
    node *last = NULL;
    node* middle = NULL;

    makenodes(head, last,filepath);

    middle = give_middle_Node(head);

    delete_extra(head,middle,last);
    
    int k;
    cout << "Enter value of k : ";
    cin >> k;

    print_top_k(head,middle,last,k);

    delete_nodes(head, last);

    return 0;
}

    
