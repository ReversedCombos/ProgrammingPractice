//https://www.codewars.com/kata/5264d2b162488dc400000001/train/cpp

//This was a pretty good kata. The only challege was identifying that when reversing the string it is using the actual length as the input.
//This is becuase it is starting from strCopy.begin() and adding the index. When the index is at the end it is strCopy[i-1].

//I would rate my performace as 6/10 and the kata 8/10.

#include <algorithm>

std::string spinWords(const std::string &str)
{
  int lastWordIndex = 0;
  std::string strCopy = str;
  
  for(int i = 0; i <= strCopy.length(); i++)
  {
    if(!isalpha(strCopy[i]) || i == strCopy.length())
    {
      if(i - lastWordIndex >= 5 )
      {
        reverse(strCopy.begin() + lastWordIndex, strCopy.begin() + i);
      }
      lastWordIndex = i + 1;
    }
  }
  return strCopy;
}