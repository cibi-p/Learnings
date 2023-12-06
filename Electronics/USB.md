# USB
<sup>[USB is a NutShell](https://www.beyondlogic.org/usbnutshell/usb1.shtml)</sup>

# BASICS of USB 
- USB 1.0
- USB 1.1
- USB 2.0

USB version 1.1 supported two speeds, a full speed mode of 12Mbits/s and a low speed mode of 1.5Mbits/s. The 1.5Mbits/s mode is slower and less susceptible to EMI, thus reducing the cost of ferrite beads and quality components. For example, crystals can be replaced by cheaper resonators. USB 2.0 which is still yet to see day light on mainstream desktop computers has upped the stakes to 480Mbits/s. The 480Mbits/s is known as High Speed mode and was a tack on to compete with the Firewire Serial Bus.

USB Speeds
- High Speed - 480Mbits/s
- Full Speed - 12Mbits/s
- Low Speed - 1.5Mbits/s

1. Only One host per bus. ( On the Go specification in USB 2.0 standard allow two devices to negotiate for the role of host )
2. The USB host is responsible for undertaking all transactions and scheduling bandwidth. Data can be sent by various transaction methods using a token-based protocol.
3. However USB uses a tiered star topology
4. Up to 127 devices can be connected to any one USB bus at any one given time.
5. The USB host controllers have their own specifications. With USB 1.1, there were two Host Controller Interface Specifications, UHCI (Universal Host Controller Interface) developed by Intel which puts more of the burden on software (Microsoft) and allowing for cheaper hardware and the OHCI (Open Host Controller Interface) developed by Compaq, Microsoft and National Semiconductor which places more of the burden on hardware(Intel) and makes for simpler software. Typical hardware / software engineer relationship. . .
6. With the introduction of USB 2.0 a new Host Controller Interface Specification was needed to describe the register level details specific to USB 2.0. The EHCI (Enhanced Host Controller Interface) was born. Significant Contributors include Intel, Compaq, NEC, Lucent and Microsoft so it would hopefully seem they have pooled together to provide us one interface standard and thus only one new driver to implement in our operating systems. Its about time.
7. USB as its name would suggest is a serial bus. It uses 4 shielded wires of which two are power (+5v & GND). The remaining two are twisted pair differential data signals. It uses a NRZI (Non Return to Zero Invert) encoding scheme to send data with a sync field to synchronise the host and receiver clocks.
   ![ USB_Wire_Expla. ](https://github.com/cibi-p/Learnings/assets/57592824/bef7d4ac-cddd-4dde-8517-92723f9924e4)

   ![NRIZ](https://github.com/cibi-p/Learnings/assets/57592824/2f556731-e329-4f39-ab5d-ea34d6d9d680)

   ![NRIZ...](https://github.com/cibi-p/Learnings/assets/57592824/e6bcb5e9-4742-47b5-b141-3128fd6b442a)
8. USB supports plug’n’plug with dynamically loadable and unloadable drivers. The user simply plugs the device into the bus. The host will detect this addition, interrogate the newly inserted device and load the appropriate driver all in the time it takes the hourglass to blink on your screen provided a driver is installed for your device. The end user needs not worry about terminations, terms such as IRQs and port addresses, or rebooting the computer. Once the user is finished, they can simply lug the cable out, the host will detect its absence and automatically unload the driver.
10. The loading of the appropriate driver is done using a PID/VID (Product ID/Vendor ID) combination. The VID is supplied by the USB Implementor's forum at a cost and this is seen as another sticking point for USB. The latest info on fees can be found on the USB Implementor’s Website
11. Another more notable feature of USB, is its transfer modes. USB supports Control, Interrupt, Bulk and Isochronous transfers. While we will look at the other transfer modes later, Isochronous allows a device to reserve a defined amount of bandwidth with guaranteed latency. This is ideal in Audio or Video applications where congestion may cause loss of data or frames to drop. Each transfer mode provides the designer trade-offs in areas such as error detection and recovery, guaranteed latency and bandwidth.
12. 
