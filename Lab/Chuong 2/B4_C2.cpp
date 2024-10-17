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
    int size();                 // Lấy số phần tử của mảng

    int find(DataType item, int index = 0); // Tìm chỉ số của phần tử item từ chỉ số index
    void removeAtIndex(int index);          // Xoá phần tử tại vị trí index
    bool removeAll(DataType item);          // Xoá hết phần tử có giá trị item
    DataType getAt(int index);              // Lấy giá trị của phần tử tại vị trí index
    void sortAsc();                         // Hàm sắp xếp tăng dần mảng
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
    Array<int> _array;              // Đối tượng mảng để lưu trữ các phần tử
    int countDigit(string input);   // Đếm số phần tử số hợp lệ trong chuỗi đầu vào
    void setTextColor(int color);   // Đổi màu chữ hiển thị trên console

public:
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

/***************************************************************************
* @Description hàm chạy chương trình.
* @attention: gọi đến các hàm thành phần của chương trình.
****************************************************************************/
void Program::run() {
    setTextColor(WHITE);    
    SetConsoleOutputCP(CP_UTF8);    // Thiết lập mã hóa để console hỗ trợ tiếng Việt

    cout << "≫ Nhấn phím bất kỳ để đóng chương trình!";
    getch();
}