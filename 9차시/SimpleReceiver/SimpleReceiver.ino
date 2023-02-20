/*
 ************************************************************************************
 이 예제는 Arduino-IRremote 을 기반으로 만들었습니다. https://github.com/Arduino-IRremote/Arduino-IRremote.
 ************************************************************************************
 */

// 적외선센서 프로토콜로 NEC로 사용할 것을 정의하는 코드입니다.
#define DECODE_NEC

#include <Arduino.h>  // 아두이노의 기본적이 기능을 담은 표준 라이브러리입니다.
#include "PinDefinitionsAndMore.h"  // 컴퓨터에 연결된 아두이노에 따라 입력받을 Data핀을 결정하는 라이브러리 입니다
#include <IRremote.hpp>  // 적외선 센서 기능을 담은 사용자 라이브러리입니다.

void setup() {
  // 여기에 코드를 입력하면 한 번만 실행합니다.

  Serial.begin(115200);                                   //적외선 센서의 데이터를 확인하기 위해 컴퓨터와 115200 보드레이트로 시리얼 통신 시작합니다.
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // 적외선 센서를 통해 신호가 들어오면 기본으로 달려있는 LED에 불빛이 들어오게합니다.

  Serial.print(F("수신이 가능한 적외선 신호 프로토콜: "));     //시리얼 모니터에 프로토콜 안내문구를 출력합니다.
  printActiveIRProtocols(&Serial);                             //시리얼 모니터에 프로토콜 정보를 출력합니다.
  Serial.println(F("\nData pin번호는 " STR(IR_RECEIVE_PIN)));  //시리얼 모니터에 연결된 적외선 Data 핀 번호를 출력합니다.


void loop() {
  //여기는 전원이 켜져 있는 동안 반복실행합니다.

  /*
     * 적외선 데이터를 받게되면 신호를 디코딩합니다. 디코딩되는 결과는 아래의 정보를 담고 있습니다.
     * command는 디코딩 된 적외선 센서의 명령어에 사용될 데이터입니다.
     * address는 디코딩된 적외선 센서의 주소입니다.
     * raw data는 디코딩된 적외선 센서에서 가공되지 않은 데이터입니다.
     */
  if (IrReceiver.decode()) {

    //IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);  // 적외선 데이터를 사용될 수 있도록 만들어 줍니다.
    // 만약 디코딩된 프로토콜이 정의되지 않는 경우 시리얼 모니터에 표시합니다.
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      // We have an unknown protocol here, print more info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    Serial.println();

    IrReceiver.resume();  // 적외선 센서 값을 계속 받기위한 코드입니다.

    /*
         * 수신된 적외선 데이터에서 command 값이 일치하면 동작하도록 하는 조건문입니다.
        */
    if (IrReceiver.decodedIRData.command == 0x10) {
      // 적외선센서의 command 값이 0x10과 일치하면 실행되는 코드입니다.
    } else if (IrReceiver.decodedIRData.command == 0x11) {
      // 적외선센서의 command 값이 0x11과 일치하면 실행되는 코드입니다.
    }
  }
}
