import serial
import threading
import time
from typing import Optional, Callable


class LoadCellSerialInterface:
    """
    Interface for reading weight data from Arduino over serial (HX711).
    """

    def __init__(
        self,
        port: str = "/dev/ttyUSB0",
        baudrate: int = 38400,
        timeout: float = 1.0,
        read_interval: float = 0.1,
        on_weight_callback: Optional[Callable[[float], None]] = None
    ):
        self.port = port
        self.baudrate = baudrate
        self.timeout = timeout
        self.read_interval = read_interval
        self.on_weight_callback = on_weight_callback

        self._serial = None
        self._thread = None
        self._running = False
        self.last_weight: Optional[float] = None

    def start(self):
        try:
            self._serial = serial.Serial(self.port, self.baudrate, timeout=self.timeout)
            self._running = True
            self._thread = threading.Thread(target=self._read_loop, daemon=True)
            self._thread.start()
            print(f"[LoadCellSerialInterface] Started reading from {self.port}")
        except serial.SerialException as e:
            raise RuntimeError(f"Failed to open serial port {self.port}: {e}")

    def stop(self):
        self._running = False
        if self._thread:
            self._thread.join()
        if self._serial and self._serial.is_open:
            self._serial.close()
        print("[LoadCellSerialInterface] Stopped")

    def _read_loop(self):
        while self._running:
            try:
                line = self._serial.readline().decode("utf-8").strip()
                if line.startswith("Weight(g):"):
                    weight = self._parse_weight(line)
                    if weight is not None:
                        self.last_weight = weight
                        if self.on_weight_callback:
                            self.on_weight_callback(weight)
            except Exception as e:
                print(f"[LoadCellSerialInterface] Error reading: {e}")
            time.sleep(self.read_interval)

    def _parse_weight(self, line: str) -> Optional[float]:
        try:
            # Expected format: "Weight(g):  123.45"
            return float(line.split(":")[1].strip())
        except Exception:
            return None

    def get_last_weight(self) -> Optional[float]:
        return self.last_weight


def main():
    """Test function for direct execution"""
    print("Testing LoadCell Serial Interface...")
    
    def weight_callback(weight):
        print(f"Weight received: {weight:.3f}g")
    
    interface = LoadCellSerialInterface(
        port="/dev/ttyUSB0",
        baudrate=38400,
        on_weight_callback=weight_callback
    )
    
    try:
        interface.start()
        print("Interface started. Press Ctrl+C to stop...")
        while True:
            time.sleep(1)
            last_weight = interface.get_last_weight()
            if last_weight is not None:
                print(f"Last weight: {last_weight:.3f}g")
    except KeyboardInterrupt:
        print("Stopping interface...")
    finally:
        interface.stop()


if __name__ == "__main__":
    main()
