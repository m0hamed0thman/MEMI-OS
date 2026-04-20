# MIME-OS (MEMI-OS) 🚀

MIME-OS is a lightweight, educational operating system kernel and hardware emulator built in modern C++20. It demonstrates core OS concepts including virtual file systems, process scheduling, memory management, and basic CPU emulation within a simulated environment.

## 🌟 Architecture Overview

The system is modularized into several key subsystems:
* **Hardware Abstraction:** Simulates a basic CPU with an instruction cycle (Fetch, Decode, Execute) and a RAM module.
* **Memory Management:** Implements contiguous memory allocation and deallocation for processes.
* **Process Management:** Features a Round-Robin Scheduler (Time Quantum = 3) managing processes through `READY`, `RUNNING`, and `TERMINATED` states.
* **Virtual File System (VFS):** A hierarchical directory and file structure with state persistence (saving/loading from disk).
* **Shell & Command Line Interface:** An interactive REPL loop allowing users to interact with the OS dynamically.
* **System Logger:** Thread-safe logging mechanism recording events across `INFO`, `WARNING`, `ERROR`, and `DEBUG` levels.

---

## ✅ What's Working (Current Features)

### 1. Interactive Shell & Commands
The OS launches in a dedicated terminal window (supports `gnome-terminal` and `xterm`). The shell executes operations in real-time alongside the process scheduler.
* **System Navigation:** `ls`, `dir`, `pwd`, `cd`, `mkdir`, `touch`.
* **File Operations:** `cat`, `read`, `write`, `rewrite`, `clean`.
* **Process Control:** `ps` (list active processes), `exec <program>` (spawn process), `kill <pid>`.
* **System Info:** `free`, `mem` (memory usage statistics), `help`, `clear`.
* **Scripting:** `run <script_file>` executes batch commands from a text file.

### 2. Process & Memory Management
* Allocates a standard 64-unit block of memory per process upon creation.
* Executes processes using a Round-Robin scheduling algorithm.
* Safely frees memory and removes the process context upon termination or via the `kill` command.

### 3. File System Persistence
* In-memory nodes (Directories and Files) allow seamless manipulation.
* `saveState()` function serializes the entire filesystem tree to a local disk image, ensuring data is not lost between sessions.

---

## 🚧 Work In Progress (Roadmap & Future Scope)

As MIME-OS evolves, the following features are actively being developed:

* **Recursive Directory Sizing:** Currently, directory size returns the number of immediate children. Future updates will implement DFS/BFS algorithms to calculate the total size of all nested files.
* **Extended CPU Instruction Set:** The CPU currently decodes dummy/basic opcodes (`0x00`, `0x01`, `0xFF`). We are expanding the instruction set to support complete assembly-like program execution.
* **Advanced Memory Allocation:** Moving beyond simple First-Fit/Contiguous allocation towards Paging or Segmentation to prevent memory fragmentation.
* **File Permissions & Security:** Implementing read/write/execute permissions for different user levels.

---

## 🛠️ Getting Started

### Prerequisites
* **Compiler:** A C++20 compatible compiler (e.g., GCC 10+ or Clang 10+).
* **Build System:** CMake 3.20 or higher.
* **OS:** Linux environment (Ubuntu recommended) to fully support the terminal-spawning logic (`gnome-terminal` or `xterm`).

### Build Instructions

1. Clone the repository and navigate to the project root:
   ```bash
   cd MIME_OS