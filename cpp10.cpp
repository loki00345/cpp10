#include <iostream>

using namespace std;

class String {
private:
    static const int DEFAULT_SIZE = 80;
    char* str;
    static int count;

public:
    String() : str(new char[DEFAULT_SIZE + 1]) {
        count++;
        str[0] = '\0';
    }

    String(int size) : str(new char[size + 1]) {
        count++;
        str[0] = '\0'; 
    }

    String(const char* s) {
        int len = 0;
        const char* p = s;
        while (*p++) {
            len++;
        }

        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';

        count++;
    }

    ~String() {
        delete[] str;
        count--;
    }

    void inputString() {
        cout << "Enter a string: ";
        cin.getline(str, DEFAULT_SIZE + 1);
    }

    void displayString() {
        cout << "String: " << str << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String s1;
    s1.inputString();
    s1.displayString();

    String s2(50);
    s2.inputString();
    s2.displayString();

    const char* input = "Hello, world!";
    String s3(input);
    s3.displayString();

    cout << "Number of String objects created: " << String::getCount() << endl;

    return 0;
}
