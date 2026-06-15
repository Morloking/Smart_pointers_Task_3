#include <iostream>
#include <memory>

template <typename T>
class UniquePointer {
public:
    UniquePointer(T* ptr) : 
        ptr(ptr)
    {};
    UniquePointer(const UniquePointer&) = delete;
    T& operator=(const UniquePointer&) = delete;

    T& operator*() {
        return *ptr;
    }

    T* release() {
        T* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }

    ~UniquePointer() {
        delete ptr;
    }
private:
    T* ptr;
};

int main() {

    return 0;
}

