function updateRobotPose({ x, y }) {
    const marker = document.getElementById('robot-marker')
    const container = document.getElementById('map-container')
    const mapWidth = container.offsetWidth
    const mapHeight = container.offsetHeight
    
    // 1단계: TF 좌표를 맵 픽셀 좌표로 변환
    const mapPixelX = (x - MAP_METADATA.origin.x) / MAP_METADATA.resolution
    const mapPixelY = (y - MAP_METADATA.origin.y) / MAP_METADATA.resolution
    
    // 2단계: 맵 이미지의 실제 크기 확인
    const mapImg = document.getElementById('map')
    let mapImageWidth = mapWidth
    let mapImageHeight = mapHeight
    
    if (mapImg && mapImg.naturalWidth > 0) {
        mapImageWidth = mapImg.naturalWidth
        mapImageHeight = mapImg.naturalHeight
    }
    
    // 3단계: 맵 픽셀을 화면 픽셀로 스케일링
    const scaleX = mapWidth / mapImageWidth
    const scaleY = mapHeight / mapImageHeight
    
    const px = mapPixelX * scaleX
    const py = mapHeight - (mapPixelY * scaleY) // Y축 반전 (ROS → 웹)
    
    marker.style.left = `${px}px`
    marker.style.top = `${py}px`
}

// 정확한 좌표 변환 (map.yaml 기반)
const MAP_METADATA = {
    resolution: 0.05,
    origin: { x: -6.7, y: -3.71 }
};