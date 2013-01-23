#define BOOST_TEST_MAIN

#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include "../data/list_single.hpp"

BOOST_AUTO_TEST_SUITE (list_single_test)

BOOST_AUTO_TEST_CASE( Constructors )
{
  SingleList * sl = new SingleList();

  BOOST_CHECK( sl -> size() == 0 );
  BOOST_CHECK( sl -> empty() );
}

BOOST_AUTO_TEST_CASE( Add )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );

  BOOST_CHECK( sl -> size() == 1 );

  sl -> add( 9 );
  sl -> add( 10 );
  sl -> add( 13 );

  BOOST_CHECK( sl -> size() == 4 );
}

BOOST_AUTO_TEST_CASE( Drop )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );
  sl -> drop();

  BOOST_CHECK( sl -> size() == 3 );
}

BOOST_AUTO_TEST_CASE( Value )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  SingleList * n = sl -> drop();

  BOOST_CHECK( sl -> size() == 3 );
  BOOST_CHECK( n -> value() == 127 );
}


BOOST_AUTO_TEST_CASE( Head )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  SingleList * n = sl -> head();

  BOOST_CHECK_EQUAL( sl -> size(), 4 );

  BOOST_CHECK_EQUAL( sl -> value(), 7 );
  BOOST_CHECK_EQUAL( n -> value(), 7 );
}

BOOST_AUTO_TEST_CASE( Tail )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  SingleList * n = sl -> tail();

  BOOST_CHECK_EQUAL( sl -> size(),  4 );
  BOOST_CHECK_EQUAL( n -> value(), 127 );
}

BOOST_AUTO_TEST_CASE( Find )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  SingleList * n17 = sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  SingleList * n = sl -> find( 17 );

  BOOST_CHECK_EQUAL( n, n17 );
  BOOST_CHECK_EQUAL( sl->size(), 4 );
}

BOOST_AUTO_TEST_CASE( Remove )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  SingleList * n = sl -> find( 17 );

  sl->remove( &sl, n );

  SingleList * not17 = sl -> find( 17 );

  BOOST_CHECK( not17 == nullptr );
  BOOST_CHECK_EQUAL( sl->size(), 3 );

  sl -> remove( &sl, sl -> find( 127 ) );

  BOOST_CHECK_EQUAL( sl->size(), 2 );
  BOOST_CHECK_EQUAL( sl->tail()->value(), 27 );

}


BOOST_AUTO_TEST_CASE( Insert )
{
  SingleList * sl = new SingleList();

  sl -> add( 7 );
  sl -> add( 17 );
  sl -> add( 27 );
  sl -> add( 127 );

  sl->insert( &sl, 5, 2 );

  BOOST_CHECK_EQUAL( sl->size(), 5 );

  sl->drop();
  sl->drop();

  SingleList * n = sl -> tail();

  BOOST_CHECK_EQUAL( n->value(), 5 );
  BOOST_CHECK_EQUAL( sl->size(), 3 );

}
BOOST_AUTO_TEST_SUITE_END( )
