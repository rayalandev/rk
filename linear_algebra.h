//  linear_algebra.h - Rayalan Kenyon
//  July, 2017
//
//  linear_algebra.h is a single file header library for doing mathematics
//  operations relating to linear algebra.
//  The library includes methods working with Vectors, Matrices, and Quaternions
// 
//  YOU MUST:
//      #define LINEAR_ALGEBRA_IMPLEMENTATION in at least one file
//
//  DEFINITIONS:
//      #define LINEAR_ALGEBRA_IMPLEMENTATION
//          includes the .c source code for this library
//      #define LINEAR_ALGEBRA_STATIC
//          declares the functions as static (multiple copies of lib)
//      #define LINEAR_ALGEBRA_NO_INLINE
//          disable the default feature of forcing inline on every function
//      #define LINEAR_ALGEBRA_NO_CRT
//          stop the #include <math.h> for sqrtf, tanf
//      #define LINEAR_ALGEBRA_SQRTF(x)
//          redefine sqrt() function used by this library
//      #define LINEAR_ALGEBRA_TANF(x)
//          redefine tan() function used by this library
//
//  NOTES:
//      EVERY matrix in this library is in ROW MAJOR order.
//          Row major order is used because this is C's default.
//      OpenGL uses matrices in COLUMN MAJOR order.
//          This means you need to transpose matrices for OpenGL.
//          Alternatively you can multiply matrices in reverse order.
//
//  VERSION:
//      0.92 - quaternion slerp, nlerp
//      0.91 - add mat4_ translate, rotate, scale, shear
//      0.90 - push to github needs slerp, nlerp
//
//  LICENSE:
//      See end of file for license information.
//
#ifndef LINEAR_ALGEBRA_INCLUDE
#define LINEAR_ALGEBRA_INCLUDE

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

#ifdef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wgnu-anonymous-struct"
#endif

#ifndef LINEAR_MATH_NO_CRT
#include <math.h>
#endif /* LINEAR_MATH_NO_CRT */


#ifndef LINEAR_ALGEBRA_SQRTF
#define LINEAR_ALGEBRA_SQRTF(x) sqrtf(x)
#endif /* LINEAR_ALGEBRA_SQRTF */


#ifndef LINEAR_ALGEBRA_COSF
#define LINEAR_ALGEBRA_COSF(x) cosf(x)
#endif /* LINEAR_ALGEBRA_COSF */

#ifndef LINEAR_ALGEBRA_SINF
#define LINEAR_ALGEBRA_SINF(x) sinf(x)
#endif /* LINEAR_ALGEBRA_SINF */

#ifndef LINEAR_ALGEBRA_TANF
#define LINEAR_ALGEBRA_TANF(x) tanf(x)
#endif /* LINEAR_ALGEBRA_ATANF */

#ifndef LINEAR_ALGEBRA_ACOSF
#define LINEAR_ALGEBRA_ACOSF(x) acosf(x)
#endif /* LINEAR_ALGEBRA_ACOSF */

#ifdef LINEAR_ALGEBRA_STATIC
#define LINEAR_ALGEBRA_DEF static
#else
#define LINEAR_ALGEBRA_DEF extern
#endif /* LINEAR_ALGEBRA_STATIC */

#ifdef LINEAR_ALGEBRA_NO_INLINE
    #define LINEAR_ALGEBRA_INLINE
#elif _MSC_VER && !__INTEL_COMPILER
    #define LINEAR_ALGEBRA_INLINE __inline
#else
    #define LINEAR_ALGEBRA_INLINE inline
#endif /* LINEAR_ALGEBRA_NO_INLINE */


#define LINEAR_ALGEBRA_PI_OVER_360 0.00872664625f
#define LINEAR_ALGEBRA_PI_OVER_180 0.01745329251f

typedef union Vec2 {
    struct {
        float x, y;
    };
    struct {
        float s, t;
    };
    struct {
        float u, v;
    };
    struct {
        float w, h;
    };
    struct {
        float width, height;
    };
    struct {
        float left, right;
    };
    float e[2];
} Vec2;

typedef union Vec3 {
    struct {
        float x, y, z;
    };
    struct {
        float r, g, b;
    };
    struct {
        float i, j, k;
    };
    struct {
        Vec2 xy;
        float _ignored1;
    };
    struct {
        float _ignored2;
        Vec2 yz;
    };
    struct {
        Vec2 rg;
        float _ignored3;
    };
    struct {
        float _ignored4;
        Vec2 gb;
    };
    struct {
        Vec2 ij;
        float _ignored5;
    };
    struct {
        float _ignored6;
        Vec2 jk;
    };
    float e[3];
} Vec3;

typedef union Vec4 {
    struct {
        float x, y, z, w;
    };
    struct {
        float r, g, b, a;
    };
    struct {
        float s, t, u, v;
    };
    struct {
        Vec2 xy;
        float _ignored1, _ignored2;
    };
    struct {
        float _ignored3;
        Vec2 yz;
        float _ignored4;
    };
    struct {
        float _ignored5, _ignored6;
        Vec2 zw;
    };
    struct {
        Vec3 xyz;
        float _ignored7;
    };
    struct {
        float _ignored8;
        Vec3 yzw;
    };
    struct {
        Vec2 rg;
        float _ignored9, _ignored10;
    };
    struct {
        float _ignored11;
        Vec2 gb;
        float _ignored12;
    };
    struct {
        float _ignored13, _ignored14;
        Vec2 ba;
    };
    struct {
        Vec3 rgb;
        float _ignored15;
    };
    struct {
        float _ignored16;
        Vec3 gba;
    };
    struct {
        Vec2 st;
        float _ignored17, _ignored18;
    };
    struct {
        float _ignored19;
        Vec2 tu;
        float _ignored20;
    };
    struct {
        float _ignored21, _ignored22;
        Vec3 uv;
    };
    struct {
        Vec3 stu;
        float _ignored23;
    };
    struct {
        float _ignored24;
        Vec3 tuv;
    };
    float e[4];
} Vec4;

typedef union Quat {
    struct {
        union {
            Vec3 xyz;
            struct {
                float x, y, z;
            };
        };
        float w;
    };
    Vec4 xyzw;
    float e[4];
} Quat;

typedef union Mat2 {
    float e[2][2];
    Vec2 v[2];
} Mat2;

typedef union Mat3 {
    float e[3][3];
    Vec3 v[3];
} Mat3;

typedef union Mat4 {
    float e[4][4];
    Vec4 v[4];
} Mat4;

LINEAR_ALGEBRA_DEF Vec2 vec2(const float a, const float b);
LINEAR_ALGEBRA_DEF Vec2 vec2_add(const Vec2 a, const Vec2 b);
LINEAR_ALGEBRA_DEF Vec2 vec2_sub(const Vec2 a, const Vec2 b);
LINEAR_ALGEBRA_DEF Vec2 vec2_scale(const Vec2 a, const float scale);
LINEAR_ALGEBRA_DEF float vec2_dot(const Vec2 a, const Vec2 b);
LINEAR_ALGEBRA_DEF float vec2_length2(const Vec2 a);
LINEAR_ALGEBRA_DEF float vec2_length(const Vec2 a);
LINEAR_ALGEBRA_DEF Vec2 vec2_normalize(const Vec2 a);

LINEAR_ALGEBRA_DEF Vec3 vec3(const float a, const float b, const float c);
LINEAR_ALGEBRA_DEF Vec3 vec3_from_vec2(const Vec2 a, const float b);
LINEAR_ALGEBRA_DEF Vec3 vec3_add(const Vec3 a, const Vec3 b);
LINEAR_ALGEBRA_DEF Vec3 vec3_sub(const Vec3 a, const Vec3 b);
LINEAR_ALGEBRA_DEF Vec3 vec3_scale(const Vec3 a, const float scale);
LINEAR_ALGEBRA_DEF float vec3_dot(const Vec3 a, const Vec3 b);
LINEAR_ALGEBRA_DEF Vec3 vec3_cross(const Vec3 a, const Vec3 b);
LINEAR_ALGEBRA_DEF float vec3_length2(const Vec3 a);
LINEAR_ALGEBRA_DEF float vec3_length(const Vec3 a);
LINEAR_ALGEBRA_DEF Vec3 vec3_normalize(const Vec3 a);

LINEAR_ALGEBRA_DEF Vec4 vec4(const float a, const float b, const float c, const float d);
LINEAR_ALGEBRA_DEF Vec4 vec4_from_vec3(const Vec3 a, const float b);
LINEAR_ALGEBRA_DEF Vec4 vec4_add(const Vec4 a, const Vec4 b);
LINEAR_ALGEBRA_DEF Vec4 vec4_sub(const Vec4 a, const Vec4 b);
LINEAR_ALGEBRA_DEF Vec4 vec4_scale(const Vec4 a, const float scale);
LINEAR_ALGEBRA_DEF float vec4_dot(const Vec4 a, const Vec4 b);
LINEAR_ALGEBRA_DEF float vec4_length2(const Vec4 a);
LINEAR_ALGEBRA_DEF float vec4_length(const Vec4 a);
LINEAR_ALGEBRA_DEF Vec4 vec4_normalize(const Vec4 a);

LINEAR_ALGEBRA_DEF Quat quat(const float x, const float y, const float z, const float w);
LINEAR_ALGEBRA_DEF Quat quat_from_vec4(const Vec4 a);
LINEAR_ALGEBRA_DEF Quat quat_identity(void);
LINEAR_ALGEBRA_DEF Quat quat_add(const Quat a, const Quat b);
LINEAR_ALGEBRA_DEF Quat quat_sub(const Quat a, const Quat b);
LINEAR_ALGEBRA_DEF Quat quat_mul(const Quat a, const Quat b);
LINEAR_ALGEBRA_DEF Quat quat_scale(const Quat a, const float scale);
LINEAR_ALGEBRA_DEF float quat_dot(const Quat a, const Quat b);
LINEAR_ALGEBRA_DEF float quat_length2(const Quat a);
LINEAR_ALGEBRA_DEF float quat_length(const Quat a);
LINEAR_ALGEBRA_DEF Quat quat_normalize(const Quat a);
LINEAR_ALGEBRA_DEF Quat quat_inverse(const Quat a);
LINEAR_ALGEBRA_DEF Quat quat_slerp(const Quat a, const Quat b, const float t);
LINEAR_ALGEBRA_DEF Quat quat_nlerp(const Quat a, const Quat b, const float t);

LINEAR_ALGEBRA_DEF Mat2 mat2(void);
LINEAR_ALGEBRA_DEF Mat2 mat2_from_vec2(const Vec2 a, const Vec2 b);
LINEAR_ALGEBRA_DEF Mat2 mat2_diagonal(const float d);
LINEAR_ALGEBRA_DEF Mat2 mat2_identity(void);
LINEAR_ALGEBRA_DEF Mat2 mat2_add(const Mat2 a, const Mat2 b);
LINEAR_ALGEBRA_DEF Mat2 mat2_sub(const Mat2 a, const Mat2 b);
LINEAR_ALGEBRA_DEF Mat2 mat2_mul(const Mat2 a, const Mat2 b);
LINEAR_ALGEBRA_DEF Mat2 mat2_scale(const Mat2 a, const float s);
LINEAR_ALGEBRA_DEF Mat2 mat2_transpose(const Mat2 a);
LINEAR_ALGEBRA_DEF float mat2_determinant(const Mat2 a);
LINEAR_ALGEBRA_DEF Mat2 mat2_inverse(const Mat2 a);

LINEAR_ALGEBRA_DEF Mat3 mat3(void);
LINEAR_ALGEBRA_DEF Mat3 mat3_from_vec3(const Vec3 a, const Vec3 b, const Vec3 c);
LINEAR_ALGEBRA_DEF Mat3 mat3_diagonal(const float d);
LINEAR_ALGEBRA_DEF Mat3 mat3_identity(void);
LINEAR_ALGEBRA_DEF Mat3 mat3_add(const Mat3 a, const Mat3 b);
LINEAR_ALGEBRA_DEF Mat3 mat3_sub(const Mat3 a, const Mat3 b);
LINEAR_ALGEBRA_DEF Mat3 mat3_mul(const Mat3 a, const Mat3 b);
LINEAR_ALGEBRA_DEF Mat3 mat3_scale(const Mat3 a, const float s);
LINEAR_ALGEBRA_DEF Mat3 mat3_transpose(const Mat3 a);
LINEAR_ALGEBRA_DEF float mat3_determinant(const Mat3 a);
LINEAR_ALGEBRA_DEF Mat3 mat3_inverse(const Mat3 a);

LINEAR_ALGEBRA_DEF Mat4 mat4(void);
LINEAR_ALGEBRA_DEF Mat4 mat4_from_vec4(const Vec4 a, const Vec4 b, const Vec4 c, const Vec4 d);
LINEAR_ALGEBRA_DEF Mat4 mat4_diagonal(const float d);
LINEAR_ALGEBRA_DEF Mat4 mat4_identity(void);
LINEAR_ALGEBRA_DEF Mat4 mat4_orthographic(const float left, const float right, const float bottom, const float top, const float znear, const float zfar);
LINEAR_ALGEBRA_DEF Mat4 mat4_perspective(const float fov, const float aspect_ratio, const float znear, const float zfar);
LINEAR_ALGEBRA_DEF Mat4 mat4_translate(const Vec3 a);
LINEAR_ALGEBRA_DEF Mat4 mat4_translatef(const float x, const float y, const float z);
LINEAR_ALGEBRA_DEF Mat4 mat4_rotate(const float degrees, const Vec3 axis);
LINEAR_ALGEBRA_DEF Mat4 mat4_rotate_x(const float degrees);
LINEAR_ALGEBRA_DEF Mat4 mat4_rotate_y(const float degrees);
LINEAR_ALGEBRA_DEF Mat4 mat4_rotate_z(const float degrees);
LINEAR_ALGEBRA_DEF Mat4 mat4_scale(const Vec3 a);
LINEAR_ALGEBRA_DEF Mat4 mat4_scalef(const float x, const float y, const float z);
LINEAR_ALGEBRA_DEF Mat4 mat4_shear(const float s);
LINEAR_ALGEBRA_DEF Mat4 mat4_add(const Mat4 a, const Mat4 b);
LINEAR_ALGEBRA_DEF Mat4 mat4_sub(const Mat4 a, const Mat4 b);
LINEAR_ALGEBRA_DEF Mat4 mat4_mul(const Mat4 a, const Mat4 b);
LINEAR_ALGEBRA_DEF Mat4 mat4_transpose(const Mat4 a);
LINEAR_ALGEBRA_DEF float mat4_determinant(const Mat4 a);
LINEAR_ALGEBRA_DEF Mat4 mat4_inverse(const Mat4 a);

//=============================================================================
//
//
//  IMPLEMENTATION
//
//
//=============================================================================
#ifdef LINEAR_ALGEBRA_IMPLEMENTATION

LINEAR_ALGEBRA_INLINE Vec2 vec2(const float a, const float b) {
    Vec2 r = { 0 };
    r.x = a;
    r.y = b;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec2 vec2_add(const Vec2 a, const Vec2 b) {
    Vec2 r = { 0 };
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec2 vec2_sub(const Vec2 a, const Vec2 b) {
    Vec2 r = { 0 };
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec2 vec2_scale(const Vec2 a, const float scale) {
    Vec2 r = { 0 };
    r.x = scale * a.x;
    r.y = scale * a.y;
    return r;
}

LINEAR_ALGEBRA_INLINE float vec2_dot(const Vec2 a, const Vec2 b) {
    float r = 0.0f;
    r = (a.x * b.x) + (a.y * b.y);
    return r;
}

LINEAR_ALGEBRA_INLINE float vec2_length2(const Vec2 a) {
    float r = 0.0f;
    r = vec2_dot(a, a);
    return r;
}

LINEAR_ALGEBRA_INLINE float vec2_length(const Vec2 a) {
    float r = 0.0f;
    r = LINEAR_ALGEBRA_SQRTF(vec2_length2(a));
    return r;
}

LINEAR_ALGEBRA_INLINE Vec2 vec2_normalize(const Vec2 a) {
    Vec2 r = { 0 };
    float length = vec2_length(a);
    if(length != 0.0f) { 
        r = vec2_scale(a, 1.0f / length);
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3(const float a, const float b, const float c) {
    Vec3 r = { 0 };
    r.x = a;
    r.y = b;
    r.z = c;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3_from_vec2(const Vec2 a, const float b) {
    Vec3 r = { 0 };
    r.x = a.x;
    r.y = a.y;
    r.z = b;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3_add(const Vec3 a, const Vec3 b) {
    Vec3 r = { 0 };
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3_sub(const Vec3 a, const Vec3 b) {
    Vec3 r = { 0 };
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3_scale(const Vec3 a, const float scale) {
    Vec3 r = { 0 };
    r.x = scale * a.x;
    r.y = scale * a.y;
    r.z = scale * a.z;
    return r;
}

LINEAR_ALGEBRA_INLINE float vec3_dot(const Vec3 a, const Vec3 b) {
    float r = 0.0f;
    r = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    return r;
}

LINEAR_ALGEBRA_INLINE 
float vec3_length2(const Vec3 a) {
    float r = 0.0f;
    r = vec3_dot(a,a);
    return r;
}

LINEAR_ALGEBRA_INLINE float vec3_length(const Vec3 a) {
    float r = 0.0f;
    r = LINEAR_ALGEBRA_SQRTF(vec3_length2(a));
    return r;
}

LINEAR_ALGEBRA_INLINE Vec3 vec3_normalize(const Vec3 a) {
    Vec3 r = { 0 };
    float length = vec3_length(a);
    if(length != 0.0f) { 
        r = vec3_scale(a, 1.0f / length);
    }
    return r;
}

/*
 *
 *  x y z  
 *          =   (yb-zg)     -(xb-zr)    (xg-yr)
 *  r g b
 *
 *
 */
LINEAR_ALGEBRA_INLINE Vec3 vec3_cross(const Vec3 a, const Vec3 b) {
    Vec3 r = { 0 };
    r.x = a.y * b.z - a.z * b.y;
    r.y = -a.x * b.z + a.z * b.x;
    r.z = a.x * b.y - a.y * b.x;
    return r;
}


LINEAR_ALGEBRA_INLINE Vec4 vec4(const float a, const float b, const float c, const float d) {
    Vec4 r = { 0 };
    r.x = a;
    r.y = b;
    r.z = c;
    r.w = d;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec4 vec4_from_vec3(const Vec3 a, const float b) {
    Vec4 r = { 0 };
    r.x = a.x;
    r.y = a.y;
    r.z = a.z;
    r.w = b;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec4 vec4_add(const Vec4 a, const Vec4 b) {
    Vec4 r = { 0 };
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec4 vec4_sub(const Vec4 a, const Vec4 b) {
    Vec4 r = { 0 };
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Vec4 vec4_scale(const Vec4 a, const float scale) {
    Vec4 r = { 0 };
    r.x = scale * a.x;
    r.y = scale * a.y;
    r.z = scale * a.z;
    r.w = scale * a.w;
    return r;
}

LINEAR_ALGEBRA_INLINE float vec4_dot(const Vec4 a, const Vec4 b) {
    float r = 0.0f;
    r = (a.x * b.x) + (a.y * b.y) + (a.z + b.z) + (a.w * b.w);
    return r;
}

LINEAR_ALGEBRA_INLINE float vec4_length2(const Vec4 a) {
    float r = 0.0f;
    r = vec4_dot(a, a);
    return r;
}

LINEAR_ALGEBRA_INLINE float vec4_length(const Vec4 a) {
    float r = 0.0f;
    r = LINEAR_ALGEBRA_SQRTF(vec4_length2(a));
    return r;
}

LINEAR_ALGEBRA_INLINE Vec4 vec4_normalize(const Vec4 a) {
    Vec4 r = { 0 };
    float length = vec4_length(a);
    if(length != 0.0f) { 
        r = vec4_scale(a, 1.0f / length);
    }
    return r;
}


LINEAR_ALGEBRA_INLINE Quat quat(const float x, const float y, const float z, const float w) {
    Quat r = { 0 };
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = w;
    return r;
}


LINEAR_ALGEBRA_INLINE Quat quat_from_vec4(const Vec4 a) {
    Quat r = { 0 };
    r.x = a.x;
    r.y = a.y;
    r.z = a.z;
    r.w = a.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_identity(void) {
    Quat r = { 0 };
    r.w = 1;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_conjugate(const Quat a) {
    Quat r = { 0 };
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    r.w = a.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_add(const Quat a, const Quat b) {
    Quat r = { 0 };
    r.xyz = vec3_add(a.xyz, b.xyz);
    r.w = a.w + b.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_sub(const Quat a, const Quat b) {
    Quat r = { 0 };
    r.xyz = vec3_sub(a.xyz, b.xyz);
    r.w = a.w - b.w;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_mul(const Quat a, const Quat b) {
    Quat r = { 0 };
    r.xyz = vec3_add(
            vec3_cross(a.xyz, b.xyz),
            vec3_add(vec3_scale(a.xyz, b.w), vec3_scale(b.xyz, a.w)));
    r.w = a.w * b.w - vec3_dot(a.xyz, b.xyz);
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_scale(const Quat a, const float scale) {
    Quat r = { 0 };
    r.x = scale * a.x;
    r.y = scale * a.y;
    r.z = scale * a.z;
    r.w = scale * a.w;
    return r;
}

LINEAR_ALGEBRA_INLINE float quat_dot(const Quat a, const Quat b) {
    float r = 0.0f;
    r = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return r;
}

LINEAR_ALGEBRA_INLINE float quat_length2(const Quat a) {
    float r = 0.0f;
    r = quat_dot(a, a);
    return r;
}

LINEAR_ALGEBRA_INLINE float quat_length(const Quat a) {
    float r = 0.0f;
    r = LINEAR_ALGEBRA_SQRTF(quat_length2(a));
    return r;
}


LINEAR_ALGEBRA_INLINE Quat quat_normalize(const Quat a) {
    Quat r = { 0 };
    float d = 1.0f / quat_length(a);
    r.x = a.x * d;
    r.y = a.y * d;
    r.z = a.z * d;
    r.w = a.w * d;
    return r;
}

LINEAR_ALGEBRA_INLINE Quat quat_inverse(const Quat a) {
    Quat r = quat_conjugate(a);
    float s = 1.0f / quat_length2(a);
    r.x *= s;
    r.y *= s;
    r.z *= s;
    r.w *= s;
    return r;
}

// TODO(rayalan): wip
LINEAR_ALGEBRA_DEF Quat quat_slerp(const Quat a, const Quat b, const float t) { 
    Quat r = { 0 };
    float cos_theta = quat_dot(a, b);
    float phi = LINEAR_ALGEBRA_ACOSF(cos_theta);
    float sin_phi = LINEAR_ALGEBRA_SINF(phi);
    float s1 = LINEAR_ALGEBRA_SINF(phi * (1.0f - t)) / sin_phi;
    float s2 = LINEAR_ALGEBRA_SINF(phi * t) / sin_phi;
    Quat q1 = quat_scale(a, s1);
    Quat q2 = quat_scale(b, s2);
    return quat_add(q1, q2);
}

LINEAR_ALGEBRA_DEF Quat quat_nlerp(const Quat a, const Quat b, const float t) {
    Quat r = { 0 };

    r.x = a.x + t * (b.x - a.x);
    r.y = a.y + t * (b.y - a.y);
    r.z = a.z + t * (b.z - a.z);
    r.w = a.w + t * (b.w - a.w);

    return quat_normalize(r);
}

LINEAR_ALGEBRA_INLINE Mat2 mat2(void) {
    Mat2 r = { 0 };
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_from_vec2(const Vec2 a, const Vec2 b) {
    Mat2 r = { 0 };
    r.v[0] = a;
    r.v[1] = b;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_diagonal(const float d) {
    Mat2 r = { 0 };
    int i;
    for(i = 0; i < 2; i++) {
        r.e[i][i] = d;
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_identity(void) {
    return mat2_diagonal(1.0f);
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_add(const Mat2 a, const Mat2 b) {
    Mat2 r = { 0 };
    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            r.e[i][j] = a.e[i][j] + b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_sub(const Mat2 a, const Mat2 b) {
    Mat2 r = { 0 };
    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            r.e[i][j] = a.e[i][j] - b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_mul(const Mat2 a, const Mat2 b) {
    Mat2 r = { 0 };
    int i, j, k;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
           for(k = 0; k < 2; k++) {
                r.e[i][j] += a.e[i][k] * b.e[k][j];
           }
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_transpose(const Mat2 a) {
    Mat2 r = { 0 };
    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            r.e[i][j] = a.e[j][i];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_scale(const Mat2 a, const float scale) {
    Mat2 r = { 0 };
    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            r.e[i][j] = scale * a.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE float mat2_determinant(const Mat2 a) {
    return a.e[0][0] * a.e[1][1] - a.e[0][1] * a.e[1][0];
}

LINEAR_ALGEBRA_INLINE Mat2 mat2_inverse(const Mat2 a) {
    Mat2 r = { 0 };
    float d = mat2_determinant(a);
    r.e[0][0] =  a.e[1][1]; r.e[0][1] = -a.e[0][1];
    r.e[1][0] = -a.e[1][0]; r.e[1][1] =  a.e[0][0];
    return mat2_scale(r, 1.0f/d);
}

LINEAR_ALGEBRA_INLINE Mat3 mat3(void) {
    Mat3 r = { 0 };
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_from_vec3(const Vec3 a, const Vec3 b, const Vec3 c) {
    Mat3 r = { 0 };
    r.v[0] = a;
    r.v[1] = b;
    r.v[2] = c;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_diagonal(const float d) {
    Mat3 r = { 0 };
    int i;
    for(i = 0; i < 3; i++) {
        r.e[i][i] = d;
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_identity(void) {
    return mat3_diagonal(1.0f);
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_add(const Mat3 a, const Mat3 b) {
    Mat3 r = { 0 };
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            r.e[i][j] = a.e[i][j] + b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_sub(const Mat3 a, const Mat3 b) {
    Mat3 r = { 0 };
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            r.e[i][j] = a.e[i][j] - b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_mul(const Mat3 a, const Mat3 b) {
    Mat3 r = { 0 };
    int i, j, k;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
           for(k = 0; k < 3; k++) {
               r.e[i][j] += a.e[i][k] * b.e[k][j];
           }
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_transpose(const Mat3 a) {
    Mat3 r = { 0 };
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            r.e[i][j] = a.e[j][i];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_scale(const Mat3 a, const float scale) {
    Mat3 r = { 0 };
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            r.e[i][j] = scale * a.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE float mat3_determinant(const Mat3 a) {
    return (
         (a.e[0][0] * a.e[1][1] * a.e[2][2])
        +(a.e[0][1] * a.e[1][2] * a.e[2][0])
        +(a.e[0][2] * a.e[1][0] * a.e[2][1])
        -(a.e[0][1] * a.e[1][0] * a.e[2][2])
        -(a.e[0][0] * a.e[1][2] * a.e[2][1])
        -(a.e[0][2] * a.e[1][1] * a.e[2][0])
    );
}

LINEAR_ALGEBRA_INLINE Mat3 mat3_inverse(const Mat3 a) {
    Mat3 r;
    float d = mat3_determinant(a);

    r.e[0][0] = a.e[1][1]*a.e[2][2] - a.e[1][2]*a.e[2][1];
    r.e[0][1] = a.e[0][2]*a.e[2][1] - a.e[0][1]*a.e[2][2];
    r.e[0][2] = a.e[0][1]*a.e[1][2] - a.e[0][2]*a.e[1][1];

    r.e[1][0] = a.e[1][2]*a.e[2][0] - a.e[1][0]*a.e[2][2];
    r.e[1][1] = a.e[0][0]*a.e[2][2] - a.e[0][2]*a.e[2][0];
    r.e[1][2] = a.e[0][2]*a.e[1][0] - a.e[0][0]*a.e[1][2];

    r.e[2][0] = a.e[1][0]*a.e[2][1] - a.e[1][1]*a.e[2][0];
    r.e[2][1] = a.e[0][1]*a.e[2][0] - a.e[0][0]*a.e[2][1];
    r.e[2][2] = a.e[0][0]*a.e[1][1] - a.e[0][1]*a.e[1][0];


    return mat3_scale(r, 1.0f/d);
}

LINEAR_ALGEBRA_INLINE Mat4 mat4(void) {
    Mat4 r = { 0 };
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_from_vec4(const Vec4 a, const Vec4 b, const Vec4 c, const Vec4 d) {
    Mat4 r = { 0 };
    r.v[0] = a;
    r.v[1] = b;
    r.v[2] = c;
    r.v[3] = d;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_diagonal(const float d) {
    Mat4 r = { 0 };
    int i;
    for(i = 0; i < 4; i++) {
        r.e[i][i] = d;
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_identity(void) {
    return mat4_diagonal(1.0f);
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_orthographic(const float left, const float right, const float bottom, const float top, const float znear, const float zfar) {
    Mat4 r = { 0 };

    r.e[0][0] = 2.0f / (right - left);
    r.e[1][1] = 2.0f / (top - bottom);
    r.e[2][2] = 2.0f / (znear - zfar);
    r.e[3][3] = 1.0f;

    r.e[0][3] = -(right + left)/(right - left);
    r.e[1][3] = -(top + bottom)/(top - bottom);
    r.e[2][3] = -(zfar + znear)/(zfar - znear);

    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_perspective(const float fov, const float aspect_ratio, const float znear, const float zfar) {
    Mat4 r = { 0 };
    float tto2 = LINEAR_ALGEBRA_TANF(fov * LINEAR_ALGEBRA_PI_OVER_360);

    r.e[0][0] = 1.0f / tto2;
    r.e[1][1] = aspect_ratio / tto2;
    r.e[2][2] = (znear + zfar) / (znear - zfar);
    r.e[2][3] = (2 * znear * zfar) / (znear - zfar);
    r.e[3][2] = -1.0f;

    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_translate(const Vec3 a) {
    Mat4 r = mat4_identity();
    r.e[0][3] = a.x;
    r.e[1][3] = a.y;
    r.e[2][3] = a.z;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_translatef(const float x, const float y, const float z) {
    Mat4 r = mat4_identity();
    r.e[0][3] = x;
    r.e[1][3] = y;
    r.e[2][3] = z;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_rotate(const float degrees, const Vec3 axis) {
    Mat4 r = mat4_identity();
    Vec3 a = vec3_normalize(axis);
    
    float sin_theta = LINEAR_ALGEBRA_SINF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    float cos_theta = LINEAR_ALGEBRA_COSF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    float one_minus_cos = 1.0f - cos_theta;

    r.e[0][0] = cos_theta + a.x * a.x * one_minus_cos;
    r.e[0][1] = a.x * a.y * one_minus_cos - a.z * sin_theta;
    r.e[0][2] = a.x * a.z * one_minus_cos + a.y * sin_theta;
    
    r.e[1][0] = a.y * a.x * one_minus_cos + a.z * sin_theta;
    r.e[1][1] = cos_theta + a.y * a.y * one_minus_cos;
    r.e[1][2] = a.y * a.z * one_minus_cos - a.x * sin_theta;

    r.e[2][0] = a.z * a.x * one_minus_cos - a.y * sin_theta;
    r.e[2][1] = a.z * a.y * one_minus_cos + a.x * sin_theta;
    r.e[2][2] = cos_theta + a.z * a.z * one_minus_cos;

    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_rotate_x(const float degrees) {
    Mat4 r = mat4_identity();

    r.e[1][1] = LINEAR_ALGEBRA_COSF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[2][2] = r.e[1][1];

    r.e[2][1] = LINEAR_ALGEBRA_SINF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[1][2] = -r.e[2][1];
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_rotate_y(const float degrees) {
    Mat4 r = mat4_identity();
    
    r.e[0][0] = LINEAR_ALGEBRA_COSF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[2][2] = r.e[0][0];

    r.e[0][2] = LINEAR_ALGEBRA_SINF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[2][0] = -r.e[0][2];

    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_rotate_z(const float degrees) {
    Mat4 r = mat4_identity();
    
    r.e[0][0] = LINEAR_ALGEBRA_COSF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[1][1] = r.e[0][0];

    r.e[1][0] = LINEAR_ALGEBRA_SINF(degrees * LINEAR_ALGEBRA_PI_OVER_180);
    r.e[0][1] = -r.e[1][0];
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_scale(const Vec3 a) { 
    Mat4 r = { 0 };
    r.e[0][0] = a.x;
    r.e[1][1] = a.y;
    r.e[2][2] = a.z;
    r.e[3][3] = 1.0f;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_scalef(const float x, const float y, const float z) {
    Mat4 r = { 0 };
    r.e[0][0] = x;
    r.e[1][1] = y;
    r.e[2][2] = z;
    r.e[3][3] = 1.0f;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_shear(const float s) {
    Mat4 r = mat4_identity();
    r.e[0][2] = s;
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_add(const Mat4 a, const Mat4 b) {
    Mat4 r = { 0 };
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            r.e[i][j] = a.e[i][j] + b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_sub(const Mat4 a, const Mat4 b) {
    Mat4 r = { 0 };
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            r.e[i][j] = a.e[i][j] - b.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_mul(const  Mat4 a, const Mat4 b) {
    Mat4 r = { 0 };
    int i, j, k;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
           for(k = 0; k < 4; k++) {
               r.e[i][j] += a.e[i][k] * b.e[k][j];
           }
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_transpose(const Mat4 a) {
    Mat4 r = { 0 };
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            r.e[i][j] = a.e[j][i];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_scale(const Mat4 a, const float scale) {
    Mat4 r = { 0 };
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            r.e[i][j] = scale * a.e[i][j];
        }
    }
    return r;
}

LINEAR_ALGEBRA_INLINE float mat4_determinant(const Mat4 a) {
    float r = 0.0f;
    r =   a.e[0][0]*a.e[1][1]*a.e[2][2]*a.e[3][3] 
        + a.e[0][0]*a.e[1][2]*a.e[2][3]*a.e[3][1]
        + a.e[0][0]*a.e[1][3]*a.e[2][1]*a.e[3][2]
        + a.e[0][1]*a.e[1][0]*a.e[2][3]*a.e[3][2]
        + a.e[0][1]*a.e[1][2]*a.e[2][0]*a.e[3][3]
        + a.e[0][1]*a.e[1][3]*a.e[2][2]*a.e[3][0]
        + a.e[0][2]*a.e[1][0]*a.e[2][1]*a.e[3][3]
        + a.e[0][2]*a.e[1][1]*a.e[2][3]*a.e[3][0]
        + a.e[0][2]*a.e[1][3]*a.e[2][0]*a.e[3][1]
        + a.e[0][3]*a.e[1][0]*a.e[2][2]*a.e[3][1]
        + a.e[0][3]*a.e[1][1]*a.e[2][0]*a.e[3][2]
        + a.e[0][3]*a.e[1][2]*a.e[2][1]*a.e[3][0]
        - a.e[0][0]*a.e[1][1]*a.e[2][3]*a.e[3][2]
        - a.e[0][0]*a.e[1][2]*a.e[2][1]*a.e[3][3]
        - a.e[0][0]*a.e[1][3]*a.e[2][2]*a.e[3][1]
        - a.e[0][1]*a.e[1][0]*a.e[2][2]*a.e[3][3]
        - a.e[0][1]*a.e[1][2]*a.e[2][3]*a.e[3][0]
        - a.e[0][1]*a.e[1][3]*a.e[2][0]*a.e[3][2]
        - a.e[0][2]*a.e[1][0]*a.e[2][3]*a.e[3][1]
        - a.e[0][2]*a.e[1][1]*a.e[2][0]*a.e[3][3]
        - a.e[0][2]*a.e[1][3]*a.e[2][1]*a.e[3][0]
        - a.e[0][3]*a.e[1][0]*a.e[2][1]*a.e[3][2]
        - a.e[0][3]*a.e[1][1]*a.e[2][2]*a.e[3][0]
        - a.e[0][3]*a.e[1][2]*a.e[2][0]*a.e[3][1];
    return r;
}

// NOTE(rayalan): this is the lazy slow way to do this
LINEAR_ALGEBRA_INLINE Mat4 mat4_inverse(const Mat4 a) {
    Mat4 r = { 0 };
    double d = mat4_determinant(a);

    r.e[0][0] =    a.e[1][2]*a.e[2][3]*a.e[3][1] + a.e[1][3]*a.e[2][1]*a.e[3][2] + a.e[1][1]*a.e[2][2]*a.e[3][3];
    r.e[0][0] += - a.e[1][3]*a.e[2][2]*a.e[3][1] - a.e[1][1]*a.e[2][3]*a.e[3][2] - a.e[1][2]*a.e[2][1]*a.e[3][3];

    r.e[0][1] =    a.e[0][3]*a.e[2][2]*a.e[3][1] + a.e[0][1]*a.e[2][3]*a.e[3][2] + a.e[0][2]*a.e[2][1]*a.e[3][3];
    r.e[0][1] += - a.e[0][2]*a.e[2][3]*a.e[3][1] - a.e[0][3]*a.e[2][1]*a.e[3][2] - a.e[0][1]*a.e[2][2]*a.e[3][3];

    r.e[0][2] =    a.e[0][2]*a.e[1][3]*a.e[3][1] + a.e[0][3]*a.e[1][1]*a.e[3][2] + a.e[0][1]*a.e[1][2]*a.e[3][3];
    r.e[0][2] += - a.e[0][3]*a.e[1][2]*a.e[3][1] - a.e[0][1]*a.e[1][3]*a.e[3][2] - a.e[0][2]*a.e[1][1]*a.e[3][3];

    r.e[0][3] =    a.e[0][3]*a.e[1][2]*a.e[2][1] + a.e[0][1]*a.e[1][3]*a.e[2][2] + a.e[0][2]*a.e[1][1]*a.e[2][3];
    r.e[0][3] += - a.e[0][2]*a.e[1][3]*a.e[2][1] - a.e[0][3]*a.e[1][1]*a.e[2][2] - a.e[0][1]*a.e[1][2]*a.e[2][3];

    r.e[1][0] =    a.e[1][3]*a.e[2][2]*a.e[3][0] + a.e[1][0]*a.e[2][3]*a.e[3][2] + a.e[1][2]*a.e[2][0]*a.e[3][3];
    r.e[1][0] += - a.e[1][2]*a.e[2][3]*a.e[3][0] - a.e[1][3]*a.e[2][0]*a.e[3][2] - a.e[1][0]*a.e[2][2]*a.e[3][3];

    r.e[1][1] =    a.e[0][2]*a.e[2][3]*a.e[3][0] + a.e[0][3]*a.e[2][0]*a.e[3][2] + a.e[0][0]*a.e[2][2]*a.e[3][3];
    r.e[1][1] += - a.e[0][3]*a.e[2][2]*a.e[3][0] - a.e[0][0]*a.e[2][3]*a.e[3][2] - a.e[0][2]*a.e[2][0]*a.e[3][3];

    r.e[1][2] =    a.e[0][3]*a.e[1][2]*a.e[3][0] + a.e[0][0]*a.e[1][3]*a.e[3][2] + a.e[0][2]*a.e[1][0]*a.e[3][3];
    r.e[1][2] += - a.e[0][2]*a.e[1][3]*a.e[3][0] - a.e[0][3]*a.e[1][0]*a.e[3][2] - a.e[0][0]*a.e[1][2]*a.e[3][3];

    r.e[1][3] =    a.e[0][2]*a.e[1][3]*a.e[2][0] + a.e[0][3]*a.e[1][0]*a.e[2][2] + a.e[0][0]*a.e[1][2]*a.e[2][3];
    r.e[1][3] += - a.e[0][3]*a.e[1][2]*a.e[2][0] - a.e[0][0]*a.e[1][3]*a.e[2][2] - a.e[0][2]*a.e[1][0]*a.e[2][3];

    r.e[2][0] =    a.e[1][1]*a.e[2][3]*a.e[3][0] + a.e[1][3]*a.e[2][0]*a.e[3][1] + a.e[1][0]*a.e[2][1]*a.e[3][3];
    r.e[2][0] += - a.e[1][3]*a.e[2][1]*a.e[3][0] - a.e[1][0]*a.e[2][3]*a.e[3][1] - a.e[1][1]*a.e[2][0]*a.e[3][3];

    r.e[2][1] =    a.e[0][3]*a.e[2][1]*a.e[3][0] + a.e[0][0]*a.e[2][3]*a.e[3][1] + a.e[0][1]*a.e[2][0]*a.e[3][3];
    r.e[2][1] += - a.e[0][1]*a.e[2][3]*a.e[3][0] - a.e[0][3]*a.e[2][0]*a.e[3][1] - a.e[0][0]*a.e[2][1]*a.e[3][3];

    r.e[2][2] =    a.e[0][1]*a.e[1][3]*a.e[3][0] + a.e[0][3]*a.e[1][0]*a.e[3][1] + a.e[0][0]*a.e[1][1]*a.e[3][3];
    r.e[2][2] += - a.e[0][3]*a.e[1][1]*a.e[3][0] - a.e[0][0]*a.e[1][3]*a.e[3][1] - a.e[0][1]*a.e[1][0]*a.e[3][3];

    r.e[2][3] =    a.e[0][3]*a.e[1][1]*a.e[2][0] + a.e[0][0]*a.e[1][3]*a.e[2][1] + a.e[0][1]*a.e[1][0]*a.e[2][3];
    r.e[2][3] += - a.e[0][1]*a.e[1][3]*a.e[2][0] - a.e[0][3]*a.e[1][0]*a.e[2][1] - a.e[0][0]*a.e[1][1]*a.e[2][3];

    r.e[3][0] =    a.e[1][2]*a.e[2][1]*a.e[3][0] + a.e[1][0]*a.e[2][2]*a.e[3][1] + a.e[1][1]*a.e[2][0]*a.e[3][2];
    r.e[3][0] += - a.e[1][1]*a.e[2][2]*a.e[3][0] - a.e[1][2]*a.e[2][0]*a.e[3][1] - a.e[1][0]*a.e[2][1]*a.e[3][2];

    r.e[3][1] =    a.e[0][1]*a.e[2][2]*a.e[3][0] + a.e[0][2]*a.e[2][0]*a.e[3][1] + a.e[0][0]*a.e[2][1]*a.e[3][2];
    r.e[3][1] += - a.e[0][2]*a.e[2][1]*a.e[3][0] - a.e[0][0]*a.e[2][2]*a.e[3][1] - a.e[0][1]*a.e[2][0]*a.e[3][2];

    r.e[3][2] =    a.e[0][2]*a.e[1][1]*a.e[3][0] + a.e[0][0]*a.e[1][2]*a.e[3][1] + a.e[0][1]*a.e[1][0]*a.e[3][2];
    r.e[3][2] += - a.e[0][1]*a.e[1][2]*a.e[3][0] - a.e[0][2]*a.e[1][0]*a.e[3][1] - a.e[0][0]*a.e[1][1]*a.e[3][2];

    r.e[3][3] =    a.e[0][1]*a.e[1][2]*a.e[2][0] + a.e[0][2]*a.e[1][0]*a.e[2][1] + a.e[0][0]*a.e[1][1]*a.e[2][2];
    r.e[3][3] += - a.e[0][2]*a.e[1][1]*a.e[2][0] - a.e[0][0]*a.e[1][2]*a.e[2][1] - a.e[0][1]*a.e[1][0]*a.e[2][2];

    return mat4_scale(r, 1.0f/d);
}

LINEAR_ALGEBRA_INLINE Mat4 mat4_look_at(const Vec3 eye, const Vec3 at, const Vec3 up) {
    Mat4 r = { 0 };

    // NOTE(rayalan): 
    Vec3 cam_dir = vec3_normalize(vec3_sub(eye, at));
    Vec3 cam_right = vec3_normalize(vec3_cross(up, cam_dir));
    Vec3 cam_up = vec3_normalize(vec3_cross(cam_dir, cam_right));

    r.e[0][0] = cam_right.x;
    r.e[0][1] = cam_right.y;
    r.e[0][2] = cam_right.z;
    r.e[0][3] = -vec3_dot(cam_right, eye);
    
    r.e[1][0] = cam_up.x,
    r.e[1][1] = cam_up.y,
    r.e[1][2] = cam_up.z,
    r.e[1][3] = -vec3_dot(cam_up, eye);
    
    r.e[2][0] = cam_dir.x;
    r.e[2][1] = cam_dir.y;
    r.e[2][2] = cam_dir.z;
    r.e[2][3] = -vec3_dot(cam_dir, eye);

    r.e[3][3] = 1.0f;

    return r;
}

#endif /* LINEAR_ALGEBRA_IMPLEMENTATION */
#endif /* LINEAR_ALGEBRA_INCLUDE */

/*
------------------------------------------------------------------------------
This software is available under 2 licenses -- choose whichever you prefer.
------------------------------------------------------------------------------
ALTERNATIVE A - MIT License
Copyright (c) 2017 Rayalan Kenyon
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
------------------------------------------------------------------------------
ALTERNATIVE B - Public Domain (www.unlicense.org)
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.
In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------------------------------
*/
