#include "../inc/randomgenerator.h"
#include <iostream>

int main()
{
	RandomEngine *r = new RandomEngine();

	try {
		/* random_t val = r->nrand(INT_MAX);		 */
		random_t val = r->nrand(100);		
		std::cout << val << std::endl;
		/* std::cout << rand() << std::endl; */
	} catch (logic_error e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
