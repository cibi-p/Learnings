# USB
<sup>**Ref.**</sup>  
<sup>[USB is a NutShell](https://www.beyondlogic.org/usbnutshell/usb1.shtml)</sup>  
<sup>USB 2.0 Specification</sub>

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
   
   ![NRZI](https://github.com/cibi-p/Learnings/assets/57592824/09b557c3-4aa1-4e00-a409-aba404183cc2)

 
9. USB supports plug’n’plug with dynamically loadable and unloadable drivers. The user simply plugs the device into the bus. The host will detect this addition, interrogate the newly inserted device and load the appropriate driver all in the time it takes the hourglass to blink on your screen provided a driver is installed for your device. The end user needs not worry about terminations, terms such as IRQs and port addresses, or rebooting the computer. Once the user is finished, they can simply lug the cable out, the host will detect its absence and automatically unload the driver.
10. The loading of the appropriate driver is done using a PID/VID (Product ID/Vendor ID) combination. The VID is supplied by the USB Implementor's forum at a cost and this is seen as another sticking point for USB. The latest info on fees can be found on the USB Implementor’s Website
11. Another more notable feature of USB, is its transfer modes. USB supports Control, Interrupt, Bulk and Isochronous transfers. While we will look at the other transfer modes later, Isochronous allows a device to reserve a defined amount of bandwidth with guaranteed latency. This is ideal in Audio or Video applications where congestion may cause loss of data or frames to drop. Each transfer mode provides the designer trade-offs in areas such as error detection and recovery, guaranteed latency and bandwidth.

## Connectors
![image](https://github.com/cibi-p/Learnings/assets/57592824/afe3876a-0538-489c-9023-9e7e77425f0e)
USB ports carry both power and data to a device. There are two kinds of USB ports - upstream and downstream. An upstream USB port receives power (and data) and a downstream USB port provides power (and data) to devices connected to it.
![image](https://github.com/cibi-p/Learnings/assets/57592824/68cf418d-5477-4da4-82ec-553e6932b462)

## Electrical 

![EXPLA DIAGRAM (CIBI)](https://github.com/cibi-p/Learnings/assets/57592824/a1138c56-d5e7-4a37-b699-48f02256d736)

![Low/full-speed signaling Levels](https://github.com/cibi-p/Learnings/assets/57592824/31f32d65-643d-4b12-8ad0-0dc757cb75a2)

From above table  
For Low Speed Mode : D- will be HIGH, D+ will be LOW   
For High Speed Mode : D+ will be HIGH, D- will be LOW  

J is differential `0` in Low Speed Mode  
K is differential `1` in LOW Speed Mode  
and
J is differential `1` in High Speed Mode
K is differential `0` in LOW Speed Mode

# USB Protocols
- USB is made up of several layers of protocols.
- Each USB transaction consists of a
   - Token Packet (Header defining what it expects to follow), an
   - Optional Data Packet, (Containing the payload) and a
   - Status Packet (Used to acknowledge transactions and to provide a means of error correction)
  As we have already discussed, USB is a host centric bus. The host initiates all transactions. The first packet, also called a token is generated by the host to describe what is to follow and whether the data transaction will be a read or write and what the device’s address and designated endpoint is. The next packet is generally a data packet carrying the payload and is followed by an handshaking packet, reporting if the data or token was received successfully, or if the endpoint is stalled or not available to accept data.

## Common USB Packet Fields
<details><summary>Sync</summary>
   All packets must start with a sync field. The sync field is 8 bits long at low and full speed or 32 bits long for high speed and is used to synchronise the clock of the receiver with that of the transmitter. The last two bits indicate where the PID fields starts.

   ![Sync Pattern](https://github.com/cibi-p/Learnings/assets/57592824/fe3a9338-c101-4730-8fd3-4b69e9dce29b)

</details>

<details><summary>PID</summary>
   PID stands for Packet ID. This field is used to identify the type of packet that is being sent. The following table shows the possible values.
   
![PID](https://github.com/cibi-p/Learnings/assets/57592824/897022fe-fc0f-4fb2-a832-49d13d48fab8)

![PID expla-1 ](https://github.com/cibi-p/Learnings/assets/57592824/0bc5bf93-8baa-4ea0-bca7-232a1e6eb425)
![PID table](https://github.com/cibi-p/Learnings/assets/57592824/ab41d40c-13ab-433a-a816-3dc7d5a02cf9)

   
</details>

<details><summary>ADDR</summary>
   The address field specifies which device the packet is designated for. Being 7 bits in length allows for 127 devices to be supported. Address 0 is not valid, as any device which is not yet assigned an address must respond to packets sent to address zero.

   ![image](https://github.com/cibi-p/Learnings/assets/57592824/2dcc511c-862f-4630-b24d-56f145408eb5)

</details>

<details><summary>ENDP</summary>
   The endpoint field is made up of 4 bits, allowing 16 possible endpoints. Low speed devices, however can only have 2 additional endpoints on top of the default pipe. (4 endpoints max)

   ![image](https://github.com/cibi-p/Learnings/assets/57592824/2578e66a-6ad9-45be-92cb-7e190a6d0d2c)

</details>

<details><summary>CRC</summary>
   Cyclic Redundancy Checks are performed on the data within the packet payload. All token packets have a 5 bit CRC while data packets have a 16 bit CRC.
</details>

<details><summary>EOP</summary>
   End of packet. Signalled by a Single Ended Zero (SE0) for approximately 2 bit times followed by a J for 1 bit time.
</details>

### Bit Stuffing
![ Bit Stuffing ](https://github.com/cibi-p/Learnings/assets/57592824/3a6dc389-af01-4f59-8bc1-e3d61da518a1)


