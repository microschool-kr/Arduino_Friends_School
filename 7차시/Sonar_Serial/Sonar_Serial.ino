void setup()
{
	// 여기에 코드를 입력하면 한 번만 실행합니다.
	pinMode(13, OUTPUT);	// 초음파 센서의 trigger Pin의 입출력 설정, 초음파를 송신하는 역활
	pinMode(12, INPUT);   // 초음파 센서의 echo Pin의 입출력 설정, 초음파를 수신하는 역활
	Serial.begin(9600);	  // 초음파 센서의 거리를 출력하기 위해 컴퓨터와 9600 보드레이트로 시리얼 통신 시작 
}

void loop()
{
	// 여기는 전원이 켜져있는 동안 무한대로 실행합니다.
	digitalWrite(13, LOW);  // trigger Pin을 LOW로 변환하여 송신 중지 (초기화)
	delayMicroseconds(2);   // 2 마이크로초 (1/1000000초) 동안 기다리기 
	digitalWrite(13, HIGH); // trigger Pin을 HIGH로 변환하여 초음파 송신
	delayMicroseconds(10);  // 10 마이크로초 (10/1000000초) 동안 기다리기
	digitalWrite(13, LOW);  // trigger Pin을 LOW로 변환하여 송신 중지

	long duration = pulseIn(12, HIGH); // echo Pin을 HiGH로 변환하여 반사된 초음파를 수신한다.
	// 이때 수신한 결과는 초음파를 발사하고, 반사되어 돌아온 시간 (마이크로초)
	// 수신한 시간을 거리로 변환해야 합니다. 거리 = 시간 * 속도  (초음파의 속도는 340m/s)
	// 이때 /2는 왕복한 시간이여서 편도로 변환해주는 역할, 아래는 cm단위로 변환입니다.
	long distance = ((340 * duration) / 10000) / 2;

  	Serial.println(distance); //  시리얼 통신으로 거리값 송신 
	Serial.print("cm"); //  시리얼 통신으로 'cm'라는 문장 송신
	delay(100); //  100 밀리초 (100/1000초) 동안 기다리기 
}
