#include <iostream>
#include <windows.h>
using namespace std;

class LinkedList;

class Base {
public:
    virtual ~Base() = default; 
    virtual void display() const = 0; 
};

class Node {
private:
    Base* _pData;
    Node* _pNext;

public:
    Node(Base* data);
    ~Node();
    void print();
    friend class Stack;
};

class Int : public Base {
private:
    int _iValue;

public: 
    Int(int value);
    void display() const override; 
};

class String : public Base {
private:
    string _strValue;

public: 
    String(const string& value);
    void display() const override; 
};

class Float : public Base {
private:
    float _fValue;

public: 
    Float(float value);
    void display() const override; 
};

class Char : public Base {
private:
    char _cValue;

public: 
    Char(char value);
    void display() const override;
};

class Stack {
private:
    Node* _pTop;
    int _iSize;

public:
    Stack();
    ~Stack();

    int size();
    bool empty();
    void push(Base* data);
    Base* top();
    void pop();
    void clear();
    void print();
};

int main() {
    Stack stack;
    int choice;

    do {
        system("cls");
        cout << "Cho lua chon:\n";
        cout << "1. Int\n";
        cout << "2. String\n";
        cout << "3. Float\n";
        cout << "4. Char\n";
        cout << "5. Thoat va xem stack\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Nhap du lieu (int): ";
                cin >> value;
                stack.push(new Int(value));
                break;
            }

            case 2: {
                string value;
                cout << "Nhap du lieu (string): ";
                cin.ignore(); 
                getline(cin, value);
                stack.push(new String(value));
                break;
            }

            case 3: {
                float value;
                cout << "Nhap du lieu (float): ";
                cin >> value;
                stack.push(new Float(value));
                break;
            }

            case 4: {
                char value;
                cout << "Nhap du lieu (char): ";
                cin >> value;
                stack.push(new Char(value));
                break;
            }

            case 5:
                cout << "Stack thu duoc: ";
                stack.print();

                cout << "\nThoat chuong trinh...\n";
                break;

            default:
                cout << "Khong co lua chon nay!\n";
                break;
        }

    } while (choice != 5);
    return 0;
}

Node::Node(Base* data) : _pData(data), _pNext(nullptr) {}
Node::~Node() {
    delete _pData; 
}

void Node::print() {
    _pData->display();
}

Int::Int(int value) : _iValue(value) {}
void Int::display() const {
    cout << _iValue;
}

String::String(const string& value) : _strValue(value) {}
void String::display() const {
    cout << _strValue;
}

Float::Float(float value) : _fValue(value) {}
void Float::display() const {
    cout << _fValue;
}

Char::Char(char value) : _cValue(value) {}
void Char::display() const {
    cout << _cValue;
}

Stack::Stack() {
    _pTop = nullptr;
    _iSize = 0;
}

Stack::~Stack() {
    this->clear();
}

int Stack::size() {
    return _iSize;
}

bool Stack::empty() {
    return _pTop == nullptr;
}

void Stack::push(Base* data) {
    Node* pNewNode = new Node(data);
    pNewNode->_pNext = _pTop;
    _pTop = pNewNode;
    _iSize++;
}

Base* Stack::top() {
    return _pTop->_pData;
}

void Stack::pop() {
    if (this->empty()) {
        cout << "empty !\n";
        return;
    }

    Node* pDelete = _pTop;
    _pTop = _pTop->_pNext;
    _iSize--;
    delete pDelete;
}

void Stack::clear() {
    Node* pDelete = nullptr;
    while (_pTop != nullptr) {
        pDelete = _pTop;
        _pTop = _pTop->_pNext;
        delete pDelete;
    }
}

void Stack::print() {
    Node* pWalker = _pTop;
    bool first = true;
    while (pWalker != nullptr) {
        if (!first) 
            cout << ", ";
        pWalker->print();
        pWalker = pWalker->_pNext;
        first = false;
    }
}