
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
void delete_node(node *node)       // Function for delete specific node we use for delete extra word's node
{
    if (node == NULL){      
        return;
    }

    if (node == head)
    {
        head = head->next;
        if (head != NULL){
            head->pre = NULL;
        }
    }
    else
    {
        node->pre->next = node->next;          // delete node from linked list

        if (node != last){
            node->next->pre = node->pre;
        }else{
            last = node->pre;
        }

    }
    delete node;
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

    sort(sorted_nodes.begin(), sorted_nodes.end(), [](node *a, node *b) { return a->count > b->count; });   // sort linked list
    
    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
    cout <<"|"<< left << setw(20) << " s" << setw(10) << "Frequency" <<" |"<< endl;  
    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
        

    for (int i = 0; i < min(k, unique_words); i++)
    {
        cout <<"| "<< left << setw(20) << sorted_nodes[i]->s << setw(10) << sorted_nodes[i]->count <<"|"<< endl;  // print top k
    }

    cout <<"|"<< setfill('-') << setw(31) << "" << setfill(' ') <<"|"<< endl;
}
