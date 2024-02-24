/**************************************************
* author: Stephen Merwin
**************************************************/
#include "my_str.h"

void my_str::deleteList(node* &del){//O(N)
    node* current = del;
    while(current){
        node* next = current->next;
        delete current;
        current = next;
    }
    del = nullptr;
}
node*  my_str::str2list(const char* str) const{//O(N)
    node* h = nullptr;
    node* temp = nullptr;
    for(int i = 0; str[i] != 0; ++i){
        if(!h){
            temp = new node(str[i]);
            h = temp;
        }else{
        temp->next = new node(str[i]);
        temp = temp->next;
        }
    }
    return h;
}
int my_str::strlen(const node* head) const{//O(N)
    node* temp = (node*) head;
    int i;
    for(i = 0; temp; ++i)
        temp = temp->next;
    return i;
}
node* my_str::strdup(const node *ptr1) const{//O(N)
    node* destination = nullptr;
    node* ptr2 = nullptr;
    while(ptr1){
        if(!destination){
            ptr2 = new node(ptr1->info);
            destination = ptr2;
        }else{
            ptr2->next = new node(ptr1->info);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return destination;
}
node* my_str::str2dup(const node *ptr1, const node *ptr2) const{//O(N)
    node* ptr3 = strdup(ptr1);
    strcat(ptr3, ptr2);
    return ptr3;
}
node* my_str::strstr(const node* mainstr, const node* substr) const{//O(N^2)
    node* str = (node*) mainstr;//make a non const pointer to const node* mainstr
    while(str){
        node* beg = str;
        node* pat = (node*) substr;
        while(str && pat && str->info == pat->info){//if matches first char of substr, check rest
            str = str->next;
            pat = pat->next;
        }
        if(!pat)//all of the pattern has been checked
            return beg;
        str = beg->next;//increment thru str
    }
    return nullptr;
}
void my_str::strcat(node* destination, const node* source) const{//O(N)
    if(!destination)
        destination = strdup(source);
    while(destination->next != nullptr)//iterate thru to end of destination
        destination = destination->next;
    destination->next = strdup(source);
}
int my_str::strcmp(const node* n1, const node* n2) const{//O(N)
    int ret = 0;
    while (n2 && n1 && !(ret = n1->info - n2->info)){
        n1 = n1->next;
        n2 = n2->next;
    }
    return ret;
}

my_str::my_str(const char *s){//O(N)
    head = str2list(s);
}
my_str::my_str(const my_str &rhs){//O(N){
    head = strdup(rhs.head);
}
my_str& my_str::operator=(const my_str &rhs){//O(N)
    if(this == &rhs)
        return *this;
    deleteList(head);
    head = strdup(rhs.head);
    return *this;
}
char& my_str::operator[] (const int index){//O(N)
    if (strlen(head) <= index || index < 0)
        error("out of bounds!");
    char* c = nullptr;
    node* temp = head;
    for(int i = 0; i <= index; ++i){
        c = &temp->info;
        temp = temp->next;
    }
    return *c;
}
int my_str::indexOf(char c) const{//O(N)
    node* temp = head;
    for(int i = 0; temp != nullptr; ++i){
        if(temp->info == c)
            return i;
        temp = temp->next;
    }
    return -1;//not found will return -1
}
int my_str::indexOf(const my_str &pat) const{//O(N^2)
    node* target = strstr(head, pat.head);
    if(target == nullptr)
        return -1;
    node* temp = head;
    int i;
    for(i = 0; temp != target; ++i)//iterate thru array until target is found
        temp = temp->next;
    return i;
}
bool my_str::operator==(const my_str &rhs) const{//O(N)
    return (strcmp(head, rhs.head) == 0);
}
my_str & my_str::operator+=(const my_str &rhs){//O(N)
    strcat(head, rhs.head);
    return *this;
}
my_str my_str::operator+(const my_str &rhs) const{//O(N)
    my_str lhs = *this;
    lhs += rhs;
    return lhs;
}
my_str my_str::reverse() const{//O(N)
    node* root = strdup(head);
    node* revd = nullptr;
    while(root){
        node* nextn = root->next;
        root->next = revd;
        revd = root;
        root = nextn;
    }
    my_str rev;
    rev.head = revd;
    return rev;
}
void my_str::print(ostream& out) const{//O(N)
    node* temp = head;
    while(temp){
        out << temp->info;
        temp = temp->next;
    }
}
void my_str::read(istream& in){//O(N)
    deleteList(head);
    char strtemp[999];
    in.getline(strtemp, 999, '\n');
    head = str2list(strtemp);
}
my_str::~my_str(){//O(N)
    deleteList(head);
}
