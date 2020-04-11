#include "UnitFabric.h"

UnitFabric::UnitFabric()
{

}

Object* UnitFabric::create_object(Object_ID ID)
{
    return create_unit(ID);
}
