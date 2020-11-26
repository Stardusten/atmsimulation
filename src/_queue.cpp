#include"_queue.h"
namespace QUEUE{
    queue::node::node(const item & _val) : val(_val) {}
    queue::queue(const int & q) : qsiz_m(q) {}
    queue::~queue(){
        for(node* it=front;it!=nullptr;it=it->next)
            delete it;
        front=rear=nullptr;
        qsiz=0;
    }
    bool queue::is_empty(){
        return qsiz==0?true:false;
        // return front==nullptr?true:false;
    }
    bool queue::is_full(){
        return qsiz==qsiz_m?true:false;
    }
    bool queue::push(const item & val){
        if(is_full()) return false;
        node* tmp=new node(val);
        qsiz++;
        if(front==nullptr) front=tmp;
        else rear->next=tmp;
        rear=tmp;
        return true;
    }
    bool queue::pop(){
        if(front==nullptr) return false;
        qsiz--;
        node* tmp=front->next;
        delete front;
        front=tmp;
        if(qsiz==0) rear=nullptr;
        return true;
    }
    item queue::top(){
        assert(front!=nullptr);
        return front->val;
    }
}