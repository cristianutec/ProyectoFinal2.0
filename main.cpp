#include <iostream>
#include "word.h"
#include "funciones.h"
#include <vector>

using namespace std;

int main()
{
    Word* file = nullptr;
    pantallaPrincipal(file);
    delete file;
    return 0;
}