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

bool toanTu(string str);
int tinh(int a, int b, char c);

int main() {
    string str, tmp;
    Stack<int> stack;

    cout << "Nhap bieu thuc hau to (co khoang trang): ";
    getline(cin, str);
    stringstream ss(str);

    while (ss >> tmp) {
        if (!toanTu(tmp))
            stack.push(stoi(tmp));
        else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(tinh(a, b, tmp[0]));
        }
    }

    cout << "Ket qua: ";
    cout << stack.top();
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

bool toanTu(string str) {
    char c = str[0];
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int tinh(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
} 