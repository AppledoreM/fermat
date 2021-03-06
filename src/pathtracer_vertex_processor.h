/*
 * Fermat
 *
 * Copyright (c) 2016-2019, NVIDIA CORPORATION. All rights reserved.
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

#include <pathtracer_core.h>

///@addtogroup Fermat
///@{

///@addtogroup PTLib
///@{

/// A simple implementation of the \ref TPTVertexProcessor policy interface required by all the \ref PTLibCore functions.
/// This class is responsible of processing each vertex generated by the path tracer, including:
///\par
/// - the computation of NEE weights
/// - the computation of scattering weights
/// - the accumulation of emissive surface hits
/// - the accumulation of NEE samples
///
struct PTVertexProcessor
{
	/// preprocess a vertex and return some packed vertex info
	///
	/// \param context					the current context
	/// \param renderer					the current renderer
	/// \param pixel_info				packed pixel info
	/// \param ev						the eye vertex
	/// \param cone_radius				the current cone radius
	/// \param scene_bbox				the scene bounding box
	template <typename PTContext>
	FERMAT_DEVICE
	uint32 preprocess_vertex(
		const PTContext&			context,
		const RenderingContextView&	renderer,
		const PixelInfo				pixel_info,
		const EyeVertex&			ev,
		const float					cone_radius,
		const cugar::Bbox3f			scene_bbox,
		const uint32				prev_vertex_info,
		const cugar::Vector3f		w,
		const float					p_prev)
	{
		return uint32(0xFFFFFFFF);
	}

	//! [PTVertexProcessor::compute_nee_weights]
	/// compute nee weights given a vertex
	///
	/// \param context					the current context
	/// \param renderer					the current renderer
	/// \param pixel_info				packed pixel info
	/// \param vertex_info				packed vertex info
	/// \param ev						the eye vertex
	/// \param f_d						the diffuse brdf
	/// \param f_g						the glossy brdf
	/// \param w						the current path weight
	/// \param f_L						the current light EDF sample contribution, including the MIS weight
	/// \param out_w_d					the output diffuse weight
	/// \param out_w_g					the output glossy weight
	/// \param out_vertex_info			the output packed vertex info
	template <typename PTContext>
	FERMAT_DEVICE
	void compute_nee_weights(
		const PTContext&			context,				// the current context
		const RenderingContextView&	renderer,				// the current renderer
		const PixelInfo				pixel_info,				// packed pixel info
		const uint32				prev_vertex_info,		// packed previous vertex info
		const uint32				vertex_info,			// packed vertex info
		const EyeVertex&			ev,						// the local vertex
		const cugar::Vector3f&		f_d,					// the diffuse BSDF weight
		const cugar::Vector3f&		f_g,					// the glossy BSDF weight
		const cugar::Vector3f&		w,						// the current path weight
		const cugar::Vector3f&		f_L,					// the current light EDF sample contribution
			  cugar::Vector3f&		out_w_d,				// the output diffuse weight
			  cugar::Vector3f&		out_w_g,				// the output glossy weight
			  uint32&				out_vertex_info)		// the output packed vertex info
	{
		//! [PTVertexProcessor::compute_nee_weights_body]
		out_w_d = (context.in_bounce == 0 ? f_d : f_d + f_g) * w * f_L;
		out_w_g = (context.in_bounce == 0 ? f_g : f_d + f_g) * w * f_L;
		out_vertex_info = 0xFFFFFFFF; // mark this unused
		//! [PTVertexProcessor::compute_nee_weights_body]
	}
	//! [PTVertexProcessor::compute_nee_weights]

	//! [PTVertexProcessor::compute_scattering_weights]
	/// compute scattering weights given a vertex
	///
	/// \param context					the current context
	/// \param renderer					the current renderer
	/// \param pixel_info				packed pixel info
	/// \param vertex_info				packed vertex info
	/// \param ev						the local vertex
	/// \param out_comp					the bsdf scattering component
	/// \param g						the bsdf scattering weight (= f/p)
	/// \param w						the current path weight
	/// \param out_w					the output path weight
	/// \param out_vertex_info			the output vertex info
	///
	template <typename PTContext>
	FERMAT_DEVICE
	void compute_scattering_weights(
		const PTContext&			context,				// the current context
		const RenderingContextView&	renderer,				// the current renderer
		const PixelInfo				pixel_info,				// packed pixel info
		const uint32				prev_vertex_info,		// packed previous vertex info
		const uint32				vertex_info,			// packed vertex info
		const EyeVertex&			ev,						// the local vertex
		const uint32				out_comp,				// the bsdf scattering component
		const cugar::Vector3f&		g,						// the bsdf scattering weight (= f/p)
		const cugar::Vector3f&		w,						// the current path weight
			  cugar::Vector3f&		out_w,					// the output path weight
			  uint32&				out_vertex_info)		// the output vertex info
	{
		out_w = g * w;
		out_vertex_info = 0xFFFFFFFF; // mark this unused
	}
	//! [PTVertexProcessor::compute_scattering_weights]

	//! [PTVertexProcessor::accumulate_emissive]
	/// accumulate an emissive surface hit
	///
	/// \param context					the current context
	/// \param renderer					the current renderer
	/// \param pixel_info				packed pixel info
	/// \param vertex_info				packed vertex info
	/// \param ev						the eye vertex
	/// \param w						the emissive sample weight
	///
	template <typename PTContext>
	FERMAT_DEVICE
	void accumulate_emissive(
		const PTContext&			context,				// the current context
			  RenderingContextView&	renderer,				// the current renderer
		const PixelInfo				pixel_info,				// packed pixel info
		const uint32				prev_vertex_info,		// packed previous vertex info
		const uint32				vertex_info,			// packed vertex info
		const EyeVertex&			ev,						// the local vertex
		const cugar::Vector3f&		w)						// the current path weight
	{
		FBufferView& fb = renderer.fb;
		FBufferChannelView& composited_channel = fb(FBufferDesc::COMPOSITED_C);
		FBufferChannelView& direct_channel     = fb(FBufferDesc::DIRECT_C);
		FBufferChannelView& diffuse_channel    = fb(FBufferDesc::DIFFUSE_C);
		FBufferChannelView& specular_channel   = fb(FBufferDesc::SPECULAR_C);

		const uint32 pixel_index = pixel_info.pixel;
		const uint32 pixel_comp  = pixel_info.comp;
		const float frame_weight = context.frame_weight;

		// accumulate to the image
		add_in<false>(composited_channel, pixel_index, w, frame_weight);

		// accumulate the per-component value to the proper output channel
		if (context.in_bounce == 0)
			add_in<false>(direct_channel, pixel_index, w, frame_weight);
		else
		{
			if (pixel_comp & Bsdf::kDiffuseMask) add_in<true>(diffuse_channel,  pixel_index, w, frame_weight);
			if (pixel_comp & Bsdf::kGlossyMask)	 add_in<true>(specular_channel, pixel_index, w, frame_weight);
		}
	}
	//! [PTVertexProcessor::accumulate_emissive]

	//! [PTVertexProcessor::accumulate_nee]
	/// accumulate a NEE sample
	///
	/// \param context					the current context
	/// \param renderer					the current renderer
	/// \param pixel_info				packed pixel info
	/// \param vertex_info				packed vertex info
	/// \param hit						the hit information
	/// \param w_d						the diffuse nee weight
	/// \param w_g						the glossy nee weight
	///
	template <typename PTContext>
	FERMAT_DEVICE
	void accumulate_nee(
		const PTContext&			context,				// the current context
			  RenderingContextView&	renderer,				// the current renderer
		const PixelInfo				pixel_info,				// packed pixel info
		const uint32				vertex_info,			// packed vertex info
		const bool					shadow_hit,				// the hit information
		const cugar::Vector3f&		w_d,					// the diffuse NEE weight
		const cugar::Vector3f&		w_g)					// the glossy NEE weight
	{
		if (shadow_hit == false)
		{
			FBufferView& fb = renderer.fb;
			FBufferChannelView& composited_channel = fb(FBufferDesc::COMPOSITED_C);
			FBufferChannelView& diffuse_channel    = fb(FBufferDesc::DIFFUSE_C);
			FBufferChannelView& specular_channel   = fb(FBufferDesc::SPECULAR_C);

			const uint32 pixel_index = pixel_info.pixel;
			const uint32 pixel_comp  = pixel_info.comp;
			const float frame_weight = context.frame_weight;

			add_in<false>( composited_channel, pixel_index, w_d + w_g, frame_weight );

			if (context.in_bounce == 0)
			{
				// accumulate the per-component values to the respective output channels
				add_in<true>( diffuse_channel,  pixel_index, w_d, frame_weight );
				add_in<true>( specular_channel, pixel_index, w_g, frame_weight );
			}
			else
			{
				// accumulate the per-component value to the proper output channel
				if (pixel_comp & Bsdf::kDiffuseMask) add_in<true>( diffuse_channel,  pixel_index, w_d, frame_weight );
				if (pixel_comp & Bsdf::kGlossyMask)  add_in<true>( specular_channel, pixel_index, w_g, frame_weight );
			}
		}
	}
	//! [PTVertexProcessor::accumulate_nee]
};

///@} PTLib
///@} Fermat
