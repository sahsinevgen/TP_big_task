#include "UnitFabric.h"

UnitFabric::UnitFabric(QWidget *parent):
    ObjectFabric(parent)
{

}

Object* UnitFabric::create_object(Object_ID ID)
{
    return create_unit(ID);
}
