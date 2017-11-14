/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Account.h"

Checking::Checking(){};

void Checking::setMontlyFee(float f){
    monthlyFee=f;
}

float Checking::getMonthlyFee(){
    return monthlyFee;
}
    