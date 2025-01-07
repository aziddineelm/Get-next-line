# Get Next Line  

**Get Next Line** is a project from the 42/1337 curriculum that challenges students to create a function capable of reading a single line from a file descriptor, one line at a time.  

---

## 📋 **Project Description**  
The goal of this project is to develop a function that:  
- Reads a line from a file descriptor.  
- Returns the line, including the newline character if present.  
- Handles multiple file descriptors simultaneously.  
- Efficiently manages memory and avoids leaks.  

This project is a great way to deepen your understanding of file I/O operations, memory allocation, and state management in C.  

---

## 🛠️ **How It Works**  

The `get_next_line` function uses a buffer to read chunks of data from a file descriptor. By processing these chunks iteratively, it builds and returns each line of the file until EOF is reached.  

---

## 🚀 **Features**  
- Compatible with multiple file descriptors.  
- Handles any line length or buffer size.  
- Implements robust memory management.  
- Designed with simplicity and efficiency in mind.  

---

## 📂 **Repository Structure**  

```plaintext
.
├── get_next_line.c       // Core function implementation
├── get_next_line_utils.c // Utility functions
└── get_next_line.h       // Header file ```

---

```plaintext
.
├── get_next_line_bonus.c       // Core function implementation
├── get_next_line_utils_bonu.c // Utility functions
└──  get_next_line_bonu.h       // Header file````
