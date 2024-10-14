#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
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
    Array();                    // Khởi tạo mặc định
    ~Array();                   // Hàm hủy
    void add(DataType item);    // Thêm phần tử item và mảng
    void print();               // In mảng
    void clear();               // Xóa mảng
    int size();                // Lấy số phần tử của mảng

    int find(DataType item, int index = 0); // Tìm chỉ số của phần tử item từ chỉ số index
    void removeAtIndex(int index);          // Xoá phần tử tại vị trí index
    bool removeAll(DataType item);          // Xoá hết phần tử có giá trị item
    DataType getAt(int index);              // Lấy giá trị của phần tử tại vị trí index
    void sortAsc();                         // Hàm sắp xếp tăng dần mảng
};

// Lớp chương trình
class Program {
private:
    Array<int> _array;              // Đối tượng mảng để lưu trữ các phần tử
    int countDigit(string input);   // Đếm số phần tử số hợp lệ trong chuỗi đầu vào
    void setTextColor(int color);   // Đổi màu chữ hiển thị trên console
    bool checkSortedAsc();          // Hàm kiểm tra xem mảng đã sắp xếp tăng dần hay chưa

public:
    int inputSizeArray();           // Nhập số lượng phần tử mảng
    void inputItemArray(int size);  // Nhập các phần tử của mảng
    void outputArray();             // In các phần tử của mảng
    void removeItem();              // Xóa phần tử trong mảng
    void printItemPositions();      // In ra tất cả vị trí của một phần tử
    void binSearchSteps();          // Hàm thực hiện in các bước tìm kiếm nhị phân
    void run();                     // Hàm điều khiển chính của chương trình
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
    _items = new DataType[1000];    // Giới hạn 1000 phần tử
}

/***************************************************************************
* @Description hàm hủy.
* @attention: gọi đến hàm clear.
****************************************************************************/
template<class DataType>
Array<DataType>::~Array() {
    this->clear();
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
        cout << _items[i] << ' ';

    // trường hợp mảng trống
    if (_iSize == 0) 
        cout << "empty!";

    cout << endl;
}

/***************************************************************************
* @Description xóa mảng.
* @attention: đặt số lượng phần tử về 0, xóa cấp phát.
****************************************************************************/
template<class DataType>
void Array<DataType>::clear() {
    _iSize = 0;
    delete[] _items;
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
* @return: trả về giá trị tại vị trí index trong mảng items.
****************************************************************************/
template<class DataType>
DataType Array<DataType>::getAt(int index) {
    return _items[index];
}

/***************************************************************************
* @Description hàm sắp xếp tăng dần.
* @attention: sắp xếp theo thuật toán sắp xếp chèn (insertion sort).
****************************************************************************/
template<class DataType>
void Array<DataType>::sortAsc() {
    for (int i = 1; i < _iSize; i++) {
        int j = i;
        while (j > 0 && _items[j-1] > _items[j]) {
            swap(_items[j-1], _items[j]);
            j--;
        }
    }
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

/***************************************************************************
* @Description kiểm tra xem mảng đã sắp xếp tăng dần hay chưa.
* @attention: duyệt qua các phần tử của mảng để kiểm tra.
* @return: true nếu mảng đã sắp xếp tăng dần, false nếu mảng có cặp nghịch thế.
****************************************************************************/
bool Program::checkSortedAsc() {
    for (int i = 1; i < _array.size(); i++) 
        if (_array.getAt(i-1) > _array.getAt(i))
            return false;
    return true;
}

/***************************************************************************
* @Description nhập số lượng phần tử vào mảng.
* @attention: thực hiện ràng buộc dữ liệu, chỉ cho nhập số, gọi đến các hàm xử lý liên quan.
* @return: số lượng phần tử được nhập.
****************************************************************************/
int Program::inputSizeArray() {
    char cKey;
    int iSize;
    string strInput = "";

    setTextColor(BLUE);
    cout << "≫ Nhập số lượng phần tử của mảng: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();    // Đọc ký tự nhập vào

        // Nếu là ký tự số
        if (isdigit(cKey)) {
            cout << cKey;
            strInput += cKey;
        }
        
        // Nếu là phím Backspace
        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        // Nếu là phím Enter
        else if (cKey == '\r' && strInput.size() > 0) {
            cout << endl;
            break;
        }
    }

    iSize = stoi(strInput);     // Chuyển chuỗi thành số nguyên
    return iSize;
}

/***************************************************************************
* @Description nhập số lượng phần tử và các phần tử vào mảng.
* @param size: số lượng phần tử của mảng.
* @attention: thực hiện ràng buộc dữ liệu, chỉ cho nhập số, gọi đến các hàm xử lý liên quan.
****************************************************************************/
void Program::inputItemArray(int size) {
    int iItem;
    char cKey;
    string strInput = "";

    setTextColor(BLUE);
    cout << "≫ Nhập các phần tử của mảng: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        // Kiểm tra điều kiện nhập hợp lệ
        if ((isdigit(cKey) || (cKey == ' ' && strInput.back() != '-') || (cKey == '-' && (strInput.empty() || strInput.back() == ' '))) && countDigit(strInput) < size) {
            cout << cKey;
            strInput += cKey;
        }

        // Xử lý phím Backspace
        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        // Nhấn Enter khi đủ phần tử
        else if (cKey == '\r' && countDigit(strInput) > 0) { 
            cout << endl;
            break;
        }
    }

    stringstream inStream(strInput);
    while (inStream >> iItem)
        _array.add(iItem);      // Thêm từng phần tử vào mảng
}

/***************************************************************************
* @Description in ra mảng hiện tại.
* @attention: duyệt qua các phần tử trong mảng và in ra màn hình
****************************************************************************/
void Program::outputArray() {
    setTextColor(BLUE);
    cout << "≫ Mảng hiện tại: ";

    setTextColor(YELLOW);
    _array.print();
}

/***************************************************************************
* @Description nhập vào số cần xóa.
* @attention: ràng buộc dữ liệu chỉ được nhập số.
* @attention: thực hiện xóa, in ra thông náo nếu xóa thành công/không thành công.
****************************************************************************/
void Program::removeItem() {
    char cKey;
    int iItem;
    string strInput = "";

    setTextColor(BLUE);
    cout << "≫ Nhập phần tử cần xóa: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) || (cKey == '-' && (strInput.empty() || strInput.back() == ' '))) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && strInput.size() > 0) {
            cout << endl;
            break;
        }
    }

    iItem = stoi(strInput);
    if (_array.removeAll(iItem)) {
        setTextColor(GREEN);
        cout << "≫ Đã xóa thành công!" << endl;
    }

    else {
        setTextColor(RED);
        cout << "≫ Không có phần tử này trong mảng!" << endl;
    }
}

/***************************************************************************
* @Description in ra tất cả vị trí xuất hiện của một phần tử trong mảng.
* @attention: ràng buộc dữ liệu chỉ được nhập số, nhập vào phần tử cần tìm.
* @attention: thực hiện in tất cả vị trí xuất hiện nếu tìm thấy phần tử đó trong mảng.
****************************************************************************/
void Program::printItemPositions() {
    char cKey;
    int iItem;
    string strInput = "";

    setTextColor(BLUE);
    cout << "≫ Nhập phần tử cần in vị trí: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) || (cKey == '-' && (strInput.empty() || strInput.back() == ' '))) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && strInput.size() > 0) {
            cout << endl;
            break;
        }
    }

    iItem = stoi(strInput);
    int iIndex = _array.find(iItem);

    if (iIndex == -1) {
        setTextColor(RED);
        cout << "≫ Không có phần tử này trong mảng!" << endl;
        return;
    }

    setTextColor(GREEN);
    cout << "≫ Các vị trí xuất hiện trong mảng: ";

    setTextColor(YELLOW);
    while (iIndex != -1) {
        cout << iIndex << ' ';
        iIndex = _array.find(iItem, iIndex + 1);
    }

    cout << endl;
}

/***************************************************************************
* @Description in ra các bước thực hiện tìm kiếm nhị phân trong mảng.
* @attention: ràng buộc dữ liệu chỉ được nhập số, nhập vào phần tử cần tìm.
* @attention: kiểm tra xem mảng có sắp xếp tăng dần hay chương, nếu chưa thì tự động sắp xếp.
* @attention: thực hiện tìm kiếm nhị phân và in ra từng bước.
****************************************************************************/
void Program::binSearchSteps() {
    if (!checkSortedAsc()) {
        setTextColor(RED);
        cout << "≫ Mảng chưa được sắp xếp, sẽ tự động sắp xếp tăng dần..." << endl;
        _array.sortAsc();
        outputArray();
    }

    char cKey;
    int iItem;
    string strInput = "";

    setTextColor(BLUE);
    cout << "≫ Nhập phần tử cần tìm kiếm: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) || (cKey == '-' && (strInput.empty() || strInput.back() == ' '))) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && strInput.size() > 0) {
            cout << endl;
            break;
        }
    }

    iItem = stoi(strInput);
    int iCount = 1;     // Số lần chia đôi
    int iLeft = 0, iRight = _array.size();

    while (iLeft <= iRight) {
        cout << "≫ Lần " << iCount << ": x = " << iItem << " nằm trong đoạn [" << iLeft << ".." << iRight << "]" << endl;
        
        int iMid = (iLeft + iRight) >> 1;
        iCount++;

        if (_array.getAt(iMid) == iItem) {
            setTextColor(GREEN);
            cout << "≫ Tìm thấy tại vị trí: " << iMid << endl;
            return;
        }

        if (_array.getAt(iMid) < iItem)
            iLeft = iMid + 1;
        else    
            iRight = iMid - 1;
    }

    setTextColor(RED);
    cout << "≫ Không tìm thấy phần tử!" << endl;
}

/***************************************************************************
* @Description hàm chạy chương trình.
* @attention: gọi đến các hàm thành phần của chương trình.
****************************************************************************/
void Program::run() {
    setTextColor(WHITE);    
    SetConsoleOutputCP(CP_UTF8);    // Thiết lập mã hóa để console hỗ trợ tiếng Việt

    int iSize = inputSizeArray();
    inputItemArray(iSize);

    outputArray();
    binSearchSteps();

    setTextColor(WHITE);
    cout << "≫ Nhấn phím bất kỳ để đóng chương trình!";
    getch();
}