#include <iostream>
#include <unordered_map>

//#define MAX_ENGINES 10
#define MAX_QUERIES 100

using namespace std;

int main(int argc, char **argv) {
  
  // predef vars
  int t, s, q, res=0;
  unordered_map<string,int> str_s;
  int query[MAX_QUERIES];

  int count=0;
  unordered_map<string,int> used;
  string temp;

  cin >> t;
  for (int i = 1; i <= t; ++i) {

    // get file info
    cin >> s;
    cin.ignore();
    cout << "Search engines (" << s << "): " << endl;
    for (int j = 0; j < s; ++j) {
      getline(cin, temp);
      str_s[temp] = j;
    }

    // get query and process
    cin >> q;
    cin.ignore();
    cout << "Queries (" << q << "): " << endl;
    for (int m = 0; m < q; ++m) {
      getline(cin, temp);
      auto eng_exist = str_s.find(temp);
      auto eng_used = used.find(temp);
      
      ///debug
      //cout << "used:" << endl;
      //for (auto it = used.begin(); it != used.end(); it++) {
      //  cout << it->first << " " << it->second << endl;
      //}
      //cout << count << endl;
      ///debug end

      if (eng_exist != str_s.end()) {
        query[m] = eng_exist->second;
	if (eng_used == used.end()) {
	  ++count;
          used[temp] = eng_exist->second;
	} else {
	  if (count >= s) {
	    ++res;
            count = 1;
            used.clear();
            used[temp] = eng_exist->second;
	  }
	}
      } else {
        query[m] = s;
      }
    }
    
    /// TODO: 1. check if in str_s, 2. check if engine used
    /// if engine not used add count and add to list
    /// if count greater equal s inc res and reset count to one and keep current string in used
    
    cout << "Case #" << i << ": " << res << endl;
    res=0;
    count=0;
    used.clear();
    str_s.clear();
  }


  return 0;
}
