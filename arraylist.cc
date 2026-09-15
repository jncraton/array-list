#include <cassert>
#include <print>
#include <stdexcept>

class ArrayList {
private:
  int *data;
  size_t capacity;
  size_t size;

  void resize(size_t new_capacity) {
    int *new_data = new int[new_capacity];
    for (size_t i = 0; i < size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

public:
  ArrayList() : capacity(4), size(0) {
    data = new int[capacity];
  }

  ~ArrayList() {
    delete[] data;
  }

  size_t get_size() const {
    return size;
  }

  void append(int value) {
  }

  int get(int index) const {
    return 0;
  }

  void pop() {
  }

  void insert(int index, int value) {
  }
};

int main() {
  ArrayList list;

  list.append(1);
  assert(("List has content", list.get_size() == 1));
  assert(("Single item appended", list.get(0) == 1));

  list.append(2);
  assert(("First item untouched", list.get(0) == 1));
  assert(("Second item appended", list.get(1) == 2));

  assert(("Get first item", list.get(0) == 1));
  assert(("Get second item", list.get(1) == 2));

  try {
    list.get(2);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &e) {
  }

  list.pop();
  assert(("Get first item after pop", list.get(0) == 1));
  assert(("Size after pop", list.get_size() == 1));

  list.pop();
  assert(("Pop first item", list.get_size() == 0));

  list.append(1);
  list.append(2);
  list.insert(0, 0);
  assert(("Insert 0 at index 0", list.get(0) == 0));
  assert(("Insert 1 at index 1", list.get(1) == 1));
  assert(("Insert 2 at index 2", list.get(2) == 2));

  list.insert(1, 100);
  assert(("Insert 100 at index 1", list.get(1) == 100));
  list.insert(2, 200);
  assert(("Insert 200 at index 2", list.get(2) == 200));

  return 0;
}
