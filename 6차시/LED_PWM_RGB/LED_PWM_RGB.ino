void setup() {  // 여기에 코드를 입력하면 한 번만 실행합니다.
    pinMode(11, OUTPUT);    //11(Red), 10(Green), 9(Blue) LED 핀 출력으로 설정
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
}

void loop() {   // 여기는 전원이 켜져있는 동안 무한대로 실행합니다. 
    //핑크색을 만들기 위해 각 색깔별로 PWM 출력
    analogWrite(11, 212);   //Red -> 212
    analogWrite(10, 76);    //Green -> 76
    analogWrite(9, 217);    //Blue -> 217
}