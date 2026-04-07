#include <iostream>
#include <string>
using namespace std;

bool whatIHeardYouSay(string input) { 
  cout << "what I heard you say is: " << input << "\n";  
  return input=="quit"; 
}
bool polight(string input) { 
  if(input.find("please quit") == 0) { 
    cout << "nicely said\n"; 
    return true; 
  }  
  cout << "I don't understand\n"; 
  return false; 
}
bool custserv(string input) { 
  if(input == "hangup") {
    return true;
  }
  cout << "I'm sorry. I didn't quite get that. Can you repeat it?\n"; 
  return false; 
}
void processUserInput(bool(*pfnProcess)(string)) { 
    while(true) {
    string input;
        getline(cin, input);
        if(pfnProcess(input)) {
        break;
        }
    }
}
int main() { 
  cout << "Active Listening mode\n"; 
  processUserInput(whatIHeardYouSay); 
  cout << "Polite mode\n"; 
  processUserInput(polight); 
  cout << "Xfinity Customer Service mode\n"; 
  processUserInput(custserv); 
  cout << "Deranged mode\n";
  processUserInput([] (string input) { 
    cout << "whatever\n"; return false; });
  return 0; 
}