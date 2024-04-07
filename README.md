# Tech-Heroes
DSA Project Assignment
## P4 Question
### Word Cloud Generator
You need to build a Word Cloud Generator. The generator takes in a dynamic collection of documents (i.e., new documents keep coming in) and creates a word cloud based on the frequency of unique words in the document. The generator starts with an initial collection of N documents. You can control the generator to only the top k most frequently used words. You should also be able to stop the generator from selecting a pre-defined set of words W. 
## Features
- Reads words from a text file.
- Calculates word frequencies.
- Prints the first k words based on their frequency.
- Finds the frequency of a specific word.
- Searches for words with a certain frequency.
- User-friendly menu interface for interaction. 
## PSEUDO CODE
1 . begin()<br/>
2 . include all file which we need<br/>
3 . make arr of extra word<br/>
4 . Make a vector which contain a Sort linked list<br/>
4 . Make a class of node which contain linked list<br/>
5 . Make a vector which contain a Sort linked list<br/>
6 . lower string function which make string lower so we can find Same string easily When string is mixed in capital-small letters.<br/>
7 . Make node function take a string and make it lower .<br/>
8 . then we search string in linked list if it excits then we increse count of that string or not excits then make new node.<br/>
9 . compare_nodes function give maximum of given 2 node which we use in <br/>
10. Print_top_k function first check k is 0 or negative is or not if yes than give Message <br/>
11. if not 0 or negative than print top m word where m is minimum of {m,unique_words} <br/>
12. search_frequency function search a word of given frqquency that user give is it was negative then give message else travell from linklist then give frequency<br/>
13. search_word function this will check first if this frequency is exicts in linked lisr or not if yes than traevell and print words or if not than give message<br/>
14.Delete_all function will delete all linkedlist as free all memory after use of program.<br/>
15.Main function first they take file name check it is exicts or not is not then give message and if yes than go to other part.<br/>
16.Then read all word and store in linked list after this add in vector and vector sort them.<br/>
17.give menu of operations and take input from User that He/She which operation want to do.<br/>
18.From user input operation will do and user want to exit then give 4 or 0 then program will complete with thank you message.<br/>
19.Over().<br/>


## Input
When prompted, enter the name of the text file containing the words.
##  Group Members Name and ID
  - Ritul Jitendrakumar Patel (202301086)<br />
  - Om Sutariya (202301096)<br />
  - Smit Mukeshbhai Limbasiya (202301139)<br />
  - Raj Sureshbhai Bhanderi (202301058)<br />

## CONTRIBUTION 

  Smit Limbasiya : Algorithm , Idea Of Extra functions And implement search_word() , search_freq Function , Design In Output With iomanip header file , Linkedlist <br/>
  Ritul Patel :  Algorithm , Print top k word function and it's all condition, Compare node function , Sorting vector , Make condition in main function  <br/>
  Raj bhanderi : Unordered Set's all part and use of them functions , make node function  <br/>
  Om sutariya : File handling , Define class and global variable , string lower function  <br/>
