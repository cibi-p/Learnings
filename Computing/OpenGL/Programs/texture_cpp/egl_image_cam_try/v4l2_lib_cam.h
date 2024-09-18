

#ifndef __LIB_V4L2_CAM
#define __LIB_V4L2_CAM
int init_v4l2_lib_stream(char *devName );
int exit_v4l2_lib_stream();
void process_image(const void *p, int size);
int capture_image( char **outBuf, int *size );
#endif