import csv
import os
from datetime import datetime
from typing import Dict, List, Optional
from pathlib import Path


class ExperimentLogger:
    """Enhanced experiment logger with better error handling and functionality"""
    
    def __init__(self, log_dir: str = "./logs", filename_prefix: str = "experiment"):
        # Ensure log directory exists
        self.log_dir = Path(log_dir)
        self.log_dir.mkdir(parents=True, exist_ok=True)
        
        # Generate timestamped filename
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.log_path = self.log_dir / f"{filename_prefix}_{timestamp}.csv"
        
        self.fields_initialized = False
        self.fieldnames: Optional[List[str]] = None
        self.entry_count = 0
        
        print(f"📝 Logger initialized: {self.log_path}")

    def log(self, entry: Dict[str, any]):
        """Log a single entry to CSV file"""
        try:
            if not self.fields_initialized:
                self.fieldnames = list(entry.keys())
                self.fields_initialized = True
                self._initialize_csv(self.fieldnames)
                print(f"📊 CSV initialized with fields: {self.fieldnames}")

            self._append_row(entry)
            self.entry_count += 1
            
            if self.entry_count % 5 == 0:  # Progress indicator every 5 entries
                print(f"📝 Logged {self.entry_count} entries...")
                
        except Exception as e:
            print(f"❌ Logging error: {e}")

    def _initialize_csv(self, fieldnames: List[str]):
        """Initialize CSV file with headers"""
        with open(self.log_path, mode='w', newline='', encoding='utf-8') as f:
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()

    def _append_row(self, entry: Dict[str, any]):
        """Append a single row to CSV file"""
        with open(self.log_path, mode='a', newline='', encoding='utf-8') as f:
            writer = csv.DictWriter(f, fieldnames=self.fieldnames)
            writer.writerow(entry)

    def get_log_path(self) -> str:
        """Get the full path to the log file"""
        return str(self.log_path)
    
    def get_entry_count(self) -> int:
        """Get the number of entries logged so far"""
        return self.entry_count
    
    def log_summary(self, summary: Dict[str, any]):
        """Log a summary entry with special formatting"""
        summary_entry = {
            'entry_type': 'SUMMARY',
            'timestamp': datetime.now().isoformat(),
            **summary
        }
        self.log(summary_entry)
        print(f"📋 Summary logged: {summary}")
    
    def finalize(self):
        """Finalize logging and print summary"""
        print(f"✅ Logging completed: {self.entry_count} entries saved to {self.log_path}")
        
        # Log file size
        try:
            file_size = self.log_path.stat().st_size
            print(f"📁 Log file size: {file_size} bytes")
        except:
            pass


def main():
    """Test the ExperimentLogger"""
    print("🧪 Testing ExperimentLogger")
    print("=" * 30)
    
    logger = ExperimentLogger(log_dir="./test_logs", filename_prefix="test_experiment")
    
    # Test logging various entries
    test_entries = [
        {
            "trial": 1,
            "target_concentration": 3.0,
            "actual_concentration": 2.95,
            "final_volume_ml": 100.2,
            "salt_weight_g": 3.0,
            "timestamp": datetime.now().isoformat()
        },
        {
            "trial": 2,
            "target_concentration": 3.0,
            "actual_concentration": 3.02,
            "final_volume_ml": 99.8,
            "salt_weight_g": 3.0,
            "timestamp": datetime.now().isoformat()
        },
        {
            "trial": 3,
            "target_concentration": 5.0,
            "actual_concentration": 4.98,
            "final_volume_ml": 60.1,
            "salt_weight_g": 3.0,
            "timestamp": datetime.now().isoformat()
        }
    ]
    
    print("Logging test entries...")
    for entry in test_entries:
        logger.log(entry)
        print(f"   Logged trial {entry['trial']}: {entry['actual_concentration']:.2f}%")
    
    # Log a summary
    summary = {
        "total_trials": len(test_entries),
        "average_accuracy": sum(abs(e['actual_concentration'] - e['target_concentration']) 
                               for e in test_entries) / len(test_entries),
        "experiment_duration": "5.2 minutes"
    }
    logger.log_summary(summary)
    
    # Finalize
    logger.finalize()
    
    print(f"\n✅ Test completed. Check log file: {logger.get_log_path()}")


if __name__ == "__main__":
    main()
