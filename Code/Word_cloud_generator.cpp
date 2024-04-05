#include <bits/stdc++.h>
using namespace std;

int total_word = 0;
int unique_word = 0;

const int n = 136;
const string arr[n] = {"a", "able", "about", "above", "across", "after", "all", "almost", "also", 
    "am", "among", "an", "and", "any", "are", "as", "at", "be", "because", 
    "been", "but", "by", "can", "cannot", "could", "dear", "did", "do", 
    "does", "either", "else", "ever", "every", "for", "from", "get", "got", 
    "had", "has", "have", "he", "her", "hers", "him", "his", "how", "however", 
    "i", "if", "in", "into", "is", "it", "its", "just", "least", "let", "like", 
    "likely", "may", "me", "might", "most", "must", "my", "neither", "no", 
    "nor", "not", "of", "off", "often", "on", "only", "or", "other", "our", 
    "own" , "rather", "said", "say", "says", "she", "should", "since", "so", 
    "some", "than", "that", "the", "their", "them", "then", "there", "these", 
    "they", "this", "tis", "to", "too", "twas", "us", "wants", "was", "we", 
    "were", "what", "when", "where", "which", "while", "who", "whom", "why", 
    "will", "with", "would", "yet", "you", "your", "yours", "yourself", "yourselves"};

class node
{
public:
    string s;
    int count;
    node *next;
    node *pre;
};


bool check_extra(string s){

    bool check = false;

    for(int i=0;i<=n/2;i++){
        
        if(arr[i] == s){
            check = true;
            break;
        }

        if(arr[n-i-1] == s){
            check = true;
            break;
        }

    }

    return check;

}

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


node* give_middle_Node(node* head){

    node* tem = head;
    node* tem2 = head;

    while(tem2 != NULL && tem2->next != NULL){
        tem = tem->next;
        tem2 = tem2->next->next;
   }
    return tem;
}



node *Return_top_node(node *head,node* middle, node *last)       // give max node which have maximum count
{

    int max = 0;
    node *maxNode = NULL;

    node *tem = head;
    node* tem2_pre = middle;

    node *tem_pre = last;
    node* tem2 = middle;
    

    while(tem != tem2_pre && tem2 != tem_pre){

        if(tem->count > max){

            max = tem->count;
            maxNode = tem;
        }

        if(tem2_pre->count > max){

            max = tem2_pre->count;
            maxNode = tem2_pre;

        }

        tem = tem->next;
        tem2_pre = tem2_pre->pre;

        if(tem2->count > max){

            max = tem2->count;
            maxNode = tem2;
        }

        if(tem_pre->count > max){

            max = tem_pre->count;
            maxNode = tem_pre;
        }

        tem2 = tem2->next;
        tem_pre = tem_pre->pre;
    }
    

    return maxNode;

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

    
