/****************************************************************
* author: Stephen Merwin
* class: CS1D
* date: 10/09/18
* function: my string using linked lists
****************************************************************/
#ifndef HEADER_MY_STR
#define HEADER_MY_STR

#include <iostream>
using namespace std;

class node{
public:
    char info;
    node* next;
    
    node(): info{0}, next{nullptr} {};
    node(char c): info{c}, next{nullptr} {};
};

class my_str{
private:
    node* head;
    void error(const char*s){cerr << "Error: " << s << endl; throw 0;}
public:
    my_str(const char *s="");//one parameter constructor constructs this object from a c-string s (s is an array of char terminated by ‘\0 ’) parameter, s, defaults to the empty string "”
    my_str(const my_str &rhs);//copy  constructor for a mystr, must make a deep copy of s for this. (you can use strdup() you wrote)
    my_str &operator= (const my_str &s);//assigns this mystr from mystr s (perform  deep assignment) remember, both this and s have been previously  constructed so they each have storage pointed to
    char& operator[] (const int index);//return a reference to the char at position  index, 0 is the first element and so on index must be in bounds
    int indexOf(char c) const;// returns the index of the first occurance of c  in this mystr indices range from 0 to length ()−1 returns−1 if the  character c is not in this  mystr
    int indexOf(const my_str &pat) const;// returns the index of the first occurrence of  pat in this mystr indices range from 0 to length ()−1 returns−1 if the  character string pat is not in this mystr. write and use strstr() to  implement this function
    bool operator==(const my_str &s) const;//true if the two mystr’s contain the same chars in same position. eg., "abc”=="abc” returns true write and use strcmp() to implement this function
    my_str operator+(const my_str&) const;//concatenates this and s to make a new mystr. eg. " abc ” + " def ” returns " abcdef ” write and use str2dup()  to implement this function, it should allocate a new array then call  strcpy() and strcat()
    my_str &operator+=(const my_str &s);//concatenates s onto end of this
    my_str reverse() const;//returns another mystr that is the reverse of this  mystr eg., s = "abc”; s.reverse() returns "cba” write str rev(char∗dest,  char∗src) like strcpy() but copies the reverse of src into dest, then use  it
    void print(ostream &out) const;//prints out this mystr to the ostream out
    void read(istream &in);//reads a word from the istream in and this mystr becomes the same as the characters in that word. use getline()
    ~my_str();//destruct a mystr, must free up buf
private:
    void deleteList(node*&);//delete linked list and its data
    node* str2list(const char*) const;//returns a node* to the head pointer of a linked list version of the cstring parameter
    int strlen(const node*) const;//returns the length of the linked list
    node* strdup(const node*) const;//returns a pointer to a new linked list that is a duplicate of the one passed as parameter
    node* str2dup(const node*, const node*) const;//returns a pointer to a new linked list that is a copy of both params concatted together
//    void strcpy(char*, const char*) const;//Copies the linked list pointed by source into the linked list head pointed by destination
    node* strstr(const node*, const node*) const;//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
    void strcat(node*, const node*) const;//Appends a copy of the source list to the destination list.
    int strcmp(const node*, const node*) const;//This function starts comparing the first character of each list. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
};
#endif
