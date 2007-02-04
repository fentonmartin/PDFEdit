/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
#ifndef __INVALIDMENUEXCEPTION_H__
#define __INVALIDMENUEXCEPTION_H__

#include <exception>

class QString;

namespace gui {

/**
 Exception raised when program encountered some error while loading
 menu or toolbar - in menu or toolbar item definitions
 \brief Exception raised when encountering invalid menu item
*/
class InvalidMenuException : public std::exception {
public:
 InvalidMenuException(const QString &message);
 ~InvalidMenuException() throw();
 QString message() const;
 const char* what() const throw();
protected:
 /** exception message*/
 QString msg;
};

} //namespace gui

#endif
