#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
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

template<class DataType> 
class LinkedList;

// Lớp template Node đại diện cho từng phần tử trong danh sách liên kết
template<class DataType>
class Node {
    friend LinkedList<DataType>;

private:
    DataType _data;                                                     // Dữ liệu được lưu trữ trong node
    Node* _pNext;                                                       // Con trỏ trỏ đến node tiếp theo trong danh sách

public:
    Node(DataType data);                                                // Hàm khởi tạo với dữ liệu cho trước
    void display();                                                     // Phương thức hiển thị dữ liệu của node
};

// Lớp template LinkedList để quản lý danh sách liên kết 
template<class DataType>
class LinkedList {
private:
    Node<DataType>* _pHead;                                                 // Con trỏ trỏ đến node đầu tiên trong danh sách
    Node<DataType>* _pTail;                                                 // Con trỏ trỏ đến node cuối cùng trong danh sách
    int _iSize;                                                             // Kích thước của danh sách (số lượng phần tử)

public: 
    LinkedList();                                                           // Hàm khởi tạo
    ~LinkedList();                                                          // Hàm hủy để xóa danh sách và giải phóng bộ nhớ
    LinkedList(const LinkedList<DataType> &other);                          // Hàm sao chép

    void addFront(DataType data);                                           // Phương thức thêm phần tử vào đầu danh sách
    void addBack(DataType data);                                            // Phương thức thêm phần tử vào cuối danh sách
    DataType getFront();                                                    // Phương thức lấy phần tử ở đầu danh sách
    DataType getBack();                                                     // Phương thức lấy phần tử ở cuối danh sách
    DataType getAt(int index);                                              // Phương thức lấy phần tử tại vị trí index
    void setAt(int index, DataType data);                                   // Phương thức cập nhật phần tử tại vị trí index            
    void insertAt(int index, DataType data);                                // Phương thức chèn phần tử vào vị trí index
    void removeAt(int index);                                               // Phương thức xóa phần tử tại vị trí index
    int find(DataType data);                                                // Phương thức tìm kiếm phần tử và trả về chỉ số hiện tại
    void remove(DataType data);                                             // Phương thức xóa phần tử đầu tiên có giá trị cho trước
    void clear();                                                           // Phương thức xóa toàn bộ danh sách
    int size();                                                             // Phương thức trả về kích thước của danh sách
    bool empty();                                                           // Phương thức kiểm tra danh sách có rỗng không
    void display();                                                         // Phương thức hiển thị các phần tử trong danh sách

    void sortAsc();                                                         // Phương thức sắp xếp danh sách tăng dần 
    void sortDesc();                                                        // Phương thức sắp xếp danh sách giảm dần
    void reverse();                                                         // Phương thức đảo ngược danh sách
    void unique();                                                          // Phương thức xóa các phần tử trùng lặp trong danh sách
    void sortHalfAscDesc();                                                 // Phương thức sắp xếp nửa đầu danh sách tăng dần, nửa sau giảm dần     
    bool contains(DataType data);                                           // Phương thức kiểm tra danh sách có chứa phần tử với giá trị cho trước không
    int count(DataType data);                                               // Phương thức đếm số lần xuất hiện của phần tử có giá trị cho trước

    LinkedList<DataType> unionWith(LinkedList<DataType> &other);            // Phương thức tạo danh sách hợp (union) của hai danh sách
    LinkedList<DataType> intersectWith(LinkedList<DataType> &other);        // Phương thức tạo danh sách giao (intersection) của hai danh sách
    LinkedList<DataType> differenceWith(LinkedList<DataType> &other);       // Phương thức tạo danh sách hiệu (difference) của hai danh sách
    LinkedList<DataType> merge(LinkedList<DataType> &other);                // Phương thức gộp hai danh sách thành một
    LinkedList<DataType> sumLists(LinkedList<DataType> &other);             // Phương thức tính tổng hai danh sách theo từng phần tử

    LinkedList<DataType> &operator = (const LinkedList<DataType> &other);   // Toán tử gán    
};

// TODO: Viết comment cho lớp Program
class Program {
private:
    LinkedList<int> _L1;
    LinkedList<int> _L2;

    void displayMenu();
    void setTextColor(int color);
    int countDigit(string input);
    int selectOption();
    void endOption();
    int inputNumber(const string &prompt);
    void inputList(const int &size, const string &prompt, int option);

public:
    void run();
    void inputLists();
    void createDifferenceList();
    void createIntersectList();
    void createUnionList();
};

int main() {
    Program program;
    program.run();
    return 0;
}

// TODO: Viết comment cho hàm 
template<class DataType>
Node<DataType>::Node(DataType data) {
    _data = data;
    _pNext = nullptr;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void Node<DataType>::display() {
    cout << _data << ' ';
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType>::LinkedList() {
    _pHead = _pTail = nullptr;
    _iSize = 0;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType>::~LinkedList() {
    clear();
}

// TODO: Viết comment cho hàm
template<class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType> &other) {
    _iSize = 0;
    _pHead = _pTail = nullptr;

    Node<DataType>* pWalker = other._pHead;
    while (pWalker != nullptr) {
        this->addBack(pWalker->_data);
        pWalker = pWalker->_pNext;
    }
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::addFront(DataType data) {
    Node<DataType>* newNode = new Node<DataType>(data);

    if (empty()) {
        _pHead = _pTail = newNode;

    } else {
        newNode->_pNext = _pHead;
        _pHead = newNode;
    }

    _iSize++;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::addBack(DataType data) {
    Node<DataType>* newNode = new Node<DataType>(data);

    if (empty()) {
        _pHead = _pTail = newNode;

    } else {
        _pTail->_pNext = newNode;
        _pTail = newNode;
    }

    _iSize++;
}

// TODO: Viết comment cho hàm 
template<class DataType> 
DataType LinkedList<DataType>::getFront() {
    if (!empty()) 
        return _pHead->_data;
}

// TODO: Viết comment cho hàm 
template<class DataType>
DataType LinkedList<DataType>::getBack() {
    if (!empty())
        return _pTail->_data;
}

// TODO: Viết comment cho hàm 
template<class DataType>
DataType LinkedList<DataType>::getAt(int index) {
    Node<DataType> *pWalker = _pHead;

    for (int i = 0; i < index; i++)
        pWalker = pWalker->_pNext;

    return pWalker->_data;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::setAt(int index, DataType data) {
    if (index < 0 || index >= _iSize)
        return;

    Node<DataType>* pWalker = _pHead;
    for (int i = 0; i < index; i++)
        pWalker = pWalker->_pNext;

    pWalker->_data = data;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::insertAt(int index, DataType data) {
    if (index < 0 || index > _iSize)
        return;

    if (index == 0) 
        addFront(data);

    else if (index == _iSize)
        addBack(data);

    else {
        Node<DataType>* newNode = new Node<DataType>(data);
        Node<DataType>* pWalker = _pHead;

        for (int i = 0; i < index - 1; i++)
            pWalker = pWalker->_pNext;

        newNode->_pNext = pWalker->_pNext;
        pWalker->_pNext = newNode;
        _iSize++;
    }
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::removeAt(int index) {
    if (index < 0 || index >= _iSize)
        return;

    if (index == 0) {
        Node<DataType> *pTmp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTmp;

        if (_pHead == nullptr)
            _pTail = nullptr;

    } else {
        Node<DataType>* pWalker = _pHead;

        for (int i = 0; i < index - 1; i++)
            pWalker = pWalker->_pNext;

        Node<DataType>* pTmp  = pWalker->_pNext;
        pWalker->_pNext = pTmp->_pNext;

        if (pTmp == _pTail)
            _pTail = pWalker;

        delete pTmp;
    }

    _iSize--;
}

// TODO: Viết comment cho hàm 
template<class DataType>
int LinkedList<DataType>::find(DataType data) {
    int iIndex = 0;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == data)
            return iIndex;
        pWalker = pWalker->_pNext;
    }

    return -1;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::remove(DataType data) {
    Node<DataType>* pCur = _pHead;
    Node<DataType>* pPrev = nullptr;

    while (pCur != nullptr) {
        if (pCur->_data == data) {
            if (pPrev == nullptr)
                _pHead = pCur->_pNext;
            else 
                pPrev->_pNext = pCur->_pNext;

            if (pCur == _pTail)
                _pTail = pCur;
            
            delete pCur;
            _iSize--;
            return;
        }

        pPrev = pCur;
        pCur = pCur->_pNext;
    }
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::clear() {
    while (_pHead != nullptr) {
        Node<DataType>* pTmp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTmp;
    }

    _pTail = nullptr;
    _iSize = 0;
}

// TODO: Viết comment cho hàm 
template<class DataType>
int LinkedList<DataType>::size() {
    return _iSize;
}

// TODO: Viết comment cho hàm 
template<class DataType>
bool LinkedList<DataType>::empty() {
    return _pHead == nullptr;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::display() {
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        pWalker->display();
        pWalker = pWalker->_pNext;  
    }

    cout << endl;
}   

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::sortAsc() {
    if (empty())
        return;

    for (Node<DataType>* i = _pHead; i->_pNext != nullptr; i = i->_pNext) 
        for (Node<DataType>* j = i->_pNext; j != nullptr; j = j->_pNext)
            if (i->_data > j->_data)
                swap(i->_data, j->_data);
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::sortDesc() {
    if (empty())
        return;

    for (Node<DataType>* i = _pHead; i->_pNext != nullptr; i = i->_pNext) 
        for (Node<DataType>* j = i->_pNext; j != nullptr; j = j->_pNext)
            if (i->_data < j->_data)
                swap(i->_data, j->_data);
}   

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::reverse() {
    Node<DataType>* pCur = _pHead;
    Node<DataType>* pPrev = nullptr;

    _pTail = _pHead;
    while (pCur != nullptr) {
        Node<DataType>* pNext = pCur->_pNext;
        pCur->_pNext = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }

    _pHead = pPrev;
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::unique() {
    Node<DataType> *pCur = _pHead;

    while (pCur != nullptr && pCur->_pNext != nullptr) {
        Node<DataType>* pWalker = pCur;

        while (pWalker->_pNext != nullptr) {
            if (pWalker->_pNext->_data == pCur->_data) {
                Node<DataType>* pTmp = pWalker->_pNext;
                pWalker->_pNext = pWalker->_pNext->_pNext;
                delete pTmp;
                _iSize--;

            } else {
                pWalker = pWalker->_pNext;
            }
        }

        pCur = pCur->_pNext;
    }
}

// TODO: Viết comment cho hàm 
template<class DataType>
void LinkedList<DataType>::sortHalfAscDesc() {
    if (empty() || _iSize == 1)
        return;

    Node<DataType>* pMid = _pHead;
    for (int i = 0; i < _iSize/2; i++)
        pMid = pMid->_pNext;

    for (Node<DataType>* i = _pHead; i != pMid; i = i->_pNext) 
        for (Node<DataType>* j = i->_pNext; j != pMid; j = j->_pNext) 
            if (i->_data < j->_data)
                swap(i->_data, j->_data);

    for (Node<DataType>* i = pMid; i != nullptr; i = i->_pNext) 
        for (Node<DataType>* j = i->_pNext; j != nullptr; j = j->_pNext)
            if (i->_data > j->_data)
                swap(i->_data, j->_data);
    
}

// TODO: Viết comment cho hàm 
template<class DataType>
bool LinkedList<DataType>::contains(DataType data) {
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == data)
            return true;
        pWalker = pWalker->_pNext;
    }

    return false;
}

// TODO: Viết comment cho hàm 
template<class DataType>
int LinkedList<DataType>::count(DataType data) {
    int iCount = 0;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == data)
            iCount++;
        pWalker = pWalker->_pNext;
    }

    return iCount;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType> LinkedList<DataType>::unionWith(LinkedList<DataType> &other) {
    LinkedList<DataType> result;
    Node<DataType>* pWalker = _pHead;
    Node<DataType>* pOtherWolker = other._pHead;

    while (pWalker != nullptr) {
        if (!result.contains(pWalker->_data))
            result.addBack(pWalker->_data);
        pWalker = pWalker->_pNext;
    }

    while (pOtherWolker != nullptr) {
        if (!result.contains(pOtherWolker->_data)) 
            result.addBack(pOtherWolker->_data);
        pOtherWolker = pOtherWolker->_pNext;
    } 

    return result;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType> LinkedList<DataType>::intersectWith(LinkedList<DataType>& other) {
    LinkedList<DataType> result;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (other.contains(pWalker->_data) && !result.contains(pWalker->_data)) 
            result.addBack(pWalker->_data);
        pWalker = pWalker->_pNext;
    }

    return result;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType> LinkedList<DataType>::differenceWith(LinkedList<DataType>& other) {
    LinkedList<DataType> result;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (!other.contains(pWalker->_data)) 
            result.addBack(pWalker->_data);
        pWalker = pWalker->_pNext;
    }

    return result;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType> LinkedList<DataType>::merge(LinkedList<DataType> &other) {
    LinkedList<DataType> result;
    Node<DataType>* pCur1 = _pHead;
    Node<DataType>* pCur2 = other._pHead;

    while (pCur1 != nullptr && pCur2 != nullptr) {
        if (pCur1->_data < pCur2->_data) {
            result.addBack(pCur1->_data);
            pCur1 = pCur1->_pNext;

        } else {
            result.addBack(pCur2->_data);
            pCur2 = pCur2->_pNext;
        }
    }

    while (pCur1 != nullptr) {
        result.addBack(pCur1->_data);
        pCur1 = pCur1->_pNext;
    }

    while (pCur2 != nullptr) {
        result.addBack(pCur2->_data);
        pCur2 = pCur2->_pNext;
    }

    return result;
}

// TODO: Viết comment cho hàm 
template<class DataType>
LinkedList<DataType> LinkedList<DataType>::sumLists(LinkedList<DataType> &other) {
    LinkedList<DataType> result;
    Node<DataType>* pWalker1 = _pHead;
    Node<DataType>* pWalker2 = other._pHead;

    while (pWalker1 != nullptr || pWalker2 != nullptr) {
        DataType sum = 0;

        if (pWalker1 != nullptr) {
            sum += pWalker1->_data;
            pWalker1 = pWalker1->_pNext;
        }

        if (pWalker2 != nullptr) {
            sum += pWalker2->_data;
            pWalker2 = pWalker2->_pNext;
        }

        result.addBack(sum);
    }

    return result;
}

// TODO: Viết comment cho hàm
template<class DataType>
LinkedList<DataType> &LinkedList<DataType>::operator = (const LinkedList<DataType> &other) {
    if (this == &other) 
        return *this;

    clear();

    Node<DataType>* pWalker = other._pHead;
    while (pWalker != nullptr) {
        this->addBack(pWalker->_data);
        pWalker = pWalker->_pNext;
    }

    return *this;
}

// TODO: Viết comment cho hàm 
void Program::displayMenu() {
    setTextColor(GREEN);
    cout << "-----------------Chương trình danh sách liên kết đơn----------------------" << endl;
    cout << "1. Nhập thêm phần tử vào L1 và L2." << endl;
    cout << "2. Tạo L3 là hiệu của L1 và L2." << endl;
    cout << "3. Tạo L3 là giao của L1 và L2." << endl;
    cout << "4. Tạo L3 là hợp của L1 và L2." << endl;
    cout << "5. Thoát chương trình." << endl;
    cout << "--------------------------------------------------------------------------" << endl;
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
* @Description đếm các số có trong chuỗi input.
* @param input: chuỗi chứa các số.
* @attention: chuyển chuỗi thành luồng mới và thực hiện đếm số.
* @return số lượng chữ số có trong luồng.
****************************************************************************/
int Program::countDigit(string input) {
    int iItem, iCount = 0;
    stringstream ssStream(input);

    while (ssStream >> iItem) 
        iCount++;   // Đếm số lượng phần tử hợp lệ

    return iCount;
}

// TODO: Viết comment cho hàm 
int Program::selectOption() {
    int iOption = -1;
    char cKey;
    string strInput;

    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && stoi(strInput + cKey) >= 1 && stoi(strInput + cKey) <= 5) {
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

    iOption = stoi(strInput);
    return iOption;
}

// TODO: Viết comment cho hàm 
void Program::endOption() {
    setTextColor(BLUE);
    cout << "≫ Nhấn enter để tiếp tục...";
        
    char cKey;
    while (true) {
        cKey = _getch();
        if (cKey == '\r')
            break;
    }
}

// TODO: Viết comment cho hàm 
int Program::inputNumber(const string &prompt) {
    char cKey;
    string strInput;
    int iInput;

    setTextColor(BLUE);
    cout << prompt;

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

    iInput = stoi(strInput);
    return iInput;
}

// TODO: Viết comment cho hàm 
void Program::inputList(const int &size, const string &prompt, int option) {
    int iElement;
    char cKey;
    string strInput;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if ((isdigit(cKey) || (cKey == ' ' && strInput.back() != '-') || (cKey == '-' && (strInput.empty() || strInput.back() == ' '))) && countDigit(strInput) < size) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && countDigit(strInput) > 0) { 
            cout << endl;
            break;
        }
    }

    stringstream ssStream(strInput);

    while (ssStream >> iElement) {
        if (option == 1) 
            _L1.addBack(iElement);
        else    
            _L2.addBack(iElement);
    }

    setTextColor(GREEN);
    cout << "≫ Đã thêm thành công!\n";
}

// TODO: Viết comment cho hàm 
void Program::run() {
    setTextColor(WHITE);
    SetConsoleOutputCP(CP_UTF8);

    int iMenuSelection = -1;

    while (iMenuSelection != 5) {
        system("cls");
        displayMenu();

        setTextColor(BLUE);
        cout << "≫ Nhập chức năng: ";

        setTextColor(YELLOW);
        iMenuSelection = selectOption();

        switch (iMenuSelection) {
            case 1: {
                system("cls");
                inputLists();
                break;
            }

            case 2: {
                system("cls");
                createDifferenceList();
                break;
            }
            
            case 3: {
                system("cls");
                createIntersectList();
                break;
            }
            
            case 4: {
                system("cls");
                createUnionList();
                break;
            }

            case 5: {
                setTextColor(GREEN);
                cout << "≫ Thoát chương trình...\n";
                Sleep(3000);
                setTextColor(WHITE);
                return;
            }
        }

        endOption();
    }
}

// TODO: Viết comment cho hàm
void Program::inputLists() {
    int iSizeL1, iSizeL2;

    iSizeL1 = inputNumber("≫ Nhập số lượng phần tử thêm vào L1: ");
    inputList(iSizeL1, "≫ Nhập các phần tử thêm vào L1: ", 1);

    iSizeL2 = inputNumber("≫ Nhập số lượng phần tử thêm vào L2: ");
    inputList(iSizeL2, "≫ Nhập các phần tử thêm vào L2: ", 2);
}

// TODO: Viết comment cho hàm
void Program::createDifferenceList() {
    if (_L1.empty() && _L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 và L2 đang rỗng!\n";
        return;
    }

    if (_L1.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 đang rỗng!\n";
        return;
    }

    if (_L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L2 đang rỗng!\n";
        return;
    }

    LinkedList<int> L3 = _L1.differenceWith(_L2);
    L3.sortAsc();

    setTextColor(BLUE);
    cout << "≫ Danh sách L1: "; 
    setTextColor(YELLOW);
    _L1.display();

    setTextColor(BLUE);
    cout << "≫ Danh sách L2: "; 
    setTextColor(YELLOW);
    _L2.display();

    setTextColor(BLUE);
    cout << "≫ Hiệu của L1 và L2 là ";

    setTextColor(YELLOW);
    if (L3.empty()) 
        cout << "rỗng";
    else 
        L3.display();
}

// TODO: Viết comment cho hàm
void Program::createIntersectList() {
    if (_L1.empty() && _L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 và L2 đang rỗng!\n";
        return;
    }

    if (_L1.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 đang rỗng!\n";
        return;
    }

    if (_L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L2 đang rỗng!\n";
        return;
    }

    LinkedList<int> L3 = _L1.intersectWith(_L2);
    L3.sortAsc();

    setTextColor(BLUE);
    cout << "≫ Danh sách L1: "; 
    setTextColor(YELLOW);
    _L1.display();

    setTextColor(BLUE);
    cout << "≫ Danh sách L2: "; 
    setTextColor(YELLOW);
    _L2.display();

    setTextColor(BLUE);
    cout << "≫ Giao của L1 và L2 là ";

    setTextColor(YELLOW);
    if (L3.empty()) 
        cout << "rỗng";
    else 
        L3.display();
}

// TODO: Viết comment cho hàm
void Program::createUnionList() {
    if (_L1.empty() && _L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 và L2 đang rỗng!\n";
        return;
    }

    if (_L1.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L1 đang rỗng!\n";
        return;
    }

    if (_L2.empty()) {
        setTextColor(RED);
        cout << "≫ Danh sách L2 đang rỗng!\n";
        return;
    }

    LinkedList<int> L3 = _L1.unionWith(_L2);
    L3.sortAsc();

    setTextColor(BLUE);
    cout << "≫ Danh sách L1: "; 
    setTextColor(YELLOW);
    _L1.display();

    setTextColor(BLUE);
    cout << "≫ Danh sách L2: "; 
    setTextColor(YELLOW);
    _L2.display();

    setTextColor(BLUE);
    cout << "≫ Hợp của L1 và L2 là ";

    setTextColor(YELLOW);
    if (L3.empty()) 
        cout << "rỗng";
    else 
        L3.display();
}