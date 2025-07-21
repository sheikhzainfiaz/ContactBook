# Contact Book

A **C++ CLI/WinForms-based Contact Book** that allows users to manage contacts with a clean, windowed interface while practicing **Data Structures (Linked Lists)** and **SQL Server integration** for persistent storage.

---

## Features

✅ Add, Update, Delete Contacts  
✅ User authentication (simple login)  
✅ Contact data displayed using Linked Lists for practice  
✅ Clean Windows Form UI using C++/CLI  
✅ SQL Server backend for persistent data  
✅ Suitable for Data Structures lab and semester projects

---

## Project Structure

- `/src` – Contains all C++ CLI/WinForms source code files.
- `/database` – Contains SQL Server scripts to set up the `ContactBookDB` database and required tables for the project.
- `/docs` – Documentation and screenshots (optional).

---

## Setup Instructions

### 1️⃣ Database Setup
- Navigate to the `database/` folder.
- Execute the provided SQL script (`setup_contactbookdb.sql`) in your **SQL Server environment** to set up the database and dummy data.

### 2️⃣ Application Setup

1. Clone this repository:
   ```bash
   git clone https://github.com/sheikhzainfiaz/ContactBook.git
   ```
2. Open the solution in **Visual Studio**.
3. Ensure the **SQL Server connection string** in your project matches your local environment.
4. Build and run the project.

---

## Usage

- Login using the dummy user provided in the database setup for testing.
- Add, view, update, and delete contacts through the Windows Form interface.
- Contact lists are loaded and displayed using Linked Lists, helping you practice linked list traversal, insertion, and deletion in a real project.
- You can extend it further to add:
  - Search using linked list traversal
  - Sorting contacts within the linked list
  - Exporting contacts to CSV

---

## Screenshots


![alt text](image-1.png)
---

## Why This Project?

✅ Practice Data Structures (Linked Lists) with a real application context.  
✅ Learn C++ CLI/WinForms application development.  
✅ Understand how database-backed applications work while maintaining the use of in-memory structures for learning.  
✅ Suitable for semester projects, lab submissions, and portfolio building.

---



## License

Free to use for learning and educational purposes.

