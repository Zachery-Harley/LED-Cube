void Address(bool a0, bool a1, bool a2)
{
  //set the bools to the 3 pins
  digitalWrite(A0, a0);
  digitalWrite(A1, a1);
  digitalWrite(A2, a2);
}

void SetPin(int pin)
{
  //set a pin to enable 0-24
  int board = trunc(pin / 8);
  pin %= 8;

  //set the board
  Board(address[board][0], address[board][1], address[board][2]);
  //Set the pin
  Address(address[pin][0], address[pin][1], address[pin][2]);
}

