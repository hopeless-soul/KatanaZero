#pragma once
#include <map>
#include <string>
#include <memory>
#include <Windows.h>
#include "singleton_interface.h"

class Texture_Manager : public singleton_interface<Texture_Manager>
{
public:
	virtual ~Texture_Manager()noexcept;
public:
	enum TEX_ID {SINGLE_TEX, MULTI_TEX};
public:
	// 싱글 텍스쳐의 경우 2번째 파라미터부턴 의미가 없습니다.
	std::shared_ptr<class TexInfo> Get_TexInfo
(const std::wstring& ObjectKey, const std::wstring& StateKey = L"", 
/*Zero Base [0,Index)*/const DWORD& Index = 0);

	
	HRESULT InsertTexture(const TEX_ID ETexID, const std::wstring& FilePath, const 
		std::wstring& ObjectKey,
	const std::wstring& StateKey = L"", const DWORD& Index = 0);

	void Release(); 
	// 여기서의 wstring은 오브젝트키 - 객체 - 플레이어, npc, 보스 1, 보스2 보스3, 잡몹 23~
	std::map<std::wstring,std::shared_ptr<class Texture>> TextureMap; 
};

