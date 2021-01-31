#include <iostream>
#include "tinyxml2.h"
#include <list>

using namespace tinyxml2;

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main()
{
    std::string filter_string = "person1";
	XMLDocument doc;
    std::list<XMLElement*> to_delete;

    XMLError eResult = doc.LoadFile("input.xml");
    XMLCheckResult(eResult);
    
    XMLElement* rootElement = doc.FirstChildElement();
    if(rootElement == nullptr)
    {
        std::cerr << "root node is null\n";
        return -1;
    }

    //each element is a timestep
    for(XMLElement* element = rootElement->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    {
        //each elemnt of a timestep
        for(XMLElement* timestep_e = element->FirstChildElement(); timestep_e != NULL; timestep_e = timestep_e->NextSiblingElement())
        {
            std::string id_string =  timestep_e->Attribute("id");
            if(id_string.compare(filter_string) != 0)
            {
                to_delete.push_back(timestep_e);
            }
        }
        for(auto a : to_delete)
        {
            element->DeleteChild(a);
        }

        to_delete.clear();
    }


    

    eResult = doc.SaveFile("output.xml");
    XMLCheckResult(eResult);

    return 0;
}