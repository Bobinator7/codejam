#include <iostream>
//#include <unordered_map>
#include <utility>
#include <regex>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  
  // data set parameters
  int n, t, na, nb;

  string str_tmp;
  regex reg_time("([0-9]+):([0-9]+)");
  smatch sm_time;

  // TODO: reduce variable size for space complexity (int -> unsigned char?)

  cin >> n;
  for (int ii = 1; ii <= n; ++ii) {

    vector<pair<int,int>> trip_ab,trip_ba;

    // get case info
    cin >> t >> na >> nb;
    cin.ignore();
    cout << t << " " << na << " " << nb << endl;

    for (int jj = 0; jj < na; ++jj) {

      int hours, min, start_time, end_time;

      // get start time and length of trip
      cin >> str_tmp;
      if(regex_search(str_tmp,sm_time,reg_time)) {
	hours = stoi(sm_time[1].str());
	min = stoi(sm_time[2].str());
	start_time = 60 * hours + min;
      }
      cin >> str_tmp;
      if(regex_search(str_tmp,sm_time,reg_time)) {
	hours = stoi(sm_time[1].str());
	min = stoi(sm_time[2].str());
	end_time = 60 * hours + min;
      }
      trip_ab.push_back(make_pair(start_time,end_time-start_time));
      //cout << trip_ab[jj].first << " " << trip_ab[jj].second << endl;
    }
    sort(trip_ab.begin(),trip_ab.end());

    for (int jj = 0; jj < nb; ++jj) {

      int hours, min, start_time, end_time;

      // get start time and length of trip
      cin >> str_tmp;
      if(regex_search(str_tmp,sm_time,reg_time)) {
	hours = stoi(sm_time[1].str());
	min = stoi(sm_time[2].str());
	start_time = 60 * hours + min;
      }
      cin >> str_tmp;
      if(regex_search(str_tmp,sm_time,reg_time)) {
	hours = stoi(sm_time[1].str());
	min = stoi(sm_time[2].str());
	end_time = 60 * hours + min;
      }
      trip_ba.push_back(make_pair(start_time,end_time-start_time));
      //cout << trip_ba[jj].first << " " << trip_ba[jj].second << endl;
    }
    sort(trip_ba.begin(),trip_ba.end());

    // output
    cout << "Case #" << ii << ": " << endl;

  }


  return 0;
}
