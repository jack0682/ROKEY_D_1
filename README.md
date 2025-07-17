# ROKEY_D_1

## Node flow chart

![flowchart](https://github.com/user-attachments/assets/122de651-6fdf-412a-ae41-e27f070b39af)

### Robot1

#### Human YOLO + Depth -> TF + Nav, Manager COM

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/human_detection` | `your_ros_pkg/msg/PersonDetection`| `x_m`        | `float64`       | m   | 맵 좌표 x              |
|                                      |                              | `y_m`        | `float64`       | m   | 맵 좌표 y   |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                    |


#### Puddle Seg -> TF + Nav, Manager COM

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/puddle_detection`| `your_ros_pkg/msg/CPDetection`| `x_m`        | `float64`       | m   | 맵 좌표 x          |
|                                      |                              | `y_m`        | `float64`       | m   | 맵 좌표 y |
|                                      |                              | `area_cm2`   | `float64`       | cm² | 크랙의 면적                 |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                  |

#### Crack -> TF + Nav, Manager COM

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/crack_detection` | `your_ros_pkg/msg/CPDetection`| `x_m`        | `float64`       | m   |  맵 좌표 x           |
|                                      |                              | `y_m`        | `float64`       | m   | 맵 좌표 y |
|                                      |                              | `area_cm2`   | `float64`       | cm² | 크랙의 면적                  |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                  |


#### TF + Nav -> Buzzer

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/arrival`                    | `your_ros_pkg/msg/Arrival`   | `alert_message`        | `string`       |    | 도착 알림          |


#### robot1/TF + Nav -> robot3/TF + Nav

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/mapping_comand`             | `your_ros_pkg/msg/GlobalMapping`    | `command`      | `string`|    |  글로벌 매핑 명령    |

