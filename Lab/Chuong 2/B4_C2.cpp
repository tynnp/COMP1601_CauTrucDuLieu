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

// Lớp môn học
class Subject {
private:
    string _strSubjectID;       // Mã môn học
    string _strSubjectName;     // Tên môn học
    int _iCredits;              // Số tín chỉ
    float _fScore;              // Điểm

public:
    Subject();                                                                  // Hàm khởi tạo mặc định
    Subject(string subjectID, string subjectName, int credits, float score);    // Hàm khởi tạo có tham số
    Subject(const Subject &other);                                              // Hàm sao chép
    ~Subject();                                                                 // Hàm hủy

    string getSubjectID();                      // Hàm lấy mã môn học
    void setSubjectID(string subjectID);        // Hàm thiết lập mã môn học
    string getSubjectName();                    // Hàm lấy tên môn học
    void setSubjectName(string subjectName);    // Hàm thiết lập tên môn học
    int getCredits();                           // Hàm lấy số tín chỉ
    void setCredits(int credits);               // Hàm thiết lập số tín chỉ
    float getScore();                           // Hàm lấy điểm
    void setScore(float score);                 // Hàm thiết lập điểm

    friend ostream &operator << (ostream &out, Subject other);  // Toán tử xuất
};


// Lớp sinh viên
class Student {
private:
    string _strStudentID;           // Mã sinh viên
    string _strFullName;            // Họ tên
    string _strBirthDate;           // Ngày sinh (định dạng dd/MM/yyyy)
    Array<Subject> _arrSubjects;    // Danh sách các môn học
    int _iSubjectCount;             // Số lượng môn học

public:
    Student();                                                                                                  // Hàm khởi tạo mặc định
    Student(string studentID, string fullName, string birthDate, Array<Subject> subjects, int subjectCount);    // Hàm khởi tạo có tham số
    Student(const Student &other);                                                                              // Hàm sao chép
    ~Student();                                                                                                 // Hàm hủy

    string getStudentID();                      // Hàm lấy mã sinh viên
    void setStudentID(string studentID);        // Hàm thiết lập mã sinh viên
    string getFullName();                       // Hàm lấy họ tên 
    void setFullName(string fullName);          // Hàm thiết lập họ tên
    string getBirthDate();                      // Hàm lấy ngày tháng năm sinh
    void setBirthDate(string birthDate);        // Hàm thiết lập ngày tháng năm sinh    
    Array<Subject> getSubjects();               // Hàm lấy danh sách môn học
    void setSubjects(Array<Subject> subjects);  // Hàm thiết lập danh sách môn học
    int getSubjectCount();                      // Hàm lấy số lượng môn học
    void setSubjectCount(int subjectCount);     // Hàm thiết lập số lượng môn học
    float getAVGScore();                        // Hàm lấy điểm trung bình
    bool checkScholarship();                    // Hàm check học bổng

    friend ostream &operator << (ostream &out, Student other);  // Toán tử xuất
};

// Lớp chương trình
class Program {
private:
    Array<Student> _array;                                  // Đối tượng mảng để lưu trữ các phần tử
    int countDigit(string input);                           // Đếm số phần tử số hợp lệ trong chuỗi đầu vào
    void setTextColor(int color);                           // Đổi màu chữ hiển thị trên console
    bool isValidDate(string date);                          // Hàm kiểm tra ngày tháng năm có hợp lệ không
    bool compareDate(Student studenA, Student studentB);
    Subject inputSubject();                                 // Nhập môn học
    Student inputStudent();                                 // Nhập sinh viên
    int selectOption();
    void endOption();
    void recursiveQuickSort(int left, int right);           // Hàm đệ quy để áp dụng trong thuật toán quick sort

public:
    void inputStudentList();            // Nhập danh sách sinh viên
    void updateStudentNameByID();       // Tìm kiếm sinh viên theo mã số và sửa họ tên
    void sortStudentByNameDesc();       // Sắp xếp các sinh viên theo họ tên giảm dần
    void sortStudentByNameAsc();        // Sắp xếp các sinh viên theo họ tên tăng dần
    void removeStudentByName();         // Tìm kiếm sinh viên theo mã số và xóa sinh viên đó khỏi danh sách
    void sortStudentByAVGScoreAsc();    // Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
    void printScholarshipStudents();    // In ra danh sách tên của các sinh viên có học bổng
    void sortStudentsByBirthYearAsc();  // Sắp xếp danh sách tăng dần theo năm sinh
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

// TODO: Bổ sung comment hàm
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

// TODO: Bổ sung comment hàm
Subject::Subject() {
    _strSubjectID = _strSubjectName = "";
    _iCredits = _fScore = 0;
}

// TODO: Bổ sung comment hàm
Subject::Subject(string subjectID, string subjectName, int credits, float score) {
    _strSubjectID = subjectID;
    _strSubjectName = subjectName;
    _iCredits = credits;
    _fScore = score;
}

// TODO: Bổ sung comment hàm
Subject::Subject(const Subject &other) {
    _strSubjectID = other._strSubjectID;
    _strSubjectName = other._strSubjectName;
    _iCredits = other._iCredits;
    _fScore = other._fScore;
}

// TODO: Bổ sung comment hàm
Subject::~Subject() {
    // Không cần định nghĩa
}

// TODO: Bổ sung comment hàm
string Subject::getSubjectID() {
    return _strSubjectID;
}

// TODO: Bổ sung comment hàm
void Subject::setSubjectID(string subjectID) {
    _strSubjectID = subjectID;
}

// TODO: Bổ sung comment hàm
string Subject::getSubjectName() {
    return _strSubjectName;
}

// TODO: Bổ sung comment hàm
void Subject::setSubjectName(string subjectName) {
    _strSubjectName = subjectName;
}

// TODO: Bổ sung comment hàm
int Subject::getCredits() {
    return _iCredits;
}

// TODO: Bổ sung comment hàm
void Subject::setCredits(int credits) {
    _iCredits = credits;
}

// TODO: Bổ sung comment hàm
float Subject::getScore() {
    return _fScore;
}

// TODO: Bổ sung comment hàm
void Subject::setScore(float score) {
    _fScore = score;
}

// TODO: Bổ sung comment hàm
ostream &operator << (ostream &out, Subject other) {
    out << "\nMã môn: " << other._strSubjectID << endl;
    out << "Tên môn học: " << other._strSubjectName << endl;
    out << "Số tín chỉ: " << other._iCredits << endl;

    out << fixed << setprecision(2);
    out << "Điểm: " << other._fScore << endl;

    return out;
}

// TODO: Bổ sung comment hàm
Student::Student() {
    _strStudentID = _strFullName = _strBirthDate = "";
    _iSubjectCount = 0;
}

// TODO: Bổ sung comment hàm
Student::Student(string studentID, string fullName, string birthDate, Array<Subject> subjects, int subjectCount) {
    _strStudentID = studentID;
    _strFullName = fullName;
    _strBirthDate = birthDate;
    _arrSubjects = subjects;
    _iSubjectCount = subjectCount;
}

// TODO: Bổ sung comment hàm
Student::Student(const Student &other) {
    _strStudentID = other._strStudentID;
    _strFullName = other._strFullName;
    _strBirthDate = other._strBirthDate;
    _arrSubjects = other._arrSubjects;
    _iSubjectCount = other._iSubjectCount;
}

// TODO: Bổ sung comment hàm
Student::~Student() {
    // Không cần định nghĩa
}

// TODO: Bổ sung comment hàm
string Student::getStudentID() {
    return _strStudentID;
}

// TODO: Bổ sung comment hàm
void Student::setStudentID(string studentID) {
    _strStudentID = studentID;
}

// TODO: Bổ sung comment hàm
string Student::getFullName() {
    return _strFullName;
}

// TODO: Bổ sung comment hàm
void Student::setFullName(string fullName) {
    _strFullName = fullName;
}

// TODO: Bổ sung comment hàm
string Student::getBirthDate() {
    return _strBirthDate;
}

// TODO: Bổ sung comment hàm
void Student::setBirthDate(string birthDate) {
    _strBirthDate = birthDate;
}

// TODO: Bổ sung comment hàm
Array<Subject> Student::getSubjects() {
    return _arrSubjects;
}

// TODO: Bổ sung comment hàm
void Student::setSubjects(Array<Subject> subjects) {
    _arrSubjects = subjects;
}

// TODO: Bổ sung comment hàm
int Student::getSubjectCount() {
    return _iSubjectCount;
}

// TODO: Bổ sung comment hàm
void Student::setSubjectCount(int subjectCount) {
    _iSubjectCount = subjectCount;
}

// TODO: Bổ sung comment hàm
float Student::getAVGScore() {
    float fResult = 0;
    for (int i = 0; i < _arrSubjects.size(); i++) 
        fResult += _arrSubjects.getAt(i).getScore();
    fResult /= _arrSubjects.size();
    return fResult;
}

// TODO: Bổ sung comment hàm
bool Student::checkScholarship() {
    if (getAVGScore() < 7)
        return false;

    for (int i = 0; i < _arrSubjects.size(); i++)
        if (_arrSubjects.getAt(i).getScore() < 5)
            return false;
    
    return true;
}

// TODO: Bổ sung comment hàm
ostream &operator << (ostream &out, Student other) {
    out << "----------------------------------------------------------------\n";
    out << "Mã sinh viên: " << other._strStudentID << endl;
    out << "Họ tên: " << other._strFullName << endl;
    out << "Ngày sinh: " << other._strBirthDate << endl;

    out << fixed << setprecision(2);
    out << "Điểm trung bình: " << other.getAVGScore() << endl;

    out << "Danh sách môn học: " << endl;
    other._arrSubjects.print();
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
    stringstream ssStream(input);

    while (ssStream >> iItem) 
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

// TODO: Bổ sung comment hàm
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

// TODO: Bổ sung comment hàm
bool Program::compareDate(Student studentA, Student studentB) {
    int dayA, monthA, yearA;
    int dayB, monthB, yearB;

    sscanf(studentA.getBirthDate().c_str(), "%d/%d/%d", &dayA, &monthA, &yearA);
    sscanf(studentB.getBirthDate().c_str(), "%d/%d/%d", &dayB, &monthB, &yearB);

    if (yearA != yearB) 
        return yearA < yearB;

    if (monthA != monthB) 
        return monthA < monthB;

    return dayA < dayB;
}

// TODO: Bổ sung comment hàm
Subject Program::inputSubject() {
    string strSubjectID, strSubjectName;
    int iCredits;
    float fScore;
    char cKey;
    string strInput;

    // Nhập mã môn học
    setTextColor(BLUE);
    cout << "≫ Nhập mã môn học: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalnum(cKey)) {
            cout << cKey;
            strSubjectID += cKey;
        }

        else if (cKey == 8) {
            if (!strSubjectID.empty()) {
                cout << "\b \b";
                strSubjectID.pop_back();
            }
        }

        else if (cKey == '\r' && !strSubjectID.empty()) {
            cout << endl;
            break;
        }
    }

    // Nhập tên môn học
    setTextColor(BLUE);
    cout << "≫ Nhập tên môn học: ";
    
    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalnum(cKey) || cKey == ' ') {
            cout << cKey;
            strSubjectName += cKey;
        }

        else if (cKey == 8) {
            if (!strSubjectName.empty()) {
                cout << "\b \b";
                strSubjectName.pop_back();
            }
        }

        else if (cKey == '\r' && !strSubjectName.empty()) {
            cout << endl;
            break;
        }
    }
    
    // Nhập số tín chỉ
    setTextColor(BLUE);
    cout << "≫ Nhập số tín chỉ (1-5): ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && strInput.empty() && cKey >= '1' && cKey <= '5') {
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
    iCredits = stoi(strInput);
    strInput.clear();

    // Nhập điểm
    setTextColor(BLUE);
    cout << "≫ Nhập điểm (0-10): ";

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

    fScore = stof(strInput);
    strInput.clear();
    
    Subject subject(strSubjectID, strSubjectName, iCredits, fScore);
    return subject;
}

// TODO: Bổ sung comment hàm
Student Program::inputStudent() {
    string strStudentID, strFullName, strBirthDate;
    Array<Subject> arrSubjects;
    int iSubjectCount;

    char cKey;
    string strInput;

    // Nhập mã sinh viên
    setTextColor(BLUE);
    cout << "≫ Nhập mã sinh viên (11 ký tự): ";

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

    // Nhập tên sinh viên
    setTextColor(BLUE);
    cout << "≫ Nhập tên sinh viên: ";
    
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

    // Nhập ngày sinh
    setTextColor(BLUE);
    cout << "≫ Nhập ngày sinh (dd/mm/yyyy): ";

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

    // Nhập số môn học
    setTextColor(BLUE);
    cout << "≫ Nhập số môn học: ";

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
            cout << endl;
            break;
        }
    }
    iSubjectCount = stoi(strInput);
    strInput.clear();

    for (int i = 1; i <= iSubjectCount; i++) {
        Subject subject;
        bool bIsValid = true;

        while (true) {
            setTextColor(YELLOW);
            cout << endl << "≫ Nhập thông tin môn học thứ " << i << endl;

            subject = inputSubject();

            for (int i = 0; i < arrSubjects.size(); i++) {
                if (arrSubjects.getAt(i).getSubjectID() == subject.getSubjectID()) {
                    setTextColor(RED);
                    cout << "≫ Mã môn này đã tồn tại đối với sinh viên này!\n";
                    cout << "≫ Vui lòng nhập lại thông tin môn học này!\n";
                    bIsValid = false;
                    break;
                }

                if (i == arrSubjects.size() - 1)
                    bIsValid = true;
            }       

            if (!bIsValid)   
                continue;

            arrSubjects.add(subject);
            break;
        }

        setTextColor(GREEN);
        cout << "≫ Đã thêm thành công môn học " + subject.getSubjectName() + "!\n";
    }

    Student student(strStudentID, strFullName, strBirthDate, arrSubjects, iSubjectCount);
    return student;
}

// TODO: Bổ sung comment hàm
int Program::selectOption() {
    int iOption = -1;
    char cKey;
    string strInput;

    while (true) {
        cKey = _getch();

        if (isdigit(cKey) && cKey >= '1' && cKey <= '8' && strInput.empty()) {
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

// TODO: Bổ sung comment hàm
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

// TODO: Bổ sung comment hàm
void Program::recursiveQuickSort(int left, int right) {
    if (left >= right)
        return;

    Student x = _array.getAt((left + right) / 2);
    int i = left, j = right;

    while (i <= j) {
        while (compareDate(_array.getAt(i), x)) i++;
        while (compareDate(x, _array.getAt(j))) j--;

        if (i <= j) {
            swap(_array.getAt(i), _array.getAt(j));
            i++, j--;
        }
    } 

    recursiveQuickSort(left, j);
    recursiveQuickSort(i, right);
}

// TODO: Bổ sung comment hàm
void Program::inputStudentList() {
    int iSize;
    char cKey;
    string strInput;

    setTextColor(BLUE);
    cout << "≫ Số lượng sinh viên cần nhập: ";

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
        Student student;
        bool bIsValid = true;

        while (true) {
            setTextColor(YELLOW);
            cout << "≫ Nhập thông tin sinh viên thứ " << i << " -----------------------\n";

            student = inputStudent();
            
            for (int i = 0; i < _array.size(); i++) {
                if (_array.getAt(i).getStudentID() == student.getStudentID()) {
                    setTextColor(RED);
                    cout << "≫ Mã sinh viên của sinh viên này đã tồn tại trong danh sách!\n";
                    cout << "≫ Vui lòng nhập lại thông tin sinh viên này!\n\n";
                    bIsValid = false;
                    break;
                }

                if (i == _array.size() - 1)
                    bIsValid =true;
            }

            if (!bIsValid)
                continue;

            _array.add(student);
            break;
        }

        setTextColor(GREEN);
        cout << "≫ Đã thêm sinh viên " + student.getFullName() + "!\n\n";
    }
}

// TODO: Bổ sung comment hàm
void Program::updateStudentNameByID() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    char cKey;
    string strInput, strStudentID, strNewName;
    
    setTextColor(BLUE);
    cout << "≫ Nhập mã sinh viên cần tìm (11 ký tự): ";

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

    bool bCheck = false;
    int iIndex = -1;
    for (int i = 0; i < _array.size(); i++) {
        if (_array.getAt(i).getStudentID() == strStudentID) {
            bCheck = true;
            iIndex = i;
            break;
        }
    }

    if (!bCheck) {
        setTextColor(RED);
        cout << "≫ Không có sinh viên này!\n";
        return;
    }

    setTextColor(BLUE);
    cout << "≫ Đổi tên sinh viên ";
    setTextColor(YELLOW);
    cout << _array.getAt(iIndex).getFullName() << endl;

    setTextColor(BLUE);
    cout << "≫ Nhập tên mới của sinh viên: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalpha(cKey) || cKey == ' ') {
            cout << cKey;
            strNewName += cKey;
        }

        else if (cKey == 8) {
            if (!strNewName.empty()) {
                cout << "\b \b";
                strNewName.pop_back();
            }
        }

        else if (cKey == '\r' && !strNewName.empty()) {
            cout << endl;
            break;
        }
    }

    _array.getAt(iIndex).setFullName(strNewName);
    setTextColor(GREEN);
    cout << "≫ Đã đổi tên thành công!\n";
}

// TODO: Bổ sung comment hàm
void Program::sortStudentByNameDesc() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    for (int i = 1; i < _array.size(); i++) {
        int j = i;
        while (j > 0 && _array.getAt(j-1).getFullName() < _array.getAt(j).getFullName()) {
            swap(_array.getAt(j-1), _array.getAt(j));
            j--;
        }
    }


    setTextColor(GREEN);
    cout << "≫ Đã sắp xếp giảm dần theo họ tên!\n";
    setTextColor(YELLOW);
}

// TODO: Bổ sung comment hàm
void Program::sortStudentByNameAsc() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    for (int i = 1; i < _array.size(); i++) {
        int j = i;
        while (j > 0 && _array.getAt(j-1).getFullName() > _array.getAt(j).getFullName()) {
            swap(_array.getAt(j-1), _array.getAt(j));
            j--;
        }
    }
}

// TODO: Bổ sung comment hàm
void Program::removeStudentByName() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    string strName;
    char cKey;

    setTextColor(BLUE);
    cout << "≫ Nhập tên sinh viên cần xóa: ";

    setTextColor(YELLOW);
    while (true) {
        cKey = _getch();

        if (isalpha(cKey) || cKey == ' ') {
            cout << cKey;
            strName += cKey;
        }

        else if (cKey == 8) {
            if (!strName.empty()) {
                cout << "\b \b";
                strName.pop_back();
            }
        }

        else if (cKey == '\r' && !strName.empty()) {
            cout << endl;
            break;
        }
    }
    
    // Sắp xếp tăng dần trước khi tìm kiếm
    sortStudentByNameAsc();

    int iLeft = 0, iRight = _array.size(), iIndex = -1;
    while (iLeft <= iRight) {
        int iMid = iLeft + (iRight - iLeft) / 2;

        if (strName == _array.getAt(iMid).getFullName()) {
            iIndex = iMid;
            break;
        }

        if (strName < _array.getAt(iMid).getFullName())
            iRight = iMid - 1;
        else 
            iLeft = iMid + 1;
    }

    if (iIndex == -1) {
        setTextColor(RED);
        cout << "≫ Không tìm thấy sinh viên cần xóa!" << endl;
        return;
    } 

    _array.removeAtIndex(iIndex);

    setTextColor(GREEN);
    cout << "≫ Đã xóa thành công!" << endl;

}

// TODO: Bổ sung comment hàm
void Program::sortStudentByAVGScoreAsc() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    for (int i = 0; i < _array.size(); i++) {
        int iMinIdx = i;
        for (int j = i + 1; j < _array.size(); j++) 
            if (_array.getAt(j).getAVGScore() < _array.getAt(iMinIdx).getAVGScore())
                iMinIdx = j;
        swap(_array.getAt(iMinIdx), _array.getAt(i));
    }

    setTextColor(GREEN);
    cout << "≫ Đã sắp xếp tăng dần theo điểm trung bình!\n";
    setTextColor(YELLOW);
}

// TODO: Bổ sung comment hàm
void Program::printScholarshipStudents() {
    setTextColor(YELLOW);
    int iCount = 0;

    for (int i = 0; i < _array.size(); i++) {
        if (_array.getAt(i).checkScholarship()) {
            cout << _array.getAt(i);
            iCount++;
        }
    }

    if (iCount == 0) {
        setTextColor(RED);
        cout << "≫ Không có sinh viên nào nhận được học bổng!" << endl;
        return;
    }
}

// TODO: Bổ sung comment hàm
void Program::sortStudentsByBirthYearAsc() {
    if (_array.size() == 0) {
        setTextColor(RED);
        cout << "≫ Danh sách hiện tại không có sinh viên nào!\n";
        return;
    }

    recursiveQuickSort(0, _array.size()-1);

    setTextColor(GREEN);
    cout << "≫ Đã sắp xếp tăng dần theo ngày sinh!\n";
    setTextColor(YELLOW);
}

// TODO: Bổ sung comment hàm
void Program::displayMenu() {
    setTextColor(GREEN);
    cout << "-----------------Chương trình quản lý sinh viên-----------------" << endl;
    cout << "1. Nhập thêm sinh viên vào danh sách." << endl;
    cout << "2. Đổi tên sinh viên bằng mã sinh viên." << endl;  
    cout << "3. Xóa sinh viên bằng tên sinh viên." << endl;    
    cout << "4. In danh sách sinh viên giảm dần theo họ tên." << endl;
    cout << "5. In danh sách sinh viên tăng dần theo điểm trung bình." << endl;
    cout << "6. In danh sách sinh viên tăng dần theo ngày sinh." << endl;
    cout << "7. In danh sách sinh viên đạt được học bổng." << endl;
    cout << "8. Thoát chương trình." << endl;
    cout << "----------------------------------------------------------------" << endl;
}

/***************************************************************************
* @Description hàm chạy chương trình.
* @attention: gọi đến các hàm thành phần của chương trình.  
****************************************************************************/
void Program::run() {
    setTextColor(WHITE);    
    SetConsoleOutputCP(CP_UTF8);    // Xuất được tiếng Việt
    //SetConsoleCP(CP_UTF8);          // Nhập được tiếng Việt, thiết lập ràng buộc dữ liệu nên không dùng hàm này

    int iMenuSelection = -1;

    while (iMenuSelection != 8) {
        system("cls");
        displayMenu();

        setTextColor(BLUE);
        cout << "≫ Nhập chức năng: ";

        setTextColor(YELLOW);
        iMenuSelection = selectOption();

        switch (iMenuSelection) {
            case 1: {
                system("cls");
                inputStudentList();
                break;
            }

            case 2: {
                system("cls");
                updateStudentNameByID();
                break;
            }

            case 3: {
                system("cls");
                removeStudentByName();
                break;
            }

            case 4: {
                system("cls");
                sortStudentByNameDesc();
                _array.print();
                break;
            }

            case 5: {
                system("cls");
                sortStudentByAVGScoreAsc();
                _array.print();
                break;
            }

            case 6: {
                system("cls");
                sortStudentsByBirthYearAsc();
                _array.print();
                break;
            }

            case 7: {
                system("cls");
                printScholarshipStudents();
                break;
            }

            case 8: {
                setTextColor(RED);
                cout << "≫ Thoát chương trình...\n";
                Sleep(3000);      
                setTextColor(WHITE);
                return;
            }
        }

        endOption();
    }
}