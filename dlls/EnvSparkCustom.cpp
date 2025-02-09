#include "extdll.h"
#include "util.h"
#include "cbase.h"

class CEnvSparkCustom : public CBaseEntity
{
public:
	// Is called when the entity is triggered by some other entity
	void Think() override;
	void Use(CBaseEntity* pActivator, CBaseEntity* pCaller, USE_TYPE useType, float value) override;

private:
	bool canSpark = false;
};

LINK_ENTITY_TO_CLASS(env_spark_custom, CEnvSparkCustom);

void CEnvSparkCustom::Think()
{
	if (canSpark)
	{
		UTIL_Sparks(pev->origin); //Emits sparks at entity origin
	}

	//wait 0.2 sec before calling think again
	//speed is delay keyvalue
	pev->nextthink = gpGlobals->time + pev->speed;
}

void CEnvSparkCustom::Use(CBaseEntity* pActivator, CBaseEntity* pCaller, USE_TYPE useType, float value)
{
	canSpark = !canSpark;
	//think now when triggered
	pev->nextthink = gpGlobals->time;
}