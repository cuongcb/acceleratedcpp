#include <algorithm>
#include <cctype> // isspace
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::vector;		using std::string;
using std::domain_error;	using std::cout;
using std::endl;		using std::out_of_range;
using std::getline;		using std::cin;
using std::max;

// return the max size in a collection of strings
string::size_type width(const vector<string> &v)
{
	string::size_type maxlen = 0;
	for (string it : v)
		maxlen = max(maxlen, it.size());
	return maxlen;
}

// create a frame of the current strings

/*
********
* abcd *
********
*/
vector<string> frame(const vector<string> &v)
{
	vector<string> ret;
	string::size_type maxlen = width(v) + 4;

	ret.push_back(string(maxlen, '*'));
	for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		ret.push_back("* " + *it + string(maxlen - (*it).size(), ' ') + " *");
	}
	ret.push_back(string(maxlen, '*'));

	return ret;
}

vector<string> vcat(const vector<string> &top, const vector<string> &bot)
{
	vector<string> ret = top;
	ret.insert(ret.end(), bot.begin(), bot.end());

	return ret;
}

vector<string> hcat(const vector<string> &left, const vector<string> &right)
{
	vector<string> ret;
	typedef vector<string>::size_type vec_sz;
	string::size_type swidth = width(left) + 1;
	vec_sz lsize = left.size();
	vec_sz rsize = right.size();
	vec_sz i = 0, j = 0;

	while (i != lsize || j != rsize)
	{
		string s;
#if 0
		if (lsize != 0)
		{
			ret.push_back(left[i++]);
		}
		else
		{
			ret.push_back(string(left[0].size(), ' '));
		}

		ret.push_back(right[j++]);
#endif
		if (i != lsize)
			s = left[i++];

		s += string(swidth - s.size(), ' ');

		if (j != rsize)
			s += right[j++];

		ret.push_back(s);
	}

	return ret;
}

vector<string> center(const vector<string> &v)
{
	typedef vector<string>::size_type vec_sz;
	vector<string> ret;
	string::size_type swidth = width(v);

	vec_sz size = v.size();
	if (size == 0)
	{
		return ret;
	}

	
}

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