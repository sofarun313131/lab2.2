#include <stdexcept>
#include <algorithm>

//ОБЪЯВЛЕНИЕ ШАБЛОННОГО КЛАССА
template<class T>
class vector
{
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    vector()
        : data_(nullptr), size_(0), capacity_(0) {}
    //КОНСТРУКТОР
    vector(size_t n, const T& value)
    {
        size_ = capacity_ = n;
        data_ = new T[n];

        for(size_t i=0;i<n;i++)
            data_[i] = value;
    }
    //ДЕСТРУКТОР
    ~vector()
    {
        delete[] data_;
    }
    //КОНСТРУКТОР КОПИРОВАНИЯ
    vector(const vector& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for(size_t i=0;i<size_;i++)
            data_[i] = other.data_[i];
    }
    //ОПЕРАТОР ПРИСВАИВАНИЯ
    vector& operator=(const vector& other)
    {
        if(this == &other)
            return *this;
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for(size_t i=0;i<size_;i++)
            data_[i] = other.data_[i];
        return *this;
    }
    //ОПЕРАТОР []
    T& operator[](size_t i)
    {
        return data_[i];
    }
    const T& operator[](size_t i) const
    {
        return data_[i];
    }
    //ФУНКЦИЯ at()
    T& at(size_t i)
    {
        if(i >= size_)
            throw std::out_of_range("index");
        return data_[i];
    }
    //ФУНКЦИЯ size()
    size_t size() const
    {
        return size_;
    }
    //ФУНКЦИЯ capacity()
    size_t capacity() const
    {
        return capacity_;
    }
    //ФУНКЦИЯ empty()
    bool empty() const
    {
        return size_ == 0;
    }
    //ФУНКЦИЯ reserve()
    void reserve(size_t new_cap)
    {
        if(new_cap <= capacity_)
            return;
        T* new_data = new T[new_cap];
        for(size_t i=0;i<size_;i++)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }
    //ФУНКЦИЯ push_back()
    void push_back(const T& value)
    {
        if(size_ == capacity_)
        {
            size_t new_cap = capacity_ == 0 ? 1 : capacity_ * 2;
            reserve(new_cap);
        }
        data_[size_] = value;
        size_++;
    }
    //ФУНКЦИЯ pop_back()
    void pop_back()
    {
        if(size_ > 0)
            size_--;
    }
    //ФУНКЦИЯ clear()
    void clear()
    {
        size_ = 0;
    }
    //ФУНКЦИИ begin() и end()
    T* begin()
    {
        return data_;
    }
    T* end()
    {
        return data_ + size_;
    }
    //ФУНКЦИЯ swap()
    void swap(vector& other)
    {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
};