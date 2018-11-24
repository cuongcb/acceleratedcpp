#pragma once
#include <climits>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

typedef int random_t;
typedef long long high_random_t;

using std::logic_error;

class RandomEngine {
public:
	RandomEngine();
	~RandomEngine();
	random_t nrand(random_t n);	
private:
	random_t low_nrand(random_t n);
	random_t high_nrand(random_t n);
};
