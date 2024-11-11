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
    // TODO: Viết định nghĩa cho hàm
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
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
LinkedList<Monominal> Program::derivativePolynomial(LinkedList<Monominal> F) {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
float Program::evaluatePolynomial(LinkedList<Monominal> F, float x) {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm 
void Program::run() {
    // TODO: Viết định nghĩa cho hàm   
}

// TODO: Viết comment cho hàm
void Program::inputPolynominals() {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
void Program::displayPolynominals() {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
void Program::derivativePolynomials() {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
void Program::evaluatePolynomials() {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
void Program::sumPolynomials() {
    // TODO: Viết định nghĩa cho hàm
}

// TODO: Viết comment cho hàm
void Program::multiplyPolynomials() {
    // TODO: Viết định nghĩa cho hàm
}