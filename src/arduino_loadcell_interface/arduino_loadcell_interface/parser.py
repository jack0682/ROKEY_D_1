import re


class LoadCellParser:
    """
    Parses serial strings from Arduino-based HX711 load cell firmware.
    Expected format: "W: 123.45 g" or just "123.45"
    """

    WEIGHT_PATTERN = re.compile(r"([-+]?[0-9]*\.?[0-9]+)")

    @staticmethod
    def parse_line(line: str) -> float | None:
        """
        Parses a line of serial input and extracts the weight value.

        Args:
            line (str): Serial input line from Arduino.

        Returns:
            float or None: Parsed weight in grams, or None if parsing failed.
        """
        if not line:
            return None

        try:
            # Strip control characters and whitespaces
            clean_line = line.strip()

            # Try to find a floating-point number in the line
            match = LoadCellParser.WEIGHT_PATTERN.search(clean_line)
            if match:
                return float(match.group(1))
        except Exception as e:
            # Silently handle unexpected cases
            pass

        return None


# Example test
if __name__ == "__main__":
    test_lines = [
        "W: 123.45 g",
        "123.45",
        "Weight=456.78g",
        "W:-12.3",
        "Noise data.... W: 78.9g",
        "",
        "Error",
    ]

    for line in test_lines:
        weight = LoadCellParser.parse_line(line)
        print(f"Input: '{line}' => Parsed: {weight}")
