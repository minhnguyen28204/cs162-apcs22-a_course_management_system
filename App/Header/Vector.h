template<typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int size;

public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        size = 0;
    }

    T* begin() {
        return arr;
    }

    T* end() {
        return arr+size;
    }

    void push_back(T val) {
        if (size == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size++] = val;
    }

    void pop_back() {
        size--;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    ~Vector() {
        delete[] arr;
    }
};

