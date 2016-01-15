#include <stdlib.h>
#include <algorithm>
#include <ParticleSedimetary.h>
#include <Array2D.h>


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iterator>



template <class T>
inline void PRINT_ELEMENTS(const T& coll, const char * optcstr = "")
{
	typename T::const_iterator pos;
	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	
	std::cout << std::endl;
}


int main()
{
	TerrianGenerator::ParticleSedimetary p = TerrianGenerator::ParticleSedimetary(257, 257, 20, 2, 0.3, 0.3);
	p.Walker(100000);
	p.CreateHeightMap("random11.bmp");
	p.CreateRawHeightMap("random11.raw");
	system("pause");
	return 0;
}