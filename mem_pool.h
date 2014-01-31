const int DEF_PAGE_SIZE = 1 << 12; // 4k

static int alloc_ctr = 0;
static int dealloc_ctr = 0;

template <class T>
class MemPool
{
public:
  T *Alloc() {
	++alloc_ctr;
	return static_cast<T *>(malloc(sizeof(T)));
  }
  void Dealloc(T *p) {
	++dealloc_ctr;
	free(p);
  }

};
