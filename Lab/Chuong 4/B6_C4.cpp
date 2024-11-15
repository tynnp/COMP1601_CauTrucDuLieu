#include <iostream>
#include <string>
using namespace std;

template<class DataType>
class Queue;

template<class DataType>
class Node {
    friend Queue<DataType>;

private:
    DataType _data;
    Node<DataType>* _pNext;

public:
    Node(DataType data);
    void display() const;
};

template<class DataType>
class Queue {
private:
    Node<DataType>* _pFront;
    Node<DataType>* _pRear; 
    int _iSize;

public:
    Queue();
    ~Queue();

    int size() const;
    bool empty() const;
    void push(const DataType& data);
    DataType front() const;
    void pop();
    void clear();
    void print() const;
};

class Product {
private:
    string _strProductID;
    string _strProductName;
    int _iQuantity;
    float _fPrice;

public:
    Product() {};
    Product(string productID, string productName, int quantity, float price);
    Product(const Product &other);
    ~Product() {};

    string getProductID() const;
    void setProductID(const string& productID);
    string getProductName() const;
    void setProductName(const string& productName);
    int getQuantity() const;
    void setQuantity(int quantity);
    float getPrice() const;
    void setPrice(float price);
    friend istream &operator >> (istream &in, Product &product);
    friend ostream &operator << (ostream &out, const Product &product);
};

class App {
public: 
    void run();

private:
    Queue<Product> products;

    void displayMenu() const;
    void viewAllProducts() const;
    void viewNextProduct() const;
    void addProduct(const Product &product);
    void exportProduct();
};

int main() {
    App app;
    app.run();
    return 0;
}

template<class DataType>
Node<DataType>::Node(DataType data) : _data(data), _pNext(nullptr) {}

template<class DataType>
void Node<DataType>::display() const {
    cout << _data << endl;
}

template<class DataType>
Queue<DataType>::Queue() : _pFront(nullptr), _pRear(nullptr), _iSize(0) {}

template<class DataType>
Queue<DataType>::~Queue() {
    this->clear();
}

template<class DataType>
int Queue<DataType>::size() const {
    return _iSize;
}

template<class DataType>
bool Queue<DataType>::empty() const {
    return _pFront == nullptr;
}

template<class DataType>
void Queue<DataType>::push(const DataType& data) {
    Node<DataType>* pNewNode = new Node<DataType>(data);

    if (_pRear) {
        _pRear->_pNext = pNewNode;
        _pRear = pNewNode;
    } else {
        _pFront = _pRear = pNewNode;
    }
    _iSize++;
}

template<class DataType>
DataType Queue<DataType>::front() const {
    if (_pFront != nullptr)
        return _pFront->_data;
    return DataType(); 
}

template<class DataType>
void Queue<DataType>::pop() {
    if (this->empty()) {
        cout << "empty!\n";
        return;
    }

    Node<DataType>* temp = _pFront;
    _pFront = _pFront->_pNext;
    if (_pFront == nullptr) {
        _pRear = nullptr;
    }
    delete temp;
    _iSize--;
}

template<class DataType>
void Queue<DataType>::clear() {
    while (_pFront != nullptr) {
        pop();
    }
}

template<class DataType>
void Queue<DataType>::print() const {
    Node<DataType>* pWalker = _pFront;
    while (pWalker != nullptr) {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}

Product::Product(string productID, string productName, int quantity, float price) :
    _strProductID(productID), _strProductName(productName), _iQuantity(quantity), _fPrice(price) {}

Product::Product(const Product &other) :
    _strProductID(other._strProductID), _strProductName(other._strProductName),
    _iQuantity(other._iQuantity), _fPrice(other._fPrice) {}

string Product::getProductID() const {
    return _strProductID;
}

void Product::setProductID(const string& productID) {
    _strProductID = productID;
}

string Product::getProductName() const {
    return _strProductName;
}

void Product::setProductName(const string& productName) {
    _strProductName = productName;
}

int Product::getQuantity() const {
    return _iQuantity;
}

void Product::setQuantity(int quantity) {
    _iQuantity = quantity;
}

float Product::getPrice() const {
    return _fPrice;
}

void Product::setPrice(float price) {
    _fPrice = price;
}

istream &operator >> (istream &in, Product &product) {
    cout << "Ma hang hoa: ";
    in >> product._strProductID;
    in.ignore();

    cout << "Ten hang hoa: ";
    getline(in, product._strProductName);

    cout << "So luong: ";
    in >> product._iQuantity;

    cout << "Don gia: ";
    in >> product._fPrice;
    return in;
}

ostream &operator << (ostream &out, const Product &product) {
    out << "Ma hang hoa: " << product._strProductID << endl;
    out << "Ten hang hoa: " << product._strProductName << endl;
    out << "So luong: " << product._iQuantity << endl;
    out << "Don gia: " << product._fPrice << endl;
    return out;
}

void App::viewAllProducts() const {
    if (products.empty()) {
        cout << "Khong co mat hang nao!\n";
        return;
    }

    cout << "Tat ca mat hang:\n";
    products.print();
}

void App::viewNextProduct() const {
    if (products.empty()) {
        cout << "Khong co mat hang nao!\n";
        return;
    }

    cout << products.front();
}

void App::addProduct(const Product &product) {
    products.push(product);
    cout << "Them thanh cong!\n";
}

void App::exportProduct() {
    if (products.empty()) {
        cout << "Khong co mat hang nao!\n";
        return;
    }

    cout << "Xuat mat hang: ";
    cout << products.front();
    products.pop();
}

void App::displayMenu() const {
    cout << "-----------------Chuong trinh quan ly kho-----------------\n";
    cout << "1. Xem tat ca hang hoa trong kho.\n";
    cout << "2. Xem mat hang sap duoc xuat kho.\n";
    cout << "3. Them mot mat hang vao kho.\n";
    cout << "4. Xuat mot mat hang ra khoi kho.\n";
    cout << "5. Thoat chuong trinh.\n";
    cout << "----------------------------------------------------------\n";
}

void App::run() {
    string strTmp;
    int iChoice = 0;

    while (iChoice != 5) {
        system("cls");
        displayMenu();
        cout << "Nhap lua chon: ";
        cin >> iChoice;
        cin.ignore(); 

        switch (iChoice) {
            case 1: {
                viewAllProducts();
                cout << "Nhan enter de tiep tuc: ";
                getline(cin, strTmp);
                break;
            }

            case 2: {
                viewNextProduct();
                cout << "Nhan enter de tiep tuc: ";
                getline(cin, strTmp);
                break;
            }

            case 3: {
                Product product;
                cin >> product;
                cin.ignore();
                addProduct(product);
                cout << "Nhan enter de tiep tuc: ";
                getline(cin, strTmp);
                break;
            }

            case 4: {
                exportProduct();
                cout << "Nhan enter de tiep tuc: ";
                getline(cin, strTmp);
                break;
            }

            case 5: {
                cout << "Thoat chuong trinh...";
                break;
            }

            default: {
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
    }
}
