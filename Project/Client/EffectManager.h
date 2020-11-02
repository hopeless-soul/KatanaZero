#pragma once
#include "singleton_interface.h"
#include "CollisionComponent.h"
#include <string_view>
// 50 - 20       / 50 
struct EffectInfo
{
	// ���� ����
	bool bLoop = false;
	// �浹 ���� ������� ����
	bool bPhysic = false;
	// �浹������ ����� ũ��
	float Width = 0.f;
	float Height = 0.f;
	bool bMapSlide = false;
	bool bHitNotify = false;

	std::wstring ObjKey = L"";
	std::wstring StateKey = L"";
	uint8_t DrawID = 0;
	// [Begin,End)
	uint8_t End = 1;
	// ���� ��ġ
	vec3 Pos = { 0,0,0 };
	// ������ ������ �ݸ��� �Ѵ� ����
	vec3 Scale{ 1.f,1.f,1.f };
	// ���ư��� ����
	vec3 Dir = { 0,0,0 };
	// Z�� ���������� �������� ��
	float RotZAcc = 0.f;
	// ȸ��
	float RotZ = 0.f;
	// ���ӽð�
	float MaxT = 1.f;
	// T�� MaxT�� ���޽� ����
	float T = 0.f;
	// �����Ӱ��� ��Ÿ
	float AnimDelta = 0.1f;
	float CurrentDelta = 0.f;

	// ���ĸ� ����Ʈ �ð��� ���� �����ұ�� ?? 
	bool bAlphaLerp = false;
	int32_t Alpha = 255;
	OBJECT_ID::EID _ID = OBJECT_ID::EID::ENONE;
};

class EffectManager : public singleton_interface<EffectManager>
{
public :
	void Initialize() & noexcept;
	void Render();
	void Update();

	void HitEvent(EffectInfo& _Effect ,
		math::Collision::HitInfo _HitInfo);

	D3DXCOLOR SwitchColorFromEffectID(OBJECT_ID::EID _EffectID,D3DXCOLOR _Color);

	void EffectPush(
		const std::wstring_view& _ObjKey,
		const std::wstring_view& _StateKey,
		uint8_t _End,
		float AnimDelta,
		float MaxT,
		OBJECT_ID::EID _EffectID,
		vec3 Pos,
		vec3 Dir={ 0,0,0 },
		vec3 Scale = { 1,1,1 },
		bool bLoop = false,
		bool bPhysic = false,
		bool bMapSlide = false,
		bool bHitNotify = false,
		float Width = 0.f,
		float Height = 0.f,
		int32_t Alpha=255,
		bool bAlphaLerp=false ,
		float T = 0,
		float RotZ = 0,
		float RotZAcc = 0,
		uint8_t _StartID = 0
	);
	std::set<CollisionComponent::ETag> _EffectCollisionTagSet;

	inline std::vector<EffectInfo>& EffectsRef(){return _Effects;}
private:
	std::vector<EffectInfo> _Effects;
};
