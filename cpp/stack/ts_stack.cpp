#include "ts_stack.hpp"
    
template <typename T>
ts_stack<T>::ts_stack()
{
}


template <typename T>
ts_stack<T>::ts_stack(const ts_stack& other)
{
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
}


template <typename T>
ts_stack<T>::~ts_stack()
{
    if(this->data != NULL)
        delete[] this->data;
}


template <typename T>
void ts_stack<T>::push(T val)
{
    std::lock_guard<std::mutex> lock(m);
    this->data.push(val);
}


template <typename T>
std::shared_ptr<T> ts_stack<T>::pop()
{
    std::lock_guard<std::mutex> lock(m);
    if(this->data.empty()) {
        throw empty_stack();
    }

    std::shared_ptr<T> const res(std::make_shared<T>(this->data.top()));
    this->data.pop();

    return res;
}


template <typename T>
void ts_stack<T>::pop(T& val)
{
    std::lock_guard<std::mutex> lock(m);
    if(this->data.empty()) {
        val = this->data.top();
        this->data.pop();
    }
}


template <typename T>
bool ts_stack<T>::empty() const
{
    std::lock_guard<std::mutex> lock(m);
    return this->data.empty();
}


