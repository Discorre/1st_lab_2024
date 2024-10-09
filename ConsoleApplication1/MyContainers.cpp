//#include <iostream>
//#include <stdexcept>
//
//template <typename T>
//class MyList2 {
//private:
//    struct Node {
//        T data;
//        Node* next;
//        Node(T data) : data(data), next(nullptr) {}
//    };
//
//    Node* head;
//    Node* tail;
//    int length;
//
//public:
//    // �����������
//    MyList2() : head(nullptr), tail(nullptr), length(0) {}
//
//    // ����������
//    ~MyList2() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    // ���������� �������� � ����� ������
//    void push_back(T element) {
//        Node* newNode = new Node(element);
//        if (tail == nullptr) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//        }
//        length++;
//    }
//
//    // ���������� �������� � ������ ������
//    void push_front(T element) {
//        Node* newNode = new Node(element);
//        if (head == nullptr) {
//            head = tail = newNode; // ���� ������ ����, ����� ���� ���������� � �������, � �������
//        }
//        else {
//            newNode->next = head; // ����� ���� ��������� �� ������� ������
//            head = newNode; // ����� ���� ���������� ����� �������
//        }
//        length++;
//    }
//
//    // �������� �������� � ������ ������
//    T pop_front() {
//        if (head == nullptr) {
//            throw std::out_of_range("List is empty");
//        }
//        Node* temp = head;
//        T data = temp->data;
//        head = head->next;
//        if (head == nullptr) {
//            tail = nullptr;
//        }
//        delete temp;
//        length--;
//        return data;
//    }
//
//    // ����� get ��� ��������� �������� �� �������
//    T get(int index) const {
//        if (index < 0 || index >= length) {
//            throw std::out_of_range("Index out of range");
//        }
//        Node* current = head;
//        for (int i = 0; i < index; ++i) {
//            current = current->next;
//        }
//        return current->data;
//    }
//
//    // ��������� ����� ������
//    int size() const {
//        return length;
//    }
//
//    // ����� ��� ������ ��������� ������
//    void print() const {
//        Node* current = head;
//        std::cout << "List: ";
//        while (current != nullptr) {
//            std::cout << current->data << " -> ";
//            current = current->next;
//        }
//        std::cout << "nullptr" << std::endl;
//    }
//};
//
//
//template <typename T>
//class MyVector {
//private:
//    T* data;        // ��������� �� ������ ���������
//    int capacity;   // ������� ������� �������
//    int length;     // ������� ����� �������
//
//public:
//    // ����������� �� ���������
//    MyVector(int size = 10) : capacity(10), length(0) {
//        data = new T[capacity];  // ������������� ������� � ��������� ��������
//    }
//
//    // ����������
//    ~MyVector() {
//        delete[] data; // ������������ ���������� ������
//    }
//
//    // ����� ��� ���������� �������� � ����� �������
//    void push_back(const T& element) {
//        if (length == capacity) {
//            resize(); // ���������� �������, ���� ������ �����
//        }
//        data[length++] = element; // ���������� �������� � ���������� �����
//    }
//
//    // ����� ��� ���������� �������� �� �������
//    void insert(int index, const T& element) {
//        if (index < 0 || index > length) {
//            throw std::out_of_range("Index out of range");
//        }
//        if (length == capacity) {
//            resize(); // ���������� �������, ���� ������ �����
//        }
//        // ����� ��������� ������, ����� ���������� �����
//        for (int i = length; i > index; --i) {
//            data[i] = data[i - 1];
//        }
//        data[index] = element; // ������� ��������
//        length++; // ���������� �����
//    }
//
//    // ����� ��� �������� �������� �� �������
//    void erase(int index) {
//        if (index < 0 || index >= length) {
//            throw std::out_of_range("Index out of range");
//        }
//        // ����� ��������� �����, ����� ��������� ������
//        for (int i = index; i < length - 1; ++i) {
//            data[i] = data[i + 1];
//        }
//        length--; // ���������� �����
//    }
//
//    // ����� ��� ��������� �������� �� ������� (������������� ������)
//    T& get(int index) {
//        if (index < 0 || index >= length) {
//            throw std::out_of_range("Index out of range");
//        }
//        return data[index]; // ���������� �������
//    }
//
//    // ����������� ������ ������ get
//    const T& get(int index) const {
//        if (index < 0 || index >= length) {
//            throw std::out_of_range("Index out of range");
//        }
//        return data[index]; // ���������� �������
//    }
//
//    // ����� ��� ������ �������� �� �������
//    void set(int index, const T& element) {
//        if (index < 0 || index >= length) {
//            throw std::out_of_range("Index out of range");
//        }
//        data[index] = element; // ������ ��������
//    }
//
//    // ���������� ������� �������
//    void resize() {
//        capacity *= 2; // ����������� ������� � ��� ����
//        T* newData = new T[capacity]; // ������� ����� ������ � ����� ��������
//        for (int i = 0; i < length; i++) {
//            newData[i] = data[i]; // �������� ������ ������ � ����� ������
//        }
//        delete[] data; // ����������� ������ ������
//        data = newData; // �������������� ��������� �� ����� ������
//    }
//
//    // ����� ��� ��������� ������� ����� �������
//    int size() const {
//        return length; // ���������� �����
//    }
//
//    // ����� ��� ������ ���� ��������� �������
//    void print() const {
//        for (int i = 0; i < length; i++) {
//            std::cout << data[i] << " "; // ������� ������ �������
//        }
//        std::cout << std::endl; // ������� �� ����� ������
//    }
//};