# Some notes on this subject

the id table of keyboard.c was extracted from drivers/hid/usbhid/usbkbd.c
it's quite simple and with MODULE_DEVICE_TABLE, depmod can know that this
module supports usb keyboard class.

and I accidently forgot to implement probe of it, but don't know why it works(?)
for now...

don't know why both general usbkbd module, and my keyboard.ko module are loaded.
I think I should learn more about hotplug event, and depmod / udev.
