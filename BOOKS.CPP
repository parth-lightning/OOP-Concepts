#include <iostream.h>
#include <conio.h>

class books {
    int book_id;
    char book_name[30];
    char author[30];
    int price;

public:
    void get_details(int a, char b[], char c[], int d);
    void print_details();
    int get_price(); // New function to get price
};

void books::get_details(int a, char b[], char c[], int d) {
    int i;
    book_id = a;

    for (i = 0; b[i] != '\0'; i++)
        book_name[i] = b[i];
    book_name[i] = '\0';

    for (i = 0; c[i] != '\0'; i++)
        author[i] = c[i];
    author[i] = '\0';

    price = d;
}

void books::print_details() {
    cout << book_id << ", " << book_name << ", " << author << ", " << price << "\n";
}

int books::get_price() {
    return price;
}

void inputting(books arr[], int i) {
    int a, d;
    char bname[30];
    char aname[30];
    cout << "Enter the book_id: ";
    cin >> a;
    cout << "Enter the book name: ";
    cin >> bname;
    cout << "Enter the author name: ";
    cin >> aname;
    cout << "Enter the price: ";
    cin >> d;

    arr[i].get_details(a, bname, aname, d);
}

int main() {
    int choice, r = 0, i;
    books b[30];

    while (1) {
        cout << "Menu:\n1. Add Entry\n2. Show Details\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            inputting(b, r);
            r++;
        }
        else if (choice == 2) {
            int total_price = 0;
            for (i = 0; i < r; i++) {
                b[i].print_details();
                total_price += b[i].get_price();
            }
            cout << "Total Price of all books: " << total_price << "\n";
        }
        else {
            cout << "End";
            break;
        }
    }
    getch();
    return 0;
}
