// Copyright (C) 2025 by Jericho S.
#include <iostream>
#include <tuple>
#include <iomanip>
using namespace std;

const char reset_color[] = "\033[0m";
const char bold_font[] = "\033[1m";
const char dim_color[] = "\033[2;32m";
const char move_back_53[] = "\033[53D";
const char clear_to_end[] = "\033[0K";

class HeartRates {
private:
  string first_name;
  string last_name;
  int birth_month;
  int birth_day;
  int birth_year;
public:
  // Constructor
  HeartRates(string fn,
	     string ln,
	     int bm,
	     int bd,
	     int by) {
    first_name = fn;
    last_name = ln;
    birth_month = bm;
    birth_day = bd;
    birth_year = by;
  }

  // Methods
  int getAge() {
    time_t now = time(NULL);

    return (1970 + (now / 31556952)) -
      birth_year;
  }

  double getMaximumHeartRate() {
    return 220 - getAge();
  }

  tuple<double, double> getTargetHeartRate() {
    double max_heart_rate = getMaximumHeartRate();
    return make_tuple(max_heart_rate * 0.50,
		      max_heart_rate * 0.85);
  }

  void displayData() {
    tuple<double, double> target_heart_rate = getTargetHeartRate();
    cout << bold_font << "\nSummary:\n\n" << reset_color;
    cout << "Name: " <<  first_name << " " << last_name << '\n'
	 << "Birthday: " << setfill('0') << setw(2) << birth_month << '-'
	 << setw(2) << birth_day << '-' << setw(4) << birth_year << '\n'
	 << "Age: " << getAge() << '\n'
	 << "Maximum Heart Rate: " << getMaximumHeartRate() << '\n'
	 << "Target Heart Rate: "
	 << get<0>(target_heart_rate) << "–"
	 << get<1>(target_heart_rate) << '\n';
  }

  // Accessors
  string getFirstName() {return first_name;}
  string getLastName() {return last_name;}
  int getBirthMonth() {return birth_month;}
  int getBirthDay() {return birth_day;}
  int getBirthYear() {return birth_year;}

  // Mutators
  void setFirstName(string fn) {first_name = fn;}
  void setLastName(string ln) {last_name = ln;}
  void setBirthMonth(int bm) {birth_month = bm;}
  void setBirthDay(int bd) {birth_day = bd;}
  void setBirthYear(int by) {birth_year = by;}
};

tuple<string, string, int, int, int> getPersonalData() {
  string first_name, last_name;
  int birth_month, birth_year, birth_day;
  cout << "Tell me about yourself.\n\n";
  cout << "First Name: ";
  cin >> first_name;
  cout << "Last Name: ";
  cin >> last_name;
  cout << "Birthday: ";
  cout << dim_color
       << "                    [YEAR MONTH DAY; space separated]"
       << reset_color << move_back_53;
  cin >> birth_year >> birth_month >> birth_day;
  return make_tuple(first_name, last_name,
		    birth_month, birth_day, birth_year);
}

int
main ()
{
  string first_name, last_name;
  int birth_month, birth_year, birth_day;

  cout << bold_font
       << "\nWelcome to Heart Wellness Program!\n"
       << reset_color
       << "\n"
       << "Determine your target heart beat rate.\n"
       << "\n";

  tie(first_name,
      last_name,
      birth_month,
      birth_day,
      birth_year) = getPersonalData();
  HeartRates heart_rates = HeartRates(first_name,
				      last_name,
				      birth_month,
				      birth_day,
				      birth_year);
  heart_rates.displayData();

  return 0;
}
