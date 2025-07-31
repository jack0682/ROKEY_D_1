import pandas as pd
import matplotlib.pyplot as plt
import os


class ResultAnalyzer:
    def __init__(self, csv_path: str):
        if not os.path.isfile(csv_path):
            raise FileNotFoundError(f"Result CSV file not found: {csv_path}")
        self.csv_path = csv_path
        self.df = pd.read_csv(csv_path)

    def summary_statistics(self):
        """
        농도, 소금 무게, 물 무게에 대한 평균, 표준편차 등을 출력합니다.
        """
        print(f"📊 [Summary] {os.path.basename(self.csv_path)}")
        print(self.df.describe())

    def plot_concentration_over_time(self, save_path: str = None):
        """
        시간 순으로 농도 변화 시각화
        """
        if 'concentration_percent' not in self.df.columns:
            print("❌ 'concentration_percent' column not found.")
            return

        plt.figure(figsize=(10, 5))
        plt.plot(self.df.index, self.df['concentration_percent'], marker='o')
        plt.title("Salt Concentration Over Time")
        plt.xlabel("Sample Index")
        plt.ylabel("Concentration (%)")
        plt.grid(True)

        if save_path:
            plt.savefig(save_path)
            print(f"📈 농도 그래프 저장됨: {save_path}")
        else:
            plt.show()

    def concentration_error_analysis(self, target_concentration: float):
        """
        각 샘플이 목표 농도로부터 얼마나 오차가 있는지 분석
        """
        if 'concentration_percent' not in self.df.columns:
            print("❌ 'concentration_percent' column not found.")
            return

        self.df['error'] = self.df['concentration_percent'] - target_concentration
        mean_error = self.df['error'].mean()
        std_error = self.df['error'].std()
        print(f"🎯 목표 농도: {target_concentration:.2f}%")
        print(f"📉 평균 오차: {mean_error:.4f}%")
        print(f"📈 오차 표준편차: {std_error:.4f}%")
        return self.df[['concentration_percent', 'error']]


if __name__ == "__main__":
    # 테스트 실행 예시
    analyzer = ResultAnalyzer("logs/salinity_test_20250731_153055.csv")
    analyzer.summary_statistics()
    analyzer.concentration_error_analysis(target_concentration=2.5)
    analyzer.plot_concentration_over_time()
