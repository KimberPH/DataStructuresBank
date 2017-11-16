#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Date.h"

bool CheckBook::Date::valid(u8 day, u8 month, u16 year){
  if(!day) return false;
  if(!month || month > 12) return false;
  if(month == 2) return day < 28 + !(year % 4);
  
  u8 extraDay = month & 1;
  u8 addedDay = (month < 8) & extraDay;
  return day <= (30 + addedDay);
}

CheckBook::Date::Date(u8 day = 1, u8 month = 1, u16 year = 1970){
  if(!set(day, month, year))
    throw std::invalid_argument("Date set to an invalid date.");
}

bool CheckBook::Date::set(u8 day, u8 month, u16 year){
  if(!valid(day, month, year)) return false;
  this->day = day;
  this->month = month;
  this->year = year;
  return true;
}

std::string CheckBook::Date::toString() const {
  std::ostringstream os;
  u16 iout;
  iout = month;
  os << iout << "/";
  iout = day;
  os << iout << "/" << year;
  return os.str();
}

namespace CheckBook {
  std::istream &operator>>(std::istream &is, Date &date){
    std::string line;
    std::getline(is, line);
    std::istringstream ss(line); //to leave as default values if reaches end of line
    
    u16 iin = 1; //needed since using cin/cout instead of sscanf/printf
    if(!(ss >> iin)){
      std::cin.setstate(std::ios::failbit);
      return is;
    }
    
    ss.get();
    date.month = iin;

    iin = 1;
    if(!(ss >> iin)){
      std::cin.setstate(std::ios::failbit);
      return is;
    }
    
    ss.get();
    date.day = iin;
    if(!(ss >> date.year))
      std::cin.setstate(std::ios::failbit);
    
    return is;
  }

  std::ostream &operator<<(std::ostream &os, const Date &date){
    os << date.toString();
    return os;
  }

  bool operator<(const Date &left, const Date &right){
    if(left.year < right.year) return true;
    if(left.year > right.year) return false;

    if(left.month < right.month) return true;
    if(left.month > right.month) return false;

    return left.day < right.day;
  }

  bool operator>(const Date &left, const Date &right){
    return right < left;
  }

  bool operator==(const Date &left, const Date &right){
    return !(left < right || left > right);
  }

  bool operator!=(const Date &left, const Date &right){
    return !(left == right);
  }
}
