from influxdb_client import InfluxDBClient

client = InfluxDBClient(
    url="https://us-east-1-1.aws.cloud2.influxdata.com",
    token="i56KVYFm6JCfVEAXfnk94bfndv-qkGX36tLhHPWER9dz5-vugmhvDqNMHX3CAN8agzNkinf7fR4_GTswUhbwbg==",
    org="rokey",  # 임시로 넣어도 무방
    verify_ssl=False
)

print("🔄 Pinging InfluxDB...")
print("Ping:", client.ping())

print("🔎 Health Check...")
health = client.health()
print("Status:", health.status)
print("Message:", health.message)

print("✅ 현재 계정의 Org 목록:")
orgs = client.organizations_api().find_organizations()
for org in orgs:
    print(f"- ID: {org.id}, Name: {org.name}")
