#ifndef _a_h_included_
#define _a_h_included_
#include "abase.h"
#include "b.h"

//https://www.eventhelix.com/design-patterns/header-file-include/
/*
Header File Inclusion Rules

Here, we discuss the basic rules of C++ header file inclusion needed to simplify header file management.

    A header file should be included only when a forward declaration would not do the job.
    The header file should be so designed that the order of header file inclusion is not important.
        This is achieved by making sure that x.h is the first header file in x.cpp
    The header file inclusion mechanism should be tolerant to duplicate header file inclusions.

The following sections will explain these rules with the help of an example.
*/

// Forward Declarations
class C;
class D;

class A : public ABase
{
  B m_b;
  C *m_c;
  D *m_d;
  
public:
  void SetC(C *c); // Points m_c to c
  C *GetC() const; // Returns m_c
  
  void ModifyD(D *d);
    //Modifies d, and sets m_d to d
};
#endif