import matplotlib.pyplot as plt
import matplotlib.dates as dt
import numpy as np
import requests
#import datetime
from datetime import datetime
import json

headers = {
    'Accept': 'application/json',
    'X-M2M-Origin': 'admin:admin'
}
response_json = requests.get('http://192.168.43.224:8080/~/in-cse/in-name/iot_project/water_sensor/?rcn=4', headers=headers)
response = json.loads(response_json.text)
water_sensor = []
water_sensor_T1 = []

for data in response['m2m:cnt']['m2m:cin']:
    water_sensor.append(float(data['con']))
    water_sensor_T1.append(datetime.strptime(data['ct'], "%Y%m%dT%H%M%S"))

Dates_W2 = dt.date2num(water_sensor_T1)
plt.plot_date(Dates_W2, water_sensor, label='water_sensor_Level', xdate=True, ydate=False)

plt.xticks(rotation=90)


plt.gcf().autofmt_xdate()
plt.title('Project_Water_Level')

plt.show()