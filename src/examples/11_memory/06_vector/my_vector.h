//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <iostream>
#include <memory>

template <typename T> class Vector {
private:
  std::size_t size;
  T *elements;
  std::size_t capacity;
  const int RESERVED_DEFAULT_MULTIPLIER{2};
  const int RESERVED_DEFAULT_SIZE{3};

public:
  Vector();
  // initialize size and create elements dynamic memory array
  Vector(std::size_t s);
  // legacy C++
  // Rule 1: create a copy constructor
  Vector(const Vector<T> &v);

  // overload [], allows cout << v[0] and v[0] = 15;
  T &operator[](std::size_t i) const { return elements[i]; }
  T &operator[](std::size_t i) { return elements[i]; }

  std::size_t Capacity() const { return capacity; }
  // Rule 2
  Vector &operator=(const Vector<T> &v);
  // rule 4
  Vector(Vector<T> &&v); // Move constructor
  // rule 5
  Vector &operator=(Vector<T> &&v);

  std::size_t Size() const { return size; }
  ~Vector(); // destructor, Rule 3
  void Reserve(std::size_t new_allocation_size);
  void Push_Back(T value);
};

/* free functions */
void use_stack_vector();
void use_heap_vector();
Vector<int> get_vector();

// put template class type declarations here
#endif // MY_VECTOR_H