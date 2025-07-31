# precision_liquid_pouring/utils.py

import time
import logging


def wait_until(condition_fn, timeout=10.0, check_interval=0.1):
    """
    Wait until the condition_fn returns True or timeout is reached.
    :param condition_fn: Callable that returns True when condition is met
    :param timeout: Maximum time to wait in seconds
    :param check_interval: Interval between checks in seconds
    :return: True if condition met, False if timeout
    """
    start_time = time.time()
    while time.time() - start_time < timeout:
        if condition_fn():
            return True
        time.sleep(check_interval)
    return False


def clamp(value, min_value, max_value):
    """Clamp a value between min and max."""
    return max(min_value, min(value, max_value))


def setup_logger(name="liquid_pouring", level=logging.INFO):
    """Setup a basic logger with time and level."""
    formatter = logging.Formatter("%(asctime)s [%(levelname)s] %(message)s")
    handler = logging.StreamHandler()
    handler.setFormatter(formatter)

    logger = logging.getLogger(name)
    logger.setLevel(level)
    logger.addHandler(handler)
    logger.propagate = False
    return logger


class Timer:
    """
    Simple timer utility class for measuring durations.
    """
    def __init__(self):
        self.start_time = None

    def start(self):
        self.start_time = time.perf_counter()

    def elapsed(self):
        if self.start_time is None:
            return 0.0
        return time.perf_counter() - self.start_time
