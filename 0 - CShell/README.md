# Custom Unix Shell in C

A Unix shell written from scratch in C, built to understand the OS/software
layer in preparation for bare-metal porting to a self-designed 2-way
superscalar RISC-V SoC.

---

## What it does

- Prints a prompt and reads user input
- Parses input into tokens (command + arguments)
- Forks a child process and execs commands via `execvp`
- Waits for child processes to finish with `waitpid`
- Built-in commands: `cd`, `exit`
- Pipes: `ls | grep foo`

---

## Building and Running

```bash
gcc -Wall shell.c -o shell
./shell
```

---

## Roadmap

- [x] REPL loop
- [x] Input parsing
- [x] Fork + exec
- [x] Built-in commands (cd, exit)
- [x] Pipes
- [ ] I/O redirection (>, <, >>)
- [ ] Signals (Ctrl+C handling)
- [ ] Port to bare-metal RISC-V SoC

---

## Why

Most shell tutorials stop at the basics. This is part of a larger effort to
own the full stack — from custom silicon to the software running on it.
The eventual goal is booting this shell on a self-designed RISC-V processor.