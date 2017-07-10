// c99 features used in this library
// TODO(rayalan): 
//	system info
//		ram
//		cpu info / features
//		display names / etc
//		peripheral names/etc
//	threads (maybe)
//	osx
#ifndef SYS_INCLUDE
#define SYS_INCLUDE
#ifdef __cplusplus
extern "C" {
#endif

	// todo(rayalan): use rk_gl solution to replace
#include <stdint.h> // int64_t
#include <stddef.h> // size_t

#if defined(_WIN32) || defined(_WIN64)
#define SYS_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
#define SYS_OSX
#elif defined(__linux__)
#define SYS_LINUX
#else
#error "You must #define what system you are building for."
#endif

#ifdef SYS_STATIC
#define SYS_DEF static
#else
#define SYS_DEF extern
#endif

#if defined(DEBUG) || defined(_DEBUG) || defined(DBG)
#ifndef NDEBUG
#define SYS_DEBUG
#endif
#endif

#if defined(_MSC_VER) && !defined(_WIN32_WCE)
#define sys_trigger_breakpoint() __debugbreak()
#elif (defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)))
#define sys_trigger_breakpoint() __asm__ __volatile__("int $3\n\t")
#elif defined(HAVE_SIGNAL_H)
#include <signal.h>
#define sys_trigger_breakpoint() raise(SIGTRAP)
#else
	/* How do we trigger breakpoints on this platform? */
#define sys_trigger_breakpoint()
#endif

#ifdef SYS_DEBUG
#define sys_assert(condition) if(!(condition)){sys_trigger_breakpoint();}
#else
#define sys_assert(condition) do { (void) sizeof((condition)); } while (0)
#endif

#if defined(_MSC_VER)
#define sys_unused(x) (__pragma(warning(suppress:4100))(x))
#elif defined (__GCC__)
#define sys_unused(x) __attribute__((__unused__))(x)
#else
#define sys_unused(x) ((void)(sizeof(x)))
#endif

#define SYS_MONITOR_PRIMARY -1
#define SYS_INPUT_STATE_SIZE 256

#ifndef SYS_OPENGL_MAJOR
#define SYS_OPENGL_MAJOR 4
#endif
#ifndef SYS_OPENGL_MINOR
#define SYS_OPENGL_MINOR 1
#endif

#ifndef SYS_OPENGL_COLOR_BITS
#define SYS_OPENGL_COLOR_BITS 32
#endif

#ifndef SYS_OPENGL_DEPTH_BITS
#define SYS_OPENGL_DEPTH_BITS 32
#endif

	//=============================================================================
	//      
	//
	//     Key State Codes
	//
	//
	//=============================================================================
	// TODO(rayalan): this may depend on os
#define MOUSE_LEFT        0x01
#define MOUSE_RIGHT      0x02
#define KEY_CANCEL       0x03
#define MOUSE_MIDDLE       0x04
#define MOUSE_FORWARD      0x05
#define MOUSE_BACKWARD       0x06
#define KEY_BACKSPACE           0x08
#define KEY_TAB            0x09
#define KEY_CLEAR          0x0C
#define KEY_ENTER         0x0D
#define KEY_SHIFT          0x10
#define KEY_CONTROL        0x11
#define KEY_ALT           0x12
#define KEY_PAUSE          0x13
#define KEY_CAPITAL        0x14
#define KEY_KANA           0x15
#define KEY_HANGUL         0x15
#define KEY_JUNJA          0x17
#define KEY_FINAL          0x18
#define KEY_HANJA          0x19
#define KEY_KANJI          0x19
#define KEY_ESC         0x1B
#define KEY_CONVERT        0x1C
#define KEY_NONCONVERT     0x1D
#define KEY_ACCEPT         0x1E
#define KEY_MODECHANGE     0x1F
#define KEY_SPACE          0x20
#define KEY_PAGE_UP          0x21
#define KEY_PAGE_DOWN        0x22
#define KEY_END            0x23
#define KEY_HOME           0x24
#define KEY_LEFT           0x25
#define KEY_UP             0x26
#define KEY_RIGHT          0x27
#define KEY_DOWN           0x28
#define KEY_SELECT         0x29
#define KEY_PRINT          0x2A
#define KEY_NUMENTER        0x2B
#define KEY_SNAPSHOT       0x2C
#define KEY_INS         0x2D
#define KEY_DELETE         0x2E
#define KEY_HELP           0x2F
#define KEY_LSUPER           0x5B
#define KEY_RSUPER           0x5C
#define KEY_APPS           0x5D
#define KEY_SLEEP          0x5F
#define KEY_NUMPAD0        0x60
#define KEY_NUMPAD1        0x61
#define KEY_NUMPAD2        0x62
#define KEY_NUMPAD3        0x63
#define KEY_NUMPAD4        0x64
#define KEY_NUMPAD5        0x65
#define KEY_NUMPAD6        0x66
#define KEY_NUMPAD7        0x67
#define KEY_NUMPAD8        0x68
#define KEY_NUMPAD9        0x69
#define KEY_MULTIPLY       0x6A
#define KEY_ADD            0x6B
#define KEY_SEPARATOR      0x6C
#define KEY_SUBTRACT       0x6D
#define KEY_DECIMAL        0x6E
#define KEY_DIVIDE         0x6F
#define KEY_F1             0x70
#define KEY_F2             0x71
#define KEY_F3             0x72
#define KEY_F4             0x73
#define KEY_F5             0x74
#define KEY_F6             0x75
#define KEY_F7             0x76
#define KEY_F8             0x77
#define KEY_F9             0x78
#define KEY_F10            0x79
#define KEY_F11            0x7A
#define KEY_F12            0x7B
#define KEY_F13            0x7C
#define KEY_F14            0x7D
#define KEY_F15            0x7E
#define KEY_F16            0x7F
#define KEY_F17            0x80
#define KEY_F18            0x81
#define KEY_F19            0x82
#define KEY_F20            0x83
#define KEY_F21            0x84
#define KEY_F22            0x85
#define KEY_F23            0x86
#define KEY_F24            0x87
#define KEY_NUMLOCK        0x90
#define KEY_SCROLL         0x91
#define KEY_OEM_NEC_EQUAL  0x92   // '=' key on numpad
#define KEY_OEM_FJ_JISHO   0x92   // 'Dictionary' key
#define KEY_OEM_FJ_MASSHOU 0x93   // 'Unregister word' key
#define KEY_OEM_FJ_TOUROKU 0x94   // 'Register word' key
#define KEY_OEM_FJ_LOYA    0x95   // 'Left OYAYUBI' key
#define KEY_OEM_FJ_ROYA    	0x96   // 'Right OYAYUBI' key
	// these aren't used by windows 
#define MOUSE_BUTTON1       0x97
#define MOUSE_BUTTON2       0x98
#define MOUSE_BUTTON3       0x99
#define MOUSE_BUTTON4       0x9A
#define MOUSE_BUTTON5       0x9B
#define KEY_LSHIFT         0xA0
#define KEY_RSHIFT         0xA1
#define KEY_LCONTROL       0xA2
#define KEY_RCONTROL       0xA3
#define KEY_LALT          0xA4
#define KEY_RALT          		0xA5
#define KEY_BROWSER_BACK        0xA6
#define KEY_BROWSER_FORWARD     0xA7
#define KEY_BROWSER_REFRESH     0xA8
#define KEY_BROWSER_STOP        0xA9
#define KEY_BROWSER_SEARCH      0xAA
#define KEY_BROWSER_FAVORITES   0xAB
#define KEY_BROWSER_HOME        0xAC
#define KEY_VOLUME_MUTE         0xAD
#define KEY_VOLUME_DOWN         0xAE
#define KEY_VOLUME_UP           0xAF
#define KEY_MEDIA_NEXT_TRACK    0xB0
#define KEY_MEDIA_PREV_TRACK    0xB1
#define KEY_MEDIA_STOP          0xB2
#define KEY_MEDIA_PLAY_PAUSE    0xB3
#define KEY_LAUNCH_MAIL         0xB4
#define KEY_LAUNCH_MEDIA_SELECT 0xB5
#define KEY_LAUNCH_APP1         0xB6
#define KEY_LAUNCH_APP2         0xB7
#define KEY_OEM_1          		0xBA   // ';:' for US
#define KEY_OEM_PLUS       0xBB   // '+' any country
#define KEY_OEM_COMMA      0xBC   // ',' any country
#define KEY_OEM_MINUS      0xBD   // '-' any country
#define KEY_OEM_PERIOD     0xBE   // '.' any country
#define KEY_OEM_2          0xBF   // '/?' for US
#define KEY_OEM_3          0xC0   // '`~' for US
#define KEY_OEM_4          0xDB  //  '[{' for US
#define KEY_OEM_5          0xDC  //  '\|' for US
#define KEY_OEM_6          0xDD  //  ']}' for US
#define KEY_OEM_7          0xDE  //  ''"' for US
#define KEY_OEM_8          0xDF
#define KEY_OEM_AX         0xE1  //  'AX' key on Japanese AX kbd
#define KEY_OEM_102        0xE2  //  "<>" or "\|" on RT 102-key kbd.
#define KEY_ICO_HELP       0xE3  //  Help key on ICO
#define KEY_ICO_00         0xE4  //  00 key on ICO
#define KEY_PROCESSKEY     0xE5
#define KEY_ICO_CLEAR      0xE6
#define KEY_PACKET         0xE7
#define KEY_OEM_RESET      0xE9
#define KEY_OEM_JUMP       0xEA
#define KEY_OEM_PA1        0xEB
#define KEY_OEM_PA2        0xEC
#define KEY_OEM_PA3        0xED
#define KEY_OEM_WSCTRL     0xEE
#define KEY_OEM_CUSEL      0xEF
#define KEY_OEM_ATTN       0xF0
#define KEY_OEM_FINISH     0xF1
#define KEY_OEM_COPY       0xF2
#define KEY_OEM_AUTO       0xF3
#define KEY_OEM_ENLW       0xF4
#define KEY_OEM_BACKTAB    0xF5
#define KEY_ATTN           0xF6
#define KEY_CRSEL          0xF7
#define KEY_EXSEL          0xF8
#define KEY_EREOF          0xF9
#define KEY_PLAY           0xFA
#define KEY_ZOOM           0xFB
#define KEY_NONAME         0xFC
#define KEY_PA1            0xFD
#define KEY_OEM_CLEAR      0xFF

	typedef struct Sys_Memory {
		void *ptr;
		size_t alloc_size;
		size_t usable_size;
		uint64_t flags;
	} Sys_Memory;

	typedef struct Sys_File {
		void *ptr;
		unsigned char is_new;
		uint64_t size;
	} Sys_File;

	typedef struct Sys_Config {
		int width, height;
		int monitor;
		int fullscreen;
		const char *title;
		Sys_Memory memory;
		unsigned char color_bits, depth_bits;
	} Sys_Config;

	typedef struct Sys_State {
		// window information
		void *window;
		void *gfx_context;
		int width, height;
		int monitor;
		int fullscreen;
		// memory
		Sys_Memory memory;
		// mouse
		struct mouse {
			int x, y;
			int dx, dy, dw;
		} mouse;
		unsigned char input_state[SYS_INPUT_STATE_SIZE];
		// timing
		float dt;
		// system
		int minimized;
		int focused;
		int running;
	} Sys_State;

	static Sys_State __sys_state;

	SYS_DEF void sys_show_cursor(int show);
	SYS_DEF void sys_set_title(const char *title);
	SYS_DEF void sys_set_window_params(int width, int height, int monitor, int fullscreen);
	SYS_DEF void sys_error(const char *error);
	SYS_DEF void sys_message_box(const char *title, const char *message);
	SYS_DEF void sys_toggle_fullscreen(void);
	SYS_DEF void sys_quit(void);
	SYS_DEF double sys_time_now(void);
	SYS_DEF void sys_sleep(int ms);
	SYS_DEF Sys_File sys_file_open(const char *file_name);
	SYS_DEF void sys_file_close(Sys_File file);
	SYS_DEF uint64_t sys_file_read(Sys_File file, uint64_t offset, uint64_t size, void *destination);
	SYS_DEF uint64_t sys_file_write(Sys_File file, uint64_t offset, uint64_t size, void *source);
	SYS_DEF Sys_Memory sys_alloc(size_t size, uint64_t flags);
	SYS_DEF void sys_free(Sys_Memory memory);
	static Sys_Config sys_default_config(void);

#ifdef SYS_INIT_PROC
	Sys_Config SYS_INIT_PROC(int argc, char **argv);
#endif

#ifdef SYS_LOOP_PROC
	void SYS_LOOP_PROC(Sys_State *sys);
#endif

#ifdef SYS_QUIT_PROC
	void SYS_QUIT_PROC(Sys_State *sys);
#endif

	// 
	// 
	//		IMPLEMENTATION 
	// 
	// 
#ifdef SYS_IMPLEMENTATION
#define SYS_IMPLEMENTATION

#ifdef SYS_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif 
#include <windows.h>

#ifdef SYS_OPENGL
#include <gl/gl.h>

#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB        0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_VERSION_ARB         0x2095
	typedef HGLRC WINAPI wgl_create_context_attribs_arb(HDC hDC,
		HGLRC hShareContext,
		const int *attribList);
#endif /* WGL_ARB_create_context */

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1
	typedef int WINAPI wgl_swap_interval_ext(int interval);
	typedef int WINAPI wgl_get_swap_interval_ext(void);
#ifdef WGL_WGLEXT_PROTOTYPES
	int WINAPI wglSwapIntervalEXT(int interval);
	int WINAPI wglGetSwapIntervalEXT(void);
#endif /* WGL_WGLEXT_PROTOTYPES */
#endif /* WGL_EXT_swap_control */

	// todo(rayalan): use wglextensionstringext 
#ifndef WGL_EXT_swap_control_tear
#define WGL_EXT_swap_control_tear 1
#endif /* WGL_EXT_swap_control_tear */

#ifdef SYS_OPENGL_COMPATIBILITY
#define SYS_OPENGL_PROFILE WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
#else
#define SYS_OPENGL_PROFILE WGL_CONTEXT_CORE_PROFILE_BIT_ARB
#endif /* SYS_OPENGL_COMPATIBILITY */
#endif /* SYS_OPENGL */

	SYS_DEF Sys_Memory sys_alloc(size_t size, uint64_t flags) {
		Sys_Memory memory = { 0 };
		MEMORY_BASIC_INFORMATION info = { 0 };
		memory.flags = flags;

#ifdef SYS_DEBUG
		const size_t alloc_size = size + 8192;
#else
		const size_t alloc_size = size;
#endif

		memory.ptr = VirtualAlloc(0, alloc_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		sys_assert(memory.ptr);

		VirtualQuery(memory.ptr, &info, sizeof(MEMORY_BASIC_INFORMATION));
		memory.alloc_size = info.RegionSize;
		memory.usable_size = info.RegionSize;

#ifdef SYS_DEBUG
		DWORD old_protect = 0;
		unsigned char *p = (unsigned char *)memory.ptr;
		VirtualProtect(memory.ptr, 4096, PAGE_NOACCESS, &old_protect);
		VirtualProtect(p + memory.alloc_size - 4096, 4096, PAGE_NOACCESS, &old_protect);
		memory.usable_size = memory.alloc_size - 8192;
		memory.ptr = (void*)(p + 4096);
#endif

		return memory;
	}

	SYS_DEF void sys_free(Sys_Memory memory) {
		// todo(rayalan): asserts
#ifdef SYS_DEBUG
		unsigned char *p = (unsigned char *)memory.ptr;
		sys_assert(p);
		VirtualFree(p - 4096, memory.alloc_size, MEM_RELEASE);
#else
		VirtualFree(memory.ptr, memory.alloc_size, MEM_RELEASE);
#endif
	}

	SYS_DEF Sys_File sys_file_open(const char* file_name) {
		Sys_File file = { 0 };
		HANDLE handle = CreateFileA(file_name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_ALWAYS, 0, 0);
		if (handle != INVALID_HANDLE_VALUE) {
			LARGE_INTEGER size = { 0 };

			if (!GetFileSizeEx(handle, &size)) {
				sys_error("Failed to determine file size.");
			}

			file.ptr = handle;
			file.is_new = (GetLastError() & ERROR_FILE_EXISTS);
			file.size = (uint64_t)size.QuadPart;
		}
		else {
			sys_error("Failed to open file.");
		}
		return file;
	}

	SYS_DEF void sys_file_close(Sys_File file) {
		if (!CloseHandle(file.ptr)) {
			sys_error("Failed to close file.");
		}
	}

	SYS_DEF uint64_t sys_file_read(Sys_File file, uint64_t offset, uint64_t size, void *destination) {
		DWORD bytes_read = 0;
		OVERLAPPED overlapped = { 0 };
		overlapped.Offset = (uint32_t)((offset >> 0) & 0xFFFFFFFF);
		overlapped.OffsetHigh = (uint32_t)((offset >> 32) & 0xFFFFFFFF);

		if (size > 0xFFFFFFFF) {
			sys_error("Exceded Win32 max read size of 4 GB.");
		}
		if (!ReadFile(file.ptr, destination, (uint32_t)size, &bytes_read, &overlapped)) {
			sys_error("Unable to read file");
		}
		if (bytes_read != size) {
			sys_error("Unable to read indicated number of bytes from file.");
		}

		return (uint64_t)bytes_read;
	}

	SYS_DEF uint64_t sys_file_write(Sys_File file, uint64_t offset, uint64_t size, void *source) {
		DWORD bytes_written = 0;
		OVERLAPPED overlapped = { 0 };
		overlapped.Offset = (uint32_t)((offset >> 0) & 0xFFFFFFFF);
		overlapped.OffsetHigh = (uint32_t)((offset >> 32) & 0xFFFFFFFF);

		if (size > 0xFFFFFFFF) {
			sys_error("Exceded Win32 max write size of 4 GB");
		}
		if (!WriteFile(file.ptr, source, (uint32_t)size, &bytes_written, &overlapped)) {
			sys_error("Unable to write file");
		}
		if (bytes_written != size) {
			sys_error("Unable to write indicated number of bytes to file.");
		}

		return (uint64_t)bytes_written;
	}

	SYS_DEF void sys_sleep(int ms) {
		Sleep(ms);
	}

	SYS_DEF double sys_time_now(void) {
		static LARGE_INTEGER freq = { 0 };
		LARGE_INTEGER now;

		if (!freq.QuadPart) {
			QueryPerformanceFrequency(&freq);
		}

		QueryPerformanceCounter(&now);
		return (double)now.QuadPart / freq.QuadPart;
	}

	SYS_DEF void sys_message_box(const char *title, const char *message) {
		MessageBoxA((HWND)__sys_state.window, message, title, MB_OK);
	}

	SYS_DEF void sys_error(const char *message) {
		sys_message_box("Error", message);
		sys_quit();
	}

	static void sys_update_window(LPRECT rect) {
		if (__sys_state.fullscreen) {
			LONG style = GetWindowLong((HWND)__sys_state.window, GWL_STYLE);
			SetWindowLong((HWND)__sys_state.window, GWL_STYLE, style & ~WS_OVERLAPPEDWINDOW);
			SetWindowPos(
				(HWND)__sys_state.window, HWND_TOP,
				rect->left, rect->top,
				rect->right - rect->left,
				rect->bottom - rect->top,
				SWP_NOOWNERZORDER | SWP_FRAMECHANGED
			);
		}
		else {
			DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
#ifndef SYS_NO_RESIZE
#ifndef SYS_NO_MAXIMIZE
				| WS_MAXIMIZEBOX
#endif
				| WS_THICKFRAME
#endif
				; // NOTE(rayalan): maybe this is cleaner if I define SYS_MAXIMIZE_BIT to or's result

			SetWindowLongPtr((HWND)__sys_state.window, GWL_STYLE, style);

			RECT adjust = { 0 };
			adjust.right = __sys_state.width;
			adjust.bottom = __sys_state.height;
			AdjustWindowRect(&adjust, style, FALSE);

			SetWindowPos(
				(HWND)__sys_state.window, 0,
				rect->left + (rect->right - rect->left - adjust.right - adjust.left) / 2,
				rect->top + (rect->bottom - rect->top - adjust.bottom + adjust.top) / 2,
				adjust.right - adjust.left, adjust.bottom - adjust.top,
				SWP_FRAMECHANGED | SWP_SHOWWINDOW
			);
		}
	}

	static int __stdcall sys_monitor_proc(HMONITOR monitor, HDC hdc, LPRECT rect, LPARAM data) {
		sys_unused(hdc);
		static int count = 0;
		if (data == SYS_MONITOR_PRIMARY) {
			MONITORINFO info = { sizeof(info) };
			if (GetMonitorInfo(monitor, &info) && (info.dwFlags & MONITORINFOF_PRIMARY)) {
				sys_update_window(rect);
				__sys_state.monitor = count;
				count = 0;
				return 0;
			}
		}
		else if (count == data) {
			sys_update_window(rect);
			__sys_state.monitor = count;
			count = 0;
			return 0;
		}
		count++;
		return 1;
	}

	SYS_DEF void sys_set_window_params(int width, int height, int monitor, int fullscreen) {
		__sys_state.width = width;
		__sys_state.height = height;
		__sys_state.fullscreen = fullscreen;
		EnumDisplayMonitors(NULL, NULL, sys_monitor_proc, monitor);
	}

	static void sys_create_gl_context(void) {
		HDC device_context = GetDC((HWND)__sys_state.window);
		HGLRC share_context = 0; // todo(rayalan): do something with this?

		PIXELFORMATDESCRIPTOR pfd;
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = SYS_OPENGL_COLOR_BITS;
		pfd.cDepthBits = SYS_OPENGL_DEPTH_BITS;
		pfd.iLayerType = PFD_MAIN_PLANE;

		int chosen_format = ChoosePixelFormat(device_context, &pfd);
		SetPixelFormat(device_context, chosen_format, &pfd);

		HGLRC temp_context = wglCreateContext(device_context);
		wglMakeCurrent(device_context, temp_context);

		wgl_create_context_attribs_arb *__wglCreateContextAttribsARB =
			(wgl_create_context_attribs_arb*)
			wglGetProcAddress("wglCreateContextAttribsARB");
		if (!__wglCreateContextAttribsARB) {
			sys_error("Failed to load function pointer 'wglCreateContextAttribsARB'.");
		}

		int attribs[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, SYS_OPENGL_MAJOR,
			WGL_CONTEXT_MINOR_VERSION_ARB, SYS_OPENGL_MINOR,
#ifdef SYS_DEBUG
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
#endif 
			WGL_CONTEXT_PROFILE_MASK_ARB, SYS_OPENGL_PROFILE,
			0,
		};

		__sys_state.gfx_context = __wglCreateContextAttribsARB(device_context, share_context, attribs);
		sys_assert(__sys_state.gfx_context);

		wgl_swap_interval_ext *__wglSwapIntervalEXT = (wgl_swap_interval_ext*)wglGetProcAddress("wglSwapIntervalEXT");
		sys_assert(__wglSwapIntervalEXT);

		__wglSwapIntervalEXT(1); // TODO(rayalan):

		wglMakeCurrent(device_context, (HGLRC)__sys_state.gfx_context);
		wglDeleteContext(temp_context);
		ReleaseDC((HWND)__sys_state.window, device_context);
	}

	LRESULT __stdcall sys_win_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {
		switch (message) {
		case WM_CLOSE: {
			__sys_state.running = 0;
		} break;
		case WM_ENDSESSION:
		case WM_DESTROY: {

#ifdef SYS_QUIT_PROC
			SYS_QUIT_PROC(&__sys_state);
#endif
			if (__sys_state.memory.ptr) {
				sys_free(__sys_state.memory);
			}

			wglMakeCurrent(0, 0);
			wglDeleteContext((HGLRC)__sys_state.gfx_context);
		} break;
		case WM_SIZE: {
			__sys_state.width = (int)LOWORD(lparam);
			__sys_state.height = (int)HIWORD(lparam);
			__sys_state.minimized = (wparam == SIZE_MINIMIZED) ? 1 : 0;
			HDC device_context = GetDC((HWND)__sys_state.window);
			SwapBuffers(device_context);
			ReleaseDC((HWND)__sys_state.window, device_context);
		} break;
		case WM_SETFOCUS: {
			__sys_state.focused = true;
		} break;
		case WM_KILLFOCUS: {
			ZeroMemory(__sys_state.input_state, SYS_INPUT_STATE_SIZE); // memset
			__sys_state.focused = false;
		} break;
		case WM_INPUT: {
			UINT size;
			static BYTE buffer[40];
			GetRawInputData((HRAWINPUT)lparam, RID_INPUT, (LPVOID)buffer, &size, sizeof(RAWINPUTHEADER));
			RAWINPUT* raw = (RAWINPUT*)buffer;
			if (raw->header.dwType == RIM_TYPEMOUSE) {
				__sys_state.mouse.dx += (int)raw->data.mouse.lLastX;
				__sys_state.mouse.dy += (int)raw->data.mouse.lLastY;
				int flags = raw->data.mouse.usButtonFlags;

				if (flags & RI_MOUSE_LEFT_BUTTON_DOWN) {
					__sys_state.input_state[MOUSE_LEFT] = 1;
				}
				else if (flags & RI_MOUSE_LEFT_BUTTON_UP) {
					__sys_state.input_state[MOUSE_LEFT] = 0;
				}
				else if (flags & RI_MOUSE_MIDDLE_BUTTON_DOWN) {
					__sys_state.input_state[MOUSE_MIDDLE] = 1;
				}
				else if (flags & RI_MOUSE_MIDDLE_BUTTON_UP) {
					__sys_state.input_state[MOUSE_MIDDLE] = 0;
				}
				else if (flags & RI_MOUSE_RIGHT_BUTTON_DOWN) {
					__sys_state.input_state[MOUSE_RIGHT] = 1;
				}
				else if (flags & RI_MOUSE_RIGHT_BUTTON_UP) {
					__sys_state.input_state[MOUSE_RIGHT] = 0;
				}
				else if (flags & RI_MOUSE_BUTTON_1_DOWN) {
					__sys_state.input_state[MOUSE_BUTTON1] = 1;
				}
				else if (flags & RI_MOUSE_BUTTON_1_UP) {
					__sys_state.input_state[MOUSE_BUTTON1] = 0;
				}
				else if (flags & RI_MOUSE_BUTTON_2_DOWN) {
					__sys_state.input_state[MOUSE_BUTTON2] = 1;
				}
				else if (flags & RI_MOUSE_BUTTON_2_UP) {
					__sys_state.input_state[MOUSE_BUTTON2] = 0;
				}
				else if (flags & RI_MOUSE_BUTTON_3_DOWN) {
					__sys_state.input_state[MOUSE_BUTTON3] = 1;
				}
				else if (flags & RI_MOUSE_BUTTON_3_UP) {
					__sys_state.input_state[MOUSE_BUTTON3] = 0;
				}
				else if (flags & RI_MOUSE_BUTTON_4_DOWN) {
					__sys_state.input_state[MOUSE_BUTTON4] = 1;
				}
				else if (flags & RI_MOUSE_BUTTON_4_UP) {
					__sys_state.input_state[MOUSE_BUTTON4] = 0;
				}
				else if (flags & RI_MOUSE_BUTTON_5_DOWN) {
					__sys_state.input_state[MOUSE_BUTTON5] = 1;
				}
				else if (flags & RI_MOUSE_BUTTON_5_UP) {
					__sys_state.input_state[MOUSE_BUTTON5] = 0;
				}
				else if (flags & RI_MOUSE_WHEEL) {
					__sys_state.mouse.dw += (short)raw->data.mouse.usButtonData / 120;
				}
			}
			else if (raw->header.dwType == RIM_TYPEKEYBOARD) {
				UINT virtual_key = raw->data.keyboard.VKey;
				UINT scan_code = raw->data.keyboard.MakeCode;
				UINT flags = raw->data.keyboard.Flags;
				const int e0 = ((flags & RI_KEY_E0) != 0);
				const int e1 = ((flags & RI_KEY_E1) != 0);

				if (virtual_key == 255) { return 0; }
				else if (virtual_key == VK_NUMLOCK) {
					scan_code = (MapVirtualKey(virtual_key, MAPVK_VK_TO_VSC) | 0x100);
				}

				if (e1) {
					if (virtual_key == VK_PAUSE)
						scan_code = 0x45;
					else
						scan_code = MapVirtualKey(virtual_key, MAPVK_VK_TO_VSC);
				}

				switch (virtual_key) {
				case VK_INSERT: {
					if (!e0)
						virtual_key = KEY_NUMPAD0;
				} break;
				case VK_HOME: {
					if (!e0)
						virtual_key = KEY_NUMPAD7;
				} break;
				case VK_END: {
					if (!e0)
						virtual_key = KEY_NUMPAD1;
				} break;
				case VK_PRIOR: {
					if (!e0)
						virtual_key = KEY_NUMPAD9;
				} break;
				case VK_NEXT: {
					if (!e0)
						virtual_key = KEY_NUMPAD3;
				} break;
				case VK_LEFT: {
					if (!e0)
						virtual_key = KEY_NUMPAD4;
				} break;
				case VK_RIGHT: {
					if (!e0)
						virtual_key = KEY_NUMPAD6;
				} break;
				case VK_UP: {
					if (!e0)
						virtual_key = KEY_NUMPAD8;
				} break;
				case VK_DOWN: {
					if (!e0)
						virtual_key = KEY_NUMPAD2;
				} break;
				case VK_CLEAR: {
					if (!e0)
						virtual_key = KEY_NUMPAD5;
				} break;
				}

#ifndef SYS_NO_ALT_ENTER
				if (virtual_key == KEY_ENTER) {
					if (__sys_state.input_state[KEY_ALT] && !__sys_state.input_state[KEY_ENTER] &&
						((flags & RI_KEY_BREAK) == 0))
						sys_toggle_fullscreen();
				}
#endif
				__sys_state.input_state[virtual_key] = !(flags & RI_KEY_BREAK);
			}

		} break;
		default: {
			return DefWindowProcA(window, message, wparam, lparam);
		} break;
		}
		return 0;
	}

	char **CommandLineToArgvA(char *cmd_line, int *argc) {
		char **argv, *_argv;
		unsigned long   len, _argc;
		char   c;
		unsigned long i, j;
		unsigned char in_QM, in_TEXT, in_SPACE;

		for (len = 0; cmd_line[len]; len++) {/* len = strlen(cmd_line) */ }
		i = ((len + 2) / 2) * sizeof(void *) + sizeof(void *);
		argv = (char **)GlobalAlloc(GMEM_FIXED, i + (len + 2) * sizeof(char));
		_argv = (char *)(((unsigned char *)argv) + i);

		_argc = 0;
		argv[_argc] = _argv;
		in_QM = FALSE;
		in_TEXT = FALSE;
		in_SPACE = TRUE;
		i = 0;
		j = 0;
		c = cmd_line[i];

		while (c) {
			if (in_QM) {
				if (c == '\"') {
					in_QM = FALSE;
				}
				else {
					_argv[j] = c;
					j++;
				}
			}
			else {
				switch (c) {
				case '\"': {
					in_QM = TRUE;
					in_TEXT = TRUE;
					if (in_SPACE) {
						argv[_argc] = _argv + j;
						_argc++;
					}
					in_SPACE = FALSE;
				} break;
				case ' ': case '\t': case '\n': case '\r': {
					if (in_TEXT) {
						_argv[j] = '\0';
						j++;
					}
					in_TEXT = FALSE;
					in_SPACE = TRUE;
				} break;
				default: {
					in_TEXT = TRUE;
					if (in_SPACE) {
						argv[_argc] = _argv + j;
						_argc++;
					}
					_argv[j] = c;
					j++;
					in_SPACE = FALSE;
				} break;
				}
			}
			i++;
			c = cmd_line[i];
		}
		_argv[j] = '\0';
		argv[_argc] = NULL;

		(*argc) = _argc;
		return argv;
	}

	int __stdcall WinMain(HINSTANCE instance, HINSTANCE prev, char *cmd_line, int show_code) {
		sys_unused(show_code);
		sys_unused(prev);

		WNDCLASSEXA wc = { 0 };
		wc.cbSize = sizeof(WNDCLASSEXA);
		wc.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
		wc.lpfnWndProc = sys_win_proc;
		wc.lpszClassName = "SysWindowClass";
		wc.hInstance = instance;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		RegisterClassExA(&wc);

		__sys_state.window = CreateWindowExA(
			0,
			wc.lpszClassName,
			"",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			0, 0,
			NULL, NULL,
			instance,
			NULL
		);
		sys_assert(__sys_state.window);

		RAWINPUTDEVICE rid[2];
		// MOUSE
		rid[0].usUsagePage = 0x01;
		rid[0].usUsage = 0x02;
		rid[0].dwFlags = 0;	// We use legacy messages for cursor position
		rid[0].hwndTarget = 0;
		// KEYBOARD
		rid[1].usUsagePage = 0x01;
		rid[1].usUsage = 0x06;
		rid[1].dwFlags = RIDEV_NOLEGACY;
		rid[1].hwndTarget = 0;

		if (RegisterRawInputDevices(rid, 2, sizeof(rid[0])) == FALSE) {
			sys_error("Failed to register raw input devices.");
		}

#ifdef SYS_OPENGL
		sys_create_gl_context();
#endif

		Sys_Config cfg;
#ifdef SYS_INIT_PROC
		int argc;
		char **argv = CommandLineToArgvA(cmd_line, &argc);
		cfg = SYS_INIT_PROC(argc, argv);
#else
		cfg = sys_default_config();
		sys_unused(cmd_line);
#endif
		__sys_state.memory = cfg.memory;

		sys_set_title(cfg.title);
		sys_set_window_params(cfg.width, cfg.height, cfg.monitor, cfg.fullscreen);
		ShowWindow((HWND)__sys_state.window, SW_SHOW);
		__sys_state.running = 1;

		MSG msg = { 0 };
		double t1 = 0.0f;
		double t2 = 0.0f;
		double delta;

		while (__sys_state.running) {
			t1 = sys_time_now();
			delta = t1 - t2;
			__sys_state.dt = t1 - t2;
			__sys_state.mouse.dx = 0;
			__sys_state.mouse.dy = 0;
			__sys_state.mouse.dw = 0;
			POINT point = { 0 };
			GetCursorPos(&point);
			ScreenToClient((HWND)__sys_state.window, &point);
			__sys_state.mouse.x = (int)point.x;
			__sys_state.mouse.y = (int)point.y;

			while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessageA(&msg);
			}

#ifdef SYS_LOOP_PROC
			SYS_LOOP_PROC(&__sys_state);
#endif
			HDC device_context = GetDC((HWND)__sys_state.window);
			SwapBuffers(device_context);
			ReleaseDC((HWND)__sys_state.window, device_context);
			t2 = t1;
		}

		DestroyWindow((HWND)__sys_state.window);

		return 0;
	}

	SYS_DEF void sys_show_cursor(int show) {
		ShowCursor(show);
	}

	SYS_DEF void sys_set_title(const char *title) {
		SetWindowTextA((HWND)__sys_state.window, title);
	}

	SYS_DEF void sys_toggle_fullscreen(void) {
		static WINDOWPLACEMENT prev_pos = { sizeof(prev_pos) };
		DWORD style = (DWORD)GetWindowLong((HWND)__sys_state.window, GWL_STYLE);
		if (style & WS_OVERLAPPEDWINDOW) {
			MONITORINFO info = { sizeof(info) };
			if (GetWindowPlacement((HWND)__sys_state.window, &prev_pos) &&
				GetMonitorInfo(MonitorFromWindow((HWND)__sys_state.window,
					MONITOR_DEFAULTTOPRIMARY), &info)) {
				SetWindowLong((HWND)__sys_state.window, GWL_STYLE,
					(LONG)style & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos((HWND)__sys_state.window, HWND_TOP,
					info.rcMonitor.left, info.rcMonitor.top,
					info.rcMonitor.right - info.rcMonitor.left,
					info.rcMonitor.bottom - info.rcMonitor.top,
					SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
			}
		}
		else {
			SetWindowLong((HWND)__sys_state.window, GWL_STYLE,
				(LONG)style | WS_OVERLAPPEDWINDOW);
			SetWindowPlacement((HWND)__sys_state.window, &prev_pos);
			SetWindowPos((HWND)__sys_state.window, NULL, 0, 0, 0, 0,
				SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
				SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
		}
	}

	SYS_DEF void sys_quit(void) {
		__sys_state.running = 0;
	}

#endif /* SYS_WINDOWS */

	static Sys_Config sys_default_config(void) {
		Sys_Config default_config = { 0 };
		default_config.width = 1280;
		default_config.height = 720;
		default_config.monitor = SYS_MONITOR_PRIMARY;
		default_config.fullscreen = 0;
		default_config.title = "Hello, World!";
		return default_config;
	}

#endif /* SYS_IMPLEMENTATION */
#ifdef __cplusplus
}
#endif
#endif /* SYS_INCLUDE */