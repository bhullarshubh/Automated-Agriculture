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
response_json = requests.get('http://192.168.43.248:8080/~/in-cse/in-name/iot_project/pressure/?rcn=4', headers=headers)
response = json.loads(response_json.text)
pressure1 = []
pressure_T1 = []

for data in response['m2m:cnt']['m2m:cin']:
    pressure1.append(float(data['con']))
    pressure_T1.append(datetime.strptime(data['ct'], "%Y%m%dT%H%M%S"))

Dates_P1 = dt.date2num(pressure_T1)
plt.plot_date(Dates_P1, pressure1, label='pressure', xdate=True, ydate=False)

plt.xticks(rotation=90)


plt.gcf().autofmt_xdate()
plt.title('Project_Pressure')

plt.show()