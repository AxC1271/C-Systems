# C Systems Programming — RISC-V Stack

Low-level C projects built from scratch as the software foundation
for a self-designed 2-way superscalar RISC-V SoC.

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