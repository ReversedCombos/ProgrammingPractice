//https://www.codewars.com/kata/52e88b39ffb6ac53a400022e

//This one took about 2 hours. There were parts that I am mad at myself for not catching. For instance when checking if the ip >= pow(2,i)
//I forgot to add the = of >=. This didn't allow the program to enter when the ip and current pow() were equal. This only happend at the //very end of the binary address so it wasn't super obvious as to what was going on.

//Overall I would rate my performance 2/10 and the kata 8/10.

#include <math.h>

std::string uint32_to_ip(uint32_t ip)
{
  //Initialize the string were returning
  std::string returnString = "";
  
  //Initalize an array that can hold the bits for the IPv4
  int ipArr[32] = {0};
  
  //This is a modified bottom-up approach. This starts from the 2^32 IP and takes advantage
  //of the way the way binary works by working backwards through the IP
  for(int i = 31; i >= 0; i--)
  {
    //If it has found a power of i that is greater than the current IP then it subtracts
    //and updates the IP array
    if(ip >= static_cast<uint32_t>(pow(2, i)))
    {
      ip -= static_cast<uint32_t>(pow(2, i));
      ipArr[31 - i] = 1;
    }
  }
  
  //Next is to take the IP array and turn them into octets
  for(int i = 0; i < 32; i++)
  {
    //Checks if i + 1 (arrays start at 0) % 8 == 0
    //This allows to check if something is a perfect divisor of 8 or allow you do something
    //Every Nth steps
    if((i + 1) % 8 == 0)
    {
      //Initalize the octet
      int octet = 0;
      
      //Once the octet index has been found you an subtract 7 from the index and iterate through
      //it again
      for(int x = i - 7; x <= i; x++)
      {
        //If there is a 1 or (ON) in the octet then you can count it
        if(ipArr[x] == 1)
        {
          octet += pow(2, i - x);
        }
      }
      
      //Checks if it is the last iteration
      //If it isn't then add a dot. If it is the don't add a dot.
      if(i < 31)
      {
        returnString += std::to_string(octet) + ".";
      }
      else
      {
        returnString += std::to_string(octet);
      }
    }
  }
  return returnString;
}