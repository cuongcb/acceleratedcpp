#include "../inc/randomgenerator.h"
#include <iostream>

RandomEngine::RandomEngine()
{
	srand(time(NULL)); // seed
	std::cout << "Seeding completes..." << std::endl;
}

RandomEngine::~RandomEngine()
{

}

random_t RandomEngine::nrand(random_t n)
{
	if (n < 0 || n > INT_MAX)
	{
		throw logic_error("Invalid value.");
	}

	if (n < RAND_MAX)
	{
		return low_nrand(n);
	}
	else
	{
		return high_nrand(n);
	}
}

random_t RandomEngine::low_nrand(random_t n)
{
	const random_t bucket_size = RAND_MAX / n;
	std::cout << "RAND_MAX: " << RAND_MAX << std::endl;
	std::cout << "bucket_size: " << bucket_size << std::endl;
	random_t r;

	do {
		r = rand();// / bucket_size;
		r = rand();
		std::cout << "rand(): " << r << std::endl;
		r = r / bucket_size;
		std::cout << "r: " << r << std::endl;
	} while (r >= n);

	return r;
}

random_t RandomEngine::high_nrand(random_t n)
{
	// r = RAND_MAX * rand1 + rand2	
	const random_t bucket_numb = n / RAND_MAX;
	high_random_t r;
	
	do {
		r = static_cast<high_random_t>(RAND_MAX * low_nrand(bucket_numb + 1) + rand());
	} while (r >= n);

	return static_cast<random_t>(r);
}
