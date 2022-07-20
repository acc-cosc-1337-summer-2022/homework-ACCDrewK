#include "my_vector.h"
#include <string>
// #include <template>

template <typename T>
Vector<T>::Vector() : size(0), elements(nullptr), capacity(0){};

template <typename T>
Vector<T>::Vector(std::size_t s) : size(s), elements(new T[s]), capacity(s) {
  std::cout << "Memory created at: " << &elements << std::endl;
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector &v) : size{v.size}, elements{new T(v.size)} {
  /* 1. Initialize size for v2 */
  /* 2. Initialize memory for v2 */
  /* 3. Copy elements from v1 to v2 */
  std::cout << "Executed copy constructor..." << std::endl;
  for (std::size_t i = 0; i < v.size; ++i) {
    elements[i] = v.elements[i];
  }
};

template <typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &v1) {
  /* 1. Create temp memory for v2 */
  /* 2. Copy values from v into temp for v2 */
  /* 3. delete v2 elements from memory (no memory leak)
     4. Point elements memory to temp
     5. Return reference to this vector
     6. Return a self ref to this class */
  std::cout << "Memory created " << elements << std::endl;
  T *temp{new T[v1.size]};
  for (std::size_t i = 0; i < v1.size; i++) {
    temp[i] = v1.elements[i];
  }
  std::cout << "Delete memory " << elements << std::endl;
  delete[] elements;
  elements = temp;
  std::cout << "Copy assignment operator " << elements << std::endl;
  size = v1.size;
  return *this;
}

template <typename T> Vector<T>::~Vector() {
  std::cout << "Memory released..." << std::endl;
  delete[] elements;
}

template <typename T> Vector<T> &Vector<T>::operator=(Vector<T> &&v) {
  std::cout << "Move assignment: delete memory " << elements << std::endl;
  delete elements;
  elements = v.elements;
  std::cout << "Move assignment: point to memory " << elements << std::endl;
  size = v.size;
  v.elements = nullptr;
  v.size = 0;
  return *this;
};

template <typename T>
Vector<T>::Vector(Vector<T> &&v) : size(v.size), elements{v.elements} {
  /*
    1. get v.elements memory
    2. get size form v
    3. point v.elements to nullptr
    4. set v.size to 0
    */
  std::cout << "Move constructor " << elements << std::endl;
  v.size = 0;
  // v.capacity = size;
  v.elements = nullptr;
};

template <typename T> void Vector<T>::Reserve(std::size_t new_allocation_size) {
  if (new_allocation_size <= capacity) {
    return;
  }
  T *temp = new T[new_allocation_size];
  std::cout << "Reserve memory created: " << temp << std::endl;
  for (std::size_t i = 0; i < size; i++) {
    temp[i] = elements[i];
  }
  delete[] elements;
  elements = temp;
  capacity = new_allocation_size;
};

template <typename T> void Vector<T>::Push_Back(T value) {
  /*If capacity 0, call reserve w/ reserve default size.
  else, if size== space, call reseve w/ space * reserve default multiplier
  set value to current element at size
  increment size*/

  if (capacity == 0) {
    Reserve(RESERVED_DEFAULT_SIZE);
  } else if (size == capacity) {
    Reserve(capacity * RESERVED_DEFAULT_MULTIPLIER);
  }
  elements[size] = value;
  size++;
};

/* free functions */

template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
Vector<int> get_vector() {
  Vector<int> v1(3);
  return v1;
};

void use_stack_vector() {
  Vector<int> v(3);
  std::cout << "Exiting use stack vector..." << std::endl;
}
void use_heap_vector() {
  Vector<int> *v{new Vector<int>(3)};
  delete v;
  std::cout << "Exiting use heap vector..." << std::endl;
}