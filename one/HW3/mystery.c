#include "mystery.h"

int myst(int number)
{
  if (number == 0)
  {
    return 2;
  }
  else if (number == 1)
  {
    return 1;
  }
  else
  {
    return 2 * myst(number-1) +myst(number-2);
  }

};
