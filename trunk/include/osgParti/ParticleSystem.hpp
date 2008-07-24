#ifndef _OSGPARTI_PARTICLESYSTEM_HPP_
#define _OSGPARTI_PARTICLESYSTEM_HPP_ 1

#include <osg/Object>
#include <osg/Group>
#include <osg/Geode>
#include <osg/PositionAttitudeTransform>
#include <osgParti/Export.hpp>
#include <osgParticle/ParticleSystem>
#include <osgParticle/Particle>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/ModularEmitter>
#include <osgParticle/ModularProgram>
#include <osgParticle/AccelOperator>
#include <osgParticle/FluidFrictionOperator>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/PointPlacer>
#include <osgParticle/RadialShooter>
/*
    SDL Includes
*/
#include <string>

using std::string;

namespace osgParti {

	class OSGPARTI_EXPORT ParticleSystem: public osg::Object {
		public:
    
			ParticleSystem();
    		ParticleSystem(const ParticleSystem&,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY) {}

			META_Object(osgParti,ParticleSystem);
    
    /*
        Returns the osg::Group node to be attached to the SceneGraph
    */
    osg::Group* getGroup();
    
    /*
        Returns the osg::PositionAttitudeTransform which holds the Emitter, so we
        may translate it into the screen.
        
        We could have added it to the above group, but if we keep things separate
        in this manner, it would be easy later grab this PAT and translate it
        around in space dynamically.
    */
    osg::PositionAttitudeTransform* getPat();
    
    //Particle Colors //////////////////////////////////////////////////////////
    
	void setMinRGB(const osg::Vec4f &color);
	void setMaxRGB(const osg::Vec4f &color);
 

	void incMinR();
    void incMinG();
    void incMinB();
    void incMaxR();
    void incMaxG();
    void incMaxB();
   
    void decMinR();
    void decMinG();
    void decMinB();
    void decMaxR();
    void decMaxG();
    void decMaxB();
    
    void incMinAlpha();
    void incMaxAlpha();
    void decMinAlpha();
    void decMaxAlpha();
    
    osg::Vec4f getMinColor() const;
    osg::Vec4f getMaxColor() const;
    
    //Particle Size ////////////////////////////////////////////////////////////
    
	void setMinSize(float size);
	void setMaxSize(float size);
	void incMinSize();
    void incMaxSize();
    void decMinSize();
    void decMaxSize();
    
    osgParticle::rangef getSize() const;
    
    //Particle Shape ///////////////////////////////////////////////////////////
    void setShapePoint();
    void setShapeQuad();
    void setShapeQuadTriangle();
    void setShapeHex();
    void setShapeLine();
    
    string getShape() const;
    
    //Particle Lifetime ////////////////////////////////////////////////////////
    
	void setLifeTime(float time);
	void incLifetime();
    void decLifetime();
    
    double getLifetime() const;
    
    //Particle Alignment ///////////////////////////////////////////////////////////
    void setAlignmentFixed();
    void setAlignmentBillboard();
    
    string getAlignment() const;
    
    //Particle Count ///////////////////////////////////////////////////////////
  	
	void setMinRate(float rate);
	void setMaxRate(float rate);
	void incMinRate();
    void incMaxRate();
    void decMinRate();
    void decMaxRate();
    
    osgParticle::rangef getRate() const;
    
    //Particle Theta ///////////////////////////////////////////////////////////
    
	void setMinTheta(float theta);
	void setMaxTheta(float theta);
	
	void incMinTheta();
    void incMaxTheta();
    void decMinTheta();
    void decMaxTheta();
    
    osgParticle::rangef getTheta() const;
    
    //Particle Phi ///////////////////////////////////////////////////////////
    
	void setMinPhi(float phi);
	void setMaxPhi(float phi);
	void incMinPhi();
    void incMaxPhi();
    void decMinPhi();
    void decMaxPhi();
    
    osgParticle::rangef getPhi() const;
    
    //Particle Speed ///////////////////////////////////////////////////////////
   
	void setMinSpeed(float speed);
	void setMaxSpeed(float speed);
 	void incMinSpeed();
    void incMaxSpeed();
    void decMinSpeed();
    void decMaxSpeed();
    
    osgParticle::rangef getSpeed() const;
 ~ParticleSystem();
protected:
    
	
	//Holds the Geode, and Updater
    osg::ref_ptr<osg::Group>                             root;

    //Holds the ParticleSystem as it is a Drawable
    osg::ref_ptr<osg::Geode>                             geode;
    
    //Emitter which holds ParticleSystem, RandomRateCounter, PointPlacer, RadialShooter
    osg::ref_ptr<osgParticle::ModularEmitter>            emitter;
    
    //ParticleSystem which contains the Default Particle
    osg::ref_ptr<osgParticle::ParticleSystem>            particleSystem;
    
    //Default Particle which will define all other particles created by ParticleSystem
   osgParticle::Particle *                 				 defaultParticle;
    
    //Helper Class to auto update the ParticleSystem
    osg::ref_ptr<osgParticle::ParticleSystemUpdater>     updater;
    
    //Determines how many particles are created per second
    osg::ref_ptr<osgParticle::RandomRateCounter>         rateCounter;
    
    //Defines particles spawning from a single point in space
    osg::ref_ptr<osgParticle::PointPlacer>               placer;
    
    //Shoots particles out in a radial fashion
   osg::ref_ptr<osgParticle::RadialShooter>             shooter;
    
    //Positions the Emitter into the screen so we can see the particles
    osg::ref_ptr<osg::PositionAttitudeTransform>         pat;
    
    /*
        Constants used in the property modifier functions. Defined here so
        all functions are consistent among updates.
    */
   
    
};
}
#endif
