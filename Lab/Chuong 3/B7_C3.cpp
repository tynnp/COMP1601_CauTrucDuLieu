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

// Lớp đơn thức
class Monominal {
private:
    float _fCoefficient;
    int _iExponent;

public:
    Monominal();
    Monominal(float coefficient, int exponent);
    Monominal(const Monominal &other);

    float getCoefficient();
    void setCoefficient(float coefficient);
    int getExponent();
    void setExponent(int exponent); 
    bool display();
};

// TODO: Viết comment cho lớp Program
class Program {
private:
    LinkedList<Monominal> _F1;
    LinkedList<Monominal> _F2;

    void displayMenu();
    void setTextColor(int color);
    int countElementInput(string input);
    int selectOption();
    void endOption();
    int inputIntNumber(const string &prompt);
    float inputFloatNumber(const string &prompt);
    void inputList(const int &size, const string &prompt, int option);

    void displayPolynominal(LinkedList<Monominal> F);
    LinkedList<Monominal> derivativePolynomial(LinkedList<Monominal> F);
    float evaluatePolynomial(LinkedList<Monominal> F, float x);

public:
    void run();
    void inputPolynominals();
    void displayPolynominals();
    void derivativePolynomials();
    void evaluatePolynomials();
    void sumPolynomials();
    void multiplyPolynomials();
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
Monominal::Monominal() {
    _fCoefficient = 0;
    _iExponent = 0;
}

// TODO: Viết comment cho hàm
Monominal::Monominal(float coefficient, int exponent) {
    _fCoefficient = coefficient;
    _iExponent = exponent;
}

// TODO: Viết comment cho hàm
Monominal::Monominal(const Monominal &other) {
    _fCoefficient = other._fCoefficient;
    _iExponent = other._iExponent;
}

// TODO: Viết comment cho hàm
float Monominal::getCoefficient() {
    return _fCoefficient;
}

// TODO: Viết comment cho hàm
void Monominal::setCoefficient(float coefficient) {
    _fCoefficient = coefficient;
}

// TODO: Viết comment cho hàm
int Monominal::getExponent() {
    return _iExponent;
}

// TODO: Viết comment cho hàm
void Monominal::setExponent(int exponent) {
    _iExponent = exponent;
}

// TODO: Viết comment cho hàm
bool Monominal::display() {
    if (_fCoefficient == 0) 
        return false;

    if (_iExponent == 0) {
        cout << abs(_fCoefficient);
        return true;
    }

    if (abs(_iExponent) == 1) {
        if (abs(_fCoefficient) != 1)
            cout << abs(_fCoefficient);
        cout << "x";
        return true;
    }

    if (abs(_fCoefficient) != 1)
        cout << abs(_fCoefficient);
    cout << "x^" << _iExponent;
    return true;
}

// TODO: Viết comment cho hàm 
void Program::displayMenu() {
    setTextColor(GREEN);
    cout << "-----------------Chương trình danh sách liên kết đa thức----------------------" << endl;
    cout << "1. Nhập 2 đa thức F1 và F2." << endl;
    cout << "2. In 2 đa thức." << endl;
    cout << "3. Tính đạo hàm 2 đa thức." << endl;
    cout << "4. Tính giá trị 2 đa thức theo x." << endl;
    cout << "5. Tạo danh sách là tổng 2 đa thức." << endl;
    cout << "6. Tạo danh sách là tích 2 đa thức." << endl;
    cout << "7. Thoát chương trình." << endl;
    cout << "------------------------------------------------------------------------------" << endl;
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

// TODO: Viết comment cho hàm
int Program::countElementInput(string input) {
    int iCount = 0;
    string strElement;
    stringstream ssStream(input);

    while (ssStream >> strElement)
        iCount++;

    return iCount;
}

// TODO: Viết comment cho hàm 
int Program::selectOption() {
    int iOption = -1;
    char cKey;
    string strInput;

    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && stoi(strInput + cKey) >= 1 && stoi(strInput + cKey) <= 7) {
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
int Program::inputIntNumber(const string &prompt) {
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
float Program::inputFloatNumber(const string &prompt) {
    char cKey;
    string strInput;
    float fInput;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if ((isdigit(cKey) || (isdigit(strInput.back()) && cKey == '.') || (cKey == '-' && strInput.empty()))) {
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

    fInput = stof(strInput);
    return fInput;
}

// TODO: Viết comment cho hàm 
void Program::inputList(const int &size, const string &prompt, int option) {
    char cKey;
    string strInput;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();
        int iCount = countElementInput(strInput);

        if ((isdigit(cKey) || (cKey == ' ' && strInput.back() != '-' && strInput.back() != ' ') || (cKey == '-' && (strInput.empty() || strInput.back() == ' ') && iCount % 2 == 0)) && countElementInput(strInput + cKey) <= 2 * size) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && countElementInput(strInput) > 0) { 
            cout << endl;
            break;
        }
    }

    stringstream ssStream(strInput);
    float fCofficient;
    int iExponent;

    while (ssStream >> fCofficient >> iExponent) {
        if (option == 1) 
            _F1.addBack(Monominal(fCofficient, iExponent));
        else 
            _F2.addBack(Monominal(fCofficient, iExponent));
    }

    setTextColor(GREEN);
    cout << "≫ Đã thêm thành công!\n";
}

// TODO: Viết comment cho hàm
void Program::displayPolynominal(LinkedList<Monominal> F) {
    if (F.empty()) {
        cout << "rỗng\n";
        return;
    }

    bool bIsFirst = true;

    for (int i = 0; i < F.size(); i++) {
        if (bIsFirst) {
            if (F.getAt(i).getCoefficient() < 0)
                cout << '-';
            if (F.getAt(i).display())
                bIsFirst = false;

        } else {
            if (F.getAt(i).getCoefficient() < 0)
                cout << " - ";
            else if (F.getAt(i).getCoefficient() != 0)
                cout << " + ";
            F.getAt(i).display();
        }
    }

    cout << endl;
}

// TODO: Viết comment cho hàm
LinkedList<Monominal> Program::derivativePolynomial(LinkedList<Monominal> F) {
    LinkedList<Monominal> result;

    for (int i = 0; i < F.size(); i++) {
        float fNewCoefficient = F.getAt(i).getCoefficient() * F.getAt(i).getExponent();
        int iNewExponent = F.getAt(i).getExponent() - 1;

        if (iNewExponent >= 0) {
            Monominal deriveMonominal(fNewCoefficient, iNewExponent);
            result.addBack(deriveMonominal);
        }
    }

    return result;
}

// TODO: Viết comment cho hàm
float Program::evaluatePolynomial(LinkedList<Monominal> F, float x) {
    float fResult = 0;

    for (int i = 0; i < F.size(); i++) 
        fResult += F.getAt(i).getCoefficient() * pow(x, F.getAt(i).getExponent());
    
    return fResult;
}

// TODO: Viết comment cho hàm 
void Program::run() {
    setTextColor(WHITE);
    SetConsoleOutputCP(CP_UTF8);

    int iMenuSelection = -1;
    bool bPolynomialEntered = false;

    while (iMenuSelection != 7) {
        system("cls");
        displayMenu();

        setTextColor(BLUE);
        cout << "≫ Nhập chức năng: ";

        setTextColor(YELLOW);
        iMenuSelection = selectOption();

        switch (iMenuSelection) {
            case 1: {
                system("cls");

                if (!bPolynomialEntered) {
                    inputPolynominals();
                    bPolynomialEntered = true;

                } else {
                    setTextColor(RED);
                    cout << "≫ Đa thức đã được nhập!\n";
                }

                break;
            }

            case 2: {
                system("cls");
                displayPolynominals();
                break;
            }
            
            case 3: {
                system("cls");
                derivativePolynomials();
                break;
            }

            case 4: {
                system("cls");
                evaluatePolynomials();
                break;
            }
            
            case 5: {
                system("cls");
                sumPolynomials();
                break;
            }

            case 6: {
                system("cls");
                multiplyPolynomials();
                break;
            }

            case 7: {
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
void Program::inputPolynominals() {
    int iSizeF1, iSizeF2;

    iSizeF1 = inputIntNumber("≫ Nhập số lượng đơn thức F1: ");
    inputList(iSizeF1, "≫ Nhập hệ số và số mũ các đơn thức của F1: ", 1);

    iSizeF2 = inputIntNumber("≫ Nhập số lượng đơn thức F2: ");
    inputList(iSizeF2, "≫ Nhập hệ số và số mũ các đơn thức của F2: ", 2);
}

// TODO: Viết comment cho hàm
void Program::displayPolynominals() {
    if (_F1.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F1 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F1: ";
        setTextColor(YELLOW);
        displayPolynominal(_F1);
    }

    if (_F2.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F2 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F2: ";
        setTextColor(YELLOW);
        displayPolynominal(_F2);
    }
}

// TODO: Viết comment cho hàm
void Program::derivativePolynomials() {
    if (_F1.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F1 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F1: ";
        setTextColor(YELLOW);
        displayPolynominal(_F1);

        setTextColor(BLUE);
        cout << "≫ Đạo hàm F1: ";
        setTextColor(YELLOW);
        displayPolynominal(derivativePolynomial(_F1));
    }

    if (_F2.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F2 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F2: ";
        setTextColor(YELLOW);
        displayPolynominal(_F2);

        setTextColor(BLUE);
        cout << "≫ Đạo hàm F2: ";
        setTextColor(YELLOW);
        displayPolynominal(derivativePolynomial(_F2));
    }
}

// TODO: Viết comment cho hàm
void Program::evaluatePolynomials() {
    float fValueX = inputFloatNumber("≫ Nhập số thực x: ");

    if (_F1.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F1 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F1: ";
        setTextColor(YELLOW);
        displayPolynominal(_F1);

        setTextColor(BLUE);
        cout << "≫ Giá trị F1 theo x: ";
        setTextColor(YELLOW);
        cout << evaluatePolynomial(_F1, fValueX) << endl;
    }

    if (_F2.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F2 không có phần tử!\n";
    } else {
        setTextColor(BLUE);
        cout << "≫ Đa thức F2: ";
        setTextColor(YELLOW);
        displayPolynominal(_F2);

       setTextColor(BLUE);
        cout << "≫ Giá trị F2 theo x: ";
        setTextColor(YELLOW);
        cout << evaluatePolynomial(_F2, fValueX) << endl;
    }
}

// TODO: Viết comment cho hàm
void Program::sumPolynomials() {
    if (_F1.empty() && _F2.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F1 và F2 đang rỗng!\n";
        return;
    }

    LinkedList<Monominal> result;
    int i = 0, j = 0;

    while (i < _F1.size() && j < _F2.size()) {
        if (_F1.getAt(i).getExponent() == _F2.getAt(j).getExponent()) {
            float fNewCoefficient = _F1.getAt(i).getCoefficient() + _F2.getAt(j).getCoefficient();
            if (fNewCoefficient != 0)
                result.addBack(Monominal(fNewCoefficient, _F1.getAt(i).getExponent()));
            i++, j++;

        } else if (_F1.getAt(i).getExponent() > _F2.getAt(j).getExponent()) {
            result.addBack(_F1.getAt(i));
            i++;

        } else {
            result.addBack(_F2.getAt(j));
            j++;
        }
    }

    while (i < _F1.size()) {
        result.addBack(_F1.getAt(i));
        i++;
    }

    while (j < _F2.size()) {
        result.addBack(_F2.getAt(j));
        j++;
    }

    setTextColor(BLUE);
    cout << "≫ Đa thức F1: ";
    setTextColor(YELLOW);
    displayPolynominal(_F1);

    setTextColor(BLUE);
    cout << "≫ Đa thức F2: ";
    setTextColor(YELLOW);
    displayPolynominal(_F2);

    setTextColor(BLUE);
    cout << "≫ Tổng 2 đa thức: ";
    setTextColor(YELLOW);
    displayPolynominal(result);
}

// TODO: Viết comment cho hàm
void Program::multiplyPolynomials() {
    if (_F1.empty() && _F2.empty()) {
        setTextColor(RED);
        cout << "≫ Đa thức F1 và F2 đang rỗng!\n";
        return;
    }

    LinkedList<Monominal> result;

    for (int i = 0; i < _F1.size(); i++) {
        for (int j = 0; j < _F2.size(); j++) {
            float fNewCoefficient = _F1.getAt(i).getCoefficient() * _F2.getAt(j).getCoefficient();
            int iNewExponent = _F1.getAt(i).getExponent() + _F2.getAt(j).getExponent();

            Monominal newMonominal(fNewCoefficient, iNewExponent);
            bool bMerged = false;

            for (int k = 0; k < result.size(); k++) {
                if (result.getAt(k).getExponent() == iNewExponent) {
                    result.getAt(k).setCoefficient(result.getAt(k).getCoefficient() + fNewCoefficient);
                    bMerged = true;
                    break;
                }
            }

            if (!bMerged) 
                result.addBack(newMonominal);
        }
    }

    setTextColor(BLUE);
    cout << "≫ Đa thức F1: ";
    setTextColor(YELLOW);
    displayPolynominal(_F1);

    setTextColor(BLUE);
    cout << "≫ Đa thức F2: ";
    setTextColor(YELLOW);
    displayPolynominal(_F2);

    setTextColor(BLUE);
    cout << "≫ Tích 2 đa thức: ";
    setTextColor(YELLOW);
    displayPolynominal(result);
}
