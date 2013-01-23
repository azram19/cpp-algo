#define BOOST_TEST_MAIN

#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include "../data/array_queue.hpp"

BOOST_AUTO_TEST_SUITE (array_queue_test)

BOOST_AUTO_TEST_CASE( Constructors )
{
  ArrayQueue * as = new ArrayQueue();
  BOOST_CHECK( as -> size() == 0 );
}

BOOST_AUTO_TEST_CASE( Enqueue )
{
  ArrayQueue * as = new ArrayQueue();
  as -> enqueue( 7 );

  BOOST_CHECK_EQUAL( as->dequeue(), 7 );
}

BOOST_AUTO_TEST_CASE( Dequeue )
{
  ArrayQueue * as = new ArrayQueue();

  as -> enqueue( 6 );
  as -> enqueue( 5 );
  as -> dequeue();
  as -> enqueue( 1 );

  BOOST_CHECK_EQUAL( as->dequeue(), 5 );
}

BOOST_AUTO_TEST_CASE( Resize )
{
  ArrayQueue * as = new ArrayQueue();

  for( int i = 0; i < 512; i++ ){
    as -> enqueue( i );
    as -> enqueue( i*2 );
    as -> dequeue();
  }

  BOOST_CHECK( as->size() == 512 );
  BOOST_CHECK_EQUAL( as->dequeue(), 256 );
}

BOOST_AUTO_TEST_CASE( Empty )
{
  ArrayQueue * as = new ArrayQueue();

  as -> enqueue( 7 );
  as -> enqueue( 9 );
  as -> dequeue();
  as -> dequeue();

  BOOST_CHECK( as->size() == 0 );
  BOOST_CHECK( as->empty() );
}

BOOST_AUTO_TEST_SUITE_END( )
