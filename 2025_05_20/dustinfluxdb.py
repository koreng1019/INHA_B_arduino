import time
import requests, json
from influxdb import InfluxDBClient as influxdb
import serial

seri = serial.Serial('/dev/ttyAcm0', baudrate = 9600, timeout = None)

while(True):
  time.sleep(1)
  if seri.in_wating != 0:
  a = float(content.decode())
  data = [{
    'measurement' : 'dust',
    'tags':{
      'InhaUni' : '2222',
    },
    'fields':{
      'dust' : a,
    }
  }]
  client = None
  try:
    client = influxdb('loacalhost', 8086, 'root', 'root', 'dust')
  except Exception as e:
    print("Exception" + str(e))
  if client is not None:
    try:
      client.write_points(data)
    except Exception as e:
      print("Exception write " + str(e))
    finally:
      client.close()
  print(a)
  print("running influxdb OK")
