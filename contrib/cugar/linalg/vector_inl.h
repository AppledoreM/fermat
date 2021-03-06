/*
 * cugar
 * Copyright (c) 2011-2018, NVIDIA CORPORATION. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the NVIDIA CORPORATION nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

namespace cugar {

#if 0
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM>::Vector(const T* v)
{
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        this->operator[](d) = v[d];
}
#endif

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> operator- (const Vector<T, DIM>& op)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = -op[d];
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> operator+ (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = op1[d] + op2[d];
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM>& operator+= (Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        op1[d] += op2[d];
    return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> operator- (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = op1[d] - op2[d];
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM>& operator-= (Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        op1[d] -= op2[d];
    return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> operator* (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = op1[d] * op2[d];
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM>& operator*= (Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        op1[d] = op1[d] * op2[d];
    return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> operator* (const T op1, const Vector<T, DIM>& op2)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = op1 * op2[d];
	return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> operator* (const Vector<T, DIM>& op1, const T op2)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = op1[d] * op2;
	return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM>& operator*= (Vector<T, DIM>& op1, const T op2)
{
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		op1[d] = op1[d] * op2;
	return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> operator/ (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = op1[d] / op2[d];
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM>& operator/= (Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        op1[d] = op1[d] / op2[d];
    return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> operator/ (const Vector<T, DIM>& op1, const T op2)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = op1[d] / op2;
	return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM>& operator/= (Vector<T, DIM>& op1, const T op2)
{
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		op1[d] = op1[d] / op2;
	return op1;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> min(const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = cugar::min( op1[d], op2[d] );
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> max(const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    Vector<T,DIM> r;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r[d] = cugar::max( op1[d], op2[d] );
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> min(const Vector<T,DIM>& op1, const T op2)
{
	Vector<T,DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = cugar::min( op1[d], op2 );
	return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T,DIM> max(const Vector<T,DIM>& op1, const T op2)
{
	Vector<T,DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = cugar::max( op1[d], op2 );
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> abs(const Vector<T, DIM>& op)
{
	Vector<T,DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = cugar::abs( op[d] );
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool any(const Vector<T,DIM>& op)
{
    bool r = false;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r || (op[d] != 0);
    return r;
}
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool all(const Vector<T,DIM>& op)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op[d] != 0);
    return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator== (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op1[d] == op2[d]);
    return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator!= (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = false;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r || (op1[d] != op2[d]);
    return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator< (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op1[d] < op2[d]);
    return r;
}


template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator<= (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op1[d] <= op2[d]);
    return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator> (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op1[d] > op2[d]);
    return r;
}


template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool operator>= (const Vector<T,DIM>& op1, const Vector<T,DIM>& op2)
{
    bool r = true;
    #pragma unroll
    for (uint32 d = 0; d < DIM; ++d)
        r = r && (op1[d] >= op2[d]);
    return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T dot(const Vector<T, DIM>& op1, const Vector<T, DIM>& op2)
{
	T r = T(0.0f);
	for (uint32 d = 0; d < DIM; ++d)
		r += op1[d] * op2[d];
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T square_length(const Vector<T, DIM>& op)
{
	return dot(op, op);
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T length(const Vector<T, DIM>& op)
{
	return sqrt( dot(op, op) );
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> normalize(const Vector<T, DIM>& op)
{
	const T l = length(op);
	return l > T(0) ? op / l : op;
}

template <typename T>
CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
Vector<T, 3u> cross(const Vector<T, 3u>& op1, const Vector<T, 3u>& op2)
{
	return Vector<T, 3u>(
		op1[1] * op2[2] - op1[2] * op2[1],
		op1[2] * op2[0] - op1[0] * op2[2],
		op1[0] * op2[1] - op1[1] * op2[0]);
}
template <typename T>
CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
Vector<T, 3> reflect(const Vector<T, 3> I, const Vector<T, 3> N)
{
	return I - T(2.0)*dot(I, N)*N;
}
template <typename T>
CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
Vector<T, 3> refract(const Vector<T, 3> I, const Vector<T, 3> N, const float eta)
{
	const float N_dot_I = dot(N, I);
	const float cos_theta_t2 = 1.f - eta * eta * (1.f - N_dot_I * N_dot_I);
	if (cos_theta_t2 < 0.f)
		return reflect(I,N); // total internal reflection
	else
		return eta * I - (eta * N_dot_I + sqrtf(cos_theta_t2)) * N;
}
template <typename T>
CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
Vector<T, 3> refraction_normal(const Vector<T, 3> I, const Vector<T, 3> T, const float eta)
{
	return normalize(T - I * eta);
}
template <typename T>
CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
Vector<T, 3> faceforward(const Vector<T, 3> N, const Vector<T, 3> I)
{
	return dot(I,N) > 0.0f ? N : -N;
}
template <typename T>
CUGAR_HOST_DEVICE
Vector<T, 3> orthogonal(const Vector<T, 3> v)
{
	if (v[0] * v[0] < v[1] * v[1])
	{
		if (v[0] * v[0] < v[2] * v[2])
		{
			// r = -cross( v, (1,0,0) )
			return Vector<T, 3>(0.0f, -v[2], v[1]);
		}
		else
		{
			// r = -cross( v, (0,0,1) )
			return Vector<T, 3>(-v[1], v[0], 0.0);
		}
	}
	else
	{
		if (v[1] * v[1] < v[2] * v[2])
		{
			// r = -cross( v, (0,1,0) )
			return Vector<T, 3>(v[2], 0.0, -v[0]);
		}
		else
		{
			// r = -cross( v, (0,0,1) )
			return Vector<T, 3>(-v[1], v[0], 0.0);
		}
	}
}

template <typename T>
CUGAR_HOST_DEVICE
void orthonormal_basis(
	const Vector<T, 3>	normal,
		  Vector<T, 3>&	tangent,
		  Vector<T, 3>&	bitangent)
{
    // [Duff et al. 17] Building An Orthonormal Basis, Revisited. JCGT. 2017.
    const T sign = normal.z >= T(0) ? T(1) : T(-1);

	const T a = -T(1)/(sign + normal.z);
    const T b = normal.x * normal.y * a;

	tangent		= Vector<T,3>(1.0f + sign*normal.x*normal.x*a, sign*b, -sign*normal.x);
    bitangent	= Vector<T,3>(b, sign + normal.y*normal.y*a, -normal.y);
}

CUGAR_HOST_DEVICE CUGAR_FORCEINLINE
void orthonormal_basis(
	const Vector3f	normal,
		  Vector3f&	tangent,
		  Vector3f&	bitangent)
{
    // [Duff et al. 17] Building An Orthonormal Basis, Revisited. JCGT. 2017.
    const float sign = copysignf(1.0f, normal.z);

	const float a = -1.0f/(sign + normal.z);
    const float b = normal.x * normal.y * a;

	tangent		= Vector3f(1.0f + sign*normal.x*normal.x*a, sign*b, -sign*normal.x);
    bitangent	= Vector3f(b, sign + normal.y*normal.y*a, -normal.y);
}

template <typename T>
CUGAR_HOST_DEVICE
uint32 pack_vector(const Vector<T, 2> v, const uint32 n_bits_comp)
{
	const uint32 MAX = (1u << n_bits_comp) - 1u;
	const uint32 x = cugar::quantize(v[0], MAX);
	const uint32 y = cugar::quantize(v[1], MAX);
	return x | (y << n_bits_comp);
}

template <typename T>
CUGAR_HOST_DEVICE
Vector<T, 2> unpack_vector(const uint32 u, const uint32 n_bits_comp)
{
	const uint32 MAX = (1u << n_bits_comp) - 1u;
	return Vector<T, 2>(
		T(u & MAX)			/ T(MAX),
		T(u >> n_bits_comp) / T(MAX) );
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> mod(const Vector<T, DIM>& op, const T m)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = mod(op[d],m);
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> sqrt(const Vector<T, DIM>& op)
{
	Vector<T, DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = ::sqrt(op[d]);
	return r;
}

template <uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<float,DIM> sqrt(const Vector<float,DIM>& op)
{
	Vector<float,DIM> r;
	#pragma unroll
	for (uint32 d = 0; d < DIM; ++d)
		r[d] = ::sqrtf(op[d]);
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T max_comp(const Vector<T, DIM>& op)
{
	T r = op[0];
	#pragma unroll
	for (uint32 d = 1; d < DIM; ++d)
		r = max(r, op[d]);
	return r;
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T min_comp(const Vector<T, DIM>& op)
{
	T r = op[0];
#pragma unroll
	for (uint32 d = 1; d < DIM; ++d)
		r = min(r, op[d]);
	return r;
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float max_comp(const Vector3f& op)		// Vector3f specialization
{
	return max3(op.x, op.y, op.z);
}
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float min_comp(const Vector3f& op)		// Vector3f specialization
{
	return min3(op.x, op.y, op.z);
}

template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool is_finite(const Vector<T, DIM>& op)
{
	for (uint32 i = 0; i < DIM; ++i)
	{
		if (is_finite(op[i]) == false)
			return false;
	}
	return true;
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
bool is_finite(const Vector3f& op) { return is_finite(op.x) && is_finite(op.y) && is_finite(op.z); }

// \relates Vector
// L_1 vector norm
//
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T L1_norm(const Vector<T, DIM>& op)
{
	T r = T(0);
	for (uint32 i = 0; i < DIM; ++i)
		r += abs( op[i] );

	return r;
}

// \relates Vector
// L_2 vector norm
//
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T L2_norm(const Vector<T, DIM>& op)
{
	return length( op );
}

// \relates Vector
// L_inf vector norm
//
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T L_inf_norm(const Vector<T, DIM>& op)
{
	return max_comp( op );
}

// \relates Vector
// L_p vector norm
//
template <typename T, uint32 DIM, uint32 p>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T L_norm(const Vector<T, DIM>& op)
{
	if (p == 1) return L1_norm( op );
	else if (p == 2) return L2_norm( op );
	else if (p == uint32(-1)) return L_inf_norm( op );
	else
	{
		T r = T(0);
		for (uint32 i = 0; i < DIM; ++i)
			r += pow( abs( op[i] ), p );

		return pow( r, T(1)/T(p) );
	}
}

// \relates Vector
// L_1 vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float L1_norm(const float op)
{
	return abs( op );
}
// \relates Vector
// L_1 vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double L1_norm(const double op)
{
	return abs( op );
}

// \relates Vector
// L_2 vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float L2_norm(const float op)
{
	return sqrt( op * op );
}
// \relates Vector
// L_2 vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double L2_norm(const double op)
{
	return sqrt( op * op );
}

// \relates Vector
// L_inf vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float L_inf_norm(const float op)
{
	return abs( op );
}
// \relates Vector
// L_inf vector norm
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double L_inf_norm(const double op)
{
	return abs( op );
}

// \relates Vector
// L_p vector norm
//
template <uint32 p>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float L_norm(const float op)
{
	if (p == 1) return L1_norm( op );
	else if (p == 2) return L2_norm( op );
	else if (p == uint32(-1)) return L_inf_norm( op );
	else
		return powf( powf( fabsf( op ), p ), float(1)/float(p) );
}
// \relates Vector
// L_p vector norm
//
template <uint32 p>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double L_norm(const double op)
{
	if (p == 1) return L1_norm( op );
	else if (p == 2) return L2_norm( op );
	else if (p == uint32(-1)) return L_inf_norm( op );
	else
		return pow( pow( fabs( op ), p ), double(1)/double(p) );
}

// \relates Vector
// vector average
//
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
T average(const Vector<T, DIM>& op)
{
	T r = T(0);
	for (uint32 i = 0; i < DIM; ++i)
		r += op[i];

	return r / T(DIM);
}

// \relates Vector
// vector average
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float average(const float op)
{
	return op;
}
// \relates Vector
// vector average
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double average(const double op)
{
	return op;
}

// \relates Vector
// vector lerp
//
template <typename T, uint32 DIM>
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector<T, DIM> lerp(const Vector<T, DIM>& op1, const Vector<T, DIM>& op2, const T u)
{
	return op1 * (T(1) - u) + op2 * u;
}

// \relates Vector
// vector lerp
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float lerp(const float op1, const float op2, const float u)
{
	return op1 * (1 - u) + op2 * u;
}

// \relates Vector
// vector lerp
//
CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
double lerp(const double op1, const double op2, const double u)
{
	return op1 * (1 - u) + op2 * u;
}


CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector3f encode_normal(Vector3f N)
{
	return N * 0.5f + Vector3f(0.5f);
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector3f decode_normal(Vector3f N)
{
	return N * 2.0f - Vector3f(1.0f);
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
uint32 float_to_uint(const float f, const uint32 n)
{
	return uint32( f * n );
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
uint32 float3_to_r10g10b10(float3 unpackedInput)
{
	uint32 packedOutput;
	packedOutput = (
		(float_to_uint(saturate(unpackedInput.x), 1023)) |
		(float_to_uint(saturate(unpackedInput.y), 1023) << 10) |
		(float_to_uint(saturate(unpackedInput.z), 1023) << 20)
	);
	return packedOutput;
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
float3 r10g10b10_to_float3(uint32 packedInput)
{
	float3 unpackedOutput;
	unpackedOutput.x = (float)(packedInput & 0x000003ff) / 1023;
	unpackedOutput.y = (float)(((packedInput >> 10) & 0x000003ff)) / 1023;
	unpackedOutput.z = (float)(((packedInput >> 20) & 0x000003ff)) / 1023;
	return unpackedOutput;
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
uint32 pack_normal(Vector3f N)
{
	return float3_to_r10g10b10(encode_normal(N));
}

CUGAR_FORCEINLINE CUGAR_HOST_DEVICE
Vector3f unpack_normal(uint32 Ni)
{
	return decode_normal(r10g10b10_to_float3(Ni));
}

} // namespace cugar
