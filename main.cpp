#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* next;
};

class hashT{
public:
    Node** arr;
    hashT(int size=10){arr=new Node*[size];}
    void insert(int a);
    void display();
    int del(int a);
};

int hashT::del(int a){
    int index = a%10;
    Node*p = arr[index];
    Node*ptr = arr[index];
    while(ptr->key!=a){
        if(ptr==nullptr)
            break;
        ptr=ptr->next;
    }
    while(p!=ptr && p->next!=ptr){
        p=p->next;
    }
    if(ptr==nullptr){
        cout << "This number is not in the hashtable" << endl;
        return -1;
    }
    else if(ptr->next == nullptr){
        int temp = ptr->key;
        free(ptr);
        p->next=NULL;
        return temp;
    }
    else{
        p = ptr->next;
        int temp = ptr->key;
        free(ptr);
        return temp;
    }
}

void hashT::insert(int a) {
    Node*p = new Node;
    p->key = a;
    int index = a%10;
    if(arr[index] == nullptr) {
        arr[index] = p;
        p->next=nullptr;
    }
    else{
        Node*ptr;
        ptr = arr[index];
        while(ptr->next!=nullptr){
            ptr = ptr->next;
        }
        ptr->next = p;
    }
}

void hashT::display() {
    Node*ptr = nullptr;
    for(int i=0;i<10;i++){
        ptr=arr[i];
        while(ptr!=nullptr){
            cout << ptr->key << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main() {
    hashT hash;

    hash.insert(1);
    hash.insert(2);
    hash.insert(33);
    hash.insert(104);
    hash.insert(25);
    hash.insert(0);
    hash.insert(11);
    hash.insert(16);
    hash.insert(67);
    hash.insert(83);
    hash.insert(88);
    hash.insert(219);
    hash.insert(1251);
    hash.insert(245);
    hash.del(11);
    hash.display();
    return 0;
}