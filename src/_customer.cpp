#include "_customer.h"
namespace CUSTOMER{
    customer::customer(const int & ar){
        std::srand((unsigned)std::time(NULL)); 
        ar_time=ar;
        pc_time=std::rand()%10+1;
    }
}