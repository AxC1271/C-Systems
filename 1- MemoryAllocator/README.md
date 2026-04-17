# Memory Allocator in C

A `malloc` and `free` implementation from scratch, managing the heap
directly via `sbrk`.

---

## How it works

The allocator maintains a linked list of memory blocks. Each block
has a header storing its size, whether it's free, and a pointer to
the next block:

```c
typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;
```

### Allocation
1. Walk the free list looking for a block that's large enough
2. If found, mark it in use and return a pointer to its data portion
3. If not, call `sbrk` to expand the heap and append a new block

### Freeing
Step back one `Block` from the returned pointer to find the header,
then mark it free. The data isn't wiped — it's just available for
reuse.

---

## Key insight

`free()` doesn't return memory to the OS. It just marks the block available internally. The allocator reuses freed blocks before asking the OS for more memory via `sbrk`.

This is visible in the test output:

```
a: 0x104530018
b: 0x104530094
c: 0x104530018
```

---

## What's missing vs production malloc

- Block splitting — using a 200B block for a 10B request wastes space
- Block coalescing — merging adjacent free blocks
- Thread safety
- Size classes for performance

---

## Why

Part of a larger effort to own the full software stack running on a self-designed RISC-V SoC. A bare-metal system has no malloc unless you write one — this is that foundation.