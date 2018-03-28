#include "../inc/StudentGrades.h"

double Median(vector<double> vec)
{
	typedef vector<double>::size_type vec_size;

	vec_size size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_size mid = size / 2;
	return (size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid]);
}
static double Grade(double midterm, double final, double median)
{
	return (midterm * 0.2 + final * 0.4 + median * 0.4);
}

double Grade(double midterm, double final, const vector<double> &hw) // prevent from creating a large copy of hw and modifying hw
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");

	return Grade(midterm, final, Median(hw));
}

istream &read_hw(istream &in, vector<double> &hw)
{
	if (in)
	{
		hw.clear(); // reset hw

		double score;
		while (in >> score)
			hw.push_back(score);

		in.clear(); // reset the state
	}

	return in; // without copy
}