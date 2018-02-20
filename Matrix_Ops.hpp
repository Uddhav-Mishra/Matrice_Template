#ifndef _BOOST_MATRIX_OPS_
#define _BOOST_MATRIX_OPS_

#include <iostream>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/exception/exception.hpp>
#include <boost/numeric/ublas/io.hpp> 

using namespace std;
namespace boost { namespace numeric { namespace ublas {

	template<class T>
		class Matrice{
			matrix<T> m;
			public:
			Matrice() : m(){}
			Matrice(int x,int y) : m(x,y){}
			void resize(int r,int c){
			m.resize(r,c);
			}
			T get(int i,int j){
				return m(i,j);
			}
			void set(int i,int j,T value){
				m(i,j) = value;
			}
			int size1(){return m.size1();}
			int size2(){return m.size2();}
			Matrice<T> operator=(Matrice<T> other){
				m = other;
			}
		};

	template<class T>
	Matrice<T> operator+(Matrice<T> &a, Matrice<T> &b){
			int rows = a.size1();
    			int cols = a.size2();
			Matrice<T> sum(rows,cols) ;
			for (int i = 0; i < rows ; i++) {
				for(int j=0; j < cols ; j++) {
					sum.set(i,j,a.get(i,j)+b.get(i,j));
				}
			}
			return sum;
	}

	template<class T>	
	Matrice<T> operator+=(Matrice<T> &a, Matrice<T> &b){
			int rows = a.size1();
    			int cols = a.size2();
			for (int i = 0; i < rows ; i++) {
				for(int j=0; j < cols ; j++) {
					a.set(i,j,a.get(i,j)+b.get(i,j));
				}
			}
			return a;
	}
	
	template<class T>	
		Matrice<T> operator*(Matrice<T> &a, Matrice<T> &b){
			int rows = a.size1();
    			int cols = b.size2();
			Matrice<T> product(rows,cols);
			for (int i = 0; i < rows ; i++) {
				for(int j=0; j < cols ; j++) {
					product.set(i,j,0);
					for(int k=0;k<a.size2();k++){
						product.set(i,j,product.get(i,j)+a.get(i,k)*b.get(k,j));
					}
				}
			}
			return product;
	}

	template<class T>	
		Matrice<T> operator *= (Matrice<T> &a, Matrice<T> &b){
			int rows = a.size1();
    			int cols = b.size2();
			Matrice<T> product(rows,cols);
			for (int i = 0; i < rows ; i++) {
				for(int j=0; j < cols ; j++) {
					product.set(i,j,0);
					for(int k=0;k<a.size2();k++){
						product.set(i,j,product.get(i,j)+a.get(i,k)*b.get(k,j));
					}
				}
			}
			a.resize(rows,cols);
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					a.set(i,j,product.get(i,j));
				}
			}
			return a;
	}




// ===================================== above = for template class , below = for standard class =======================






}}}
#endif
