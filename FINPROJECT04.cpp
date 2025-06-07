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

class HealthProfile {
private:
  string first_name;
  string last_name;
  char gender;
  int birth_month;
  int birth_day;
  int birth_year;
  double height;
  double pounds;
public:
  // Constructor
  HealthProfile(string fn, string ln, char g,
		int bm, int bd, int by,
		double h, double p) {
    first_name = fn;
    last_name = ln;
    gender = g;
    birth_month = bm;
    birth_day = bd;
    birth_year = by;
    height = h;
    pounds = p;
  }

  // Methods
  int computeAge() {
    time_t now = time(NULL);

    return (1970 + (now / 31556952)) -
      birth_year;
  }

  double computeMaximumHeartRate() {
    return 220 - computeAge();
  }

  tuple<double, double> computeTargetHeartRate() {
    double max_heart_rate = computeMaximumHeartRate();
    return make_tuple(max_heart_rate * 0.50,
		      max_heart_rate * 0.85);
  }

  double computeBMI() {
    return pounds / height * height * 4.88;
  }


  void displayData() {
    tuple<double, double> target_heart_rate = computeTargetHeartRate();
    cout << bold_font << "\nPatient Record:\n\n" << reset_color;
    cout << "Name: " <<  first_name << " " << last_name << '\n'
	 << "Gender: " <<  gender << '\n'
	 << "Birthday: " << setfill('0') << setw(2) << birth_month << '-'
	 << setw(2) << birth_day << '-' << setw(4) << birth_year << '\n'
	 << "Age: " << computeAge() << '\n'
	 << "Maximum Heart Rate: " << computeMaximumHeartRate() << '\n'
	 << "Target Heart Rate: "
	 << get<0>(target_heart_rate) << "–"
	 << get<1>(target_heart_rate) << '\n'
	 << "Body Mass Index: " << computeBMI() << '\n';
  }


  // Accessoprs
  string getFirstName() {return first_name;}
  string getLastName() {return last_name;}
  char getGender() {return gender;}
  int getBirthMonth() {return birth_month;}
  int getBirthDay() {return birth_day;}
  int getBirthYear() {return birth_year;}
  double getHeight() {return height;}
  double getPounds() {return pounds;}  

  // Mutators
  void setFirstName(string fn) {first_name = fn;}
  void setLastName(string ln) {last_name = ln;}
  void setGender(char g) {gender = g;}
  void setBirthMonth(int bm) {birth_month = bm;}
  void setBirthDay(int bd) {birth_day = bd;}
  void setBirthYear(int by) {birth_year = by;}
  void setHeight(double h) {height = h;}
  void setPounds(double p) {pounds = p;}  
};

void getPersonalData(string *first_name,
		     string *last_name,
		     char *gender,
		     int *birth_month,
		     int *birth_day,
		     int *birth_year,
		     double *height,
		     double *pounds) {

  cout << bold_font << "Adding data...\n\n" << reset_color;
  cout << "Full Name [FIRST LAST]: ";
  cin >> *first_name >> *last_name;
  cout << "Gender [M/F]: ";
  cin >> *gender;
  cout << "Birthday: [YYYY MM DD]: ";
  cin >> *birth_year >> *birth_month >> *birth_day;
  cout << "Weight [in lbs]: ";
  cin >> *pounds;
  cout << "Height [in feet]: ";
  cin >> *height;
}

int
main ()
{
  string first_name, last_name;
  char gender;
  int birth_month, birth_year, birth_day;
  double height, pounds;

  cout << bold_font
       << "\nWelcome to Health Records Program!\n"
       << reset_color
       << "\n"
       << "The centralized database of everyone's health records.\n"
       << "\n";

  // Prompt for data
  getPersonalData(&first_name, &last_name, &gender,
		  &birth_month, &birth_day, &birth_year,
		  &height, &pounds);

  // Construct object
  HealthProfile patient_record =
    HealthProfile(first_name, last_name, gender,
		  birth_month, birth_day, birth_year,
		  height, pounds);

  patient_record.displayData();
  
  return 0;
}
