#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <PrimitiveBuffers.h>
#include <RendererShader.h>
#include <Material.h>
#include <Camera.h>
#include <imgui.h>

namespace sys {

	class Renderer
	{
	public:

		virtual int	Init();
		virtual bool InitStaticDatas();
		virtual void Shut() = 0;
		virtual void MainLoop() = 0;
		virtual void InitShaders();
		virtual void SetSize(U32 _SizeX,U32 _SizeY) { SizeX=_SizeX; SizeY=_SizeY; }

		// ImGui integration
		virtual void InitImGUI();
		virtual void DrawImGUI();

		// Set current scene camera
				void	SetCamera(Camera * _Cam) { m_Camera=_Cam; }
		inline	Camera* GetCamera() const { return m_Camera; }
		
		//
		// Vertex/Index buffers
		virtual VertexBuffer *		CreateVertexBuffer(U32 _Size,U32 _Usage,void * _Datas);
		virtual IndexBuffer *		CreateIndexBuffer(U32 _Size,U32 _Usage,U32 _Fmt,void * _Datas);
		virtual VertexDeclaration *	CreateVertexDecl(VertexElement* Decl,U32 _ShaderUID);
		virtual void				CreateTexture(Bitmap * _Bmap) = 0;

		virtual void	PushWorldMatrix( Mat4x4* _m ) {}

		virtual void	PushShader( U32 _ShaderUID );
		virtual void	PushVertexDeclaration(VertexDeclaration* Decl) {}
		virtual void	PushStreamSource(U32 StreamNumber,VertexBuffer* Buffer,U32 Offset,U32 Stride) {}
		virtual void	PushIndices(IndexBuffer* Buffer,U32 _Fmt=FMT_IDX_16) {}
		virtual void	PushDrawIndexed(PrimitiveType Type,U32 BaseVertexIndex,U32 MinVertexIndex,U32 NumVertices,U32 StartIndex,U32 PrimCount) {}
		virtual void	PushMaterial(Material* Mat) {}
		virtual void	RegisterShaderFromSourceFile(U32 _SUID,const char* src,const char* epoint) = 0;

		// Graphics command list
		virtual void SetBlendState(D3D11_BLEND_DESC& desc) = 0;
		virtual void SetSampler(U32 Slot, EShaderType Type, void* Sampler) = 0;
		virtual void SetShaderResource(U32 Slot, EShaderType Type, Bitmap* Texture) = 0;
		virtual void DSSetDefault() = 0;
		virtual void RSSetDefault() = 0;
		virtual void SetPrimitiveTopology(PrimitiveType Topology) = 0;
		virtual void DrawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation) = 0;

	protected:
		int		SizeX, SizeY;

		VertexBuffer		*	m_FullscreenQuadVB;
		VertexDeclaration	*	m_ScreenVertexDecl;

		Bitmap				*	m_RenderTarget;
		Bitmap				*	m_HdrRenderTarget;

		Bitmap				*	m_gBuffer[4];
		Bitmap				*	m_linearZBuffer;
		Bitmap				*	m_lightBuffer;
		Bitmap				*	m_localLightBuffer;
		Bitmap				*	m_shadowBuffer;
		Bitmap				*	m_ssaoBuffer;

		// Viewports and camera
		Camera				*	m_Camera;

		// ImGui data
		VertexDeclaration* m_ImGuiVertexDeclaration = nullptr;
		VertexBuffer* m_ImGuiVB = nullptr;
		IndexBuffer* m_ImGuiIB = nullptr;
	};

};

#endif //__RENDERER_H__
