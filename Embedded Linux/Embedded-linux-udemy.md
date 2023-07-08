# Embedded Linux Step by Step Using Beaglebone Black

<sup>[Udemy Course Link](https://www.udemy.com/course/embedded-linux-step-by-step-using-beaglebone/learn/lecture/22179210?start=0#overview)</sup>
-
<sup>**Course by:** Kiran Nayak</sup>

<sup>**Development Board used:** Beaglebone Black Revision (6 or A6A or A5c orA5B or A5A or A4B or A4A or A4) or Bealebone White</sup>

<sup>**Source code and other files:** [Click here](https://github.com/niekiran/EmbeddedLinuxBBB)</sup>

---
![BeagleBone Black](https://beagleboard.org/static/ti/product_detail_black_sm.jpg)

## Introduction
### Intro. to Beaglebone Black?
- It is the Low cost single board computer(SBC)
- Like Raspberry pi
- It's an Open-source hardware and software platform
- It has Significant amount of on-board memory, wireless/wired connectivity, USB interfaces, it can run OS, you can connect to monitor.
- It uses **TI’s AM355x SOC**, which can run at 1GHZ clock speed
- It Comes with the pre loaded debian based distro.

### Important Hardware parts of the BBB Rev C board

![Hardware parts explanation of BBB](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-09-54-2a835b3967416b6547610dd4d441f2b8.png)

1. **The AM355x SoC by Texas Instruments (TI)**

    <sup>SOC stands for System on Chip. As the name indicates, a single chip contains most of the essential computing /communication/storage engine of the computing world, like Flash memory, Graphics processing engine, the image processing engine, the USB communication engine, RS232, SPI, I2C engine and much more. The heart of the SOC is a processor. For example AM355x SOC is powered by ARM cortex A8 processor. Explore more about AM355x SOC from here:
    http://www.ti.com/product/AM3359 </sup>

    ![SoC](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-07-41-251651543be3a79fa9b7866c5b03de83.png)

    The below image shows the Texas insturments TI's AM3359 Specs, (Note: the specs can be vary based on the series number AM335x, The SoC used in BBB Rev C is AM3358BZCZ100)
    ![TI'S AM3359 specs](https://github.com/broharigunda/HSS/assets/57592824/88794d8d-6f49-424f-83cb-184fc4112104)
2. **Embedded MMC(eMMC)**\
    The board has 4GB of eMMC(embedded Multi Media Controller) memory chip, This is an on-board  memory chip that holds up to 4GB of data in BBB Rev C.

    Accessing data from this memory is much faster than accessing through external micro sd card , and remember that the board boots from this memory by default. But you can always change, from where the boot should boot, more on this is covered later. 
3. **SDRAM Memory: 512MB DDR3**\
    This is external Dynamic RAM memory, the board comes with SDRAM Memory: 512MB DDR3. This is on the board and connected to SOC. I will cover more on memory interfaces later in this course. They claim this memory as, faster and low power RAM memory. During booting the boot images will get loaded to this RAM from other memories and will execute from here, more on this later. 
4. **Serial(UART) pin outs**\
    ![UART BBB](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-13-29-35869590e6f74ed234a373ceecc5d80c.jpg)
    The BBB hardware doesn’t come with on board UART to usb convertor chip. But , what they have given is serial port pin outs. They want you to get an external uart to usb convertor hardware and connect to these pins in order to get the debug messages from the board on to your Host PC serial monitoring software.
5. **The boot button (S2)**\
    the board boots from on-board eMMC memory by default, so instead of eMMC booting, if you want to boot from the external SD card, then you have to use this button (S2). By pressing and holding this button, if you apply the power or press the power button, then board will boot from the external SD Card.
8. **Powering the BBB board.**\
    There are 2 options to power the board. 

    *Through the Mini USB port*\
    The mini USB cable comes with the BBB, and using that cable you can power the board by connecting it to your PC. At max it can only get the current of 500mA . Note that there are 2 mini USB ports on the board. You should use the one which is adjacent to the Ethernet connector which says P4.

    But powering through USB has couple of disadvantages.

    1) You won’t be able to run the board at full speed

    2) You won’t be able to drive the LCD

    3) You will not be able to drive the some Beaglebone capes connected over expansion headers.

    But don’t worry most of the time the current from the USB cable connected to PC is sufficient and you may not need to buy power adapter unless you connect lots of power hungry peripherals to the BBB. 

    *DC Barrel Plug 5.5mm/2.1mm (Recommended 5V @ 2A)*\
    You can also power the board by connecting a DC power adapter to the board; it should limit the current to max 2A. This power adapter won’t come with the board and you have to purchase it separately only if required

    - The operating voltage must be 5V.
    - The operating current is recommended to be 1.2A to 2A.

### Features
![specs BBB](https://elinux.org/images/2/2b/Features.jpg)

### Connecting BBB to PC Using External USB to UART Converter
![UART Converter](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-00-21-59850e1f22a6c6c8558e20b833310b63.png)

or

you can use the cables with UART converter

#### Serial Monitoring Software
Serial Monitoring Software lets you monitor and record any data going through serial ports of your computer. This dedicated solution will come in handy for development, testing and debugging of your COM-based programs and devices.

- software for ubuntu
    - Minicom
- software for windows
    - Tera-Term
    - PuTTY
    - Hyper-Terminal

### Connecting BBB to the PC
**For Ubuntu**
- Install minicom
- Connect the BBB board
- Run `dmesg` in the terminal. It will log the ubs connected info. along with the other system log.
  <details><summary>dmesg</summary><sub>The dmesg command is a Linux utility that displays kernel-related messages retrieved from the kernel ring buffer. The ring buffer stores information about hardware, device driver initialization, and messages from kernel modules that take place during system startup</sub></details>
  
  ![Output of dmesg](https://github.com/broharigunda/HSS/assets/57592824/5091bcc7-d16a-48ad-8561-69d67e1f676f)

  - To configure Minicom, type `sudo minicom -s`. It will list various option. Select `Serial port setup`. Edit the Serial Device name to the name found using `dmesg` (ex: /dev/ttyUSB0 since dmesg gives ttyUSB0). Also Change the BPS/Par/Bits (Baud rate) to `115200 8N1`.
  For monitoring purpose Hardware and Software flow control should be No. Press enter to save it.
  - Then select `save setup as dfl`, using this we not want do configure every time.
  - Then Select `Exit`
  - Now you can monitor the BBB board

  ### Connecting BBB to internet using USB
  - Connect the BBB and PC using the Cable
  - New Drive is appeared in the Laptop
  - Install the Driver's in that drive based on your OS. It will enable the USB cable acting as the Ethernet 
  
  **Exploring BBB Web Interface**
  - After connecting the BBB board to Internet using USB.
  - After this BBB debian os which is running on BBB board already running a web server.
  - to connect that open browser and type `192.168.7.2`. It will show the BBB web Page/portal
  - You can interact with the BBB board with this portal.
  - This portal shows the board connection status, BBB Serial Number, Demo Scripts... etc. 
  - For Example click **Blink a in built led** demo. You can see the `java script` code for blink a led. which is use `Node.js` and `BoneScript Library`

## TI's AM335x Functional block overview
![AM335x block diagram](https://www.mouser.in/images/marketingid/2012/microsites/145997644/TI_AM335x_blkdia.png)

## What do we need to boot Linux kernel in ARM based Hardware(BBB)
We Need at-least 4 software components
1. **ROM Boot Loader (RBL)**\
    - First Piece of Code to run on the SOC when the supply is given. It is written by the vendor and stored in ROM of the SoC during the production of this chip. Cannot be Changed.
    - The major job of the RBL is to load and run the second stage boot loader such as SPL or MLO
2. **SPL(Secondary Program Loader) / MLO(Memory Loader)**
    - The job of the Second stage boot loader is to load and execute the third stage boot loader such as U-boot
3. **U-boot**
    - it load and run the Linux Kernel
4. **Linux Kernel**
5. **RFS (Root File System)**

**BeagleBone Board Boot Options**
we can keeP the boot the images in the any of the `NAND Flash, NOR Flash (eXecute in place, XIP), USB, eMMC, SD card, Ethernet, UART, SPI` memory or peripheral and boot able to boot this SOC

Goto the page number 5031 of the TRM(Technical Reference Manual) and you will find the below table. 

![SYSBOOT Configuration Pins](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-27-04-860c053e9f9fa96dff869559fe99a105.png)

Don’t be scared by looking at the table, but just concentrate on SYSBOOT[4:0]

“SYSBOOT” is one of the register of this SOC and its first five bits decide the boot order .

Let’s take an example,

When SYSBOOT [4:0] = 00000b (This is reserved, you cannot use this configuration)

When SYSBOOT [4:0] = 00001b

After the RESET if SYSBOOT [4:0] = 00001b , then SOC will try to boot from UART0 first , if fails, then it tries to boot from XIP(XIP stands for eXutable In Place memory like NOR Flash), if that also fails, then it will try to boot from MMC0, if no success, finally it tries to boot from SPI0, if that also fails, then SOC outputs the error message and stops. 

**How SOC decides the boot order?**
When you reset the SOC, the code stored in the ROM of the SOC runs first !

The code stored in the “ROM” is called ROM boot loader, this is programmed in to the ROM of the SOC during taping out of the chip, you cannot able to change it, why?? Because its ROM. Read only !!!!

The job of the ROM is to set up the SOC clock, watch dog timer, etc and also its major job is to load the second stage boot loader, what we call MLO or SPL, more on this later.

**Now, from where it should load the second stage boot loader?**

For that what ROM code does is, it reads the register SYSBOOT [15:0], and based on the value of SYSBOOT[4:0] it prepares the list of booting devices. The register SYSBOOT [15:0] value is decided by the voltage level on the SYSBOOT pins.

That is, let’s say, if SYSBOOT[4:0] = 00011b, then boot order will be , UART0,SPI0.XIP,MMC0 ( look at the table please !!! )

So, we can say that, The SYSBOOT pins configure the boot device order (set by SYSBOOT[4:0]).

Some board, will give you the control to change the SYSBOOT[15:0] value by using dip switches like below. 

![dip switch](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-28-00-cb8cace0d3d9aaf40c35d025161cbc9e.jpg)

Here, by configuring the dip switches you can decide the value of SYSBOOT pins , thus enforcing the boot order which you like. 

But in BBB, there are no such dip switches to configure the SYSBOOT pins. BBB has some other circuitry to decide the SYSBOOT pins voltage level, read on!!

BBB Boot order configuration circuit

In BBB you will find this circuitry, (you will find in SRM  , not in TRM )

![TRM reference](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-28-25-cd61d3c3871527b453928528611c4c38.png)

Here observe that SYS_BOOT2 is connected to a button S2 of the BBBB ( S2 is the boot button )

When you simply give power to the board, You will find the voltage level as below.

SYS_BOOT0 = 0V

SYS_BOOT1 = 0V

SYS_BOOT2 =1V

SYS_BOOT3 = 1V

SYS_BOOT4 = 1V

You can confirm this by measuring the voltage level using Mutlimeter,

If you have Multimeter, measure the voltage of 45,44,43,41,40 pins of the expansion header P8 of the board you will find SYSBOOT[4:0] = 11100 

![Expansion Headers](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-28-50-1aca8ef1aab6a418daf54cf7d3c60b74.png)

and when you press the button S2, SYS_BOOT2 will be grounded , so SYSBOOT[4:0]= 11000

Great! Now based on S2 (BBB boot button) we got 2 boot configurations

    1) S2 Released (SYSBOOT[4:0] = 11100)

        The boot order will be

        MMC1 (eMMC)
        MMC0 (SD card)
        UART0
        USB0
    2) S2 pressed (SYSBOOT[4:0] = 11000) , The boot order will be

        SPI0
        MMC0 (SD card)
        USB0
        UART0
        So, to conclude, there are 5 boot sources supported for this board including SPI.

1) **eMMC Boot(MMC1) :**

 eMMC is connected over MMC1 interface, This is the fastest boot mode possible, eMMC is right there on your board, so need not to purchase any external components or memory chip. This is the default boot mode. As soon as you reset the board, the board start booting from loading the images stored in the eMMC.

If no proper boot image is found in the eMMC, then Processor will automatically try to boot from the next device on the list. 

**2) SD Boot :**

 If the default ( that is booting from eMMC) boot mode fails, then it will try to boot from the SD card you connected to the sd card connector at MMC0 interface.

If you press S2 and then apply the power, then the board will try to boot from the SPI first, and if nothing is connected to SPI, it will try to boot from the MMC0 where our SD card is found

Also remember that we can use SD card boot to flash boot images on the eMMC. So if you want to write new images on the eMMC  then you can boot through sd card, then write new images to eMMC, then reset the board, so that your board can boot using new images stored in the eMMC.  We will do these experiments later in this course. Don’t worry!

**3) Serial boot :**

In this mode, the ROM code of the SOC will try to download the boot images from the serial port.

We have separate experiment on this boot mode and its very interesting. 

**4 ) USB BOOT :**

You may be familiar with this boot mode, that is booting through usb stick!

 You would have booted your PC through the usb stick. What you do is, you restart the PC, then press bios button to put the PC in to bios mode, there you select boot form usb, right?

 It is very similar, when you reset the board, you can make your board to boot from the USB stick. 

**More details about ROM Code Booting procedure!**

These are the 2 flow charts, you can find in the TRM of the am335x SOC

Please visit the page 5029 of the TRM

You will find the below image 

![ROM code Booting Procedure](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-30-17-44c5d28b9fd340abb67e504c2886923b.png)

Here, you can see that the ROM code goes through its boot device list to load the second stage boot loader. It will prepare the boot devices list based on the value of SYSBOOT pins. 

The ROM Code start-up procedure  (page 5026)

![ROM CODE STARTUM SEQUENCE](https://img-c.udemycdn.com/redactor/raw/2017-08-21_09-30-46-337610a35c2e16f3ab22f26588afea30.png)


In the above diagram you can see it run `DPLLS` and Clocks configuration before booting.

Here PLL (Phase Locked Loop) is a CLOCK generating engine. By using this we can generate the wide frequencies of the frequencies for Display subsystem, processor, usb subsystem, AHB/APB/System Clock generation... etc

![PLL](https://github.com/broharigunda/Learnings/assets/57592824/40044c6c-21df-4b6d-b4b0-c1acb283b5b6)

**Clocking Configuration**

During booting, based on the value of 15:14 bits of the SYSBOOT register, the RBL (ROM Boot loader) comes to know about the value of the external crystal connected to the SoC
![CLocking configuration](https://github.com/broharigunda/Learnings/assets/57592824/8a778a75-d2ce-45d1-9767-a6d63b343788)

In BBB it is configured to 24MHz(SYSBOOT[15:14]=01b)

PLL take this 24MHZ and produce the necessary clock frequency, ex: 200MHZ for peripheral block, 500MHZ for ARM Cortex A8 etc... in the below image

![PLL clocking output](https://github.com/broharigunda/Learnings/assets/57592824/6831ebd9-45a6-4ff9-b632-da2ce998248d)

**MLO/SPL (Memory Loader / Secondary Program Loader)**\
MLO or SPL initializes the SoC to a point that, U-boot can be loaded into external RAM (DDR Memory)

1. It does UART console initialization to print out the debug messages
2. Reconfigures the PLL to desired value.
3. Initializes the DDR registers to use the DDR memory
4. Does muxing configurations of boot peripherals pin, because its next job is to load the u-boot from the boot peripherals
5. eg. if MLO is going to get the u-boot from the MMC0 or MMC1 interfaces, then it will do the mux configurations to bring out the MMC0 or MMC1 functionalities on the pins
6. It copies the u-boot image into the DDR memory and passes control to it.

Note: MLO will does not load 3rd stage boot loader like U-boot to the internal RAM of the SoC, because the internal RAM of the SoC will be 128KB only. So it copies it into the DDR Memory.

**Why RBL need MLO/SPL to load the U-Boot, why not it directly load U-boot into SRAM?**\
Because the size of the memory is low less than 128KB (because it also use this part of 128KB for Stack and HEAP + 1Kb is considered as Secured memory)

**Why AM335x ROM Code cannot load the Uboot directly to DDR RAM?**\
The reason why ROM boot loader of the AM335x SOC cannot load Uboot directly to DDD3 by skipping SPL is,

ROM code won’t be having any idea about what kind of DDR RAM being used in the product to initialize it.

DDR RAM is purely product/ board specific.

Let’s say there are 3 board/product manufacturing companies X,Y,Z

X may design a product using AM335x SOC with DDR3. In which lets say DDR3 RAM is produced by microchip.

Y may design its product using AM335x SOC with DDR2 produced by Transcend and Z may not use DDR memory at all for its product.

So, RBL has no idea in which product this chip will be used and what kind of DDR will be used, and what are DDR tuning parameters like speed, bandwidth, clock augments, size, etc. 

Because to read ( or write) anything from/to DDR RAM , first, the tuning parameters must be set properly and DDR registers must be initialized properly .

Every different manufacture will have different parameters for their RAM. So, that’s the reason RBL never care about initializing DDR controller of the chip and DDR RAM which is connected to chip.

RBL just tries to fetch the SPL found in memory devices such as eMMC and SD card or peripherals like UART,EMAC,etc.

And in the SPL/MLO, you should know, what kind of DDR is connected to your product and based on that you have to change the SPL code , rebuild it and generate the binary to use it as the second stage boot loader.

For example the Beaglebone black uses DDR3 from Kingston and if your product uses DDR3 from transcend, then if the turning parameters are different then you have to change the DDR related header files and the tuning parameter macros of the SPL , rebuild and generate the binary .

**U-BOOT**

1. It initialize some of the peripherals like I2C, NAND, Flash, ethernet, UART, USB, MMC, etc, because it supports loading kernel from all these peripherals
2. Load the linux kernel images from various boot sources to the DDR memory of the board.
3. Boot Sources: USB, eMMC, SD card, Ethernet, Serial port, NAND, flash, etc.
4. passing of boot arguments to the kernel

    **uEnv.txt**

    we should provide one file called uEnv.txt (it consist of environment variable values of u-boot). This file is used to change the behavior of the u-boot. Example content of uEnv.txt
    ```bash
    console=ttyO0,115200n8
    ipaddr=192.168.7.2
    serverip=192.168.7.1
    loadaddr=0x82000000
    fdtaddr=0x88000000
    loadfromsd=load mmc 0:2 ${loadaddr} /boot/uImage;load mmc 0:2 ${fdtaddr} /boot/am335x-boneblack.dtb
    linuxbootargs=setenv bootargs console=${console} root=/dev/mmcblk0p2 rw 
    uenvcmd=setenv autoload no; run loadfromsd; run linuxbootargs; bootm ${loadaddr} - ${fdtaddr}
    ```

**U-Boot** always look for `uImage` (uImage= u-boot header + zImage(ELF binary format of the linux kernel))

Sample header of U-boot looks like

```C
typedef struct image_header {
     uint32_t ih_magic; /* Image Header Magic Number */
     uint32_t ih_hcrc; /* Image Header CRC Checksum */
     uint32_t ih_time; /* Image Creation Timestamp */
     uint32_t ih_size; /* Image Data Size */
     uint32_t ih_load; /* Data Load Address */
     uint32_t ih_ep; /* Entry Point Address */
     uint32_t ih_dcrc; /* Image Data CRC Checksum */
     uint8_t ih_os; /* Operating System */
     uint8_t ih_arch; /* CPU architecture */
     uint8_t ih_type; /* Image Type */
     uint8_t ih_comp; /* Compression Type */
     uint8_t ih_name[IH_NMLEN]; /* Image Name */
} image_header_t;
```
![u-boot partial console output](https://slideplayer.com/slide/3997036/13/images/18/Kernel+uImage+%E2%80%93+What+is+it.jpg)

### linux Boot strap loader
![Control flow during linux boot](https://github.com/broharigunda/Learnings/assets/57592824/2f369c2f-a6e8-472a-b420-dce6ff80f59e)

`bootm.c` is the one of the file of the U-boot source code, which will help the U-boot to hands off the control to the linux kernel (it leave boot strap loader because linux will be in compressed mode, boot strap mode first has to be called to uncompress and relocate the kernel)

in the above image head.s in Linux kernel is used to 
- CPU secific initializations
- checks for valid processor architecture
- page table inits
- Initialize and prepare MMU for the indentified processor architecture
- Enable MMU to support virtual memory
- call `start_kernel` function of the main.c


### eMMC flashing of BBB
1. Download the latest Debian OS
2. Write the Bootable image to the SD caard first
3. Boot the board from SD card
4. Execute the eMMC flasher script
5. eMMC flasher script will flash all the conents of the sd card on to the eMMC memory

## Linux Device Tree / Flattened Device Tree
The on board peripherals which connect to SPI, I2C, SDIO, ETHERNET, etc have no capability to announce there existence on the board by themselves to the operating system. THese peripherals are also called as "Platform devices". For that board file should be created, so the linux know the device details.

When a driver for a particular platform peripheral is loaded, the linux calls the "probe" function of the driver if there is any match in its platform device database. In the "Probe" function of the driver, you can do device initializations

Note: USB device has the inbuilt intelligence to send its details to the operating systems (that means USB supports dynamic discoverability), so it is not platform device.

**Why device tree is introduced?**\
One kernel image of the Development board does not run completely in other development board.(Means Linux community does not ship the kernel for the only one development board, manufacture may use different hardware components)

The linux community wanted to cut off the dependencies of platform device enumeration from the linux kernel, that is, hard coding od platform specific details in to the linux kernel.

They Linux community come up with the Device tree.
In this Instead of adding hard coded hardware details in to the linux kernel board file, every board vendors has to come up with a file called DTS.

This file actually consists of all the details related to the board written using some pre defined syntaxes. so you can say that this file consists of data structures which describe all the required peripherals of the board.

This .dtd file is compiled by DTC (Device Tree Compiler) produce DTB(Device Tree Binary) binary file

When you edit the DTS file to add a new entry, you need not to compile the kernel again, you just have to compile the DTS to obtain the new DTB.

During booting linux must know the address at which DTB is present in the RAM

## Writing uEnv.txt file from scratch
Smiliar to linux environment variables, u-boot also has set to standard as well as user defined environmental variables which can be used to override or change the behavior of the uboot

uEnv.txt file is nothing but collections of various env variables which are initialized to number of uboot commands and automating the command execution.

**About RFS**/
about the Root File System(RFS) and its directory structure. 

Now the root file system, as the name indicates, it’s a file system which Linux mounts to the "/" (root)

File system is nothing but a collection of files organized in standard folder structure. 

Yes!!! There is a standard for the Linux file system. That is called "File system Hierarchy Standard"

Now, let’s understand what the purpose of each folder is and what exactly it contains. 

The official documentation of the FHS says this about the directories present in the "/"

http://refspecs.Linuxfoundation.org/FHS_3.0/fhs/ch03s02.html


Directory	| Description
-|-
bin	|Essential command binaries
boot|	Static files of the boot loader
dev	|Device files
etc	|Host-specific system configuration
lib	|Essential shared libraries and kernel modules
media|	Mount point for removable media
mnt	|Mount point for mounting a filesystem temporarily
opt	|Add-on application software packages
run	|Data relevant to running processes
sbin|	Essential system binaries
srv	|Data for services provided by this system
tmp	|Temporary files
usr	|Secondary hierarchy
var	|Variable data

**bin/ :**\
This directory contains binaries of Linux commands which are used by both the system admins and users.

You don’t need privileges from your System admin to execute these commands neither you need root access. Remember that this folder will not contain binaries for all the Linux commands. There is a restriction on what types of commands have to be placed in this directory, because these binaries can be executed by the common user. 

Below are some the commands you will find it in the bin/ directory. 

cat, pwd, cp.. etc

you can see that commands related to "repairing", "recovering", "restoring", "network configuration" ,”modules install remove”  are not found in this directory. 

**boot/:**\
This directory contains the boot related files, which are required to boot the Linux. This directory may be read by the boot loader to read the boot images like Linux kernel image, dtb, vmLinux, initramfs, etc. 

So this directory may be accessed by boot loader even before the kernel boots and mounts the file system. 

**dev/:**\
This is the place where you can find the "device files”.

You may be heard or read this statement "in unix/Linux devices are treated like file access" .

 Yes, if you want to access any i/o, networking devices, memory devices, serial devices, parallel devices, input output devices such as keyboard, mouse, display, everything will be treated like a file.

So, this directory will have the file entry for every device

For example: the i2c devices may have a file entries like this 

/dev/i2c-0 ,

/dev/i2c-1,

The user Space application can use this device files to access those devices .

The ram may have a device file entry like /dev/ram0

The 2 partitions of the SD card may have entries like this:

/dev/mmcblk0p1

/dev/mmcblkop2.

The serial devices may have entries like this:

 /dev/ttyS0,

/dev/ttyS1,

/dev/ttyO0 

It’s the responsibility of the respective drivers to populate this directory with the device files 

**etc/ :**\
This is the place where all the start-up scripts, networking scripts, scripts to start and stop networking protocols like NFS, networking configuration files,  different run level scripts will be stored. 

1) Contains run level scripts, which will be used during different run levels

2) Contains start-up and shutdown scripts

3) Contains various scripts related to services like start/stop networking, start/stop NFS, etc 

4) Contains various configuration files, like passwd, hostinfo, etc. 

5) Contains various network configuration files

**lib/ :**\
The major contents of this directory are 

1) The dynamically loadable kernel modules.  ( later you will see, when we compile the kernel modules and when we run “modules install” command , all the kernel modules will go and sit in this directory under the sub directory "modules" .)

2) To store the Essential shared libraries (.so.*) for dynamic linking.

 for example, 'C' shared library(libc), math library, python libray, etc,

**media/ :**\
This is the mount point for the removable media like your USB flash drive, SD cards, camera, cell phone memory, etc .

For example, when i connect my SD card to the PC, there will be 2 device files will be created for each partition 1) /dev/sdb1 and 2) /dev/sdb2

and theses 2 device files are automatically mounted under the /media directory. So that i can access those 2 partitions just like folders. 

Some examples:-

/media/cdrom for CD-ROM  

/media/<your usb flash drive name>

**mnt/ :**\
This is the place where you can mount the temporary file system. 

The system admins can use a Linux commands to temporarily mount and un-mount the file system, if they want to transfer any file. 

**opt/ :**\
"opt" stands for "optional"

This directory will be used when you install any software packages for your Linux distribution. 

For example if i run the command apt-get install <some packages name> then the package will be installed in this directory. 

**sbin/ :**\
The commands which come in the category of system administration will be stored in this directory, which is used by your sys admins for the purpose of networking configurations, repairing, restoring and recovering .

may be sbin stands for "System Admin's bin" ??

It also has root only command and need privileges to execute those commands. 

These are the commands which  you will find in sbin/
fastboot, fdisk, mkfs, reboot, ifconfig... etc..

**home/:**\
The /home directory contains a home folder for each user.

Each user only has write access to their own home folder and must obtain elevated permissions (become the root user) to modify other files on the system.

This directory will be used to store personal data of the user . 

In a single user mode you may have folder like this 

/home/ramesh

In a multiple user mode, you may have folder dedicated to each user. 

/home/ramesh,  /home/suresh, /home/ram etc. 

**srv/ :**\
SRV stands for "Service"

The /srv directory contains “data for services provided by the system.” If you are using the Apache HTTP server to serve a website, you’d likely store your website’s files in a directory inside the /srv directory.

**tmp/ :**\
Applications store temporary files in the /tmp directory.

**usr/ :**\
According to FHS, it’s a "secondary hierarchy", the usr/ directory may contain the below sub directories 

Directory          |         Description
-|-
bin|                              Most user commands
include                    |  Header files included by C programs
lib                         |       Libraries
local                     |      Local hierarchy (empty after main installation)
sbin         |                    Non-vital system binaries
share                  |        Architecture-independent data

/usr/bin contains binary of the commands for user programs

For example, if you have firefox on your system then just check it must be available under "/usr/bin" not under /bin. Because it is a binary related to user installed programs, similarly, "zip" command also you will find it under /usr/bin. 

/usr/sbin contains, again privileged commands which may be used by the system admins, but these commands are for system administration purposes. 

/usr/include will hold the header files which will be included from the C programs you write.

/usb/lib will again hold the shared libraries, linker/loader files , which enable your /usb/bin and /usr/sbin commands to execute. 

For more information you may check this official link:

http://refspecs.linuxfoundation.org/FHS_3.0/fhs/ch03.html

### Generating "initramfs" using RFS

**What is initramfs ?**

 The word "initramfs" is made up of three words "initial" "RAM based" "file system"

This is nothing but a file system hierarchy (which you just studied in the last lecture, all those directory structure), made to live in the RAM of the device by compressing it (we use compression because RAM is precious, we cannot use whole RAM just to store the FS) and during booting, Linux mounts this file system as the initial file system.  That means you just need RAM to mount the FS and get going with the complete boot Process. 

**Does that mean usage of initramfs is compulsory? Used everywhere, every time ?**

 No, not necessarily. Using initramfs is optional.

**So, why do we need initramfs ?**

 Let’s understand this with an example. 

Let’s say you have a product and your product has USB interfaces, mass storage devices like SD card and let’s say you also have networking peripherals like Ethernet and also display. 

Now, to operate this wide range of peripherals, all the device drivers must be in place right?

That means all the drivers must be loaded in to the kernel space.

And along with the drivers, some peripherals may require the firmware binaries to operate. 

One idea is make sure that all those drivers are “built in” in to the kernel, that’s not a great idea because that makes your Linux kernel specific to your product and it will drastically increase the Linux kernel image size. 

Another good way is, you come up with the minimal file system, where you store all your drivers and firmware, and load that FS in to the RAM and ask the Linux to mount that file system during boot( Thanks to kernel boot arguments , you can use the kernel boot arguments to indicate kernel that your FS resides in RAM )

When the kernel mounts that file system from RAM, it loads all the required drivers for your product and all the peripherals of your product are ready to operate, because the drivers are in place. 

after That you can even get rid of this RAM based file system and use (switch to) some other advanced file system which resides on your other memory devices like eMMC/SD card or even you can mount from the network. 

So, basically initramfs embedded into the kernel and loaded at an early stage of the boot process, where it gives all the minimal requirements to boot the Linux kernel successfully on the board just from RAM without worrying about other peripherals. And what you should store in initramfs is left to your product requirements, you may store all the important drivers and firmware, you may keep your product specific scripts, early graphic display logos, etc. 

**How to keep initramfs in to RAM?**

 There are 2 ways, 

1) You can make initramfs “built in” in to the Linux Kernel during compilation ( i will show you later in this course) , so when the Linux starts booting , it will place the initramfs in the RAM and mounts as the initial root file system and continues.

2) You can load the initramfs from some other sources in to the RAM of your board and tell the Linux Kernel about it (that is , at  what RAM address initramfs is present ) via the kernel boot arguments. 


**How to generate the initramfs ?**

Step 1: Download and extract the root file system attached with this lecture. This root file system I took from TI software SDK (am335x-tiny_filesystem.zip)


Step 2: Get in to the extracted folder and run the below 2 commands from the “terminal”
```sh
$ find . | cpio -H newc -o > ../initramfs.cpio

$ cat ../initramfs.cpio | gzip > ../initramfs.gz
```
In the first command we are generating a cpio archive and then gz archive.

You will end up with the file “initramfs.gz” which is about 3MB.

STEP 3 : install mkImage command

For that run “apt-get install u-boot-tools” on your terminal software, this will install all the u-boot related tools along with mkImage tool.

```$ apt-get install u-boot-tools```

STEP 4: Make our initramfs , uboot friendly by attaching the uboot header with load  address and other info .

Run the below command.

```$ mkimage -A arm -O Linux -T ramdisk -C none -a 0x80800000 -n "Root Filesystem" -d ../initramfs.gz  ../initramfs```

### Booting BBB over serial port
Serial booting means transferring the boot image(which has SPL, U-BOOT, linux kernel image, DTB, file system) from HOST(PC) to the board via the Serial Port(UART) in order to boot the board

Xmodem, Ymodem, Zmodem, Kermit, etc... are the protocol used to transfer file over UART

**Booting the BBB boots via UART Peripheral**\
We have to boot exactly the same way how we used to boot via SD card, that is press and hold the s2 button, then press and release the s3 power button(power button), make sure that sd card is not inserted to the board

 S2 pressed (SYSBOOT[4:0] = 11000) , The boot order will be

        SPI0
        MMC0 (SD card)
        USB0
        UART0
    IT check SPI0, MMC0 (SD card), USB0. since we does not connect any it will Check UART0 and boot.

## Important Hints
1. **Recommended load addresses**
    Binary | DDR RAM Load address
    -|-
    Linux kernel image (uImage) | 0x82000000
    FDT or DTB | 0x88000000
    RAMDIS or INITRAMFS | 0x88080000
  
## Glossory
- **SYSFS** 
    - It is a file system. it is on the fly file system and exists on the RAM
    - It is a kind of window for the user space to peek in to the various subsystem of the linux kernel like, Networking subsystem, memory subsystem, bus, devices, firmware... 
    - Using SYSFS we can control various peripheral which are connected like LCD, EEPROM, I2C Sensor, 7Segment display, SPI, ADC, etc

- **Inteconnects**
    Interconnects are the high speed buses which carry information between various controllers and peripheral devices of the SoC. All the Interconnects will have the own set of registers by which you can control data width, speed, interrupt, etc..

## ABBREVATION
 
Abb. | Full form
 -|-
 BSL | Boot Strap loader
 DTB | Device Tree Binary
 DTS | Device Tree Source
 DTC | Device Tree Compiler
 ELF | Executable and Linkable Format
 eMMC | Embedded Multimedia Card (NAND Flash memory and it also has controller)
 MMU | Memory Management Unit
 MMC | MultiMediaCard 
 MLO | Memory Loader
 RBL | ROM Boot Loader
 SPL | Secondary Program Loader
 SPI | Serial Peripheral Interface
 UART | Universal Asynchronours receiver-transmitter

## Commands
**Linux commands**
Command | Explanation
-|-
dmesg | The dmesg command is a Linux utility that displays kernel-related messages retrieved from the kernel ring buffer. The ring buffer stores information about hardware, device driver initialization, and messages from kernel modules that take place during system startup

**U-Boot Commands**
commands | explanation
-|-
 md | Memory display
 imi | print header information for application image
 load | load binary file from a filesystem
 fatload | used to read file from FAT commands
 help | it will help to understand the command
  boot | boot default
  bootm | boot from memory
  bootp | boot image via network
  bootz | boot linux zImage Imagefrom memory
  cmp | memory compare
  echo | echo arg. to console
  printenv | print all the environment variables.
  setenv | used to create/update environment variable
  run | run is used to run the environment variable value as command
  loadx/loady/loadz | send/receive file using xmodem/ymodem/zmodem protocol


