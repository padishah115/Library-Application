#include <iostream>
#include <string>
#include <vector>

//TO DO- Strip "the" from book beginnings
//Allow user input, standardise capital letters.

std::string toLowerCase(const std::string& str) {
	std::string lowerStr;
	for (char c : str) {
		lowerStr.push_back(tolower(c));
	}

	return lowerStr;
}


std::string toProperCase(const std::string& str) {
	std::string properStr;

	return properStr;
}


class Book{
private:
	std::string title;
	std::string author;
	int year;

public:
	//Constructor
	Book() {
		title = "";
		author = "";
		year = 0;
	}

	//Constructor with arguments
	Book(const std::string& title, const std::string& author, int year) :
		title(title), author(author), year(year){}

	//Accessor
	std::string getTitle() { return title; }
	std::string getAuthor() { return author; }
	int getYear() { return year; }

	std::string getTitle_Lower() const{
		return toLowerCase(title);
	}

	//Print the book
	void printBook() {
		std::cout << title << ", written by " << author << ", published in "
			<< year << ".\n";
	}
	

};

class Library {
private:
	//list of all books in library
	std::vector<Book> books;

public:

	//List books
	void listBooks() {
		std::cout << "The list of books in your library: \n";
		for (Book x : books) {
			x.printBook();
		}
		std::cout << "\n";
	}

	//Add books
	void addBook(const Book& book) {
		books.push_back(book);
	}

	/*void addBook(const Book& book1){
		std::string properTitle = toProperCase(book1.getTitle());
		std::string properAuthor = toProperCase(book1.getAuthor());
		int properYear = book1.year;

		Book new_book();
		books.push_back(new_book);
	}*/

	//Remove book
	void removeBook(const std::string& title) {
		std::string title_lower = toLowerCase(title);

		for (auto it = books.begin(); it != books.end(); ++it) {
			if (it->getTitle_Lower() == title_lower) {
				books.erase(it);
				return;
			}
		}

		std::cout << "Could not find the title in the library.\n";

	}

};

int main() {
	Book book1("The Fellowship of the Ring", "JRR Tolkien", 1954);
	Book book2("The Two Towers", "JRR Tolkien", 1954);
	Book book3("The Return of the King", "JRR Tolkien", 1955);

	Library myLibrary;

	myLibrary.addBook(book1);
	myLibrary.addBook(book2);
	myLibrary.addBook(book3);
	myLibrary.listBooks();

	myLibrary.removeBook("THE FELLOWSHIP OF THE RING");

	myLibrary.listBooks();


	return 0;
}