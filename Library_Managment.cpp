#include <vector>
#include <iostream>
using namespace std;
class Book
{
private:
    int id;
    string name;
    string author;

public:
    Book(int id, string name, string author)
    {
        this->id = id;
        this->name = name;
        this->author = author;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getAuthor()
    {
        return author;
    }
};
class Library
{
public:
    vector<Book> books;
    void addBook(Book book)
    {
        books.push_back(book);
    }
    void deleteBook(int id)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getId() == id)
            {
                books.erase(books.begin() + i);
                break;
            }
        }
    }
    void updateBook(int id, Book book)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getId() == id)
            {
                books[i] = book;
                break;
            }
        }
    }
    void displayBooks()
    {
        for (int i = 0; i < books.size(); i++)
        {
            cout << "ID: " << books[i].getId() << endl;
            cout << "Name: " << books[i].getName() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
        }
    }
};
int main()
{
    cout << "Library Management System" << endl;
    Library library;
    while (true)
    {
        cout << "1. Add Book" << endl;
        cout << "2. Delete Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int id;
            string name;
            string author;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Author: ";
            getline(cin, author);
            Book book(id, name, author);
            library.addBook(book);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            library.deleteBook(id);
        }
        else if (choice == 3)
        {
            int id;
            string name;
            string author;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Author: ";
            getline(cin, author);
            Book book(id, name, author);
            library.updateBook(id, book);
        }
        else if (choice == 4)
        {
            library.displayBooks();
        }
        else if (choice == 5)
        {
            break;
        }
    }

    return 0;
}
