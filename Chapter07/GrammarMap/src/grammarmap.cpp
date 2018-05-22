#include "../inc/grammarmap.h"


bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string &s)
{
	vector<string> ret;
	if (s.size() == 0)
	{
		return ret;
	}

	string::const_iterator iter = s.begin();
	while (iter != s.end())
	{
		iter = find_if(iter, s.end(), not_space);
		string::const_iterator j = iter;
		j = find_if(iter, s.end(), space);

		if (iter != s.end())
		{
			ret.push_back(string(iter, j));
		}
		iter = j;
	}

	return ret;
}

Grammar read_grammar(istream &in)
{
	Grammar ret;
	string line;

	while (getline(in, line))
	{
		vector<string> entry = split(line);
		if (!entry.empty())
		{
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}

	return ret;
}

vector<string> gen_sentence(const Grammar &g)
{
	vector<string> ret;
	try {
		gen_aux(g, "<sentence>", ret);
	} catch (logic_error e) {
		cout << e.what() << endl;
	}
	

	return ret;
}

bool bracketed(const string &s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar &g, const string &word, vector<string> &ret)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
		{
			throw logic_error("empty rule");
		}

		const Rule_collection &c = it->second;
		const Rule &r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
		{
			gen_aux(g, *i, ret);
		}
	}
}

int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
	{
		throw domain_error("Argument to nrand is out-of-range");
	}

	const int bucket_size = RAND_MAX / n;
	int r;
	
	do {
		r = rand() / bucket_size;
	} while (r >= n);

	return r;
}