#define BOOST_TEST_MAIN

#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include "../data/array_stack.hpp"

BOOST_AUTO_TEST_SUITE (array_stack_test)

BOOST_AUTO_TEST_CASE( Constructors )
{
  ArrayStack * as = new ArrayStack();
  BOOST_CHECK( as -> size() == 0 );
}

BOOST_AUTO_TEST_CASE( Push )
{
  ArrayStack * as = new ArrayStack();
  as -> push( 7 );

  BOOST_CHECK_EQUAL( as->pop(), 7 );
}

BOOST_AUTO_TEST_CASE( Pop )
{
  ArrayStack * as = new ArrayStack();

  as -> push( 6 );
  as -> push( 5 );
  as -> pop();
  as -> push( 1 );

  BOOST_CHECK_EQUAL( as->pop(), 1 );
}

BOOST_AUTO_TEST_CASE( Resize )
{
  ArrayStack * as = new ArrayStack();

  for( int i = 0; i < 512; i++ ){
    as -> push( i );
  }

  BOOST_CHECK( as->size() == 512 );
}

BOOST_AUTO_TEST_CASE( Empty )
{
  ArrayStack * as = new ArrayStack();

  as -> push( 7 );
  as -> push( 9 );
  as -> pop();
  as -> pop();

  BOOST_CHECK( as->size() == 0 );
  BOOST_CHECK( as->empty() );
}

BOOST_AUTO_TEST_SUITE_END( )
