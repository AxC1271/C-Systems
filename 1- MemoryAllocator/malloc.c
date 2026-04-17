#include <unistd.h>
#include <string.h>

void* my_malloc(size_t size);
void my_free(void* ptr);

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

#define BLOCK_SIZE sizeof(Block)

Block* head = NULL;  // start of our free list

void *my_malloc(size_t size) {
    Block* current = head;

    // 1. walk the list looking for a free block that fits
    while (current != NULL) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (void*)(current + 1);
        }
        current = current->next;
    }

    // 2. nothing found — ask OS for memory
    Block *block = sbrk(BLOCK_SIZE + size);

    block->size = size;
    block->free = 0;
    block->next = NULL;

    // 3. attach to linked list
    if (head == NULL) {
        head = block;
    } else {
        // walk to end of list and attach
        Block *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = block;
    }

    // 4. return pointer to data portion
    return (void*)(block + 1);
}

void my_free(void* ptr) {
    if (ptr == NULL) return;
    Block* block = (Block*)ptr - 1;
    block->free = 1;
}