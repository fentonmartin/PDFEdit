/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
/** @file
 ToolButton - Class representing a single button on the toolbar
 Same as QToolButton, difference is that ToolButton also emit its ID in signal
 @author Martin Petricek
*/
#include "toolbutton.h"
#include <qiconset.h>
#include <qpixmap.h>
#include <qstring.h>
#include "util.h"

namespace gui {

/**
 Constructor of ToolButton
 @param icon Icon for this button
 @param tooltip Text to display as tooltip
 @param id Button Id that will be emitted : clicked(id)
 @param parent Parent widget
 @param name Name of button
 */
ToolButton::ToolButton(const QPixmap *icon, const QString tooltip, int id, QWidget *parent/*=0*/, const char *name/*=""*/) : QToolButton(parent,name) {
 connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
 b_id=id;
 setTextLabel(tooltip);
 if (icon) {
  QIconSet ico=QIconSet(*icon);
  setIconSet(ico);
 }
} 

/**
 Constructor of ToolButton
 @param iconSet Icon set for this button
 @param tooltip Text to display as tooltip
 @param id Button Id that will be emitted : clicked(id)
 @param parent Parent widget
 @param name Name of button
 */
ToolButton::ToolButton(const QIconSet *iconSet, const QString tooltip, int id, QWidget *parent/*=0*/, const char *name/*=""*/) : QToolButton(parent,name) {
 connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
 b_id=id;
 setTextLabel(tooltip);
 if (iconSet) {
  setIconSet(*iconSet);
 }
} 

/**
 Event handler for mouse cursor entering button.
 Sends its tooltip as help text.
 @param e Event
*/
void ToolButton::enterEvent(QEvent *e) {
 emit helpText(textLabel());
 QToolButton::enterEvent(e);
}

/**
 Event handler for mouse cursor leaving button.
 Sends empty helptext, thus disabling it
 @param e Event
*/
void ToolButton::leaveEvent(QEvent *e) {
 emit helpText(QString::null);
 QToolButton::leaveEvent(e);
}

/** slot that will emit clicked with ID of whis button */
void ToolButton::slotClicked() {
 emit clicked(b_id);
}

} // namespace gui
