#include<stdio.h>
#include "v4l2_lib_cam.h"


int main()
{
	char *outBuf;
	int size;
	init_v4l2_lib_stream("/dev/video0");

	for( int i=0 ;i < 5; i++)
	{
	capture_image(&outBuf, &size );
	process_image(outBuf, size);
	usleep(100);
	//queue_next_buff();
	}


	exit_v4l2_lib_stream();
}