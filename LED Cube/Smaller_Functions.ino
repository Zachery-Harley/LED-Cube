void Board(bool b0, bool b1, bool b2)
{
  //set the bools to the 3 pins
  digitalWrite(B0, b0);
  digitalWrite(B1, b1);
  digitalWrite(B2, b2);
}

void Level(int level)
{
  //Set the level to be turned on
  switch (level)
  {
    case 0:
      digitalWrite(L0, HIGH);
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
      digitalWrite(L4, LOW);
      break;
    case 1:
      digitalWrite(L0, LOW);
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
      digitalWrite(L4, LOW);
      break;
    case 2:
      digitalWrite(L0, LOW);
      digitalWrite(L1, LOW);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, LOW);
      digitalWrite(L4, LOW);
      break;
    case 3:
      digitalWrite(L0, LOW);
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, HIGH);
      digitalWrite(L4, LOW);
      break;
    case 4:
      digitalWrite(L0, LOW);
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
      digitalWrite(L4, HIGH);
      break;
  }
}

void Plane(int level)
{
  //will light up a single level
  for (int i = 0; i < 25; i++)
  {
    Level(level);
    SetPin(i);
  }
}

void Droplet (int sLevel, int sPin)
{
  //Specil versin allowing a plane to immuminate, then a spare to iluminate
  for (int i = 0; i < 25; i++)
  {
    Level(0);
    SetPin(i);
    //delayMicroseconds(10);
    SetPin(i);
    Level(4);
    //delayMicroseconds(10);
    SetPin(sPin);
    Level(sLevel);
    //delayMicroseconds(10);
  }
}

void Array (String letters)
{
  //create variables
  String levelTemp = "";
  String sPin = "";

  for (int r = 0; r < 50; r++)
  {
    //int arrayLength = length(strfind(letters,','));
    for (int i = 0; i < letters.length(); i++)
    {
      //loop through each letter
      //check for ,
      if (letters[i] == ',')
      {
        //reset the values and set values
        SetPin(sPin.toInt() + (r / 10));
        Level(levelTemp.toInt());
        sPin = "";
        levelTemp =  "";
        delayMicroseconds(1000);
      }
      else
      {
        //check if a level has been set
        if (levelTemp == "")
        {
          //Set the level
          levelTemp += letters[i];
        }
        else
        {
          //get the pin data
          sPin += letters[i];
        }
      }

    }
  }
}












