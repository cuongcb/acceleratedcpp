// Calculate the squares of int value up to 100
#if 0
#include <iostream>
#include <iomanip>

using std::cout;	using std::setw;
using std::endl;	using std::setprecision;
using std::streamsize;

int main()
{
	streamsize prec = cout.precision();
	for (double i = 1; i <= 100; i++)
	{
		//cout << setw(6) << i * i << setw(0) << endl;
		cout << setw(2) << i << "\t" << setprecision(6) << i * i << setprecision(prec) << endl;
	}
	
	setw(0);

	system("pause");

	return 0;
}

#endif