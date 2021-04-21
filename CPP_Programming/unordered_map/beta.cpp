#include <iostream>
#include <vector>
// unordered_map::insert
#include <string>
#include <unordered_map>

struct X
{
  std::unordered_map<std::string, int*> map;
};

int main ()
{
  int val = 5;
  int* y = &val;
  X* x = new X;

  const auto insertion = x->map.insert({"Maps",y});
  std::cout<<insertion.first->second<<std::endl;

  const auto emp = x->map.insert({"Name",nullptr});
  const bool e = emp.first;
  const bool m = emp.second;
  std::cout<<((e)?"True":"False")<<std::endl;
  std::cout<<((m)?"True":"False")<<std::endl;

  return 0;
}