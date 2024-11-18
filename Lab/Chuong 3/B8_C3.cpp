#include <iostream>
#include <sstream>
#include <windows.h>
using namespace std;

template<class DataType>
class LinkedList;
class App;

template<class DataType>
class Node {
    friend LinkedList<DataType>;
    friend App;

private:
    DataType _data;
    Node<DataType>* _pNext;

public:
    Node(DataType data);
};

template<class DataType>
class LinkedList {
    friend class App;

private: 
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;

public:
    LinkedList();
    ~LinkedList();

    void add(DataType element);
    void add(int index, DataType element);
    void addAll(const LinkedList<DataType> &otherList);
    void addAll(int index, const LinkedList<DataType> &otherList);
    void addFirst(DataType element);
    void addLast(DataType element);
    void addAfter(Node<DataType>* node, DataType element);
    DataType get(int index);
    DataType getFirst();
    DataType getLast();
    Node<DataType>* search(DataType element);
    Node<DataType>* searchPre(DataType element);
    int indexOf(DataType element);
    int lastIndexOf(DataType element);
    void remove(DataType element);
    void removeFirst();
    void removeLast();
    void removeAfter(Node<DataType>* node);
    int size();
    bool empty();
    void print();
    void clear();
    void sort();
    void reSort();
};

class Video {
private:
    string _strTitle;
    string _strGenre;
    string _strDirector;
    string _strLeadActor;
    string _strLeadActress;
    int _iReleaseYear;

public:
    Video() {};
    Video(string title, string genre, string director, string leadActor, string leadActress, int releaseYear);
    Video(const Video &other);
    ~Video() {};

    string getTitle();
    void setTitle(string title);
    string getGenre();
    void setGenre(string genre);
    string getDirector();
    void setDirector(string director);
    string getLeadActor();
    void setLeadActor(string leadActor);
    string getLeadActress();
    void setLeadActress(string leadActor);
    int getReleaseYear();
    void setReleaseYear(int releaseYear);

    friend ostream &operator << (ostream &out, Video &video);
    bool operator == (const Video &other);
    bool operator > (const Video &other);
};

class App {
private:
    LinkedList<Video> lists;

    void displayMenu();
    void loadVideos();
    void updateGenre(string title, string newGenre);
    void printVideos();
    void findMoviesByActor(string actorName);
    void statsByDirector();
    void printTop3Newest();

public:
    void run();

};

int main() {
    App app;
    app.run();
    return 0;
}

template<class DataType>
Node<DataType>::Node(DataType data) {
    _data = data;
    _pNext = nullptr;
}

template<class DataType>
LinkedList<DataType>::LinkedList() {
    _iSize = 0;
    _pHead = _pTail = nullptr;
}

template<class DataType> 
LinkedList<DataType>::~LinkedList() {
    this->clear();
}

template<class DataType>
void LinkedList<DataType>::add(DataType element) {
    if (_pHead == nullptr) 
        this->addFirst(element);
    else 
        this->addLast(element);
}

template<class DataType>
void LinkedList<DataType>::add(int index, DataType element) {
    // Trường hợp index ngoài list
    if (index < 0 || index > _iSize) 
        return;
    

    // Thêm đầu danh sách
    if (index == 0) {
        this->addFirst(element);
        return;
    }

    int iIdx = 0;
    Node<DataType>* pWalker = _pHead;
    Node<DataType>* pNewNode = new Node<DataType>(element);

    while (iIdx < index - 1) {
        pWalker = pWalker->_pNext;
        iIdx++;
    } 

    pNewNode->_pNext = pWalker->_pNext;
    pWalker->_pNext = pNewNode;

    // Trường hợp thêm cuối
    if (pWalker == _pTail) 
        _pTail = pNewNode;
    _iSize++;
}

template<class DataType>
void LinkedList<DataType>::addAll(const LinkedList<DataType> &otherList) {
    if (otherList._pHead == nullptr) 
        return;

    Node<DataType>* current = otherList._pHead;

    while (current != nullptr) {
        this->add(current->_data);
        current = current->_pNext;
    }
}


template<class DataType>
void LinkedList<DataType>::addAll(int index, const LinkedList<DataType> &otherList) {
    if (index < 0 || index > _iSize || otherList._pHead == nullptr)
        return;

    Node<DataType>* pCurrent = otherList._pHead;
    LinkedList<DataType> tempList;

    // Sao chép 
    while (pCurrent != nullptr) {
        tempList.add(pCurrent->data);  
        pCurrent = pCurrent->_pNext;
    }

    // Chèn 
    if (index == 0) {
        // Trường hợp thêm vào đầu danh sách
        tempList._pTail->_pNext = _pHead;
        _pHead = tempList._pHead;

        if (_pTail == nullptr)  
            _pTail = tempList._pTail;

    } else {
        Node<DataType>* pWalker = _pHead;
        for (int i = 0; i < index - 1; i++) {
            pWalker = pWalker->_pNext;
        }

        // Chèn vào giữa danh sách hiện tại
        Node<DataType>* pNext = pWalker->_pNext;
        pWalker->_pNext = tempList._pHead;
        tempList._pTail->_pNext = pNext;

        // Trường hợp thêm vào cuối 
        if (pNext == nullptr)
            _pTail = tempList._pTail;
    }

    _iSize += tempList._iSize;
    tempList._pHead = nullptr;
    tempList._pTail = nullptr;
    tempList._iSize = 0;
}


template<class DataType>
void LinkedList<DataType>::addFirst(DataType element) {
    Node<DataType>* pNewNode = new Node<DataType>(element);

    if (_pHead == nullptr) {
        _pHead = _pTail = pNewNode;
        _iSize++;
        return;
    }

    pNewNode->_pNext = _pHead;
    _pHead = pNewNode;
    _iSize++;
}

template<class DataType>
void LinkedList<DataType>::addLast(DataType element) {
    if (_pHead == nullptr)
        this->addFirst(element);

    Node<DataType>* pNewNode = new Node<DataType>(element);
    _pTail->_pNext = pNewNode;
    _pTail = pNewNode;
    _iSize++;

}

template<class DataType>
void LinkedList<DataType>::addAfter(Node<DataType>* node, DataType element) {
    if (node == nullptr) 
        return;
    
    Node<DataType>* pNewNode = new Node<DataType>(element);
    pNewNode->_pNext = node->_pNext;
    node->_pNext = pNewNode;
    
    if (node == _pTail) 
        _pTail = pNewNode;
    _iSize++;
}

template<class DataType>
DataType LinkedList<DataType>::get(int index) {
    int iIdx = 0;
    Node<DataType>* pWalker = _pHead;

    while (iIdx < index) {
        pWalker = pWalker->_pNext;
        iIdx++;
    }

    return pWalker->_data;
}

template<class DataType>
DataType LinkedList<DataType>::getFirst() {
    return _pHead->_data;
}

template<class DataType>
DataType LinkedList<DataType>::getLast() {
    return _pTail->_data;
}

template<class DataType>
Node<DataType>* LinkedList<DataType>::search(DataType element) {
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == element)
            return pWalker;
        pWalker = pWalker->_pNext;
    }

    return nullptr;
}

template<class DataType>
Node<DataType>* LinkedList<DataType>::searchPre(DataType element) {
    if (_pHead == nullptr)
        return nullptr;

    if (_pHead->_data == element)
        return nullptr;

    Node<DataType>* pWalker = _pHead;

    while (pWalker->_pNext != nullptr) {
        if (pWalker->_pNext->_data == element)
            return pWalker;
        pWalker = pWalker->_pNext;
    }

    return nullptr;
}

template<class DataType>
int LinkedList<DataType>::indexOf(DataType element) {
    int iIdx = 0;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == element)
            return iIdx;
        pWalker = pWalker->_pNext;
        iIdx++;
    }

    return -1;
}

template<class DataType>
int LinkedList<DataType>::lastIndexOf(DataType element) {
    int iIdx = 0, iLastIdx = -1;
    Node<DataType>* pWalker = _pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data == element)
            iLastIdx = iIdx;
        pWalker = pWalker->_pNext;
        iIdx++;
    }

    return iLastIdx;
}

template<class DataType>
void LinkedList<DataType>::remove(DataType element) {
    Node<DataType>* pPre = this->searchPre(element);
    // Nếu tìm không thấy
    if (pPre == nullptr && _pHead->_data != element) 
        return;
    
    Node<DataType>* pDeleteNode = (pPre == nullptr) ? _pHead : pPre->_pNext;

    // Nếu node cần xóa là node đầu tiên
    if (pDeleteNode == _pHead) {
        _pHead = _pHead->_pNext;
        if (_pHead == nullptr) 
            _pTail = nullptr;
    } else {
        pPre->_pNext = pDeleteNode->_pNext;
        if (pDeleteNode == _pTail) 
            _pTail = pPre;
    }

    delete pDeleteNode;
    _iSize--;
}

template<class DataType>
void LinkedList<DataType>::removeFirst() {
    if (_pHead == nullptr) 
        return;

    Node<DataType>* pDeleteNode = _pHead;
    _pHead = _pHead->_pNext;
    if (_pHead == nullptr) 
        _pTail = nullptr;

    delete pDeleteNode;
    _iSize--;
}

template<class DataType>
void LinkedList<DataType>::removeLast() {
    if (_pTail == nullptr) 
        return;
    
    if (_pHead == _pTail) {
        delete _pHead;
        _pHead = _pTail = nullptr;
        return; 
    } 

    Node<DataType>* pWalker = _pHead;
    while (pWalker->_pNext != _pTail)
        pWalker = pWalker->_pNext;

    delete _pTail;
    _pTail = pWalker;
    _pTail->_pNext = nullptr;
    _iSize--;
}

template<class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType>* node) {
    if (node == nullptr || node->_pNext == nullptr) 
        return;

    Node<DataType>* pDeleteNode = node->_pNext;
    node->_pNext = pDeleteNode->_pNext;

    if (pDeleteNode == _pTail) 
        _pTail = node;

    delete pDeleteNode;
    _iSize--;
}

template<class DataType>
int LinkedList<DataType>::size() {
    return _iSize;
}

template<class DataType>
bool LinkedList<DataType>::empty() {
    return _iSize == 0;
}

template<class DataType>
void LinkedList<DataType>::print() {
    if (_iSize == 0)
        cout << "Trong!\n";

    Node<DataType>* pWalker = _pHead;
    while (pWalker != nullptr) {
        cout << pWalker->_data;
        pWalker = pWalker->_pNext;
    }

    cout << '\n';
}

template<class DataType>
void LinkedList<DataType>::clear() {
    while (_pHead != nullptr) {
        Node<DataType>* pDeleteNode = _pHead;
        _pHead = _pHead->_pNext;
        delete pDeleteNode;
    }
    _pTail = nullptr;
    _iSize = 0;
}

template<class DataType>
void LinkedList<DataType>::sort() {
    if (_pHead == nullptr)
        return;

    Node<Video>* i = _pHead;
    Node<Video>* j = nullptr;

    while (i->_pNext != nullptr) {
        j = i->_pNext;
        while (j != nullptr) {
            if (i->_data > j->_data) 
                swap(i->_data, j->_data);
            j = j->_pNext;
        }
        i = i->_pNext;
    }
}

template<class DataType> 
void LinkedList<DataType>::reSort() {
    if (_pHead == nullptr)
        return;

    Node<Video>* i = _pHead;
    Node<Video>* j = nullptr;

    while (i->_pNext != nullptr) {
        j = i->_pNext;
        while (j != nullptr) {
            if (j->_data > i->_data) 
                swap(i->_data, j->_data);
            j = j->_pNext;
        }
        i = i->_pNext;
    }
}

Video::Video(string title, string genre, string director, string leadActor, string leadActress, int releaseYear) {
    _strTitle = title;
    _strGenre = genre;
    _strDirector = director;
    _strLeadActor = leadActor;
    _strLeadActress = leadActress;
    _iReleaseYear = releaseYear;
}

Video::Video(const Video &other) {
    _strTitle = other._strTitle;
    _strGenre = other._strGenre;
    _strDirector = other._strDirector;
    _strLeadActor = other._strLeadActor;
    _strLeadActress = other._strLeadActress;
    _iReleaseYear = other._iReleaseYear;
}

string Video::getTitle() {
    return _strTitle;
}

void Video::setTitle(string title) {
    _strTitle = title;
}

string Video::getGenre() {
    return _strGenre;
}

void Video::setGenre(string genre) {
    _strGenre = genre;
}

string Video::getDirector() {
    return _strDirector;
}

void Video::setDirector(string director) {
    _strDirector = director;
}

string Video::getLeadActor() {
    return _strLeadActor;
}

void Video::setLeadActor(string leadActor) {
    _strLeadActor = leadActor;
}

string Video::getLeadActress() {
    return _strLeadActress;
}

void Video::setLeadActress(string leadActress) {
    _strLeadActress = leadActress;
}

int Video::getReleaseYear() {
    return _iReleaseYear;
}

void Video::setReleaseYear(int releaseYear) {
    _iReleaseYear = releaseYear;
}

ostream &operator << (ostream &out, Video &video) {
    out << "Ten phim: " << video._strTitle << '\n';
    out << "The loai: " << video._strGenre << '\n';
    out << "Ten dao dien: " << video._strDirector << '\n';
    out << "Ten dien vien nam chinh: " << video._strLeadActor << '\n';
    out << "Ten dien vien nu chinh: " << video._strLeadActress << '\n';
    out << "Nam san xuat: " << video._iReleaseYear << "\n\n";
    return out;
}

bool Video::operator == (const Video &other) {
    return _strTitle == other._strTitle;
}

bool Video::operator > (const Video &other) {
    return _iReleaseYear > other._iReleaseYear;
}

void App::loadVideos() {
    int iSize;
    cout << "Nhap so luong phim: ";
    cin >> iSize;
    cin.ignore();

    for (int i = 1; i <= iSize; i++) {
        string strInput;
        cout << "Nhan thong tin phim thu " << i << ": ";
        getline(cin, strInput);

        if (strInput[strInput.size() - 1] != '#')   
            strInput += '#';

        stringstream inputStream(strInput);
        string title, genre, director, leadActor, leadActress, releaseYearStr;
        int releaseYear;

        getline(inputStream, title, '#');
        getline(inputStream, genre, '#');
        getline(inputStream, director, '#');
        getline(inputStream, leadActor, '#');
        getline(inputStream, leadActress, '#');
        getline(inputStream, releaseYearStr, '#');
        releaseYear = stoi(releaseYearStr);

        Video video(title, genre, director, leadActor, leadActress, releaseYear);
        lists.add(video);
    }

    cout << "Da them thanh cong!\n";
}

void App::updateGenre(string title, string newGenre) {
    Node<Video>* pWalker = lists._pHead;

    while (pWalker != nullptr) {
        if (pWalker->_data.getTitle() == title) {
            pWalker->_data.setGenre(newGenre);
            cout << "Da doi thanh cong!\n";
            return;
        }
        pWalker = pWalker->_pNext;
    }

    cout << "Khong tim thay!\n";
}

void App::printVideos() {
    lists.print();
}

void App::findMoviesByActor(string actorName) {
    Node<Video>* pWalker = lists._pHead;
    while (pWalker != nullptr) {
        if (pWalker->_data.getLeadActor() == actorName) 
            cout << pWalker->_data.getTitle() << '\n';
        pWalker = pWalker->_pNext;
    }
}

void App::statsByDirector() {
    LinkedList<string> directorList;
    Node<Video>* pWalker = lists._pHead;

    while (pWalker != nullptr) {
        string directorName = pWalker->_data.getDirector();
        if (directorList.search(directorName) == nullptr)
            directorList.add(directorName);
        pWalker = pWalker->_pNext;
    }

    Node<string>* pDirectorWalker = directorList._pHead;
    while (pDirectorWalker != nullptr) {
        int iCount = 0;
        LinkedList<Video> videoList;
        pWalker = lists._pHead;

        while (pWalker != nullptr) {
            if (pWalker->_data.getDirector() == pDirectorWalker->_data) {
                videoList.add(pWalker->_data);
                iCount++;
            }
            pWalker = pWalker->_pNext;
        }

        cout << "Dao dien: " << pDirectorWalker->_data << ":\n";
        cout << "So luong phim: " << iCount << '\n';
        cout << "Thong tin phim:\n";
        videoList.print();
        pDirectorWalker = pDirectorWalker->_pNext;
    }
}

void App::printTop3Newest() {
    LinkedList<Video> resultList;
    lists.reSort();

    Node<Video>* pWalker = lists._pHead;
    for (int i = 0; i < 3; i++) {
        resultList.add(pWalker->_data);
        pWalker = pWalker->_pNext;
    }

    resultList.print();
}

void App::displayMenu() {
    cout << "-----------------Chuong trinh quan ly phim-----------------\n";
    cout << "1. Nhap danh sach phim.\n";
    cout << "2. Cap nhat the loai phim.\n";
    cout << "3. In danh sach phim.\n";
    cout << "4. Tim phim theo ten dien vien nam.\n";
    cout << "5. Thong ke phim theo dao dien.\n";
    cout << "6. Tim 3 bo phim moi nhat.\n";
    cout << "7. Thoat chuong trinh.\n";
    cout << "-----------------------------------------------------------\n";
}

void App::run() {
    int iChoice = 0;
    string strTmp;

    while (iChoice != 7) {
        system("cls");
        this->displayMenu();
        cout << "Nhap lua chon: ";
        cin >> iChoice;
        cin.ignore();

        switch (iChoice) {
            case 1: {
                system("cls");
                this->loadVideos();
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 2: {
                system("cls");
                string title, newGenre;

                cout << "Nhap ten phim: ";
                getline(cin, title);

                cout << "Nhap the loai moi: ";
                getline(cin, newGenre);

                this->updateGenre(title, newGenre);
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 3: {
                system("cls");
                this->printVideos();
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 4: {
                system("cls");
                string actorName;
                cout << "Nhap ten dien vien nam: ";
                getline(cin, actorName);
                this->findMoviesByActor(actorName);
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 5: {
                system("cls");
                this->statsByDirector();
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 6: {
                system("cls");
                this->printTop3Newest();
                cout << "Nhan enter de quay lai: ";
                getline(cin, strTmp);
                break;
            }

            case 7: {
                cout << "Thoat chuong trinh.";
                break;
            }
        }
    }
}