#ifndef GUARD_myList_h
#define GUARD_myList_h

#include <cstddef> // size_t
#include <memory> // allocator

template <class T>
class myList {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;


    // construct, copy, assign, destroy
    myList() { create(); }
    explicit myList(size_t n, const T& val = T()) { create(n, val); }
    myList(const myList& L) { create(L.begin(), L.end()); }
    ~myList() { uncreate(); }

    myList& operator= (const myList&);

    size_t size() const { return tail - head; }
    iterator begin() { return head; }
    const_iterator begin() const { return head; }
    iterator end() { return tail; }
    const_iterator end() const { return tail; }


private:
    struct node{
        T value;
        node* next;
        node* previous;
    };
    node* head;
    node* tail;
    node* limit;
    std::allocator<node> alloc;

    void create();
    void create(size_t, const T&);
    void create(const_iterator, const_iterator);
    void uncreate();
    void grow();
    void unchecked_append(const T&);
};

template <class T>
myList<T>& myList<T>::operator=(const myList& rhs){
    if (&rhs != this){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void myList<T>::create(){
    head = tail = limit = 0;
}

template <class T>
void myList<T>::create(size_t n, const T& val){
    head = alloc.allocate(n);
    limit = tail = head + n;
    iterator it = head;
    while (it != limit){
        it->value = val;
        ++it;
    }
}

template <class T>
void myList<T>::create(const_iterator first, const_iterator end){
    head = alloc.allocate(end - first);
    limit = tail = head + (end - first);
    iterator it = head;
    iterator copy = first;
    while (it != limit){
        it->value = copy->value;
        it++;
        copy++;
    }
}

template <class T>
void myList<T>::uncreate() {

}

#endif
