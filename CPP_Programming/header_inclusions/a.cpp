#include "a.h"
#include "d.h"

void A::SetC(C* c)
{
  m_c = c;
}

C* A::GetC() const
{
  return m_c;
}

void A::ModifyD(D* d)
{
  d->SetX(0);
  d->SetY(0);
  m_d = d;
}
