# Inventory Management System

A simple yet efficient command-line inventory management application built in C that allows users to manage product inventory with full CRUD (Create, Read, Update, Delete) operations.

## 🎯 Project Overview

This console-based application provides a straightforward solution for small businesses or individuals to track inventory items, including their quantities and prices. All data is persisted in a CSV file format, making it easy to import/export data if needed.

## ✨ Key Features

- **Add Items**: Create new inventory entries with auto-generated unique IDs
- **View All Items**: Display complete inventory in a formatted table
- **Search Items**: Find specific items by their ID
- **Update Items**: Modify existing item details (name, quantity, price)
- **Delete Items**: Remove items from inventory
- **Persistent Storage**: All data saved in `inventory.txt` file
- **Auto ID Generation**: Automatically assigns unique IDs to new items

## 🛠️ Technical Implementation

### Technologies Used
- **Language**: C
- **Storage**: File I/O (CSV format)
- **Data Structure**: Structs for item organization

### Core Functionality

**Data Structure:**
```c
struct Item {
    int id;           // Unique identifier
    char name[50];    // Item name
    int quantity;     // Stock quantity
    float price;      // Item price
}
```

**File Operations:**
- CSV-based storage (`inventory.txt`)
- Read/write operations for data persistence
- Temporary file technique for update/delete operations

## 📁 Project Structure

```
inventory-management/
├── main.c           # Main application code
├── inventory.txt    # Data storage file (auto-generated)
└── README.md        # Project documentation
```

## 🚀 How to Run

### Prerequisites
- GCC compiler (or any C compiler)
- Terminal/Command prompt access

### Compilation
```bash
gcc main.c -o inventory
```

### Execution
```bash
./inventory          # On Linux/Mac
inventory.exe        # On Windows
```

## 💡 Usage Example

Upon running, users are presented with a menu:

```
=====================================
     INVENTORY MANAGEMENT SYSTEM     
=====================================
1. Add Item
2. View All Items
3. Search Item
4. Update Item
5. Delete Item
6. Exit
-------------------------------------
Enter your choice:
```

## 🎓 Skills Demonstrated

- **File I/O Operations**: Reading from and writing to files
- **Data Structures**: Using structs for organized data management
- **Memory Management**: Proper handling of file pointers and buffers
- **Algorithm Design**: ID generation, search, and CRUD operations
- **User Interface**: Clean, menu-driven console interface
- **Error Handling**: File operation validation and user input handling
- **Code Organization**: Modular function design for maintainability

## 📊 Sample Data Format

The `inventory.txt` file stores data in CSV format:
```
1,shashank,23,54.00
2,amit,13,-13.00
```

Format: `ID,Name,Quantity,Price`

## 🔄 Future Enhancements

Potential improvements for this project:
- Add data validation (prevent negative quantities/prices)
- Implement search by name functionality
- Add sorting options (by price, quantity, name)
- Generate reports (low stock alerts, total inventory value)
- Add backup and restore functionality
- Implement category management

## 👨‍💻 Developer Notes

This project demonstrates fundamental programming concepts essential for systems development, including file handling, data persistence, and user interaction design. The modular architecture makes it easy to extend with additional features.

## 📝 License

This is an educational project, free to use and modify.

---

**Note**: This project showcases practical C programming skills applicable to real-world business applications, demonstrating the ability to design, implement, and maintain data-driven systems.
