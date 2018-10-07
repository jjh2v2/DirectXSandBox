#ifndef __RENDERER_SHADER_HH__
#define __RENDERER_SHADER_HH__

enum EShaderType
{
	SHADER_TYPE_VERTEX=1,
	SHADER_TYPE_PIXEL,
	SHADER_TYPE_GEOM,
	SHADER_TYPE_COMPUTE,

	SHADER_TYPE_BITS = (28),
	SHADER_TYPE_MASK = (0xf0000000)
};

enum
{
	// Vertex shaders
	SHADER_VS_NULL			= (SHADER_TYPE_VERTEX<<SHADER_TYPE_BITS),
	SHADER_VS_BASE_SCREENVERTEX,
	SHADER_VS_BASE_2D		,
	SHADER_VS_BASE_MESH		,
	SHADER_VS_IMGUI			,
	SHADER_VS_LAST			,
	SHADER_VS_COUNT			= SHADER_VS_LAST&(~SHADER_TYPE_MASK)
};

enum
{	
	// Pixel shaders
	SHADER_PS_NULL			= (SHADER_TYPE_PIXEL<<SHADER_TYPE_BITS),
	SHADER_PS_PIXEL_LIT					,
	SHADER_PS_PIXEL_GBUFFER				,
	SHADER_PS_POSTPROC_COLORGRADING		,
	SHADER_PS_POSTPROC_FXAA				,
	SHADER_PS_POSTPROC_PASSTHROUGH		,
	SHADER_PS_LINEAR_DEPTH				,
	SHADER_PS_SSAO						,
	SHADER_PS_IMGUI,
	SHADER_PS_LAST						,
	SHADER_PS_COUNT			= SHADER_PS_LAST&(~SHADER_TYPE_MASK)
};

enum
{
	// Geometry shaders
	SHADER_GS_NULL			= (SHADER_TYPE_GEOM<<SHADER_TYPE_BITS),
	SHADER_GS_TEST						,
	SHADER_GS_LAST						,
	SHADER_GS_COUNT			= SHADER_GS_LAST&(~SHADER_TYPE_MASK)
};

enum
{
	// Compute shaders
	SHADER_CS_NULL			= (SHADER_TYPE_COMPUTE<<SHADER_TYPE_BITS),
	SHADER_CS_TEST						,
	SHADER_CS_COLORGRADING				,
	SHADER_CS_LAST						,
	SHADER_CS_COUNT			= SHADER_CS_LAST&(~SHADER_TYPE_MASK)
};

#endif //__RENDERER_SHADER_HH__
