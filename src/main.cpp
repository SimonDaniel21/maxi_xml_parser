#include <iostream>
#include "tinyxml2.h"
using namespace tinyxml2;

int main()
{
	XMLDocument doc;
	doc.LoadFile( "input.xml" );
    std::cout << "xml";
    return 0;
}