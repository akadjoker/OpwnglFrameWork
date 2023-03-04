/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:25:34 by lrosa-do          #+#    #+#             */
/*   Updated: 2023/03/03 17:41:34 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "pch.hpp"

#define MATH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
#define MATH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
#define MATH_RANDOM_MINUS1_1()      ((2.0f*((float)rand()/RAND_MAX))-1.0f)      // Returns a random float between -1 and 1.
#define MATH_RANDOM_0_1()           ((float)rand()/RAND_MAX)                    // Returns a random float between 0 and 1.
#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_E                      2.71828182845904523536f
#define MATH_LOG10E                 0.4342944819032518f
#define MATH_LOG2E                  1.442695040888963387f
#define MATH_PI                     3.14159265358979323846f
#define MATH_PIOVER2                1.57079632679489661923f
#define MATH_PIOVER4                0.785398163397448309616f
#define MATH_PIX2                   6.28318530717958647693f
#define MATH_EPSILON                0.000001f
#define MATH_CLAMP(x, lo, hi)       ((x < lo) ? lo : ((x > hi) ? hi : x))
#define M_1_PI                      0.31830988618379067154
#define SMALL_FLOAT 0.000001f
//#define PI 3.14159265358979323846f
#define EPSILON 0.000001f
#define DEG2RAD (PI/180.0f)
#define RAD2DEG (180.0f/PI)
#define DEG_CIRCLE 360
#define DEG_TO_RAD (M_PI / (DEG_CIRCLE / 2))
#define RAD_TO_DEG ((DEG_CIRCLE / 2) / M_PI)
const float PI = 3.14159265359f;
const float RECIPROCAL_PI = 1.0f/PI;
const float HALF_PI = PI/2.0f;

const unsigned int MaxUInt32 = 0xFFFFFFFF;
const int MinInt32 = 0x80000000;
const int MaxInt32 = 0x7FFFFFFF;
const float MaxFloat = 3.402823466e+38F;
const float MinPosFloat = 1.175494351e-38F;

const float Pi = 3.141592654f;
const float TwoPi = 6.283185307f;
const float PiHalf = 1.570796327f;

const float Epsilon = 0.000001f;
const float ZeroEpsilon = 32.0f * MinPosFloat;  // Very small epsilon for checking against 0.0f

enum NoInitHint
{
    NO_INIT
};

inline double	module(double a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

inline bool isnotzero(const float a, const float tolerance=Epsilon)
{
	return fabsf(a) > tolerance;
}

inline bool isequal(const float a, const float b,const float tolerance=Epsilon)
{
	if (fabs(b-a) <= tolerance)
            return true;
        else
            return false;
}

inline double	radians(double degrees)
{
	return (degrees / 180 * PI);
}

inline double deg2rad(double degrees)
{
    return degrees * DEG_TO_RAD;
}

inline double rad2deg(double radians)
{
    return radians * RAD_TO_DEG;
}


inline double cosdeg(double degrees)
{
	return cos(deg2rad(degrees));
}

inline double sindeg(double degrees)
{
	return sin(deg2rad(degrees));
}

inline double tandeg(double degrees)
{
	return tan(deg2rad(degrees));
}

inline double acosdeg(double val)
{
	return rad2deg(acos(val));
}

inline double asindeg(double val)
{
	return rad2deg(asin(val));
}

inline double atandeg(double val)
{
	return rad2deg(atan(val));
}

inline double atan2deg(double val,double val2)
{
	return rad2deg(atan2(val,val2));
}

inline bool	equal(double a, double b)
{
	return (module(a - b) < EPSILON);
}
inline float degToRad( float f )
{
	return f * 0.017453293f;
}

inline float radToDeg( float f )
{
	return f * 57.29577951f;
}

inline float clamp( float f, float min, float max )
{
	if( f < min ) f = min;
	else if( f > max ) f = max;

	return f;
}

inline float minf( float a, float b )
{
	return a < b ? a : b;
}

inline float maxf( float a, float b )
{
	return a > b ? a : b;
}

inline float fsel( float test, float a, float b )
{
	// Branchless selection
	return test >= 0 ? a : b;
}

// Computes a/b, rounded up
// To be used for positive a and b and small numbers (beware of overflows)
inline int idivceil( int a, int b )
{
	return (a + b - 1) / b;
}


// -------------------------------------------------------------------------------------------------
// Conversion
// -------------------------------------------------------------------------------------------------
inline float reciprocal ( const float f )
{
    return 1.0 / f;
}

inline int ftoi_t( double val )
{
	// Float to int conversion using truncation

	return (int)val;
}

inline int ftoi_r( double val )
{
	// Fast round (banker's round) using Sree Kotay's method
	// This function is much faster than a naive cast from float to int

	union
	{
		double dval;
		int ival[2];
	} u;

	u.dval = val + 6755399441055744.0;  // Magic number: 2^52 * 1.5;
	return u.ival[0];         // Needs to be [1] for big-endian
}



// -------------------------------------------------------------------------------------------------
// Vector
// -------------------------------------------------------------------------------------------------

class Vec2
{
public:
	float x, y;
	
	
	// ------------
	// Constructors
	// ------------
	Vec2() : x( 0.0f ), y( 0.0f )
	{
	}
	
	explicit Vec2( NoInitHint )
	{
		// Constructor without default initialization
	}
	
	Vec2( const float x, const float y ) : x( x ), y( y )
	{
	}
	 void set(  float x,  float y )
	{
        this->x=x;
        this->y=y;
      
	}
	 void set( const Vec2 &v )
	{
        this->x=v.x;
        this->y=v.y;
      
	}
	// ------
	// Access
	// ------
	float operator[]( unsigned int index ) const
	{
		return *(&x + index);
	}

	float &operator[]( unsigned int index )
	{
		return *(&x + index);
	}
	
	// -----------
	// Comparisons
	// -----------
	bool operator==( const Vec2 &v ) const
	{
		return (x > v.x - Epsilon && x < v.x + Epsilon &&
				y > v.y - Epsilon && y < v.y + Epsilon);
	}
	
	bool operator!=( const Vec2 &v ) const
	{
		return (x < v.x - Epsilon || x > v.x + Epsilon ||
				y < v.y - Epsilon || y > v.y + Epsilon);
	}
	
	// ---------------------
	// Arithmetic operations
	// ---------------------
	Vec2 operator-() const
	{
		return Vec2( -x, -y );
	}
	
	Vec2 operator+( const Vec2 &v ) const
	{
		return Vec2( x + v.x, y + v.y );
	}
	
	Vec2 &operator+=( const Vec2 &v )
	{
		return *this = *this + v;
	}
	
	Vec2 operator-( const Vec2 &v ) const
	{
		return Vec2( x - v.x, y - v.y );
	}
	
	Vec2 &operator-=( const Vec2 &v )
	{
		return *this = *this - v;
	}
	
	Vec2 operator*( const float f ) const
	{
		return Vec2( x * f, y * f );
	}
	
	Vec2 &operator*=( const float f )
	{
		return *this = *this * f;
	}
	
	Vec2 operator/( const float f ) const
	{
		return Vec2( x / f, y / f );
	}
	
	Vec2 &operator/=( const float f )
	{
		return *this = *this / f;
	}
	
	// ----------------
	// Special products
	// ----------------
	float dot( const Vec2 &v ) const
	{
		return x * v.x + y * v.y;
	}
	
	// ----------------
	// Other operations
	// ----------------
	float length() const
	{
		return sqrtf( x * x + y * y );
	}
	
	Vec2 normalized() const
	{
		float invLen = 1.0f / length();
		return Vec2( x * invLen, y * invLen );
	}
	
	void normalize()
	{
		float invLen = 1.0f / length();
		x *= invLen;
		y *= invLen;
	}
	
	Vec2 lerp( const Vec2 &v, float f ) const
	{
		return Vec2( x + (v.x - x) * f, y + (v.y - y) * f );
	}
};


class Vec3
{
public:
	float x, y, z;
	
	
	// ------------
	// Constructors
	// ------------
	Vec3() : x( 0.0f ), y( 0.0f ), z( 0.0f )
	{ 
	}
		
	Vec3(  float x,  float y,  float z ) : x( x ), y( y ), z( z ) 
	{
	}

    void set(  float x,  float y,  float z )
	{
        this->x=x;
        this->y=y;
        this->z=z;
	}
		 void set( const Vec3 &v )
	{
        this->x=v.x;
        this->y=v.y;
		this->z=v.z;
      
	}

	bool equals(const Vec3 &v)
	{
        
		return (isequal(x,v.x) && isequal(y,v.y) && isequal(z,v.z));
	}

    static Vec3 Normalize(const Vec3 &v) 
    {
    float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return Vec3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
    }
    static Vec3 Cross(const Vec3 &a, const Vec3 &b) 
    {
        return Vec3(a.y * b.z - a.z * b.y,
                        a.z * b.x - a.x * b.z,
                        a.x * b.y - a.y * b.x);
    }

    static float Dot(const Vec3 &a, const Vec3 &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
        
    // ------
	// Access
	// ------
	float operator[]( unsigned int index ) const
	{
		return *(&x + index);
	}

	float &operator[]( unsigned int index )
	{
		return *(&x + index);
	}
	
	// -----------
	// Comparisons
	// -----------
	bool operator==( const Vec3 &v ) const
	{
		return (x > v.x - Epsilon && x < v.x + Epsilon && 
		        y > v.y - Epsilon && y < v.y + Epsilon &&
		        z > v.z - Epsilon && z < v.z + Epsilon);
	}

	bool operator!=( const Vec3 &v ) const
	{
		return (x < v.x - Epsilon || x > v.x + Epsilon || 
		        y < v.y - Epsilon || y > v.y + Epsilon ||
		        z < v.z - Epsilon || z > v.z + Epsilon);
	}
	
	// ---------------------
	// Arithmetic operations
	// ---------------------
	Vec3 operator-() const
	{
		return Vec3( -x, -y, -z );
	}

	Vec3 operator+( const Vec3 &v ) const
	{
		return Vec3( x + v.x, y + v.y, z + v.z );
	}

	Vec3 &operator+=( const Vec3 &v )
	{
		return *this = *this + v;
	}

	Vec3 operator-( const Vec3 &v ) const 
	{
		return Vec3( x - v.x, y - v.y, z - v.z );
	}

	Vec3 &operator-=( const Vec3 &v )
	{
		return *this = *this - v;
	}

	Vec3 operator*( const float f ) const
	{
		return Vec3( x * f, y * f, z * f );
	}

	Vec3 &operator*=( const float f )
	{
		return *this = *this * f;
	}

	Vec3 operator/( const float f ) const
	{
		return Vec3( x / f, y / f, z / f );
	}

	Vec3 &operator/=( const float f )
	{
		return *this = *this / f;
	}

	// ----------------
	// Special products
	// ----------------
	float dot( const Vec3 &v ) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	Vec3 cross( const Vec3 &v ) const
	{
		return Vec3( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x );
	}

	// ----------------
	// Other operations
	// ----------------
	float length() const 
	{
		return sqrtf( x * x + y * y + z * z );
	}
	//! Get squared length of the vector.
		/** This is useful because it is much faster than .
		 **/
	float length_squared() const
	{
		return x * x + y * y + z * z;
	}

	Vec3 normalized() const
	{
		float invLen = 1.0f / length();
		return Vec3( x * invLen, y * invLen, z * invLen );
	}

	void normalize()
	{
		float invLen = 1.0f / length();
		x *= invLen;
		y *= invLen;
		z *= invLen;
	}

	/*void fromRotation( float angleX, float angleY )
	{
		x = cosf( angleX ) * sinf( angleY ); 
		y = -sinf( angleX );
		z = cosf( angleX ) * cosf( angleY );
	}*/

	Vec3 toRotation() const
	{
		// Assumes that the unrotated view vector is (0, 0, -1)
		Vec3 v;
		
		if( y != 0 ) v.x = atan2f( y, sqrtf( x*x + z*z ) );
		if( x != 0 || z != 0 ) v.y = atan2f( -x, -z );

		return v;
	}

	Vec3 lerp( const Vec3 &v, float f ) const
	{
		return Vec3( x + (v.x - x) * f, y + (v.y - y) * f, z + (v.z - z) * f ); 
	}
};


class Vec4
{
public:
	
	float x, y, z, w;


	Vec4() : x( 0 ), y( 0 ), z( 0 ), w( 0 )
	{
	}
	
	explicit Vec4( const float x, const float y, const float z, const float w ) :
		x( x ), y( y ), z( z ), w( w )
	{
	}

	explicit Vec4( Vec3 v ) : x( v.x ), y( v.y ), z( v.z ), w( 1.0f )
	{
	}

	// ------
	// Access
	// ------
	float operator[]( unsigned int index ) const
	{
		return *(&x + index);
	}

	float &operator[]( unsigned int index )
	{
		return *(&x + index);
	}

	// ---------------------
	// Arithmetic operations
	// ---------------------
	Vec4 operator+( const Vec4 &v ) const
	{
		return Vec4( x + v.x, y + v.y, z + v.z, w + v.w );
	}

	Vec4 operator-() const
	{
		return Vec4( -x, -y, -z, -w );
	}
	
	Vec4 operator*( const float f ) const
	{
		return Vec4( x * f, y * f, z * f, w * f );
	}
};


// -------------------------------------------------------------------------------------------------
// Quat
// -------------------------------------------------------------------------------------------------

class Quat
{
public:	
	
	float x, y, z, w;

	// ------------
	// Constructors
	// ------------
	Quat() : x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 0.0f ) 
	{ 
	}
	
	explicit Quat( const float x, const float y, const float z, const float w ) :
		x( x ), y( y ), z( z ), w( w )
	{
	}
	
	Quat( const float eulerX, const float eulerY, const float eulerZ )
	{
		Quat roll( sinf( eulerX * 0.5f ), 0, 0, cosf( eulerX * 0.5f ) );
		Quat pitch( 0, sinf( eulerY * 0.5f ), 0, cosf( eulerY * 0.5f ) );
		Quat yaw( 0, 0, sinf( eulerZ * 0.5f ), cosf( eulerZ * 0.5f ) );
	
		// Order: y * x * z
		*this = pitch * roll * yaw;
	}

	// ---------------------
	// Arithmetic operations
	// ---------------------
	Quat operator*( const Quat &q ) const
	{
		return Quat(
			y * q.z - z * q.y + q.x * w + x * q.w,
			z * q.x - x * q.z + q.y * w + y * q.w,
			x * q.y - y * q.x + q.z * w + z * q.w,
			w * q.w - (x * q.x + y * q.y + z * q.z) );
	}

	Quat &operator*=( const Quat &q )
	{
		return *this = *this * q;
	}

	// ----------------
	// Other operations
	// ----------------

	Quat slerp( const Quat &q, const float t ) const
	{
		// Spherical linear interpolation between two Quats
		// Note: SLERP is not commutative
		
		Quat q1( q );

		// Calculate cosine
		float cosTheta = x * q.x + y * q.y + z * q.z + w * q.w;

		// Use the shortest path
		if( cosTheta < 0 )
		{
			cosTheta = -cosTheta; 
			q1.x = -q.x; q1.y = -q.y;
			q1.z = -q.z; q1.w = -q.w;
		}

		// Initialize with linear interpolation
		float scale0 = 1 - t, scale1 = t;
		
		// Use spherical interpolation only if the Quats are not very close
		if( (1 - cosTheta) > 0.001f )
		{
			// SLERP
			float theta = acosf( cosTheta );
			float sinTheta = sinf( theta );
			scale0 = sinf( (1 - t) * theta ) / sinTheta;
			scale1 = sinf( t * theta ) / sinTheta;
		} 
		
		// Calculate final Quat
		return Quat( x * scale0 + q1.x * scale1, y * scale0 + q1.y * scale1,
		                   z * scale0 + q1.z * scale1, w * scale0 + q1.w * scale1 );
	}

	Quat nlerp( const Quat &q, const float t ) const
	{
		// Normalized linear Quat interpolation
		// Note: NLERP is faster than SLERP and commutative but does not yield constant velocity

		Quat qt;
		float cosTheta = x * q.x + y * q.y + z * q.z + w * q.w;
		
		// Use the shortest path and interpolate linearly
		if( cosTheta < 0 )
			qt = Quat( x + (-q.x - x) * t, y + (-q.y - y) * t,
							 z + (-q.z - z) * t, w + (-q.w - w) * t );
		else
			qt = Quat( x + (q.x - x) * t, y + (q.y - y) * t,
							 z + (q.z - z) * t, w + (q.w - w) * t );

		// Return normalized Quat
		float invLen = 1.0f / sqrtf( qt.x * qt.x + qt.y * qt.y + qt.z * qt.z + qt.w * qt.w );
		return Quat( qt.x * invLen, qt.y * invLen, qt.z * invLen, qt.w * invLen );
	}

	Quat inverted() const
	{
		float len = x * x + y * y + z * z + w * w;
		if( len > 0 )
		{
			float invLen = 1.0f / len;
			return Quat( -x * invLen, -y * invLen, -z * invLen, w * invLen );
		}
		else return Quat();
	}
};


// -------------------------------------------------------------------------------------------------
// Matrix
// -------------------------------------------------------------------------------------------------



class Mat3
{
	public:
	float m[3][3];	

	explicit Mat3( NoInitHint )
	{
	}

    Mat3()
	{
		m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
    }
	 Mat3(const float arr[3][3])
	{
		memcpy(m,arr,9*sizeof(float));
    }
	Mat3(float V00, float V01, float V02,
	     float V10, float V11, float V12,
		 float V20, float V21, float V22) 
	{
      	m[0][0] = V00;
        m[0][1] = V01;
        m[0][2] = V02;
		
        m[1][0] = V10;
        m[1][1] = V11;
        m[1][2] = V12;
		
        m[2][0] = V20;
        m[2][1] = V21;
        m[2][2] = V22;
    }

	void identity()
	{
		
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
	}
	Mat3 transpose() const 
	{
         Mat3 kTranspose;
        for (size_t iRow = 0; iRow < 3; iRow++)
        {
            for (size_t iCol = 0; iCol < 3; iCol++)
                kTranspose[iRow][iCol] = m[iCol][iRow];
        }
        return kTranspose;
    }
	 Mat3 operator*(const Mat3& rkMatrix) const 
	 {
        Mat3 kProd;
        for (size_t iRow = 0; iRow < 3; iRow++)
        {
            for (size_t iCol = 0; iCol < 3; iCol++)
            {
                kProd.m[iRow][iCol] =
                    m[iRow][0]*rkMatrix.m[0][iCol] +
                    m[iRow][1]*rkMatrix.m[1][iCol] +
                    m[iRow][2]*rkMatrix.m[2][iCol];
            }
        }
        return kProd;
    }

	 Mat3& operator= (const Mat3& rkMatrix)
	{
		memcpy(m,rkMatrix.m,9*sizeof(float));
		return *this;
	}
	bool operator!= (const Mat3& rkMatrix) const
	{
		return !operator==(rkMatrix);
	}
	bool operator== (const Mat3& rkMatrix) const
	{
	 for (size_t iRow = 0; iRow < 3; iRow++)
        {
            for (size_t iCol = 0; iCol < 3; iCol++)
            {
                if ( m[iRow][iCol] != rkMatrix.m[iRow][iCol] )
                    return false;
            }
        }

        return true;
	}
	Vec3 operator* (const Vec3& rkPoint) const
	{
		Vec3 kProd;
        for (size_t iRow = 0; iRow < 3; iRow++)
        {
            kProd[iRow] =
                m[iRow][0]*rkPoint.x +
                m[iRow][1]*rkPoint.y +
                m[iRow][2]*rkPoint.z;
        }
        return kProd;
	}
	Mat3 operator* (float fScalar) const
	{
		Mat3 kProd;
        for (size_t iRow = 0; iRow < 3; iRow++)
        {
            for (size_t iCol = 0; iCol < 3; iCol++)
                kProd[iRow][iCol] = fScalar*m[iRow][iCol];
        }
        return kProd;
	}


	inline const float* operator[] (size_t iRow) const
	{
		return m[iRow];
	}

	inline float* operator[] (size_t iRow)
	{
		return m[iRow];
	}
	 static Mat3 createRotationX(float angle) {
        float cosTheta = cos(angle);
        float sinTheta = sin(angle);
        return Mat3
		(
            1.0f, 0.0f, 0.0f,
            0.0f, cosTheta, sinTheta,
            0.0f, -sinTheta, cosTheta
		);
    }

  
  
    static Mat3 createRotationY(float angle) 
	{
        float cosTheta = cos(angle);
        float sinTheta = sin(angle);
        return Mat3
		(
            cosTheta, 0.0f, -sinTheta,
            0.0f, 1.0f, 0.0f,
            sinTheta, 0.0f, cosTheta
		);
    }



    static Mat3 createRotationZ(float angle) 
	{
        float cosTheta = cos(angle);
        float sinTheta = sin(angle);
        return Mat3
		(
            cosTheta, sinTheta, 0.0f,
            -sinTheta, cosTheta, 0.0f,
            0.0f, 0.0f, 1.0f
		);
    }
	 bool hasScale() const
		{
			// check magnitude of column vectors (==local axes)
			float t = m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0];
			if (!isequal(t, 1.0, (float)1e-04))
				return true;
			t = m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1];
			if (!isequal(t, 1.0, (float)1e-04))
				return true;
			t = m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2];
			if (!isequal(t, 1.0, (float)1e-04))
				return true;

			return false;
		}
		inline  friend std::ostream& operator <<
			( std::ostream& o, const Mat3& mat )
		{
			o << "Matrix3(" << mat[0][0] << ", " << mat[0][1] << ", " << mat[0][2] << ", " 
                            << mat[1][0] << ", " << mat[1][1] << ", " << mat[1][2] << ", " 
                            << mat[2][0] << ", " << mat[2][1] << ", " << mat[2][2] << ")";
			return o;
		}

        static const Mat3 ZERO;
        static const Mat3 IDENTITY;
   protected:		
		friend class Mat4;
};

class Mat4
{

public:
	
	union
	{
		float m[4][4];	// Column major order for OpenGL: m[column][row]
		float x[16];
	};
	
	// ------------
	// Constructors
	// ------------
	explicit Mat4( NoInitHint )
	{
	}

	Mat4()
	{
		m[0][0] = 1; m[1][0] = 0; m[2][0] = 0; m[3][0] = 0;
		m[0][1] = 0; m[1][1] = 1; m[2][1] = 0; m[3][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 1; m[3][2] = 0;
		m[0][3] = 0; m[1][3] = 0; m[2][3] = 0; m[3][3] = 1;
	}

	Mat4( const float *floatArray16 )
	{
		for( unsigned int i = 0; i < 4; ++i )
		{
			for( unsigned int j = 0; j < 4; ++j )
			{
				m[i][j] = floatArray16[i * 4 + j];
			}
		}
	}

	Mat4(
            float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33 )
        {
            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
            m[2][0] = m20;
            m[2][1] = m21;
            m[2][2] = m22;
            m[2][3] = m23;
            m[3][0] = m30;
            m[3][1] = m31;
            m[3][2] = m32;
            m[3][3] = m33;
        }

	Mat4( const Quat &q )
	{
		// Calculate coefficients
		float x2 = q.x + q.x, y2 = q.y + q.y, z2 = q.z + q.z;
		float xx = q.x * x2,  xy = q.x * y2,  xz = q.x * z2;
		float yy = q.y * y2,  yz = q.y * z2,  zz = q.z * z2;
		float wx = q.w * x2,  wy = q.w * y2,  wz = q.w * z2;

		m[0][0] = 1 - (yy + zz);  m[1][0] = xy - wz;	
		m[2][0] = xz + wy;        m[3][0] = 0;
		m[0][1] = xy + wz;        m[1][1] = 1 - (xx + zz);
		m[2][1] = yz - wx;        m[3][1] = 0;
		m[0][2] = xz - wy;        m[1][2] = yz + wx;
		m[2][2] = 1 - (xx + yy);  m[3][2] = 0;
		m[0][3] = 0;              m[1][3] = 0;
		m[2][3] = 0;              m[3][3] = 1;
	}
	
   void identity() 
  {
 
    for (int i = 0; i < 4; i++) 
    {
      for (int j = 0; j < 4; j++) 
      {
        m[i][j] = (i == j) ? 1.0f : 0.0f;
      }
    }
    
  }
	// --------------
	// Static methods
	// --------------
    static Mat4 Identity() 
  {
    Mat4 matrix;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        matrix.m[i][j] = (i == j) ? 1.0f : 0.0f;
      }
    }
    return matrix;
  }

	static Mat4 Translate( float x, float y, float z )
	{
		Mat4 r;

		r.m[3][0] = x;
		r.m[3][1] = y;
		r.m[3][2] = z;

		return r;
	}
	static Mat4 Translate(const Vec3 &v )
	{
		Mat4 r;

		r.m[3][0] = v.x;
		r.m[3][1] = v.y;
		r.m[3][2] = v.z;

		return r;
	}

	static Mat4 Scale( float x, float y, float z )
	{
		Mat4 r;
		
		r.m[0][0] = x;
		r.m[1][1] = y;
		r.m[2][2] = z;

		return r;
	}

	static Mat4 Rotate( float x, float y, float z )
	{
		// Rotation order: YXZ [* Vector]
		return Mat4( Quat( x, y, z ) );
	}

	static Mat4 Rotate( Vec3 axis, float angle )
	{
		axis = axis * sinf( angle * 0.5f );
		return Mat4( Quat( axis.x, axis.y, axis.z, cosf( angle * 0.5f ) ) );
	}


	static Mat4 Perspective( float l, float r, float b, float t, float n, float f )
	{
		Mat4 m;

		m.x[0] = 2 * n / (r - l);
		m.x[5] = 2 * n / (t - b);
		m.x[8] = (r + l) / (r - l);
		m.x[9] = (t + b) / (t - b);
		m.x[10] = -(f + n) / (f - n);
		m.x[11] = -1;
		m.x[14] = -2 * f * n / (f - n);
		m.x[15] = 0;

		return m;
	}

    static Mat4 Perspective( float fov, float aspect, float nearPlane, float farPlane)
	{


		float ymax = nearPlane * tanf( degToRad( fov / 2 ) );
	    float xmax = ymax * aspect;

        float frustLeft = -xmax;
        float frustRight = xmax;
        float frustBottom = -ymax;
        float frustTop = ymax;
        
		return Mat4::Perspective(frustLeft, frustRight, frustBottom, frustTop, nearPlane, farPlane);
	}


    // Builds a right-handed perspective projection matrix based on a field of view
	static Mat4 ProjectionMatrix(float fieldOfViewRadians, float aspectRatio, float zNear, float zFar)
	{
		const float h = reciprocal(tan(fieldOfViewRadians*0.5));
		const float w = (h / aspectRatio);

	    Mat4 M;
		M.x[0] = w;
		M.x[1] = 0;
		M.x[2] = 0;
		M.x[3] = 0;

		M.x[4] = 0;
		M.x[5] = h;
		M.x[6] = 0;
		M.x[7] = 0;

		M.x[8] = 0;
		M.x[9] = 0;
		//M[10]
		M.x[11] = -1;

		M.x[12] = 0;
		M.x[13] = 0;
		//M[14]
		M.x[15] = 0;

        M.x[10] = (float)((zFar+zNear)/(zNear-zFar));
        M.x[14] = (float)(2.0f*zNear*zFar/(zNear-zFar));
        

		return M;
	}


	// Builds a left-handed perspective projection matrix based on a field of view
	static Mat4 ProjectionMatrixLH(float fieldOfViewRadians, float aspectRatio, float zNear, float zFar)
	{
    	const float h = reciprocal(tan(fieldOfViewRadians*0.5));
		const float w = (h / aspectRatio);
        Mat4 M;

		M.x[0] = w;
		M.x[1] = 0;
		M.x[2] = 0;
		M.x[3] = 0;

		M.x[4] = 0;
		M.x[5] = (float)h;
		M.x[6] = 0;
		M.x[7] = 0;

		M.x[8] = 0;
		M.x[9] = 0;
		//M[10]
		M.x[11] = 1;

		M.x[12] = 0;
		M.x[13] = 0;
		//M[14]
		M.x[15] = 0;


        M.x[10] = (float)((zFar+zNear)/(zFar-zNear));
        M.x[14] = (float)(2.0f*zNear*zFar/(zNear-zFar));
    


		return M;
	}


        // Builds a left-handed look-at matrix.
        static Mat4 LookAtLH( const Vec3 &position, const Vec3 &target, const Vec3 &upVector)
        {
                Vec3 zaxis = target - position;
                zaxis.normalize();

                Vec3 xaxis = upVector.cross(zaxis);
                xaxis.normalize();

                Vec3 yaxis = zaxis.cross(xaxis);

                Mat4 M;
                M.x[0] = xaxis.x;
                M.x[1] = yaxis.x;
                M.x[2] = zaxis.x;
                M.x[3] = 0;

                M.x[4] = xaxis.y;
                M.x[5] = yaxis.y;
                M.x[6] = zaxis.y;
                M.x[7] = 0;

                M.x[8] = xaxis.z;
                M.x[9] = yaxis.z;
                M.x[10] =zaxis.z;
                M.x[11] = 0;

                M.x[12] = -xaxis.dot(position);
                M.x[13] = -yaxis.dot(position);
                M.x[14] = -zaxis.dot(position);
                M.x[15] = 1;
                return M;
    }

    //Builds a right-handed look-at matrix.
    static Mat4 LookAt( const Vec3 &position, const Vec3 &target, const Vec3 &upVector)
    {
            Vec3 zaxis = position - target;
            zaxis.normalize();

            Vec3 xaxis = upVector.cross(zaxis);
            xaxis.normalize();

            Vec3 yaxis = zaxis.cross(xaxis);

            Mat4 M = Mat4::Identity();
            M.x[0] = xaxis.x;
            M.x[1] = yaxis.x;
            M.x[2] = zaxis.x;
            M.x[3] = 0;

            M.x[4] = xaxis.y;
            M.x[5] = yaxis.y;
            M.x[6] = zaxis.y;
            M.x[7] = 0;

            M.x[8] = xaxis.z;
            M.x[9] = yaxis.z;
            M.x[10] =zaxis.z;
            M.x[11] = 0;

            M.x[12] = -xaxis.dot(position);
            M.x[13] = -yaxis.dot(position);
            M.x[14] = -zaxis.dot(position);
            M.x[15] = 1;
            return M;
}


	static Mat4 OrthoMat( float l, float r, float b, float t, float n, float f )
	{
		Mat4 m;

		m.x[0] = 2 / (r - l);
		m.x[5] = 2 / (t - b);
		m.x[10] = -2 / (f - n);
		m.x[12] = -(r + l) / (r - l);
		m.x[13] = -(t + b) / (t - b);
		m.x[14] = -(f + n) / (f - n);

		return m;
	}

	static void fastMult43( Mat4 &dst, const Mat4 &m1, const Mat4 &m2 )
	{
		// Note: dst may not be the same as m1 or m2

		float *dstx = dst.x;
		const float *m1x = m1.x;
		const float *m2x = m2.x;
		
		dstx[0] = m1x[0] * m2x[0] + m1x[4] * m2x[1] + m1x[8] * m2x[2];
		dstx[1] = m1x[1] * m2x[0] + m1x[5] * m2x[1] + m1x[9] * m2x[2];
		dstx[2] = m1x[2] * m2x[0] + m1x[6] * m2x[1] + m1x[10] * m2x[2];
		dstx[3] = 0.0f;

		dstx[4] = m1x[0] * m2x[4] + m1x[4] * m2x[5] + m1x[8] * m2x[6];
		dstx[5] = m1x[1] * m2x[4] + m1x[5] * m2x[5] + m1x[9] * m2x[6];
		dstx[6] = m1x[2] * m2x[4] + m1x[6] * m2x[5] + m1x[10] * m2x[6];
		dstx[7] = 0.0f;

		dstx[8] = m1x[0] * m2x[8] + m1x[4] * m2x[9] + m1x[8] * m2x[10];
		dstx[9] = m1x[1] * m2x[8] + m1x[5] * m2x[9] + m1x[9] * m2x[10];
		dstx[10] = m1x[2] * m2x[8] + m1x[6] * m2x[9] + m1x[10] * m2x[10];
		dstx[11] = 0.0f;

		dstx[12] = m1x[0] * m2x[12] + m1x[4] * m2x[13] + m1x[8] * m2x[14] + m1x[12] * m2x[15];
		dstx[13] = m1x[1] * m2x[12] + m1x[5] * m2x[13] + m1x[9] * m2x[14] + m1x[13] * m2x[15];
		dstx[14] = m1x[2] * m2x[12] + m1x[6] * m2x[13] + m1x[10] * m2x[14] + m1x[14] * m2x[15];
		dstx[15] = 1.0f;
	}



	// ----------
	// Matrix sum
	// ----------
	Mat4 operator+( const Mat4 &m ) const 
	{
		Mat4 mf( NO_INIT );
		
		mf.x[0] = x[0] + m.x[0];
		mf.x[1] = x[1] + m.x[1];
		mf.x[2] = x[2] + m.x[2];
		mf.x[3] = x[3] + m.x[3];
		mf.x[4] = x[4] + m.x[4];
		mf.x[5] = x[5] + m.x[5];
		mf.x[6] = x[6] + m.x[6];
		mf.x[7] = x[7] + m.x[7];
		mf.x[8] = x[8] + m.x[8];
		mf.x[9] = x[9] + m.x[9];
		mf.x[10] = x[10] + m.x[10];
		mf.x[11] = x[11] + m.x[11];
		mf.x[12] = x[12] + m.x[12];
		mf.x[13] = x[13] + m.x[13];
		mf.x[14] = x[14] + m.x[14];
		mf.x[15] = x[15] + m.x[15];

		return mf;
	}

	Mat4 &operator+=( const Mat4 &m )
	{
		return *this = *this + m;
	}

	void transformVect( Vec3& vect) const
	{
		float vector[3];

		vector[0] = vect.x*x[0] + vect.y*x[4] + vect.z*x[8] + x[12];
		vector[1] = vect.x*x[1] + vect.y*x[5] + vect.z*x[9] + x[13];
		vector[2] = vect.x*x[2] + vect.y*x[6] + vect.z*x[10] + x[14];

		vect.x = vector[0];
		vect.y = vector[1];
		vect.z = vector[2];
	}
	// ---------------------
	// Matrix multiplication
	// ---------------------
	Mat4 operator*( const Mat4 &m ) const 
	{
		Mat4 mf( NO_INIT );
		
		mf.x[0] = x[0] * m.x[0] + x[4] * m.x[1] + x[8] * m.x[2] + x[12] * m.x[3];
		mf.x[1] = x[1] * m.x[0] + x[5] * m.x[1] + x[9] * m.x[2] + x[13] * m.x[3];
		mf.x[2] = x[2] * m.x[0] + x[6] * m.x[1] + x[10] * m.x[2] + x[14] * m.x[3];
		mf.x[3] = x[3] * m.x[0] + x[7] * m.x[1] + x[11] * m.x[2] + x[15] * m.x[3];

		mf.x[4] = x[0] * m.x[4] + x[4] * m.x[5] + x[8] * m.x[6] + x[12] * m.x[7];
		mf.x[5] = x[1] * m.x[4] + x[5] * m.x[5] + x[9] * m.x[6] + x[13] * m.x[7];
		mf.x[6] = x[2] * m.x[4] + x[6] * m.x[5] + x[10] * m.x[6] + x[14] * m.x[7];
		mf.x[7] = x[3] * m.x[4] + x[7] * m.x[5] + x[11] * m.x[6] + x[15] * m.x[7];

		mf.x[8] = x[0] * m.x[8] + x[4] * m.x[9] + x[8] * m.x[10] + x[12] * m.x[11];
		mf.x[9] = x[1] * m.x[8] + x[5] * m.x[9] + x[9] * m.x[10] + x[13] * m.x[11];
		mf.x[10] = x[2] * m.x[8] + x[6] * m.x[9] + x[10] * m.x[10] + x[14] * m.x[11];
		mf.x[11] = x[3] * m.x[8] + x[7] * m.x[9] + x[11] * m.x[10] + x[15] * m.x[11];

		mf.x[12] = x[0] * m.x[12] + x[4] * m.x[13] + x[8] * m.x[14] + x[12] * m.x[15];
		mf.x[13] = x[1] * m.x[12] + x[5] * m.x[13] + x[9] * m.x[14] + x[13] * m.x[15];
		mf.x[14] = x[2] * m.x[12] + x[6] * m.x[13] + x[10] * m.x[14] + x[14] * m.x[15];
		mf.x[15] = x[3] * m.x[12] + x[7] * m.x[13] + x[11] * m.x[14] + x[15] * m.x[15];

		return mf;
	}

	Mat4 operator*( const float f ) const
	{
		Mat4 m( *this );
		
		m.x[0]  *= f; m.x[1]  *= f; m.x[2]  *= f; m.x[3]  *= f;
		m.x[4]  *= f; m.x[5]  *= f; m.x[6]  *= f; m.x[7]  *= f;
		m.x[8]  *= f; m.x[9]  *= f; m.x[10] *= f; m.x[11] *= f;
		m.x[12] *= f; m.x[13] *= f; m.x[14] *= f; m.x[15] *= f;

		return m;
	}

	// ----------------------------
	// Vector-Matrix multiplication
	// ----------------------------
	Vec3 operator*( const Vec3 &v ) const
	{
		return Vec3( v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0],
		              v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1],
		              v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2] );
	}

	Vec4 operator*( const Vec4 &v ) const
	{
		return Vec4( v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0],
		              v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1],
		              v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2],
		              v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3] );
	}

	Vec3 mult33Vec( const Vec3 &v ) const
	{
		return Vec3( v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
		              v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
		              v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] );
	}
	
	// ---------------
	// Transformations
	// ---------------
	void translate( const float tx, const float ty, const float tz )
	{
		*this = Translate( tx, ty, tz ) * *this;
	}

	void scale( const float sx, const float sy, const float sz )
	{
		*this = Scale( sx, sy, sz ) * *this;
	}

	void rotate( const float rx, const float ry, const float rz )
	{
		*this = Rotate( rx, ry, rz ) * *this;
	}

	// ---------------
	// Other
	// ---------------

	Mat4 transposed() const
	{
		Mat4 r( *this );
		
		for( unsigned int maty = 0; maty < 4; ++maty )
		{
			for( unsigned int matx = maty + 1; matx < 4; ++matx ) 
			{
				float tmp = r.m[matx][maty];
				r.m[matx][maty] = r.m[maty][matx];
				r.m[maty][matx] = tmp;
			}
		}

		return r;
	}

	float determinant() const
	{
		return 
			m[0][3]*m[1][2]*m[2][1]*m[3][0] - m[0][2]*m[1][3]*m[2][1]*m[3][0] - m[0][3]*m[1][1]*m[2][2]*m[3][0] + m[0][1]*m[1][3]*m[2][2]*m[3][0] +
			m[0][2]*m[1][1]*m[2][3]*m[3][0] - m[0][1]*m[1][2]*m[2][3]*m[3][0] - m[0][3]*m[1][2]*m[2][0]*m[3][1] + m[0][2]*m[1][3]*m[2][0]*m[3][1] +
			m[0][3]*m[1][0]*m[2][2]*m[3][1] - m[0][0]*m[1][3]*m[2][2]*m[3][1] - m[0][2]*m[1][0]*m[2][3]*m[3][1] + m[0][0]*m[1][2]*m[2][3]*m[3][1] +
			m[0][3]*m[1][1]*m[2][0]*m[3][2] - m[0][1]*m[1][3]*m[2][0]*m[3][2] - m[0][3]*m[1][0]*m[2][1]*m[3][2] + m[0][0]*m[1][3]*m[2][1]*m[3][2] +
			m[0][1]*m[1][0]*m[2][3]*m[3][2] - m[0][0]*m[1][1]*m[2][3]*m[3][2] - m[0][2]*m[1][1]*m[2][0]*m[3][3] + m[0][1]*m[1][2]*m[2][0]*m[3][3] +
			m[0][2]*m[1][0]*m[2][1]*m[3][3] - m[0][0]*m[1][2]*m[2][1]*m[3][3] - m[0][1]*m[1][0]*m[2][2]*m[3][3] + m[0][0]*m[1][1]*m[2][2]*m[3][3];
	}

	Mat4 inverted() const
	{
		Mat4 r( NO_INIT );

		float d = determinant();
		if( d == 0 ) return r;
		d = 1.0f / d;
		
		r.m[0][0] = d * (m[1][2]*m[2][3]*m[3][1] - m[1][3]*m[2][2]*m[3][1] + m[1][3]*m[2][1]*m[3][2] - m[1][1]*m[2][3]*m[3][2] - m[1][2]*m[2][1]*m[3][3] + m[1][1]*m[2][2]*m[3][3]);
		r.m[0][1] = d * (m[0][3]*m[2][2]*m[3][1] - m[0][2]*m[2][3]*m[3][1] - m[0][3]*m[2][1]*m[3][2] + m[0][1]*m[2][3]*m[3][2] + m[0][2]*m[2][1]*m[3][3] - m[0][1]*m[2][2]*m[3][3]);
		r.m[0][2] = d * (m[0][2]*m[1][3]*m[3][1] - m[0][3]*m[1][2]*m[3][1] + m[0][3]*m[1][1]*m[3][2] - m[0][1]*m[1][3]*m[3][2] - m[0][2]*m[1][1]*m[3][3] + m[0][1]*m[1][2]*m[3][3]);
		r.m[0][3] = d * (m[0][3]*m[1][2]*m[2][1] - m[0][2]*m[1][3]*m[2][1] - m[0][3]*m[1][1]*m[2][2] + m[0][1]*m[1][3]*m[2][2] + m[0][2]*m[1][1]*m[2][3] - m[0][1]*m[1][2]*m[2][3]);
		r.m[1][0] = d * (m[1][3]*m[2][2]*m[3][0] - m[1][2]*m[2][3]*m[3][0] - m[1][3]*m[2][0]*m[3][2] + m[1][0]*m[2][3]*m[3][2] + m[1][2]*m[2][0]*m[3][3] - m[1][0]*m[2][2]*m[3][3]);
		r.m[1][1] = d * (m[0][2]*m[2][3]*m[3][0] - m[0][3]*m[2][2]*m[3][0] + m[0][3]*m[2][0]*m[3][2] - m[0][0]*m[2][3]*m[3][2] - m[0][2]*m[2][0]*m[3][3] + m[0][0]*m[2][2]*m[3][3]);
		r.m[1][2] = d * (m[0][3]*m[1][2]*m[3][0] - m[0][2]*m[1][3]*m[3][0] - m[0][3]*m[1][0]*m[3][2] + m[0][0]*m[1][3]*m[3][2] + m[0][2]*m[1][0]*m[3][3] - m[0][0]*m[1][2]*m[3][3]);
		r.m[1][3] = d * (m[0][2]*m[1][3]*m[2][0] - m[0][3]*m[1][2]*m[2][0] + m[0][3]*m[1][0]*m[2][2] - m[0][0]*m[1][3]*m[2][2] - m[0][2]*m[1][0]*m[2][3] + m[0][0]*m[1][2]*m[2][3]);
		r.m[2][0] = d * (m[1][1]*m[2][3]*m[3][0] - m[1][3]*m[2][1]*m[3][0] + m[1][3]*m[2][0]*m[3][1] - m[1][0]*m[2][3]*m[3][1] - m[1][1]*m[2][0]*m[3][3] + m[1][0]*m[2][1]*m[3][3]);
		r.m[2][1] = d * (m[0][3]*m[2][1]*m[3][0] - m[0][1]*m[2][3]*m[3][0] - m[0][3]*m[2][0]*m[3][1] + m[0][0]*m[2][3]*m[3][1] + m[0][1]*m[2][0]*m[3][3] - m[0][0]*m[2][1]*m[3][3]);
		r.m[2][2] = d * (m[0][1]*m[1][3]*m[3][0] - m[0][3]*m[1][1]*m[3][0] + m[0][3]*m[1][0]*m[3][1] - m[0][0]*m[1][3]*m[3][1] - m[0][1]*m[1][0]*m[3][3] + m[0][0]*m[1][1]*m[3][3]);
		r.m[2][3] = d * (m[0][3]*m[1][1]*m[2][0] - m[0][1]*m[1][3]*m[2][0] - m[0][3]*m[1][0]*m[2][1] + m[0][0]*m[1][3]*m[2][1] + m[0][1]*m[1][0]*m[2][3] - m[0][0]*m[1][1]*m[2][3]);
		r.m[3][0] = d * (m[1][2]*m[2][1]*m[3][0] - m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] + m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] - m[1][0]*m[2][1]*m[3][2]);
		r.m[3][1] = d * (m[0][1]*m[2][2]*m[3][0] - m[0][2]*m[2][1]*m[3][0] + m[0][2]*m[2][0]*m[3][1] - m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] + m[0][0]*m[2][1]*m[3][2]);
		r.m[3][2] = d * (m[0][2]*m[1][1]*m[3][0] - m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] + m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] - m[0][0]*m[1][1]*m[3][2]);
		r.m[3][3] = d * (m[0][1]*m[1][2]*m[2][0] - m[0][2]*m[1][1]*m[2][0] + m[0][2]*m[1][0]*m[2][1] - m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2] + m[0][0]*m[1][1]*m[2][2]);
		
		return r;
	}

	void decompose( Vec3 &trans, Vec3 &rot, Vec3 &scale ) const
	{
		// Getting translation is trivial
		trans = Vec3( m[3][0], m[3][1], m[3][2] );

		// Scale is length of columns
		scale.x = sqrtf( m[0][0] * m[0][0] + m[0][1] * m[0][1] + m[0][2] * m[0][2] );
		scale.y = sqrtf( m[1][0] * m[1][0] + m[1][1] * m[1][1] + m[1][2] * m[1][2] );
		scale.z = sqrtf( m[2][0] * m[2][0] + m[2][1] * m[2][1] + m[2][2] * m[2][2] );

		if( scale.x == 0 || scale.y == 0 || scale.z == 0 ) return;

		// Detect negative scale with determinant and flip one arbitrary axis
		if( determinant() < 0 ) scale.x = -scale.x;

		// Combined rotation matrix YXZ
		//
		// Cos[y]*Cos[z]+Sin[x]*Sin[y]*Sin[z]   Cos[z]*Sin[x]*Sin[y]-Cos[y]*Sin[z]  Cos[x]*Sin[y]	
		// Cos[x]*Sin[z]                        Cos[x]*Cos[z]                       -Sin[x]
		// -Cos[z]*Sin[y]+Cos[y]*Sin[x]*Sin[z]  Cos[y]*Cos[z]*Sin[x]+Sin[y]*Sin[z]  Cos[x]*Cos[y]

		rot.x = asinf( -m[2][1] / scale.z );
		
		// Special case: Cos[x] == 0 (when Sin[x] is +/-1)
		float f = fabsf( m[2][1] / scale.z );
		if( f > 0.999f && f < 1.001f )
		{
			// Pin arbitrarily one of y or z to zero
			// Mathematical equivalent of gimbal lock
			rot.y = 0;
			
			// Now: Cos[x] = 0, Sin[x] = +/-1, Cos[y] = 1, Sin[y] = 0
			// => m[0][0] = Cos[z] and m[1][0] = Sin[z]
			rot.z = atan2f( -m[1][0] / scale.y, m[0][0] / scale.x );
		}
		// Standard case
		else
		{
			rot.y = atan2f( m[2][0] / scale.z, m[2][2] / scale.z );
			rot.z = atan2f( m[0][1] / scale.x, m[1][1] / scale.y );
		}
	}

	
	void setCol( unsigned int col, const Vec4& v ) 
	{
		x[col * 4 + 0] = v.x;
		x[col * 4 + 1] = v.y;
		x[col * 4 + 2] = v.z;
		x[col * 4 + 3] = v.w;
	}

	Vec4 getCol( unsigned int col ) const
	{
		return Vec4( x[col * 4 + 0], x[col * 4 + 1], x[col * 4 + 2], x[col * 4 + 3] );
	}

	Vec4 getRow( unsigned int row ) const
	{
		return Vec4( x[row + 0], x[row + 4], x[row + 8], x[row + 12] );
	}

	Vec3 getTrans() const
	{
		return Vec3( m[3][0], m[3][1], m[3][2] );
	}
	
	Vec3 getScale() const
	{
		Vec3 scale;
		// Scale is length of columns
		scale.x = sqrtf( m[0][0] * m[0][0] + m[0][1] * m[0][1] + m[0][2] * m[0][2] );
		scale.y = sqrtf( m[1][0] * m[1][0] + m[1][1] * m[1][1] + m[1][2] * m[1][2] );
		scale.z = sqrtf( m[2][0] * m[2][0] + m[2][1] * m[2][1] + m[2][2] * m[2][2] );
		return scale;
	}
	float* operator [] ( size_t iRow )
	{
		
		return m[iRow];
	}

		const float *operator [] ( size_t iRow ) const
	{
	
		return m[iRow];
	}
	   friend std::ostream& operator <<
            ( std::ostream& o, const Mat4& mat )
        {
            o << "Matrix4(";
			for (size_t i = 0; i < 4; ++i)
            {
                o << " row" << (unsigned)i << "{";
                for(size_t j = 0; j < 4; ++j)
                {
                    o << mat[i][j] << " ";
                }
                o << "}";
            }
            o << ")";
            return o;
        }
		 bool isAffine(void) const
        {
            return m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
        }
		
};

Mat3 createMatrix3(const  Mat4 &m);
Mat4 createMatrix4(const  Mat3 &m);
// -------------------------------------------------------------------------------------------------
// Plane
// -------------------------------------------------------------------------------------------------

class Plane
{
public:
	Vec3 normal; 
	float dist;

	// ------------
	// Constructors
	// ------------
	Plane() 
	{ 
		normal.x = 0; normal.y = 0; normal.z = 0; dist = 0; 
	};

	explicit Plane( const float a, const float b, const float c, const float d )
	{
		normal = Vec3( a, b, c );
		float invLen = 1.0f / normal.length();
		normal *= invLen;	// Normalize
		dist = d * invLen;
	}

	Plane( const Vec3 &v0, const Vec3 &v1, const Vec3 &v2 )
	{
		normal = v1 - v0;
		normal = normal.cross( v2 - v0 );
		normal.normalize();
		dist = -normal.dot( v0 );
	}

	// ----------------
	// Other operations
	// ----------------
	float distToPoint( const Vec3 &v ) const
	{
		return normal.dot( v ) + dist;
	}
};

struct Triangle3d
{
	    Triangle3d() {}
		
		Triangle3d(const Vec3& v1, const Vec3& v2, const Vec3& v3) : pointA(v1), pointB(v2), pointC(v3) {}

		//! Equality operator
		bool operator==(const Triangle3d& other) const
		{
			return other.pointA==pointA && other.pointB==pointB && other.pointC==pointC;
		}

		//! Inequality operator
		bool operator!=(const Triangle3d& other) const
		{
			return !(*this==other);
		}
		
		Plane getPlane() const
		{
			return Plane(pointA, pointB, pointC);
		}

		//! Get the area of the triangle
		float getArea() const
		{
			return (pointB - pointA).cross(pointC - pointA).length_squared() * 0.5f;

		}
		bool isFrontFacing(const Vec3& lookDirection) const
		{
			const Vec3 n = getNormal().normalized();
			const float d = (float)n.dot(lookDirection);
			return d;
		}
		Vec3 getNormal() const
		{
			return (pointB - pointA).cross(pointC - pointA);
		}

		//! sets the triangle's points
		void set(const Vec3& a, const  Vec3& b, const  Vec3& c)
		{
			pointA = a;
			pointB = b;
			pointC = c;
		}


		Vec3 pointA;
		Vec3 pointB;
		Vec3 pointC;
};
// -------------------------------------------------------------------------------------------------
// Intersection
// -------------------------------------------------------------------------------------------------

inline bool rayTriangleIntersection( const Vec3 &rayOrig, const Vec3 &rayDir, 
                                     const Vec3 &vert0, const Vec3 &vert1, const Vec3 &vert2,
                                     Vec3 &intsPoint )
{
	// Idea: Tomas Moeller and Ben Trumbore
	// in Fast, Minimum Storage Ray/Triangle Intersection 
	
	// Find vectors for two edges sharing vert0
	Vec3 edge1 = vert1 - vert0;
	Vec3 edge2 = vert2 - vert0;

	// Begin calculating determinant - also used to calculate U parameter
	Vec3 pvec = rayDir.cross( edge2 );

	// If determinant is near zero, ray lies in plane of triangle
	float det = edge1.dot( pvec );


	// *** Culling branch ***
	/*if( det < Epsilon )return false;

	// Calculate distance from vert0 to ray origin
	Vec3 tvec = rayOrig - vert0;

	// Calculate U parameter and test bounds
	float u = tvec.dot( pvec );
	if (u < 0 || u > det ) return false;

	// Prepare to test V parameter
	Vec3 qvec = tvec.cross( edge1 );

	// Calculate V parameter and test bounds
	float v = rayDir.dot( qvec );
	if (v < 0 || u + v > det ) return false;

	// Calculate t, scale parameters, ray intersects triangle
	float t = edge2.dot( qvec ) / det;*/


	// *** Non-culling branch ***
	if( det > -Epsilon && det < Epsilon ) return 0;
	float inv_det = 1.0f / det;

	// Calculate distance from vert0 to ray origin
	Vec3 tvec = rayOrig - vert0;

	// Calculate U parameter and test bounds
	float u = tvec.dot( pvec ) * inv_det;
	if( u < 0.0f || u > 1.0f ) return 0;

	// Prepare to test V parameter
	Vec3 qvec = tvec.cross( edge1 );

	// Calculate V parameter and test bounds
	float v = rayDir.dot( qvec ) * inv_det;
	if( v < 0.0f || u + v > 1.0f ) return 0;

	// Calculate t, ray intersects triangle
	float t = edge2.dot( qvec ) * inv_det;


	// Calculate intersection point and test ray length and direction
	intsPoint = rayOrig + rayDir * t;
	Vec3 vec = intsPoint - rayOrig;
	if( vec.dot( rayDir ) < 0 || vec.length() > rayDir.length() ) return false;

	return true;
}


inline bool rayAABBIntersection( const Vec3 &rayOrig, const Vec3 &rayDir, 
                                 const Vec3 &mins, const Vec3 &maxs )
{
	// SLAB based optimized ray/AABB intersection routine
	// Idea taken from http://ompf.org/ray/
	
	float l1 = (mins.x - rayOrig.x) / rayDir.x;
	float l2 = (maxs.x - rayOrig.x) / rayDir.x;
	float lmin = minf( l1, l2 );
	float lmax = maxf( l1, l2 );

	l1 = (mins.y - rayOrig.y) / rayDir.y;
	l2 = (maxs.y - rayOrig.y) / rayDir.y;
	lmin = maxf( minf( l1, l2 ), lmin );
	lmax = minf( maxf( l1, l2 ), lmax );
		
	l1 = (mins.z - rayOrig.z) / rayDir.z;
	l2 = (maxs.z - rayOrig.z) / rayDir.z;
	lmin = maxf( minf( l1, l2 ), lmin );
	lmax = minf( maxf( l1, l2 ), lmax );

	if( (lmax >= 0.0f) & (lmax >= lmin) )
	{
		// Consider length
		const Vec3 rayDest = rayOrig + rayDir;
		Vec3 rayMins( minf( rayDest.x, rayOrig.x), minf( rayDest.y, rayOrig.y ), minf( rayDest.z, rayOrig.z ) );
		Vec3 rayMaxs( maxf( rayDest.x, rayOrig.x), maxf( rayDest.y, rayOrig.y ), maxf( rayDest.z, rayOrig.z ) );
		return 
			(rayMins.x < maxs.x) && (rayMaxs.x > mins.x) &&
			(rayMins.y < maxs.y) && (rayMaxs.y > mins.y) &&
			(rayMins.z < maxs.z) && (rayMaxs.z > mins.z);
	}
	else
		return false;
}


inline float nearestDistToAABB( const Vec3 &pos, const Vec3 &mins, const Vec3 &maxs )
{
	const Vec3 center = (mins + maxs) * 0.5f;
	const Vec3 extent = (maxs - mins) * 0.5f;
	
	Vec3 nearestVec;
	nearestVec.x = maxf( 0, fabsf( pos.x - center.x ) - extent.x );
	nearestVec.y = maxf( 0, fabsf( pos.y - center.y ) - extent.y );
	nearestVec.z = maxf( 0, fabsf( pos.z - center.z ) - extent.z );
	
	return nearestVec.length();
}

inline void calculateTangents
(
	Vec3& tangent,
	Vec3& bitangent,
	const Vec3& v0, const Vec3& v1, const Vec3& v2, // vertices
	const Vec2& uv0, const Vec2& uv1, const Vec2& uv2) // texture coords
{
	 // Edges of the triangle : position delta
        Vec3 deltaPos1 = v1-v0;
        Vec3 deltaPos2 = v2-v0;

        // UV delta
        Vec2 deltaUV1 = uv1-uv0;
        Vec2 deltaUV2 = uv2-uv0;

		float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
        tangent = (deltaPos1 * deltaUV2.y   - deltaPos2 * deltaUV1.y)*r;
        bitangent = (deltaPos2 * deltaUV1.x   - deltaPos1 * deltaUV2.x)*r;
		
}
inline void calculateTangents(
	Vec3& normal,
	Vec3& tangent,
	Vec3& binormal,
	const Vec3& vt1, const Vec3& vt2, const Vec3& vt3, // vertices
	const Vec2& tc1, const Vec2& tc2, const Vec2& tc3) // texture coords
{


	Vec3 v1 = vt1 - vt2;
	Vec3 v2 = vt3 - vt1;
	normal = v2.cross(v1);
	normal.normalize();

	// binormal

	float deltaX1 = tc1.x - tc2.x;
	float deltaX2 = tc3.x - tc1.x;
	binormal = (v1 * deltaX2) - (v2 * deltaX1);
	binormal.normalize();

	// tangent

	float deltaY1 = tc1.y - tc2.y;
	float deltaY2 = tc3.y - tc1.y;
	tangent = (v1 * deltaY2) - (v2 * deltaY1);
	tangent.normalize();

	// adjust

	Vec3 txb = tangent.cross(binormal);
	if (txb.dot(normal) < 0.0f)
	{
		tangent *= -1.0f;
		binormal *= -1.0f;
	}


}