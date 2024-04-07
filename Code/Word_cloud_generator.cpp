
#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip>           // for desing use in printing top k word
#include <algorithm>     // for use of sort 
#include <vector>
#include <unordered_set>  // for make searching operation easily
using namespace std;


int total_words = 0;
int unique_words = 0;
int extra_words = 0;

unordered_set<string> arrs = {"a", "able", "about", "above", "across", "after", "all", "almost", "also",
                                    "am", "among", "an", "and", "any", "are", "as", "at", "be", "because",
                                    "been", "but", "by", "can", "cannot", "could", "dear", "did", "do",
                                    "does", "either", "else", "ever", "every", "for", "from", "get", "got",
                                    "had", "has", "have", "he", "her", "hers", "him", "his", "how", "however",
                                    "i", "if", "in", "into", "is", "it", "its", "just", "least", "let", "like",
                                    "likely", "may", "me", "might", "most", "must", "my", "neither", "no",
                                    "nor", "not", "of", "off", "often", "on", "only", "or", "other", "our",
                                    "own", "rather", "said", "say", "says", "she", "should", "since", "so",
                                    "some", "than", "that", "the", "their", "them", "then", "there", "these",
                                    "they", "this", "tis", "to", "too", "twas", "us", "wants", "was", "we",
                                    "were", "what", "when", "where", "which", "while", "who", "whom", "why",
                                    "will", "with", "would", "yet", "you", "your", "yours", "yourself", "yourselves"};

class node         // make a class of node so we can make linked list
{
    public:

    string s;
    int count;
    node *next;
    node *pre;

    node(string s){
        this->s = s;
        this->count = 1;
        this->next = NULL;
        this->pre = NULL;
    }

};

node *head = NULL;        // make head ,last pointer global so we can use them in function easily
node *last = NULL;


string lower_string(string s)        // Function for make string lower so we can search node easily
{
    string s1;

    for (int i = 0; i < s.size(); i++)
    {
        s1 += tolower(s[i]);
    }
    return s1;
}

void make_nodes(const string &s)
{
    total_words++;

    if(s.size() == 1 || arrs.find(s) != arrs.end()){
        extra_words++;
        return;
    }

    if (head == NULL)           // if first node 
    {
        head = new node(s);
        last = head;
        unique_words++;
        return;
    }

    node *tem = head;       
    while (tem != NULL)     // check if this string's node is exist or not
    {
        if (tem->s == s)
        {
            tem->count++;      // if exist increase the count
            return;
        }
        tem = tem->next;
    }

    node *n = new node(s);     // else make a new node
    last->next = n;
    n->pre = last;
    last = n;
    unique_words++;
}

bool compareNodes(const node *a, const node *b) {
    return a->count > b->count;
}


void print_top_k_words(int k)       // Function for print top k word
{
   cout<<endl<<endl;
   cout <<"||"<< setw(35) << setfill('=') << "||" << endl;      // make design to print total, unique and extra words

    // Output the lines with variable values
    cout << "||" << setw(25) << setfill(' ') << left<< " Total Readed s -->  " << setw(8) << setfill(' ') << left<< total_words << setw(4) << setfill(' ') << left<< "||" << endl;
    cout << "||" << setw(25) << setfill(' ') << left<< " Total Unique s --> " << setw(8) << setfill(' ') << left<< unique_words << setw(4) << setfill(' ') << left<< "||" << endl;
    cout << "||" << setw(25) << setfill(' ') << left<< " Unique Extra s --> " << setw(8) << setfill(' ') << left<< extra_words << setw(4) << setfill(' ') << left<< "||" << endl;
    
    cout <<"|" << setw(34) << setfill('=') << "|" <<"||"<< endl<<endl<<endl;

    if(k <= 0){
        cout<<"Enter valid number ..."<<endl;    // if user enter k as negative then print error
        return;
    }


    vector<node *> sorted_nodes;    // make a vector which contain linked list 
    node *tem = head;

    while (tem != NULL)
    {
        sorted_nodes.push_back(tem);    // add linkedlist's element in vector
        tem = tem->next;
    }

    sort(sorted_nodes.begin(), sorted_nodes.end(),compareNodes);   // sort linked list
    
    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
    cout <<"|"<< left << setw(20) << "Words" << setw(10) << "Frequency" <<" |"<< endl;  
    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        

    for (int i = 0; i < min(k, unique_words); i++)
    {
        cout <<"| "<< left << setw(20) << sorted_nodes[i]->s << setw(10) << sorted_nodes[i]->count <<"|"<< endl;  // print top k
    }

    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
}


void search_frequency(string s1){

    s1 = lower_string(s1);       // make given string lower

    int f = 0;
    node *tem = head;
    node* tem1 = last;

    while(tem != tem1){          // Travell from both side to find word fast
        if(tem->s == s1){
            f = 1;              // if find that given frequency is exicts then return else f will be 0
            break; 
        }

        if(tem1->s == s1){
            f = 2;
            break;
        }

        tem = tem->next;
        tem1 = tem1->pre; 
    }
 

    if(f == 0){                  // if frequrncy not found
            cout<<"|----------------|"<<endl;
            cout<<"| Word not found |"<<endl;
            cout<<"|----------------|"<<endl;
    }else if(f == 1){                          // if find from head's side
            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
            cout <<"|"<< left << setw(20) << "Words" << setw(10) << "Frequency" <<" |"<< endl;  
            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        
            cout <<"| "<< left << setw(20) << tem->s << setw(10) << tem->count <<"|"<< endl;  

            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
    }else if(f == 2){                  // if find from last's side
            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
            cout <<"|"<< left << setw(20) << "Words" << setw(10) << "Frequency" <<" |"<< endl;  
            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        
            cout <<"| "<< left << setw(20) << tem1->s << setw(10) << tem1->count <<"|"<< endl;  

            cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
    }

}


void search_word(int f){       // this function search word in linked list and print its frequency

    if(f <= 0){
        cout<<"|--------------------------------|"<<endl;
        cout<<"| Given frequency is in valid... |"<<endl;
        cout<<"|--------------------------------|"<<endl;
        return;
    }

    int check = 0;
    node *tem = head;
    node* tem_pre = last;

    while(tem != tem_pre){            // it take O(n/2) time complexity

        if(tem->count == f){
            check = 1;
            break;
        }

        if(tem_pre->count == f){
            check = 1;
            break;       
        }

        tem = tem->next;
        tem_pre = tem_pre->pre;
    }

    if(check == 0){                  // if word not found then give message
        cout<<"Word not found"<<endl;
    }else{                          // else print word and it's frequnecy

        node *tem = head;
        node* tem_pre = last;

        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        cout <<"|"<< left << setw(20) << "Words" << setw(10) << "Frequency" <<" |"<< endl;  
        cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;

    while(tem != tem_pre){

        if(tem->count == f){
            cout <<"| "<< left << setw(20) << tem->s << setw(10) << tem->count <<"|"<< endl;           
        }

        if(tem_pre->count == f){
            cout <<"| "<< left << setw(20) << tem_pre->s << setw(10) << tem_pre->count <<"|"<< endl;
        }

        tem = tem->next;
        tem_pre = tem_pre->pre;
    }  

    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl <<endl;

    }

}

void delete_All()      // delete all nodes from linked list
{
    node *tem = head;
    while (tem != NULL)
    {
        node *tem1 = tem;
        tem = tem->next;
        delete tem1;
    }
}



int main()
{
    string filename;               
    cout << "Enter file name :- ";      // take input as file's name
    cin>>filename;

    ifstream file(filename);        // open file in reading mode
    if (!file.is_open())           // if not file open then print error message
    {
        cerr << "Unable to open the file." << endl;
        return 1;
    }else{                         // if file open successfully then print message
        cout<<"File opened successfully"<<endl;
    }

    string s;
    while (file >> s)
    {
        s = lower_string(s);
        make_nodes(s);            // take each string from file and store in linked list
    }

    file.close();                // close file when linke list created
    
    //delete_extra_words()       // delete extra word from linked list


    cout<<endl<<endl;


    cout << "|============================================|" << endl;
    cout << "| PRESS |     MENU                           |" << endl;
    cout << "|-------|------------------------------------|" << endl;
    cout << "|  1    | Print top k word                   |" << endl;
    cout << "|  2    | Search word's frequency            |" << endl;
    cout << "|  3    | Search specific frequency's word   |" << endl;
    cout << "|  4/0  | Exit                               |" << endl;
    cout << "|============================================|" << endl << endl;


    while(1){

    int tem;
    cout<<" Enter your choice : ";
    cin>>tem;

    if(tem == 1){
          int k;
          cout<<" Enter value of k: ";
          cin>>k;

          print_top_k_words(k);        // print top k word

    }else if(tem == 2){
          string find_word;
          cout<<" Enter word: ";
          cin>>find_word;

          search_frequency(find_word);   // search word's frequency

    }else if(tem == 3){
          int freq;
          cout<<" Enter frequency: ";
          cin>>freq;

          search_word(freq);        // search specific frequency's words

    }else if(tem == 4 || tem == 0){
        cout<<"|------------------------------------|"<<endl;
        cout<<"| THANK YOU FOR USING THIS PROGRAM...|"<<endl;
        cout<<"|------------------------------------|"<<endl;
        break;

    }else{
        cout<<" Enter valid number ..."<<endl;
    }

    }

    delete_All();               // free all memory

    return 0;
}
