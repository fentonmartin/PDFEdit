/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
#ifndef __STRINGOPTION_H__
#define __STRINGOPTION_H__

#include "option.h"
class QString;
class QLineEdit;

namespace gui {

/**
 Class for widget containing one editable setting of type string.<br>
 Also serves as a base class for editing some more specific types that can be represented in a string.
 \brief Widget to edit string option
*/
class StringOption : public Option {
 Q_OBJECT
public:
 StringOption(const QString &_key=0,QWidget *parent=0,const QString &defValue=QString::null);
 virtual ~StringOption();
 virtual void writeValue();
 virtual void readValue();
 virtual QSize sizeHint() const;
protected slots:
 void enableChange(const QString &newText);
protected:
 virtual void resizeEvent (QResizeEvent *e);
protected:
 /** one line edit control used for editing the value */
 QLineEdit *ed;
};

} // namespace gui

#endif
