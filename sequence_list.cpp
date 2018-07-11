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
} Sequence_List;

int a[MAXSIZE];

void create(Sequence_List &L) {
  // initial length
  L.length = 0;
  int value;
  int i = 0;
  while (std::cin >> value) {
    L.data[i] = value;
    L.length++;
    i++;
  }
}

void display(Sequence_List &L) {
  for (int i = 0; i < L.length; i++) {
    std::cout << L.data[i] << " ";
  }
  std::cout << std::endl;
  // test
  //std::cout << L.length << std::endl;
}

void insertion(Sequence_List &L, int position, int value) {
  if (L.length == 0) {
    std::cout << "can not insert a empty sequence_list, please use create() function first." << std::endl;
  } else if (position <= L.length) {     
    for (int i = L.length; i >= position; i--) {
      L.data[i] = L.data[i - 1];
    }
    L.data[position - 1] = value;
    L.length++;
  } else {
    std::cout << "invalid position" << std::endl;
  }

}

void deletion(Sequence_List &L, int position) {
  if (L.length == 0) {
    std::cout << "can not delete a empty sequence_list, please use create() function first." << std::endl;
  } else if (position <= L.length) {
    for (int i = position -1; i < L.length - 1; i++) {
      L.data[i] = L.data[i + 1];
    }
    L.length--;
  } else {
    std::cout << "invalid position" << std::endl;
  }
}

int main() {
  Sequence_List a;
  create(a);
  insertion(a, 1, 4);
  display(a);
  insertion(a, 3, 100);
  display(a);
  deletion(a, 5);
  display(a);
  return 0;
}
