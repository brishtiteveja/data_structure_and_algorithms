Welcome to Facebook!

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

Enjoy your interview!
   
  
    input string:   { 
                           
    output string:  (){{}}{}
                           
                           
    stack <char>
      
      s    ( { [   ] 
      
    input string:  (111(1))  ))
    output string:  (111(1))  


 paren  
 pi             
            
#include <iostream>
#include <stack>

using namespace std;
            
            
stack<int> pi;

bool isValid(string s) {  
  
  bool isv = true;
  
  for(int i=0; i<s.length(); i++) {
    char c = s[i];
    switch(c) 
    {
      case '(':
      case '{':
      case '[': paren.push(c); pi.push(i); break;
      case ')': 
        if(paren.empty() || paren.top() != '(') {
                    pi.push(i);
                    isv = false;
        }
        else { 
          paren.pop();
          pi.pop(); 
        }
        break;
     case '}': 
        if(paren.empty() || paren.top() != '{') {
                    return false;
        }
        else {
          paren.pop();
          pi.pop();
        }
        break;
     case ']': 
        if(paren.empty() || paren.top() != '[') {
                    return false;
        }
        else {
          paren.pop();
          pi.pop();
        }
        break;
      default:
        break;
    }
  }
  
  
  return paren.empty()? false: true;
  
}


string getValidString(string s) {
  string res;
  
  vector<char> vc;
  
  for(int i=0; i<s.length(); i++)
    vc.push_back(s[i]);
  
  vector canTake[s.length()];
  
  for(int i=0; i<s.length(); i++)
    canTake[i] = 1;

  if (isValid(s))
    return s;
  else {
    while(!pi.empty()) {
      int i = pi.top();
      pi.pop();
      
      canTake[i] = 0;
    }
  
    for(int i=0; i<vc.size(); i++) {
       if (canTake[i])
        res.push_back(vc[i]);
    }
  }
    
  return res;
  
}


                     
        
