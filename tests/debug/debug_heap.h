
#ifndef DEBUG_HEAP
#define DEBUG_HEAP

#define DBG_HEAP_COUNT 4096

typedef struct {
    void* addr;
    int size;
    char* file;
    int line;
} DBG_HEAP_ENTRY;

//the first one is a macro, and therefore replaces the __FILE__ and __LINE__ wherever we use them
#define debug_malloc(size) _debug_malloc(size, __FILE__, __LINE__)
void* _debug_malloc(int size, char* file, int line);

void debug_free(void* address);

int debug_verify_heap();

#endif
