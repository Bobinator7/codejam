#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char **argv) {
  
  // data set parameters
  int n, t, na, nb;

  // temporary vars (TODO: move into for loop scope to omit reset code)

  cin >> n;
  for (int i = 1; i <= n; ++i) {

    // get case info
    cin >> t >> na >> nb;
    cin.ignore();
    cout << t << " " << na << " " << nb << endl;


    // output
    cout << "Case #" << i << ": " << endl;

  }


  return 0;
}
