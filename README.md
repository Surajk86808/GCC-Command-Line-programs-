# Suraj Kumar - C Programming Projects Portfolio

Welcome to my collection of C programming projects! This repository demonstrates my proficiency in systems programming, data structures, file operations, and building practical command-line applications.

## 👨‍💻 About Me

I'm a passionate developer with a strong foundation in C programming and systems development. I enjoy building practical applications that solve real-world problems while showcasing clean code architecture and robust error handling.

## 📂 Projects

### 1. To-Do List Management System
**Location:** `To do list project/`

A comprehensive task management application that helps users organize, prioritize, and track their daily tasks efficiently.

**Key Features:**
- ✅ Complete CRUD operations (Create, Read, Update, Delete)
- 📊 Priority-based task sorting (High/Medium/Low)
- 📅 Due date tracking and sorting
- ✔️ Task completion status tracking
- 🔍 Search functionality by task ID
- 💾 Persistent storage using CSV format

**Technical Highlights:**
- Advanced file I/O operations with temporary file technique
- Bubble sort algorithm implementation
- Complex struct design for multi-field data
- String manipulation and input sanitization
- Custom priority mapping system

**Technologies:** C, File I/O, Structs, Sorting Algorithms

[View Project Details →](To%20do%20list%20project/README.md)

---

### 2. Inventory Management System
**Location:** `inventory managment/`

A streamlined inventory management solution for small businesses to track products, quantities, and pricing.

**Key Features:**
- 📦 Add, view, search, update, and delete inventory items
- 🆔 Auto-generated unique ID system
- 💰 Price and quantity tracking
- 📋 Formatted table display
- 💾 CSV-based data persistence

**Technical Highlights:**
- Clean modular function design
- Efficient file handling operations
- Memory-safe string operations
- Error handling for file operations
- Simple yet effective data structure

**Technologies:** C, File I/O, Structs

[View Project Details →](inventory%20managment/README.md)

---

## 🛠️ Technical Skills Demonstrated

### Core Programming Concepts
- **Data Structures**: Struct design and array manipulation
- **File I/O**: Advanced read/write operations, CSV parsing
- **Algorithm Implementation**: Sorting (bubble sort), searching
- **Memory Management**: Proper pointer handling and buffer management
- **String Manipulation**: Safe input handling with `fgets()` and sanitization

### Software Development Practices
- **Modular Design**: Function-based architecture for maintainability
- **Error Handling**: Comprehensive validation and error messages
- **User Experience**: Intuitive menu-driven interfaces
- **Data Persistence**: Reliable storage mechanisms
- **Code Quality**: Well-commented, organized, and readable code

### Problem-Solving Skills
- Converting requirements into working applications
- Implementing CRUD operations efficiently
- Handling edge cases and data integrity
- Designing user-friendly command-line interfaces

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal/Command prompt

### Compilation & Execution

**For To-Do List:**
```bash
cd "To do list project"
gcc todo.c -o todo
./todo          # Linux/Mac
todo.exe        # Windows
```

**For Inventory Management:**
```bash
cd "inventory managment"
gcc main.c -o inventory
./inventory     # Linux/Mac
inventory.exe   # Windows
```

---

## 📊 Project Statistics

| Project | Lines of Code | Functions | Complexity | Features |
|---------|---------------|-----------|------------|----------|
| To-Do List | 400+ | 14 | Advanced | 9 operations |
| Inventory | 200+ | 7 | Intermediate | 6 operations |

---

## 🎯 Future Enhancements

**To-Do List:**
- Date validation and format checking
- Task categorization/tagging system
- Recurring tasks support
- Overdue task alerts
- Statistics dashboard
- Color-coded terminal output

**Inventory Management:**
- Input validation (prevent negative values)
- Search by name functionality
- Sorting options (by price, quantity, name)
- Low stock alerts
- Inventory value reports
- Category management

---

## 📝 Code Samples

### Data Structure Design
```c
// To-Do List Task Structure
struct Task {
    int id;
    char title[100];
    char description[200];
    char dueDate[20];
    char priority[10];
    char status[15];
}

// Inventory Item Structure
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
}
```

### File Operations Pattern
```c
// Safe file update using temporary file
FILE *fp = fopen(FILE_NAME, "r");
FILE *temp = fopen("temp.txt", "w");
// ... perform operations ...
fclose(fp);
fclose(temp);
remove(FILE_NAME);
rename("temp.txt", FILE_NAME);
```

---

## 🏆 Learning Outcomes

Through these projects, I've developed:
- **Strong foundation in C programming** with practical applications
- **File handling expertise** for data persistence
- **Algorithm implementation** skills (sorting, searching)
- **User interface design** for command-line applications
- **Problem-solving abilities** for real-world scenarios
- **Code organization** and modular design principles

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🔗 Connect With Me

Feel free to explore these projects, suggest improvements, or reach out for collaboration opportunities!

---

## 📌 Quick Navigation

- [To-Do List Project](To%20do%20list%20project/)
- [Inventory Management Project](inventory%20managment/)
- [License](LICENSE)

---

*Built with dedication to clean code, practical problem-solving, and continuous learning* ✨

**Last Updated:** November 2025
