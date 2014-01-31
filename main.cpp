#include <iostream>
#include "mem_pool.h"

class TestClass;


class TestClass 
{
public:
  void* operator new(std::size_t count) {
	return alloc.Alloc();
  }

  void operator delete(void *p, std::size_t count) {
	alloc.Dealloc();
  }

private:
  int x;
  int y;

  MemPool<TestClass> alloc;
};


int main() {
  

}
