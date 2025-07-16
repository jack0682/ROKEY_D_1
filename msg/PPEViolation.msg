# PPE 위반 정보
std_msgs/Header header
string          violation_id
string          person_id
geometry_msgs/Point position
string[]        missing_items
float32         confidence
string          zone
uint8           severity_level  # 0=Low,1=Med,2=High
string          robot_id
