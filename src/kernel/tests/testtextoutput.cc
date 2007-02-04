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
/*
 * =====================================================================================
 *        Filename:  testtextoutput.cc
 *         Created:  13/10/2006 09:07:27 PM CEST
 *          Author:  jmisutka (), 
 * =====================================================================================
 */

#include "testmain.h"
#include "testcobject.h"
#include "testcpage.h"
#include "testcpdf.h"

#include "textoutput.h"
#include "textoutputengines.h"


//=====================================================================================
namespace {
//=====================================================================================
using namespace std;
using namespace boost;
using namespace textoutput;

//=====================================================================================
bool text_cpageout (__attribute__((unused)) std::ostream& oss, 
			   __attribute__((unused)) const char* file_name)
{

	boost::shared_ptr<CPdf> pdf (getTestCPdf (file_name), pdf_deleter());

	for (size_t i = 0; i < pdf->getPageCount() && i < 1/*TEST_MAX_PAGE_COUNT*/; ++i)
	{
		boost::shared_ptr<CPage> page = pdf->getPage (i+1);

		XmlOutputBuilder out;
		page->convert<SimpleWordEngine,
					  SimpleLineEngine,
					  SimpleColumnEngine> (out);
		ofstream of;
		of.open ("1.xml");
		of << XmlOutputBuilder::xml(out);
		of.close();
	}

	return true;
}


//=========================================================================
// class TestTextOutput
//=========================================================================

class TestTextOutput : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(TestTextOutput);
		CPPUNIT_TEST(test_cpageout);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() {OUTPUT << endl;}
	void tearDown() {}

public:
	//
	//
	//
	void test_cpageout ()
	{
		for (FileList::const_iterator it = fileList.begin (); it != fileList.end(); ++it)
		{
			OUTPUT << "Testing filename: " << *it << endl;
			
			TEST(" text cpage output");
			CPPUNIT_ASSERT (text_cpageout (OUTPUT, (*it).c_str()));
			OK_TEST;
		}
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(TestTextOutput);
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestTextOutput, "TEST_TEXTOUTPUT");

//=====================================================================================
} // namespace
//=====================================================================================








