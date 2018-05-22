#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ios>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

using std::vector;		using std::sort;
using std::domain_error;	using std::istream;
using std::cout;		using std::cin;
using std::string;		using std::streamsize;
using std::setprecision;	using std::endl;
using std::max;			using std::list;
using std::ostream;		using std::accumulate;



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
double GradeAux(const StudentInfo &s);
double median_analysis(const vector<StudentInfo> &students);
istream &read(istream &in, StudentInfo &s);
istream &read_hw(istream &in, vector<double> &homework);
bool did_all_hw(const StudentInfo &s);
void write_analysis(ostream &out, 
		    const string &name, 
		    double analysis(const vector<StudentInfo> &students), 
		    const vector<StudentInfo> &did, 
		    const vector<StudentInfo> &didnt);

double average(const vector<double> &v);
double average_grade(const StudentInfo &s);
double average_analysis(const vector<StudentInfo> &students);
double optimistic_median(const StudentInfo &s);
double optimistic_analysis(const vector<StudentInfo> &students);