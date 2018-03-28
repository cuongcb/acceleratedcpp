#include <cctype> // isspace
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::vector;		using std::string;
using std::domain_error;	using std::cout;
using std::endl;		using std::out_of_range;
using std::getline;		using std::cin;

vector<string> split(const string &s, char delimiter)
{
	vector<string> output;
	typedef string::size_type string_sz;

	string_sz size = s.size();
	if (size == 0)
		throw domain_error("Exception: null string!");

	string_sz i = 0;
	string_sz j = 0;
	// i stop at the first non-space character or i = size	
	while (i != size)
	{
		while (i != size && s[i] == delimiter)
			i++;

		j = i;
		while (j != size && s[j] != delimiter)
			j++;

		output.push_back(s.substr(i, j - i)); // [i, i+j)
		i = j;
	}

	return output;
}

vector<string> split(const string &s)//, char delimitter)
{
	vector<string> output;
	typedef string::size_type string_sz;

	string_sz size = s.size();
	if (size == 0)
		throw domain_error("Exception: null string!");

	string_sz i = 0;
	string_sz j = 0;
	// i stop at the first non-space character or i = size	
	while (i != size)
	{
		while (i != size && isspace(s[i])) // strim all trailing spaces
			i++;

		j = i;
		while (j != size && !isspace(s[j]))
			j++;

		output.push_back(s.substr(i, j - i)); // [i, i+j)
		i = j;
	}

	return output;
}

int main()
{
	//string s = "Hello, this is a test string";
	//string s1 = "        ";
	//string s2 = "";
	string s;
	getline(cin, s);

	vector<string> ret;
	try {
		ret = split(s);
	} catch (domain_error e) {
		cout << e.what() << endl;;
	} catch (out_of_range e) {
		cout << e.what() << endl;;
	}

	for (auto it : ret)
		cout << it << endl;

	system("pause");

	return 0;
}