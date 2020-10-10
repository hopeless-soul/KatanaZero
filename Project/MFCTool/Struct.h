#pragma once
#include "Function.h"
#include <iostream>
#include "Typedef.h"
#include <ostream>
#include <istream>
// TODO :: ZeroMemory 를 사용해서 초기화 하는 코드가 많다
// 포인터와 상속을 사용하고 싶어진다면 고민해봐야한다.
struct TexInfo
{
	//이미지를 제어하기 위한 COM 객체
	LPDIRECT3DTEXTURE9 pTexture; 

	// 이미지에 대한 정보를 담고 있을 구조체. 
	D3DXIMAGE_INFO ImageInfo; 

	~TexInfo()noexcept{DXRelease(pTexture);}
};

typedef struct tagTexInfo
{
	// 이미지 한장을 제어하기 위한 컴객체. 예쩐에 쓰던 HBITMAP과 동일한 역할을 수행할 것. 
	LPDIRECT3DTEXTURE9 pTexture;

	// 이미지에 대한 정보를 담고 있을 구조체. 
	D3DXIMAGE_INFO tImageInfo;
}TEXINFO;

// 맵 오브젝트들 그리는 순서 통제
enum ELayer_Map  : int32_t
{
	BACK_GROUND=0,
	FORE_GROUND,
	DECORATIONS,
	NONE,
};

static ELayer_Map operator++(ELayer_Map& _ELayer_Map) {
	_ELayer_Map = static_cast<ELayer_Map>(_ELayer_Map + 1);
	return _ELayer_Map;
}

// 렌더링 하기위해 필요한 정보
struct RenderMapObjInfo
{
	ELayer_Map _LayerMap{ ELayer_Map::BACK_GROUND };
	// Texture 기준 그리는 사이즈
	vec3 Position{};
	int32_t DrawID{};
};

struct ObjectInfo
{
	enum EObjectID : uint32_t
	{
		NONE,
	}; 
	ObjectInfo() = default;
	ObjectInfo(const uint32_t _ObjectID, const vec3& Position) : _ObjectID{ _ObjectID }, Position{ Position } {};

	uint32_t _ObjectID{};
	vec3 Position{};
};
static std::wostream& operator<<(std::wostream& os,
	const ObjectInfo& _ObjectInfo)
{
	return os

		// 파일 저장 시작
		<< _ObjectInfo._ObjectID << std::endl
		<< _ObjectInfo.Position << std::endl;
		// 파일 저장 끝
}

static std::wistream& operator >> (std::wistream& is,
	ObjectInfo& _ObjectInfo)
{
	uint32_t temp{}; 

	is
		>> _ObjectInfo._ObjectID
		>> _ObjectInfo.Position;

	return is;
};



static std::wostream& operator<<(std::wostream& os,
	const RenderMapObjInfo& _RenderMapObjInfo)
{
	return os

		// 파일 저장 시작
		<< _RenderMapObjInfo._LayerMap << std::endl
		<< _RenderMapObjInfo.Position << std::endl
		<< _RenderMapObjInfo.DrawID << std::endl;
	// 파일 저장 끝
}

static std::wistream& operator >> (std::wistream& is,
	RenderMapObjInfo& _RenderMapObjInfo)
{
	int32_t _LayerMap{};

	 is
		>> _LayerMap
		>> _RenderMapObjInfo.Position
		>> _RenderMapObjInfo.DrawID;

	 _RenderMapObjInfo._LayerMap = static_cast<ELayer_Map>(_LayerMap);

	 return is;
};

struct UnitInfo
{
#ifdef _AFX
	CString Name;
#else
	wstring Name;
#endif // AFX
	int32_t Attack; 
	int32_t Defense;
	int32_t Job;
	int32_t Item;
};

static std::wostream& operator<<(std::wostream& os,
	const UnitInfo& _UnitInfo)
{
	return os

		// 널종료 문자열 스트림 체크
		<< _UnitInfo.Name.GetString() <<std::endl
		<< _UnitInfo.Attack << std::endl
		<< _UnitInfo.Defense << std::endl
		<< _UnitInfo.Job << std::endl
		<< _UnitInfo.Item << std::endl;
}

static std::wistream& operator >> (std::wistream& is,
	UnitInfo& _UnitInfo)
{
	std::wstring Temp;

	is
		>> Temp
		>> _UnitInfo.Attack
		>> _UnitInfo.Defense
		>> _UnitInfo.Job
		>> _UnitInfo.Item;

	_UnitInfo.Name = Temp.c_str();

	return is;
};
