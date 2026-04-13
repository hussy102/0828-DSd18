#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct action {
    string type;
    char ch;
    action(string t, char c) {
        type = t;
        ch = c;
    }
};
class texteditor {
private:
    string text;
    stack<action> undo_stack;
    stack<action> redo_stack;
public:
    void type_char(char c) {
        text.push_back(c);
        undo_stack.push(action("insert", c));
        while (!redo_stack.empty()) {
            redo_stack.pop();
        }
    }
    void delete_char() {
        if (!text.empty()) {
            char c = text.back();
            text.pop_back();
            undo_stack.push(action("delete", c));
            while (!redo_stack.empty()) {
                redo_stack.pop();
            }
        }
    }
    void undo() {
        if (!undo_stack.empty()) {
            action last = undo_stack.top();
            undo_stack.pop();
            if (last.type == "insert") {
                if (!text.empty()) {
                    text.pop_back();
                }
            }
            else {
                text.push_back(last.ch);
            }
                        redo_stack.push(last);
        }
    }
    void redo() {
        if (!redo_stack.empty()) {
            action last = redo_stack.top();
            redo_stack.pop();
            if (last.type == "insert") {
                text.push_back(last.ch);
            }
            else {
                if (!text.empty()) {
                    text.pop_back();
                }
            }
            undo_stack.push(last);
        }
    }
    void show() {
        cout << "text: " << text << endl;
    }
};
int main() {
    texteditor editor;
    int choice;
    char c;
    while (true) {
        cout << "\n";
        cout << "1 type\n";
        cout << "2 delete\n";
        cout << "3 undo\n";
        cout << "4 redo\n";
        cout << "5 show\n";
        cout << "6 exit";
        cout << "enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "enter character: ";
            cin >> c;
            editor.type_char(c);
            break;
        case 2:
            editor.delete_char();
            break;
        case 3:
            editor.undo();
            break;
        case 4:
            editor.redo();
            break;
        case 5:
            editor.show();
            break;
        case 6:
            return 0;
        default:
            cout << "invalid choice"<<endl;
        }
    }
}