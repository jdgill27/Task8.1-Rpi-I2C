#  Raspberry Pi Master for Arduino Slave
#  i2c_master(rpi).py
 
from smbus import SMBus
 
addr = 0x8 # bus address
bus = SMBus(1) # indicates /dev/ic2-1
 
numb = 1
 
print ("Enter 1 for ON or 0 for OFF")
while numb == 1:
 
	ledstate = input(">>>>   ")
 
	if ledstate == "1":
		bus.write_byte(addr, 0x1) # switch LED on
	elif ledstate == "0":
		bus.write_byte(addr, 0x0) # switch LED on
	else:
		numb = 0