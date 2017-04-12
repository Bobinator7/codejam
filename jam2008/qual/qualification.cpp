#include <iostream>
#include <list>

#define MAX_ENGINES 10
#define MAX_QUERIES 100

using namespace std;

int main(int argc, char **argv) {
  
  // predef vars
  int t, s, q, res;
  string str_s[MAX_ENGINES];
  string str_q[MAX_QUERIES];

  int count;
  bool first_flag = true;
  list<string> used;

  // get header
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ":" << endl;
    
    // get file info
    cin >> s;
    cin.ignore();
    cout << "Search engines (" << s << "): " << endl;
    for (int j = 0; j < s; ++j) {
      getline(cin, str_s[j]);
      cout << str_s[j] << endl;
    }

    cin >> q;
    cin.ignore();
    cout << "Queries (" << q << "): " << endl;
    for (int m = 0; m < q; ++m) {
      getline(cin, str_q[m]);
      cout << str_q[m] << endl;
    }

    // process data
    for (int m = 0; m < q; ++m) {

      /// TODO: 1. check if in str_s, 2. check if engine used
      /// if engine not used add count and add to list
      /// if count greater equal s inc res and reset count to one and keep current string in used

    }
    
  }

  //cout << "Case #" << i << ": " << res << endl;

  return 0;
}
