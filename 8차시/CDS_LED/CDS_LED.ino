void setup()
{
    // 여기에 코드를 입력하면 한 번만 실행합니다.
    pinMode(A0, INPUT);     // 조도센서의 입출력 설정, 밝기를 전달하는 역할
    Serial.begin(9600);     // 조도센서의 밝기를 출력하기 위해 컴퓨터와 9600 보드레이트로 시리얼 통신 시작 
    pinMode(3, INPUT);
}

void loop()
{
    // 여기는 전원이 켜져있는 동안 무한대로 실행합니다.
    int value = analogRead(A0);                 // value라는 int 정수형 변수 생성, 조도센서와 연결된 A0번 핀의 밝기 값 저장
    Serial.println(value);                      // 시리얼 통신으로 밝기값 송신 
    int bright = map(value, 0, 1023, 0, 255);   // 밝기값에 따라 LED를 출력하기 위해 정수형 변수 bright에 변환된 값 저장
    // 밝기값은 아날로그 입력이기 때문에 0~1023의 값을 가짐. PWM으로 출력할 수 있는 값은 0~255이기 때문에 
    // map 함수를 이용해 값의 범위를 수정, bright에 저장
    // 문법 : map(변환할 값, 현재 최소값, 현재 최대값, 바꿀 최소값, 바꿀 최대값);
    analogWrite(3, bright);                     // 3번핀에 있는 LED를 변환한 밝기 값만큼 PWM으로 출력
}