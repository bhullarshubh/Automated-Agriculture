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
response_json = requests.get('http://192.168.43.248:8080/~/in-cse/in-name/iot_project/humidity_2/?rcn=4', headers=headers)
response = json.loads(response_json.text)
humidity2 = []
humidity_T2 = []

for data in response['m2m:cnt']['m2m:cin']:
    humidity2.append(float(data['con']))
    humidity_T2.append(datetime.strptime(data['ct'], "%Y%m%dT%H%M%S"))

Dates_H2 = dt.date2num(humidity_T2)
plt.plot_date(Dates_H2, humidity2, label='Humidity_2', xdate=True, ydate=False)

plt.xticks(rotation=90)


plt.gcf().autofmt_xdate()
plt.title('Project_Temperature_2')

plt.show()