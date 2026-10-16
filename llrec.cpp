#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void pivot_helper(Node *&head, Node *&smaller, Node *&larger, int pivot);

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  smaller = nullptr;
  larger = nullptr;
  pivot_helper(head, smaller,larger,pivot);
  head = NULL;
}

void pivot_helper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) return;
  Node* temp = head->next;
  head->next = nullptr;
  if (head->val <= pivot) {
    if (smaller == nullptr) {
      smaller = head;
      pivot_helper(temp, smaller, larger, pivot);
    }
    else {
      smaller->next = head;
      pivot_helper(temp, smaller->next, larger, pivot);
    }
  } else {
    if (larger == nullptr) {
      larger = head;
      pivot_helper(temp, smaller, larger, pivot);
    }
    else {
      larger->next = head;
      pivot_helper(temp, smaller, larger->next, pivot);
    }
  }
}

