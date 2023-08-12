//https://www.codewars.com/kata/541c8630095125aba6000c00/train/cpp

//This kata was pretty easy to solve, however, the intersting part of this is the fact you have to take advantage of casting char into int.
//When casting it uses the Ascii values which you can work around by subtracting '0'. This allows you to turn the char into an actual int.

//I would rate my performance as 5/10 and the kata 9/10.

#include <string>

int digital_root(int n)
{
  //Populate the string
  std::string returnString = std::to_string(n);
  
  //While the string is > 1
  while(returnString.length() > 1)
  {
    //Create a temp int
    int temp = 0;
    
    //Iterate though the string and add each single digit value to the temp
    for(int i = 0; i < returnString.length(); i++)
    {
      temp += returnString[i] - '0';
    }
    
    //Set the new int to the string
    returnString = std::to_string(temp);
  }
  
  //Return the single digit number of the digital root
  return stoi(returnString);
}
