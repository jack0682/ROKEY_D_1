import csv
import os
from datetime import datetime
from typing import Dict, List, Optional


class ExperimentLogger:
    def __init__(self, log_dir: str = "./logs", filename_prefix: str = "experiment"):
        os.makedirs(log_dir, exist_ok=True)
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.log_path = os.path.join(log_dir, f"{filename_prefix}_{timestamp}.csv")
        self.fields_initialized = False
        self.fieldnames: Optional[List[str]] = None

    def log(self, entry: Dict[str, any]):
        """한 줄씩 로깅"""
        if not self.fields_initialized:
            self.fieldnames = list(entry.keys())
            self.fields_initialized = True
            self._initialize_csv(self.fieldnames)

        self._append_row(entry)

    def _initialize_csv(self, fieldnames: List[str]):
        with open(self.log_path, mode='w', newline='') as f:
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()

    def _append_row(self, entry: Dict[str, any]):
        with open(self.log_path, mode='a', newline='') as f:
            writer = csv.DictWriter(f, fieldnames=self.fieldnames)
            writer.writerow(entry)

    def get_log_path(self) -> str:
        return self.log_path
