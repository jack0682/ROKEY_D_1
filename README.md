# ROKEY_D_1

## Node flow chart


![flowchart](https://github.com/user-attachments/assets/6482f594-0f37-487c-97c1-ea921d246053)



### Robot1

#### Human YOLO + Depth -> TF + Nav 

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/human_detection` | `your_ros_pkg/msg/PersonDetection`| `x_m`        | `float64`       | m   | 객체까지 전방 거리              |
|                                      |                              | `y_m`        | `float64`       | m   | 중앙 픽셀 기준 좌우 오프셋 거리    |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                    |


#### Puddle Seg -> TF + Nav 

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/puddle_detection`| `your_ros_pkg/msg/CPDetection`| `x_m`        | `float64`       | m   | 객체까지 전방 거리           |
|                                      |                              | `y_m`        | `float64`       | m   | 중앙 픽셀 기준 좌우 오프셋 거리 |
|                                      |                              | `area_cm2`   | `float64`       | cm² | 크랙의 면적                 |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                  |

#### Crack -> TF + Nav 

  | 토픽 이름                                | 메시지 타입                       | 필드 이름        | 타입              | 단위  | 설명                      |
| ------------------------------------ | ---------------------------- | ------------ | --------------- | --- | ----------------------- |
| `/robot1/yolo_depth/crack_detection` | `your_ros_pkg/msg/CPDetection`| `x_m`        | `float64`       | m   | 객체까지 전방 거리         |
|                                      |                              | `y_m`        | `float64`       | m   | 중앙 픽셀 기준 좌우 오프셋 거리 |
|                                      |                              | `area_cm2`   | `float64`       | cm² | 크랙의 면적                  |
|                                      |                              | `class_name` | `string`        |     | 클래스 라벨                  |

