#include "../inc/StudentGrades.h"


int main()
{
	cout << "Please enter your first name: ";
	string firstName;
	cin >> firstName;

	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	vector<double> homework;

	read_hw(cin, homework);

	try {
		double final_grade = Grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	} catch (domain_error e) {
		cout << e.what() << endl;
		//system("pause");
		return 1;
	}

	system("pause");

	return 0;
}
