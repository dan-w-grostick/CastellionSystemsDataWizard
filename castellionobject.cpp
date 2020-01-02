#include "castellionobject.h"

CastellionObject::CastellionObject()
{
    this->id = -1;
    this->val2 = -1;
    this->meta_val1 = -1;
    this->val3 = -1;
}

CastellionObject::CastellionObject(long id, short val2, short meta_val1, short val3)
{
    this->id = id;
    this->val2 = val2;
    this->meta_val1 = meta_val1;
    this->val3 = val3;
}
