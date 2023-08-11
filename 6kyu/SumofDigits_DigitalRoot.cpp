#include <string>

int digital_root(int n)
{
  std::string returnString = std::to_string(n);
  
  while(returnString.length() > 1)
  {
    int temp = 0;
    
    for(int i = 0; i < returnString.length(); i++)
    {
      temp += returnString[i] - '0';
    }
    
    returnString = std::to_string(temp);
  }
  
  return stoi(returnString);
}