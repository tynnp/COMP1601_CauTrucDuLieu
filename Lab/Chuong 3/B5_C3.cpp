#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
#include <string>
#include <regex>
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

// TODO: bổ sung comment cho lớp Date
class Date {
private:
    int _iDay, _iMonth, _iYear;

public:
    Date();
    Date(int day, int month, int year);
    Date(string strDate);
    Date(const Date &other);
    
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);

    void display();
};

// TODO: bổ sung comment cho lớp Student
class Student {
private: 
    string _strStudentID;
    string _strFullName;
    string _strClassName;
    Date _birthDate;
    float _fAverageScore;

public:
    Student();
    Student(string studentID, string fullName, string className, Date birthDate, float averageScore);
    Student(const Student &other);

    string getStudentID();
    void setStudentID(string studentID);
    string getFullName();
    void setFullName(string fullName);
    string getClassName();
    void setClassName(string className);
    Date getDate();
    void setDate(Date birthDate);
    float getAverageScore();
    void setAverageScore(float averageScore);

    void display();
    bool operator < (string strStudentID);
    bool operator == (string strStudentID);
};

// TODO: Viết comment cho lớp Program
class Program {
private:
    LinkedList<Student> _students;

    void displayMenu();
    void setTextColor(int color);
    int countDigit(string input);
    int selectOption();
    void endOption();
    bool isValidDate(string date);
    bool containID(string studentID);

    int inputNumber(const string &prompt);
    string inputStudentID(const string &prompt);
    string inputFullName(const string &prompt);
    string inputClassName(const string &prompt);
    Date inputBirthDate(const string &prompt);
    float inputAverageScore(const string &prompt);
    Student inputStudent(const string &prompt);

public:
    void run();
    void inputStudentList();
    void printStudentList();
    void printPassStudents();
    void findByID();
    void sortByID();
    void binSearchByID();
    void delByID();
    void updateScoreByID();
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

// TODO: Bổ sung comment cho hàm
Date::Date() {
    _iDay = 1;
    _iMonth = 1;
    _iYear = 1900;
}

// TODO: Bổ sung comment cho hàm
Date::Date(int day, int month, int year) {
    _iDay = day;
    _iMonth = month;
    _iYear = year;
}

// TODO: Bổ sung comment cho hàm
Date::Date(string strDate) {
    int iDay, iMonth, iYear;
    sscanf(strDate.c_str(), "%d/%d/%d", &iDay, &iMonth, &iYear);

    _iDay = iDay;
    _iMonth = iMonth;
    _iYear = iYear;
}

// TODO: Bổ sung comment cho hàm
Date::Date(const Date &other) {
    _iDay = other._iDay;
    _iMonth = other._iMonth;
    _iYear = other._iYear;
}

// TODO: Bổ sung comment cho hàm    
int Date::getDay() {
    return _iDay;
}

// TODO: Bổ sung comment cho hàm
void Date::setDay(int day) {
    _iDay = day;
}

// TODO: Bổ sung comment cho hàm
int Date::getMonth() {
    return _iMonth;
}

// TODO: Bổ sung comment cho hàm
void Date::setMonth(int month) {
    _iMonth = month;
}

// TODO: Bổ sung comment cho hàm
int Date::getYear() {
    return _iYear;
}

// TODO: Bổ sung comment cho hàm
void Date::setYear(int year) {
    _iYear = year;
}

// TODO: Bổ sung comment cho hàm
void Date::display() {
    cout << (_iDay < 10 ? "0" : "") << _iDay << '/';
    cout << (_iMonth < 10 ? "0" : "") << _iMonth << '/';
    cout << _iYear << endl;
}

// TODO: Bổ sung comment cho hàm
Student::Student() {
    _strStudentID = _strFullName = _strClassName = "";
    _fAverageScore = 0;
}

// TODO: Bổ sung comment cho hàm
Student::Student(string studentID, string fullName, string className, Date birthDate, float averageScore) {
    _strStudentID = studentID;
    _strFullName = fullName;
    _strClassName = className;
    _birthDate = birthDate;
    _fAverageScore = averageScore;
}

// TODO: Bổ sung comment cho hàm
Student::Student(const Student &other) {
    _strStudentID = other._strStudentID;
    _strFullName = other._strFullName;
    _strClassName = other._strClassName;
    _birthDate = other._birthDate;
    _fAverageScore = other._fAverageScore;
}

// TODO: Bổ sung comment cho hàm
string Student::getStudentID() {
    return _strStudentID;
}

// TODO: Bổ sung comment cho hàm
void Student::setStudentID(string studentID) {
    _strStudentID = studentID;
}

// TODO: Bổ sung comment cho hàm
string Student::getFullName() {
    return _strFullName;
}

// TODO: Bổ sung comment cho hàm
void Student::setFullName(string fullName) {
    _strFullName = fullName;
}

// TODO: Bổ sung comment cho hàm
string Student::getClassName() {
    return _strClassName;
}

// TODO: Bổ sung comment cho hàm
void Student::setClassName(string className) {
    _strClassName = className;
}

// TODO: Bổ sung comment cho hàm
Date Student::getDate() {
    return _birthDate;
}

// TODO: Bổ sung comment cho hàm
void Student::setDate(Date birthDate) {
    _birthDate = birthDate;
}

// TODO: Bổ sung comment cho hàm
float Student::getAverageScore() {
    return _fAverageScore;
}

// TODO: Bổ sung comment cho hàm
void Student::setAverageScore(float averageScore) {
    _fAverageScore = averageScore;
}

// TODO: Bổ sung comment cho hàm
void Student::display() {
    cout << "Mã sinh viên: " << _strStudentID << endl;
    cout << "Họ tên: " << _strFullName << endl;
    cout << "Lớp: " << _strClassName << endl;
    cout << "Ngày sinh: "; _birthDate.display();
    cout << "Điểm trung bình: " << _fAverageScore << endl;
}

// TODO: Bổ sung comment cho hàm
bool Student::operator < (string strStudentID) {
    return _strStudentID < strStudentID;
}

// TODO: Bổ sung comment cho hàm
bool Student::operator == (string strStudentID) {
    return _strStudentID == strStudentID;
}

// TODO: Viết comment cho hàm 
void Program::displayMenu() {
    setTextColor(GREEN);
    cout << "-----------------Chương trình danh sách liên kết đơn----------------------" << endl;

    cout << ". Thoát chương trình." << endl;
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

        if (isdigit(cKey) && stoi(strInput + cKey) >= 1 && stoi(strInput + cKey) <= 9) {
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

        else if (cKey == '\r' && strInput.size() > 0 && stoi(strInput) > 0) {
            cout << endl;
            break;
        }
    }

    iInput = stoi(strInput);
    return iInput;
}

// TODO: Bổ sung comment cho hàm
bool Program::isValidDate(string date) {
    regex datePattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");

    if (!regex_match(date, datePattern))
        return false;

    int iDay, iMonth, iYear;
    if (sscanf(date.c_str(), "%d/%d/%d", &iDay, &iMonth, &iYear) != 3)
        return false;

    int arrDays[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    arrDays[2] = (iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 != 0)) ? 29 : 28;

    if (iDay > arrDays[iMonth])
        return false;

    return true;
}

// TODO: Bổ sung comment cho hàm
bool Program::containID(string studentID) {
    for (int i = 0; i < _students.size(); i++)
        if (_students.getAt(i) == studentID)
            return true;
    return false;
}

// TODO: Bổ sung comment cho hàm
string Program::inputStudentID(const string &prompt) {
    char cKey;
    string strStudentID;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalnum(cKey) && strStudentID.size() < 11) {
            cout << cKey;
            strStudentID += cKey;
        }

        else if (cKey == 8) {
            if (!strStudentID.empty()) {
                cout << "\b \b";
                strStudentID.pop_back();
            }
        }

        else if (cKey == '\r' && !strStudentID.empty() && strStudentID.size() == 11) {
            cout << endl;
            break;
        }
    }

    return strStudentID;
}

// TODO: Bổ sung comment cho hàm
string Program::inputFullName(const string &prompt) {
    char cKey;
    string strFullName;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalpha(cKey) || cKey == ' ') {
            cout << cKey;
            strFullName += cKey;
        }

        else if (cKey == 8) {
            if (!strFullName.empty()) {
                cout << "\b \b";
                strFullName.pop_back();
            }
        }

        else if (cKey == '\r' && !strFullName.empty()) {
            cout << endl;
            break;
        }
    }

    return strFullName;
}

// TODO: Bổ sung comment cho hàm
string Program::inputClassName(const string &prompt) {
    char cKey;
    string strClassName;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalpha(cKey) || cKey == ' ') {
            cout << cKey;
            strClassName += cKey;
        }

        else if (cKey == 8) {
            if (!strClassName.empty()) {
                cout << "\b \b";
                strClassName.pop_back();
            }
        }

        else if (cKey == '\r' && !strClassName.empty()) {
            cout << endl;
            break;
        }
    }

    return strClassName;
}

// TODO: Bổ sung comment cho hàm
Date Program::inputBirthDate(const string &prompt) {
    char cKey;
    string strBirthDate;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) || cKey == '/') {
            cout << cKey;
            strBirthDate += cKey;
        }

        else if (cKey == 8) {
            if (!strBirthDate.empty()) {
                cout << "\b \b";
                strBirthDate.pop_back();
            }
        }

        else if (cKey == '\r' && isValidDate(strBirthDate)) {
            cout << endl;
            break;
        }
    }

    return Date(strBirthDate);
}

// TODO: Bổ sung comment cho hàm
float Program::inputAverageScore(const string &prompt) {
    char cKey;
    string strInput;
    float fInput;

    setTextColor(BLUE);
    cout << prompt;

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) || (isdigit(strInput.back()) && cKey == '.')) {
            cout << cKey;
            strInput += cKey;
        }

        else if (cKey == 8) {
            if (!strInput.empty()) {
                cout << "\b \b";
                strInput.pop_back();
            }
        }

        else if (cKey == '\r' && !strInput.empty() && strInput.back() != '.' && stof(strInput) >= 0 && stof(strInput) <= 10) {
            cout << endl;
            break;
        }
    }

    fInput = stof(strInput);
    return fInput;
}

// TODO: Bổ sung comment cho hàm
Student Program::inputStudent(const string &prompt) {
    setTextColor(YELLOW);
    cout << prompt;

    string strStudentID = inputStudentID("≫ Nhập mã sinh viên (11 ký tự): ");

    while (containID(strStudentID)) {
        setTextColor(RED);
        cout << "≫ ID này tồn tại, vui lòng nhập lại!\n";
        strStudentID = inputStudentID("≫ Nhập mã sinh viên (11 ký tự): ");
    }

    string strFullName = inputFullName("≫ Nhập tên sinh viên: ");
    string strClassName = inputClassName("≫ Nhập tên lớp: ");
    Date birthDate = inputBirthDate("≫ Nhập ngày sinh: ");
    float fAverageScore = inputAverageScore("≫ Nhập điểm trung bình: ");

    setTextColor(GREEN);
    cout << "≫ Đã nhập thành công thông tin sinh viên!\n";
    return Student(strStudentID, strFullName, strClassName, birthDate, fAverageScore);
}

// TODO: Viết comment cho hàm 
void Program::run() {
    setTextColor(WHITE);
    SetConsoleOutputCP(CP_UTF8);

    int iMenuSelection = -1;

    while (iMenuSelection != 9) {
        system("cls");
        displayMenu();

        setTextColor(BLUE);
        cout << "≫ Nhập chức năng: ";

        setTextColor(YELLOW);
        iMenuSelection = selectOption();

        switch (iMenuSelection) {
            case 1: {
                system("cls");
                
                break;
            }

            case 2: {
                system("cls");
                
                break;
            }
            
            case 3: {
                system("cls");
                
                break;
            }
            
            case 4: {
                system("cls");
                
                break;
            }

            case 5: {
                system("cls");
                
                break;
            }

            case 6: {
                system("cls");
                
                break;
            }

            case 7: {
                system("cls");
                
                break;
            }

            case 8: {
                system("cls");
                
                break;
            }

            case 9: {
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

// TODO: Bổ sung comment cho hàm
void Program::inputStudentList() {
    int iSize = inputNumber("≫ Nhập số lượng sinh viên cần thêm: ");

    for (int i = 1; i <= iSize; i++) {
        Student student = inputStudent("≫ Nhập thông tin sinh viên thứ " + to_string(i) + ": ");
        _students.addBack(student);
    }

    setTextColor(GREEN);
    cout << "≫ Đã nhập thành công thông tin tất cả sinh viên!\n";
}

// TODO: Bổ sung comment cho hàm
void Program::printStudentList() {
    if (_students.empty()) {
        setTextColor(RED);
        cout << "≫ Hiện tại không có thông tin sinh viên nào!\n";
        return;
    }

    setTextColor(BLUE);
    cout << "≫ Danh sách các sinh viên: \n";

    setTextColor(YELLOW);
    for (int i = 0; i < _students.size(); i++)
        _students.getAt(i).display();
}

// TODO: Bổ sung comment cho hàm
void Program::printPassStudents() {
    if (_students.empty()) {
        setTextColor(RED);
        cout << "≫ Hiện tại không có thông tin sinh viên nào!\n";
        return;
    }

    bool bCheck = false;

    setTextColor(BLUE);
    cout << "≫ Danh sách các sinh viên có điểm trung bình lớn hơn hoặc bằng 5: \n";

    setTextColor(YELLOW);
    for (int i = 0; i < _students.size(); i++) {
        if (_students.getAt(i).getAverageScore() >= 5) {
            _students.getAt(i).display();
            bCheck = true;
        }
    }

    if (!bCheck) {
        cout << "Không có!\n";
    }
}

// TODO: Bổ sung comment cho hàm
void Program::findByID() {
    if (_students.empty()) {
        setTextColor(RED);
        cout << "≫ Hiện tại không có thông tin sinh viên nào!\n";
        return;
    }

    string strStudentID = inputStudentID("≫ Nhập mã sinh viên cần tìm: ");

    for (int i = 0; i < _students.size(); i++) {
        if (_students.getAt(i) == strStudentID) {
            setTextColor(GREEN);
            cout << "≫ Thông tin sinh viên cần tìm: ";

            setTextColor(YELLOW);
            _students.getAt(i).display();
            return;
        }
    }

    setTextColor(RED);
    cout << "≫ Không tìm thấy sinh viên có mã sinh viên này!\n";
}

// TODO: Bổ sung comment cho hàm
void Program::sortByID() {

}

// TODO: Bổ sung comment cho hàm
void Program::binSearchByID() {

}

// TODO: Bổ sung comment cho hàm
void Program::delByID() {

}

// TODO: Bổ sung comment cho hàm}
void Program::updateScoreByID() {
    if (_students.empty()) {
        setTextColor(RED);
        cout << "≫ Hiện tại không có thông tin sinh viên nào!\n";
        return;
    }

    string strStudentID = inputStudentID("≫ Nhập mã sinh viên cần cập nhật điểm: ");
    
    int iIndex = -1;
    for (int i = 0; i < _students.size(); i++) {
        if (_students.getAt(i) == strStudentID) {
            iIndex = i;
            break;
        }
    }

    if (iIndex = -1) {
        setTextColor(RED);
        cout << "≫ Không tìm thấy sinh viên có mã sinh viên này!\n";
        return;
    }

    float fAverageScoreNew = inputAverageScore("≫ Nhập điểm trung bình mới: ");
    
}
