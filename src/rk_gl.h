// TODO(rayalan): 
//	constants for common colors i.e. black, blue, white / etc
//	tools for loading any opengl extension	
//		options { different functions for wgl/glx/etc or use string methods to detect which to use using provided function name }
//	macros for making using vaos/etc easier to use 
#ifndef RK_GL_INCLUDE
#define RK_GL_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(__glew_h__) || defined(__GLEW_H__)
#error You must include rk_gl.h before glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error You must include rk_gl.h before gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error You must include rk_gl.h before glext.h
#endif
#if defined(__gltypes_h_)
#error You must include rk_gl.h before gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error You must include rk_gl.h before glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

#ifndef GLAPI
	#define GLAPI extern
#endif

#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void* GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef unsigned short GLhalfARB;
typedef unsigned short GLhalf;
typedef GLint GLfixed;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync* GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY* GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar* message,const void* userParam);
typedef void (APIENTRY* GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar* message,const void* userParam);
typedef void (APIENTRY* GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar* message,void* userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;

#define GL_ALPHA 0x1906
#define GL_ALWAYS 0x0207
#define GL_AND 0x1501
#define GL_AND_INVERTED 0x1504
#define GL_AND_REVERSE 0x1502
#define GL_BACK 0x0405
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_BLEND 0x0BE2
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLUE 0x1905
#define GL_BYTE 0x1400
#define GL_CCW 0x0901
#define GL_CLEAR 0x1500
#define GL_COLOR 0x1800
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_COPY 0x1503
#define GL_COPY_INVERTED 0x150C
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_CW 0x0900
#define GL_DECR 0x1E03
#define GL_DEPTH 0x1801
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_COMPONENT 0x1902
#define GL_DEPTH_FUNC 0x0B74
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DITHER 0x0BD0
#define GL_DONT_CARE 0x1100
#define GL_DOUBLE 0x140A
#define GL_DOUBLEBUFFER 0x0C32
#define GL_DRAW_BUFFER 0x0C01
#define GL_DST_ALPHA 0x0304
#define GL_DST_COLOR 0x0306
#define GL_EQUAL 0x0202
#define GL_EQUIV 0x1509
#define GL_EXTENSIONS 0x1F03
#define GL_FALSE 0
#define GL_FASTEST 0x1101
#define GL_FILL 0x1B02
#define GL_FLOAT 0x1406
#define GL_FRONT 0x0404
#define GL_FRONT_AND_BACK 0x0408
#define GL_FRONT_FACE 0x0B46
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_GEQUAL 0x0206
#define GL_GREATER 0x0204
#define GL_GREEN 0x1904
#define GL_INCR 0x1E02
#define GL_INT 0x1404
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_OPERATION 0x0502
#define GL_INVALID_VALUE 0x0501
#define GL_INVERT 0x150A
#define GL_KEEP 0x1E00
#define GL_LEFT 0x0406
#define GL_LEQUAL 0x0203
#define GL_LESS 0x0201
#define GL_LINE 0x1B01
#define GL_LINEAR 0x2601
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_LINE_STRIP 0x0003
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_NAND 0x150E
#define GL_NEAREST 0x2600
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_NEVER 0x0200
#define GL_NICEST 0x1102
#define GL_NONE 0
#define GL_NOOP 0x1505
#define GL_NOR 0x1508
#define GL_NOTEQUAL 0x0205
#define GL_NO_ERROR 0
#define GL_ONE 1
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_OR 0x1507
#define GL_OR_INVERTED 0x150D
#define GL_OR_REVERSE 0x150B
#define GL_OUT_OF_MEMORY 0x0505
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_POINT 0x1B00
#define GL_POINTS 0x0000
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_R3_G3_B2 0x2A10
#define GL_READ_BUFFER 0x0C02
#define GL_RED 0x1903
#define GL_RENDERER 0x1F01
#define GL_REPEAT 0x2901
#define GL_REPLACE 0x1E01
#define GL_RGB 0x1907
#define GL_RGB10 0x8052
#define GL_RGB10_A2 0x8059
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB5_A1 0x8057
#define GL_RGB8 0x8051
#define GL_RGBA 0x1908
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGBA8 0x8058
#define GL_RIGHT 0x0407
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_SET 0x150F
#define GL_SHORT 0x1402
#define GL_SRC_ALPHA 0x0302
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_SRC_COLOR 0x0300
#define GL_STENCIL 0x1802
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_INDEX 0x1901
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_STEREO 0x0C33
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE 0x1702
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_FAN 0x0006
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRUE 1
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_UNSIGNED_SHORT 0x1403
#define GL_VENDOR 0x1F00
#define GL_VERSION 0x1F02
#define GL_VIEWPORT 0x0BA2
#define GL_XOR 0x1506
#define GL_ZERO 0

#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364

#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_MULTISAMPLE 0x809D
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519

#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_CONSTANT_ALPHA 0x8003
#define GL_CONSTANT_COLOR 0x8001
#define GL_DECR_WRAP 0x8508
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_INCR_WRAP 0x8507
#define GL_MAX 0x8008
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_MIN 0x8007
#define GL_MIRRORED_REPEAT 0x8370
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_LOD_BIAS 0x8501

#define GL_ARRAY_BUFFER 0x8892
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_CURRENT_QUERY 0x8865
#define GL_DYNAMIC_COPY 0x88EA
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_READ_ONLY 0x88B8
#define GL_READ_WRITE 0x88BA
#define GL_SAMPLES_PASSED 0x8914
#define GL_SRC1_ALPHA 0x8589
#define GL_STATIC_COPY 0x88E6
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STREAM_COPY 0x88E2
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_WRITE_ONLY 0x88B9

#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_COMPILE_STATUS 0x8B81
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_DELETE_STATUS 0x8B80
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_LINK_STATUS 0x8B82
#define GL_LOWER_LEFT 0x8CA1
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_SHADER_TYPE 0x8B4F
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_UPPER_LEFT 0x8CA2
#define GL_VALIDATE_STATUS 0x8B83
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_SHADER 0x8B31

#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SRGB_ALPHA 0x8C42

#define GL_BGRA_INTEGER 0x8D9B
#define GL_BGR_INTEGER 0x8D9A
#define GL_BLUE_INTEGER 0x8D96
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_RG 0x8226
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_CONTEXT_FLAGS 0x821E
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH_STENCIL 0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FIXED_ONLY 0x891D
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_FRAMEBUFFER 0x8D40
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_SRGB 0x8DB9
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_GREEN_INTEGER 0x8D95
#define GL_HALF_FLOAT 0x140B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_MAJOR_VERSION 0x821B
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_MAX_SAMPLES 0x8D57
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_MINOR_VERSION 0x821C
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_NUM_EXTENSIONS 0x821D
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_WAIT 0x8E13
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_R16 0x822A
#define GL_R16F 0x822D
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32F 0x822E
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_R8 0x8229
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RED_INTEGER 0x8D94
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RG 0x8227
#define GL_RG16 0x822C
#define GL_RG16F 0x822F
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32F 0x8230
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_RG8 0x822B
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RGB16F 0x881B
#define GL_RGB16I 0x8D89
#define GL_RGB16UI 0x8D77
#define GL_RGB32F 0x8815
#define GL_RGB32I 0x8D83
#define GL_RGB32UI 0x8D71
#define GL_RGB8I 0x8D8F
#define GL_RGB8UI 0x8D7D
#define GL_RGB9_E5 0x8C3D
#define GL_RGBA16F 0x881A
#define GL_RGBA16I 0x8D88
#define GL_RGBA16UI 0x8D76
#define GL_RGBA32F 0x8814
#define GL_RGBA32I 0x8D82
#define GL_RGBA32UI 0x8D70
#define GL_RGBA8I 0x8D8E
#define GL_RGBA8UI 0x8D7C
#define GL_RGBA_INTEGER 0x8D99
#define GL_RGB_INTEGER 0x8D98
#define GL_RG_INTEGER 0x8228
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX16 0x8D49
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD

#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_R16_SNORM 0x8F98
#define GL_R8_SNORM 0x8F94
#define GL_RG16_SNORM 0x8F99
#define GL_RG8_SNORM 0x8F95
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA16_SNORM 0x8F9B
#define GL_RGBA8_SNORM 0x8F97
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8

#define GL_ALREADY_SIGNALED 0x911A
#define GL_CONDITION_SATISFIED 0x911C
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_PROFILE_MASK 0x9126
#define GL_DEPTH_CLAMP 0x864F
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_OBJECT_TYPE 0x9112
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SIGNALED 0x9119
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_SYNC_STATUS 0x9114
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_UNSIGNALED 0x9118
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_WAIT_FAILED 0x911D

extern void (APIENTRY* glBlendFunc)(GLenum sfactor, GLenum dfactor);
extern void (APIENTRY* glClear)(GLbitfield mask);
extern void (APIENTRY* glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRY* glClearDepth)(GLdouble depth);
extern void (APIENTRY* glClearStencil)(GLint s);
extern void (APIENTRY* glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (APIENTRY* glCullFace)(GLenum mode);
extern void (APIENTRY* glDepthFunc)(GLenum func);
extern void (APIENTRY* glDepthMask)(GLboolean flag);
extern void (APIENTRY* glDepthRange)(GLdouble ren_near, GLdouble ren_far);
extern void (APIENTRY* glDisable)(GLenum cap);
extern void (APIENTRY* glDrawBuffer)(GLenum buf);
extern void (APIENTRY* glEnable)(GLenum cap);
extern void (APIENTRY* glFinish)(void);
extern void (APIENTRY* glFlush)(void);
extern void (APIENTRY* glFrontFace)(GLenum mode);
extern void (APIENTRY* glGetBooleanv)(GLenum pname, GLboolean * data);
extern void (APIENTRY* glGetDoublev)(GLenum pname, GLdouble * data);
extern GLenum (APIENTRY* glGetError)(void);
extern void (APIENTRY* glGetFloatv)(GLenum pname, GLfloat * data);
extern void (APIENTRY* glGetIntegerv)(GLenum pname, GLint * data);
extern const GLubyte*  (APIENTRY *glGetString)(GLenum name);
extern void (APIENTRY* glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
extern void (APIENTRY* glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat * params);
extern void (APIENTRY* glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint * params);
extern void (APIENTRY* glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat * params);
extern void (APIENTRY* glGetTexParameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (APIENTRY* glHint)(GLenum target, GLenum mode);
extern GLboolean (APIENTRY* glIsEnabled)(GLenum cap);
extern void (APIENTRY* glLineWidth)(GLfloat width);
extern void (APIENTRY* glLogicOp)(GLenum opcode);
extern void (APIENTRY* glPixelStoref)(GLenum pname, GLfloat param);
extern void (APIENTRY* glPixelStorei)(GLenum pname, GLint param);
extern void (APIENTRY* glPointSize)(GLfloat size);
extern void (APIENTRY* glPolygonMode)(GLenum face, GLenum mode);
extern void (APIENTRY* glReadBuffer)(GLenum src);
extern void (APIENTRY* glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
extern void (APIENTRY* glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY* glStencilFunc)(GLenum func, GLint ref, GLuint mask);
extern void (APIENTRY* glStencilMask)(GLuint mask);
extern void (APIENTRY* glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (APIENTRY* glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (APIENTRY* glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (APIENTRY* glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY* glTexParameterfv)(GLenum target, GLenum pname, const GLfloat * params);
extern void (APIENTRY* glTexParameteri)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY* glTexParameteriv)(GLenum target, GLenum pname, const GLint * params);
extern void (APIENTRY* glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);

extern void (APIENTRY* glBindTexture)(GLenum target, GLuint texture);
extern void (APIENTRY* glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (APIENTRY* glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (APIENTRY* glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRY* glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY* glDeleteTextures)(GLsizei n, const GLuint * textures);
extern void (APIENTRY* glDrawArrays)(GLenum mode, GLint first, GLsizei count);
extern void (APIENTRY* glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void * indices);
extern void (APIENTRY* glGenTextures)(GLsizei n, GLuint * textures);
extern GLboolean (APIENTRY* glIsTexture)(GLuint texture);
extern void (APIENTRY* glPolygonOffset)(GLfloat factor, GLfloat units);
extern void (APIENTRY* glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
extern void (APIENTRY* glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);

extern void (APIENTRY* glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY* glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
extern void (APIENTRY* glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (APIENTRY* glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);

extern void (APIENTRY* glActiveTexture)(GLenum texture);
extern void (APIENTRY* glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
extern void (APIENTRY* glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
extern void (APIENTRY* glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
extern void (APIENTRY* glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
extern void (APIENTRY* glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
extern void (APIENTRY* glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
extern void (APIENTRY* glGetCompressedTexImage)(GLenum target, GLint level, void * img);
extern void (APIENTRY* glSampleCoverage)(GLfloat value, GLboolean invert);

extern void (APIENTRY* glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRY* glBlendEquation)(GLenum mode);
extern void (APIENTRY* glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
extern void (APIENTRY* glMultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
extern void (APIENTRY* glMultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
extern void (APIENTRY* glPointParameterf)(GLenum pname, GLfloat param);
extern void (APIENTRY* glPointParameterfv)(GLenum pname, const GLfloat * params);
extern void (APIENTRY* glPointParameteri)(GLenum pname, GLint param);
extern void (APIENTRY* glPointParameteriv)(GLenum pname, const GLint * params);

extern void (APIENTRY* glBeginQuery)(GLenum target, GLuint id);
extern void (APIENTRY* glBindBuffer)(GLenum target, GLuint buffer);
extern void (APIENTRY* glBufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
extern void (APIENTRY* glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
extern void (APIENTRY* glDeleteBuffers)(GLsizei n, const GLuint * buffers);
extern void (APIENTRY* glDeleteQueries)(GLsizei n, const GLuint * ids);
extern void (APIENTRY* glEndQuery)(GLenum target);
extern void (APIENTRY* glGenBuffers)(GLsizei n, GLuint * buffers);
extern void (APIENTRY* glGenQueries)(GLsizei n, GLuint * ids);
extern void (APIENTRY* glGetBufferParameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (APIENTRY* glGetBufferPointerv)(GLenum target, GLenum pname, void ** params);
extern void (APIENTRY* glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
extern void (APIENTRY* glGetQueryObjectiv)(GLuint id, GLenum pname, GLint * params);
extern void (APIENTRY* glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params);
extern void (APIENTRY* glGetQueryiv)(GLenum target, GLenum pname, GLint * params);
extern GLboolean (APIENTRY* glIsBuffer)(GLuint buffer);
extern GLboolean (APIENTRY* glIsQuery)(GLuint id);
extern void*  (APIENTRY *glMapBuffer)(GLenum target, GLenum access);
extern GLboolean (APIENTRY* glUnmapBuffer)(GLenum target);

extern void (APIENTRY* glAttachShader)(GLuint program, GLuint shader);
extern void (APIENTRY* glBindAttribLocation)(GLuint program, GLuint index, const GLchar * name);
extern void (APIENTRY* glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
extern void (APIENTRY* glCompileShader)(GLuint shader);
extern GLuint (APIENTRY* glCreateProgram)(void);
extern GLuint (APIENTRY* glCreateShader)(GLenum type);
extern void (APIENTRY* glDeleteProgram)(GLuint program);
extern void (APIENTRY* glDeleteShader)(GLuint shader);
extern void (APIENTRY* glDetachShader)(GLuint program, GLuint shader);
extern void (APIENTRY* glDisableVertexAttribArray)(GLuint index);
extern void (APIENTRY* glDrawBuffers)(GLsizei n, const GLenum * bufs);
extern void (APIENTRY* glEnableVertexAttribArray)(GLuint index);
extern void (APIENTRY* glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
extern void (APIENTRY* glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
extern void (APIENTRY* glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
extern GLint (APIENTRY* glGetAttribLocation)(GLuint program, const GLchar * name);
extern void (APIENTRY* glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
extern void (APIENTRY* glGetProgramiv)(GLuint program, GLenum pname, GLint * params);
extern void (APIENTRY* glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
extern void (APIENTRY* glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
extern void (APIENTRY* glGetShaderiv)(GLuint shader, GLenum pname, GLint * params);
extern GLint (APIENTRY* glGetUniformLocation)(GLuint program, const GLchar * name);
extern void (APIENTRY* glGetUniformfv)(GLuint program, GLint location, GLfloat * params);
extern void (APIENTRY* glGetUniformiv)(GLuint program, GLint location, GLint * params);
extern void (APIENTRY* glGetVertexAttribPointerv)(GLuint index, GLenum pname, void ** pointer);
extern void (APIENTRY* glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble * params);
extern void (APIENTRY* glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat * params);
extern void (APIENTRY* glGetVertexAttribiv)(GLuint index, GLenum pname, GLint * params);
extern GLboolean (APIENTRY* glIsProgram)(GLuint program);
extern GLboolean (APIENTRY* glIsShader)(GLuint shader);
extern void (APIENTRY* glLinkProgram)(GLuint program);
extern void (APIENTRY* glShaderSource)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
extern void (APIENTRY* glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
extern void (APIENTRY* glStencilMaskSeparate)(GLenum face, GLuint mask);
extern void (APIENTRY* glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern void (APIENTRY* glUniform1f)(GLint location, GLfloat v0);
extern void (APIENTRY* glUniform1fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (APIENTRY* glUniform1i)(GLint location, GLint v0);
extern void (APIENTRY* glUniform1iv)(GLint location, GLsizei count, const GLint * value);
extern void (APIENTRY* glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRY* glUniform2fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (APIENTRY* glUniform2i)(GLint location, GLint v0, GLint v1);
extern void (APIENTRY* glUniform2iv)(GLint location, GLsizei count, const GLint * value);
extern void (APIENTRY* glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRY* glUniform3fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (APIENTRY* glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRY* glUniform3iv)(GLint location, GLsizei count, const GLint * value);
extern void (APIENTRY* glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRY* glUniform4fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (APIENTRY* glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRY* glUniform4iv)(GLint location, GLsizei count, const GLint * value);
extern void (APIENTRY* glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUseProgram)(GLuint program);
extern void (APIENTRY* glValidateProgram)(GLuint program);
extern void (APIENTRY* glVertexAttrib1d)(GLuint index, GLdouble x);
extern void (APIENTRY* glVertexAttrib1dv)(GLuint index, const GLdouble * v);
extern void (APIENTRY* glVertexAttrib1f)(GLuint index, GLfloat x);
extern void (APIENTRY* glVertexAttrib1fv)(GLuint index, const GLfloat * v);
extern void (APIENTRY* glVertexAttrib1s)(GLuint index, GLshort x);
extern void (APIENTRY* glVertexAttrib1sv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRY* glVertexAttrib2dv)(GLuint index, const GLdouble * v);
extern void (APIENTRY* glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
extern void (APIENTRY* glVertexAttrib2fv)(GLuint index, const GLfloat * v);
extern void (APIENTRY* glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
extern void (APIENTRY* glVertexAttrib2sv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY* glVertexAttrib3dv)(GLuint index, const GLdouble * v);
extern void (APIENTRY* glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY* glVertexAttrib3fv)(GLuint index, const GLfloat * v);
extern void (APIENTRY* glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
extern void (APIENTRY* glVertexAttrib3sv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttrib4Nbv)(GLuint index, const GLbyte * v);
extern void (APIENTRY* glVertexAttrib4Niv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttrib4Nsv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void (APIENTRY* glVertexAttrib4Nubv)(GLuint index, const GLubyte * v);
extern void (APIENTRY* glVertexAttrib4Nuiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttrib4Nusv)(GLuint index, const GLushort * v);
extern void (APIENTRY* glVertexAttrib4bv)(GLuint index, const GLbyte * v);
extern void (APIENTRY* glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY* glVertexAttrib4dv)(GLuint index, const GLdouble * v);
extern void (APIENTRY* glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY* glVertexAttrib4fv)(GLuint index, const GLfloat * v);
extern void (APIENTRY* glVertexAttrib4iv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY* glVertexAttrib4sv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttrib4ubv)(GLuint index, const GLubyte * v);
extern void (APIENTRY* glVertexAttrib4uiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttrib4usv)(GLuint index, const GLushort * v);
extern void (APIENTRY* glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);

extern void (APIENTRY* glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (APIENTRY* glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);

extern void (APIENTRY* glBeginConditionalRender)(GLuint id, GLenum mode);
extern void (APIENTRY* glBeginTransformFeedback)(GLenum primitiveMode);
extern void (APIENTRY* glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
extern void (APIENTRY* glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRY* glBindFragDataLocation)(GLuint program, GLuint color, const GLchar * name);
extern void (APIENTRY* glBindFramebuffer)(GLenum target, GLuint framebuffer);
extern void (APIENTRY* glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
extern void (APIENTRY* glBindVertexArray)(GLuint ren_array);
extern void (APIENTRY* glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern GLenum (APIENTRY* glCheckFramebufferStatus)(GLenum target);
extern void (APIENTRY* glClampColor)(GLenum target, GLenum clamp);
extern void (APIENTRY* glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern void (APIENTRY* glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
extern void (APIENTRY* glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint * value);
extern void (APIENTRY* glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint * value);
extern void (APIENTRY* glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern void (APIENTRY* glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers);
extern void (APIENTRY* glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers);
extern void (APIENTRY* glDeleteVertexArrays)(GLsizei n, const GLuint * arrays);
extern void (APIENTRY* glDisablei)(GLenum target, GLuint index);
extern void (APIENTRY* glEnablei)(GLenum target, GLuint index);
extern void (APIENTRY* glEndConditionalRender)(void);
extern void (APIENTRY* glEndTransformFeedback)(void);
extern void (APIENTRY* glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
extern void (APIENTRY* glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRY* glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY* glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY* glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (APIENTRY* glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (APIENTRY* glGenFramebuffers)(GLsizei n, GLuint * framebuffers);
extern void (APIENTRY* glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers);
extern void (APIENTRY* glGenVertexArrays)(GLsizei n, GLuint * arrays);
extern void (APIENTRY* glGenerateMipmap)(GLenum target);
extern void (APIENTRY* glGetBooleani_v)(GLenum target, GLuint index, GLboolean * data);
extern GLint (APIENTRY* glGetFragDataLocation)(GLuint program, const GLchar * name);
extern void (APIENTRY* glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
extern void (APIENTRY* glGetIntegeri_v)(GLenum target, GLuint index, GLint * data);
extern void (APIENTRY* glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params);
extern const GLubyte*  (APIENTRY *glGetStringi)(GLenum name, GLuint index);
extern void (APIENTRY* glGetTexParameterIiv)(GLenum target, GLenum pname, GLint * params);
extern void (APIENTRY* glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint * params);
extern void (APIENTRY* glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
extern void (APIENTRY* glGetUniformuiv)(GLuint program, GLint location, GLuint * params);
extern void (APIENTRY* glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint * params);
extern void (APIENTRY* glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint * params);
extern GLboolean (APIENTRY* glIsEnabledi)(GLenum target, GLuint index);
extern GLboolean (APIENTRY* glIsFramebuffer)(GLuint framebuffer);
extern GLboolean (APIENTRY* glIsRenderbuffer)(GLuint renderbuffer);
extern GLboolean (APIENTRY* glIsVertexArray)(GLuint ren_array);
extern void*  (APIENTRY *glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (APIENTRY* glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY* glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY* glTexParameterIiv)(GLenum target, GLenum pname, const GLint * params);
extern void (APIENTRY* glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint * params);
extern void (APIENTRY* glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
extern void (APIENTRY* glUniform1ui)(GLint location, GLuint v0);
extern void (APIENTRY* glUniform1uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (APIENTRY* glUniform2ui)(GLint location, GLuint v0, GLuint v1);
extern void (APIENTRY* glUniform2uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (APIENTRY* glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRY* glUniform3uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (APIENTRY* glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRY* glUniform4uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (APIENTRY* glVertexAttribI1i)(GLuint index, GLint x);
extern void (APIENTRY* glVertexAttribI1iv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttribI1ui)(GLuint index, GLuint x);
extern void (APIENTRY* glVertexAttribI1uiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttribI2i)(GLuint index, GLint x, GLint y);
extern void (APIENTRY* glVertexAttribI2iv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
extern void (APIENTRY* glVertexAttribI2uiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
extern void (APIENTRY* glVertexAttribI3iv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
extern void (APIENTRY* glVertexAttribI3uiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttribI4bv)(GLuint index, const GLbyte * v);
extern void (APIENTRY* glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY* glVertexAttribI4iv)(GLuint index, const GLint * v);
extern void (APIENTRY* glVertexAttribI4sv)(GLuint index, const GLshort * v);
extern void (APIENTRY* glVertexAttribI4ubv)(GLuint index, const GLubyte * v);
extern void (APIENTRY* glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRY* glVertexAttribI4uiv)(GLuint index, const GLuint * v);
extern void (APIENTRY* glVertexAttribI4usv)(GLuint index, const GLushort * v);
extern void (APIENTRY* glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);

extern void (APIENTRY* glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (APIENTRY* glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
extern void (APIENTRY* glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
extern void (APIENTRY* glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
extern void (APIENTRY* glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
extern void (APIENTRY* glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
extern void (APIENTRY* glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
extern GLuint (APIENTRY* glGetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName);
extern void (APIENTRY* glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
extern void (APIENTRY* glPrimitiveRestartIndex)(GLuint index);
extern void (APIENTRY* glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
extern void (APIENTRY* glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

extern GLenum (APIENTRY* glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (APIENTRY* glDeleteSync)(GLsync sync);
extern void (APIENTRY* glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern void (APIENTRY* glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
extern void (APIENTRY* glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern GLsync (APIENTRY* glFenceSync)(GLenum condition, GLbitfield flags);
extern void (APIENTRY* glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRY* glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params);
extern void (APIENTRY* glGetInteger64i_v)(GLenum target, GLuint index, GLint64 * data);
extern void (APIENTRY* glGetInteger64v)(GLenum pname, GLint64 * data);
extern void (APIENTRY* glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val);
extern void (APIENTRY* glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
extern GLboolean (APIENTRY* glIsSync)(GLsync sync);
extern void (APIENTRY* glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
extern void (APIENTRY* glProvokingVertex)(GLenum mode);
extern void (APIENTRY* glSampleMaski)(GLuint maskNumber, GLbitfield mask);
extern void (APIENTRY* glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRY* glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRY* glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);

int glLoadFunctions(void);

//=============================================================================
//
//
//	IMPLEMENTATION
//
//
//=============================================================================
#ifdef RK_GL_IMPLEMENTATION

#if defined(__APPLE__)
#include <dlfcn.h>

static void* glAppleGetProcAddress(const char* name)
{
	static void* image = NULL;
	
	if (NULL == image)
		image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);

	return (image ? dlsym(image, name) : NULL);
}
#endif /* __APPLE__*/

#if defined(_WIN32)

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4055)
#pragma warning(disable: 4211)
#pragma warning(disable: 4054)
#pragma warning(disable: 4996)
#pragma warning(disable: 4047) // todo(rayalan): should be able to remove this?
#endif

static int glTestPointer(const PROC pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

static PROC glWinGetProcAddress(const char* name)
{
	HMODULE glMod = NULL;
	PROC pFunc = wglGetProcAddress((LPCSTR)name);
	if(glTestPointer(pFunc))
	{
		return pFunc;
	}
	glMod = GetModuleHandleA("OpenGL32.dll");
	return (PROC)GetProcAddress(glMod, (LPCSTR)name);
}
	
#define glAnyGetProcAddress(name) glWinGetProcAddress(name)
#else
	#if defined(__APPLE__)
		#define glAnyGetProcAddress(name) glAppleGetProcAddress(name)
	#else
		#include <GL/glx.h>
		#define glAnyGetProcAddress(name) (*glXGetProcAddressARB)((const GLubyte*)name)
	#endif
#endif

void (APIENTRY* glBlendFunc)(GLenum sfactor, GLenum dfactor) = NULL;
void (APIENTRY* glClear)(GLbitfield mask) = NULL;
void (APIENTRY* glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
void (APIENTRY* glClearDepth)(GLdouble depth) = NULL;
void (APIENTRY* glClearStencil)(GLint s) = NULL;
void (APIENTRY* glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = NULL;
void (APIENTRY* glCullFace)(GLenum mode) = NULL;
void (APIENTRY* glDepthFunc)(GLenum func) = NULL;
void (APIENTRY* glDepthMask)(GLboolean flag) = NULL;
void (APIENTRY* glDepthRange)(GLdouble ren_near, GLdouble ren_far) = NULL;
void (APIENTRY* glDisable)(GLenum cap) = NULL;
void (APIENTRY* glDrawBuffer)(GLenum buf) = NULL;
void (APIENTRY* glEnable)(GLenum cap) = NULL;
void (APIENTRY* glFinish)(void) = NULL;
void (APIENTRY* glFlush)(void) = NULL;
void (APIENTRY* glFrontFace)(GLenum mode) = NULL;
void (APIENTRY* glGetBooleanv)(GLenum pname, GLboolean* data) = NULL;
void (APIENTRY* glGetDoublev)(GLenum pname, GLdouble* data) = NULL;
GLenum (APIENTRY* glGetError)(void) = NULL;
void (APIENTRY* glGetFloatv)(GLenum pname, GLfloat* data) = NULL;
void (APIENTRY* glGetIntegerv)(GLenum pname, GLint* data) = NULL;
const GLubyte*  (APIENTRY*glGetString)(GLenum name) = NULL;
void (APIENTRY* glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) = NULL;
void (APIENTRY* glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat* params) = NULL;
void (APIENTRY* glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params) = NULL;
void (APIENTRY* glGetTexParameteriv)(GLenum target, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glHint)(GLenum target, GLenum mode) = NULL;
GLboolean (APIENTRY* glIsEnabled)(GLenum cap) = NULL;
void (APIENTRY* glLineWidth)(GLfloat width) = NULL;
void (APIENTRY* glLogicOp)(GLenum opcode) = NULL;
void (APIENTRY* glPixelStoref)(GLenum pname, GLfloat param) = NULL;
void (APIENTRY* glPixelStorei)(GLenum pname, GLint param) = NULL;
void (APIENTRY* glPointSize)(GLfloat size) = NULL;
void (APIENTRY* glPolygonMode)(GLenum face, GLenum mode) = NULL;
void (APIENTRY* glReadBuffer)(GLenum src) = NULL;
void (APIENTRY* glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) = NULL;
void (APIENTRY* glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (APIENTRY* glStencilFunc)(GLenum func, GLint ref, GLuint mask) = NULL;
void (APIENTRY* glStencilMask)(GLuint mask) = NULL;
void (APIENTRY* glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = NULL;
void (APIENTRY* glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) = NULL;
void (APIENTRY* glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) = NULL;
void (APIENTRY* glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = NULL;
void (APIENTRY* glTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params) = NULL;
void (APIENTRY* glTexParameteri)(GLenum target, GLenum pname, GLint param) = NULL;
void (APIENTRY* glTexParameteriv)(GLenum target, GLenum pname, const GLint* params) = NULL;
void (APIENTRY* glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;

void (APIENTRY* glBindTexture)(GLenum target, GLuint texture) = NULL;
void (APIENTRY* glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
void (APIENTRY* glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
void (APIENTRY* glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
void (APIENTRY* glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (APIENTRY* glDeleteTextures)(GLsizei n, const GLuint* textures) = NULL;
void (APIENTRY* glDrawArrays)(GLenum mode, GLint first, GLsizei count) = NULL;
void (APIENTRY* glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void* indices) = NULL;
void (APIENTRY* glGenTextures)(GLsizei n, GLuint* textures) = NULL;
GLboolean (APIENTRY* glIsTexture)(GLuint texture) = NULL;
void (APIENTRY* glPolygonOffset)(GLfloat factor, GLfloat units) = NULL;
void (APIENTRY* glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) = NULL;
void (APIENTRY* glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) = NULL;

void (APIENTRY* glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (APIENTRY* glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) = NULL;
void (APIENTRY* glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) = NULL;
void (APIENTRY* glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) = NULL;

void (APIENTRY* glActiveTexture)(GLenum texture) = NULL;
void (APIENTRY* glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) = NULL;
void (APIENTRY* glGetCompressedTexImage)(GLenum target, GLint level, void* img) = NULL;
void (APIENTRY* glSampleCoverage)(GLfloat value, GLboolean invert) = NULL;

void (APIENTRY* glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
void (APIENTRY* glBlendEquation)(GLenum mode) = NULL;
void (APIENTRY* glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = NULL;
void (APIENTRY* glMultiDrawArrays)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount) = NULL;
void (APIENTRY* glMultiDrawElements)(GLenum mode, const GLsizei* count, GLenum type, const void*const* indices, GLsizei drawcount) = NULL;
void (APIENTRY* glPointParameterf)(GLenum pname, GLfloat param) = NULL;
void (APIENTRY* glPointParameterfv)(GLenum pname, const GLfloat* params) = NULL;
void (APIENTRY* glPointParameteri)(GLenum pname, GLint param) = NULL;
void (APIENTRY* glPointParameteriv)(GLenum pname, const GLint* params) = NULL;

void (APIENTRY* glBeginQuery)(GLenum target, GLuint id) = NULL;
void (APIENTRY* glBindBuffer)(GLenum target, GLuint buffer) = NULL;
void (APIENTRY* glBufferData)(GLenum target, GLsizeiptr size, const void* data, GLenum usage) = NULL;
void (APIENTRY* glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) = NULL;
void (APIENTRY* glDeleteBuffers)(GLsizei n, const GLuint* buffers) = NULL;
void (APIENTRY* glDeleteQueries)(GLsizei n, const GLuint* ids) = NULL;
void (APIENTRY* glEndQuery)(GLenum target) = NULL;
void (APIENTRY* glGenBuffers)(GLsizei n, GLuint* buffers) = NULL;
void (APIENTRY* glGenQueries)(GLsizei n, GLuint* ids) = NULL;
void (APIENTRY* glGetBufferParameteriv)(GLenum target, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetBufferPointerv)(GLenum target, GLenum pname, void** params) = NULL;
void (APIENTRY* glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void* data) = NULL;
void (APIENTRY* glGetQueryObjectiv)(GLuint id, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint* params) = NULL;
void (APIENTRY* glGetQueryiv)(GLenum target, GLenum pname, GLint* params) = NULL;
GLboolean (APIENTRY* glIsBuffer)(GLuint buffer) = NULL;
GLboolean (APIENTRY* glIsQuery)(GLuint id) = NULL;
void*  (APIENTRY* glMapBuffer)(GLenum target, GLenum access) = NULL;
GLboolean (APIENTRY* glUnmapBuffer)(GLenum target) = NULL;

void (APIENTRY* glAttachShader)(GLuint program, GLuint shader) = NULL;
void (APIENTRY* glBindAttribLocation)(GLuint program, GLuint index, const GLchar* name) = NULL;
void (APIENTRY* glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) = NULL;
void (APIENTRY* glCompileShader)(GLuint shader) = NULL;
GLuint (APIENTRY* glCreateProgram)(void) = NULL;
GLuint (APIENTRY* glCreateShader)(GLenum type) = NULL;
void (APIENTRY* glDeleteProgram)(GLuint program) = NULL;
void (APIENTRY* glDeleteShader)(GLuint shader) = NULL;
void (APIENTRY* glDetachShader)(GLuint program, GLuint shader) = NULL;
void (APIENTRY* glDisableVertexAttribArray)(GLuint index) = NULL;
void (APIENTRY* glDrawBuffers)(GLsizei n, const GLenum* bufs) = NULL;
void (APIENTRY* glEnableVertexAttribArray)(GLuint index) = NULL;
void (APIENTRY* glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) = NULL;
void (APIENTRY* glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) = NULL;
void (APIENTRY* glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) = NULL;
GLint (APIENTRY* glGetAttribLocation)(GLuint program, const GLchar* name) = NULL;
void (APIENTRY* glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) = NULL;
void (APIENTRY* glGetProgramiv)(GLuint program, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) = NULL;
void (APIENTRY* glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) = NULL;
void (APIENTRY* glGetShaderiv)(GLuint shader, GLenum pname, GLint* params) = NULL;
GLint (APIENTRY* glGetUniformLocation)(GLuint program, const GLchar* name) = NULL;
void (APIENTRY* glGetUniformfv)(GLuint program, GLint location, GLfloat* params) = NULL;
void (APIENTRY* glGetUniformiv)(GLuint program, GLint location, GLint* params) = NULL;
void (APIENTRY* glGetVertexAttribPointerv)(GLuint index, GLenum pname, void** pointer) = NULL;
void (APIENTRY* glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble* params) = NULL;
void (APIENTRY* glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat* params) = NULL;
void (APIENTRY* glGetVertexAttribiv)(GLuint index, GLenum pname, GLint* params) = NULL;
GLboolean (APIENTRY* glIsProgram)(GLuint program) = NULL;
GLboolean (APIENTRY* glIsShader)(GLuint shader) = NULL;
void (APIENTRY* glLinkProgram)(GLuint program) = NULL;
void (APIENTRY* glShaderSource)(GLuint shader, GLsizei count, const GLchar*const* string, const GLint* length) = NULL;
void (APIENTRY* glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = NULL;
void (APIENTRY* glStencilMaskSeparate)(GLenum face, GLuint mask) = NULL;
void (APIENTRY* glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = NULL;
void (APIENTRY* glUniform1f)(GLint location, GLfloat v0) = NULL;
void (APIENTRY* glUniform1fv)(GLint location, GLsizei count, const GLfloat* value) = NULL;
void (APIENTRY* glUniform1i)(GLint location, GLint v0) = NULL;
void (APIENTRY* glUniform1iv)(GLint location, GLsizei count, const GLint* value) = NULL;
void (APIENTRY* glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = NULL;
void (APIENTRY* glUniform2fv)(GLint location, GLsizei count, const GLfloat* value) = NULL;
void (APIENTRY* glUniform2i)(GLint location, GLint v0, GLint v1) = NULL;
void (APIENTRY* glUniform2iv)(GLint location, GLsizei count, const GLint* value) = NULL;
void (APIENTRY* glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
void (APIENTRY* glUniform3fv)(GLint location, GLsizei count, const GLfloat* value) = NULL;
void (APIENTRY* glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = NULL;
void (APIENTRY* glUniform3iv)(GLint location, GLsizei count, const GLint* value) = NULL;
void (APIENTRY* glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
void (APIENTRY* glUniform4fv)(GLint location, GLsizei count, const GLfloat* value) = NULL;
void (APIENTRY* glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
void (APIENTRY* glUniform4iv)(GLint location, GLsizei count, const GLint* value) = NULL;
void (APIENTRY* glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUseProgram)(GLuint program) = NULL;
void (APIENTRY* glValidateProgram)(GLuint program) = NULL;
void (APIENTRY* glVertexAttrib1d)(GLuint index, GLdouble x) = NULL;
void (APIENTRY* glVertexAttrib1dv)(GLuint index, const GLdouble* v) = NULL;
void (APIENTRY* glVertexAttrib1f)(GLuint index, GLfloat x) = NULL;
void (APIENTRY* glVertexAttrib1fv)(GLuint index, const GLfloat* v) = NULL;
void (APIENTRY* glVertexAttrib1s)(GLuint index, GLshort x) = NULL;
void (APIENTRY* glVertexAttrib1sv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (APIENTRY* glVertexAttrib2dv)(GLuint index, const GLdouble* v) = NULL;
void (APIENTRY* glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = NULL;
void (APIENTRY* glVertexAttrib2fv)(GLuint index, const GLfloat* v) = NULL;
void (APIENTRY* glVertexAttrib2s)(GLuint index, GLshort x, GLshort y) = NULL;
void (APIENTRY* glVertexAttrib2sv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (APIENTRY* glVertexAttrib3dv)(GLuint index, const GLdouble* v) = NULL;
void (APIENTRY* glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (APIENTRY* glVertexAttrib3fv)(GLuint index, const GLfloat* v) = NULL;
void (APIENTRY* glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z) = NULL;
void (APIENTRY* glVertexAttrib3sv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttrib4Nbv)(GLuint index, const GLbyte* v) = NULL;
void (APIENTRY* glVertexAttrib4Niv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttrib4Nsv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = NULL;
void (APIENTRY* glVertexAttrib4Nubv)(GLuint index, const GLubyte* v) = NULL;
void (APIENTRY* glVertexAttrib4Nuiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttrib4Nusv)(GLuint index, const GLushort* v) = NULL;
void (APIENTRY* glVertexAttrib4bv)(GLuint index, const GLbyte* v) = NULL;
void (APIENTRY* glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (APIENTRY* glVertexAttrib4dv)(GLuint index, const GLdouble* v) = NULL;
void (APIENTRY* glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (APIENTRY* glVertexAttrib4fv)(GLuint index, const GLfloat* v) = NULL;
void (APIENTRY* glVertexAttrib4iv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
void (APIENTRY* glVertexAttrib4sv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttrib4ubv)(GLuint index, const GLubyte* v) = NULL;
void (APIENTRY* glVertexAttrib4uiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttrib4usv)(GLuint index, const GLushort* v) = NULL;
void (APIENTRY* glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) = NULL;

void (APIENTRY* glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;
void (APIENTRY* glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) = NULL;

void (APIENTRY* glBeginConditionalRender)(GLuint id, GLenum mode) = NULL;
void (APIENTRY* glBeginTransformFeedback)(GLenum primitiveMode) = NULL;
void (APIENTRY* glBindBufferBase)(GLenum target, GLuint index, GLuint buffer) = NULL;
void (APIENTRY* glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
void (APIENTRY* glBindFragDataLocation)(GLuint program, GLuint color, const GLchar* name) = NULL;
void (APIENTRY* glBindFramebuffer)(GLenum target, GLuint framebuffer) = NULL;
void (APIENTRY* glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = NULL;
void (APIENTRY* glBindVertexArray)(GLuint ren_array) = NULL;
void (APIENTRY* glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = NULL;
GLenum (APIENTRY* glCheckFramebufferStatus)(GLenum target) = NULL;
void (APIENTRY* glClampColor)(GLenum target, GLenum clamp) = NULL;
void (APIENTRY* glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) = NULL;
void (APIENTRY* glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat* value) = NULL;
void (APIENTRY* glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint* value) = NULL;
void (APIENTRY* glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint* value) = NULL;
void (APIENTRY* glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = NULL;
void (APIENTRY* glDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers) = NULL;
void (APIENTRY* glDeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers) = NULL;
void (APIENTRY* glDeleteVertexArrays)(GLsizei n, const GLuint* arrays) = NULL;
void (APIENTRY* glDisablei)(GLenum target, GLuint index) = NULL;
void (APIENTRY* glEnablei)(GLenum target, GLuint index) = NULL;
void (APIENTRY* glEndConditionalRender)(void) = NULL;
void (APIENTRY* glEndTransformFeedback)(void) = NULL;
void (APIENTRY* glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length) = NULL;
void (APIENTRY* glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
void (APIENTRY* glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (APIENTRY* glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (APIENTRY* glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = NULL;
void (APIENTRY* glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
void (APIENTRY* glGenFramebuffers)(GLsizei n, GLuint* framebuffers) = NULL;
void (APIENTRY* glGenRenderbuffers)(GLsizei n, GLuint* renderbuffers) = NULL;
void (APIENTRY* glGenVertexArrays)(GLsizei n, GLuint* arrays) = NULL;
void (APIENTRY* glGenerateMipmap)(GLenum target) = NULL;
void (APIENTRY* glGetBooleani_v)(GLenum target, GLuint index, GLboolean* data) = NULL;
GLint (APIENTRY* glGetFragDataLocation)(GLuint program, const GLchar* name) = NULL;
void (APIENTRY* glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetIntegeri_v)(GLenum target, GLuint index, GLint* data) = NULL;
void (APIENTRY* glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint* params) = NULL;
const GLubyte*  (APIENTRY*glGetStringi)(GLenum name, GLuint index) = NULL;
void (APIENTRY* glGetTexParameterIiv)(GLenum target, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint* params) = NULL;
void (APIENTRY* glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) = NULL;
void (APIENTRY* glGetUniformuiv)(GLuint program, GLint location, GLuint* params) = NULL;
void (APIENTRY* glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint* params) = NULL;
GLboolean (APIENTRY* glIsEnabledi)(GLenum target, GLuint index) = NULL;
GLboolean (APIENTRY* glIsFramebuffer)(GLuint framebuffer) = NULL;
GLboolean (APIENTRY* glIsRenderbuffer)(GLuint renderbuffer) = NULL;
GLboolean (APIENTRY* glIsVertexArray)(GLuint ren_array) = NULL;
void*  (APIENTRY*glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) = NULL;
void (APIENTRY* glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (APIENTRY* glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (APIENTRY* glTexParameterIiv)(GLenum target, GLenum pname, const GLint* params) = NULL;
void (APIENTRY* glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint* params) = NULL;
void (APIENTRY* glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar*const* varyings, GLenum bufferMode) = NULL;
void (APIENTRY* glUniform1ui)(GLint location, GLuint v0) = NULL;
void (APIENTRY* glUniform1uiv)(GLint location, GLsizei count, const GLuint* value) = NULL;
void (APIENTRY* glUniform2ui)(GLint location, GLuint v0, GLuint v1) = NULL;
void (APIENTRY* glUniform2uiv)(GLint location, GLsizei count, const GLuint* value) = NULL;
void (APIENTRY* glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
void (APIENTRY* glUniform3uiv)(GLint location, GLsizei count, const GLuint* value) = NULL;
void (APIENTRY* glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
void (APIENTRY* glUniform4uiv)(GLint location, GLsizei count, const GLuint* value) = NULL;
void (APIENTRY* glVertexAttribI1i)(GLuint index, GLint x) = NULL;
void (APIENTRY* glVertexAttribI1iv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttribI1ui)(GLuint index, GLuint x) = NULL;
void (APIENTRY* glVertexAttribI1uiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttribI2i)(GLuint index, GLint x, GLint y) = NULL;
void (APIENTRY* glVertexAttribI2iv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y) = NULL;
void (APIENTRY* glVertexAttribI2uiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z) = NULL;
void (APIENTRY* glVertexAttribI3iv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z) = NULL;
void (APIENTRY* glVertexAttribI3uiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttribI4bv)(GLuint index, const GLbyte* v) = NULL;
void (APIENTRY* glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
void (APIENTRY* glVertexAttribI4iv)(GLuint index, const GLint* v) = NULL;
void (APIENTRY* glVertexAttribI4sv)(GLuint index, const GLshort* v) = NULL;
void (APIENTRY* glVertexAttribI4ubv)(GLuint index, const GLubyte* v) = NULL;
void (APIENTRY* glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
void (APIENTRY* glVertexAttribI4uiv)(GLuint index, const GLuint* v) = NULL;
void (APIENTRY* glVertexAttribI4usv)(GLuint index, const GLushort* v) = NULL;
void (APIENTRY* glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) = NULL;

void (APIENTRY* glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = NULL;
void (APIENTRY* glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = NULL;
void (APIENTRY* glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) = NULL;
void (APIENTRY* glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) = NULL;
void (APIENTRY* glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) = NULL;
void (APIENTRY* glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) = NULL;
void (APIENTRY* glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) = NULL;
GLuint (APIENTRY* glGetUniformBlockIndex)(GLuint program, const GLchar* uniformBlockName) = NULL;
void (APIENTRY* glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar*const* uniformNames, GLuint* uniformIndices) = NULL;
void (APIENTRY* glPrimitiveRestartIndex)(GLuint index) = NULL;
void (APIENTRY* glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer) = NULL;
void (APIENTRY* glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = NULL;

GLenum (APIENTRY* glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;
void (APIENTRY* glDeleteSync)(GLsync sync) = NULL;
void (APIENTRY* glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) = NULL;
void (APIENTRY* glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) = NULL;
void (APIENTRY* glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) = NULL;
GLsync (APIENTRY* glFenceSync)(GLenum condition, GLbitfield flags) = NULL;
void (APIENTRY* glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level) = NULL;
void (APIENTRY* glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64* params) = NULL;
void (APIENTRY* glGetInteger64i_v)(GLenum target, GLuint index, GLint64* data) = NULL;
void (APIENTRY* glGetInteger64v)(GLenum pname, GLint64* data) = NULL;
void (APIENTRY* glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat* val) = NULL;
void (APIENTRY* glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values) = NULL;
GLboolean (APIENTRY* glIsSync)(GLsync sync) = NULL;
void (APIENTRY* glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei* count, GLenum type, const void*const* indices, GLsizei drawcount, const GLint* basevertex) = NULL;
void (APIENTRY* glProvokingVertex)(GLenum mode) = NULL;
void (APIENTRY* glSampleMaski)(GLuint maskNumber, GLbitfield mask) = NULL;
void (APIENTRY* glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
void (APIENTRY* glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;
void (APIENTRY* glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;

static int glLoadFunctions(void)
{
	glGetIntegerv = (void (APIENTRY*)(GLenum, GLint*))glAnyGetProcAddress("glGetIntegerv");
	if(!glGetIntegerv) return NULL;
	glGetStringi = (const GLubyte* (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glGetStringi");
	if(!glGetStringi) return NULL;	
	glBlendFunc = (void (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glBlendFunc");
	if(!glBlendFunc) return NULL;
	glClear = (void (APIENTRY*)(GLbitfield))glAnyGetProcAddress("glClear");
	if(!glClear) return NULL;
	glClearColor = (void (APIENTRY*)(GLfloat, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glClearColor");
	if(!glClearColor) return NULL;
	glClearDepth = (void (APIENTRY*)(GLdouble))glAnyGetProcAddress("glClearDepth");
	if(!glClearDepth) return NULL;
	glClearStencil = (void (APIENTRY*)(GLint))glAnyGetProcAddress("glClearStencil");
	if(!glClearStencil) return NULL;
	glColorMask = (void (APIENTRY*)(GLboolean, GLboolean, GLboolean, GLboolean))glAnyGetProcAddress("glColorMask");
	if(!glColorMask) return NULL;
	glCullFace = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glCullFace");
	if(!glCullFace) return NULL;
	glDepthFunc = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glDepthFunc");
	if(!glDepthFunc) return NULL;
	glDepthMask = (void (APIENTRY*)(GLboolean))glAnyGetProcAddress("glDepthMask");
	if(!glDepthMask) return NULL;
	glDepthRange = (void (APIENTRY*)(GLdouble, GLdouble))glAnyGetProcAddress("glDepthRange");
	if(!glDepthRange) return NULL;
	glDisable = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glDisable");
	if(!glDisable) return NULL;
	glDrawBuffer = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glDrawBuffer");
	if(!glDrawBuffer) return NULL;
	glEnable = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glEnable");
	if(!glEnable) return NULL;
	glFinish = (void (APIENTRY*)(void))glAnyGetProcAddress("glFinish");
	if(!glFinish) return NULL;
	glFlush = (void (APIENTRY*)(void))glAnyGetProcAddress("glFlush");
	if(!glFlush) return NULL;
	glFrontFace = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glFrontFace");
	if(!glFrontFace) return NULL;
	glGetBooleanv = (void (APIENTRY*)(GLenum, GLboolean*))glAnyGetProcAddress("glGetBooleanv");
	if(!glGetBooleanv) return NULL;
	glGetDoublev = (void (APIENTRY*)(GLenum, GLdouble*))glAnyGetProcAddress("glGetDoublev");
	if(!glGetDoublev) return NULL;
	glGetError = (GLenum (APIENTRY*)(void))glAnyGetProcAddress("glGetError");
	if(!glGetError) return NULL;
	glGetFloatv = (void (APIENTRY*)(GLenum, GLfloat*))glAnyGetProcAddress("glGetFloatv");
	if(!glGetFloatv) return NULL;
	glGetIntegerv = (void (APIENTRY*)(GLenum, GLint*))glAnyGetProcAddress("glGetIntegerv");
	if(!glGetIntegerv) return NULL;
	glGetString = (const GLubyte* (APIENTRY*)(GLenum))glAnyGetProcAddress("glGetString");
	if(!glGetString) return NULL;
	glGetTexImage = (void (APIENTRY*)(GLenum, GLint, GLenum, GLenum, void*))glAnyGetProcAddress("glGetTexImage");
	if(!glGetTexImage) return NULL;
	glGetTexLevelParameterfv = (void (APIENTRY*)(GLenum, GLint, GLenum, GLfloat*))glAnyGetProcAddress("glGetTexLevelParameterfv");
	if(!glGetTexLevelParameterfv) return NULL;
	glGetTexLevelParameteriv = (void (APIENTRY*)(GLenum, GLint, GLenum, GLint*))glAnyGetProcAddress("glGetTexLevelParameteriv");
	if(!glGetTexLevelParameteriv) return NULL;
	glGetTexParameterfv = (void (APIENTRY*)(GLenum, GLenum, GLfloat*))glAnyGetProcAddress("glGetTexParameterfv");
	if(!glGetTexParameterfv) return NULL;
	glGetTexParameteriv = (void (APIENTRY*)(GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetTexParameteriv");
	if(!glGetTexParameteriv) return NULL;
	glHint = (void (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glHint");
	if(!glHint) return NULL;
	glIsEnabled = (GLboolean (APIENTRY*)(GLenum))glAnyGetProcAddress("glIsEnabled");
	if(!glIsEnabled) return NULL;
	glLineWidth = (void (APIENTRY*)(GLfloat))glAnyGetProcAddress("glLineWidth");
	if(!glLineWidth) return NULL;
	glLogicOp = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glLogicOp");
	if(!glLogicOp) return NULL;
	glPixelStoref = (void (APIENTRY*)(GLenum, GLfloat))glAnyGetProcAddress("glPixelStoref");
	if(!glPixelStoref) return NULL;
	glPixelStorei = (void (APIENTRY*)(GLenum, GLint))glAnyGetProcAddress("glPixelStorei");
	if(!glPixelStorei) return NULL;
	glPointSize = (void (APIENTRY*)(GLfloat))glAnyGetProcAddress("glPointSize");
	if(!glPointSize) return NULL;
	glPolygonMode = (void (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glPolygonMode");
	if(!glPolygonMode) return NULL;
	glReadBuffer = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glReadBuffer");
	if(!glReadBuffer) return NULL;
	glReadPixels = (void (APIENTRY*)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void*))glAnyGetProcAddress("glReadPixels");
	if(!glReadPixels) return NULL;
	glScissor = (void (APIENTRY*)(GLint, GLint, GLsizei, GLsizei))glAnyGetProcAddress("glScissor");
	if(!glScissor) return NULL;
	glStencilFunc = (void (APIENTRY*)(GLenum, GLint, GLuint))glAnyGetProcAddress("glStencilFunc");
	if(!glStencilFunc) return NULL;
	glStencilMask = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glStencilMask");
	if(!glStencilMask) return NULL;
	glStencilOp = (void (APIENTRY*)(GLenum, GLenum, GLenum))glAnyGetProcAddress("glStencilOp");
	if(!glStencilOp) return NULL;
	glTexImage1D = (void (APIENTRY*)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexImage1D");
	if(!glTexImage1D) return NULL;
	glTexImage2D = (void (APIENTRY*)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexImage2D");
	if(!glTexImage2D) return NULL;
	glTexParameterf = (void (APIENTRY*)(GLenum, GLenum, GLfloat))glAnyGetProcAddress("glTexParameterf");
	if(!glTexParameterf) return NULL;
	glTexParameterfv = (void (APIENTRY*)(GLenum, GLenum, const GLfloat*))glAnyGetProcAddress("glTexParameterfv");
	if(!glTexParameterfv) return NULL;
	glTexParameteri = (void (APIENTRY*)(GLenum, GLenum, GLint))glAnyGetProcAddress("glTexParameteri");
	if(!glTexParameteri) return NULL;
	glTexParameteriv = (void (APIENTRY*)(GLenum, GLenum, const GLint*))glAnyGetProcAddress("glTexParameteriv");
	if(!glTexParameteriv) return NULL;
	glViewport = (void (APIENTRY*)(GLint, GLint, GLsizei, GLsizei))glAnyGetProcAddress("glViewport");
	if(!glViewport) return NULL;
	glBindTexture = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glBindTexture");
	if(!glBindTexture) return NULL;
	glCopyTexImage1D = (void (APIENTRY*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))glAnyGetProcAddress("glCopyTexImage1D");
	if(!glCopyTexImage1D) return NULL;
	glCopyTexImage2D = (void (APIENTRY*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))glAnyGetProcAddress("glCopyTexImage2D");
	if(!glCopyTexImage2D) return NULL;
	glCopyTexSubImage1D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLint, GLsizei))glAnyGetProcAddress("glCopyTexSubImage1D");
	if(!glCopyTexSubImage1D) return NULL;
	glCopyTexSubImage2D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))glAnyGetProcAddress("glCopyTexSubImage2D");
	if(!glCopyTexSubImage2D) return NULL;
	glDeleteTextures = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteTextures");
	if(!glDeleteTextures) return NULL;
	glDrawArrays = (void (APIENTRY*)(GLenum, GLint, GLsizei))glAnyGetProcAddress("glDrawArrays");
	if(!glDrawArrays) return NULL;
	glDrawElements = (void (APIENTRY*)(GLenum, GLsizei, GLenum, const void*))glAnyGetProcAddress("glDrawElements");
	if(!glDrawElements) return NULL;
	glGenTextures = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenTextures");
	if(!glGenTextures) return NULL;
	glIsTexture = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsTexture");
	if(!glIsTexture) return NULL;
	glPolygonOffset = (void (APIENTRY*)(GLfloat, GLfloat))glAnyGetProcAddress("glPolygonOffset");
	if(!glPolygonOffset) return NULL;
	glTexSubImage1D = (void (APIENTRY*)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexSubImage1D");
	if(!glTexSubImage1D) return NULL;
	glTexSubImage2D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexSubImage2D");
	if(!glTexSubImage2D) return NULL;
	glCopyTexSubImage3D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))glAnyGetProcAddress("glCopyTexSubImage3D");
	if(!glCopyTexSubImage3D) return NULL;
	glDrawRangeElements = (void (APIENTRY*)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void*))glAnyGetProcAddress("glDrawRangeElements");
	if(!glDrawRangeElements) return NULL;
	glTexImage3D = (void (APIENTRY*)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexImage3D");
	if(!glTexImage3D) return NULL;
	glTexSubImage3D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*))glAnyGetProcAddress("glTexSubImage3D");
	if(!glTexSubImage3D) return NULL;
	glActiveTexture = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glActiveTexture");
	if(!glActiveTexture) return NULL;
	glCompressedTexImage1D = (void (APIENTRY*)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexImage1D");
	if(!glCompressedTexImage1D) return NULL;
	glCompressedTexImage2D = (void (APIENTRY*)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexImage2D");
	if(!glCompressedTexImage2D) return NULL;
	glCompressedTexImage3D = (void (APIENTRY*)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexImage3D");
	if(!glCompressedTexImage3D) return NULL;
	glCompressedTexSubImage1D = (void (APIENTRY*)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexSubImage1D");
	if(!glCompressedTexSubImage1D) return NULL;
	glCompressedTexSubImage2D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexSubImage2D");
	if(!glCompressedTexSubImage2D) return NULL;
	glCompressedTexSubImage3D = (void (APIENTRY*)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void*))glAnyGetProcAddress("glCompressedTexSubImage3D");
	if(!glCompressedTexSubImage3D) return NULL;
	glGetCompressedTexImage = (void (APIENTRY*)(GLenum, GLint, void*))glAnyGetProcAddress("glGetCompressedTexImage");
	if(!glGetCompressedTexImage) return NULL;
	glSampleCoverage = (void (APIENTRY*)(GLfloat, GLboolean))glAnyGetProcAddress("glSampleCoverage");
	if(!glSampleCoverage) return NULL;
	glBlendColor = (void (APIENTRY*)(GLfloat, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glBlendColor");
	if(!glBlendColor) return NULL;
	glBlendEquation = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glBlendEquation");
	if(!glBlendEquation) return NULL;
	glBlendFuncSeparate = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLenum))glAnyGetProcAddress("glBlendFuncSeparate");
	if(!glBlendFuncSeparate) return NULL;
	glMultiDrawArrays = (void (APIENTRY*)(GLenum, const GLint*, const GLsizei*, GLsizei))glAnyGetProcAddress("glMultiDrawArrays");
	if(!glMultiDrawArrays) return NULL;
	glMultiDrawElements = (void (APIENTRY*)(GLenum, const GLsizei*, GLenum, const void*const*, GLsizei))glAnyGetProcAddress("glMultiDrawElements");
	if(!glMultiDrawElements) return NULL;
	glPointParameterf = (void (APIENTRY*)(GLenum, GLfloat))glAnyGetProcAddress("glPointParameterf");
	if(!glPointParameterf) return NULL;
	glPointParameterfv = (void (APIENTRY*)(GLenum, const GLfloat*))glAnyGetProcAddress("glPointParameterfv");
	if(!glPointParameterfv) return NULL;
	glPointParameteri = (void (APIENTRY*)(GLenum, GLint))glAnyGetProcAddress("glPointParameteri");
	if(!glPointParameteri) return NULL;
	glPointParameteriv = (void (APIENTRY*)(GLenum, const GLint*))glAnyGetProcAddress("glPointParameteriv");
	if(!glPointParameteriv) return NULL;
	glBeginQuery = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glBeginQuery");
	if(!glBeginQuery) return NULL;
	glBindBuffer = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glBindBuffer");
	if(!glBindBuffer) return NULL;
	glBufferData = (void (APIENTRY*)(GLenum, GLsizeiptr, const void*, GLenum))glAnyGetProcAddress("glBufferData");
	if(!glBufferData) return NULL;
	glBufferSubData = (void (APIENTRY*)(GLenum, GLintptr, GLsizeiptr, const void*))glAnyGetProcAddress("glBufferSubData");
	if(!glBufferSubData) return NULL;
	glDeleteBuffers = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteBuffers");
	if(!glDeleteBuffers) return NULL;
	glDeleteQueries = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteQueries");
	if(!glDeleteQueries) return NULL;
	glEndQuery = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glEndQuery");
	if(!glEndQuery) return NULL;
	glGenBuffers = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenBuffers");
	if(!glGenBuffers) return NULL;
	glGenQueries = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenQueries");
	if(!glGenQueries) return NULL;
	glGetBufferParameteriv = (void (APIENTRY*)(GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetBufferParameteriv");
	if(!glGetBufferParameteriv) return NULL;
	glGetBufferPointerv = (void (APIENTRY*)(GLenum, GLenum, void**))glAnyGetProcAddress("glGetBufferPointerv");
	if(!glGetBufferPointerv) return NULL;
	glGetBufferSubData = (void (APIENTRY*)(GLenum, GLintptr, GLsizeiptr, void*))glAnyGetProcAddress("glGetBufferSubData");
	if(!glGetBufferSubData) return NULL;
	glGetQueryObjectiv = (void (APIENTRY*)(GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetQueryObjectiv");
	if(!glGetQueryObjectiv) return NULL;
	glGetQueryObjectuiv = (void (APIENTRY*)(GLuint, GLenum, GLuint*))glAnyGetProcAddress("glGetQueryObjectuiv");
	if(!glGetQueryObjectuiv) return NULL;
	glGetQueryiv = (void (APIENTRY*)(GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetQueryiv");
	if(!glGetQueryiv) return NULL;
	glIsBuffer = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsBuffer");
	if(!glIsBuffer) return NULL;
	glIsQuery = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsQuery");
	if(!glIsQuery) return NULL;
	glMapBuffer = (void* (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glMapBuffer");
	if(!glMapBuffer) return NULL;
	glUnmapBuffer = (GLboolean (APIENTRY*)(GLenum))glAnyGetProcAddress("glUnmapBuffer");
	if(!glUnmapBuffer) return NULL;
	glAttachShader = (void (APIENTRY*)(GLuint, GLuint))glAnyGetProcAddress("glAttachShader");
	if(!glAttachShader) return NULL;
	glBindAttribLocation = (void (APIENTRY*)(GLuint, GLuint, const GLchar*))glAnyGetProcAddress("glBindAttribLocation");
	if(!glBindAttribLocation) return NULL;
	glBlendEquationSeparate = (void (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glBlendEquationSeparate");
	if(!glBlendEquationSeparate) return NULL;
	glCompileShader = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glCompileShader");
	if(!glCompileShader) return NULL;
	glCreateProgram = (GLuint (APIENTRY*)(void))glAnyGetProcAddress("glCreateProgram");
	if(!glCreateProgram) return NULL;
	glCreateShader = (GLuint (APIENTRY*)(GLenum))glAnyGetProcAddress("glCreateShader");
	if(!glCreateShader) return NULL;
	glDeleteProgram = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glDeleteProgram");
	if(!glDeleteProgram) return NULL;
	glDeleteShader = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glDeleteShader");
	if(!glDeleteShader) return NULL;
	glDetachShader = (void (APIENTRY*)(GLuint, GLuint))glAnyGetProcAddress("glDetachShader");
	if(!glDetachShader) return NULL;
	glDisableVertexAttribArray = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glDisableVertexAttribArray");
	if(!glDisableVertexAttribArray) return NULL;
	glDrawBuffers = (void (APIENTRY*)(GLsizei, const GLenum*))glAnyGetProcAddress("glDrawBuffers");
	if(!glDrawBuffers) return NULL;
	glEnableVertexAttribArray = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glEnableVertexAttribArray");
	if(!glEnableVertexAttribArray) return NULL;
	glGetActiveAttrib = (void (APIENTRY*)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*))glAnyGetProcAddress("glGetActiveAttrib");
	if(!glGetActiveAttrib) return NULL;
	glGetActiveUniform = (void (APIENTRY*)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*))glAnyGetProcAddress("glGetActiveUniform");
	if(!glGetActiveUniform) return NULL;
	glGetAttachedShaders = (void (APIENTRY*)(GLuint, GLsizei, GLsizei*, GLuint*))glAnyGetProcAddress("glGetAttachedShaders");
	if(!glGetAttachedShaders) return NULL;
	glGetAttribLocation = (GLint (APIENTRY*)(GLuint, const GLchar*))glAnyGetProcAddress("glGetAttribLocation");
	if(!glGetAttribLocation) return NULL;
	glGetProgramInfoLog = (void (APIENTRY*)(GLuint, GLsizei, GLsizei*, GLchar*))glAnyGetProcAddress("glGetProgramInfoLog");
	if(!glGetProgramInfoLog) return NULL;
	glGetProgramiv = (void (APIENTRY*)(GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetProgramiv");
	if(!glGetProgramiv) return NULL;
	glGetShaderInfoLog = (void (APIENTRY*)(GLuint, GLsizei, GLsizei*, GLchar*))glAnyGetProcAddress("glGetShaderInfoLog");
	if(!glGetShaderInfoLog) return NULL;
	glGetShaderSource = (void (APIENTRY*)(GLuint, GLsizei, GLsizei*, GLchar*))glAnyGetProcAddress("glGetShaderSource");
	if(!glGetShaderSource) return NULL;
	glGetShaderiv = (void (APIENTRY*)(GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetShaderiv");
	if(!glGetShaderiv) return NULL;
	glGetUniformLocation = (GLint (APIENTRY*)(GLuint, const GLchar*))glAnyGetProcAddress("glGetUniformLocation");
	if(!glGetUniformLocation) return NULL;
	glGetUniformfv = (void (APIENTRY*)(GLuint, GLint, GLfloat*))glAnyGetProcAddress("glGetUniformfv");
	if(!glGetUniformfv) return NULL;
	glGetUniformiv = (void (APIENTRY*)(GLuint, GLint, GLint*))glAnyGetProcAddress("glGetUniformiv");
	if(!glGetUniformiv) return NULL;
	glGetVertexAttribPointerv = (void (APIENTRY*)(GLuint, GLenum, void**))glAnyGetProcAddress("glGetVertexAttribPointerv");
	if(!glGetVertexAttribPointerv) return NULL;
	glGetVertexAttribdv = (void (APIENTRY*)(GLuint, GLenum, GLdouble*))glAnyGetProcAddress("glGetVertexAttribdv");
	if(!glGetVertexAttribdv) return NULL;
	glGetVertexAttribfv = (void (APIENTRY*)(GLuint, GLenum, GLfloat*))glAnyGetProcAddress("glGetVertexAttribfv");
	if(!glGetVertexAttribfv) return NULL;
	glGetVertexAttribiv = (void (APIENTRY*)(GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetVertexAttribiv");
	if(!glGetVertexAttribiv) return NULL;
	glIsProgram = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsProgram");
	if(!glIsProgram) return NULL;
	glIsShader = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsShader");
	if(!glIsShader) return NULL;
	glLinkProgram = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glLinkProgram");
	if(!glLinkProgram) return NULL;
	glShaderSource = (void (APIENTRY*)(GLuint, GLsizei, const GLchar*const*, const GLint*))glAnyGetProcAddress("glShaderSource");
	if(!glShaderSource) return NULL;
	glStencilFuncSeparate = (void (APIENTRY*)(GLenum, GLenum, GLint, GLuint))glAnyGetProcAddress("glStencilFuncSeparate");
	if(!glStencilFuncSeparate) return NULL;
	glStencilMaskSeparate = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glStencilMaskSeparate");
	if(!glStencilMaskSeparate) return NULL;
	glStencilOpSeparate = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLenum))glAnyGetProcAddress("glStencilOpSeparate");
	if(!glStencilOpSeparate) return NULL;
	glUniform1f = (void (APIENTRY*)(GLint, GLfloat))glAnyGetProcAddress("glUniform1f");
	if(!glUniform1f) return NULL;
	glUniform1fv = (void (APIENTRY*)(GLint, GLsizei, const GLfloat*))glAnyGetProcAddress("glUniform1fv");
	if(!glUniform1fv) return NULL;
	glUniform1i = (void (APIENTRY*)(GLint, GLint))glAnyGetProcAddress("glUniform1i");
	if(!glUniform1i) return NULL;
	glUniform1iv = (void (APIENTRY*)(GLint, GLsizei, const GLint*))glAnyGetProcAddress("glUniform1iv");
	if(!glUniform1iv) return NULL;
	glUniform2f = (void (APIENTRY*)(GLint, GLfloat, GLfloat))glAnyGetProcAddress("glUniform2f");
	if(!glUniform2f) return NULL;
	glUniform2fv = (void (APIENTRY*)(GLint, GLsizei, const GLfloat*))glAnyGetProcAddress("glUniform2fv");
	if(!glUniform2fv) return NULL;
	glUniform2i = (void (APIENTRY*)(GLint, GLint, GLint))glAnyGetProcAddress("glUniform2i");
	if(!glUniform2i) return NULL;
	glUniform2iv = (void (APIENTRY*)(GLint, GLsizei, const GLint*))glAnyGetProcAddress("glUniform2iv");
	if(!glUniform2iv) return NULL;
	glUniform3f = (void (APIENTRY*)(GLint, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glUniform3f");
	if(!glUniform3f) return NULL;
	glUniform3fv = (void (APIENTRY*)(GLint, GLsizei, const GLfloat*))glAnyGetProcAddress("glUniform3fv");
	if(!glUniform3fv) return NULL;
	glUniform3i = (void (APIENTRY*)(GLint, GLint, GLint, GLint))glAnyGetProcAddress("glUniform3i");
	if(!glUniform3i) return NULL;
	glUniform3iv = (void (APIENTRY*)(GLint, GLsizei, const GLint*))glAnyGetProcAddress("glUniform3iv");
	if(!glUniform3iv) return NULL;
	glUniform4f = (void (APIENTRY*)(GLint, GLfloat, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glUniform4f");
	if(!glUniform4f) return NULL;
	glUniform4fv = (void (APIENTRY*)(GLint, GLsizei, const GLfloat*))glAnyGetProcAddress("glUniform4fv");
	if(!glUniform4fv) return NULL;
	glUniform4i = (void (APIENTRY*)(GLint, GLint, GLint, GLint, GLint))glAnyGetProcAddress("glUniform4i");
	if(!glUniform4i) return NULL;
	glUniform4iv = (void (APIENTRY*)(GLint, GLsizei, const GLint*))glAnyGetProcAddress("glUniform4iv");
	if(!glUniform4iv) return NULL;
	glUniformMatrix2fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix2fv");
	if(!glUniformMatrix2fv) return NULL;
	glUniformMatrix3fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix3fv");
	if(!glUniformMatrix3fv) return NULL;
	glUniformMatrix4fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix4fv");
	if(!glUniformMatrix4fv) return NULL;
	glUseProgram = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glUseProgram");
	if(!glUseProgram) return NULL;
	glValidateProgram = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glValidateProgram");
	if(!glValidateProgram) return NULL;
	glVertexAttrib1d = (void (APIENTRY*)(GLuint, GLdouble))glAnyGetProcAddress("glVertexAttrib1d");
	if(!glVertexAttrib1d) return NULL;
	glVertexAttrib1dv = (void (APIENTRY*)(GLuint, const GLdouble*))glAnyGetProcAddress("glVertexAttrib1dv");
	if(!glVertexAttrib1dv) return NULL;
	glVertexAttrib1f = (void (APIENTRY*)(GLuint, GLfloat))glAnyGetProcAddress("glVertexAttrib1f");
	if(!glVertexAttrib1f) return NULL;
	glVertexAttrib1fv = (void (APIENTRY*)(GLuint, const GLfloat*))glAnyGetProcAddress("glVertexAttrib1fv");
	if(!glVertexAttrib1fv) return NULL;
	glVertexAttrib1s = (void (APIENTRY*)(GLuint, GLshort))glAnyGetProcAddress("glVertexAttrib1s");
	if(!glVertexAttrib1s) return NULL;
	glVertexAttrib1sv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttrib1sv");
	if(!glVertexAttrib1sv) return NULL;
	glVertexAttrib2d = (void (APIENTRY*)(GLuint, GLdouble, GLdouble))glAnyGetProcAddress("glVertexAttrib2d");
	if(!glVertexAttrib2d) return NULL;
	glVertexAttrib2dv = (void (APIENTRY*)(GLuint, const GLdouble*))glAnyGetProcAddress("glVertexAttrib2dv");
	if(!glVertexAttrib2dv) return NULL;
	glVertexAttrib2f = (void (APIENTRY*)(GLuint, GLfloat, GLfloat))glAnyGetProcAddress("glVertexAttrib2f");
	if(!glVertexAttrib2f) return NULL;
	glVertexAttrib2fv = (void (APIENTRY*)(GLuint, const GLfloat*))glAnyGetProcAddress("glVertexAttrib2fv");
	if(!glVertexAttrib2fv) return NULL;
	glVertexAttrib2s = (void (APIENTRY*)(GLuint, GLshort, GLshort))glAnyGetProcAddress("glVertexAttrib2s");
	if(!glVertexAttrib2s) return NULL;
	glVertexAttrib2sv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttrib2sv");
	if(!glVertexAttrib2sv) return NULL;
	glVertexAttrib3d = (void (APIENTRY*)(GLuint, GLdouble, GLdouble, GLdouble))glAnyGetProcAddress("glVertexAttrib3d");
	if(!glVertexAttrib3d) return NULL;
	glVertexAttrib3dv = (void (APIENTRY*)(GLuint, const GLdouble*))glAnyGetProcAddress("glVertexAttrib3dv");
	if(!glVertexAttrib3dv) return NULL;
	glVertexAttrib3f = (void (APIENTRY*)(GLuint, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glVertexAttrib3f");
	if(!glVertexAttrib3f) return NULL;
	glVertexAttrib3fv = (void (APIENTRY*)(GLuint, const GLfloat*))glAnyGetProcAddress("glVertexAttrib3fv");
	if(!glVertexAttrib3fv) return NULL;
	glVertexAttrib3s = (void (APIENTRY*)(GLuint, GLshort, GLshort, GLshort))glAnyGetProcAddress("glVertexAttrib3s");
	if(!glVertexAttrib3s) return NULL;
	glVertexAttrib3sv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttrib3sv");
	if(!glVertexAttrib3sv) return NULL;
	glVertexAttrib4Nbv = (void (APIENTRY*)(GLuint, const GLbyte*))glAnyGetProcAddress("glVertexAttrib4Nbv");
	if(!glVertexAttrib4Nbv) return NULL;
	glVertexAttrib4Niv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttrib4Niv");
	if(!glVertexAttrib4Niv) return NULL;
	glVertexAttrib4Nsv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttrib4Nsv");
	if(!glVertexAttrib4Nsv) return NULL;
	glVertexAttrib4Nub = (void (APIENTRY*)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))glAnyGetProcAddress("glVertexAttrib4Nub");
	if(!glVertexAttrib4Nub) return NULL;
	glVertexAttrib4Nubv = (void (APIENTRY*)(GLuint, const GLubyte*))glAnyGetProcAddress("glVertexAttrib4Nubv");
	if(!glVertexAttrib4Nubv) return NULL;
	glVertexAttrib4Nuiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttrib4Nuiv");
	if(!glVertexAttrib4Nuiv) return NULL;
	glVertexAttrib4Nusv = (void (APIENTRY*)(GLuint, const GLushort*))glAnyGetProcAddress("glVertexAttrib4Nusv");
	if(!glVertexAttrib4Nusv) return NULL;
	glVertexAttrib4bv = (void (APIENTRY*)(GLuint, const GLbyte*))glAnyGetProcAddress("glVertexAttrib4bv");
	if(!glVertexAttrib4bv) return NULL;
	glVertexAttrib4d = (void (APIENTRY*)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))glAnyGetProcAddress("glVertexAttrib4d");
	if(!glVertexAttrib4d) return NULL;
	glVertexAttrib4dv = (void (APIENTRY*)(GLuint, const GLdouble*))glAnyGetProcAddress("glVertexAttrib4dv");
	if(!glVertexAttrib4dv) return NULL;
	glVertexAttrib4f = (void (APIENTRY*)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))glAnyGetProcAddress("glVertexAttrib4f");
	if(!glVertexAttrib4f) return NULL;
	glVertexAttrib4fv = (void (APIENTRY*)(GLuint, const GLfloat*))glAnyGetProcAddress("glVertexAttrib4fv");
	if(!glVertexAttrib4fv) return NULL;
	glVertexAttrib4iv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttrib4iv");
	if(!glVertexAttrib4iv) return NULL;
	glVertexAttrib4s = (void (APIENTRY*)(GLuint, GLshort, GLshort, GLshort, GLshort))glAnyGetProcAddress("glVertexAttrib4s");
	if(!glVertexAttrib4s) return NULL;
	glVertexAttrib4sv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttrib4sv");
	if(!glVertexAttrib4sv) return NULL;
	glVertexAttrib4ubv = (void (APIENTRY*)(GLuint, const GLubyte*))glAnyGetProcAddress("glVertexAttrib4ubv");
	if(!glVertexAttrib4ubv) return NULL;
	glVertexAttrib4uiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttrib4uiv");
	if(!glVertexAttrib4uiv) return NULL;
	glVertexAttrib4usv = (void (APIENTRY*)(GLuint, const GLushort*))glAnyGetProcAddress("glVertexAttrib4usv");
	if(!glVertexAttrib4usv) return NULL;
	glVertexAttribPointer = (void (APIENTRY*)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void*))glAnyGetProcAddress("glVertexAttribPointer");
	if(!glVertexAttribPointer) return NULL;
	glUniformMatrix2x3fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix2x3fv");
	if(!glUniformMatrix2x3fv) return NULL;
	glUniformMatrix2x4fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix2x4fv");
	if(!glUniformMatrix2x4fv) return NULL;
	glUniformMatrix3x2fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix3x2fv");
	if(!glUniformMatrix3x2fv) return NULL;
	glUniformMatrix3x4fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix3x4fv");
	if(!glUniformMatrix3x4fv) return NULL;
	glUniformMatrix4x2fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix4x2fv");
	if(!glUniformMatrix4x2fv) return NULL;
	glUniformMatrix4x3fv = (void (APIENTRY*)(GLint, GLsizei, GLboolean, const GLfloat*))glAnyGetProcAddress("glUniformMatrix4x3fv");
	if(!glUniformMatrix4x3fv) return NULL;
	glBeginConditionalRender = (void (APIENTRY*)(GLuint, GLenum))glAnyGetProcAddress("glBeginConditionalRender");
	if(!glBeginConditionalRender) return NULL;
	glBeginTransformFeedback = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glBeginTransformFeedback");
	if(!glBeginTransformFeedback) return NULL;
	glBindBufferBase = (void (APIENTRY*)(GLenum, GLuint, GLuint))glAnyGetProcAddress("glBindBufferBase");
	if(!glBindBufferBase) return NULL;
	glBindBufferRange = (void (APIENTRY*)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))glAnyGetProcAddress("glBindBufferRange");
	if(!glBindBufferRange) return NULL;
	glBindFragDataLocation = (void (APIENTRY*)(GLuint, GLuint, const GLchar*))glAnyGetProcAddress("glBindFragDataLocation");
	if(!glBindFragDataLocation) return NULL;
	glBindFramebuffer = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glBindFramebuffer");
	if(!glBindFramebuffer) return NULL;
	glBindRenderbuffer = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glBindRenderbuffer");
	if(!glBindRenderbuffer) return NULL;
	glBindVertexArray = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glBindVertexArray");
	if(!glBindVertexArray) return NULL;
	glBlitFramebuffer = (void (APIENTRY*)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))glAnyGetProcAddress("glBlitFramebuffer");
	if(!glBlitFramebuffer) return NULL;
	glCheckFramebufferStatus = (GLenum (APIENTRY*)(GLenum))glAnyGetProcAddress("glCheckFramebufferStatus");
	if(!glCheckFramebufferStatus) return NULL;
	glClampColor = (void (APIENTRY*)(GLenum, GLenum))glAnyGetProcAddress("glClampColor");
	if(!glClampColor) return NULL;
	glClearBufferfi = (void (APIENTRY*)(GLenum, GLint, GLfloat, GLint))glAnyGetProcAddress("glClearBufferfi");
	if(!glClearBufferfi) return NULL;
	glClearBufferfv = (void (APIENTRY*)(GLenum, GLint, const GLfloat*))glAnyGetProcAddress("glClearBufferfv");
	if(!glClearBufferfv) return NULL;
	glClearBufferiv = (void (APIENTRY*)(GLenum, GLint, const GLint*))glAnyGetProcAddress("glClearBufferiv");
	if(!glClearBufferiv) return NULL;
	glClearBufferuiv = (void (APIENTRY*)(GLenum, GLint, const GLuint*))glAnyGetProcAddress("glClearBufferuiv");
	if(!glClearBufferuiv) return NULL;
	glColorMaski = (void (APIENTRY*)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean))glAnyGetProcAddress("glColorMaski");
	if(!glColorMaski) return NULL;
	glDeleteFramebuffers = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteFramebuffers");
	if(!glDeleteFramebuffers) return NULL;
	glDeleteRenderbuffers = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteRenderbuffers");
	if(!glDeleteRenderbuffers) return NULL;
	glDeleteVertexArrays = (void (APIENTRY*)(GLsizei, const GLuint*))glAnyGetProcAddress("glDeleteVertexArrays");
	if(!glDeleteVertexArrays) return NULL;
	glDisablei = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glDisablei");
	if(!glDisablei) return NULL;
	glEnablei = (void (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glEnablei");
	if(!glEnablei) return NULL;
	glEndConditionalRender = (void (APIENTRY*)(void))glAnyGetProcAddress("glEndConditionalRender");
	if(!glEndConditionalRender) return NULL;
	glEndTransformFeedback = (void (APIENTRY*)(void))glAnyGetProcAddress("glEndTransformFeedback");
	if(!glEndTransformFeedback) return NULL;
	glFlushMappedBufferRange = (void (APIENTRY*)(GLenum, GLintptr, GLsizeiptr))glAnyGetProcAddress("glFlushMappedBufferRange");
	if(!glFlushMappedBufferRange) return NULL;
	glFramebufferRenderbuffer = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLuint))glAnyGetProcAddress("glFramebufferRenderbuffer");
	if(!glFramebufferRenderbuffer) return NULL;
	glFramebufferTexture1D = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLuint, GLint))glAnyGetProcAddress("glFramebufferTexture1D");
	if(!glFramebufferTexture1D) return NULL;
	glFramebufferTexture2D = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLuint, GLint))glAnyGetProcAddress("glFramebufferTexture2D");
	if(!glFramebufferTexture2D) return NULL;
	glFramebufferTexture3D = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))glAnyGetProcAddress("glFramebufferTexture3D");
	if(!glFramebufferTexture3D) return NULL;
	glFramebufferTextureLayer = (void (APIENTRY*)(GLenum, GLenum, GLuint, GLint, GLint))glAnyGetProcAddress("glFramebufferTextureLayer");
	if(!glFramebufferTextureLayer) return NULL;
	glGenFramebuffers = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenFramebuffers");
	if(!glGenFramebuffers) return NULL;
	glGenRenderbuffers = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenRenderbuffers");
	if(!glGenRenderbuffers) return NULL;
	glGenVertexArrays = (void (APIENTRY*)(GLsizei, GLuint*))glAnyGetProcAddress("glGenVertexArrays");
	if(!glGenVertexArrays) return NULL;
	glGenerateMipmap = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glGenerateMipmap");
	if(!glGenerateMipmap) return NULL;
	glGetBooleani_v = (void (APIENTRY*)(GLenum, GLuint, GLboolean*))glAnyGetProcAddress("glGetBooleani_v");
	if(!glGetBooleani_v) return NULL;
	glGetFragDataLocation = (GLint (APIENTRY*)(GLuint, const GLchar*))glAnyGetProcAddress("glGetFragDataLocation");
	if(!glGetFragDataLocation) return NULL;
	glGetFramebufferAttachmentParameteriv = (void (APIENTRY*)(GLenum, GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!glGetFramebufferAttachmentParameteriv) return NULL;
	glGetIntegeri_v = (void (APIENTRY*)(GLenum, GLuint, GLint*))glAnyGetProcAddress("glGetIntegeri_v");
	if(!glGetIntegeri_v) return NULL;
	glGetRenderbufferParameteriv = (void (APIENTRY*)(GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetRenderbufferParameteriv");
	if(!glGetRenderbufferParameteriv) return NULL;
	glGetStringi = (const GLubyte* (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glGetStringi");
	if(!glGetStringi) return NULL;
	glGetTexParameterIiv = (void (APIENTRY*)(GLenum, GLenum, GLint*))glAnyGetProcAddress("glGetTexParameterIiv");
	if(!glGetTexParameterIiv) return NULL;
	glGetTexParameterIuiv = (void (APIENTRY*)(GLenum, GLenum, GLuint*))glAnyGetProcAddress("glGetTexParameterIuiv");
	if(!glGetTexParameterIuiv) return NULL;
	glGetTransformFeedbackVarying = (void (APIENTRY*)(GLuint, GLuint, GLsizei, GLsizei*, GLsizei*, GLenum*, GLchar*))glAnyGetProcAddress("glGetTransformFeedbackVarying");
	if(!glGetTransformFeedbackVarying) return NULL;
	glGetUniformuiv = (void (APIENTRY*)(GLuint, GLint, GLuint*))glAnyGetProcAddress("glGetUniformuiv");
	if(!glGetUniformuiv) return NULL;
	glGetVertexAttribIiv = (void (APIENTRY*)(GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetVertexAttribIiv");
	if(!glGetVertexAttribIiv) return NULL;
	glGetVertexAttribIuiv = (void (APIENTRY*)(GLuint, GLenum, GLuint*))glAnyGetProcAddress("glGetVertexAttribIuiv");
	if(!glGetVertexAttribIuiv) return NULL;
	glIsEnabledi = (GLboolean (APIENTRY*)(GLenum, GLuint))glAnyGetProcAddress("glIsEnabledi");
	if(!glIsEnabledi) return NULL;
	glIsFramebuffer = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsFramebuffer");
	if(!glIsFramebuffer) return NULL;
	glIsRenderbuffer = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsRenderbuffer");
	if(!glIsRenderbuffer) return NULL;
	glIsVertexArray = (GLboolean (APIENTRY*)(GLuint))glAnyGetProcAddress("glIsVertexArray");
	if(!glIsVertexArray) return NULL;
	glMapBufferRange = (void* (APIENTRY*)(GLenum, GLintptr, GLsizeiptr, GLbitfield))glAnyGetProcAddress("glMapBufferRange");
	if(!glMapBufferRange) return NULL;
	glRenderbufferStorage = (void (APIENTRY*)(GLenum, GLenum, GLsizei, GLsizei))glAnyGetProcAddress("glRenderbufferStorage");
	if(!glRenderbufferStorage) return NULL;
	glRenderbufferStorageMultisample = (void (APIENTRY*)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))glAnyGetProcAddress("glRenderbufferStorageMultisample");
	if(!glRenderbufferStorageMultisample) return NULL;
	glTexParameterIiv = (void (APIENTRY*)(GLenum, GLenum, const GLint*))glAnyGetProcAddress("glTexParameterIiv");
	if(!glTexParameterIiv) return NULL;
	glTexParameterIuiv = (void (APIENTRY*)(GLenum, GLenum, const GLuint*))glAnyGetProcAddress("glTexParameterIuiv");
	if(!glTexParameterIuiv) return NULL;
	glTransformFeedbackVaryings = (void (APIENTRY*)(GLuint, GLsizei, const GLchar*const*, GLenum))glAnyGetProcAddress("glTransformFeedbackVaryings");
	if(!glTransformFeedbackVaryings) return NULL;
	glUniform1ui = (void (APIENTRY*)(GLint, GLuint))glAnyGetProcAddress("glUniform1ui");
	if(!glUniform1ui) return NULL;
	glUniform1uiv = (void (APIENTRY*)(GLint, GLsizei, const GLuint*))glAnyGetProcAddress("glUniform1uiv");
	if(!glUniform1uiv) return NULL;
	glUniform2ui = (void (APIENTRY*)(GLint, GLuint, GLuint))glAnyGetProcAddress("glUniform2ui");
	if(!glUniform2ui) return NULL;
	glUniform2uiv = (void (APIENTRY*)(GLint, GLsizei, const GLuint*))glAnyGetProcAddress("glUniform2uiv");
	if(!glUniform2uiv) return NULL;
	glUniform3ui = (void (APIENTRY*)(GLint, GLuint, GLuint, GLuint))glAnyGetProcAddress("glUniform3ui");
	if(!glUniform3ui) return NULL;
	glUniform3uiv = (void (APIENTRY*)(GLint, GLsizei, const GLuint*))glAnyGetProcAddress("glUniform3uiv");
	if(!glUniform3uiv) return NULL;
	glUniform4ui = (void (APIENTRY*)(GLint, GLuint, GLuint, GLuint, GLuint))glAnyGetProcAddress("glUniform4ui");
	if(!glUniform4ui) return NULL;
	glUniform4uiv = (void (APIENTRY*)(GLint, GLsizei, const GLuint*))glAnyGetProcAddress("glUniform4uiv");
	if(!glUniform4uiv) return NULL;
	glVertexAttribI1i = (void (APIENTRY*)(GLuint, GLint))glAnyGetProcAddress("glVertexAttribI1i");
	if(!glVertexAttribI1i) return NULL;
	glVertexAttribI1iv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttribI1iv");
	if(!glVertexAttribI1iv) return NULL;
	glVertexAttribI1ui = (void (APIENTRY*)(GLuint, GLuint))glAnyGetProcAddress("glVertexAttribI1ui");
	if(!glVertexAttribI1ui) return NULL;
	glVertexAttribI1uiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttribI1uiv");
	if(!glVertexAttribI1uiv) return NULL;
	glVertexAttribI2i = (void (APIENTRY*)(GLuint, GLint, GLint))glAnyGetProcAddress("glVertexAttribI2i");
	if(!glVertexAttribI2i) return NULL;
	glVertexAttribI2iv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttribI2iv");
	if(!glVertexAttribI2iv) return NULL;
	glVertexAttribI2ui = (void (APIENTRY*)(GLuint, GLuint, GLuint))glAnyGetProcAddress("glVertexAttribI2ui");
	if(!glVertexAttribI2ui) return NULL;
	glVertexAttribI2uiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttribI2uiv");
	if(!glVertexAttribI2uiv) return NULL;
	glVertexAttribI3i = (void (APIENTRY*)(GLuint, GLint, GLint, GLint))glAnyGetProcAddress("glVertexAttribI3i");
	if(!glVertexAttribI3i) return NULL;
	glVertexAttribI3iv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttribI3iv");
	if(!glVertexAttribI3iv) return NULL;
	glVertexAttribI3ui = (void (APIENTRY*)(GLuint, GLuint, GLuint, GLuint))glAnyGetProcAddress("glVertexAttribI3ui");
	if(!glVertexAttribI3ui) return NULL;
	glVertexAttribI3uiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttribI3uiv");
	if(!glVertexAttribI3uiv) return NULL;
	glVertexAttribI4bv = (void (APIENTRY*)(GLuint, const GLbyte*))glAnyGetProcAddress("glVertexAttribI4bv");
	if(!glVertexAttribI4bv) return NULL;
	glVertexAttribI4i = (void (APIENTRY*)(GLuint, GLint, GLint, GLint, GLint))glAnyGetProcAddress("glVertexAttribI4i");
	if(!glVertexAttribI4i) return NULL;
	glVertexAttribI4iv = (void (APIENTRY*)(GLuint, const GLint*))glAnyGetProcAddress("glVertexAttribI4iv");
	if(!glVertexAttribI4iv) return NULL;
	glVertexAttribI4sv = (void (APIENTRY*)(GLuint, const GLshort*))glAnyGetProcAddress("glVertexAttribI4sv");
	if(!glVertexAttribI4sv) return NULL;
	glVertexAttribI4ubv = (void (APIENTRY*)(GLuint, const GLubyte*))glAnyGetProcAddress("glVertexAttribI4ubv");
	if(!glVertexAttribI4ubv) return NULL;
	glVertexAttribI4ui = (void (APIENTRY*)(GLuint, GLuint, GLuint, GLuint, GLuint))glAnyGetProcAddress("glVertexAttribI4ui");
	if(!glVertexAttribI4ui) return NULL;
	glVertexAttribI4uiv = (void (APIENTRY*)(GLuint, const GLuint*))glAnyGetProcAddress("glVertexAttribI4uiv");
	if(!glVertexAttribI4uiv) return NULL;
	glVertexAttribI4usv = (void (APIENTRY*)(GLuint, const GLushort*))glAnyGetProcAddress("glVertexAttribI4usv");
	if(!glVertexAttribI4usv) return NULL;
	glVertexAttribIPointer = (void (APIENTRY*)(GLuint, GLint, GLenum, GLsizei, const void*))glAnyGetProcAddress("glVertexAttribIPointer");
	if(!glVertexAttribIPointer) return NULL;
	glCopyBufferSubData = (void (APIENTRY*)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr))glAnyGetProcAddress("glCopyBufferSubData");
	if(!glCopyBufferSubData) return NULL;
	glDrawArraysInstanced = (void (APIENTRY*)(GLenum, GLint, GLsizei, GLsizei))glAnyGetProcAddress("glDrawArraysInstanced");
	if(!glDrawArraysInstanced) return NULL;
	glDrawElementsInstanced = (void (APIENTRY*)(GLenum, GLsizei, GLenum, const void*, GLsizei))glAnyGetProcAddress("glDrawElementsInstanced");
	if(!glDrawElementsInstanced) return NULL;
	glGetActiveUniformBlockName = (void (APIENTRY*)(GLuint, GLuint, GLsizei, GLsizei*, GLchar*))glAnyGetProcAddress("glGetActiveUniformBlockName");
	if(!glGetActiveUniformBlockName) return NULL;
	glGetActiveUniformBlockiv = (void (APIENTRY*)(GLuint, GLuint, GLenum, GLint*))glAnyGetProcAddress("glGetActiveUniformBlockiv");
	if(!glGetActiveUniformBlockiv) return NULL;
	glGetActiveUniformName = (void (APIENTRY*)(GLuint, GLuint, GLsizei, GLsizei*, GLchar*))glAnyGetProcAddress("glGetActiveUniformName");
	if(!glGetActiveUniformName) return NULL;
	glGetActiveUniformsiv = (void (APIENTRY*)(GLuint, GLsizei, const GLuint*, GLenum, GLint*))glAnyGetProcAddress("glGetActiveUniformsiv");
	if(!glGetActiveUniformsiv) return NULL;
	glGetUniformBlockIndex = (GLuint (APIENTRY*)(GLuint, const GLchar*))glAnyGetProcAddress("glGetUniformBlockIndex");
	if(!glGetUniformBlockIndex) return NULL;
	glGetUniformIndices = (void (APIENTRY*)(GLuint, GLsizei, const GLchar*const*, GLuint*))glAnyGetProcAddress("glGetUniformIndices");
	if(!glGetUniformIndices) return NULL;
	glPrimitiveRestartIndex = (void (APIENTRY*)(GLuint))glAnyGetProcAddress("glPrimitiveRestartIndex");
	if(!glPrimitiveRestartIndex) return NULL;
	glTexBuffer = (void (APIENTRY*)(GLenum, GLenum, GLuint))glAnyGetProcAddress("glTexBuffer");
	if(!glTexBuffer) return NULL;
	glUniformBlockBinding = (void (APIENTRY*)(GLuint, GLuint, GLuint))glAnyGetProcAddress("glUniformBlockBinding");
	if(!glUniformBlockBinding) return NULL;
	glClientWaitSync = (GLenum (APIENTRY*)(GLsync, GLbitfield, GLuint64))glAnyGetProcAddress("glClientWaitSync");
	if(!glClientWaitSync) return NULL;
	glDeleteSync = (void (APIENTRY*)(GLsync))glAnyGetProcAddress("glDeleteSync");
	if(!glDeleteSync) return NULL;
	glDrawElementsBaseVertex = (void (APIENTRY*)(GLenum, GLsizei, GLenum, const void*, GLint))glAnyGetProcAddress("glDrawElementsBaseVertex");
	if(!glDrawElementsBaseVertex) return NULL;
	glDrawElementsInstancedBaseVertex = (void (APIENTRY*)(GLenum, GLsizei, GLenum, const void*, GLsizei, GLint))glAnyGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!glDrawElementsInstancedBaseVertex) return NULL;
	glDrawRangeElementsBaseVertex = (void (APIENTRY*)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void*, GLint))glAnyGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!glDrawRangeElementsBaseVertex) return NULL;
	glFenceSync = (GLsync (APIENTRY*)(GLenum, GLbitfield))glAnyGetProcAddress("glFenceSync");
	if(!glFenceSync) return NULL;
	glFramebufferTexture = (void (APIENTRY*)(GLenum, GLenum, GLuint, GLint))glAnyGetProcAddress("glFramebufferTexture");
	if(!glFramebufferTexture) return NULL;
	glGetBufferParameteri64v = (void (APIENTRY*)(GLenum, GLenum, GLint64*))glAnyGetProcAddress("glGetBufferParameteri64v");
	if(!glGetBufferParameteri64v) return NULL;
	glGetInteger64i_v = (void (APIENTRY*)(GLenum, GLuint, GLint64*))glAnyGetProcAddress("glGetInteger64i_v");
	if(!glGetInteger64i_v) return NULL;
	glGetInteger64v = (void (APIENTRY*)(GLenum, GLint64*))glAnyGetProcAddress("glGetInteger64v");
	if(!glGetInteger64v) return NULL;
	glGetMultisamplefv = (void (APIENTRY*)(GLenum, GLuint, GLfloat*))glAnyGetProcAddress("glGetMultisamplefv");
	if(!glGetMultisamplefv) return NULL;
	glGetSynciv = (void (APIENTRY*)(GLsync, GLenum, GLsizei, GLsizei*, GLint*))glAnyGetProcAddress("glGetSynciv");
	if(!glGetSynciv) return NULL;
	glIsSync = (GLboolean (APIENTRY*)(GLsync))glAnyGetProcAddress("glIsSync");
	if(!glIsSync) return NULL;
	glMultiDrawElementsBaseVertex = (void (APIENTRY*)(GLenum, const GLsizei*, GLenum, const void*const*, GLsizei, const GLint*))glAnyGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!glMultiDrawElementsBaseVertex) return NULL;
	glProvokingVertex = (void (APIENTRY*)(GLenum))glAnyGetProcAddress("glProvokingVertex");
	if(!glProvokingVertex) return NULL;
	glSampleMaski = (void (APIENTRY*)(GLuint, GLbitfield))glAnyGetProcAddress("glSampleMaski");
	if(!glSampleMaski) return NULL;
	glTexImage2DMultisample = (void (APIENTRY*)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))glAnyGetProcAddress("glTexImage2DMultisample");
	if(!glTexImage2DMultisample) return NULL;
	glTexImage3DMultisample = (void (APIENTRY*)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))glAnyGetProcAddress("glTexImage3DMultisample");
	if(!glTexImage3DMultisample) return NULL;
	glWaitSync = (void (APIENTRY*)(GLsync, GLbitfield, GLuint64))glAnyGetProcAddress("glWaitSync");
	if(!glWaitSync) return NULL;
	return 1;
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* RK_GL_IMPLEMENTATION */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* RK_GL_INCLUDE */