#include "HX711.h"

HX711 scale(A1, A0);

// 측정된 데이터 기반 계산:
// 빈 상태: -136270, 160g 상태: +38700
// 변화량: 174970, 캘리브레이션 팩터: 174970/160 = 1093.56
float calibration_factor = 1093.56;

void setup() {
  Serial.begin(38400);
  Serial.println("=== HX711 최종 캘리브레이션 적용 ===");
  Serial.println("측정된 데이터:");
  Serial.println("빈 상태: -136270");
  Serial.println("160g 상태: +38700");
  Serial.println("변화량: 174970");
  Serial.println("계산된 팩터: 1093.56");
  Serial.println("=====================================");
  
  // 캘리브레이션 팩터 적용
  scale.set_scale(calibration_factor);
  
  Serial.println("명령어:");
  Serial.println("t: 영점 조정 (빈 상태에서 필수!)");
  Serial.println("w: 현재 무게 확인");
  Serial.println("c: 캘리브레이션 검증 (160g으로)");
  Serial.println("+ : 팩터 미세 증가 (+10)");
  Serial.println("- : 팩터 미세 감소 (-10)");
  Serial.println("s: 최종 설정값 출력");
  Serial.println("=====================================");
  
  Serial.println("⚠️  먼저 센서를 비우고 't'를 눌러 영점 조정하세요!");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    switch (command) {
      case 't':
      case 'T':
        tare_scale();
        break;
        
      case 'w':
      case 'W':
        show_weight();
        break;
        
      case 'c':
      case 'C':
        verify_calibration();
        break;
        
      case '+':
        calibration_factor += 10;
        scale.set_scale(calibration_factor);
        Serial.print("팩터 증가: ");
        Serial.println(calibration_factor, 2);
        show_weight();
        break;
        
      case '-':
        calibration_factor -= 10;
        scale.set_scale(calibration_factor);
        Serial.print("팩터 감소: ");
        Serial.println(calibration_factor, 2);
        show_weight();
        break;
        
      case 's':
      case 'S':
        show_final_settings();
        break;
    }
  }
  
  // 1초마다 무게 자동 표시
  static unsigned long last_reading = 0;
  if (millis() - last_reading > 1000) {
    float weight = scale.get_units(5);
    Serial.print("실시간: ");
    Serial.print(-weight, 1);
    Serial.println("g");
    last_reading = millis();
  }
}

void tare_scale() {
  Serial.println("\n영점 조정 중...");
  Serial.println("센서 위가 완전히 비어있는지 확인하세요!");
  
  delay(2000);
  scale.tare();
  
  Serial.println("영점 조정 완료!");
  delay(1000);
  
  // 영점 확인
  float zero_weight = scale.get_units(10);
  Serial.print("영점 확인: ");
  Serial.print(zero_weight, 1);
  Serial.println("g");
  
  if (abs(zero_weight) < 2.0) {
    Serial.println("✅ 영점 조정 성공!");
  } else {
    Serial.println("⚠️  영점이 약간 벗어남. 다시 시도해보세요.");
  }
  Serial.println();
}

void show_weight() {
  Serial.println("\n=== 현재 무게 측정 ===");
  
  // 여러 번 측정해서 안정성 확인
  float weights[5];
  for (int i = 0; i < 5; i++) {
    weights[i] = scale.get_units(3);
    Serial.print("측정 ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(weights[i], 1);
    Serial.println("g");
    delay(500);
  }
  
  // 평균 계산
  float avg_weight = 0;
  for (int i = 0; i < 5; i++) {
    avg_weight += weights[i];
  }
  avg_weight /= 5;
  
  Serial.print(">>> 평균 무게: ");
  Serial.print(avg_weight, 1);
  Serial.println("g");
  Serial.println("========================\n");
}

void verify_calibration() {
  Serial.println("\n=== 캘리브레이션 검증 ===");
  Serial.println("정확히 160g을 센서 위에 올려주세요!");
  Serial.println("5초 후 측정 시작...");
  
  for (int i = 5; i > 0; i--) {
    Serial.print(i);
    Serial.print("... ");
    delay(1000);
  }
  Serial.println();
  
  float measured_weight = scale.get_units(20); // 20회 평균
  
  Serial.print("측정된 무게: ");
  Serial.print(measured_weight, 1);
  Serial.println("g");
  
  float error = abs(measured_weight - 160.0);
  Serial.print("오차: ");
  Serial.print(error, 1);
  Serial.println("g");
  
  if (error < 5.0) {
    Serial.println("🎉 캘리브레이션 완벽!");
  } else if (error < 10.0) {
    Serial.println("✅ 캘리브레이션 양호 (미세 조정 가능)");
  } else {
    Serial.println("⚠️  캘리브레이션 조정 필요");
    if (measured_weight > 160.0) {
      Serial.println("팩터가 너무 작음 → '+' 사용");
    } else {
      Serial.println("팩터가 너무 큼 → '-' 사용");
    }
  }
  Serial.println("=========================\n");
}

void show_final_settings() {
  Serial.println("\n=== 최종 캘리브레이션 설정 ===");
  Serial.print("캘리브레이션 팩터: ");
  Serial.println(calibration_factor, 6);
  Serial.println();
  Serial.println("최종 코드에 사용할 설정:");
  Serial.println("```cpp");
  Serial.println("#include \"HX711.h\"");
  Serial.println("HX711 scale(A1, A0);");
  Serial.println();
  Serial.println("void setup() {");
  Serial.println("  scale.set_scale(" + String(calibration_factor, 6) + ");");
  Serial.println("  scale.tare(); // 빈 상태에서 실행");
  Serial.println("}");
  Serial.println();
  Serial.println("void loop() {");
  Serial.println("  float weight = scale.get_units(10);");
  Serial.println("  Serial.print(weight, 1);");
  Serial.println("  Serial.println(\" g\");");
  Serial.println("  delay(1000);");
  Serial.println("}");
  Serial.println("```");
  Serial.println("================================\n");
}