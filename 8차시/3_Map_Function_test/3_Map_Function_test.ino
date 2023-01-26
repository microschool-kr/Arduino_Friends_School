void setup()
{  
    Serial.begin(9600);                       
    for (int i = 0; i <= 1023; i++)     // for문(반복문)을 이용해 변수 i를 0 부터 1023까지 1씩 더함
    {
        Serial.print(i);                // 변수 i 시리얼 출력 (변환 전 값)
        Serial.print("  --->  ");       // 알아보기 쉽도록 화살표 출력
        int mapping_i = map(i, 0, 1023, 0, 255);    // 변수 i를 0~255로 매핑
        Serial.println(mapping_i);      // 매핑된 변수 mapping_i를 출력후 줄바꿈
    }
}

void loop()
{
    // loop 함수가 없으면 오류납니다! 지우지 마세요!
}