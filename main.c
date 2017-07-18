#define OGL_IMPLEMENTATION
#define OGL_COMPATIBILITY
#include "ogl.h"

#define SYS_INIT_PROC	init
#define SYS_LOOP_PROC	loop
#define SYS_QUIT_PROC	quit
#define SYS_OPENGL
//#define SYS_OPENGL_COMPATIBILITY
#define SYS_IMPLEMENTATION
#include "sys.h"

#include <string.h>

Sys_Config init(int argc, char **argv)
{
	for (int i = 0; i < argc; i++) {
		OutputDebugStringA(argv[i]);
		OutputDebugStringA("\n");
	}

	Sys_Config config = { 0 };
	config.width = 1280;
	config.height = 720;
	config.monitor = 0;
	config.memory_size = 8192;
	config.title = "Taeky";

#if 0	// file test
	char write_string[32] = { 0 };
	write_string[0] = 'l';
	write_string[1] = 'i';
	char read_string[32] = { 0 };
	Sys_File log_file = sys_file_open("log.txt");
	sys_file_write(log_file, 0, strlen(write_string), &write_string);
	sys_file_read(log_file, 0, strlen(write_string), &read_string);
	sys_file_close(log_file);
#endif

	int i = ogl_init();
	sys_assert(i == 0);

	return(config);
}

#define gl_blue 0.0f, 0.0f, 1.0f, 1.0f
#define gl_white 1.0f, 1.0f, 1.0f, 1.0f
#define gl_red 1.0f, 0.0f, 0.0f, 1.0f
void loop(Sys_State *sys)
{
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

}

/*
WHY ARE ALT KEYS THE ONLY BOKEN KEYS AHHHHHHHHHHHHHHHHH?
*/

void quit(Sys_State *sys)
{
}

// todo
//	[x] remove maximize box / resizing options
//		 load all available display modes?
// [x] disable the warning from including windows.h
//  [x] sys_unused(x); macro
//	-------------------------------------------------------------------------------------
// 	[x] input_state
//		temporarily usable, has many bugs
//		[x] program crashes sometimes?
//		some inputs get stuck // look into clearing input every frame
//		[x] progam gets stuck if I use RIDEV_NOLEGACY?
//		look into scan codes or something alt+enter doesn't work on all computers
//	[x] minimized, width, height
//	-------------------------------------------------------------------------------------
// 	[??] timing
//		frame ?? (delta includes swap, frame is just time spent in loop() callback)
//	[x] keyboard input
//		[x] raw input makes keyboard input work in hangul / other language input modes
//	memory allocation
//		system memory detection
//		page size detection (4kb usually)
//		virtual alloc / protect / free 
//		automatically add overflow/underflow gaurd pages in debug mode
//	[??] file i/o
//		[x] file size
//		[??] current working directory
//		[??] prefered directory
//		[x] open file
//		[x] write into offset some amount of bytes
//		[x] read from offset some amount of bytes
//		[x] test
//	logging system / revisit errors (log.txt at location of executable)