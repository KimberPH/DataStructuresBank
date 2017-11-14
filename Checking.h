/* 
 * File:   Checking.h
 * Author: Aatish, Kimber, Richard
 *
 * Created on November 13, 2017, 6:46 PM
 */

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking : class Account{
    
public:
    Checking();
    void setMontlyFee();
    float getMonthlyFee(float f);
    
private:
    float monthlyFee;
};

#endif /* CHECKING_H */

