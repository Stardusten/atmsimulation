#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<ctime>
#include<cstdlib>
namespace CUSTOMER{
    class customer{
    private:
        int ar_time; // arrive time
        int pc_time; // process time 1,2,3
    public:
        customer(const int & ar=0);
        int atime(){ return ar_time; }
        int ptime(){ return pc_time; }
    };
}
#endif