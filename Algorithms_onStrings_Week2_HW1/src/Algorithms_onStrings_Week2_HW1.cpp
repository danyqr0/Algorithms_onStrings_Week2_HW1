//============================================================================
// Name        : Algorithms_onStrings_Week2_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week2
// Description : Construct the Burrows–Wheeler Transform of a String
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> M;

string BWT(const string& text) {
  char x;
  string text_tmp=text;
  string text_tmpb=text;
  vector<string>::iterator it;
  string result = "";

  M.push_back(text_tmp);

  for(int i=1;i<text.size();i++){
      x=text_tmp.back();
      if(x == 'A' || x == 'T' || x == 'C' || x == 'G' || x == '$'){
         text_tmp.replace(text_tmp.begin()+1,text_tmp.end(),text_tmpb.begin(),text_tmpb.end()-1);
         text_tmp.at(0)=x;
         text_tmpb=text_tmp;
         M.push_back(text_tmp);
      }
  }
  std::sort (M.begin(),M.end());

  for(it=M.begin();it!=M.end();++it)
	  result.push_back((*it).back());

  return result;
}


int main() {
	  string text;
	  cin >> text;
      if(text.size()>=1 && text.size()<=1000){
	     cout << BWT(text) << endl;
      }
	  return 0;
}
