# Library-Management-System
A simple and efficient C++ console-based application designed to manage a collection of manga books. 

## Description

The Manga Management System is a C++ console application designed to manage a collection of manga books. It allows users to perform the following operations:
- View all manga in the library.
- Sort manga alphabetically by their titles using the **quicksort algorithm**.
- Search for available manga in the library.
- Borrow manga by providing a book ID.

This project is a great example of using **data structures**, **functions**, and **algorithms** in C++ programming.

---

## Features

1. **View All Manga**: Displays all the manga books in the collection, including their ID, title, author, and availability status.
2. **Sort by Title**: Uses the quicksort algorithm to sort manga titles in ascending order.
3. **Search for Available Manga**: Lists all manga that are currently available for borrowing.
4. **Borrow Manga**: Allows a user to borrow a manga by providing its unique ID. Updates the availability status of the manga.
5. **Interactive Menu**: Provides an intuitive menu-driven interface for user interaction.

---

## Implementation Details

- **Data Storage**: Manga data is stored using a structure (`struct`) containing fields such as ID, title, author, and availability status.
- **Sorting**: The quicksort algorithm is used to sort manga by their titles efficiently.
- **Functions**:
  - `displayAllBooks`: Displays all manga in the collection.
  - `quickSortByTitle`: Sorts the manga by their titles.
  - `searchAvailableBooks`: Searches for manga that are available.
  - `borrowBook`: Allows users to borrow manga by ID.
- **Interactive Menu**: A menu-driven interface lets users choose different operations.

---
