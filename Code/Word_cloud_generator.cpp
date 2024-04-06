#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int total_word = 0;
int unique_word = 0;
int extra_word = 0;

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

node *searchnode(node *head, node *last, string s)
{
    node *tem = head;
    node *tem_pre = last;

    while (tem != tem_pre)
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


void makenodes(node *&head, node *&last, const string &filename)
{   
    head = new node;
    head->s = "";
    head->count = 0;
    head->next = NULL;
    head->pre = NULL;
    last = head;

    ifstream file(filename);
    if (!file.is_open())                // if file was node than give error
    {
        cerr << "Unable to open the file." << endl;
        return ;
    }

    int i = 0;
    string tem ;
    while (file>>tem)
    {
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

            if(tem.size() == 0 || check_extra(tem) == true){
                extra_word++;
            }
        }
        else
        {
            p->count++;             
        }
        tem = "";
        i++;
    }
       file.close();  
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

void print_top_k(node *head,node* middle, node *last, int k)      // Function will print top k word which have maximum frequnecy
{ 
    cout<<endl<<endl;
    cout <<"||"<< setw(35) << setfill('=') << "||" << endl;   
    
    cout << "||" << setw(25) << setfill(' ') << left<< " Total Readed Word -->  " << setw(8) << setfill(' ') << left<< total_word << setw(4) << setfill(' ') << left<< "||" << endl;
    cout << "||" << setw(25) << setfill(' ') << left<< " Total Unique word --> " << setw(8) << setfill(' ') << left<< unique_word << setw(4) << setfill(' ') << left<< "||" << endl;
    cout << "||" << setw(25) << setfill(' ') << left<< " Unique Extra word --> " << setw(8) << setfill(' ') << left<< extra_word  << setw(4) << setfill(' ') << left<< "||" << endl;
    
    cout <<"|"<< setw(34) << setfill('=') << "|" <<"||"<< endl<<endl<<endl;

    if (k <= 0)           
    {
        cout << "Enter valid number of word" << endl;
    }
    else if (unique_word < k)
    {     
        cout<<" NOTE : Sorry we have only " << unique_word << " unique words.   " << endl;
        cout<<endl;

        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        cout <<"|"<< left << setw(20) << " Word" << setw(10) << "Frequency" <<" |"<< endl;
        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        
        for (int i = 1; i <= unique_word; i++)
        {
            node *max = Return_top_node(head,middle, last);

            cout <<"| "<< left << setw(20) <<max->s<< setw(10) <<max->count<<"|"<< endl;
            max->count = 0;
        }
         cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;

    }
    else
    {
        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        cout <<"|"<< left << setw(20) << " Word" << setw(10) << "Frequency" <<" |"<< endl;
        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        for (int i = 1; i <= k; i++)
        {
            node *max = Return_top_node(head,middle,last);
            cout <<"| "<< left << setw(20) <<max->s<< setw(10) <<max->count<<"|"<< endl;
            
            max->count = 0;                              // we will take max->count as zero so it will not see second time
        }
        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
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

void delete_extra (node* &head, node* middle, node* &last)
{
    node* tem = head;
    node* middle1 = middle;
    node/ middle2 = middle;
    node* tem_pre = last;

    while((tem != middle) && (tem_pre != middle2))
    {
    // Check if the next node's string size is 1 or if it's in the predefined array
        if(tem->next && (tem->next->s.size() == 1 || check_extra(tem->next->s)))
        {
            tem = delete_node(head, last, middle, tem->next);  // Delete the node and move tem to the next node
        }
        else
        {
            tem = tem->next; // Move to the next node
        }

        // Similar checks and deletion for previous node of tem_pre
        if(tem_pre->pre && (tem_pre->pre->s.size() == 1 || ckecks_extra(tem_pre->pre>s)))
        {
            tem_pre = delete_node(head, last, middle, tem_pre->pre);
        }
        else
        {
            tem_pre = tem_pre->pre;
        }

        // Similar checks and deletion for middle1 and middle2
        if(middle1->pre && (middle1->pre->s.size() == 1 || check_extra(middle1->pre->s)))
        {
            middle1 = delete_node(head, last, middle, middle1->pre);
        }
        else
        {
            middle1 = middle1->pre;
        }

        if(middle2->pre && (middle2->pre->s.size() == 1 || check_extra(middle2->pre->s)))
        {
            middle2 = delete_node(head, last, middle, middle2->pre);
        }
        else
        {
            middle2 = middle2->pre;
        }
    }
}
       

void delete_all(node *&head, node *&last)      
{
    node *tem = head;
    node* tem_pre = last;
    while (tem != tem_pre)              
    {
        head = head->next;           
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
    delete_all(head, last);

    return 0;
}

    
