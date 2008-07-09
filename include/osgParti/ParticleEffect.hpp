#ifndef _CRSFX_PARTICLEEFFECT_HPP_
#define _CRSFX_PARTICLEEFFECT_HPP_ 1

#include <crsFX/Export.hpp>
#include <crsFX/BaseEffect.hpp>
#include <crsFX/ParticleSystem.hpp>
namespace crsFX {

	class CRSFX_EXPORT ParticleEffect: public BaseEffect
	{
		public:
			ParticleEffect();
			ParticleEffect(const ParticleEffect&,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY);
			ParticleSystem* getParticleSystem() { return particleSystem.get(); }
			const ParticleSystem* getParticleSystem() const { return particleSystem.get(); }
			META_Node(crsFX,ParticleEffect);
			
			virtual void init();
		
		protected:
			virtual ~ParticleEffect();
			osg::ref_ptr<ParticleSystem> particleSystem;
		
	};

}

#endif /*_CRSFX_PARTICLEEFFECT_HPP_*/

