## 🚀 First Stable Release (v0.1.0)

This is the first major milestone of MIME-OS, a simulated operating system kernel written in C++.

### ✨ Features Implemented:
- **Virtual File System (VFS):** Supports creating directories, files, writing/reading content, and navigation (`cd`, `ls`, `pwd`, `mkdir`, `touch`).
- **Process Management:** Supports process creation (`exec`), termination (`kill`), and listing (`ps`).
- **CPU Scheduling:** Implements **Round Robin** scheduling algorithm with context switching simulation.
- **Memory Management:** Implements **First-Fit** allocation strategy with memory protection and cleanup (`free`).
- **Interactive Shell:** A command-line interface to interact with the kernel.

### 🛠 How to Run:
```bash
make
./mime-os