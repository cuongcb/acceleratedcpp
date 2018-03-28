#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>

using std::vector;		using std::sort;
using std::domain_error;	using std::istream;
using std::cout;		using std::cin;
using std::string;		using std::streamsize;
using std::setprecision;	using std::endl;

double Median(vector<double> vec);
double Grade(double midterm, double final, const vector<double> &hw);
istream &read_hw(istream &in, vector<double> &hw);