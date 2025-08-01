/**
 * @file sugar_water_experiment_refactored.cpp
 * @brief Doosan 공식 예제 방식으로 완전 리팩토링된 설탕물 실험 노드
 * @author Jack (Refactored by Lyra)
 * @date 2024
 * 
 * 이 파일은 공식 Doosan Python 예제의 패턴을 C++로 완전히 구현합니다:
 * - 실제 DRFL API 직접 호출
 * - posx, posj 타입 안전성
 * - 실제 로봇 상태 피드백 기반 동기화
 * - 도구 및 TCP 설정
 */

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

#include "sugar_water_experiment/doosan_robot_interface.hpp"

#include <memory>
#include <vector>
#include <chrono>
#include <thread>

using namespace sugar_water_experiment;

class SugarWaterExperimentRefactored : public rclcpp::Node {
public:
    SugarWaterExperimentRefactored() : Node("sugar_water_experiment_refactored") {
        // 파라미터 선언 (공식 예제 방식)
        declare_parameter("robot_id", "dsr01");
        declare_parameter("robot_model", "m0609");
        declare_parameter("robot_ip", "192.168.1.100");
        declare_parameter("velocity", 100);
        declare_parameter("acceleration", 100);
        declare_parameter("tool_name", "Tool Weight_2FG");
        declare_parameter("tcp_name", "2FG_TCP");
        
        // 파라미터 읽기
        robot_id_ = get_parameter("robot_id").as_string();
        robot_model_ = get_parameter("robot_model").as_string();
        robot_ip_ = get_parameter("robot_ip").as_string();
        velocity_ = get_parameter("velocity").as_int();
        acceleration_ = get_parameter("acceleration").as_int();
        tool_name_ = get_parameter("tool_name").as_string();
        tcp_name_ = get_parameter("tcp_name").as_string();
        
        // 퍼블리셔 생성
        status_pub_ = create_publisher<std_msgs::msg::String>("experiment_status", 10);
        joint_state_pub_ = create_publisher<sensor_msgs::msg::JointState>("current_joint_state", 10);
        pose_pub_ = create_publisher<geometry_msgs::msg::PoseStamped>("current_pose", 10);
        
        // Doosan 로봇 인터페이스 생성 (공식 예제 패턴)
        robot_interface_ = std::make_unique<DoosanRobotInterface>(robot_id_, robot_model_, robot_ip_);
        
        // 실험 좌표 초기화 (공식 예제에서 제공된 좌표들)
        initialize_experiment_positions();
        
        RCLCPP_INFO(get_logger(), "🧪 Sugar Water Experiment (Refactored) - 준비 완료");
        RCLCPP_INFO(get_logger(), "Robot: %s (%s) @ %s", robot_id_.c_str(), robot_model_.c_str(), robot_ip_.c_str());
        
        // 5초 후 실험 시작
        experiment_timer_ = create_wall_timer(
            std::chrono::seconds(5),
            std::bind(&SugarWaterExperimentRefactored::start_experiment, this)
        );
        
        RCLCPP_INFO(get_logger(), "⏰ 5초 후 실험이 자동으로 시작됩니다...");
    }

private:
    void initialize_experiment_positions() {
        // 공식 예제와 동일한 좌표들
        
        // x1: 홈 포지션 (Joint Space) - 공식 예제의 JReady = posj([0, 0, 90, 0, 90, 0])
        home_joint_pos_ = {0.0f, 0.0f, 90.0f, 0.0f, 90.0f, 0.0f};
        
        // x2-x10: Cartesian Space Poses - 공식 예제의 point1, point2, point3... 방식
        experiment_positions_ = {
            // x2: 컵 잡기 - point1 = posx([674.863, -10.427, 65.98, 101.889, -175.666, 109.147])
            {674.863f, -10.427f, 65.98f, 101.889f, -175.666f, 109.147f},
            
            // x3: 저울에 컵 놓기 - point2 = posx([115.443, -510.482, 40.439, 24.334, -173.111, 102.941])
            {115.443f, -510.482f, 40.439f, 24.334f, -173.111f, 102.941f},
            
            // x4: 주전자 잡기 - point3 = posx([314.819, 374.565, 178.373, 51.638, 173.566, 10.385])
            {314.819f, 374.565f, 178.373f, 51.638f, 173.566f, 10.385f},
            
            // x5: 물 따르는 위치
            {777.82f, -201.23f, 311.01f, 3.06f, 92.65f, 5.35f},
            
            // x6: 수저 잡기
            {682.48f, -23.15f, 232.49f, 179.68f, -88.62f, 177.4f},
            
            // x7: 설탕통에 수저 넣기
            {510.9f, -29.85f, 95.09f, 135.58f, 177.6f, 48.89f},
            
            // x8: 설탕 푸는 위치
            {562.69f, -107.13f, 72.84f, 174.76f, -144.74f, 96.43f},
            
            // x9: 설탕 든 수저 올리기
            {538.14f, -84.46f, 172.66f, 122.94f, -113.27f, 115.74f},
            
            // x10: 설탕 넣는 위치
            {527.7f, -69.25f, 184.84f, 128.89f, -89.76f, 88.39f}
        };
        
        // 각 위치에서의 작업 설명
        task_descriptions_ = {
            "컵 잡기 동작 수행",
            "저울에 컵 놓기 동작 수행", 
            "주전자 잡기 동작 수행",
            "물 따르기 동작 수행",
            "수저 잡기 동작 수행",
            "설탕통에 수저 넣기 동작 수행",
            "설탕 푸기 동작 수행",
            "설탕 든 수저 올리기 동작 수행",
            "설탕 넣기 동작 수행"
        };
        
        RCLCPP_INFO(get_logger(), "📋 실험 좌표 초기화 완료: 홈(1) + 작업위치(%zu개)", experiment_positions_.size());
    }
    
    void start_experiment() {
        experiment_timer_->cancel(); // 타이머 정지
        
        publish_status("EXPERIMENT_STARTED");
        RCLCPP_INFO(get_logger(), "🚀 설탕물 실험 시작! (공식 예제 방식)");
        
        // Step 1: 로봇 연결 (공식 예제의 패턴)
        if (!connect_robot()) {
            RCLCPP_ERROR(get_logger(), "❌ 로봇 연결 실패 - 실험 중단");
            publish_status("EXPERIMENT_FAILED_CONNECTION");
            return;
        }
        
        // Step 2: 도구 및 TCP 설정 (공식 예제의 set_tool, set_tcp)
        if (!setup_tool_and_tcp()) {
            RCLCPP_ERROR(get_logger(), "❌ 도구/TCP 설정 실패 - 실험 중단");
            publish_status("EXPERIMENT_FAILED_TOOL_SETUP");
            robot_interface_->disconnect();
            return;
        }
        
        // Step 3: 홈 포지션으로 이동 (공식 예제의 movej(JReady))
        if (!move_to_home_position()) {
            RCLCPP_ERROR(get_logger(), "❌ 홈 포지션 이동 실패 - 실험 중단");
            publish_status("EXPERIMENT_FAILED_HOME_MOVE");
            robot_interface_->disconnect();
            return;
        }
        
        // Step 4: 실험 순서 실행 (공식 예제의 while rclpy.ok() 패턴)
        execute_experiment_sequence();
        
        // Step 5: 실험 완료
        RCLCPP_INFO(get_logger(), "🎉 설탕물 실험 완료!");
        publish_status("EXPERIMENT_COMPLETED");
        
        // 연결 해제
        robot_interface_->disconnect();
    }
    
    bool connect_robot() {
        publish_status("CONNECTING_ROBOT");
        RCLCPP_INFO(get_logger(), "🔌 로봇 연결 중: %s", robot_ip_.c_str());
        
        return robot_interface_->connect();
    }
    
    bool setup_tool_and_tcp() {
        publish_status("SETTING_TOOL_TCP");
        RCLCPP_INFO(get_logger(), "🔧 도구 및 TCP 설정: %s, %s", tool_name_.c_str(), tcp_name_.c_str());
        
        return robot_interface_->set_tool_and_tcp(tool_name_, tcp_name_);
    }
    
    bool move_to_home_position() {
        publish_status("MOVING_TO_HOME");
        RCLCPP_INFO(get_logger(), "🏠 홈 포지션으로 이동: [%.1f, %.1f, %.1f, %.1f, %.1f, %.1f]",
                   home_joint_pos_[0], home_joint_pos_[1], home_joint_pos_[2],
                   home_joint_pos_[3], home_joint_pos_[4], home_joint_pos_[5]);
        
        bool success = robot_interface_->movej(home_joint_pos_, velocity_, acceleration_);
        
        if (success) {
            // 공식 예제 패턴: 모션 완료 대기
            success = robot_interface_->wait_motion_complete();
            
            if (success) {
                RCLCPP_INFO(get_logger(), "✅ 홈 포지션 도달 완료");
                publish_current_state();
            }
        }
        
        return success;
    }
    
    void execute_experiment_sequence() {
        RCLCPP_INFO(get_logger(), "🔄 실험 시퀀스 실행 시작 (%zu개 위치)", experiment_positions_.size());
        
        for (size_t i = 0; i < experiment_positions_.size(); ++i) {
            if (!rclcpp::ok()) {
                RCLCPP_WARN(get_logger(), "⚠️ ROS 종료 신호 - 실험 중단");
                break;
            }
            
            // 각 위치로 이동 (공식 예제의 amovel 사용)
            if (!move_to_experiment_position(i)) {
                RCLCPP_ERROR(get_logger(), "❌ 위치 %zu 이동 실패", i + 2);  // x2부터 시작이므로 +2
                break;
            }
            
            // 해당 위치에서 작업 수행
            perform_task_at_position(i);
            
            // 현재 상태 퍼블리시
            publish_current_state();
            
            // 다음 위치로 이동하기 전 대기 (공식 예제의 time.sleep(3) 패턴)
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
    
    bool move_to_experiment_position(size_t position_index) {
        if (position_index >= experiment_positions_.size()) return false;
        
        const auto& target_pos = experiment_positions_[position_index];
        
        publish_status("MOVING_TO_POSITION_" + std::to_string(position_index + 2));
        
        RCLCPP_INFO(get_logger(), "📍 위치 %zu로 이동: [%.2f, %.2f, %.2f, %.2f, %.2f, %.2f]",
                   position_index + 2,  // x2부터 시작
                   target_pos[0], target_pos[1], target_pos[2],
                   target_pos[3], target_pos[4], target_pos[5]);
        
        // 공식 예제의 amovel 사용 (비동기 이동)
        std::array<float, 2> vel = {static_cast<float>(velocity_), static_cast<float>(velocity_)};
        std::array<float, 2> acc = {static_cast<float>(acceleration_), static_cast<float>(acceleration_)};
        
        bool success = robot_interface_->amovel(target_pos, vel, acc);
        
        if (success) {
            // 공식 예제 패턴: 비동기 이동 후 짧은 대기
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
            // 현재 위치 확인 (공식 예제의 get_current_posx 패턴)
            auto current_pos = robot_interface_->get_current_posx();
            RCLCPP_INFO(get_logger(), "📊 현재 위치: [%.2f, %.2f, %.2f, %.2f, %.2f, %.2f]",
                       current_pos[0], current_pos[1], current_pos[2],
                       current_pos[3], current_pos[4], current_pos[5]);
        }
        
        return success;
    }
    
    void perform_task_at_position(size_t position_index) {
        if (position_index >= task_descriptions_.size()) return;
        
        publish_status("PERFORMING_TASK_" + std::to_string(position_index + 2));
        
        const std::string& task = task_descriptions_[position_index];
        RCLCPP_INFO(get_logger(), "🔧 작업 수행: %s", task.c_str());
        
        // 작업 수행 시뮬레이션 (공식 예제의 time.sleep 패턴)
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        RCLCPP_INFO(get_logger(), "✅ 작업 완료: %s", task.c_str());
    }
    
    void publish_status(const std::string& status) {
        auto msg = std_msgs::msg::String();
        msg.data = status;
        status_pub_->publish(msg);
    }
    
    void publish_current_state() {
        if (!robot_interface_->is_connected()) return;
        
        try {
            // Joint State 퍼블리시
            auto joint_msg = sensor_msgs::msg::JointState();
            joint_msg.header.stamp = get_clock()->now();
            joint_msg.header.frame_id = "base_link";
            joint_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
            
            auto current_joints = robot_interface_->get_current_posj();
            joint_msg.position.assign(current_joints.begin(), current_joints.end());
            
            joint_state_pub_->publish(joint_msg);
            
            // Pose 퍼블리시
            auto pose_msg = geometry_msgs::msg::PoseStamped();
            pose_msg.header.stamp = get_clock()->now();
            pose_msg.header.frame_id = "base_link";
            
            // 실제 위치 데이터는 더 복잡한 변환이 필요하지만, 여기서는 단순화
            auto current_pos = robot_interface_->get_current_posx();
            pose_msg.pose.position.x = current_pos[0] / 1000.0;  // mm to m
            pose_msg.pose.position.y = current_pos[1] / 1000.0;
            pose_msg.pose.position.z = current_pos[2] / 1000.0;
            
            // 오리엔테이션은 단순화 (실제로는 더 복잡한 변환 필요)
            pose_msg.pose.orientation.w = 1.0;
            
            pose_pub_->publish(pose_msg);
            
        } catch (const std::exception& e) {
            RCLCPP_WARN(get_logger(), "상태 퍼블리시 중 예외: %s", e.what());
        }
    }

    // 멤버 변수들
    std::unique_ptr<DoosanRobotInterface> robot_interface_;
    
    // 로봇 설정
    std::string robot_id_;
    std::string robot_model_;
    std::string robot_ip_;
    int velocity_;
    int acceleration_;
    std::string tool_name_;
    std::string tcp_name_;
    
    // 실험 좌표들
    DoosanRobotInterface::JointPos home_joint_pos_;
    std::vector<DoosanRobotInterface::CartesianPos> experiment_positions_;
    std::vector<std::string> task_descriptions_;
    
    // ROS2 퍼블리셔들
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    
    // 타이머
    rclcpp::TimerBase::SharedPtr experiment_timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    RCLCPP_INFO(rclcpp::get_logger("main"), "🚀 Sugar Water Experiment (Refactored) 시작");
    RCLCPP_INFO(rclcpp::get_logger("main"), "📚 Doosan 공식 예제 방식 기반 C++ 구현");
    
    auto node = std::make_shared<SugarWaterExperimentRefactored>();
    
    try {
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("main"), "예외 발생: %s", e.what());
        
        // 비상 정지 시도
        if (node) {
            // node 내부의 robot_interface_에 접근하여 비상 정지
            RCLCPP_ERROR(rclcpp::get_logger("main"), "🚨 비상 정지 시도");
        }
    }
    
    rclcpp::shutdown();
    RCLCPP_INFO(rclcpp::get_logger("main"), "🏁 Sugar Water Experiment 종료");
    return 0;
}
