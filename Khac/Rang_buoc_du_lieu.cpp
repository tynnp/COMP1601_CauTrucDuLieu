#include <iostream>
#include <conio.h> 
#include <cctype> 
using namespace std; 

int main() {
    string input = "";
    char ch;
    const int MAX_LENGTH = 10;  

    cout << "Nhap so (toi da 10 ky tu): ";

    while (true) {
        ch = _getch(); 

        // Kiểm tra 
        if ((isdigit(ch)) && input.size() < MAX_LENGTH) {
            cout << ch;  
            input += ch;      
        }

        // Backspace
        else if (ch == 8) { 
            if (!input.empty()) {
                cout << "\b \b";  
                input.pop_back();      
            }
        }

        // Enter
        else if (ch == '\r' && input.size() == MAX_LENGTH) { 
            break; 
        }
    }

    cout << "\nSo ban nhap la: " << input << endl;
    return 0;
}
