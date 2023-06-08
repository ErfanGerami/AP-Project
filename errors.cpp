#include "errors.h"

Errors::Errors()
{


}
Errors::Errors(int stat)
{
    this->stat=stat;
}
int Errors::GetError(){return stat;}
int Errors::file_openning_error=0;
