#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
#include<set>
// #include<vector>
#include<algorithm>
using namespace std;
/* Iterators are a general and useful concept for dealing with sequences of elements
in containers. However, containers are not the only place where we find sequences
of elements. For example, an input stream produces a sequence of values, and we
write a sequence of values to an output stream. Consequently, the notion of iterators
can be usefully applied to input and output.
*/


int main() {
  string from, to;
  ostream_iterator<string> oi {cout};  // write strings to cout

  *(oi++) = "Hello ";  // cout << "Hello, "
  *(oi++) = "from ostream_iterator!\n";  // cout << "world!\n"
  *oi = "Please insert two file names from -> to:\n";
  cin >> from >> to;  // get source and target file names

  ifstream is {from};  // input stream for file "from"
  ofstream os {to};  // output stream for file "to"
  // istream_iterator<string> ii {is};  // input iterator for stream
  // istream_iterator<string> eos {};  // input sentinel
  // ostream_iterator<string> oo {os, "\n"};  // output iterator for stream with delimeter '\n'

  // vector<string> b {ii, eos};  // b is a vector initialized from input[ii:eos)
  // sort(b.begin(), b.end());  // sort the buffer
  // unique_copy(b.begin(), b.end(), oo);  // copy buffer to output, discard replicated values

  /* A more elegant solution using set, not storing duplicates at all */
  set<string> b {istream_iterator<string> {is}, istream_iterator<string> {}}; // read input
  copy(b.begin(), b.end(), ostream_iterator<string> {os, "\n"});  // copy to output

  return !is.eof() || !os;  // return error state
}
