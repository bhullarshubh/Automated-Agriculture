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
response_json = requests.get('http://192.168.43.248:8080/~/in-cse/in-name/iot_project/temperature_1/?rcn=4', headers=headers)
response = json.loads(response_json.text)
Temperature1 = []
Timestamps_T1 = []

for data in response['m2m:cnt']['m2m:cin']:
    Temperature1.append(float(data['con']))
    Timestamps_T1.append(datetime.strptime(data['ct'], "%Y%m%dT%H%M%S"))

Dates_T1 = dt.date2num(Timestamps_T1)
plt.plot_date(Dates_T1, Temperature1, label='Temperature_1', xdate=True, ydate=False)

plt.xticks(rotation=90)


plt.gcf().autofmt_xdate()
plt.title('Project_Temperature')

plt.show()