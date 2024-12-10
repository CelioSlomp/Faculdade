import pywifi, time

wifi = pywifi.PyWiFi()
# use the first interface
interface = wifi.interfaces()[0]
# start scan
interface.scan()
for i in range(4):
    time.sleep(1)
    print('\rScanning WiFi, please wait...（' + str(3 - i), end='）')
print('\rScan Completed！\n' + '-' * 38)
print('\r{:4}{:6}{}'.format('No.', 'Strength', 'wifi name'))
# Scan result，scan_results() returns a set, each being a wifi object
bss = interface.scan_results()
# a set storing wifi name
wifi_name_set = set()