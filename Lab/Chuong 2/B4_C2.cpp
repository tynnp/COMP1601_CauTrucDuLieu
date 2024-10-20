#include <iostream>
#include <sstream>
#include <cctype>
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

// Lớp Array
template<class DataType>
class Array {
private:
    DataType* _items;                                                                                           // Con trỏ lưu mảng phần tử
    int _iSize;                                                                                                 // Số lượng phần tử hiện tại của mảng
    void recursiveQuickSort(int left, int right, bool (*compare)(DataType itemA, DataType itemB) = nullptr);    // Hàm đệ quy để áp dụng trong thuật toán quick sort

public: 
    Array();                                // Khởi tạo mặc định
    Array(const Array<DataType> &other);    // Sao chép
    ~Array();                               // Hàm hủy
    void add(DataType item);                // Thêm phần tử item và mảng
    void print();                           // In mảng
    void clear();                           // Xóa mảng
    int size();                             // Lấy số phần tử của mảng

    int find(DataType item, int index = 0);                                                         // Tìm chỉ số của phần tử item từ chỉ số index
    void removeAtIndex(int index);                                                                  // Xoá phần tử tại vị trí index
    bool removeAll(DataType item);                                                                  // Xoá hết phần tử có giá trị item
    DataType getAt(int index);                                                                      // Lấy giá trị của phần tử tại vị trí index
    void insertionSort(bool (*compare)(DataType itemA, DataType itemB) = nullptr);                  // Hàm sắp xếp theo thuật toán sắp xếp chèn với điều kiện so sánh là hàm compare
    void selectionSort(bool (*compare)(DataType itemA, DataType itemB) = nullptr);                  // Hàm sắp xếp theo thuật toán sắp xếp chọn với điều kiện so sánh là hàm compare
    void quickSort(bool (*compare)(DataType itemA, DataType itemB) = nullptr);                      // Hàm sắp xếp theo thuật toán sắp xếp nhanh với điều kiện so sánh là hàm compare
    int binarySearch(DataType item, bool (*compare)(DataType itemA, DataType itemB) = nullptr);     // Hàm tìm kiếm nhị phân với hàm điều kiện được truyền vào
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
};

// Lớp chương trình
class Program {
private:
    Array<Student> _array;          // Đối tượng mảng để lưu trữ các phần tử
    int countDigit(string input);   // Đếm số phần tử số hợp lệ trong chuỗi đầu vào
    void setTextColor(int color);   // Đổi màu chữ hiển thị trên console
    bool isValidDate(string date);  // Hàm kiểm tra ngày tháng năm có hợp lệ không
    Subject inputSubject();         // Nhập môn học
    Student inputStudent();         // Nhập sinh viên

public:
    void inputStudentList();            // Nhập danh sách sinh viên
    void updateStudentNameByID();       // Tìm kiếm sinh viên theo mã số và sửa họ tên
    void sortStudentByNameDesc();       // Sắp xếp các sinh viên theo họ tên giảm dần
    void removeStudentByName();         // Tìm kiếm sinh viên theo mã số và xóa sinh viên đó khỏi danh sách
    void sortStudentByAVGScoreAsc();    // Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
    void printScholarshipStudents();    // In ra danh sách tên của các sinh viên có học bổng
    void sortStudentsByBirthYearAsc();  // Sắp xếp danh sách tăng dần theo năm sinh
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
    delete[] _items;
    _iSize = other._iSize;
    _items = new DataType[_iSize];

    for (int i = 0; i < other._iSize; i++) 
        _items[i] = other._items[i];
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
* @Description hàm sắp xếp theo điều kiện truyền vào, mặc định là tăng dần.
* @param compare: Con trỏ đến hàm so sánh hai phần tử kiểu DataType. 
* @attention: Hàm compare nhận vào hai đối tượng itemA và itemB để thực hiện so sánh.
* @attention: sắp xếp theo thuật toán sắp xếp chèn (insertion sort).
****************************************************************************/
template<class DataType>
void Array<DataType>::insertionSort(bool (*compare)(DataType itemA, DataType itemB)) {
    if (compare == nullptr) {
        compare = [] (DataType itemA, DataType itemB) {
            return itemA < itemB;
        };
    }
    
    for (int i = 1; i < _iSize; i++) {
        int j = i;
        while (j > 0 && !compare(_items[j-1], _items[j])) {
            swap(_items[j-1], _items[j]);
            j--;
        }
    }
}

template<class DataType>
void Array<DataType>::selectionSort(bool (*compare)(DataType itemA, DataType itemB)) {
    if (compare == nullptr) {
        compare = [] (DataType itemA, DataType itemB) {
            return itemA < itemB;
        };
    }

    for (int i = 0; i < _iSize; i++) {
        int iMinIdx = i;
        for (int j = i + 1; j < _iSize; j++) 
            if (compare(_items[j], _items[iMinIdx]))
                iMinIdx = j;
        if (iMinIdx != i)
            swap(_items[iMinIdx], _items[i]);
    }
} 

template<class DataType>
void Array<DataType>::recursiveQuickSort(int left, int right,bool (*compare)(DataType itemA, DataType itemB)) {
    if (left >= right)
        return;

    if (compare == nullptr) {
        compare = [] (DataType itemA, DataType itemB) {
            return itemA < itemB;
        };
    }

    DataType x = _items[(left + right) / 2];
    int i = left, j = right;

    while (i < j) {
        while (compare(_items[i], x)) i++;
        while (compare(x, _items[j])) j--;

        if (i <= j) {
            swap(_items[i], _items[j]);
            i++, j--;
        }
    } 

    recursiveQuickSort(left, j, compare);
    recursiveQuickSort(i, right, compare);
}



template<class DataType>
void Array<DataType>::quickSort(bool (*compare)(DataType itemA, DataType itemB)) {
    if (compare == nullptr) {
        compare = [] (DataType itemA, DataType itemB) {
            return itemA < itemB;
        };
    }

    recursiveQuickSort(0, _iSize-1, compare);
}



template<class DataType>
int Array<DataType>::binarySearch(DataType item, bool (*compare)(DataType itemA, DataType itemB)) {
    if (compare == nullptr) {
        compare = [] (DataType itemA, DataType itemB) {
            return itemA < itemB;
        };
    }

    int iLeft = 0, iRight = _iSize - 1;

    while (iLeft <= iRight) {
        int iMid = iLeft + (iRight - iLeft) / 2;

        if (!compare(_items[iMid], item) && !compare(item, _items[iMid]))
            return iMid;

        if (compare(_items[iMid], item))
            iLeft = iMid + 1;
        else 
            iRight = iMid - 1;
    }

    return -1;
}


Subject::Subject() {
    _strSubjectID = _strSubjectName = "";
    _iCredits = _fScore = 0;
}

Subject::Subject(string subjectID, string subjectName, int credits, float score) {
    _strSubjectID = subjectID;
    _strSubjectName = subjectName;
    _iCredits = credits;
    _fScore = score;
}

Subject::Subject(const Subject &other) {
    _strSubjectID = other._strSubjectID;
    _strSubjectName = other._strSubjectName;
    _iCredits = other._iCredits;
    _fScore = other._fScore;
}

Subject::~Subject() {
    // Không cần định nghĩa
}

string Subject::getSubjectID() {
    return _strSubjectID;
}

void Subject::setSubjectID(string subjectID) {
    _strSubjectID = subjectID;
}

string Subject::getSubjectName() {
    return _strSubjectName;
}

void Subject::setSubjectName(string subjectName) {
    _strSubjectName = subjectName;
}

int Subject::getCredits() {
    return _iCredits;
}

void Subject::setCredits(int credits) {
    _iCredits = credits;
}

float Subject::getScore() {
    return _fScore;
}

void Subject::setScore(float score) {
    _fScore = score;
}


Student::Student() {
    _strStudentID = _strFullName = _strBirthDate = "";
    _iSubjectCount = 0;
}

Student::Student(string studentID, string fullName, string birthDate, Array<Subject> subjects, int subjectCount) {
    _strStudentID = studentID;
    _strFullName = fullName;
    _strBirthDate = birthDate;
    _arrSubjects = subjects;
    _iSubjectCount = subjectCount;
}

Student::Student(const Student &other) {
    _strStudentID = other._strStudentID;
    _strFullName = other._strFullName;
    _strBirthDate = other._strBirthDate;
    _arrSubjects = other._arrSubjects;
    _iSubjectCount = other._iSubjectCount;
}

Student::~Student() {
    // Không cần định nghĩa
}

string Student::getStudentID() {
    return _strStudentID;
}

void Student::setStudentID(string studentID) {
    _strStudentID = studentID;
}

string Student::getFullName() {
    return _strFullName;
}

void Student::setFullName(string fullName) {
    _strFullName = fullName;
}

string Student::getBirthDate() {
    return _strBirthDate;
}

void Student::setBirthDate(string birthDate) {
    _strBirthDate = birthDate;
}

Array<Subject> Student::getSubjects() {
    return _arrSubjects;
}

void Student::setSubjects(Array<Subject> subjects) {
    _arrSubjects = subjects;
}

int Student::getSubjectCount() {
    return _iSubjectCount;
}

void Student::setSubjectCount(int subjectCount) {
    _iSubjectCount = subjectCount;
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
        setTextColor(YELLOW);
        cout << "≫ Nhập thông tin môn học thứ " << i << "\n";

        Subject subject = inputSubject();
        arrSubjects.add(subject);
        
        setTextColor(GREEN);
        cout << "≫ Đã thêm thành công môn học " + subject.getSubjectName() + "!\n";
    }

    Student student(strStudentID, strFullName, strBirthDate, arrSubjects, iSubjectCount);
    return student;
}

void Program::inputStudentList() {
    int iSize;
    char cKey;
    string strInput;

    setTextColor(BLUE);
    cout << "≫ Nhập số sinh viên: ";

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

    iSize = stoi(strInput);
    strInput.clear();

    for (int i = 1; i <= iSize; i++) {
        setTextColor(YELLOW);
        cout << "≫ Nhập thông tin sinh viên thứ " << i << "\n";

        Student student = inputStudent();
        _array.add(student);

        setTextColor(GREEN);
        cout << "≫ Đã thêm sinh viên " + student.getFullName() + "!\n";
    }
}

void Program::updateStudentNameByID() {

}

void Program::sortStudentByNameDesc() {

}

void Program::removeStudentByName() {

}

void Program::sortStudentByAVGScoreAsc() {

}

void Program::printScholarshipStudents() {

}

void Program::sortStudentsByBirthYearAsc() {

}


/***************************************************************************
* @Description hàm chạy chương trình.
* @attention: gọi đến các hàm thành phần của chương trình.
****************************************************************************/
void Program::run() {
    setTextColor(WHITE);    
    SetConsoleOutputCP(CP_UTF8);    // Thiết lập mã hóa để console hỗ trợ tiếng Việt

    inputStudentList();

    setTextColor(WHITE);
    cout << "≫ Nhấn phím bất kỳ để đóng chương trình!";
    getch();
}