//https://www.codewars.com/kata/5263c6999e0f40dee200059d

//This one has me kind of mad. In the list_pins() function I got stuck and had to use ChatGPT. The only thing wrong with it was
//that I was accessing the tempPin.length(), but subtracting one. This resulted in double dipping in the seconds to last digt.
//I identifyed that it was double dipping, narrowed it down to that for loop, but resored to ChatGPT. FML.

//Id rate my performace as a 1/10 and the kata a 10/10

#include <string>
#include <vector>

void list_pins(std::vector<std::string>& possibleNumbers, std::vector<std::string>& possiblePins, std::string& tempPin)
{
  //If the tempPin only has one digit left
  if(tempPin.length() + 1 == possibleNumbers.size())
  {
    //Iterate though the current possibleNumbers and push back the tempPin + possibleNumebrs
    for(int x = 0; x < possibleNumbers[tempPin.length()].length(); x++)
    {
      possiblePins.push_back(tempPin + possibleNumbers[tempPin.length()][x]);
    }
    //Pop back to the previous pin length 
    tempPin.pop_back();
    return;
  }
  
  //Iterate though the currentPossible numbers
  for(int i = 0; i < possibleNumbers[tempPin.length()].length(); i++)
  {
      //Add the current possibleNumber to the tempPin
      tempPin += possibleNumbers[tempPin.length()][i];
      //Add a layer to the recursion
      list_pins(possibleNumbers, possiblePins, tempPin);
  }
  //If the for loop terminates (it has reached the end of the list of possible iterations) then pop back
  tempPin.pop_back();
}

std::vector<std::string> get_pins(std::string observed)
{
  //Initalize varables
  std::vector<std::string> possiblePins;
  std::vector<std::string> possibleNumbers(observed.length());
  std::vector<std::string> keyPad = {"123",
                                     "456",
                                     "789",
                                     " 0 "
                                     };
  
  //Get all possible values of the observed pins
  for(int i = 0; i < observed.length(); i++)
  {
    std::string observedPos = "";

    //Find current observed number index on keyPad
    for(int x = 0; x < keyPad.size(); x++)
    {
      char temp = keyPad[x].find(std::to_string(observed[i] - '0'));
      
      if(temp != std::string::npos)
      {
        observedPos = std::to_string(x) + std::to_string(temp);
        break;
      }
    }
    
    //Using the keyPad index of the current observed number add the 4 adjacent numbers
    //This was convoluted, but it works
    char observedChar = ' ';
    for(int x = 0; x < 5; x++)
    {
      switch(x)
      {
        case 0:
          possibleNumbers[i] += keyPad[observedPos[0] - '0'][observedPos[1] - '0'];
          break;
        case 1:
          observedChar = keyPad[(observedPos[0] - '0') - 1][observedPos[1] - '0'];
          if((observedPos[0] - '0') == 0 || observedChar == ' ')
          {
            continue;
          }
          possibleNumbers[i] += observedChar;
          break;
        case 2:
          observedChar = keyPad[(observedPos[0] - '0') + 1][observedPos[1] - '0'];
          if((observedPos[0] - '0') == 3 || observedChar == ' ')
          {
            continue;
          }
          possibleNumbers[i] += observedChar;
          break;  
        case 3:
          observedChar = keyPad[(observedPos[0] - '0')][(observedPos[1] - '0') - 1];
          if((observedPos[1] - '0') == 0 || observedChar == ' ')
          {
            continue;
          }
          possibleNumbers[i] += observedChar;
          break;
        case 4:
          observedChar = keyPad[(observedPos[0] - '0')][(observedPos[1] - '0') + 1];
          if((observedPos[1] - '0') == 2 || observedChar == ' ')
          {
            continue;
          }
          possibleNumbers[i] += observedChar;
          break;
      }
    }
  }
  //Create the tempPin used in list_pins()
  std::string tempPin;

  //Throw possible pin values into list_pins() along with the possiblePins refrence
  list_pins(possibleNumbers, possiblePins, tempPin);

  //Sort the pins so it matches the comparative case
  std::sort(possiblePins.begin(), possiblePins.end());

  return possiblePins;
}