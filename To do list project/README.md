# To-Do List Management System

A comprehensive command-line task management application built in C that helps users organize, prioritize, and track their daily tasks efficiently. Features include task categorization by priority, deadline tracking, and status management.

## 🎯 Project Overview

This console-based to-do list application provides a robust solution for personal task management. It allows users to create tasks with detailed information, track their completion status, and organize them by priority or due date. All data is stored persistently in a CSV file format.

## ✨ Key Features

### Core Functionality
- **Add New Tasks**: Create tasks with title, description, due date, and priority level
- **View All Tasks**: Display complete task list in a formatted table
- **Search Tasks**: Find specific tasks by their unique ID
- **Update Tasks**: Modify existing task details
- **Delete Tasks**: Remove unwanted tasks from the list
- **Mark as Completed**: Track task completion status

### Advanced Features
- **Priority Sorting**: Sort tasks by priority (High → Medium → Low)
- **Due Date Sorting**: Organize tasks chronologically by deadline
- **Status Tracking**: Distinguish between Pending and Completed tasks
- **Auto ID Generation**: Automatically assigns unique identifiers to new tasks
- **Persistent Storage**: All data saved in `todo.txt` file

## 🛠️ Technical Implementation

### Technologies Used
- **Language**: C
- **Storage**: File I/O (CSV format)
- **Data Structure**: Structs for task organization
- **Algorithms**: Bubble sort for priority and date sorting

### Data Structure

```c
struct Task {
    int id;                    // Unique identifier
    char title[100];           // Task title
    char description[200];     // Detailed description
    char dueDate[20];          // Due date (DD-MM-YYYY)
    char priority[10];         // High/Medium/Low
    char status[15];           // Pending/Completed
}
```

### Key Technical Highlights
- **String Manipulation**: Robust handling of user input with `fgets()` and newline removal
- **File Operations**: Read/write with temporary file technique for safe updates
- **Sorting Algorithms**: Implemented bubble sort for dual sorting criteria
- **Priority Mapping**: Custom function to convert priority strings to numerical values
- **CSV Parsing**: Complex `fscanf()` patterns to handle multi-field records

## 📁 Project Structure

```
todo-list-management/
├── todo.c           # Main application code
├── todo.txt         # Data storage file (auto-generated)
└── README.md        # Project documentation
```

## 🚀 How to Run

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal/Command prompt access

### Compilation
```bash
gcc todo.c -o todo
```

### Execution
```bash
./todo          # On Linux/Mac
todo.exe        # On Windows
```

## 💡 Usage Example

Upon running, users see an interactive menu:

```
=====================================
        TO-DO LIST MANAGEMENT         
=====================================
1. Add New Task
2. View All Tasks
3. Search Task by ID
4. Update Task
5. Delete Task
6. Mark Task as Completed
7. Sort Tasks by Priority
8. Sort Tasks by Due Date
9. Exit
-------------------------------------
Enter your choice:
```

### Sample Workflow
1. **Add a Task**: Enter task details including title, description, due date, and priority
2. **View Tasks**: See all your tasks in a formatted table
3. **Sort by Priority**: Organize tasks with high-priority items first
4. **Mark Completed**: Update task status when finished
5. **Delete Task**: Remove completed or cancelled tasks

## 📊 Data Format

The `todo.txt` file stores data in CSV format:
```
1,Complete project report,Finish final draft and submit,15-12-2024,High,Pending
2,Buy groceries,Milk bread eggs,10-12-2024,Low,Completed
```

Format: `ID,Title,Description,DueDate,Priority,Status`

## 🎓 Skills Demonstrated

### Core Programming Concepts
- **File I/O Operations**: Advanced file handling with read/write operations
- **Data Structures**: Struct design for complex data modeling
- **String Manipulation**: Safe handling of user input and text processing
- **Memory Management**: Efficient use of arrays and file pointers
- **Algorithm Implementation**: Sorting algorithms (bubble sort)

### Software Development Practices
- **Modular Design**: Function-based architecture for maintainability
- **Error Handling**: Comprehensive validation of file operations
- **User Experience**: Clean, intuitive menu-driven interface
- **Data Persistence**: Reliable storage and retrieval mechanisms
- **Code Documentation**: Well-commented and organized code

### Problem-Solving Skills
- **Priority Management**: Converting qualitative values to quantitative comparisons
- **Date Handling**: String-based date sorting
- **CRUD Operations**: Complete create, read, update, delete functionality
- **Data Integrity**: Safe file update operations using temporary files

## 🔄 Future Enhancements

Potential improvements to showcase continued learning:
- **Date Validation**: Ensure due dates are in correct format and in the future
- **Recurring Tasks**: Add support for daily/weekly/monthly recurring tasks
- **Categories/Tags**: Implement task categorization (Work, Personal, Shopping, etc.)
- **Filtering**: Filter tasks by status, priority, or date range
- **Overdue Alerts**: Highlight tasks past their due date
- **Statistics Dashboard**: Show completion rates and productivity metrics
- **Export/Import**: Add JSON or XML export capabilities
- **Search Enhancement**: Search by title or description keywords
- **Task Dependencies**: Link related tasks together
- **Color Coding**: Use ANSI colors for better visual hierarchy

## 🏆 Project Highlights

### Why This Project Stands Out
- **Practical Application**: Solves real-world productivity challenges
- **Complexity**: Demonstrates ability to handle multi-field data structures
- **Algorithm Knowledge**: Shows understanding of sorting implementations
- **User-Centric Design**: Intuitive interface with clear feedback messages
- **Scalability**: Architecture allows for easy feature additions
- **Professional Code**: Clean, well-organized, and maintainable

### Learning Outcomes
This project demonstrates proficiency in:
- Building complete applications from scratch
- Designing data models for complex domains
- Implementing efficient algorithms
- Creating user-friendly interfaces
- Managing persistent data storage
- Writing production-ready code

## 👨‍💻 Technical Specifications

- **Lines of Code**: ~400+ lines
- **Functions**: 14 modular functions
- **Complexity**: Intermediate to Advanced
- **Time Complexity**: O(n²) for sorting operations
- **Space Complexity**: O(n) for task storage

## 📝 License

This is an educational project, free to use and modify.

---

**Developer Note**: This project showcases the ability to design and implement feature-rich applications with attention to user experience, data integrity, and code quality. It demonstrates readiness for real-world software development challenges.

## 🔗 Connect

Feel free to reach out for any questions or discussions about this project!

---

*Built with dedication to clean code and practical problem-solving* ✨
