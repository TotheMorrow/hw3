#include "heap.h"
#include <iostream>
using namespace std;

int main() {
  Heap<int> heap(2);
	heap.push(0);
	heap.push(10);
	heap.push(5);
	heap.pop();
  cout << heap.top() << endl;
	heap.pop();
  cout << heap.top() << endl;
  return 0;
}




