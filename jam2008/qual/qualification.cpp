#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char **argv) {
  
  // data set parameters
  int t, s, q;

  // temporary vars (TODO: move into for loop scope to omit reset code)
  int res=0,count=0;
  unordered_map<string,int> used;
  unordered_map<string,int> str_s;
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
      // check if query is a search engine
      if (eng_exist != str_s.end()) {
	// check if query is current search engine (last possible option)
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
      } 
    }

    // output
    cout << "Case #" << i << ": " << res << endl;

    // reset temporary vars
    res=0;
    count=0;
    used.clear();
    str_s.clear();
  }


  return 0;
}
