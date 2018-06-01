#include <iostream>
#include <ctime>
#include "fixedDeposit.h"
using namespace std;

int main() {
    time_t Now = time(0);
    struct tm time = {};
    time.tm_mday = 1;
    time.tm_mon = 4;
    time.tm_year = 2018;
    
    time_t future_time = mktime(&time);
    fixedDeposit fd = fixedDeposit(1000, 1, Now, future_time);
    cout << fd.getAmt() << endl;
    return 0;
}