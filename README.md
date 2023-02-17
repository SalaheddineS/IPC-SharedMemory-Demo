# IPC-SharedMemory-Demo

This is a simple example of using shared memory for Inter-Process Communication (IPC) in C. The program demonstrates how to create a shared memory region, write data to it, and read data from it using two separate processes.

## Prerequisites

This program requires a C compiler. It has been tested on Windows 10 with the Microsoft compiler & CMake.

## Getting Started

1. Clone the repository to your local machine.

2. Open a command prompt and navigate to the project directory.

3. Compile the program using your chosen compiler.

4. Run the victim program by executing the command `.\victim.exe`.

5. Run the reader program by executing the command `.\Attacker.exe`.

## How it Works

The writer program creates a file mapping object with read/write access, creates a view of the shared memory region, and writes data to the region. The reader program opens the same file mapping object, creates a view of the shared memory region, and reads the data from the region. Both programs unmap the view of the shared memory region and close the file mapping object when they are done.


