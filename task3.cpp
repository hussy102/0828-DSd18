#include <iostream>
#include <string>
using namespace std;

class publication {
public:
    virtual void display() = 0;
};
class book :public publication {
public:
    string title;
    string author;
    int pages;
    book() {}
    book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
    void display() {
        cout << "book: " << title << " | " << author << " | " << pages << endl;
    }
};
class newspaper :public publication {
public:
    string name;
    string date;
    string edition;
    newspaper() {}
    newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }
    void display() {
        cout << "newspaper: " << name << " | " << date << " | " << edition << endl;
    }
};
template <typename t>
int linearsearch(t arr[], string key, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].title == key || arr[i].name == key) {
            return i;
        }
    }
    return -1;
}
template <typename t>
void bubblesort(t arr[], int size, bool bypages) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (bypages) {
                if (arr[j].pages > arr[j + 1].pages) {
                    swap(arr[j], arr[j + 1]);
                }
            }
            else {
                if (arr[j].edition > arr[j + 1].edition) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}
class library {
public:
    book books[10];
    newspaper newspapers[10];
    int bookcount = 0;
    int newspapercount = 0;
    void addbook(book b) {
        books[bookcount++] = b;
    }
    void addnewspaper(newspaper n) {
        newspapers[newspapercount++] = n;
    }
    void displaycollection() {
        cout << "books:";
        for (int i = 0; i < bookcount; i++) {
            books[i].display();
        }
        cout << "newspapers:";
        for (int i = 0; i < newspapercount; i++) {
            newspapers[i].display();
        }
    }
    void sortbooksbypages() {
        bubblesort(books, bookcount, true);
    }
    void sortnewspapersbyedition() {
        bubblesort(newspapers, newspapercount, false);
    }
    book* searchbookbytitle(string title) {
        int index = linearsearch(books, title, bookcount);
        if (index != -1) return &books[index];
        return nullptr;
    }
    newspaper* searchnewspaperbyname(string name) {
        for (int i = 0; i < newspapercount; i++) {
            if (newspapers[i].name == name) {
                return &newspapers[i];
            }
        }
        return nullptr;
    }
};
int main() {
    book book1("dsa", "hussnain", 277);
    book book2("how to stay awake in online class", "rasheed", 324);
    newspaper newspaper1("geoo", "2-7-34");
    newspaper newspaper2("hello kitty", "3-8-8");
    library library;
    library.addbook(book1);
    library.addbook(book2);
    library.addnewspaper(newspaper1);
    library.addnewspaper(newspaper2);
    cout << "before sorting:";
    library.displaycollection();
    library.sortbooksbypages();
    library.sortnewspapersbyedition();
    cout << "nafter sorting : ";
    library.displaycollection();
    book* foundbook = library.searchbookbytitle("dsa");
    if (foundbook) {
        cout << "found book:";
        foundbook->display();
    }
    else {
        cout << "not found.";
    }
    newspaper* foundnewspaper = library.searchnewspaperbyname("hello kitty");
    if (foundnewspaper) {
        cout << "found newspaper:";
        foundnewspaper->display();
    }
    else {
        cout << "newspaper not found.";
    }
    return 0;
}