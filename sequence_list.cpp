/***************************
 * @author   yehao
 * @date     11 July 2018 
 * @theme    sequence list
 **************************/

#include <iostream>

#define MAXSIZE 9999

typedef struct {
  int data[MAXSIZE];
  int length;
} SequenceList;

int a[MAXSIZE];

void create(SequenceList &L) {
  L.length = 0;// initial length
  int value;
  int i = 0;
  while (std::cin >> value) {
    L.data[i] = value;
    L.length++;
    i++;
  }
}

void display(SequenceList &L) {
  for (int i = 0; i < L.length; ++i) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
  // test
  std::cout << L.length << std::endl;
}

void insertion(SequenceList &L, int position, int value) {
  if (L.length == 0) {
    std::cout << "can not insert a empty sequence_list, please use create() function first." << std::endl;
  } else if (position <= L.length) {     
    for (int i = L.length; i >= position; --i) {
      L.data[i] = L.data[i - 1];
    }
    L.data[position - 1] = value;
    L.length++;
  } else {
    std::cout << "invalid position" << std::endl;
  }

}

void deletion(SequenceList &L, int position) {
  if (L.length == 0) {
    std::cout << "can not delete a empty sequence_list, please use create() function first." << std::endl;
  } else if (position <= L.length) {
    for (int i = position -1; i < L.length - 1; ++i) {
      L.data[i] = L.data[i + 1];
    }
    L.length--;
  } else {
    std::cout << "invalid position" << std::endl;
  }
}

int main() {
  SequenceList a;
  display(a);
  create(a);
  insertion(a, 1, 4);
  display(a);
  insertion(a, 3, 100);
  display(a);
  deletion(a, 5);
  display(a);
  return 0;
}
