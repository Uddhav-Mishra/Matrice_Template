//#define BOOST_TEST_MODULE MatrixOpsTest
#include <boost\include\boost\test\unit_test.hpp>
//#include <boost\exception\exception.hpp>
#include<iostream>
#include <boost\numeric\ublas\matrix.hpp>
#include <Matrix_Ops.hpp>

BOOST_AUTO_TEST_SUITE(PositiveTests)

BOOST_AUTO_TEST_CASE(fiedler5x5) {

        boost::numeric::ublas::matrix<double> A(2, 2);
        A(0,0) = 1 ; A(0,1) = 0;
        A(1,0) = 0 ; A(1,1) = 1;
        
        boost::numeric::ublas::matrix<double> B(2, 2);
        B(0,0) = 1 ; B(0,1) = 0;
        B(1,0) = 0 ; B(1,1) = 1;
}
BOOST_AUTO_TEST_SUITE_END()
