#include <iostream>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
  private:
    Node *head, *tail;
  public:
    LinkedList() {
      head = NULL;
      tail = NULL;
    }
    void CreateNode(int value) {
      Node *tmp = new Node;
      tmp -> data = value;
      tmp -> next = NULL;
      if (head == NULL) {
        //std::cout << "!!!!" << std::endl;
        head = tmp;
        tail = tmp;
        //std::cout << head -> data << std::endl;
        tmp = NULL;
      } else {
        tail -> next = tmp;
        tail = tmp;
        tmp = NULL;
      }
    }
    void display() {
      Node *tmp;
      tmp = head;
      if (!tmp) {
        std::cout << "empty linked list"; 
      }
      while (tmp) {
        std::cout << tmp -> data << " ";
        tmp = tmp -> next;
      }
      std::cout << std::endl;
    }
    void insertion(int value, int position) {
      Node *tmp = new Node;
      tmp -> data = value;
      tmp -> next = NULL;
      Node *pre, *cur;
      if (position == 1) {
        // 若链表中存在>=1个节点
        if (head != NULL) {
          tmp -> next = head;
          head = tmp;
          tmp = NULL;
        }
        // 若链表中没有节点
        else {
          CreateNode(value);
        }
      } else if (position == -1) {
        tail -> next = tmp;
        tail = tmp;
        tmp = NULL;
      } else {
        pre = head;
        for (int i = 1; i < position -1; i++) {
          if (pre) {
            pre = pre -> next;
            std::cout << "check value: " << pre -> data << std::endl;
            //pre -> data = 5;
          }
        }
        cur = pre -> next;
        // 插入位置不超过链表长度
        if (cur) {
          /* tmp -> next = pre;
          pre = tmp;
          tmp = NULL; */
          /* pre = tmp;
          std::cout << pre -> data << std::endl;
          tmp = NULL; */
          pre -> next = tmp;
          tmp -> next = cur;
        } 
        // 插入位置超过链表长度
        else {
          std::cout << "insert position exceeds length" << std::endl;
        }
      }
    }
    void deletion(int position) {
      Node *pre, *cur;
      if (position == 1) {
        // 若链表中没有节点
        if (!head) {
          std::cout << "cannot delete empty linked list" << std::endl;
        } 
        // 若链表中只有一个节点
        else if (head == tail) {
          head = NULL;
          tail = NULL;
        }
        else {
          pre = head;
          head = pre -> next;
          pre = NULL;
        }
      } else if (position == -1) {
               


      } else {
        pre = head;
        for (int i = 1; i < position - 1; i++) {
          if (pre) {
            pre = pre -> next;
          }
        }
        cur = pre -> next;
        pre -> next = cur -> next;
      }
    
    }
};

int main() {
  LinkedList a;
  LinkedList b;
  a.insertion(2, 1);
  a.insertion(4, 1);
  a.insertion(6, 1);
  a.insertion(8, -1);
  a.display();
  a.insertion(1, 3);
  a.display();
  a.insertion(3, 5);
  a.display();
  a.insertion(5, 7);
  a.display();
  a.insertion(10, -1);        
  a.display();
  a.deletion(1);
  a.display();
  a.deletion(4);
  a.display();
  a.deletion(5);
  a.display();
  a.deletion(3);
  a.display();
  a.deletion(1);
  a.display();
  a.deletion(2);
  a.display();
  a.deletion(1);
  a.display();
  return 0;
}
