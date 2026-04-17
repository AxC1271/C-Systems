# C Systems Programming — RISC-V Stack

Self-directed C systems programming projects — shells, allocators, kernels, and drivers — built as the software foundation for a custom RISC-V superscalar SoC.

## Projects

| Project | Description | Status |
|---|---|---|
| CShell | Unix shell — REPL, fork/exec, pipes | ✅ Complete |
| MemoryAllocator | malloc/free from scratch using sbrk | ✅ Complete |
| UARTDriver | Bare-metal UART driver | 🔄 In progress |
| Bootloader | RISC-V bootloader in C + assembly | 🔄 In progress |
| KernelMini | Minimal kernel — syscalls, scheduler | 🔄 In progress |
| DeviceDriver | Linux kernel modules | 🔄 In progress |

---

## Goal

Boot a Unix-like shell on a self-designed RISC-V processor. Full stack ownership: RTL → ISA → bootloader → kernel → shell.

---

Thanks for stopping by!