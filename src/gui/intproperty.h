#ifndef __INTPROPERTY_H__
#define __INTPROPERTY_H__
#include "property.h"
#include "stringproperty.h"
#include <cobject.h>

using namespace pdfobjects;

class IntProperty : public StringProperty {
public:
 IntProperty (const QString &_name, QWidget *parent=0, PropertyFlags _flags=0);
 virtual ~IntProperty();
 void writeValue(IProperty *pdfObject);
 void readValue(IProperty *pdfObject);
};
#endif
