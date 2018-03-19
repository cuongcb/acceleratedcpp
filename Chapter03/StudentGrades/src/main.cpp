#include "../inc/StudentGrades.h"

vector<string>::size_type CountDistinctWords(vector<string> words)
{
	vector<string>::size_type size = words.size();

	if (size == 0)
		return 0;

	sort(words.begin(), words.end());

	vector<string>::size_type it = 0;
	vector<string>::size_type count = 1;

	while (it != size - 1)
	{
		if (words[it] != words[it+1])
			count++;
		it++;
	}

	return count;
}

bool cmp(string a, string b)
{
	return a.size() < b.size();
}

vector<vector<string>::size_type> MinAndMaxStringLength(vector<string> words)
{
	vector<vector<string>::size_type> output(2, 0);
	vector<string>::size_type size = words.size();

	if (size == 0)
		return output;

	sort(words.begin(), words.end(), cmp);

	output[0] = words[0].size();
	output[1] = words[size-1].size();

	return output;
}

int main()
{
	//Average();
	//Median;
	//vector<string> 
	string arr[] = {"HOA", "NHUNG", "CONG", "THE", "MANH", "TAN", "HOA"};
	vector<string> words(arr, arr+6);

	cout << CountDistinctWords(words) << endl;

	vector<vector<string>::size_type> result = MinAndMaxStringLength(words);
	cout << "Min: " << result[0] << " -- Max: " << result[1] << endl;

	system("pause");

	return 0;
}