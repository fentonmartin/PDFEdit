/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
/*
 * =====================================================================================
 *        Filename:  coordinates.h
 *     Description:  
 *         Created:  26/11/2006 05:42:41 PM CET
 *          Author:  jmisutka ()
 * =====================================================================================
 */

#ifndef _COORDINATES_H_
#define _COORDINATES_H_

//============================================
namespace _JM_NAMESPACE {
//============================================


//============================================
// Point
//============================================

//
// Typedefs
//
/** Coordinate according to pdf specification. */
typedef double Coordinate;
/** Invalid coordinate. */
const double COORDINATE_INVALID = std::numeric_limits<Coordinate>::max();

/**
 * Generic point. 
 */
template <typename Coord>
struct GenPoint
{
	Coord x; /**< X coordinate. */
	Coord y; /**< Y coordinate. */
	/** Constructor. */
	GenPoint () {x = y = COORDINATE_INVALID;}
	/** Constructor. */
	GenPoint (Coord _x, Coord _y) : x(_x), y(_y) {}

};

//
// Typedefs
//
/** Basic point. */
typedef struct GenPoint<Coordinate> Point;


//============================================
// Rectagnle
//============================================

/**
 * Generic rectangle.
 */
template <typename Coord>
struct GenRect
{
	typedef struct GenRect<Coord> Type;

	Coord xleft; 	/**< Left x coordinate. */
	Coord yleft; 	/**< Left y coordinate. */
	Coord xright;	/**< Right x coordinate. */
	Coord yright;	/**< Right y coordinate. */

	//
	// Constructor
	//
public:
	GenRect ()	{xleft = yleft = xright = yright = COORDINATE_INVALID;}
	GenRect (Coord x1, Coord y1, Coord x2, Coord y2) : xleft(x1), yleft(y1), xright(x2), yright(y2) {}

	//
	// Helper functions
	//
public:

	/** 
	 * True if the rectangle contains the point.
	 * 
	 * @param x x-coordinate of point.
	 * @param y y-coordinate of point.
	 *
	 * @return True if the specified point is in the rectangle, false otherwise.
	 */
	bool contains (Coord x, Coord y) const
	{
		//kernelPrintDbg (debug::DBG_DBG, "x: " << x << " y: " << y << " Rect:" << *this);
		return ( std::min(xleft,xright) <= x && x <= std::max(xleft,xright) 
				&& std::min (yleft,yright) <= y && y <= std::max(yleft,yright) );
	}

	/** Equality operator. */
	bool operator== (const GenRect<Coord>& rc) const
	{
		return (xleft == rc.xleft && xright == rc.xright &&
				yleft == rc.yleft && yright == rc.yright);
	}

	/** Is initialized. */
	static bool isInitialized (Type rc)
		{ return !(COORDINATE_INVALID == rc.xleft); }
	
};


//
// Typedefs
//
/** Basic rectangle. */
typedef struct GenRect<Coordinate> Rectangle;


//=====================================================================================
// Basic algorithms
//=====================================================================================

/** Merge two rectangles to one. */
inline Rectangle 
rectangle_merge (Rectangle _b1, Rectangle _b2)
{
	Coordinate xleft = 0, xright = 0, yleft = 0, yright = 0;
	
	//
	// 0,0 can be in 4 different corners (bottom/top left/right)
	//
	if (_b1.xleft > _b1.xright)
	{
		xleft = std::max (_b1.xleft,_b2.xleft);
		xright = std::min (_b1.xright,_b2.xright);
	}else
	{
		xleft = std::min (_b1.xleft,_b2.xleft);
		xright = std::max (_b1.xright,_b2.xright);
	}

	if (_b1.yleft > _b1.yright)
	{
		yleft = std::max (_b1.yleft,_b2.yleft);
		yright = std::min (_b1.yright,_b2.yright);
	}else
	{
		yleft = std::min (_b1.yleft,_b2.yleft);
		yright = std::max (_b1.yright,_b2.yright);
	}

	return Rectangle (xleft, yleft, xright, yright);
}

/** Intersect two rectangles. */
inline Rectangle 
rectangle_intersect (Rectangle _b1, Rectangle _b2)
{
	Coordinate xleft = 0, xright = 0, yleft = 0, yright = 0;
	
	//
	// Does it intersect at all
	//
	if ( std::min(_b1.xleft,_b1.xright) > std::max(_b2.xleft, _b2.xright)
		|| std::max(_b1.xleft,_b1.xright) < std::min(_b2.xleft, _b2.xright)
		|| std::min(_b1.yleft,_b1.yright) > std::max(_b2.yleft, _b2.yright)
		|| std::max(_b1.yleft,_b1.yright) < std::min(_b2.yleft, _b2.yright)
		)
		return Rectangle ();

	//
	// 0,0 can be in 4 different corners (bottom/top left/right)
	//
	if (_b1.xleft > _b1.xright)
	{
		xleft = std::min (_b1.xleft,_b2.xleft);
		xright = std::max (_b1.xright,_b2.xright);
	}else
	{
		xleft = std::max (_b1.xleft,_b2.xleft);
		xright = std::min (_b1.xright,_b2.xright);
	}

	if (_b1.yleft > _b1.yright)
	{
		yleft = std::min (_b1.yleft,_b2.yleft);
		yright = std::max (_b1.yright,_b2.yright);
	}else
	{
		yleft = std::max (_b1.yleft,_b2.yleft);
		yright = std::min (_b1.yright,_b2.yright);
	}

	return Rectangle (xleft, yleft, xright, yright);
}


//=====================================================================================
// Special output functions
//=====================================================================================

/**
 * Print Rectangle to output stream.
 *
 * @param os Output stream.
 * @param rc Rectangle to be printed.
 *
 * @return Output stream.
 */
inline std::ostream& 
operator << (std::ostream& os, const Rectangle& rc)
{
	os 	<< "xleft: " << rc.xleft << " yleft: " << rc.yleft
		<< " xright: " << rc.xright << " yright: " << rc.yright ;
	
	return os;
}

/**
 * Print Point to output stream.
 * 
 * @param os Output stream.
 * @param pt Point to be printed.
 *
 * @return Output stream.
 */
inline std::ostream& 
operator << (std::ostream& os, const Point& pt)
{
	os 	<< "x: " << pt.x << " y: " << pt.y;
	return os;
}


//============================================
} // namespace _JM_NAMESPACE
//============================================

#endif // _COORDINATES_H_
