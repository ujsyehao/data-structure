#include <iostream>

// node definition
struct Node {
  int data;
  Node *next; 
}; 

// linked list definition -- ye
/* class LinkedList {
  public:
    LinkedList(Node *head) {
       
    };
    Insert();
    Remove();
  private:
    int length;

}; */

// linked list definition -- blog
class List {
  private:
    Node *head, *tail;
  public:
    List() {
      head = NULL;
      tail = NULL;
    }
    void CreateNode(int value) {
      // check empty -> head pointer is equal to NULL
      // create both head and tail node
      Node *temp = new Node;
      temp -> data = value;
      temp -> next = NULL;
      if (head == NULL) {
        head = temp; 
        tail = temp;
        temp = NULL;
      }
      // a linked list is created already, insert this node at the end of 
      // the linked list including 2 steps
      else {
        tail -> next = temp;
        tail = temp;
      }
    }
    void display() {
      Node * temp = head;
      if (temp == NULL) {
        std::cout << "empty linked list" << std::endl; 
      }
      while (temp) {
        std::cout << temp -> data << " "; 
        temp = temp -> next; 
      }      
      std::cout << std::endl;
    }
    void insert(int value, int position) {
      // insert at the start including 2 steps
      Node *temp = new Node;
      temp -> data = value;
      temp -> next = NULL;
      if (position == 1) {
        temp -> next = head;
        head = temp;
      }
      // insert at the end 
      else if (position == -1) {
        tail -> next = temp;
        tail = temp;
      }
      // insert at a particular position including 2 steps
      // search from the head node and loop search
      else {
        Node *pre = new Node;
        Node *cur = new Node;
        cur = head;
        for (int i =1; i < position; i++) {
          pre = cur;
          cur = cur -> next;
          //std::cout << "check value: " << cur -> data << std::endl;
        } 
        pre -> next = temp;
        temp -> next = cur;
      }
    }
    void deletion(int position) {
      // deletion at the start including 3 steps 
      if (position == 1) {
        Node *temp = new Node;
        temp = head;
        head = head -> next;
        delete temp;
      } 
      // deletion at the end 
      else if (position == -1) {
        Node *pre = new Node;
        Node *cur = new Node;
        cur = head;
        while (cur -> next) {
          pre = cur;
          cur = cur -> next;
        }
        pre -> next = NULL;
        tail = pre;
        delete cur;
      }
      // deletion at a particular position
      else {
        Node *pre = new Node;
        Node *cur = new Node;
        cur = head;
        for (int i = 1; i < position; i++) {
          pre = cur;
          cur = cur -> next;
        }
        pre -> next = cur -> next;
        delete cur;
      }
    }
};

int main() {
  List a;
  a.CreateNode(3);
  a.CreateNode(4);
  a.CreateNode(5);
  a.CreateNode(6);
  a.display();
  a.insert(8, 3);
  a.display();
  a.deletion(1);
  a.display();
  a.deletion(2);
  a.display();
  a.deletion(1);
  a.deletion(-1);
  a.display();
  a.deletion(1);
  a.display();
  return 0;
}
