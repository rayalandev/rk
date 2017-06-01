#define SYS_INIT_PROC	init
#define SYS_LOOP_PROC	loop
#define SYS_QUIT_PROC	quit
#define SYS_OPENGL
#define SYS_OPENGL_COMPATIBILITY
#define SYS_IMPLEMENTATION
#include "sys.h" 

Sys_Config init(int argc, char **argv)
{
	for(int i = 0; i < argc; i++) {
		OutputDebugStringA(argv[i]);
		OutputDebugStringA("\n");
	}

	Sys_Config config = { 0 };
	config.width = 1280;
	config.height = 720;
	config.monitor = SYS_MONITOR_PRIMARY;
	config.depth_bits = 32;
	config.color_bits = 32;
	config.title = "whatever";

	return(config);
}

#include <math.h>
void loop(Sys_State *sys)
{
 	glClear(GL_COLOR_BUFFER_BIT);  
    static float bt = 0;
    bt += sys->dt;
    static float r, g, b;
    r = (float)sin(bt);
    g = (float)cos(bt);
    b = (float)tan(bt);
    
    glClearColor(r,g,b,1.0f);
    Sleep(16);
}

void quit(void)
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
// 	[x] timing
//		temporarily usable
//		[x] delta
//		frame ?? (delta includes swap, frame is just time spent in loop() callback)
//	memory allocation
//		:thinking:
//		virtual alloc a large size, allow user to pass memory in the conifg
//		allow user to specify offset into allocated memeory where the memory passed goes
//		this could just be one bucket
//		could also use a define to specify the number of buckets wanted, an offset, whether you want page protection, etc
//		--
//		getting into memory allocation means we need to have gaurantees on our types
//		we need more information on the size of pointers (32/64bit)
//		we need to know what the cache line size is 
//		we need to know what the page size is
//		maybe sys_alloc / sys_free / sys_protect / etc are fine apis and we just assume any memory functions in here are virtual
//		maybe sys_virtual_alloc / sys_virtual_free / sys_virtual_protect is better because the api passed in a struct would be sys->alloc() vs sys->virtual_alloc(size)
//	file i/o
//	clipboard
//	inline
//	refactor key #defines SYS_, better names, etc