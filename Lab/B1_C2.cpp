#include <iostream>
using namespace std;

template<class DataType>
class Array {
private:
    DataType* _items;
    int _iLength;

public:
    Array();
    ~Array();

    int size();
    bool empty();
    void clear();
    bool add(DataType item);
    DataType getAt(int index);
    int find(DataType item, int index = 0);
    bool removeAt(int index);
    bool removeAll(DataType item);
};

int main() {
    int n, x;
    Array<int> a;
    
    cin >> n >> x;
    while (n--) {
        int tmp;
        cin >> tmp;
        a.add(tmp);
    }
        
    cout << "So luong phan tu: " << a.size() << endl;
    
    if (!a.empty()) {
        for (int i = 0; i < a.size(); i++)
            cout << a.getAt(i) << " ";
        cout << endl;
    } else 
        cout << "empty!" << endl;
    
    if (a.removeAll(x)) 
        cout << "da xoa " << x << "!" << endl;
    else 
        cout << "khong co " << x << " trong mang!" << endl;
    
    if (!a.empty()) {
        for (int i = 0; i < a.size(); i++)
            cout << a.getAt(i) << " ";
        cout << endl;
    } else 
        cout << "empty!" << endl;
    
    cout << "So luong phan tu con lai: " << a.size() << endl;
    
    return 0;
}

template<class DataType>
Array<DataType>::Array() {
    _items = new DataType[100];
    _iLength = 0;
}

template<class DataType>
Array<DataType>::~Array() {
    this->clear();
}

template<class DataType>
int Array<DataType>::size() {
    return _iLength;
}

template<class DataType>
bool Array<DataType>::empty() {
    return _iLength == 0;
}

template<class DataType>
void Array<DataType>::clear() {
    delete[] _items;
    _iLength = 0;
}

template<class DataType>
bool Array<DataType>::add(DataType item) {
    if (_iLength < 100) {
        _items[_iLength] = item;
        _iLength += 1; 
        return true;
    }

    return false;
}

template<class DataType>
DataType Array<DataType>::getAt(int index) {
    return _items[index];
}

template<class DataType>
int Array<DataType>::find(DataType item, int index) {
    for (int i = index; i < _iLength; i++)
        if (_items[i] == item)
            return i; 
    return -1;
}

/***************************************************************************
* @Description xóa phần tử tại vị trí index.
* @param index: vị trí cần xóa.
* @return true nếu xóa thành công, false nếu vị trí không hợp lệ.
****************************************************************************/
template<class DataType>
bool Array<DataType>::removeAt(int index) {
    if (index < 0 || index >= _iLength)
        return false;

    for (int i = index; i < _iLength - 1; i++)
        _items[i] = _items[i + 1];
    _iLength -= 1;
    return true;
}

/***************************************************************************
* @Description xóa tất cả phần tử có giá trị bằng với item.
* @param item: giá trị phần tử cần xóa.
* @return true nếu xóa thành công, false nếu không xóa phần tử nào.
****************************************************************************/
template<class DataType>
bool Array<DataType>::removeAll(DataType item) {
    int _iIdx = this->find(item);
    if (_iIdx == -1) 
        return false;

    while (_iIdx != -1) {
        this->removeAt(_iIdx);
        _iIdx = this->find(item, _iIdx);
    }

    return true;
}