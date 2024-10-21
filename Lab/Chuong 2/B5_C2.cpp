#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <regex>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

// Định nghĩa giá trị màu sắc
enum Color {
    GREEN = 10,
    BLUE = 11,
    RED = 12,
    YELLOW = 14,
    WHITE = 15
};

// Lớp Array
template<class DataType>
class Array {
private:
    DataType* _items;   // Con trỏ lưu mảng phần tử
    int _iSize;         // Số lượng phần tử hiện tại của mảng

public: 
    Array();                                // Khởi tạo mặc định
    Array(const Array<DataType> &other);    // Sao chép
    ~Array();                               // Hàm hủy

    void add(DataType item);                // Thêm phần tử item và mảng
    void print();                           // In mảng
    void clear();                           // Xóa mảng
    int size();                             // Lấy số phần tử của mảng

    int find(DataType item, int index = 0);     // Tìm chỉ số của phần tử item từ chỉ số index
    void removeAtIndex(int index);              // Xoá phần tử tại vị trí index
    bool removeAll(DataType item);              // Xoá hết phần tử có giá trị item
    DataType &getAt(int index);                 // Lấy giá trị của phần tử tại vị trí index

    Array<DataType> &operator = (const Array<DataType> &other);     // Sao chép
};

// Lớp sách
class Book {
private:
    string _strBookID;
    string _strBookTitle;
    int _iPublicationYear;
    int _iPrice;

public:
    Book();
    Book(string bookID, string bookTitle, int publicationYear, int price);
    Book(const Book &other);
    ~Book();

    string getBookID();
    void setBookID(string bookID);
    string getBookTitle();
    void setBookTitle(string bookTitle);
    int getPublicationYear();
    void setPublicationYear(int publicationYear);
    int getPrice();
    void setPrice(int price);

    friend ostream &operator << (ostream &out, Book other);
};

// Lớp chương trình
class Program {
private:
    Array<Book> _bookList;
    int countDigit(string input);                           // Đếm số phần tử số hợp lệ trong chuỗi đầu vào
    void setTextColor(int color);                           // Đổi màu chữ hiển thị trên console
    Book inputBook();

public:
    void inputBookList();
    void printBookList();
    void updateBookPrice();
    void deleteBook();
    void sortBooksByIDAsc();
    void sortBooksByPublicationYearDesc();
    void sortBooksByTitleAsc();
    void sortBooksByPriceDesc();
    void displayMenu();
    void run();
};

int main() {
    Program program;
    program.run();  // Chạy chương trình
    return 0;
}

/***************************************************************************
* @Description khởi tạo mặc định.
* @attention: cấp phát 1000 phần tử.
****************************************************************************/
template<class DataType>
Array<DataType>::Array() {
    _iSize = 0;
    _items = new DataType[1000];    // Cấp phát 1000 phần tử
}

template<class DataType>
Array<DataType>::Array(const Array<DataType> &other) {
    _iSize = other._iSize;
    _items = new DataType[1000];

    for (int i = 0; i < other._iSize; i++) 
        _items[i] = other._items[i];
}

/***************************************************************************
* @Description hàm hủy.
* @attention: xóa cấp phát.
****************************************************************************/
template<class DataType>
Array<DataType>::~Array() {
    delete[] _items;
}

/***************************************************************************
* @Description thêm phần tử item vào cuối mảng.
* @param item: phần tử cần thêm.
* @attention: thêm phần tử vào chỉ số size, tăng size sau khi thêm.
****************************************************************************/
template<class DataType>
void Array<DataType>::add(DataType item) {
    _items[_iSize] = item;
    _iSize++;
}

/***************************************************************************
* @Description in các phần tử của mảng.
* @attention: duyệt từng phần tử và in ra giá trị của phần tử.
****************************************************************************/
template<class DataType>
void Array<DataType>::print() {
    for (int i = 0; i < _iSize; i++)
        cout << _items[i];
}

/***************************************************************************
* @Description xóa mảng.
* @attention: đặt số lượng phần tử về 0,các phần tử về 0.
****************************************************************************/
template<class DataType>
void Array<DataType>::clear() {
    for (int i = 0; i < _iSize; i++)
        _items[i] = 0;
    _iSize = 0;
}

/***************************************************************************
* @Description lấy số phần tử của mảng.
* @return: số lượng phần tử của mảng.
****************************************************************************/
template<class DataType>
int Array<DataType>::size() {
    return _iSize;
}

/***************************************************************************
* @Description tìm chỉ số của phần tử item, bắt đầu từ vị trí index.
* @param item: phần tử cần tìm.
* @param index: vị trí bắt đầu tìm.
* @attention: index có giá trị mặc định là 0.
* @attention: duyệt từ i = index đến hết mảng và so sánh từng phần tử.
* @return: chỉ số của phần tử cần tìm hoặc -1 nếu không tìm thấy. 
****************************************************************************/
template<class DataType>
int Array<DataType>::find(DataType item, int index) {
    for (int i = index; i < _iSize; i++)
        if (_items[i] == item)
            return i;
    return -1;
}

/***************************************************************************
* @Description xóa phần tử tại vị trí Index.
* @param index: vị trí cần xóa phần tử.
* @attention: duyệt từ i = index, cho phần tử thứ i bằng phần tử i + 1.
* @attention: giảm số lượng phần tử của mảng sau khi xóa.
****************************************************************************/
template<class DataType>
void Array<DataType>::removeAtIndex(int index) {
    for (int i = index; i < _iSize - 1; i++)
        _items[i] = _items[i + 1];
    _iSize--;
}

/***************************************************************************
* @Description xóa tất cả phần tử có giá trị bằng với item.
* @param item: giá trị phần tử cần xóa.
* @attention: tìm vị trí của phần tử đó trong mảng, nếu có thì tiến hành xóa.
* @return true nếu xóa thành công, false nếu không xóa phần tử nào.
****************************************************************************/
template<class DataType>
bool Array<DataType>::removeAll(DataType item) {
    bool bResult = false;
    int iIndex = find(item);            // Tìm vị trí đầu tiên của item

    while (iIndex != -1) {
        removeAtIndex(iIndex);          // Xóa phần tử tại chỉ số tìm được
        iIndex = find(item, iIndex);    // Tìm tiếp phần tử
        bResult = true;
    }

    return bResult;
}

/***************************************************************************
* @Description hàm lấy giá trị của phần tử tại vị trí index.
* @param index: vị trí của phần tử cần lấy giá trị.
* @return: trả về tham chiếu đến giá trị tại vị trí index trong mảng items.
****************************************************************************/
template<class DataType>
DataType &Array<DataType>::getAt(int index) {
    return _items[index];
}

template<class DataType>
Array<DataType> &Array<DataType>::operator = (const Array<DataType> &other) {
    if (this == &other) 
        return *this;

    _iSize = other._iSize;
    _items = new DataType[1000];

    for (int i = 0; i < other._iSize; i++) 
        _items[i] = other._items[i];

    return *this;
}

Book::Book() {
    _strBookID = _strBookTitle = "";
    _iPublicationYear = _iPrice = 0;
}

Book::Book(string bookID, string bookTitle, int publicationYear, int price) {
    _strBookID = bookID;
    _strBookTitle = bookTitle;
    _iPublicationYear = publicationYear;
    _iPrice = price;
}

Book::Book(const Book &other) {
    _strBookID = other._strBookID;
    _strBookTitle = other._strBookTitle;
    _iPublicationYear = other._iPublicationYear;
    _iPrice = other._iPrice;
}

Book::~Book() {
    // Không cần định nghĩa
}

string Book::getBookID() {
    return _strBookID;
}

void Book::setBookID(string bookID) {
    _strBookID = bookID;
}

string Book::getBookTitle() {
    return _strBookTitle;
}

void Book::setBookTitle(string bookTitle) {
    _strBookTitle = bookTitle;
}   

int Book::getPublicationYear() {
    return _iPublicationYear;
}

void Book::setPublicationYear(int publicationYear) {
    _iPublicationYear = publicationYear;
}

int Book::getPrice() {
    return _iPrice;
}

void Book::setPrice(int price) {
    _iPrice = price;
}

ostream &operator << (ostream &out, Book other) {
    out << "Mã sách: " << other._strBookID << endl;
    out << "Tựa sách: " << other._strBookTitle << endl;
    out << "Năm xuất bản: " << other._iPublicationYear << endl;
    out << "Giá: " << other._iPrice << endl;
    return out;
}

/***************************************************************************
* @Description đếm các số có trong chuỗi input.
* @param input: chuỗi chứa các số.
* @attention: chuyển chuỗi thành luồng mới và thực hiện đếm số.
* @return số lượng chữ số có trong luồng.
****************************************************************************/
int Program::countDigit(string input) {
    int iItem, iCount = 0;
    stringstream inStream(input);

    while (inStream >> iItem) 
        iCount++;   // Đếm số lượng phần tử hợp lệ

    return iCount;
}

/***************************************************************************
* @Description thiết lập mã màu chữ trên màn hình console.
* @param color: mã màu.
* @attention: lấy ra đối tượng màn hình console hiện tại và thiết lập màu sắc.
****************************************************************************/
void Program::setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hConsole, color);   // Đặt màu chữ trên console
}

Book Program::inputBook() {
    string strBookID, strBookTitle;
    int iPublicationYear, iPrice;

    char cKey;
    string strInput;

    // Nhập mã sách
    setTextColor(BLUE);
    cout << "≫ Nhập mã sách: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalnum(cKey) && strBookID.size() < 6) {
            cout << cKey;
            strBookID += cKey;
        }

        else if (cKey == 8) {
            if (!strBookID.empty()) {
                cout << "\b \b";
                strBookID.pop_back();
            }
        }

        else if (cKey == '\r' && !strBookID.empty()) {
            cout << endl;
            break;
        }
    }
    
    // Nhập tên sách
    setTextColor(BLUE);
    cout << "≫ Nhập tên sách: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if ((isalnum(cKey) || cKey == ' ') && strBookTitle.size() < 30) {
            cout << cKey;
            strBookTitle += cKey;
        }

        else if (cKey == 8) {
            if (!strBookTitle.empty()) {
                cout << "\b \b";
                strBookTitle.pop_back();
            }
        }

        else if (cKey == '\r' && !strBookTitle.empty()) {
            cout << endl;
            break;
        }
    }

    // Nhập năm xuất bản
    setTextColor(BLUE);
    cout << "≫ Nhập năm xuất bản: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey)) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && !strInput.empty() && stoi(strInput) > 1900) {
            cout << endl;
            break;
        }
    }

    iPublicationYear = stoi(strInput);
    strInput.clear();

    // Nhập giá bán
    setTextColor(BLUE);
    cout << "≫ Nhập giá bán: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && strInput.size() < 5) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && !strInput.empty()) {
            cout << endl;
            break;
        }
    }

    iPrice = stoi(strInput);

    Book book(strBookID, strBookTitle, iPublicationYear, iPrice);
    return book;
}


void Program::inputBookList() {
    int iSize;
    char cKey;
    string strInput;

    setTextColor(BLUE);
    cout << "≫ Số lượng sách cần nhập: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && cKey >= '1') {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && !strInput.empty()) {
            cout << endl << endl;
            break;
        }
    }

    iSize = stoi(strInput);
    strInput.clear();

    for (int i = 1; i <= iSize; i++) {
        Book book;
        bool bIsValid = true;

        while (true) {
            setTextColor(YELLOW);
            cout << "≫ Nhập thông tin sách thứ " << i << " -----------------------\n";

            book = inputBook();

            for (int i = 0; i < _bookList.size(); i++) {
                if (_bookList.getAt(i).getBookID() == book.getBookID()) {
                    setTextColor(RED);
                    cout << "≫ Mã sách này đã tồn tại trong danh sách!\n";
                    cout << "≫ Vui lòng nhập lại thông tin sách này!\n\n";
                    bIsValid = false;
                    break;
                }

                if (i == _bookList.size() - 1) 
                    bIsValid = true;
            }

            if (!bIsValid) 
                continue;

            _bookList.add(book);
        }

        setTextColor(GREEN);
        cout << "≫ Đã thêm sách " + book.getBookTitle() + "!\n\n";
    }
} 

void Program::printBookList() {
    if (_bookList.size() == 0) {
        setTextColor(RED);
        cout << "≫ Không có thông tin sách nào trong danh sách!" << endl;
        return;
    }

    setTextColor(GREEN);
    cout << "≫ Thông tin sách hiện có:" << endl;

    setTextColor(YELLOW);
    _bookList.print();
}

void Program::updateBookPrice() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::deleteBook() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::sortBooksByIDAsc() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::sortBooksByPublicationYearDesc() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::sortBooksByTitleAsc() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::sortBooksByPriceDesc() {
    // TODO: viết định nghĩa theo yêu cầu đề bài
}

void Program::displayMenu() {
    setTextColor(GREEN);
    cout << "-------------------Chương trình quản lý sách--------------------" << endl;
    cout << "1. Nhập thêm thông tin sách vào danh sách." << endl;
    cout << "2. In danh sách hiện tại." << endl;  
    cout << "3. Sửa giá của cuốn sách theo tên sách." << endl;    
    cout << "4. Xóa cuốn sách theo mã sách." << endl;
    cout << "5. Sắp xếp tăng dần theo mã sách." << endl;
    cout << "6. Sắp xếp giảm dần theo năm xuất bản." << endl;
    cout << "7. Sắp xếp tăng dần theo tên sách." << endl;
    cout << "8. Sắp xếp giảm giần theo giá sách." << endl;
    cout << "9. Thoát chương trình." << endl;
    cout << "----------------------------------------------------------------" << endl;
}


void Program::run() {
    // TODO: viết hàm chính
}
