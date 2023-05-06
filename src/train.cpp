// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  first = nullptr;
  countOp = 0;
}
void Train::addCage(bool light) {
  Cage* p = nullptr;
  if (first == nullptr) {
    first = new Cage;
    first->next = first, first->prev = first;
    first->light = light;
  } else {
    p = new Cage;
    p->next = first, p->prev = first->prev;
    p->light = light;
    first->prev = p;
    p->prev->next = p;
  }
}
int Train::getLength() {
  Cage* ptr = first;
  ptr->light = 1;
  int k = 1;
  while (ptr) {
    ptr = ptr->next;
    if (ptr->light == 0) {
      k++;
      countOp++;
    }
    if (ptr->light == 1) {
      ptr->light = 0;
      for (int i = k; i > 0; i--)
        ptr = ptr->prev;
      countOp += k + 1;
      if (ptr->light == 0)
        return  k;
      k = 1;
    }
  }
  return -1;
}
int Train::getOpCount() {
  if (countOp == -1) countOp = getLength();
  return countOp;
}
