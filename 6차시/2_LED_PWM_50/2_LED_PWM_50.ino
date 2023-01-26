void setup()
{											 // 한 번만 실행
	pinMode(10, OUTPUT); // 10번 핀을 출력으로 설정 (LED가 꽂힌 핀)
}

void loop()
{												// 무한대로 실행
	analogWrite(10, 127); // PWM을 이용해 10번 핀을 0~255 중 127 (약 50%)로 출력
}