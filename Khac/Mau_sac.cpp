#include <iostream>
#include <conio.h>
#include <windows.h> 
using namespace std;

// Hàm thay đổi màu sắc chữ
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Lấy ra cửa sổ console đang tương tác
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // Màu mặc định là trắng
    const int WHITE = 15;
    const int RED = 12;
    const int GREEN = 10;
    const int YELLOW = 14;

    string input = "";
    char ch;
    const int MAX_LENGTH = 20;  

    setTextColor(GREEN);  // Đặt màu chữ là xanh lá cây
    cout << "Nhap day so (toi da " << MAX_LENGTH << " ky tu, cach nhau bang khoang trang): ";

    setTextColor(WHITE);  // Đặt lại màu chữ về trắng
    while (true) {
        ch = _getch(); 

        
        if ((isdigit(ch) || ch == ' ') && input.size() < MAX_LENGTH) {
            setTextColor(YELLOW);  // Đặt màu chữ là vàng khi nhập ký tự
            cout << ch;        
            input += ch;            
        }

        else if (ch == 8) { 
            if (!input.empty()) {
                cout << "\b \b";  
                input.pop_back();     
            }
        }

        else if (ch == '\r') { 
            if (!input.empty()) {
                setTextColor(GREEN);  
                break;  
            } else {
                setTextColor(RED);  // Đặt màu chữ là đỏ nếu chưa nhập ký tự nào
                cout << "\nVui long nhap it nhat 1 ky tu!\n";
                setTextColor(WHITE);  
                cout << "Nhap lai: " << input; 
            }
        }
    }

    setTextColor(GREEN);  // Đặt màu chữ là xanh lá cây
    cout << "\nDay so ban da nhap la: " << input << endl;

    setTextColor(WHITE);  
    return 0;
}
