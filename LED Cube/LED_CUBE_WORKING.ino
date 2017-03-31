

#define A0 9
#define A1 8
#define A2 7
#define B0 12
#define B1 11
#define B2 10
#define L0 2
#define L1 3
#define L2 4
#define L3 5
#define L4 6

#define DEBUG

bool address[8][3] = {
  {0, 0, 0}, //Y0
  {1, 0, 0}, //Y1
  {0, 1, 0}, //Y2
  {1, 1, 0}, //Y3
  {0, 0, 1}, //Y4
  {1, 0, 1}, //Y5
  {0, 1, 1}, //Y6
  {1, 1, 1} //Y7
};

void setup() {
  //open serial
  Serial.begin(9600);

  //Create the pin outputs
  //addresses
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  //boards
  pinMode(B0, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  //levels
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
}

void loop() {
 // Anim_Levels(50,true);
 // Anim_Levels(50,false);
  //Anim_Droplets(15,true);
  Anim_Word(" FRANKIE  ZACHERY ");
  //Matrix();
}
