int lPot = 0;
int rPot = 0;

int input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    input = Serial.read();

    if(input == 'P') potValues();
  }
  delay(20);
}

void potValues ()
{
  lPot = analogRead(A0);
  rPot = analogRead(A1);

  Serial.print(Padded(lPot));
  Serial.print(":");
  Serial.println(Padded(rPot));
}

String Padded (int inNum)
{
  char buff[5];
  char padded[6];

  sprintf(buff, "%.4u", inNum);

  padded[0] = buff[0];
  padded[1] = buff[1];
  padded[2] = buff[2];
  padded[3] = buff[3];
  padded[4] = buff[4];
  padded[5] = '\0';


  return String(padded);
}

