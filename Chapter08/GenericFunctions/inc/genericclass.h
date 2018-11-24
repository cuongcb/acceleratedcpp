#include <algorithm>
#include <vector>

namespace generic {

template <class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	sort(v.begin(), v.end());

	vec_sz mid = v.size() / 2;

	return (v.size() % 2 == 0) ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template <class T>
T max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

template <class In, class X>
In find(In begin, In end, const X &val)
{
	while (begin != end && *begin != val)
	{
		++begin;	
	}

	return begin;
}

template <class In, class Out>
Out copy(In begin, In end, Out dst)
{
	while (begin != end)
	{
		*dst++ = *begin++;
	}

	return dst;
}

template <class For, class X>
void replace(For begin, For end, const X &x, const X &y)
{
	while (begin != end)
	{
		if (*begin == x)
			*begin = y;
		++begin;
	}
}

template <class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
		{
			swap(*begin, *end);
			begin++;
		}
	}
}

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X &x)
{
	while (begin < end) // note: '<' not '!='
	{
		Ran mid = begin + (end - begin) / 2;
		if (*mid > x)
		{
			end = mid; 
		}
		else if (*mix < x)
		{
			begin = mid + 1;
		}
		else
		{
			return true;
		}
	}

	return false;
}

template <class T, class Out>
Out read_T(istream_iterator<T> begin, istream_iterator<T> end, Out v)
{
	copy(begin, end, back_inserter(v));
	return v;
}

bool space(const char &c)
{
	return isspace(c);
}

bool not_space(const char &c)
{
	return !isspace(c);
}

template <class Out>
void split(const string &s, Out os)
{
	string::const_iterator i = s.begin();
	while (i != s.end())
	{
		i = find_if(i, s.end(), not_space);
		string::const_iterator j = find_if(i, s.end(), space);
		if (i != s.end())
		{
			*os++ = string(i, j)
		}
	}
}

/*
 *
 * Ex:
 * list word_list;
 * split(s, back_inserter(word_list);)
 *
 */
	
};
