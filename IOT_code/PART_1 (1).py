from onem2m import *

uri_cse = "http://127.0.0.1:8080/~/in-cse/in-name"

ae = "iot_project_final"
create_ae(uri_cse, ae)
uri_ae = uri_cse + "/" + ae

cnt = "echo_distance"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "temperature_1"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "humidity_1"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "temperature_2"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "humidity_2"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "pressure"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")

cnt = "water_sensor"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")


cnt = "DAY_HOUR"

create_cnt(uri_ae,cnt)
uri_cnt = uri_ae+"/" +cnt
create_data_cin(uri_cnt, "333")