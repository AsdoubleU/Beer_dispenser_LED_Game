


int led[] = {2, 3, 4, 5}; //2,3,4,5번 핀을 배열을 이용하여 led 핀으로 지정.

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT); //led[1],led[2],led[3],led[4]를 핀모드로 아웃풋으로 지정. 
  }
  pinMode(7, INPUT); //7번 핀(버튼)을 인풋으로 지정.
  randomSeed(analogRead(A0)); //랜덤 함수의 시드값을 지정 시드값을 아날로그 핀인 A0를 쓰며, 플로팅 현상이 일어나므로, 그 값을 실시간으로 계속 바뀜 
  Serial.begin(9600); //시리얼 지정. 9600의 속도로 데이터를 컴퓨터에 있는 시리얼 모니터로 뿌려줄 것임.
}

void loop() {

  int num = random(4); //num이라는 변수를 0부터 3까지의 시드값에 기반한 랜덤 값으로 지정 이 (num) 번째 led에 불을 맞춰서 눌러야 함.
  int count = 0; // count라는 변수를 0으로 선언. led가 켜질 때, 이 불빛이 몇번째 led인지 이 변수에 저장할 예정.

  digitalWrite(led[num], HIGH); //위에서 랜덤으로 지정한 (num)번째(아까 랜덤으로 뽑힌 값)을 켜줌.

  while (digitalRead(7) == LOW) { //버튼이 눌리는 순간까지 중괄호 안의 내용을 반복 
    for (int i = 0; i < 4; i++) { //for 문으로, 0번부터 3번 led를 계속 켜주고, 0.초뒤에 끔 
      digitalWrite(led[i], HIGH);
      delay(100);
      if (i != num) { //위에서 나온 랜덤한 불빛이 아니라면, 끄고 맞다면 끄지 않음.
        digitalWrite(led[i], LOW);
      }
      delay(100);
      count = i; //count에 지금 몇 번째 led를 켜고 끄고 있는지 저장.
    }
  }

  digitalWrite(led[count],HIGH); //버튼을 누른 순간에 켜져있던 led를 계속 켜둠.
  if(count == num){
    Serial.println("succed!"); //버튼 누른 순간에 켜진 led가 랜덤하게 켜진 led와 같다면 성공, 아니라면 실패 
  }
  else{
    Serial.println("failed!");
  }
  delay(5000);
}
