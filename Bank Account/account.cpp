#include<iostream>
#include "account.h"
using namespace std;


int main() {
    account Yashwanth =  account("Yashwanth Chawat", "8971220965", "5927-3821-3721", 15000.00);
    Yashwanth.depositAmt(50000.0);
    Yashwanth.setupFD(1000.0, 22, 6, 2018);
    Yashwanth.currentBal();
    return 0;
}