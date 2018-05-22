#include "../inc/StudentInfo.h"

#if 0
int main()
{
	vector<StudentInfo> students;
	StudentInfo record;
	string::size_type maxlen = 0;

	while (read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), Compare);

	for (vector<StudentInfo>::size_type i = 0; i != students.size(); i++)
	{
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		try {
			double final_grade = Grade(students[i]);
			streamsize prec = cout.precision();

			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}

		cout << endl;
	}

	system("pause");

	return 0;
}
#endif

int main()
{
	vector<StudentInfo> did, didnt;
	StudentInfo student;

	while (read(cin, student))
	{
		if (did_all_hw(student))
		{
			did.push_back(student);
		}
		else
		{
			didnt.push_back(student);
		}
	}

	if (did.empty())
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt.empty())
	{
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "optimistic median", optimistic_analysis, did, didnt);

	system("pause");

	return 0;
}