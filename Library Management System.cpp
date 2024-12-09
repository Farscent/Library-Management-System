#include <iostream>
#include <string>


struct Book {
   std::string id;     
   std::string title; 
   std::string author;
   bool isAvailable;   
};


void printBooks(Book book) {
   std::cout
       << "- "
       << book.id << ": "
       << book.title << ","
       << book.author << ","
       << (book.isAvailable ? " (Available)" : " (Borrowed)") << "\n";
}


int partition(Book books[], int low, int high) {
   Book pivot = books[high];
   int i = low - 1;


   for (int j = low; j < high; j++) {
       if (books[j].title < pivot.title) {
           i++;
           std::swap(books[i], books[j]);
       }
   }
   std::swap(books[i + 1], books[high]);


   return i + 1;
}


void quickSortByTitle(Book books[], int low, int high){
   // Base case: when the section has one or no elements.
   if (low >= high) return;


   // Partition the array and get the pivot index.
   int pivot = partition(books, low, high);


   // Recursively sort the left and right subarrays.
   quickSortByTitle(books, low, pivot - 1);
   quickSortByTitle(books, pivot + 1, high);
}


void displayAllBooks(Book books[], int size) {   
   for (int i = 0; i < size; i++){
       printBooks(books[i]);
   }
}


void searchAvailableBooks(Book books[], int size) {
   bool found = false;
   for (int i = 0; i < size; i++) {
       if(books[i].isAvailable) {
           printBooks(books[i]);
           found = true;
       }
   }
   if (!found) {
       std::cout << "No available books found.\n";
   }
}


void borrowBook(Book books[], int size, std::string bookId ) {
   for (int i = 0; i < size; i++) {
       if (books[i].id == bookId) {
           if(books[i].isAvailable) {
               books[i].isAvailable = false;
               std::cout << "You borrowed \"" << books[i].title << "\".\n";
           } else {
               std::cout << books[i].title << "\" is already borrowed.\n";
           } 
           return;
       }
   }
   std::cout << "Book with ID " << bookId << " not found.\n";
}




int main(){
   Book books[10] = {
       {"BK001", "The Great Gatsby", "F. Scott Fitzgerald", true},
       {"BK002", "1984", "George Orwell", true},
       {"BK003", "To Kill a Mockingbird", "Harper Lee", true},
       {"BK004", "The Catcher in the Rye", "J.D. Salinger", true},
       {"BK005", "Moby Dick", "Herman Melville", false},
       {"BK006", "Pride and Prejudice", "Jane Austen", true},
       {"BK007", "The Hobbit", "J.R.R. Tolkien", false},
       {"BK008", "Brave New World", "Aldous Huxley", true},
       {"BK009", "War and Peace", "Leo Tolstoy", false},
       {"BK010", "Ulysses", "James Joyce", true}
   };
   int size = sizeof(books) / sizeof(books[0]);


   int menu = 0;
   std::string bookId = "";




   do {
       std::cout << "1. View All Books\n";
       std::cout << "2. Sort books by title (ASC)\n";
       std::cout << "3. Search for All Available Books\n";
       std::cout << "4. Borrow a Book\n";
       std::cout << "5. Exit\n";
       std::cout << "Enter your choice: ";
       std::cin >> menu;


       switch (menu)
       {
           case 1:
               std::cout << "\n--- All Books --- \n";
               displayAllBooks(books, size);
               std::cout << "\n";
               break;
           case 2:
               std::cout << "\n--- Sorted Books By Title --- \n";
               quickSortByTitle(books, 0, size - 1);
               displayAllBooks(books, size);
               std::cout << "\n";
               break;
           case 3:
               std::cout << "\n--- Available Books --- \n";
               searchAvailableBooks(books, size);
               std::cout << "\n";
               break;
           case 4:
               std::cout << "Please enter the book id: ";
               std::cin >> bookId;
               if(bookId.empty()) {
                   std::cout << "No available books found.\n";
                   break;
               }
               borrowBook(books, size, bookId);
               std::cout << "\n";
               break;
           case 5:
               std::cout << "Goodbye!\n";
               break;


           default:
               std::cout << "Invalid choice. Try again.\n";
       }
   } while (menu != 5);


   return 0;
}
