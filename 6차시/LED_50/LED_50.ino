void setup()
{											 // 한 번만 실행
	pinMode(10, OUTPUT); // 10번 핀을 출력으로 설정 (LED가 꽂힌 핀)
}

void loop()
{													// 무한대로 실행
	digitalWrite(10, HIGH); // 10번 핀을 디지털로 출력 (5v 출력)
	delay(5);								// 5ms 동안 아두이노 멈춤 (0.005초)
	digitalWrite(10, LOW);	// 10번 핀을 디지털로 출력 (0v 출력)
	delay(5);								// 5ms 동안 아두이노 멈춤 (0.005초)
}
