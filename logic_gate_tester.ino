#include <LiquidCrystal.h>
#include <Keypad.h>

void NORgate(void);
void NANDgate(void);
void ANDgate(void);
void ORgate(void);
void XORgate(void);
void XNORgate(void);
void NOTgate(void);


void greenONE(void);
void greenTWO(void);
void greenTHREE(void);
void greenFOUR(void);
void greenFIVE(void);
void greenSIX(void);
void redTWO(void);
void redTWO(void);
void redTHREE(void);
void redFOUR(void);
void redFIVE(void);
void redSIX(void);


const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd (40, 42, 44, 46, 48, 50);


int outONEgreen = A0;
int outTWOgreen = A1;
int outTHREEgreen = A2;
int outFOURgreen = A3;
int outONEred = A4;
int outTWOred = A5;
int outTHREEred = A6;
int outFOURred = A7;

int outFIVEgreen = A8;
int outSIXgreen = A9;
int outFIVEred = A10;
int outSIXred = A11;

int var = 0;
int flagG1 = 0;
int flagG2 = 0;
int flagG3 = 0;
int flagG4 = 0;

int flagR = 0;

String Data;
char customKey;

int I1 = 2 ;
int I2 = 3;
int O1 = 4;

int I3 = 5;
int I4 = 6;
int O2 = 7;

int I5 = 8;
int I6 = 9;
int O3 = 10;

int I7 = 11;
int I8 = 12;
int O4 = 13;



//...............GETSTRING.......
String GetString()
{
  String num;
  int i = 0;
  lcd.clear();
  char key = customKeypad.getKey();
  lcd.print("IC No & Press #");
  while (key != '#')
  {
    switch (key)
    {
      case NO_KEY:
        break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
      case 'A': case 'B': case 'C': case 'D': case 'E':
      case 'F':
        lcd.setCursor(i, 1);
        lcd.print(key);
        num = num + key;
        i = i + 1;
        break;

      case '*':
        num = "";
        lcd.clear();
        break;
    }

    key = customKeypad.getKey();
  }
  lcd.clear();
  return num;

}




//.......... Main Code ...............

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("\n\n Test Begin ");
  lcd.setCursor(0, 0);
  lcd.print("Welcome !");
  lcd.setCursor(0, 1);
  lcd.print("To Gate Test");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Developed by");
  lcd.setCursor(0, 1);
  lcd.print("Jikrul 1503048");
  delay(2000);
  lcd.clear();


  pinMode(outONEgreen, OUTPUT);
  pinMode(outTWOgreen, OUTPUT);
  pinMode(outTHREEgreen, OUTPUT);
  pinMode(outFOURgreen, OUTPUT);

  pinMode(outONEred, OUTPUT);
  pinMode(outTWOred, OUTPUT);
  pinMode(outTHREEred, OUTPUT);
  pinMode(outFOURred, OUTPUT);

}

void loop() {

  //7402
L1:
  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  clearALLled();

  lcd.print("Press Any Key To");
  lcd.setCursor(0, 1);
  lcd.print("Activate Keypad!");

  customKey = customKeypad.getKey();
  if (customKey != 0) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("KeyPad Activated!");
    delay(500);

    Data = GetString();

    if (Data != 0)
    {
      if (Data == "7400")
      {
        NANDgate();
        goto L1;
      }

      else if (Data == "7402")
      {
        NORgate();
        goto L1;
      }

      else if (Data == "7408")
      {
        ANDgate();
        goto L1;

      }
      else if (Data == "7432")
      {
        ORgate();
        goto L1;
      }
      else if (Data == "7486")
      {
        XORgate();
        goto L1;
      }
      else if (Data == "74286")
      {
        XNORgate();
        goto L1;
      }
      else if (Data == "7404")
      {
        NOTgate();
        goto L1;
      }

      else
      {
        lcd.clear();
        lcd.print("Enter Right");
        lcd.setCursor(0,1);
        lcd.print("Circuit NO");        
        delay(2000);
        lcd.clear();
        goto L1;
      }
    }
  }

}

//-------Code For IC check & NORgate------------

void NORgate()
{
  lcd.clear();
  Serial.println("Test For 7402_NOR _GATE");
  lcd.print("Test 7402 NOR");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7402_NOR
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(O1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I1, INPUT);

  digitalWrite(O1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(I1);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(I1);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(O1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(I1);
  if (var == LOW)
  {
    flagG3 = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(O1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(I1);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    delay(1000);
    Serial.println("\n\n Gate 1 is BAD");
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(O2, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(I3, INPUT);

  digitalWrite(O2, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O2, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O2, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(O2, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(I3);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");



  //for 3rd gate test Logic 01
  pinMode(I5, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(O3, INPUT);

  digitalWrite(I5, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 3rd gate test Logic 02

  digitalWrite(I5, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 3rd gate test Logic 03

  digitalWrite(I5, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(I5, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(O3);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;


  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  //for 4th gate test Logic 01
  pinMode(I7, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(O4, INPUT);

  digitalWrite(I7, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(O4);

  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(I7, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(O4);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(I7, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(O4);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(I7, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(O4);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD ");
    delay(1000);
  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
     lcd.clear();
    Serial.println("\n\n Gate 4 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  delay(500);
  lcd.clear();

}

//-------END NORgate------------



//-------Code For IC check & NANDgate--------

void NANDgate()
{
  lcd.clear();
  Serial.println("Test For 7400_NAND_GATE");
  lcd.print("Test 7400 NAND");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7400_NAND
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(O1, INPUT);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(O2, INPUT);

  digitalWrite(I3, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");



  //for 3rd gate test Logic 01
  pinMode(O3, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(I5, INPUT);

  digitalWrite(O3, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O3, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O3, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 3rd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O3, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  //for 4th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(I7, INPUT);

  digitalWrite(O4, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);

  if (var == LOW)
  {

    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(O4, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O4, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O4, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD ");
    delay(1000);
  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
    Serial.println("\n\n Gate 2 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  delay(500);
  lcd.clear();

}

//-------END NANDgate------------

//-------Code For IC check & ANDgate--------
void ANDgate()
{
  lcd.clear();
  Serial.println("Test For 7408_AND_GATE");
  lcd.print("Test 7408 AND");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7408_AND
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(O1, INPUT);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();


  // 7408_AND
  //for 2nd gate test Logic 01
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(O2, INPUT);

  digitalWrite(I3, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD");
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is GOOD");
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");


  // 7408_AND
  //for 3rd gate test Logic 01
  pinMode(O3, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(I5, INPUT);

  digitalWrite(O3, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 3rd gate test Logic 02

  digitalWrite(O3, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O3, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O3, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  // 7408_AND
  //for 4th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(I7, INPUT);

  digitalWrite(O4, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);

  if (var == HIGH)
  {

    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 4th gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(O4, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O4, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O4, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD ");
    delay(1000);
  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redFOUR();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
    Serial.println("\n\n Gate 4 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  delay(500);
  lcd.clear();

}
//-------END ANDgate------------

//-------Code For IC check & ORgate 7432--------
void ORgate()
{
  lcd.clear();
  Serial.println("Test For 7432_OR_GATE");
  lcd.print("Test 7432 OR");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7432_OR
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(O1, INPUT);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(O2, INPUT);

  digitalWrite(I3, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(3000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 3rd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");



  //for 3rd gate test Logic 01
  pinMode(O3, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(I5, INPUT);

  digitalWrite(O3, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 3rd gate test Logic 02

  digitalWrite(O3, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 3rd gate test Logic 03

  digitalWrite(O3, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 3rd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O3, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  //for 4th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(I7, INPUT);

  digitalWrite(O4, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);

  if (var == HIGH)
  {

    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 4th gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(O4, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O4, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 4th gate test Logic 04

  digitalWrite(O4, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD ");
    delay(1000);
  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redFOUR();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
    Serial.println("\n\n Gate 4 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  delay(500);
  lcd.clear();

}

//-------END ORgate------------

//-------Code For IC check & XORgate 7486--------

void XORgate()
{
  lcd.clear();
  Serial.println("Test For 7486_XOR_GATE");
  lcd.print("Test 7486 XOR");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7486_XOR
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(O1, INPUT);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(O2, INPUT);

  digitalWrite(I3, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(3000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 3rd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");



  //for 3rd gate test Logic 01
  pinMode(O3, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(I5, INPUT);

  digitalWrite(O3, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O3, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 3rd gate test Logic 03

  digitalWrite(O3, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 3rd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(O3, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  //for 4th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(I7, INPUT);

  digitalWrite(O4, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);

  if (var == LOW)
  {

    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 4th gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(O4, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O4, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 4th gate test Logic 04

  digitalWrite(O4, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD ");
    delay(1000);
  }
  else
  {
    redFOUR();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
    Serial.println("\n\n Gate 4 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  delay(500);
  lcd.clear();

}


//-------END XORgate------------

//-------Code For IC check & XNORgate 7486-------

void XNORgate()
{
  delay(1000);
  lcd.clear();
  Serial.println("Test For 74266_XNOR_GATE");
  lcd.print("Test 74266 XNOR");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 74266_XNOR
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(O1, INPUT);

  digitalWrite(I1, HIGH);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for first gate test Logic 03 ");

  //for first gate test Logic 03

  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for first gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  var = digitalRead(O1);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }



  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redONE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(O2, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(I3, INPUT);

  digitalWrite(O2, HIGH);
  digitalWrite(I4, HIGH);
  var = digitalRead(I3);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O2, LOW);
  digitalWrite(I4, HIGH);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 2nd gate test Logic 03 ");

  //for 2nd gate test Logic 03

  digitalWrite(O2, HIGH);
  digitalWrite(I4, LOW);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for first gate test Logic 04

  digitalWrite(O2, LOW);
  digitalWrite(I4, LOW);
  var = digitalRead(I3);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 || flagR == 103 || flagR == 104  )
  {
    redTWO();
    delay(3000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 3rd gate test Logic 01 ");



  //for 3rd gate test Logic 01
  pinMode(I5, OUTPUT);
  pinMode(I6, OUTPUT);
  pinMode(O3, INPUT);

  digitalWrite(I5, HIGH);
  digitalWrite(I6, HIGH);
  var = digitalRead(O3);
  if (var == HIGH)
  {
    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 3rd gate test Logic 02

  digitalWrite(I5, LOW);
  digitalWrite(I6, HIGH);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 3rd gate test Logic 03 ");

  //for 3rd gate test Logic 03

  digitalWrite(I5, HIGH);
  digitalWrite(I6, LOW);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 04 ");

  //for 3rd gate test Logic 04

  digitalWrite(I5, LOW);
  digitalWrite(I6, LOW);
  var = digitalRead(O3);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD ");
    delay(1000);

  }

  //if(flagR ==101 || flagR ==102 || flagR ==103 || flagR ==104  )
  else
  {
    redTHREE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 3 is BAD");
    Serial.println("\n\n Gate3 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 4th gate test Logic 01 ");


  //for 4th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, OUTPUT);
  pinMode(I7, INPUT);

  digitalWrite(O4, HIGH);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);

  if (var == HIGH)
  {

    flagG1 = 101;
    lcd.print("H&H OK");
    Serial.println("\n\n LOGIC H & H Is OK ");

  }
  else
  {
    flagR = 101;
    lcd.print("H&H NO");
    Serial.println("\n\n H & H ERROR ");

  }

  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 4th gate test Logic 02

  digitalWrite(O4, LOW);
  digitalWrite(I8, HIGH);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H OK");
    Serial.println("\n\n LOGIC L & H Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L&H NO");
    Serial.println("\n\n L & H ERROR ");
  }


  Serial.println("\n\n for 4th gate test Logic 03 ");

  //for 4th gate test Logic 03

  digitalWrite(O4, HIGH);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == LOW)
  {
    flagG3 = 103;

    lcd.setCursor(0, 1);
    lcd.print("H&L OK");
    Serial.println("\n\n LOGIC H & L Is OK ");
  }
  else
  {
    flagR = 103;
    lcd.setCursor(0, 1);
    lcd.print("H&L NO");
    Serial.println("\n\n H & L ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 04 ");

  //for 4th gate test Logic 04

  digitalWrite(O4, LOW);
  digitalWrite(I8, LOW);
  var = digitalRead(I7);
  if (var == HIGH)
  {
    flagG4 = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L OK");
    Serial.println("\n\n LOGIC L & L Is OK ");
  }
  else
  {
    flagR = 104;
    lcd.setCursor(7, 1);
    lcd.print("L&L NO");
    Serial.println("\n\n L & L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 && flagG3 == 103 && flagG4 == 104)
  {
    Serial.println(flagG1);
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate 4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD ");
    delay(1000);
  }
  else
  {
    redFOUR();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 4 is BAD");
    Serial.println("\n\n Gate 4 is BAD ");
    delay(1000);
  }

  Serial.println("\n\n END 4th Gate Checking ");

  clearALLled();


  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;

  delay(500);
  lcd.clear();

}


//-------END XNORgate------------

//-------Code For IC check & NOTgate 7404-------

void NOTgate()
{
  lcd.clear();
  Serial.println("Test For 7404_NOT_GATE");
  lcd.print("Test 7404 NOT");
  delay(1000);
  lcd.clear();

  Serial.println("\n\n for 1st gate test Logic 01 ");


  // 7404_NOT
  //for first gate test Logic 01
  lcd.clear();
  lcd.print("1st Gate Test");
  delay(1000);
  lcd.clear();
  pinMode(I1, OUTPUT);
  pinMode(I2, INPUT);

  digitalWrite(I1, HIGH);
  var = digitalRead(I2);
  if (var == LOW)
  {
    flagG1 = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H Is OK ");
  }
  else
  {
    flagR = 101;
    //lcd.setCursor(0, 1);
    lcd.print("H NO");
    Serial.println("\n\n H ERROR ");
  }

  Serial.println("\n\n for 1st gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I1, LOW);
  var = digitalRead(I2);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L ERROR ");
  }

  if (flagG1 == 101 && flagG2 == 102 )

  {
    greenONE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate1 is GOOD");
    Serial.println("\n\n Gate 1 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102)
  {
    redONE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate 1 is BAD");
    Serial.println("\n\n Gate 1 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 1st Gate Checking ");

  //------------2nd Gate-----------------------

  flagG1 = 0;
  flagG2 = 0;
  flagR = 0;
  Serial.println("\n\n for 2nd gate test Logic 01 ");
  lcd.clear();
  lcd.print("2nd Gate Test");
  delay(1000);
  lcd.clear();



  //for 2nd gate test Logic 01
  pinMode(O1, OUTPUT);
  pinMode(I3, INPUT);

  digitalWrite(O1, HIGH);
  var = digitalRead(I3);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H  Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H NO");
    Serial.println("\n\n H  ERROR ");
  }

  Serial.println("\n\n for 2nd gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(O1, LOW);
  var = digitalRead(I3);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L  ERROR ");
  }


  
  if (flagG1 == 101 && flagG2 == 102)

  {
    greenTWO();
    delay(2000);
    lcd.clear();
    lcd.print("Gate2 is GOOD");
    Serial.println("\n\n Gate 2 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 )
  {
    redTWO();
    delay(3000);
    lcd.clear();
    lcd.print("Gate2 is BAD");
    Serial.println("\n\n Gate 2 is BAD");
    delay(1000);
  }

  Serial.println("\n\n END 2nd Gate Checking ");

  //...............3rd GATE.............................

  flagG1 = 0;
  flagG2 = 0;
  flagR = 0;
  Serial.println("\n\n for 3rd gate test Logic 01 ");
  lcd.clear();
  lcd.print("3rd Gate Test");
  delay(1000);
  lcd.clear();



  //for 3rd gate test Logic 01
  pinMode(I4, OUTPUT);
  pinMode(O2, INPUT);

  digitalWrite(I4, HIGH);
  var = digitalRead(O2);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H  Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H NO");
    Serial.println("\n\n H  ERROR ");
  }

  Serial.println("\n\n for 3rd gate test Logic 02 ");

  //for 3rd gate test Logic 02

  digitalWrite(I4, LOW);
  var = digitalRead(O2);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L  ERROR ");
  }


  
  if (flagG1 == 101 && flagG2 == 102)

  {
    greenTHREE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate3 is GOOD");
    Serial.println("\n\n Gate 3 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 )
  {
    redTHREE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate3 is BAD");
    Serial.println("\n\n Gate 3 is BAD");
    delay(1000);
  }

  
  Serial.println("\n\n END 3rd Gate Checking ");

  //-------------for Gate Test FOUR-------------

  flagG1 = 0;
  flagG2 = 0;
  flagR = 0;
  Serial.println("\n\n for 4th gate test Logic 01 ");
  lcd.clear();
  lcd.print("4th Gate Test");
  delay(1000);
  lcd.clear();
  
  //for 4th gate test Logic 01
  pinMode(I6, OUTPUT);
  pinMode(I5, INPUT);

  digitalWrite(I6, HIGH);
  var = digitalRead(I5);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H  Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H NO");
    Serial.println("\n\n H  ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 02 ");

  //for 2nd gate test Logic 02

  digitalWrite(I6, LOW);
  var = digitalRead(I5);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L  ERROR ");
  }


  
  if (flagG1 == 101 && flagG2 == 102)

  {
    greenFOUR();
    delay(2000);
    lcd.clear();
    lcd.print("Gate4 is GOOD");
    Serial.println("\n\n Gate 4 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 )
  {
    redFOUR();
    delay(3000);
    lcd.clear();
    lcd.print("Gate4 is BAD");
    Serial.println("\n\n Gate 4 is BAD");
    delay(1000);
  }

  

  Serial.println("\n\n END 4th Gate Checking ");
  
 //-------------End of  Gate Test FOUR-------------

 //-------------for Gate Test FIVE-------------

  flagG1 = 0;
  flagG2 = 0;
  flagR = 0;
  Serial.println("\n\n for 5th gate test Logic 01 ");
  lcd.clear();
  lcd.print("5th Gate Test");
  delay(1000);
  lcd.clear();
  
  //for 4th gate test Logic 01
  pinMode(I7, OUTPUT);
  pinMode(O3, INPUT);

  digitalWrite(I7, HIGH);
  var = digitalRead(O3);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H  Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H NO");
    Serial.println("\n\n H  ERROR ");
  }

  Serial.println("\n\n for 5th gate test Logic 02 ");

  //for 5th gate test Logic 02

  digitalWrite(I7, LOW);
  var = digitalRead(O3);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L  ERROR ");
  }


  
  if (flagG1 == 101 && flagG2 == 102)

  {
    greenFIVE();
    delay(2000);
    lcd.clear();
    lcd.print("Gate5 is GOOD");
    Serial.println("\n\n Gate 5 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 )
  {
    redFIVE();
    delay(3000);
    lcd.clear();
    lcd.print("Gate5 is BAD");
    Serial.println("\n\n Gate 5 is BAD");
    delay(1000);
  }

  

  Serial.println("\n\n END 5th Gate Checking ");
 
 //-------------End of  Gate Test FIVE-------------
 

  flagG1 = 0;
  flagG2 = 0;
  flagR = 0;
  Serial.println("\n\n for 6th gate test Logic 01 ");
  lcd.clear();
  lcd.print("6th Gate Test");
  delay(1000);
  lcd.clear();
  
  //for 6th gate test Logic 01
  pinMode(O4, OUTPUT);
  pinMode(I8, INPUT);

  digitalWrite(O4, HIGH);
  var = digitalRead(I8);
  if (var == LOW)
  {
    flagG1 = 101;
    lcd.print("H OK");
    Serial.println("\n\n LOGIC H  Is OK ");
  }
  else
  {
    flagR = 101;
    lcd.print("H NO");
    Serial.println("\n\n H  ERROR ");
  }

  Serial.println("\n\n for 4th gate test Logic 02 ");

  //for 6th gate test Logic 02

  digitalWrite(O4, LOW);
  var = digitalRead(I8);
  if (var == HIGH)
  {
    flagG2 = 102;
    lcd.setCursor(7, 0);
    lcd.print("L OK");
    Serial.println("\n\n LOGIC L  Is OK ");
  }
  else
  {
    flagR = 102;
    lcd.setCursor(7, 0);
    lcd.print("L NO");
    Serial.println("\n\n L  ERROR ");
  }


  
  if (flagG1 == 101 && flagG2 == 102)

  {
    greenSIX();
    delay(2000);
    lcd.clear();
    lcd.print("Gate6 is GOOD");
    Serial.println("\n\n Gate 6 is GOOD");
    delay(1000);
  }

  if (flagR == 101 || flagR == 102 )
  {
    redSIX();
    delay(3000);
    lcd.clear();
    lcd.print("Gate6 is BAD");
    Serial.println("\n\n Gate 6 is BAD");
    delay(1000);
  }

  

  Serial.println("\n\n END 6th Gate Checking ");

   //-------------End of  Gate Test SIX-------------


  clearALLled();

  flagG1 = 0;
  flagG2 = 0;
  flagG3 = 0;
  flagG4 = 0;
  flagR = 0;
  delay(500);
  lcd.clear();

}


//-----------Helping Code ----------

void greenONE()
{
  digitalWrite(outONEgreen, HIGH);
  Serial.println("outONEgreen HIGH ");
}

void greenTWO()
{

  digitalWrite(outTWOgreen, HIGH);
  Serial.println("outTWOgreen HIGH ");
}

void greenTHREE()
{
  digitalWrite(outTHREEgreen, HIGH);
  Serial.println("outTHREEgreen HIGH ");
}

void greenFOUR()
{
  digitalWrite(outFOURgreen, HIGH);
  Serial.println("outFOURgreen HIGH ");

}

void greenFIVE()
{
  digitalWrite(outFIVEgreen, HIGH);
  Serial.println("outFIVEgreen HIGH ");

}

void greenSIX()
{
  digitalWrite(outSIXgreen, HIGH);
  Serial.println("outSIXgreen HIGH ");

}

// for red allert


void redONE()
{
  digitalWrite(outONEred, HIGH);
  Serial.println("outONEred HIGH ");

}

void redTWO()
{
  digitalWrite(outTWOred, HIGH);
  Serial.println("outTWOred HIGH ");
}

void redTHREE()
{
  digitalWrite(outTHREEred, HIGH);
  Serial.println("outTHREEred HIGH ");
}

void redFOUR()
{
  digitalWrite(outFOURred, HIGH);
  Serial.println("outFOURred HIGH ");
}

void redFIVE()
{
  digitalWrite(outFIVEred, HIGH);
  Serial.println("outFIVEred HIGH ");
}

void redSIX()
{
  digitalWrite(outSIXred, HIGH);
  Serial.println("outSIXred HIGH ");
}


void clearALLled()
{

  digitalWrite(outONEgreen, LOW);
  digitalWrite(outTWOgreen, LOW);
  digitalWrite(outTHREEgreen, LOW);
  digitalWrite(outFOURgreen, LOW);
  digitalWrite(outONEred, LOW);
  digitalWrite(outTWOred, LOW);
  digitalWrite(outTHREEred, LOW);
  digitalWrite(outFOURred, LOW);

}
