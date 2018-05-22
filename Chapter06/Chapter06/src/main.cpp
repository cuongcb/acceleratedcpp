#include "../inc/splitter.h"
#include "../inc/palindrome.h"
#include "../inc/urlsparser.h"

int main()
{
	/*string test = "Hello madam, This is a test string, level advance";
	vector<string> output = split(test);*/

	string test = "abcde https://www.acceleratedcpp.com fagea";
	vector<string> output = find_urls(test);

	for (auto i : output)
	{
		cout << i << endl;
		if (is_palindrome(i))
		{
			cout << "'" << i << "'" << " is a palindrome" << endl;
		}
	}
		

	system("pause");

	return 0;
}