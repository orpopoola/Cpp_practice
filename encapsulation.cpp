#include <cassert>
#include <vector>
#include <algorithm>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);

private:
  int day_{1};
  int month_{1};
  int year_{0};
  bool LeapYear(int year) const;
  int Num_of_days(int month, int year) const;
};
int Date::Num_of_days(int month, int year) const{
      std::vector<int> t_1{1,3,5,7,8,10,12};
      std::vector<int> t_0{9,4,6,11};
      int feb=2;
      if(std::binary_search(t_1.begin(),t_1.end(),month)){return 31;}
      else if(std::binary_search(t_0.begin(),t_0.end(),month)){return 30;}
      else if(month==feb){return (LeapYear(year)?29:28);}
      else {return 0;}
}
bool Date::LeapYear(int year) const {
    if(year % 4 != 0)
        return false;
    else if(year % 100 != 0)
        return true;
    else if(year % 400 != 0)
        return false;
    else
        return true;
}
Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= Num_of_days(Month(), Year()))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(28, 2, 2021);
  assert(date.Day() == 28);
  assert(date.Month() == 2);
  assert(date.Year() == 2021);
}