#include <iostream>
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

bool isValidParentheses(const string &str);

int main() {
    string str;
    cout << "Nhap chuoi can kiem tra (khong khoang trang): ";
    getline(cin, str);

    if (isValidParentheses(str))
        cout << "Xau ngoac dung!";
    else 
        cout << "Xau ngoac khong dung!";

    return 0;
}

template<class DataType>
Node<DataType>::Node(DataType data) {
    _data = data;
    _pNext = nullptr;
}

template<class DataType>
void Node<DataType>::display() {
    cout << _data;
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

bool isValidParentheses(const string &str) {
    Stack<char> s;
    
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);

        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();
            if (
                (c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')
            )
                return false;
        }
    }

    return s.empty();
}