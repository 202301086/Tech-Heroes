
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

