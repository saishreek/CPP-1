#include <iostream>
#include <ctime>
using namespace std;

class fixedDeposit {
    double amt;
    int id;
    time_t expireTime;
    time_t initTime;
    time_t breakTime;
    bool active;
    double returnedAmt;

    public:
        fixedDeposit() {
            this->amt = 0.0;
        }
        fixedDeposit(double amt, int id, time_t expireTime, time_t initTime) {
            this->amt = amt;
            this->id = id;
            this->expireTime = expireTime;
            this->initTime = initTime;            
        }
        char * getExpireTime() {
            return ctime(&this->expireTime);
        }
        char * getInitTime() {
            return ctime(&this->initTime);
        }
        double getAmt() {
            return this->amt;
        }
        int getID() {
            return this->id;
        }
        double breakFD() {
            time_t Now = time(0);
            this->active = false;
            this->breakTime = Now;
            if ((Now - this->expireTime) >= 0) {
                this->returnedAmt = 1.2 * this->amt;
            } else {
                this->returnedAmt = 0.85 * this->amt;
            }
            return this->returnedAmt;
        }
};