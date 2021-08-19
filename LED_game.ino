


int led[] = {2, 3, 4, 5};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(7, INPUT);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void loop() {

  int num = random(4);
  int count = 0;

  digitalWrite(led[num], HIGH);

  while (digitalRead(7) == LOW) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(led[i], HIGH);
      delay(100);
      if (i != num) {
        digitalWrite(led[i], LOW);
      }
      delay(100);
      count = i;
    }
  }

  digitalWrite(led[count],HIGH);
  if(count == num){
    Serial.println("succed!");
  }
  else{
    Serial.println("failed!");
  }
  delay(5000);
}
