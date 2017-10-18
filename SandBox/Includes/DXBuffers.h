#ifndef __DXBUFFERS_HH__
#define __DXBUFFERS_HH__

typedef ID3D11Buffer				IDirect3DIndexBuffer;
typedef ID3D11Buffer				IDirect3DVertexBuffer;
typedef ID3D11VertexShader 			IDirect3DVertexShader;
typedef ID3D11PixelShader 			IDirect3DPixelShader;
typedef	ID3D11InputLayout			IDirect3DVertexDeclaration;

class DXVertexBuffer : public VertexBuffer {
private:
	IDirect3DVertexBuffer *	res;
public:
	DXVertexBuffer() : res(NULL) {}
	IDirect3DVertexBuffer * GetRes() { return res; }
	virtual void Create(U32 _Size,U32 _Usage,void * _Datas);
	virtual bool IsInited() { return res!=NULL; }
	virtual void operator = (DXVertexBuffer& _buffer)
	{
		res = _buffer.res;
	}
	virtual bool Lock(U32 OffsetToLock,U32 SizeToLock,void **pData,U32 Flags);
	virtual void Unlock();
};

class DXIndexBuffer : public IndexBuffer {
private:
	IDirect3DIndexBuffer *	res;
public:
	DXIndexBuffer() : res(NULL) {}
	IDirect3DIndexBuffer * GetRes() { return res; }
	virtual void Create(U32 _Size,U32 _Usage,U32 _Fmt=FMT_IDX_16,void * _Datas=NULL);
	virtual bool IsInited() { return res!=NULL; }
	virtual void operator = (DXIndexBuffer& _buffer)
	{
		res = _buffer.res;
	}
	virtual bool Lock(U32 OffsetToLock,U32 SizeToLock,void **pData,U32 Flags);
	virtual void Unlock();
};

class DXVertexDeclaration : public VertexDeclaration {
private:
	IDirect3DVertexDeclaration	*	res;
public:
	DXVertexDeclaration() : res(NULL) {}
	IDirect3DVertexDeclaration * GetRes() { return res; }
	virtual void Create(VertexElement* Decl,U32 _ShaderUID);
};

class DXVertexShader : public VertexShader
{
private:
	IDirect3DVertexShader *	res;
public:
	DXVertexShader() : res(NULL) {}
	IDirect3DVertexShader * GetRes() { return res; }
	virtual bool IsInited() { return res!=NULL; }
};

class DXPixelShader : public PixelShader
{
private:
	IDirect3DPixelShader *		res;
public:
	DXPixelShader() : res(NULL) {}
	IDirect3DPixelShader * GetRes() { return res; }
	virtual bool IsInited() { return res!=NULL; }
};

class DXGeometryShader : public GeometryShader
{
};

typedef DynArray<DXVertexBuffer,2048>		DXVertexBufferDA;
typedef DynArray<DXIndexBuffer,2048>		DXIndexBufferDA;
typedef DynArray<DXVertexDeclaration,2048>	DXVertexDeclarationDA;
typedef DynArray<DXVertexShader,2048>		DXVertexShaderDA;
typedef DynArray<DXPixelShader,2048>			DXPixelShaderDA;

#endif //__DXBUFFERS_HH__
