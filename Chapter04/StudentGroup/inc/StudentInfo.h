#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ios>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

using std::vector;		using std::sort;
using std::domain_error;	using std::istream;
using std::cout;		using std::cin;
using std::string;		using std::streamsize;
using std::setprecision;	using std::endl;
using std::max;			using std::list;



struct StudentInfo {
	string name;
	double midterm;
	double final;
	vector<double> homework;
};

typedef std::vector<StudentInfo> containter;
//typedef std::list<StudentInfo> containter;

bool Compare(const StudentInfo &a, const StudentInfo &b);
double Median(vector<double> vec);
double Grade(double midterm, double final, double median);
double Grade(double midterm, double final, const vector<double> &hw);
double Grade(const StudentInfo &s);
istream &read(istream &in, StudentInfo &s);
istream &read_hw(istream &in, vector<double> &homework);