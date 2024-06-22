#include <iostream>
namespace nglib
{
#include <nglib.h>
}
using namespace std;

int main2()
{

    nglib::Ng_Mesh *mesh;

    nglib::Ng_Init();

    mesh = nglib::Ng_LoadMesh("D:/netgen/netgenTest/cube.vol");

    std::cout << nglib::Ng_GetNP(mesh) << std::endl;
    std::cout << nglib::Ng_GetNSE(mesh) << std::endl;
    int nodeIds[3];
    int elementId = 1;
    nglib::Ng_GetSurfaceElement(mesh, elementId, nodeIds);
    std::cout << "Element ID: 1, [ " << nodeIds[0] << "," << nodeIds[1] << "," << nodeIds[2] <<"]"<< std::endl;
    nglib::Ng_RefineElement(mesh,elementId);
    //nglib::Ng_AddSurfaceElement(mesh, nglib::Ng_Surface_Element_Type::NG_TRIG, nodeIds);
    std::cout << nglib::Ng_GetNP(mesh) << std::endl;
    std::cout << nglib::Ng_GetNSE(mesh) << std::endl;
    nglib::Ng_SaveMesh(mesh, "test_cube.vol");
    return 0;
}
