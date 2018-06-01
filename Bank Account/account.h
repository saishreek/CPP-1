#include <iostream>
#include <string>
#include "fixedDeposit.h"
using namespace std;

class account {
    string name;
    string phone;
    string aadhar;
    double amt;
    fixedDeposit * FDS;
    int fdID = 0;

    public:
        account(string name, string phone, string aadhar, double amt) {
            this->name = name;
            this->aadhar = aadhar;
            this->phone = phone;
            this->amt = amt;   
            FDS = new fixedDeposit[10];
        }
        void setName(string name) {
            this->name = name;
        }

        string getName(void) {
            return this->name;
        }
        
        void setPhone(string phone) {
            this->phone = phone;
        }

        string getPhone(void) {
            return this->phone;
        }
        void setAadhar(string aadhar) {
            this->aadhar = aadhar;
        }

        string getAadhar(void) {
            return this->aadhar;
        }

        double getAmt(void) {
            return this->amt;
        }
        void depositAmt(double amt) {
            cout << "Deposited: Rs " << amt << endl;
            this->amt += amt;
            this->currentBal();
        }

        void currentBal(void) {
            cout << "Current Balance: Rs." << this->amt << endl;
        }

        void withdrawAmt(double amt) {
            cout << "Withdrawn: Rs " << amt << endl;
            this->amt -= amt;
            this->currentBal();    
        }

        void setupFD(double amt, int day, int mon, int year) {
            if (this->fdID == 9) {
                cout << "You have your Fixed Deposit limit" << endl;
                return;
            }
            this->amt -= amt;
            struct tm TIME = {};
            TIME.tm_mday = day;
            TIME.tm_mon = mon - 1;
            TIME.tm_year = year - 1900;
            time_t expireTime = mktime(&TIME);
            this->FDS[this->fdID] = fixedDeposit(amt, this->fdID, expireTime, time(0));
            this->fdID++;
            cout << "Fixed Deposit created - Rs. " << amt << endl; 
        }
};