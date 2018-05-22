#include "../inc/StudentInfo.h"

istream &read(istream &in, StudentInfo &s)
{
	in >> s.name >> s.midterm >> s.final;

	read_hw(in, s.homework);
	return in;
}

istream &read_hw(istream &in, vector<double> &homework)
{
	if (in)
	{
		homework.clear();

		double score;
		while (in >> score)
			homework.push_back(score);

		in.clear();
	}

	return in;
}

bool Compare(const StudentInfo &a, const StudentInfo &b)
{
	return a.name < b.name;
}

double Median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
		throw domain_error("no homework");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return (size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid]);
}

double Grade(const StudentInfo &s)
{
	return Grade(s.midterm, s.final, s.homework);
}

double Grade(double midterm, double final, const vector<double> &hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return Grade(midterm, final, Median(hw));
}

double Grade(double midterm, double final, double median)
{
	return (midterm * 0.2 + final * 0.4 + median * 0.4);
}

bool Fgrade(const StudentInfo &s)
{
	return (Grade(s) < 60);
}

bool did_all_hw(const StudentInfo &s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0) == s.homework.end()));
}

containter extract_fails(containter &students)
{
	containter fails;
	containter::iterator iter = students.begin();

	while (iter != students.end())
	{
		if (Fgrade(*iter))
		{
			fails.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	return fails;
}

double GradeAux(const StudentInfo &s)
{
	try {
		return Grade(s);
	} catch (domain_error) {
		return Grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<StudentInfo> &students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), GradeAux);

	return Median(grades);
}

void write_analysis(ostream &out, 
		    const string &name, 
		    double analysis(const vector<StudentInfo> &students), 
		    const vector<StudentInfo> &did, 
		    const vector<StudentInfo> &didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double> &v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const StudentInfo &s)
{
	return Grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<StudentInfo> &students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return Median(grades);
}

double optimistic_median(const StudentInfo &s)
{
	vector<double> nonzero;

	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return Grade(s.midterm, s.final, 0);
	else
		return Grade(s.midterm, s.final, Median(nonzero));
}

double optimistic_analysis(const vector<StudentInfo> &students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

	return Median(grades);
}