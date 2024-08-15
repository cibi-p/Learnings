
/****************************************************************************/
/* V4L2 Application */
/***************************************************************************/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>              
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <getopt.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <linux/videodev2.h>


#define DEFAULT_DEV_NAME "/dev/video2"
#define CLEAR(x) memset( &(x), 0, sizeof( x ) )
#define FALSE 0
#define TRUE 1
#define OK 0
#define FAIL 1
#define DEF_WIDTH 1280
#define DEF_HIGHT 720


#define USE_MMAP


char*        dev_name = DEFAULT_DEV_NAME;
int          fd = -1, frame_count;
unsigned int n_bufs;
bool format_change = FALSE;
bool width_change = FALSE;
bool height_change = FALSE;


struct buffer {
	void *start;
	size_t length;
} *buffers;

int img_cnt = 0;
FILE *fp = NULL;
char fName[5] = "img_out/img_o";

static void errno_exit(const char *s)
{
        fprintf(stderr, "%s error %d, %s\\n", s, errno, strerror(errno));
        exit(EXIT_FAILURE);
}

static void process_image(const void *p, int size)
{
	fName[4] = img_cnt + '0';
	fp = fopen( fName, "wb" );
        //if (out_buf)
                fwrite(p, size, 1, fp);
	fclose(fp);
	fp = NULL;

	img_cnt++;

        fflush(stderr);
        fprintf(stderr, ".");
        fflush(stdout);

}

static int read_frame(void)
{
        struct v4l2_buffer buf;
        unsigned int i;


	CLEAR(buf);

#ifdef USE_MMAP
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;

	if (-1 == ioctl(fd, VIDIOC_DQBUF, &buf)) {
		switch (errno) {
		case EAGAIN:
			//printf("D");
			return 0;

		case EIO:
			/* Could ignore EIO, see spec. */

			/* fall through */

		default:
			errno_exit("VIDIOC_DQBUF");
		}
	}

	assert(buf.index < n_bufs);

	process_image(buffers[buf.index].start, buf.bytesused);

	if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
		errno_exit("VIDIOC_QBUF");
#endif

#ifdef USE_USER_POINTER
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_USERPTR;

	if (-1 == ioctl(fd, VIDIOC_DQBUF, &buf)) {
		switch (errno) {
		case EAGAIN:
			//printf("E");
			return 0;

		case EIO:
			/* Could ignore EIO, see spec. */

			/* fall through */

		default:
			errno_exit("VIDIOC_DQBUF");
		}
	}

	for (i = 0; i < n_bufs; ++i)
		if (buf.m.userptr == (unsigned long)buffers[i].start
		    && buf.length == buffers[i].length)
			break;

//	process_image((void *)buf.m.userptr, buf.bytesused);

	if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
		errno_exit("VIDIOC_QBUF");
#endif



        return 1;
}
static void capture_image( void )
{
        unsigned int count;
	time_t time_var;
	time_t start = 0, end = 0;
	struct tm* timeinfo;
	unsigned int frame_got = 0;
        count = frame_count;
	uint8_t s_sec, e_sec;
	int start_sec;
	struct tm* start_time, *end_time;

	int average_time = 0;
	
	time( &time_var );
	timeinfo = localtime( &time_var );
	start_sec = timeinfo->tm_sec;

	//count = 50;
        while( count-- > 0 || 0 ) 
	{
		start = clock();
	
                for (;;) {
                        fd_set fds;
                        struct timeval tv;
                        int r;
			
                        FD_ZERO(&fds);
                        FD_SET(fd, &fds);

                        // Timeout. 
                        tv.tv_sec = 2;
                        tv.tv_usec = 0;

                        r = select(fd + 1, &fds, NULL, NULL, &tv);

                        if (-1 == r) {
                                if (EINTR == errno)
                                        continue;
                                errno_exit("select");
                        }

                        if (0 == r) {
                                fprintf(stderr, "select timeout\\n");
                                exit(EXIT_FAILURE);
                        }

		//printf("%d ", e_sec - s_sec );
                        if (read_frame())
                                break;
                        /* EAGAIN - continue select loop. */
                }

		end = clock(); 

		time( &time_var );
		timeinfo = localtime( &time_var );
		e_sec = timeinfo->tm_sec;
		frame_got++;
			average_time += ( end - start );
		printf("%d ", e_sec - s_sec );
		if( e_sec - s_sec >= 1 || e_sec - s_sec < 0 ) 
		{

			time( &time_var );
			printf("FPS: %d %ld %ld %ld\n", frame_got, end, start, end - start );
			timeinfo = localtime( &time_var );
			s_sec = timeinfo->tm_sec;

			frame_got = 0;

		}

        }
	time( &time_var );
	end_time = localtime( &time_var );
	printf("Average_time :%d %d, time: %d:%d\n", average_time/1000, average_time, start_sec, end_time->tm_sec);
}

static void start_capturing( void )
{
        unsigned int i;
        enum v4l2_buf_type type;
#ifdef USE_MMAP
	for (i = 0; i < n_bufs; ++i) {
		struct v4l2_buffer buf;

		CLEAR(buf);
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
			errno_exit("VIDIOC_QBUF");
	}
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if (-1 == ioctl(fd, VIDIOC_STREAMON, &type))
		errno_exit("VIDIOC_STREAMON");
#endif

#ifdef USE_USER_POINTER
       for (i = 0; i < n_bufs; ++i) 
       {
		struct v4l2_buffer buf;

		CLEAR(buf);
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_USERPTR;
		buf.index = i;
		buf.m.userptr = (unsigned long)buffers[i].start;
		buf.length = buffers[i].length;

		if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
			errno_exit("VIDIOC_QBUF");
	}
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if (-1 == ioctl(fd, VIDIOC_STREAMON, &type))
		errno_exit("VIDIOC_STREAMON");
#endif

}

void uninti_mmap( void )
{
	int i;
	for (i = 0; i < n_bufs; ++i)
                        if (-1 == munmap(buffers[i].start, buffers[i].length))
                                errno_exit("munmap");
}

static void init_mmap(void)
{
        struct v4l2_requestbuffers req;

        CLEAR(req);

        req.count = 4;
        req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        req.memory = V4L2_MEMORY_MMAP;

        if (-1 == ioctl(fd, VIDIOC_REQBUFS, &req)) {
                if (EINVAL == errno) {
                        fprintf(stderr, "%s does not support "
                                 "memory mappingn", dev_name);
                        exit(EXIT_FAILURE);
                } else {
                        errno_exit("VIDIOC_REQBUFS");
                }
        }

        if (req.count < 2) {
                fprintf(stderr, "Insufficient buffer memory on %s\\n",
                         dev_name);
                exit(EXIT_FAILURE);
        }

        buffers = calloc(req.count, sizeof(*buffers));

        if (!buffers) {
                fprintf(stderr, "Out of memory\\n");
                exit(EXIT_FAILURE);
        }

        for ( n_bufs = 0; n_bufs < req.count; ++n_bufs ) {
                struct v4l2_buffer buf;

                CLEAR(buf);

                buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
                buf.memory      = V4L2_MEMORY_MMAP;
                buf.index       = n_bufs;

                if (-1 == ioctl(fd, VIDIOC_QUERYBUF, &buf))
                        errno_exit("VIDIOC_QUERYBUF");

                buffers[n_bufs].length = buf.length;
		
                buffers[n_bufs].start =
                        mmap(NULL /* start anywhere */,
                              buf.length,
                              PROT_READ | PROT_WRITE /* required */,
                              MAP_SHARED /* recommended */,
                              fd, buf.m.offset);

                if (MAP_FAILED == buffers[n_bufs].start)
                        errno_exit("mmap");

		printf("BUF.LENGTH %d %u\n", buf.length, buf.bytesused );
        }
}

void list_format( void )
{
	struct v4l2_fmtdesc fmtdes;
	struct v4l2_frmsizeenum frmsize;
	short int fmt_nu = 0;
	fmtdes.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;


	// Opening the device camera
        fd = open(dev_name, O_RDWR /* required */ | O_NONBLOCK, 0);
        if (-1 == fd) 
	{
                fprintf(stderr, "Cannot open '%s': %d, %s\\n",
                         dev_name, errno, strerror(errno));
                exit(EXIT_FAILURE);
        }
	printf("Format\n");
        for( fmtdes.index = 0; ; fmtdes.index++ )
        {
                if( 0 != ioctl( fd, VIDIOC_ENUM_FMT, &fmtdes ) )
                {
                        break;
                }

                printf("[%d] %s %x\n", fmt_nu++, fmtdes.description, fmtdes.pixelformat );
		  /************************ Frames *********************************/


                frmsize.pixel_format = fmtdes.pixelformat;
                frmsize.index = 0;
                while( ioctl( fd, VIDIOC_ENUM_FRAMESIZES, &frmsize ) == 0 )
                {
                        if( frmsize.type == V4L2_FRMSIZE_TYPE_DISCRETE )
                                printf("\t%d x %d a\n", frmsize.discrete.width, frmsize.discrete.height );
                        else if ( frmsize.type == V4L2_FRMSIZE_TYPE_STEPWISE )
                                printf("\t%d x %d b\n", frmsize.stepwise.max_width, frmsize.stepwise.max_height );
                        frmsize.index++;
                }

        }
	close(fd);
}

static const char short_options[] = "d:hlf:W:H:Xc:";

static const struct option
long_options[] = {
        { "device", required_argument, NULL, 'd' },
        { "help",   no_argument,       NULL, 'h' },
        { "list",   no_argument,       NULL, 'l' },
        { "format",   required_argument, NULL, 'f' },
        { "width",  required_argument,       NULL, 'W' },
        { "height", required_argument,       NULL, 'H' },
        { "TO UO|PDATE", no_argument,       NULL, 'X' },
        { "count",  required_argument, NULL, 'c' },
        { 0, 0, 0, 0 }
};
static void usage(FILE *fp, int argc, char **argv)
{
        fprintf(fp,
                 "Usage: %s [options]\n\n"
                 "Version 1.3\n"
                 "Options:\n"
                 "-d | --device name   Video device name [%s]\n"
                 "-h | --help          Print this messagen\n"
                 "-l | --list          List the Format and the Frames \n"
                 "-f | --format        choose format\n"
                 "-W | --width         set Width\n"
                 "-H | --height        Set Hight\n"
                 "-f | --format        Force format to 640x480 YUYV\n"
                 "-c | --count         Number of frames to grab [%i]\n"
                 "",
                 argv[0], dev_name, frame_count);
}

static void init_UserPointer(unsigned int buffer_size)
{
        struct v4l2_requestbuffers req;

        CLEAR(req);

	printf("Afdaf");

        req.count  = 4;
        req.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        req.memory = V4L2_MEMORY_USERPTR;

        if (-1 == ioctl(fd, VIDIOC_REQBUFS, &req)) {
                if (EINVAL == errno) {
                        fprintf(stderr, "%s does not support "
                                 "user pointer i/on", dev_name);
                        exit(EXIT_FAILURE);
                } else {
                        errno_exit("VIDIOC_REQBUFS");
                }
        }

        buffers = calloc(4, sizeof(*buffers));

        if (!buffers) {
                fprintf(stderr, "Out of memory\\n");
                exit(EXIT_FAILURE);
        }

        for (n_bufs = 0; n_bufs < 4; ++n_bufs) {
                buffers[n_bufs].length = buffer_size;
                buffers[n_bufs].start = malloc(buffer_size);

                if (!buffers[n_bufs].start) {
                        fprintf(stderr, "Out of memory\\n");
                        exit(EXIT_FAILURE);
                }
        }
}

static int xioctl(int fh, int request, void *arg)
{
        int r;

        do {
                r = ioctl(fh, request, arg);
        } while (-1 == r && EINTR == errno);

        return r;
}

bool set_format( unsigned int fmt_nu, unsigned int width, unsigned int height )
{
	struct v4l2_fmtdesc fmtdes;
	struct v4l2_format format;
	bool rtn_status = OK;
	unsigned int min;
	
			printf(" in setting Format\n");
	do
	{
		
		fmtdes.index = fmt_nu;
		fmtdes.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		if( 0 != ioctl( fd, VIDIOC_ENUM_FMT, &fmtdes ) )
		{
			printf("Error in setting Format\n");
			rtn_status = FAIL;
			break;
		}

	    	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	        if (ioctl(fd, VIDIOC_G_FMT, &format) < 0) {
			perror("VIDIOC_G_FMT");
			exit(1);
	    	}

		CLEAR( format );

		format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		format.fmt.pix.field = V4L2_FIELD_INTERLACED;
		format.fmt.pix.pixelformat = fmtdes.pixelformat;
		format.fmt.pix.width = width;
		format.fmt.pix.height = height;
		//format.fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		//format.fmt.pix.sizeimage = width * height * 2;
		//format.fmt.pix.bytesperline = width * 2;
		if( -1 == xioctl( fd, VIDIOC_S_FMT, &format ) )
		{
			perror( "E" );
			rtn_status = FAIL;
			break;
		}

/*
		if( -1 == ioctl( fd, VIDIOC_G_FMT, &format ) )
		{
			printf( "TEST_INIOCTL\n" );
			perror( "E" );
			rtn_status = FAIL;
			break;
		}*/
		printf("\nSET_FMT %d %d %d %d", format.fmt.pix.bytesperline, format.fmt.pix.sizeimage, format.fmt.pix.width, format.fmt.pix.height );

 /* Buggy driver paranoia. */
        min = format.fmt.pix.width * 2;
        if (format.fmt.pix.bytesperline < min)
                format.fmt.pix.bytesperline = min;
        min = format.fmt.pix.bytesperline * format.fmt.pix.height;
        if (format.fmt.pix.sizeimage < min)
                format.fmt.pix.sizeimage = min;

		if( fmtdes.pixelformat == format.fmt.pix.pixelformat && 
				format.fmt.pix.width == width &&
				format.fmt.pix.height == height )
		{
			printf( "Format Change Successfully\n" );
		}
		else
		{
			printf("Format Change Fail" );
			rtn_status = FAIL;
			//break;
		}

	}while( 0 );
	return rtn_status;
}

int main( int argc, char **argv )
{
	int option_index, i;
	short int choice;
	enum v4l2_buf_type type;
	unsigned int width = DEF_WIDTH;
	unsigned int height = DEF_HIGHT;
	unsigned int fmt_nu = 0;
	unsigned int sizeimage;

	while( 1 )
	{
		choice = getopt_long(argc, argv,
			short_options, long_options, &option_index );
		
		if (-1 == choice)
                        break;

                switch (choice) 
		{
               		case 0: /* getopt_long() flag */
                        	break;

			case 'd':
				dev_name = optarg;
				break;

			case 'h':
				usage(stdout, argc, argv);
				exit(EXIT_SUCCESS);

			case 'l':
				list_format();
				exit(EXIT_SUCCESS);
				//io = IO_METHOD_MMAP;
				break;

			case 'f':
				format_change = TRUE;
				fmt_nu = strtol( optarg, NULL, 0 );

				//io = IO_METHOD_READ;
				break;

			case 'W':
				width_change = TRUE;
				width = strtol( optarg, NULL, 0 );
				//io = IO_METHOD_USERPTR;
				break;

			case 'H':
				height_change = TRUE;
				height = strtol( optarg, NULL, 0 );
				//out_buf++;
				break;

			case 'X':
				//force_format++;
				break;

			case 'c':
				errno = 0;
				frame_count = strtol(optarg, NULL, 0);
				if (errno)
					errno_exit(optarg);
				break;

			default:
				usage(stderr, argc, argv);
				exit(EXIT_FAILURE);
                }
	}
	
	if( width_change != height_change )
	{
		printf("Invalid selection width and height both or requeried\n");
		exit( EXIT_FAILURE );
	}

	// Opening the device camera
        fd = open(dev_name, O_RDWR /* required */ | O_NONBLOCK, 0);
        if (-1 == fd) 
	{
                fprintf(stderr, "Cannot open '%s': %d, %s\\n",
                         dev_name, errno, strerror(errno));
                exit(EXIT_FAILURE);
        }
	

	if( format_change == TRUE || ( width_change == TRUE && height_change == TRUE ) )
	{

		if( set_format( fmt_nu, width, height ) )
			exit( 1 );
	}

	struct v4l2_format format;
	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if( -1 == ioctl( fd, VIDIOC_G_FMT, &format ) )
	{
		perror( "E" );
	}
	sizeimage = format.fmt.pix.sizeimage;



	// Creating MMAP buffer
#ifdef USE_MMAP
	init_mmap();
#endif

#ifdef USE_USER_POINTER
	printf("Test: %d\n\n", sizeimage );
	init_UserPointer( sizeimage );
#endif

	start_capturing();
	capture_image();
	
	/* Steaming off */
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
                if (-1 == ioctl(fd, VIDIOC_STREAMOFF, &type))
                        errno_exit("VIDIOC_STREAMOFF");

#ifdef USE_MMAP
	/* free mmap buffer */
	for (i = 0; i < n_bufs; ++i)
		if (-1 == munmap(buffers[i].start, buffers[i].length))
			errno_exit("munmap");
#endif

#ifdef USE_USER_POINTER
	for (i = 0; i < n_bufs; ++i)
                        free(buffers[i].start);
#endif

	/* close file descriptor */
	if (-1 == close(fd))
                errno_exit("close");

        fd = -1;

}
