/*
 ************************************************************************************
 이 예제는 Arduino-IRremote 을 기반으로 만들었습니다. https://github.com/Arduino-IRremote/Arduino-IRremote.
 ************************************************************************************
 */
#include <Arduino.h>                // 아두이노의 기본적인 기능을 담은 표준 라이브러리입니다.
#include "PinDefinitionsAndMore.h"  // 컴퓨터에 연결된 아두이노에 따라 입력받을 Data핀을 결정하는 라이브러리 입니다
#include <IRremote.hpp>             // 적외선 센서 기능을 담은 사용자 라이브러리입니다.

#define DECODE_NEC                  // 적외선센서 프로토콜로 NEC로 사용할 것을 정의하는 코드입니다.

void setup() {
  // 여기에 코드를 입력하면 한 번만 실행합니다.

  Serial.begin(115200);                                         //적외선 센서의 데이터를 확인하기 위해 컴퓨터와 115200 보드레이트로 시리얼 통신 시작합니다.
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);        // 적외선 센서를 통해 신호가 들어오면 기본으로 달려있는 LED에 불빛이 들어오게합니다.
  
  //시리얼 모니터에 프로토콜 정보와 함께 적외선센터 데이터핀을 연결할 아두이노 우노의 핀 정보를 출력합니다. 
  Serial.print(F("\n수신이 가능한 적외선 신호 프로토콜: "));     
  printActiveIRProtocols(&Serial);                             
  Serial.println(F("\n적외선 데이터핀을 아두이노 우노" STR(IR_RECEIVE_PIN)"번에 연결하세요"));  
}


void loop() {
  //여기는 전원이 켜져 있는 동안 반복실행합니다.

  if (IrReceiver.decode()) {
    
    Serial.println(IrReceiver.decodedIRData.command, HEX); //적외선 센서의 값을 16진수 형식으로 시리얼모니터에 보여줍니다.

    IrReceiver.resume();  // 적외선 센서 값을 연속으로 받도록 합니다.

    }
}
