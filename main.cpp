#include <iostream>
#include <memory>
#include "mem_pool.h"
#include "stdio.h"
#include <string>

class TestClass;

std::unique_ptr<MemPool<TestClass> > alloc;

class TestClass 
{
public:
  TestClass()
  {
  }

  void* operator new(std::size_t count) {
	return alloc->Alloc();
  }

  void operator delete(void *p, std::size_t count) {
	alloc->Dealloc(static_cast<TestClass *>(p));
  }

private:
  int x;
  int y;
};


void RunSimpleAllocationCounterTest()
{
  bool bPass = false;

  {
	std::unique_ptr<TestClass> pTest(new TestClass());
  
	if (alloc_ctr == 1)
	  bPass = true;
  }

  bPass = false;
  if (dealloc_ctr == 1)
	bPass = true;

  std::cout << "Simple allocation counter test: " << (bPass ? "Pass" : "Fail") << std::endl;
}
int main() {
  RunSimpleAllocationCounterTest();

  return 0;
}
