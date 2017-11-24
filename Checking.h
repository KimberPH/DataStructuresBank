/* 
 * File:   Checking.h
 * Author: Aatish, Kimber, Richard
 *
 * Created on November 13, 2017, 6:46 PM
 */

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking : public Account{
    
public:
    Checking();
    void setMontlyFee(double f);
    double getMonthlyFee();
    
private:
    double monthlyFee;
};

#endif /* CHECKING_H */

