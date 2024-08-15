# Question 

Depmod ( dependancy modlues )
Modprobe ( same as insmod, but it automatically load the dependency also)( -r is used to remove )

Copy_to_user, copy_from_user

Nxp Downstream kernel vs mainline kernel

Upstream ( original kernel )
Downstream ( kernel modified by distributions, etc.. )
It mention the flow, if there is any bug in distribution, it can be go upward, if it originate from original kernel. And downstream kernel is the modified version of original kernel ( down flow )

BSS, data, rom size of the binary

operating clock frequency of MCU and DRIVER

mcu internel clock 16MHZ, and 48MHZ for USB
mcu I2C speed 400khz

Driver pixel clock 186.5MHZ
MIPI driver clock frequency 24MHZ

what is elf?



GMSL


Rootfs architecture

OpenGL

Nvcsi,vi, dtb, 

(Read about all the basics, and what you do stuff, porting stuff, camera,... Etc...) 

Western display, xorg, DRM direct rendering manager

Qmmf, adb... Etc

systemd services, TTY...


**How laptop chooses dtb, while there are numerous laptop work**
How Laptops Manage Hardware Diversity:

**ACPI (Advanced Configuration and Power Interface):**

Provides a standardized mechanism for operating systems to discover and configure hardware components.
Contains information about devices, power management, and other system-level details.
The kernel uses ACPI to dynamically detect and configure hardware at boot time.

**Modular Kernel:**

The Linux kernel is modular, allowing it to load and unload drivers for different hardware components as needed.
This flexibility enables the kernel to adapt to various hardware configurations.

**Firmware (UEFI):**

Stores basic system information and configuration data.
Provides a platform-independent interface for operating systems.
OS-Specific Configuration:

Operating systems like Ubuntu use configuration files and tools (e.g., xorg.conf) to further customize hardware settings.

https://unix.stackexchange.com/questions/399619/why-do-embedded-systems-need-device-tree-while-pcs-dont





Differnce between dp, dsi port..

THIS MODULE usage in driver.





EGL, Context, Surface, and Display
EGL
EGL (Embedded Graphics Library) is an interface that bridges the gap between graphics APIs like OpenGL ES and the underlying native platform window system. It handles tasks like:
 * Context management: Creating and managing OpenGL ES contexts.
 * Surface binding: Connecting OpenGL ES with surfaces where rendering occurs.
 * Synchronization: Ensuring proper synchronization between the graphics API and the display.
Display
A display represents a physical output device like a screen or monitor. In EGL, it's the connection point to the underlying graphics system. Think of it as the overall canvas where you'll be drawing.
Surface
A surface is a region where you can render graphics. It can be associated with a window, a texture, or an off-screen buffer. EGL uses surfaces to define the target for OpenGL ES rendering.
Context
A context is a state machine for OpenGL ES. It holds rendering state, including shaders, textures, and other resources. You create a context for a specific display and bind it to a surface to start rendering.
Relationship between them:
 * You create an EGL display to connect to the underlying graphics system.
 * You create a surface to define the area where you'll render.
 * You create a context to hold the rendering state.
 * You bind the context to the surface to start rendering on the display.
Visual analogy:
 * Display: The entire canvas or screen.
 * Surface: A specific area on the canvas where you'll paint.
 * Context: Your set of brushes and colors.
 * EGL: The easel that holds everything together.
Key points to remember:
 * A display can have multiple surfaces.
 * Multiple contexts can share the same surface.
 * Only one context can be current at a time.
Additional notes:
 * EGL is not Android-specific, though it's commonly used on Android.
 * There are different types of surfaces (window surfaces, pixel buffers, etc.) depending on the use case.
 * EGL provides mechanisms for creating and managing contexts efficiently.
Would you like to delve deeper into a specific aspect, such as creating an EGL context or using surfaces in Android development?





## Interesting
Dynamic debug in Linux
Unit testting
Linux display driver