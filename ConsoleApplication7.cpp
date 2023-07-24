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
	bool capitaliseNext = true;
	char c_1 = 0;
	char c_2 = 0;

	for (int i = 0; str[i]; i++) {
		char c = str[i];


		if (i > 1) {
			c_1 = str[i - 1];
			c_2 = str[i - 2];
		}
		
		//Capitalise first character
		if (capitaliseNext && isalpha(c)) {
			properStr.push_back(toupper(c));
			capitaliseNext = false;
		}
		else if (c == ' ' || c == '.') {
			capitaliseNext = true;
			properStr.push_back(c);
		}

		else if (tolower(c_1) == 'm' && c == 'c' && c_2 == ' ') {
			capitaliseNext = true;
			properStr.push_back(c);
		}

		else if (tolower(c_1) == 'o' && c == '\'' && c_2 == ' ') {
			capitaliseNext = true;
			properStr.push_back(c);
		}

		else {
			properStr.push_back(tolower(c));
		}
		

	}

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
	void addBook(Book& book) {
		std::string proper_title = toProperCase(book.getTitle());
		std::string proper_author = toProperCase(book.getAuthor());
		int proper_year = book.getYear();

		Book proper_case_book(proper_title, proper_author, proper_year);

		books.push_back(proper_case_book);
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
	Book book1("The Fellowship of the Ring", "J.R.R. Tolkien", 1954);
	Book book2("The Two Towers", "J.R.R. Tolkien", 1954);
	Book book3("The Return of the King", "J.R.R. Tolkien", 1955);
	Book book4("amSterDaM", "IaN mcEwan", 1998);
	Book book5("The life of john wayne", "marcus o\'reilly", 2005);

	Library myLibrary;

	myLibrary.addBook(book1);
	myLibrary.addBook(book2);
	myLibrary.addBook(book3);
	myLibrary.addBook(book4);
	myLibrary.addBook(book5);
	myLibrary.listBooks();

	myLibrary.removeBook("THE FELLOWSHIP OF THE RING");

	myLibrary.listBooks();

	return 0;
}