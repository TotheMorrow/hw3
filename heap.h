#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp(size_t loc);

  void heapify(size_t loc);

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_;
  int m_;
  PComparator c_;
};

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
  m_ = m;
  c_ = c;
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
  // deallocate the heap?
}

template<typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return items_.empty();
}

template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items_.size();
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("Stack is empty");

  }
  return items_[0];
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(size_t loc) {
  size_t parent = loc;
  size_t left = 2 * loc + 1;
  size_t right = 2 * loc + 2;
  if (left < items_.size() && c_(items_[left], items_[parent])) {
    parent = left;
  }
  
  if (right < items_.size() && c_(items_[right], items_[parent])) {
    parent = right;
  }

  if (parent != loc) {
    T temp = items_[parent];
    items_[parent] = items_[loc];
    items_[loc] = temp;
    heapify(parent);
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Stack is empty");
  }
  if (size() == 1) {
    items_.pop_back();
    return;
  }

  items_[0] = items_.back();
  items_.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t loc) {
  size_t parent = (loc - 1) / 2;
  while (parent < size() && parent >= 0 && c_(items_[loc], items_[parent])) {
    // swap
    T temp = items_[loc];
    items_[loc] = items_[parent];
    items_[parent] = temp;
    loc = parent;
    parent = (loc - 1) / 2;
  }
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  // push onto the heap
  items_.push_back(item);
  trickleUp(items_.size() - 1);
}

#endif

