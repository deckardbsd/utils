#include <exception>
#include <memory>
#include <mutex>
#include <stack>

#ifndef _ts_stack__
#define _ts_stack__

struct empty_stack : std::exception
{
    const char * what() const throw();
};


template <typename T>
class ts_stack {
    public:
        ts_stack();
        ts_stack(const ts_stack& );
        ~ts_stack();
        // ts_stack& operator=(const ts_stack& ) = delete;

        void push(T val);
        std::shared_ptr<T> pop();
        void pop(T& val);
        bool empty() const;

    private:
        std::stack<T> data;
        mutable std::mutex m;
};

#include "ts_stack.cpp";

#endif
