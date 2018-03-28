#include "../inc/StudentInfo.h"

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