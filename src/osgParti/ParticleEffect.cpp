#include <crsFX/ParticleEffect.hpp>
#include <crsFX/Scripting.hpp>

#include <iostream>


#include <osgUtil/CullVisitor>


using namespace crsFX;


ParticleEffect::ParticleEffect():crsFX::BaseEffect()
{
		particleSystem = new crsFX::ParticleSystem();
}

ParticleEffect::ParticleEffect(const ParticleEffect& effect,const osg::CopyOp& copyop):
	crsFX::BaseEffect(effect,copyop)
{
		
}

ParticleEffect::~ParticleEffect()
{
}

void ParticleEffect::init()
{	
	crsFX::BaseEffect::init();
	if(!particleSystem.valid()) particleSystem = new crsFX::ParticleSystem();
		
	particleSystem->setMinTheta(2.0);
	particleSystem->setMaxTheta(4.0);
	//particleSystem->setMaxRGB(osg::Vec4f(1.0,1.0,1.0,0.7));
	//particleSystem->setMinRGB(osg::Vec4f(0.0,0.0,1.0,1.0));

	addChild(particleSystem->getPat());
    addChild(particleSystem->getGroup());
}




CRSFX_WRAPPER
(

	ReferencedClass<ParticleEffect>("crsFX::ParticleEffect")
		.inherits<BaseEffect>()
		.inherits<osg::Group>()
		.inherits<osg::Node>()
		.inherits<osg::Object>()
		.constructor()
		.set("init", &ParticleEffect::init)
		.nonconst_set("getParticleSystem", &ParticleEffect::getParticleSystem)
		.const_set("const_getParticleSystem", &ParticleEffect::getParticleSystem)
	;
)



