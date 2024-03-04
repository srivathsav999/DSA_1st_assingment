#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int numberOfCopies;
    Book* next_book;

    Book(string t, string a, int copies) : title(t), author(a), numberOfCopies(copies), next_book(nullptr) {}
};

void addBook(Book*& head, string title, string author, int copies) {
    Book* currentBook = head;
    
    while (currentBook) {
        if (currentBook->title == title) {
            currentBook->numberOfCopies += copies;
            cout << "Book already exists. Added " << copies << " copies to the existing number of copies." << endl;
            return;
        }
        currentBook = currentBook->next_book;
    }

    Book* newBook = new Book(title, author, copies);

    if (!head) {
        head = newBook;
    } else {
        currentBook = head;
        while (currentBook->next_book) {
            currentBook = currentBook->next_book;
        }
        currentBook->next_book = newBook;
    }

    cout << "Book added successfully." << endl;
}

void removeBook(Book*& head, string title) {
    if (!head) {
        cout << "Library is empty. Cannot remove book." << endl;
        return;
    }

    if (head->title == title) {
        Book* temp = head;
        return;
    }

    Book* currentBook = head;
    while (currentBook->next_book && currentBook->next_book->title != title) {
        currentBook = currentBook->next_book;
    }

    if (currentBook->next_book) {
        Book* temp = currentBook->next_book;
        currentBook->next_book = currentBook->next_book->next_book;
        delete temp;
        cout << "Book removed successfully." << endl;
    } else {
        cout << "Book not found in the library." << endl;
    }
}

void searchByTitle(Book* head, string title) {
    Book* currentBook = head;
    while (currentBook) {
        if (currentBook->title == title) {
            cout << "Book found: " << currentBook->title << " by " << currentBook->author << ", Copies: " << currentBook->numberOfCopies << endl;
            return;
        }
        currentBook = currentBook->next_book;
    }
    cout << "Book not found in the library." << endl;
}

void displayAllBooks(Book* head) {
    Book* currentBook = head;
    while (currentBook) {
        cout << "Title: " << currentBook->title << ", Author: " << currentBook->author << ", Copies: " << currentBook->numberOfCopies << endl;
        currentBook = currentBook->next_book;
    }
}

int main() {
    Book* library = nullptr;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search by Title" << endl;
        cout << "4. Display All Books" << endl;
        cout << "0. Exit" << endl;


        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int copies;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                addBook(library, title, author, copies);
                break;
            }
            case 2: {
                string title;
                cout << "Enter the title of the book to remove: ";
                cin.ignore();
                getline(cin, title);
                removeBook(library, title);
                break;
            }
            case 3: {
                string title;
                cout << "Enter the title of the book to search: ";
                cin.ignore();
                getline(cin, title);
                searchByTitle(library, title);
                break;
            }
            case 4:
                displayAllBooks(library);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}