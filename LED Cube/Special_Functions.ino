void Anim_Levels(char rate, bool down)
{
  //Will animate each level sequencialy, with all leds
  //If down is true then the animation will play top down
  if (down == true)
  {
    //set the level
    for (int level = 4 * rate; level != 0; level--)
    {
      Plane(level / rate);
    }
  }
  else
  {
    //set the level
    for (int level = 0; level < 5 * rate; level++)
    {
      Plane(level / rate);
    }
  }
}

void Anim_Droplets (int rate, bool eUp)
{
  //this animation will power up the top and bottom level and create a falling or rasing effect
  //on a randome pin
  //eUP means enable up
  //rate means rate of droplet

  //get randome number for pin
  int rPin[3] = {random(25), 0, 3};
  bool next = false;//true when the cycle has complete

  if (eUp == true && random(10) > 4)
  {
    //Set to up
    rPin[1] = 1;
    rPin[2] = 1;
  }

  //phase pause
  int pause = random(2500);
  //int pause = 10;
  unsigned long previousMillis = millis();
  while (true)
  {
    if ((unsigned long)(millis() - previousMillis) >= pause)
    {
      break;
    }
    Droplet(4, 12);
  }

  //Light up
  while (next == false)
  {
    for (int i = 0; i < rate; i++)
    {
      Droplet(rPin[2], rPin[0]); //Light top level
    }
    //change droplet position
    if (rPin[1] == 1)
    {
      rPin[2]++;
      if (rPin[2] > 4)
      {
        //Go to next droplet
        next = true;
      }
    }
    else
    {
      rPin[2]--;
      if (rPin[2] < 0)
      {
        //go to next dropler
        next = true;
      }
    }
    //end of if check
  }
}

void Matrix()
{
  //Do the cool matrix thing
  int Grid[25][3];//0 - level: 1 - speed: 2 - remainign passes
  for (int r = 0; r < 25; r++)
  {
    //Create a grid
    Grid[r][0] = 4;
    Grid[r][1] = random(50,300);
    Grid[r][2] = Grid[r][1];
  }
  while (true)
  {
    // create a loop to go through each pin in the array
    for (int i = 0; i < 25; i++)
    {
      Level(Grid[i][0]);
      SetPin(i);

      //run the change
      Grid[i][2]--;
      //check if the level should drop
      if(Grid[i][2] <= 0)
      {
        //Reset Counter
        Grid[i][2] = Grid[i][1];
        //Drop Level
        Grid[i][0]--;
        if(Grid[i][0] < 0)
        {
          Grid[i][0] = 4;
          Grid[i][1] = random(50,300);
          Grid[i][2] = Grid[i][1];
        }
      }
    }
  }

}









