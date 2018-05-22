#if 0
typedef struct {

	vector<string> rotatedString;
	int size;
	int startPos;
	int endPos;
} rString_t;

// * read input lines
vector<string> readline();

// * create a set of rotations
vector<rString_t> rotate(vector<string> input);

// sort output rotated strings
sort();

// print out the string from startPos -> endPos with correct format
display();
#endif

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::vector;		using std::string;
using std::istream;		using std::getline;
using std::max;			using std::cout;
using std::endl;		using std::setw;
using std::cin;			using std::sort;

typedef struct {
	typedef vector<string>::size_type vec_sz;
	vector<string> rotatedString;
	vec_sz startPos;
} rString_t;

void printRotateString(const vector<rString_t> &rStrings)
{
	for (auto element : rStrings)
	{
		for (auto word : element.rotatedString)
		{
			cout << word << " ";
		}
		cout << endl;
		cout << element.startPos << endl;
	}
}

istream &readline(istream &in, vector<string> &input)
{
	if (in)
	{
		input.clear();
		string line;
		while (getline(in, line))
		{
			input.push_back(line);
		}
		in.clear();
	}

	return in;
}

vector<string>::size_type width(const vector<string> &input)
{
	vector<string>::size_type maxlen = 0;
	for (vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++)
	{
		maxlen = max(maxlen, iter->size());
	}

	return (maxlen + 1);
}

vector<string> split(const string &s)
{
	vector<string> ret;
	vector<string>::size_type size = s.size();
	if (size == 0)
		return ret;

	vector<string>::size_type i = 0, j = 0;

	while (i != size)
	{
		while (i != size && isspace(s[i]))
		{
			i++; // remove space
		}

		j = i;
		while (j != size && !isspace(s[j]))
		{
			j++;
		}

		ret.push_back(s.substr(i, j - i));
		i = j;
	}

	return ret;
}

// given a list of words, return a set of ratations
vector<rString_t> rotate(const vector<string> &words)
{
	vector<string>::size_type wsize = words.size();
	vector<string>::size_type i = 0;

	vector<rString_t> ret;

	if (wsize == 0)
		return ret;

	for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); iter++)
	{
		rString_t element;
		element.rotatedString.insert(element.rotatedString.end(), iter, words.end());
		element.rotatedString.insert(element.rotatedString.end(), words.begin(), iter);
		element.startPos = (wsize - (iter - words.begin())) % wsize;

		ret.push_back(element);
		//for (auto word : element.rotatedString)
		//{
		//	cout << word << " ";
		//}
		//cout << endl;
		//cout << element.startPos << endl;
	}

	return ret;
}

bool compare(const rString_t &a, const rString_t &b)
{
	return (a.rotatedString[0] < b.rotatedString[0]);
}

void display(const rString_t &a, vector<string>::size_type maxlen)
{
	string left, right;
	for (vector<string>::const_iterator iter = a.rotatedString.begin() + a.startPos; iter != a.rotatedString.end(); iter++)
	{
		left += *iter;
		left += " ";
	}

	for (vector<string>::const_iterator iter = a.rotatedString.begin(); iter != a.rotatedString.begin() + a.startPos; iter++)
	{
		right += *iter;
		right += " ";
	}

	if (a.startPos != 0)
	{
		cout << string(maxlen - left.size(), ' ') << left << string(8, ' ') << right << string(maxlen - right.size(), ' ') << endl;
	}
	else
	{
		cout << string(maxlen + 8, ' ') << left << string(maxlen - right.size(), ' ') << endl;
	}
	//cout << left << endl;
	//cout << right << endl;
}

void display(const vector<rString_t> &rStrings)
{
	for (vector<rString_t>::const_iterator iter = rStrings.begin(); iter != rStrings.end(); iter++)
	{
		//display(*iter);
	}
}

int main()
{
	vector<string> input;
	readline(cin, input);

	vector<string>::size_type maxlen = width(input);

	vector<rString_t> permutedIndex;
	
	for (auto line : input)
	{
		vector<string> words = split(line);
		vector<rString_t> rotLine = rotate(words);
		permutedIndex.insert(permutedIndex.end(), rotLine.begin(), rotLine.end());
	}

	//printRotateString(permutedIndex);

	sort(permutedIndex.begin(), permutedIndex.end(), compare);

	//printRotateString(permutedIndex);

	for (vector<rString_t>::const_iterator iter = permutedIndex.begin(); iter != permutedIndex.end(); iter++)
	{
		display(*iter, maxlen);
		//for (auto word : iter->rotatedString)
		//{
		//	cout << word << " ";
		//}
		//cout << endl;
	}

	system("pause");

	return 0;
}