#include <iomanip> // streamsize, setprecision
#include <iostream> // cout
#include <algorithm> // sort
#include <string> // string
#include <vector> // vector

using std::cout;		using std::streamsize;
using std::setprecision;	using std::vector;
using std::string;		using std::cin;
using std::sort;		using std::max;
using std::endl;

int main()
{
	vector<string> words;
	typedef vector<string>::size_type vec_sz;

	string word;
	while (cin >> word)
		words.push_back(word);

	sort(words.begin(), words.end());

	vector<string> distwords;
	vector<int> counter;
	int count = 1;
	for (vec_sz i = 1; i != words.size(); i++)
	{
		if (words[i] != words[i-1])
		{
			distwords.push_back(words[i-1]);
			counter.push_back(count);
			count = 1;
		}
		else
		{
			count++;
		}
	}

	distwords.push_back(words[words.size()-1]);
	counter.push_back(count);

	string::size_type maxlen = 0;
	for (vec_sz i = 0; i < distwords.size(); i++)
	{
		maxlen = max(maxlen, distwords[i].size());
	}
	
	streamsize prec = cout.precision();
	for (vec_sz i = 0; i < distwords.size(); i++)
	{
		cout << distwords[i] << string(maxlen + 1 - distwords[i].size(), ' ') << setprecision(3) << counter[i] << setprecision(prec) << endl;
	}

	system("pause");

	return 0;
}