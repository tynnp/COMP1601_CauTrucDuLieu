#include <iostream>
#include <sstream>
using namespace std;

template<class DataType>
class Stack;

template<class DataType>
class Node {
    friend Stack<DataType>;

private:
    DataType _data;
    Node<DataType>* _pNext;

public:
    Node(DataType data);
    void display();
};

template<class DataType>
class Stack {
private:
    Node<DataType>* _pTop;
    int _iSize;

public:
    Stack();
    ~Stack();

    int size();
    bool empty();
    void push(DataType data);
    DataType top();
    void pop();
    void clear();
    void print();
};

void quickSort(int arr[], int size);

int main() {
    int iSize;
    int arr[100];

    cout << "Nhap so luong phan tu cua mang: ";
    cin >> iSize;

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < iSize; i++)
        cin >> arr[i];

    cout << "Mang da nhap: ";
    for (int i = 0; i < iSize; i++)
        cout << arr[i] << ' ';
    cout << endl;

    quickSort(arr, iSize);
    cout << "Mang da sap xep: ";
    for (int i = 0; i < iSize; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}

template<class DataType>
Node<DataType>::Node(DataType data) {
    _data = data;
    _pNext = nullptr;
}

template<class DataType>
void Node<DataType>::display() {
    cout << _data << " ";
}

template<class DataType>
Stack<DataType>::Stack() {
    _pTop = nullptr;
    _iSize = 0;
}

template<class DataType>
Stack<DataType>::~Stack() {
    this->clear();
}

template<class DataType>
int Stack<DataType>::size() {
    return _iSize;
}

template<class DataType>
bool Stack<DataType>::empty() {
    return _pTop == nullptr;
}

template<class DataType>
void Stack<DataType>::push(DataType data) {
    Node<DataType>* pNewNode = new Node<DataType>(data);
    pNewNode->_pNext = _pTop;
    _pTop = pNewNode;
    _iSize++;
}

template<class DataType>
DataType Stack<DataType>::top() {
    return _pTop->_data;
}

template<class DataType>
void Stack<DataType>::pop() {
    if (this->empty()) {
        cout << "empty !\n";
        return;
    }

    Node<DataType>* pDelete = _pTop;
    _pTop = _pTop->_pNext;
    _iSize--;
    delete pDelete;
}

template<class DataType>
void Stack<DataType>::clear() {
    Node<DataType>* pDelete = nullptr;
    while (_pTop != nullptr) {
        pDelete = _pTop;
        _pTop = _pTop->_pNext;
        delete pDelete;
    }
}

template<class DataType>
void Stack<DataType>::print() {
    Node<DataType>* pWalker = _pTop;
    while (pWalker != nullptr) {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}

void quickSort(int arr[], int size) {
    Stack<int> leftStack, rightStack;

    leftStack.push(0);
    rightStack.push(size - 1);

    while (!leftStack.empty()) {
        int iLeft = leftStack.top();
        leftStack.pop();

        int iRight = rightStack.top();
        rightStack.pop();

        if (iLeft >= iRight)
            continue;

        int x = arr[(iLeft + iRight) / 2];
        int i = iLeft, j = iRight;

        while (i <= j) {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (iLeft < j) {
            leftStack.push(iLeft);
            rightStack.push(j);
        }

        if (i < iRight) {
            leftStack.push(i);
            rightStack.push(iRight);
        }
    }
}