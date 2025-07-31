/**
 * @file weight_monitor.cpp
 * @brief 무게 센서 모니터링 클래스
 */

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <vector>
#include <numeric>

class WeightMonitor {
public:
    WeightMonitor(rclcpp::Node* node) : node_(node), buffer_index_(0), current_weight_(0.0) {
        weight_buffer_.resize(BUFFER_SIZE, 0.0);
        
        weight_sub_ = node_->create_subscription<std_msgs::msg::Float32>(
            "sensors/weight", 10,
            std::bind(&WeightMonitor::weightCallback, this, std::placeholders::_1)
        );
        
        filtered_weight_pub_ = node_->create_publisher<std_msgs::msg::Float32>("sensors/weight_filtered", 10);
    }
    
    float getCurrentWeight() const {
        return current_weight_;
    }
    
    float getFilteredWeight() {
        if (weight_buffer_.empty()) return 0.0;
        
        float sum = std::accumulate(weight_buffer_.begin(), weight_buffer_.end(), 0.0f);
        return sum / weight_buffer_.size();
    }
    
    bool isWeightStable(float threshold = 0.01) {
        if (weight_buffer_.size() < BUFFER_SIZE) return false;
        
        float mean = getFilteredWeight();
        float variance = 0.0;
        
        for (const auto& weight : weight_buffer_) {
            variance += (weight - mean) * (weight - mean);
        }
        variance /= weight_buffer_.size();
        
        return sqrt(variance) < threshold;
    }

private:
    void weightCallback(const std_msgs::msg::Float32::SharedPtr msg) {
        float raw_weight = msg->data;
        
        // 버퍼에 추가
        weight_buffer_[buffer_index_] = raw_weight;
        buffer_index_ = (buffer_index_ + 1) % BUFFER_SIZE;
        
        // 필터링된 무게 계산
        current_weight_ = getFilteredWeight();
        
        // 필터링된 무게 퍼블리시
        std_msgs::msg::Float32 filtered_msg;
        filtered_msg.data = current_weight_;
        filtered_weight_pub_->publish(filtered_msg);
    }
    
    static const size_t BUFFER_SIZE = 10;
    
    rclcpp::Node* node_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr weight_sub_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr filtered_weight_pub_;
    
    std::vector<float> weight_buffer_;
    size_t buffer_index_;
    float current_weight_;
};
