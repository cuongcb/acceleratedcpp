#include "../inc/palindrome.h"

bool is_palindrome(const string &s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}