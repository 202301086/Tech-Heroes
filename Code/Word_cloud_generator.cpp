
void delete_extra_words()            // function delete extra word with use of delete_node function
{
    node *tem = head;
    while (tem != NULL)
    {
        if (tem->s.size() == 1 || arrs.find(tem->s) != arrs.end())
        {
            node *tem1 = tem;
            tem = tem->next;
            delete_node(tem1);
            extra_words++;
        }
        else
        {
            tem = tem->next;
        }
    }
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
