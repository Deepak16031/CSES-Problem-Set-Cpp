#include <algorithm>
#include <iostream>
#include <set>
int main (int argc, char *argv[]) {
  std::set<int> collection{2, 3, 4, 5};
  std::for_each(collection.begin(), collection.end(), [](int const& i) {
    std::cout << i << std::endl;
  });
  return 0;
}
