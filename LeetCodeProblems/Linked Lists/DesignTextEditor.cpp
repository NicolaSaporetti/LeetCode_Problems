#include <iostream>
using namespace std;

class Node {
public:
    Node(char x) : c(x), next(nullptr), prev(nullptr) {}
    char c;
    Node* next;
    Node* prev;
    
    void insertAfter(char c) {
        Node* newnode = new Node(c);
        newnode->prev = this;
        newnode->next = this->next;
        
        if (this->next)
            this->next->prev = newnode;
        this->next = newnode;
    }
    
    void remove() {
        this->prev->next = this->next;
        
        if (this->next)
            this->next->prev = this->prev;
        this->next = this->prev = nullptr;
    }
};

class TextEditor {
public:
    TextEditor(){
        head = new Node(-1);
        cursor = head;
    }
    
    void addText(string text) {
        for(char c : text) {
            cursor->insertAfter(c);
            cursor=cursor->next;
        }
    }
    
    int deleteText(int k) {
        int count=0;
        while(k > 0 && cursor != head) {
            count++;
            Node* tempCursor = cursor->prev;
            cursor->remove();
            cursor = tempCursor;
            k--;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        // move left
        while(k>0 && cursor!=head) {
            k--;
            cursor=cursor->prev;
        }
        
        return copyLeft();
    }
    
    string cursorRight(int k) {
        while(k >0 && cursor->next) {
            k--;
            cursor=cursor->next;
        }
        
        return copyLeft();
    }
    
    string copyLeft() {
        // move left
        string result;
        int n=10;
        Node* copy = cursor;
        
        while(n && copy!=head) {
            result.insert(0, 1, copy->c);
            copy=copy->prev;
            n--;
        }

        return result;
    }
    
    Node* head;
    Node* cursor;
};