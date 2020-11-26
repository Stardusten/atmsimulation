#ifndef QUEUE_H
#define QUEUE_H
#include"_customer.h"
#include<iostream>
namespace QUEUE{
    typedef CUSTOMER::customer item;
    class queue{
    private:
        struct node{
            item val;
            node* next=nullptr;
            node(const item & _val=0);
        };
        node* front=nullptr;
        node* rear=nullptr;
        int qsiz_m;
        int qsiz=0;
    public:
        queue(const int & siz=10);
        ~queue();
        queue(const queue &){}
        queue & operator=(const queue &){ return *this; }
        bool is_empty();
        bool is_full();
        bool push(const item &);
        bool pop();
        item top();
    };
}
#endif