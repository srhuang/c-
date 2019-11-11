/*****************************************************************
Name    :template
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190923 Initial Version
*****************************************************************/
#include <iostream>
using namespace std;

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
class IntVec {
public:
   IntVec(int n): data(new int[n]),size(n) { }
   ~IntVec() { delete[] data; };
   int& operator[](int n)
      { return data[n]; }
   const int& operator[](int n) const
      { return data[n]; }

   /*assignement operator*/
   IntVec&
   operator=(const IntVec& v) {
      int* newdata = new int[v.size];
      std::copy(v.data,v.data+v.size, newdata);
      delete[] data;
      data = newdata;
      size = v.size;
      return *this;
   }

   /*copy constructor*/
   IntVec(const IntVec& v):
      data(new int[v.size]),
      size(v.size) {
      std::copy(data, data + size, v.data);
   }

private:
   int* data;
   int size;
};

/*==============================================================*/
int main()
{
   IntVec x(100);
   IntVec y=x;   // Trouble!
   IntVec z(x);   // Trouble!
   return 0;
}
/*==============================================================*/