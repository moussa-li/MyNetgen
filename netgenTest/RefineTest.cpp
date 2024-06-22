#include <iostream>
#include <nginterface_v2.hpp>

#include "mydefs.hpp"

int main12()
{
    std::shared_ptr<netgen::Mesh> mptr;
    netgen::Ngx_Mesh ngxMesh(mptr);

    const std::string inputDir("test.vol");
    const char* a = inputDir.c_str();
    std::ifstream istr(a);
    if (!istr.good())
    {
        std::cout << " what " << std::endl;
    }
    ngxMesh.LoadMesh(istr);


    std::cout << "NP : " << ngxMesh.GetNP() << std::endl;
    std::cout << "NE : " << ngxMesh.GetNElements(3) << std::endl;


    ngxMesh.Refine(NG_REFINEMENT_TYPE::NG_REFINE_H, false);

    std::cout << "NP : " << ngxMesh.GetNP() << std::endl;
    std::cout << "NE : " << ngxMesh.GetNElements(3) << std::endl;
    return 0;
}