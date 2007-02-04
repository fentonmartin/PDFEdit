/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
#ifndef __QSCONTENTSTREAM_H__
#define __QSCONTENTSTREAM_H__

#include <qstring.h>
#include <qobject.h>
#include <ccontentstream.h>
#include "qscobject.h"

namespace gui {

class QSPdfOperator;
class QSPdfOperatorIterator;

using namespace pdfobjects;

/*= This type of object represents content stream in document (in page) */
/** \brief QObject wrapper around CContentStream */
class QSContentStream : public QSCObject {
 Q_OBJECT
public:
 QSContentStream(boost::shared_ptr<CContentStream> _cs,BaseCore *_base);
 virtual ~QSContentStream();
 boost::shared_ptr<CContentStream> get();
public slots:
 /*-
  Return true, if this object is equal to specified object (i.e. if they internally point to the same item)
  Reference is compared, not the value of objects
 */
 bool equals(QObject* otherObject);
 /*-
  Delete specified operator from this content stream.
  If parameter indicateChange is true (which is default), changes are immediately written to underlying stream.
 */
 void deleteOperator(QSPdfOperator *op,bool indicateChange=true);
 void deleteOperator(QObject *op,bool indicateChange=true);
 /*- Return text representation of this content stream */
 QString getText();
 /*-
  Insert specified operator newOp in this content stream, after operator op.
  If parameter indicateChange is true (which is default), changes are immediately written to underlying stream.
 */
 void insertOperator(QSPdfOperator *op,QSPdfOperator *newOp,bool indicateChange=true);
 void insertOperator(QObject *op,QObject *newOp,bool indicateChange=true);
 /*-
  Replace old operator oldOp with new operator newOp in this stream.
  If parameter indicateChange is true (which is default), changes are immediately written to underlying stream.
 */
 void replace(QSPdfOperator* oldOp,QSPdfOperator* newOp,bool indicateChange=true);
 void replace(QObject* oldOp,QObject* newOp,bool indicateChange=true);
 /*- Write any unwritten changes to operators to underlying stream. */
 void saveChange();
 /*-
  Return first operator in this contentstream.
  If not contains any operator, return NULL.
 */
 QSPdfOperator * getFirstOperator();
 /*-
  Return last operator in this contentstream.
  If not contains any operator, return NULL.
 */
 QSPdfOperator * getLastOperator();
 /*-
  Check if contentstream contains some operator.
 */
 bool isEmpty();
private:
 bool opValid(QSPdfOperator *op,bool checkThis=false);
private:
 /** Object held in class*/
 boost::shared_ptr<CContentStream> obj;
};

} // namespace gui

#endif
