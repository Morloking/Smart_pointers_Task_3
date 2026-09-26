#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
class UniquePointer {
public:
    explicit UniquePointer(T* ptr) :
        ptr(ptr)
    {}
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    T& operator*() {
        if (ptr == nullptr) {
            throw std::runtime_error("UniquePointer: operator* null ptr");
        }
        return *ptr;
    }
    T* operator->() {
        if (ptr == nullptr) {
            throw std::runtime_error("UniquePointer: member access on null pointer");
        }
        return ptr;
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

