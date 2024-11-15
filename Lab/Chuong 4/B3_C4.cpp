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

int priority(char c);
Stack<string> infixToPostfix(string str);

int main() {
    string str;
    cout << "Nhap chuoi trung to (co khoang trang): "; // 3 + 4 * 2 / ( 1 - 5 ) 
    getline(cin, str);

    Stack<string> res = infixToPostfix(str);
    res.print();
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

int priority(char c) {
    if (c == '^') return 5;
    if (c == '*') return 4;
    if (c == '/') return 3;
    if (c == '+') return 2;
    if (c == '-') return 1;
    return 0;
}

Stack<string> infixToPostfix(string str) {
    string tmp;
    Stack<string> stackTmp, reverseRes, res;
    stringstream ss(str);

    while (ss >> tmp) {
        if (isdigit(tmp[0]))
            reverseRes.push(tmp);

        else if (tmp[0] == '(')
            stackTmp.push(tmp);

        else if (tmp[0] == ')') {
            while (!stackTmp.empty() && stackTmp.top() != "(") {
                reverseRes.push(stackTmp.top());
                stackTmp.pop();
            }

            if (!stackTmp.empty())   
                stackTmp.pop();

        } else {
            while (!stackTmp.empty() && priority(stackTmp.top()[0]) > priority(tmp[0])) {
                reverseRes.push(stackTmp.top());
                stackTmp.pop();
            }

            stackTmp.push(tmp);
        }
    }

    while (!stackTmp.empty()) {
        reverseRes.push(stackTmp.top());
        stackTmp.pop();
    }

    while (!reverseRes.empty()) {
        res.push(reverseRes.top());
        reverseRes.pop();
    }

    return res;
}