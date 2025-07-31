import serial
import time
import statistics
import logging
from typing import Optional


class ScaleInterface:
    """
    HX711 기반 고정밀 로드셀 시리얼 통신 인터페이스.
    평균 필터링, 자동 재연결, 영점 보정(tare) 포함.
    """

    def __init__(self, port: str = "/dev/ttyUSB0", baudrate: int = 38400,
                 timeout: float = 1.0, samples: int = 15):
        self.port = port
        self.baudrate = baudrate
        self.timeout = timeout
        self.samples = samples
        self.ser: Optional[serial.Serial] = None
        self.tare_offset: float = 0.0

        self.logger = logging.getLogger("ScaleInterface")
        self.logger.setLevel(logging.INFO)

        self._connect()

    def _connect(self):
        try:
            self.ser = serial.Serial(self.port, self.baudrate, timeout=self.timeout)
            time.sleep(2.0)
            self.logger.info(f"[Scale] Connected to {self.port} @ {self.baudrate}bps")
        except serial.SerialException as e:
            self.logger.error(f"[Scale] Failed to connect: {e}")
            self.ser = None

    def _read_raw_value(self) -> Optional[float]:
        if not self.ser or not self.ser.is_open:
            self.logger.warning("[Scale] Serial disconnected. Reconnecting...")
            self._connect()
            return None

        try:
            line = self.ser.readline().decode("utf-8").strip()
            value = float(line)
            return value
        except (ValueError, serial.SerialException, UnicodeDecodeError) as e:
            self.logger.warning(f"[Scale] Invalid data: {e}")
            return None

    def tare(self) -> bool:
        """현재 무게를 0으로 설정 (영점 보정)"""
        self.logger.info("[Scale] Performing tare... Hold scale steady.")
        readings = []

        for _ in range(self.samples * 2):
            val = self._read_raw_value()
            if val is not None:
                readings.append(val)
            time.sleep(0.03)

        if len(readings) >= self.samples:
            self.tare_offset = statistics.median(readings)
            self.logger.info(f"[Scale] Tare offset set to {self.tare_offset:.3f}")
            return True
        else:
            self.logger.error("[Scale] Tare failed: insufficient valid data")
            return False

    def read_weight(self) -> Optional[float]:
        """보정된 무게를 g 단위로 반환. 유효하지 않으면 None."""
        values = []
        for _ in range(self.samples):
            val = self._read_raw_value()
            if val is not None:
                values.append(val)
            time.sleep(0.015)

        if not values:
            self.logger.error("[Scale] No valid data for weight reading")
            return None

        avg = statistics.mean(values)
        weight = avg - self.tare_offset
        return round(max(weight, 0.0), 4)

    def close(self):
        if self.ser and self.ser.is_open:
            self.ser.close()
            self.logger.info("[Scale] Serial connection closed")


# 테스트용 실행 코드
if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)

    scale = ScaleInterface(port="/dev/ttyUSB0", baudrate=38400, samples=15)
    scale.tare()

    try:
        while True:
            weight = scale.read_weight()
            if weight is not None:
                print(f"[READ] Weight: {weight:.4f} g")
            time.sleep(0.4)
    except KeyboardInterrupt:
        print("Interrupted. Exiting...")
    finally:
        scale.close()
