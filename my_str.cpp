/**************************************************
* author: Stephen Merwin
**************************************************/
#include "my_str.h"

void my_str::swap(char &c1, char &c2) const{
    if(c1 != c2){
    char temp = c1;
    c1 = c2;
    c2 = temp;
    }
}
int my_str::strlen(const char* str) const{//O(N)
    char *s;//iterator
    for (s = (char*) str; *s; ++s)//iterate thru array until null terminator
        ;
    return (s - str);
   /* int i;
    for(i = 0; str[i] != 0; ++i)
        ;
    return i;*/
}
char* my_str::strdup(const char *ptr1) const{//O(N)
    char* ptr2 = new char[strlen(ptr1) + 1];//+1 to include space for null terminator
    strcpy(ptr2,ptr1);
    return ptr2;
}
char* my_str::str2dup(const char *ptr1, const char *ptr2) const{//O(N)
    char* ptr3 = new char[strlen(ptr1) + strlen(ptr2) + 1];
    strcpy(ptr3, ptr1);
    strcat(ptr3, ptr2);
    return ptr3;
}
void my_str::strcpy(char* destination, const char* source) const{//O(N)
    while((*destination++ = *source++))//iterate thru array and copy buf
        ;
}
char* my_str::strstr(const char* mainstr, const char* substr) const{//O(N^2)
    char* str = (char*) mainstr;//make a non const pointer to const char* mainstr
    while(*str){
        char* beg = str;
        char* pat = (char*) substr;
        while(*str && *pat && *str == *pat){//if matches first char of substr, check rest
            ++str;
            ++pat;
        }
        if(!*pat)//all of the pattern has been checked
            return beg;
        str = beg + 1;//increment thru str
    }
    return NULL;
}
void my_str::strcat(char* destination, const char* source) const{//O(N)
    int i = strlen(destination);
    for(int j = 0; source[j] != 0; ++j)
        destination[i++] = source[j];
    destination[i] = 0;
}
int my_str::strcmp(const char* str1, const char* str2) const{//O(N)
    int ret = 0;
    while (!(ret = *(char *) str1 - *(char *) str2) && *str2)
        ++str1, ++str2;
    return ret;
}

my_str::my_str(const char *s){//O(N)
    buf = strdup(s);
}
my_str::my_str(const my_str &rhs){//O(N){
    buf = strdup(rhs.buf);
}
my_str& my_str::operator=(const my_str &rhs){//O(N)
    if(this == &rhs)
        return *this;
    if(buf != NULL)
        delete[] buf;
    buf = strdup(rhs.buf);
    return *this;
}
char& my_str::operator[] (const int index){//O(1)
    if (strlen(buf) <= index || index < 0)
        error("out of bounds!");
    return buf[index];
}
int my_str::indexOf(char c) const{//O(N)
    for(int i = 0; buf[i] != 0; ++i)
        if(buf[i] == c)
            return i;
    return -1;//not found will return -1
}
int my_str::indexOf(const my_str &pat) const{//O(N^2)
    char* target = strstr(buf, pat.buf);
    if(target == NULL)
        return -1;
    char* temp = buf;
    int i;
    for(i = 0; temp != target; ++i)//iterate thru array until target is found
        ++temp;
    return i;
}
bool my_str::operator==(const my_str &s) const{//O(N)
    return (strcmp(buf, s.buf) == 0);
}
my_str & my_str::operator+=(const my_str &rhs){//O(N)
    char* temp = str2dup(buf, rhs.buf);
    delete[] buf;
    buf = temp;
    return *this;
}
my_str my_str::operator+(const my_str &rhs) const{//O(N)
    my_str lhs = *this;
    lhs += rhs;
    return lhs;
}
my_str my_str::reverse() const{//O(N)
    int n = strlen(buf);
    my_str rev = *this;
    for(int i = 0; i < n / 2; ++i)
        swap(rev.buf[i], rev.buf[n - i - 1]);
    return rev;
}
void my_str::print(ostream& out) const{//O(N)
    int n = strlen(buf);
    for(int i = 0; i < n; ++i)
        out << buf[i];
}
void my_str::read(istream& in){//O(N)
    if(buf != NULL)
        delete[] buf;
    buf = new char[999];
    in.getline(buf, 999, '\n');
}
my_str::~my_str(){//O(N)
    delete[] buf;
}
