// ATM simulation

#include"_queue.h"
#include"_customer.h"
using namespace QUEUE;
using namespace CUSTOMER;
bool have_new_customer(const int & avg);
int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    std::srand((unsigned)std::time(NULL));
    cout<<"Max size of queue: ";
    int siz; cin>>siz;
    queue q(siz);
    cout<<"Simulation minutes: ";
    int sm; cin>>sm;
    cout<<"Avg time per person: "; // 平均 avg 分钟来一位顾客
    int avg; cin>>avg;
    int wait_time=0;
    int refuse_number=0;
    int served_number=0;
    for(int i=0;i<sm;i++){
        if(have_new_customer(avg)){
            customer ci(i);
            if(!q.is_full()){
                q.push(ci);
                served_number++;
            }else refuse_number++;
        }
        if(wait_time==0 && !q.is_empty()){
            wait_time+=q.top().ptime();
            q.pop();
        }
        if(wait_time>0) wait_time--;
    }
    cout<<"Statistic Result: "<<endl;
    cout<<"Number of served customers: "<<served_number<<endl;
    cout<<"Number of refused customers: "<<refuse_number<<endl;
    return 0;
}
bool have_new_customer(const int & avg){
    return (rand()%(avg)+1)==1;
}