/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
// vim:tabstop=4:shiftwidth=4:noexpandtab:textwidth=80

#ifndef _COBJECTHELPERS_H_
#define _COBJECTHELPERS_H_

/*
 * $RCSfile$
 *
 * $Log$
 * Revision 1.37  2007/02/04 20:17:02  mstsxfx
 * Common Licence comment for all cc and h files available in doc/licence_header
 * file and its content to all cc and h files in src/{gui,kernel,utils}
 * directories.
 * Xpdf code, QSA and QOutputDevice code are not touched
 *
 * Revision 1.36  2006/07/19 13:07:14  misuj1am
 *
 * -- doc update
 *
 * Revision 1.35  2006/07/02 14:03:55  misuj1am
 *
 * -- ADD: getXRef() helper function
 *
 * Revision 1.34  2006/06/29 20:00:07  hockm0bm
 * doc updated
 *
 * Revision 1.33  2006/06/21 18:46:00  hockm0bm
 * * CObject{Simple, Stream}, CDict, CArray
 *         - contains static const type field
 * * template helper functions with PropertyType template parameter changed to
 *   contain just Type parameter - original implementation kept but marked as
 *   deprecated (they will be removed when no deprecated warning is announced)
 *
 * Revision 1.32  2006/06/05 08:57:32  hockm0bm
 * refactoring CObjectSimple
 *         - getPropertyValue -> getValue
 *         - writeValue -> setValue
 *
 * Revision 1.31  2006/06/03 09:15:02  hockm0bm
 * getCObjectFromRef removed from cobjecthelpers.h to cpdf.h because gcc >=4.0
 * didn't like CPdf usage
 *
 * REMARK:
 * gcc 3.3 was ok with such construction
 *
 * Revision 1.30  2006/06/02 16:54:53  hockm0bm
 * checkAndReplace method added
 *
 * Revision 1.29  2006/06/02 11:54:44  hockm0bm
 * getCObjectFromRef(CPdf &, IndiRef) removed because it can't use CPdf and
 * implementation has to be in header file
 *
 * Revision 1.28  2006/06/02 10:48:46  hockm0bm
 * getCObjectFromRef template methods added
 *
 * Revision 1.27  2006/06/02 01:34:15  misuj1am
 *
 * -- ADD: support for getting all outlines dictionaries
 *
 * Revision 1.26  2006/05/30 20:48:05  hockm0bm
 * getIPropertyFromDate method added
 *
 * Revision 1.25  2006/05/30 17:27:00  hockm0bm
 * getIPropertyFromRectangle method added
 *
 * Revision 1.24  2006/05/09 20:03:47  hockm0bm
 * * getNameFromDict bug fix
 *         - Type used instead of /Type
 *
 * Revision 1.23  2006/05/01 13:53:06  hockm0bm
 * new style printDbg
 *
 * Revision 1.22  2006/04/25 22:16:16  misuj1am
 *
 * -- changes to MAKE it compile on my gcc [(GCC) 4.0.2 20051125 (Red Hat 4.0.2-8)]
 * 	-- only moved from one file to another
 * 	-- changed headers
 *
 * Revision 1.21  2006/04/25 02:26:17  misuj1am
 *
 * -- ADD: set*ToDict, set*ToArray improved to automaticly fetch object if ref
 *
 * Revision 1.20  2006/04/23 11:10:04  misuj1am
 *
 * -- small code improvment
 *
 * Revision 1.19  2006/04/23 09:45:33  misuj1am
 *
 * -- started using helper methods in iproperty.h isInValidPdf, isArray ..
 *
 * Revision 1.18  2006/04/21 11:02:07  misuj1am
 *
 * --Changes made by miso
 *
 * Revision 1.17  2006/04/20 22:30:47  hockm0bm
 * * IdCollector class added - helper fo getPropertyId
 * * getPropertyId
 *         - use parent->forEach method with IdCollector as functor
 *
 * Revision 1.16  2006/04/20 18:46:33  hockm0bm
 * correction of header - commited by mistake
 *
 * Revision 1.15  2006/04/20 18:02:59  hockm0bm
 * * operator== replaced by propertyEquals method
 * * parameters for getPropertyId and propertyEquals are const referencies
 * * getPropertyId - not useable now, because I don't have mechanism to get
 *         all available ids - but it is compileable
 *
 * Revision 1.14  2006/04/20 10:24:23  misuj1am
 *
 * --ADD getCSTreamFromArray
 *
 * Revision 1.13  2006/04/19 18:40:23  hockm0bm
 * * getPropertyId method implemented
 *         - compilation problems in linking stage (probably because of bad getAllPropertyNames implementation)
 * * operatator== for properties
 * 	- supports only pRef comparing now
 * * simpleEquals helper method for simple value comparing
 *
 * Revision 1.12  2006/04/13 18:14:09  hockm0bm
 * getDictFromRef with reference and pdf parameters
 *
 * Revision 1.11  2006/04/12 21:08:13  hockm0bm
 * printProperty method signature changed
 *         - no implicit parameter
 *         - output stream parameter is reference now
 *
 * Revision 1.10  2006/04/10 23:04:51  misuj1am
 *
 *
 * -- ADD: setValueToSimple, improved the code
 *
 * Revision 1.9  2006/04/09 21:27:13  misuj1am
 *
 *
 * -- getTypeFromDictionary returns shared_ptr<Type> that we want (if possible)
 * 	-- if CRef then try to fetch the indirect object and return it
 *
 * Revision 1.8  2006/04/07 10:23:02  misuj1am
 *
 * -- new observers, they are NOT called if an object changes
 *
 * Revision 1.7  2006/04/03 14:35:13  misuj1am
 *
 *
 * -- ADD: set (int/.../) methods for array
 *
 * Revision 1.6  2006/04/02 17:12:14  misuj1am
 *
 *
 * -- ADD get*FromArray, generic function, avaliable specification for Int and double
 *
 * Revision 1.5  2006/04/02 08:21:03  hockm0bm
 * printProperty helper method signature changed
 *         - stream parameter is not reference
 *         - default parameter is std::cout
 * implementation moved to cc file
 *
 * Revision 1.4  2006/04/01 20:43:48  hockm0bm
 * new output stream parameter for printProperty
 *
 * Revision 1.3  2006/04/01 20:30:03  hockm0bm
 * printProperty helper method for property printing
 *
 * Revision 1.2  2006/03/29 06:13:43  hockm0bm
 * getDictFromRef helper method added
 *
 * Revision 1.1  2006/03/24 17:37:57  hockm0bm
 * new file for helper methods for cobjects
 * in this time only for simple methods from dictionary
 *
 *
 */

#include "cobject.h"
#include "iproperty.h"

namespace pdfobjects
{
namespace utils
{

/** Gets type of the dictionary.
 * @param dict Dictionary wrapped in smart pointer.
 *
 * Tries to get Type field from dictionary and returns its string value. If not
 * present, returns an empty string.
 *
 * @return string name of the dictionary type or empty string if not able to
 * find out.
 */
std::string getDictType(boost::shared_ptr<CDict> dict);
        
/** Helper method for getting int property value from dictionary.
 * @param name Name of the property in the dictionary.
 * @param dict Dictionary where to search.
 *
 * Gets property according name. Checks property type and if it is realy
 * pInt, gets its int value which is returned.
 *
 * @throw ElementNotFoundException if property is not found.
 * @throw ElementBadTypeException if property is found but doesn't contain 
 * integer value.
 * @return int value of the property.
 */
int getIntFromDict(std::string name, boost::shared_ptr<CDict> dict);

/** Helper method for getting reference property value from dictionary.
 * @param name Name of the property in the dictionary.
 * @param dict Dictionary where to search.
 *
 * Gets property according name. Checks property type and if it is realy
 * pRef, gets its IndiRef value which is returned.
 *
 * @throw ElementNotFoundException if property is not found.
 * @throw ElementBadTypeException if property is found but doesn't contain 
 * reference value.
 * @return IndiRef value of the property.
 */
IndiRef getRefFromDict(std::string name, boost::shared_ptr<CDict> dict);

/** Helper method for getting string property value from dictionary.
 * @param name Name of the property in the dictionary.
 * @param dict Dictionary where to search.
 *
 * Gets property according name. Checks property type and if it is realy
 * pString, gets its string value which is returned.
 *
 * @throw ElementNotFoundException if property is not found.
 * @throw ElementBadTypeException if property is found but doesn't contain 
 * string value.
 * @return std::string value of the property.
 */
std::string getStringFromDict(std::string name, boost::shared_ptr<CDict> dict);

/** Helper method for getting name property value from dictionary.
 * @param name Name of the property in the dictionary.
 * @param dict Dictionary where to search.
 *
 * Gets property according name. Checks property type and if it is realy
 * pName, gets its string value which is returned.
 *
 * @throw ElementNotFoundException if property is not found.
 * @throw ElementBadTypeException if property is found but doesn't contain 
 * string value.
 * @return std::string value of the property.
 */
std::string getNameFromDict(std::string name, boost::shared_ptr<CDict> dict);

/** Gets dictionary from reference property.
 * @param refProp Reference property (must be pRef typed).
 *
 * Gets reference value from property and dereferences indirect object from it.
 * Uses refProp's pdf for dereference.
 * Finaly casts (if indirect is dictionary) to CDict and returns.
 *
 * @throw ElementBadTypeException if refProp is not CRef instance or indirect
 * object is not CDict instance.
 * @return CDict instance wrapper by shared_ptr smart pointer.
 */
boost::shared_ptr<CDict> getDictFromRef(boost::shared_ptr<IProperty> refProp)__attribute__((deprecated));

/** Gets dictionary from reference and pdf instance.
 * @param pdf Pdf istance.
 * @param ref Indirect reference.
 *
 * Uses CPdf::getIndirectProperty to get dereferenced object from given
 * reference on given pdf instance. Checks object type and if it is CDict,
 * returns it, otherwise throws an axception.
 *
 * @throw ElementBadTypeException if indirect object is not CDict instance.
 * @return CDict instance wrapper by shared_ptr smart pointer.
 */
boost::shared_ptr<CDict> getDictFromRef(CPdf & pdf, IndiRef ref)__attribute__((deprecated));

/** Helper method for property printing.
 * @param ip Property to print.
 * @param out Output stream, where to print (implicit value is std::cout).
 *
 * Gets string representation of given property and dumps it to standard output.
 * Checks whether this functionality is duplicated.
 */
void printProperty(boost::shared_ptr<IProperty> ip, std::ostream &out);

//=========================================================

/** Equality functor for properties.
 * 
 * Class with function operator to compare two properties. Class can be used as
 * normal function.
 */
class PropertyEquals
{
public:
	/** Equality function operator.
	 * @param val1 Value to compare (with T type wrapped by smart poiter).
	 * @param val2 Value to compare (with T type wrapped by smart poiter).
	 *
	 * Two values are equal iff:
	 * <ul>
	 * <li> have same types (getType returns same value)</li>
	 * <ul> They have same values
	 * 	<li> if value is simple - direct values are same (getValue is used)</li>
	 * 	<li> if value is complex - same number of elements and elements with same
	 * 	identifier are equal</li>
	 * </ul>
	 * </ul>
	 *
	 * <b>Supported types</b><br>
	 * <ul>
			<li> pNull </li>
			<li> pBool </li>
			<li> pInt </li>
			<li> pReal </li>
			<li> pString </li>
			<li> pName </li>
			<li> pRef </li>
	 * </ul>
	 * @throw NotImplementedException if value type is not supported (see supported
	 * types table).
	 *
	 * @return true if values are equal, false otherwise.
	 */
	bool operator()(const boost::shared_ptr<IProperty> & val1, const boost::shared_ptr<IProperty> & val2) const;
};

/** Collector of all Id complying given condition.
 *
 * Full state class which builds internal container (which may be returned by
 * getContainer method) from entries given to functional operator and which
 * matches according given comparator. 
 * <br>
 * Container is type of storage where elements of IdType are stored. Comparator
 * has to implement functional operator with two IProperty types wrapped by
 * shared_ptr smart pointers. Comparator can throw only NotImplementedException
 * to say that it is unable to compare such properties. PropertyEquals functor
 * is used as default type for Comparator.
 * <br>
 * Container instance given, as reference, to the constructor is not encapsulated
 * by class and can expose its state by getContainer method. Class is therefore
 * not responsible for deallocation of its instance. Content of the container
 * can be cleared by reset method (each time new collection should be done, it
 * should be called).
 */
template <typename Container, typename IdType, typename Comparator=PropertyEquals> 
class IdCollector
{
	Container & container;
	const boost::shared_ptr<IProperty> & searched;
	const Comparator comp;
public:
	/** Constructor with initialization.
	 * @param cont Container where to store ids.
	 * @param search Property to be searched.
	 *
	 */
	IdCollector(Container & cont, const boost::shared_ptr<IProperty> & search)
		:container(cont), searched(search), comp(Comparator())
		{};

	/** Filters ids of properties which equals searched.
	 * @param entry Entry which contains identificator, property pair.
	 *
	 * If entry's property equals according Comparator with searched one, adds 
	 * id to the container. 
	 * <br>
	 * Operator can hadle situation when Comparator throws
	 * NotImplementedException and ignores such element.
	 */
	void operator()(std::pair<IdType, boost::shared_ptr<IProperty> > entry)
	{
	using namespace debug;
		try
		{
			// uses propertyEquals method to compare properties
			// it may throw, if element is not supported by operator, we will
			// simply ignore such values
			if(comp(searched, entry.second))
			{
				utilsPrintDbg(DBG_DBG, "Element matches at id="<<entry.first);
				container.push_back(entry.first);
			}
		}catch(NotImplementedException & e)
		{
			// type of element is not supported
			utilsPrintDbg(DBG_WARN, "Element comparing not supported for typ="<<entry.second->getType()<<". Ignoring element.");
		}
	}

	/**
	 * Returns container.
	 *
	 * @return Reference to container.
	 */
	Container & getContainer()
	{
		return container;
	}
	
	/** Clears container.
	 */
	void reset()
	{
		container.clear();
	}
};

/** Gets all identificators of property in parent complex type.
 * @param parent Complex value where to search.
 * @param child Property to search.
 * @param container Container, where to place all identificators (array
 * indexes).
 *
 * Uses CObjectComplex::forEach method with IdCollector functor to collect all
 * ids to given container.
 * <br>
 * Complex template parameter stands for type of CObjectComplex where to search.
 * This type has to provide typedef for propertyId and getAllPropertyNames,
 * getProperty methods.
 * <br>
 * Container template parameter stands for type of storage where to place found
 * indexes. This has to provide clear and push_back methods. Given container is
 * cleared at start.
 *
 */
template<typename Complex, typename Container > void 
getPropertyId(const boost::shared_ptr<Complex> & parent, const boost::shared_ptr<IProperty> &child, Container & container) throw()
{
using namespace std;
using namespace boost;
using namespace debug;

	utilsPrintDbg(DBG_DBG, "");

	// collects all properties identificators which are same as child
	// uses forEach with IdCollector functor
	typedef IdCollector<Container, typename Complex::PropertyId> IdCollectorType;
	IdCollectorType collector(container, child);
	parent->forEach(collector);
	
}


/** Creates property with correct pdf Rectangle representation.
 * @param rect Rectangle to convert.
 *
 * Created property is an array with four elements (see PDF specification
 * page 134 for more information).
 *
 * @return Property (CArray) wrapped by smart pointer.
 */
boost::shared_ptr<IProperty> getIPropertyFromRectangle(const Rectangle & rect);

/** Creates property with correct pdf time representation.
 * @param time Time to convert.
 * 
 * Created property is an string with ASN.1 defined in ISO/IEC 8824 format 
 * used in pdf (see PDF specification page 133 for more information).
 */
boost::shared_ptr<IProperty> getIPropertyFromDate(const tm * time);


/**
 * Get all children of a tree like structre of pdf objects with, "Prev", Next", "First"
 * dictionary entries. This function can be used e.g. for getting all outlines.
 *
 * @param topdict Top level dictionary.
 * @param cont Output container of all children.
 */
template<typename Container>
void
getAllChildrenOfPdfObject (boost::shared_ptr<CDict> topdict, Container& cont)
{

	assert (topdict);

	//
	// Try to find any descandands
	//
	boost::shared_ptr<CDict> dict; 
	try {

		dict = getCDictFromDict (topdict, "First");

	}catch (ElementNotFoundException&) // No child
		{ return; }

	// Get the last child
	boost::shared_ptr<CDict> last = getCDictFromDict (topdict, "Last");
	
	//
	// Children found
	// 
	while (true)
	{
		assert (dict);

		// Add object to container
		cont.push_back (dict);
		// Add all its children
		getAllChildrenOfPdfObject (dict, cont);
		
		// We are at the end
		if (dict == last)
			return;
		
		dict = getCDictFromDict (dict, "Next");
	}
}

/** Checks and replaces mapping in given dictionary.
 * @param annotDict Dictionary to check.
 * @param fieldName Field name to search.
 * @param fieldValue New value for this fieldName.
 *
 * Sets new value of given fieldName field and returns true if this property was
 * replaced, false if it was added.
 *
 * @return true if given fieldName's value has been overwirten, false otherwise.
 */
bool checkAndReplace(boost::shared_ptr<CDict> annotDict, std::string fieldName, IProperty & fieldValue);


/**
 * Get xref from an object.
 */
::XRef* getXRef (boost::shared_ptr<IProperty> ip);

}// end of utils namespace

}// end of pdfobjects namespace
#endif

