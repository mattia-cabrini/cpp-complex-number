#include <iostream>
#include "complex.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  complex n, o;

  cout << "Insert a complex number (Re <SPC> Im): ";
  cin >> n;

  cout << "Insert a complex number (Re <SPC> Im): ";
  cin >> o;

  cout << "N: " << n << endl << "O: " << o << endl;

  cout << "N + O = " << n + o << endl;
  cout << "N - O = " << n - o << endl;
  cout << "N * O = " << n * o << endl;
  cout << "N * 2 = " << n * 2 << endl;
  cout << "N / O = " << n / o << endl;
  cout << "N / 2 = " << n / 2 << endl;
  cout << "|N| = " << n.magnitude() << endl;
  cout << "L(N) = " << n.phase() << endl;
  cout << "-N = " << -n << endl;
  cout << "!N = " << !o << endl;
  cout << "1 / N = " << n.Y() << endl;

  return 0;
}
