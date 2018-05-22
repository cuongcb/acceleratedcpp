#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


bool space(char c);
bool not_space(char c);
vector<string> split(const string &s);
Grammar read_grammar(istream &in);
vector<string> gen_sentence(const Grammar &g);
bool bracketed(const string &s);
void gen_aux(const Grammar &g, const string &word, vector<string> &ret);
int nrand(int n);