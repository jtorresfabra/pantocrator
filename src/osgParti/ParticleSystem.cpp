#include <osgParti/ParticleSystem.hpp>

#define SMALL_INCREMENT   0.01
#define MEDIUM_INCREMENT  0.1
#define LARGE_INCREMENT   1.0


using namespace osgParti;


ParticleSystem::ParticleSystem()
  :
  	root(new osg::Group()),
	  geode(new osg::Geode()),
	  emitter(new osgParticle::ModularEmitter()),
	  particleSystem(new osgParticle::ParticleSystem()),
	  defaultParticle(new osgParticle::Particle()),
	  updater(new osgParticle::ParticleSystemUpdater()),
	  rateCounter((osgParticle::RandomRateCounter*)emitter->getCounter()),
	  placer((osgParticle::PointPlacer*)emitter->getPlacer()),
	  shooter((osgParticle::RadialShooter*)emitter->getShooter()),
	  pat(new osg::PositionAttitudeTransform())
  {

//Set the Default Particle Properties
  //    {Shape, Size, Color, Lifetime}
        
  //The particle we define here will be used as the basis 
  // for all particles in the particle system.
  //    Shape is one of:
  //        {POINT, QUAD, QUAD_TRIANGLESTRIP, HEXAGON, LINE}
  defaultParticle->setShape(osgParticle::Particle::HEXAGON);
    
  //    Range from 0.0 to x.y
  defaultParticle->setSizeRange(osgParticle::rangef(0.0,5.0));
    
  //  Set the color range- here we're setting it from min(black) to max(black)
  //  The color range works like this: The conception of the particle starts
  //  with the minimum color, and as the particle ages towards it's death,
  //  the color gradually changes to the maximum color.
  defaultParticle->setColorRange(
      osgParticle::rangev4(
          osg::Vec4f(0.0, 0.0, 0.0, 1.0),
          osg::Vec4f(0.0, 0.0, 0.0, 1.0)
      )
  );
    
  // Note that a lifetime of 0.0 will mean indefinite... the particle will never
  // die. This is bad because we still have to dedicate resources to the particles
  // throughout their lifetime. (In seconds)
  defaultParticle->setLifeTime(100);
    
/*
    Particle System Properties - This is where we set the default particle.
    
    Note that Particle System is a derived class of Drawable, thus we must
    add it to an osg::Geode before we may add it to the SceneGraph.
*/
  particleSystem->setDefaultAttributes("../include/images/smoke.png", true, false);
  particleSystem->setDefaultParticleTemplate(*defaultParticle);
  geode->addDrawable(particleSystem.get());
  root->addChild(geode.get());
    
/*
    ParticleSystemUpdater - this is a utility class that will automatically update
    and draw particles in the system. We add the previously created ParticleSystem
    here, and then add the Updater to the SceneGraph directly.
*/
  updater->addParticleSystem(particleSystem.get());
  root->addChild(updater.get());
    
/*
    RandomRateCounter - One class required by the ModularEmitter, this class will
    control how many particles are created per second.
*/
  rateCounter->setRateRange(5.0, 200.0);
    
/*
    RadialShooter - This class shoots particles in a radius, using Theta and Phi
    as angles.
*/
    /*
        Theta and Phi:
        
        Think of a piece of paper upon which you are going to use a mechanical
        compass to draw a circle. Theta represents
        the radius of the circle (how wide you stretch the pencil leg from the
        center point, and Phi represents how much of the circle you actually draw.
        As Phi is measured in radians, assuming you only wish to draw half the
        circle, you would draw pi (~3.14) radians worth of the circle. Obviously,
        2pi would give you the entire circle. How do the min/max relate two these
        two concepts?
        
        Well think of it as a shaded area of the circle. The min Theta determines
        the start of the shaded area. If min theta is 0, then the entire area defined
        by max theta is the total area. However, if min theta is .25 and the max
        theta is .5, then you would have a ring of shaded area. The closer the
        min gets to 0, the closer you get to using the entire area of the circle.
        Likewise, the closer min approaches max, the thinner your ring of area becomes.
        If you set min/max to the same value, you would have in essence a discrete
        ring.
        
        Min/max Phi works similarly, but they define the starting/ending points
        around the circle which you want to include in the area.
        
        Try to grasp the concept using this program by setting the initial values
        of:
        
        Theta min: 0.1, max 0.2
        Phi min: 0.0, max 6.2
        
        This is easier seen when using quad particles (hit the number 2). You'll
        see what appears to be a tunnel as particles shoot around you, but not directly
        at you. Want some particles flying in your face? Reduce min theta a little
        till it approaches 0. The difference between min/max theta will determine
        the "wall of particles" thickness. Phi min/max simply control where
        there may be any opening in the tunnel, if any.
        
        Increase the speed of the particles to ~2 so they will fly past us,
        and reduce the size to (0, ~0.1). Increase the particle rate and
        change the colors to enhance the effect. This hopefully will give
        you a good idea of how a radial shooter works.
        
        Note though that while we were talking about a 2D circle, in OSG
        the shooter is a radial shooter, meaning it shoots things in a spherical fashion, 
        so theta really represents the angle of the arc from the center point of
        the shooter.
    */
  shooter->setThetaRange( osgParticle::rangef(0.01, 0.2));
  shooter->setPhiRange( osgParticle::rangef(0.0, 6.2));
  shooter->setInitialSpeedRange( osgParticle::rangef(0.1, 10));
    
/*
    ModularEmitter - This class ties in 4 systems:
        Shooter
        Placer
        Counter
        ParticleSystem
        
    The first 3 are automatically created by the ModularEmitter, which explains
    why we grabbed an instance of them in the initialization list of this constructor.
    
    The ParticleSystem, however, is not created upon construction of the ModularEmitter,
    so we had to create one separately, and now we add it to the Emitter. Note
    that the ParticleSystem is now added in 3 places:
    
    Geode connected to the SceneGraph
    ParticleSystemUpdater
    ModularEmitter
*/
  emitter->setParticleSystem(particleSystem.get());
    
    /*
        Because we don't want the emitter to be right on top of the camera
        (0, 0, 0) in the SceneGraph, we stick it on a PAT and then position
        it 10 units into the screen.
    */
  pat->addChild(emitter.get());	
  pat->setPosition( osg::Vec3d(0.0, 0.0,0.0));

  osgParticle::ModularProgram *moveDustInAir = new osgParticle::ModularProgram;
  moveDustInAir->setParticleSystem(particleSystem.get());

  // Create an operator that simulates gravity, adjust it and add it to our program
  osgParticle::AccelOperator *accelUp = new osgParticle::AccelOperator;
  accelUp->setToGravity(9.8); // scale factor for normal acceleration due to gravity. 
  moveDustInAir->addOperator(accelUp);

  // Add an operator to our program to calculate the friction of air.
  osgParticle::FluidFrictionOperator *airFriction = new osgParticle::FluidFrictionOperator;
  //airFriction->setFluidViscosity(100.0f);
 airFriction->setFluidDensity(50);
 // airFriction->setFluidDensity(1.2929/*air*/*5.0f);
  moveDustInAir->addOperator(airFriction);
//airFriction->setFluidToWater();
  // Finally, add the program to the scene 
  root->addChild(moveDustInAir);



}

ParticleSystem::~ParticleSystem(){}

osg::Group* ParticleSystem::getGroup() { return root.get(); }

osg::PositionAttitudeTransform* ParticleSystem::getPat(){
  return pat.get();
}

//EXTERNAL FUNCTIONALITY TO CHANGE PARTICLE PROPERTIES


//Particle Colors ///////////////////////////////////////////////////
void ParticleSystem::setMinRGB(const osg::Vec4f &color)
{
	const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
	osgParticle::range<osg::Vec4f> new_range(color,color_range.maximum);
	 defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

void ParticleSystem::setMaxRGB(const osg::Vec4f &color){
	const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
	osgParticle::range<osg::Vec4f> new_range(color_range.minimum,color);
	 defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
}




void ParticleSystem::incMinR() {
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.minimum.r() < 0.99){
     osgParticle::range<osg::Vec4f> new_range(
       color_range.minimum + osg::Vec4f(SMALL_INCREMENT, 0.0, 0.0, 0.0),
            color_range.maximum
     );
     defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
  }
}

void ParticleSystem::incMinG() {
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.minimum.g() < 0.99){
     osgParticle::range<osg::Vec4f> new_range(
         color_range.minimum + osg::Vec4f(0.0, SMALL_INCREMENT, 0.0, 0.0),
         color_range.maximum
     );
     defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
  }
}

void ParticleSystem::incMinB() {
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.minimum.b() < 0.99){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum + osg::Vec4f(0.0, 0.0, SMALL_INCREMENT, 0.0),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
        particleSystem->setDefaultParticleTemplate(*defaultParticle);
    }

}

void ParticleSystem::
incMaxR(){
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.maximum.r() < 0.99){
     osgParticle::range<osg::Vec4f> new_range(
         color_range.minimum,
         color_range.maximum + osg::Vec4f(SMALL_INCREMENT, 0.0, 0.0, 0.0)
     );
     defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
  }
}

void ParticleSystem::incMaxG() {
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.maximum.g() < 0.99){
     osgParticle::range<osg::Vec4f> new_range(
         color_range.minimum,
         color_range.maximum + osg::Vec4f(0.0, SMALL_INCREMENT, 0.0, 0.0)
     );
     defaultParticle->setColorRange(new_range); 
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
  }
}

void ParticleSystem::incMaxB() {
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.maximum.b() < 0.99){
     osgParticle::range<osg::Vec4f> new_range(
         color_range.minimum,
         color_range.maximum + osg::Vec4f(0.0, 0.0, SMALL_INCREMENT, 0.0)
     );
     defaultParticle->setColorRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
  }
}

void ParticleSystem::decMinR() {
  const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
  if(color_range.minimum.r() > 0.01){
     osgParticle::range<osg::Vec4f> new_range(
         color_range.minimum - osg::Vec4f(SMALL_INCREMENT, 0.0, 0.0, 0.0),
         color_range.maximum
     );
     defaultParticle->setColorRange(new_range);
  }
  else{
     osgParticle::range<osg::Vec4f> new_range(
         osg::Vec4f(
             0.0,
             color_range.minimum.g(),
             color_range.minimum.b(), 
             color_range.minimum.a()
         ),
         color_range.maximum
     );
     defaultParticle->setColorRange(new_range);
  }
  particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

void ParticleSystem::decMinG() {
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.minimum.g() > 0.01){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum - osg::Vec4f(0.0, SMALL_INCREMENT, 0.0, 0.0),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            osg::Vec4f(
                color_range.minimum.r(),
                0.0,
                color_range.minimum.b(), 
                color_range.minimum.a()
            ),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decMinB(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.minimum.b() > 0.01){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum - osg::Vec4f(0.0, 0.0, SMALL_INCREMENT, 0.0),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            osg::Vec4f(
                color_range.minimum.r(),
                color_range.minimum.g(),
                0.0,
                color_range.minimum.a()
            ),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

void ParticleSystem::decMaxR(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.maximum.r() > 0.01){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            color_range.maximum - osg::Vec4f(SMALL_INCREMENT, 0.0, 0.0, 0.0)
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            osg::Vec4f(
                0.0,
                color_range.maximum.g(),
                color_range.maximum.b(),
                color_range.maximum.a()
            )
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decMaxG(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.maximum.g() > 0.01){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            color_range.maximum - osg::Vec4f(0.0, SMALL_INCREMENT, 0.0, 0.0)
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            osg::Vec4f(
                color_range.maximum.r(),
                0.0,
                color_range.maximum.b(),
                color_range.maximum.a()
            )
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decMaxB(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.maximum.b() > 0.01){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            color_range.maximum - osg::Vec4f(0.0, 0.0, SMALL_INCREMENT, 0.0)
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            osg::Vec4f(
                color_range.maximum.r(),
                color_range.maximum.g(),
                0.0,
                color_range.maximum.a()
            )
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

void ParticleSystem::
incMinAlpha(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.minimum.a() < 0.99){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum + osg::Vec4f(0.0, 0.0, 0.0, SMALL_INCREMENT),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
        particleSystem->setDefaultParticleTemplate(*defaultParticle);
    }

}
void ParticleSystem::
incMaxAlpha(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.maximum.a() < 0.99){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            color_range.maximum + osg::Vec4f(0.0, 0.0, 0.0, SMALL_INCREMENT)
        );
        defaultParticle->setColorRange(new_range);
        particleSystem->setDefaultParticleTemplate(*defaultParticle);
    }

}
void ParticleSystem::
decMinAlpha(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.minimum.a() > 0.0){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum - osg::Vec4f(0.0, 0.0, 0.0, SMALL_INCREMENT),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            osg::Vec4f(
                color_range.minimum.r(),
                color_range.minimum.g(),
                color_range.minimum.b(), 
                0.0
            ),
            color_range.maximum
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decMaxAlpha(){
    const osgParticle::range<osg::Vec4f>& color_range = defaultParticle->getColorRange();
    if(color_range.maximum.a() > 0.0){
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            color_range.maximum - osg::Vec4f(0.0, 0.0, 0.0, SMALL_INCREMENT)
        );
        defaultParticle->setColorRange(new_range);
    }
    else{
        osgParticle::range<osg::Vec4f> new_range(
            color_range.minimum,
            osg::Vec4f(
                color_range.maximum.r(),
                color_range.maximum.g(),
                color_range.maximum.b(),
                0.0
            )
        );
        defaultParticle->setColorRange(new_range);
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);

}
osg::Vec4f ParticleSystem::
getMinColor() const{
    return defaultParticle->getColorRange().minimum;
}
osg::Vec4f ParticleSystem::
getMaxColor() const{
    return defaultParticle->getColorRange().maximum;
}
//Particle Size ////////////////////////////////////////////////////////////

void ParticleSystem::setMinSize(float size)
{
	const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
	osgParticle::rangef new_range(size,old_size.maximum);
	 defaultParticle->setSizeRange(new_range);
     particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

void ParticleSystem::setMaxSize(float size)
{
	const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
	osgParticle::rangef new_range(old_size.minimum, size);
	defaultParticle->setSizeRange(new_range);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}


void ParticleSystem::
incMinSize(){
    const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
    osgParticle::rangef new_range(
        old_size.minimum + SMALL_INCREMENT,
        old_size.maximum
    );
    defaultParticle->setSizeRange(new_range);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);    
}
void ParticleSystem::
incMaxSize(){
    const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
    osgParticle::rangef new_range(
        old_size.minimum, 
        old_size.maximum + SMALL_INCREMENT
    );
    defaultParticle->setSizeRange(new_range);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);    
}
void ParticleSystem::
decMinSize(){
    const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
    if(old_size.minimum > 0.01){
        osgParticle::rangef new_range(
            old_size.minimum - SMALL_INCREMENT,
            old_size.maximum
        );
        defaultParticle->setSizeRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            0.0,
            old_size.maximum
        );
        defaultParticle->setSizeRange(new_range);    
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decMaxSize(){
    const osgParticle::rangef& old_size = defaultParticle->getSizeRange();
    if(old_size.maximum > 0.01){
        osgParticle::rangef new_range(
            old_size.minimum, 
            old_size.maximum - SMALL_INCREMENT
        );
        defaultParticle->setSizeRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            old_size.minimum,
            0.0
        );
        defaultParticle->setSizeRange(new_range);    
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
osgParticle::rangef ParticleSystem::
getSize() const{
    return defaultParticle->getSizeRange();
}

//Particle Shape ///////////////////////////////////////////////////////////
void ParticleSystem::
setShapePoint(){
    defaultParticle->setShape(osgParticle::Particle::POINT);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
setShapeQuad(){
    defaultParticle->setShape(osgParticle::Particle::QUAD);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
setShapeQuadTriangle(){
    defaultParticle->setShape(osgParticle::Particle::QUAD_TRIANGLESTRIP);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
setShapeHex(){
    defaultParticle->setShape(osgParticle::Particle::HEXAGON);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
setShapeLine(){
    defaultParticle->setShape(osgParticle::Particle::LINE);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}

string ParticleSystem::
getShape() const{
    osgParticle::Particle::Shape current_shape = defaultParticle->getShape();
    switch(current_shape){
        case osgParticle::Particle::POINT:              return "POINT";
        case osgParticle::Particle::QUAD:               return "QUAD";
        case osgParticle::Particle::QUAD_TRIANGLESTRIP: return "QUAD_TRIANGLESTRIP";
        case osgParticle::Particle::HEXAGON:            return "HEXAGON";
        case osgParticle::Particle::LINE:               return "LINE";
        default:                                        return "UNKNOWN";
    };
}

//Particle Lifetime ////////////////////////////////////////////////////////

void ParticleSystem::setLifeTime(float time)
{
	defaultParticle->setLifeTime(time);
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
incLifetime(){
    defaultParticle->setLifeTime(
        defaultParticle->getLifeTime() + MEDIUM_INCREMENT
    );
    particleSystem->setDefaultParticleTemplate(*defaultParticle);
}
void ParticleSystem::
decLifetime(){
    if(defaultParticle->getLifeTime() > 0.1){
        defaultParticle->setLifeTime(
            defaultParticle->getLifeTime() - MEDIUM_INCREMENT
        );
    }
    else{
        defaultParticle->setLifeTime(
            0.01
        );
    }
    particleSystem->setDefaultParticleTemplate(*defaultParticle);    
}

double ParticleSystem::
getLifetime() const{
    return defaultParticle->getLifeTime();
}

//Particle Alignment ///////////////////////////////////////////////////////////
void ParticleSystem::
setAlignmentFixed(){
    particleSystem->setParticleAlignment(osgParticle::ParticleSystem::FIXED);
}
void ParticleSystem::
setAlignmentBillboard(){
    particleSystem->setParticleAlignment(osgParticle::ParticleSystem::BILLBOARD);
}

string ParticleSystem::
getAlignment() const{
    osgParticle::ParticleSystem::Alignment current_alignment = particleSystem->getParticleAlignment();
    switch(current_alignment){
        case osgParticle::ParticleSystem::FIXED:        return "FIXED";
        case osgParticle::ParticleSystem::BILLBOARD:    return "BILLBOARD";
        default:                                        return "UNKNOWN";
    };
}

//Particle Count ///////////////////////////////////////////////////////////
void ParticleSystem::setMinRate(float rate){
	const osgParticle::rangef& old_range = rateCounter->getRateRange();
    osgParticle::rangef new_range(
        rate,
        old_range.maximum
    );
    rateCounter->setRateRange(new_range);
	
}
void ParticleSystem::setMaxRate(float rate){
	const osgParticle::rangef& old_range = rateCounter->getRateRange();
    osgParticle::rangef new_range(
        old_range.minimum,
        rate
    );
    rateCounter->setRateRange(new_range);
	
}

void ParticleSystem::
incMinRate(){
    const osgParticle::rangef& old_range = rateCounter->getRateRange();
    osgParticle::rangef new_range(
        old_range.minimum + LARGE_INCREMENT,
        old_range.maximum
    );
    rateCounter->setRateRange(new_range);
}
void ParticleSystem::
incMaxRate(){
    const osgParticle::rangef& old_range = rateCounter->getRateRange();
    osgParticle::rangef new_range(
        old_range.minimum,
        old_range.maximum + LARGE_INCREMENT
    );
    rateCounter->setRateRange(new_range);
}
void ParticleSystem::
decMinRate(){
    const osgParticle::rangef& old_range = rateCounter->getRateRange();
    if(old_range.minimum > 1.0){
        osgParticle::rangef new_range(
            old_range.minimum - LARGE_INCREMENT,
            old_range.maximum
        );
        rateCounter->setRateRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            0.0,
            old_range.maximum
        );
        rateCounter->setRateRange(new_range);
    }
}
void ParticleSystem::
decMaxRate(){
    const osgParticle::rangef& old_range = rateCounter->getRateRange();
    if(old_range.maximum > 1.0){
        osgParticle::rangef new_range(
            old_range.minimum,
            old_range.maximum - LARGE_INCREMENT
        );
        rateCounter->setRateRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            old_range.minimum,
            0.0
        );
        rateCounter->setRateRange(new_range);    
    }
}

osgParticle::rangef ParticleSystem::
getRate() const{
    return rateCounter->getRateRange();
}

//Particle Theta ///////////////////////////////////////////////////////////
void ParticleSystem::
setMinTheta(float theta){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    osgParticle::rangef new_range(
      theta,
        old_range.maximum
    );
    shooter->setThetaRange(new_range);
}
void ParticleSystem::
setMaxTheta(float theta){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    osgParticle::rangef new_range(
     	old_range.minimum,theta);
    shooter->setThetaRange(new_range);
}



void ParticleSystem::
incMinTheta(){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    osgParticle::rangef new_range(
        old_range.minimum + SMALL_INCREMENT,
        old_range.maximum
    );
    shooter->setThetaRange(new_range);
}
void ParticleSystem::
incMaxTheta(){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    osgParticle::rangef new_range(
        old_range.minimum,
        old_range.maximum + SMALL_INCREMENT
    );
    shooter->setThetaRange(new_range);
}
void ParticleSystem::
decMinTheta(){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    if(old_range.minimum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum - SMALL_INCREMENT,
            old_range.maximum
        );
        shooter->setThetaRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            0.0,
            old_range.maximum
        );
        shooter->setThetaRange(new_range);    
    }

}
void ParticleSystem::
decMaxTheta(){
    const osgParticle::rangef& old_range = shooter->getThetaRange();
    if(old_range.maximum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum,
            old_range.maximum - SMALL_INCREMENT
        );
        shooter->setThetaRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            old_range.minimum,
            0.0
        );
        shooter->setThetaRange(new_range);    
    }
}

osgParticle::rangef ParticleSystem::
getTheta() const{
    return shooter->getThetaRange();
}

//Particle Phi ///////////////////////////////////////////////////////////
void ParticleSystem::
setMinPhi(float phi){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    osgParticle::rangef new_range(
     	phi,	old_range.maximum);
    shooter->setPhiRange(new_range);
}
void ParticleSystem::setMaxPhi(float phi){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    osgParticle::rangef new_range(
    old_range.minimum,phi);
    shooter->setPhiRange(new_range);
}
void ParticleSystem::
incMinPhi(){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    osgParticle::rangef new_range(
        old_range.minimum + SMALL_INCREMENT,
        old_range.maximum
    );
    shooter->setPhiRange(new_range);
}
void ParticleSystem::
incMaxPhi(){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    osgParticle::rangef new_range(
        old_range.minimum,
        old_range.maximum + SMALL_INCREMENT
    );
    shooter->setPhiRange(new_range);
}
void ParticleSystem::
decMinPhi(){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    if(old_range.minimum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum - SMALL_INCREMENT,
            old_range.maximum
        );
        shooter->setPhiRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            0.0,
            old_range.maximum
        );
        shooter->setPhiRange(new_range);    
    }
}


void ParticleSystem::decMaxPhi(){
    const osgParticle::rangef& old_range = shooter->getPhiRange();
    if(old_range.maximum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum,
            old_range.maximum - SMALL_INCREMENT
        );
        shooter->setPhiRange(new_range);
    }
    else{
    osgParticle::rangef new_range(
            old_range.minimum,
            0.0
        );
        shooter->setPhiRange(new_range);    
    }
}

osgParticle::rangef ParticleSystem::getPhi() const{
    return shooter->getPhiRange();
}
void ParticleSystem::setMinSpeed(float speed){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    osgParticle::rangef new_range(
     speed,
     old_range.maximum
    );
    shooter->setInitialSpeedRange(new_range);
}
void ParticleSystem::setMaxSpeed(float speed){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    osgParticle::rangef new_range(old_range.minimum,speed);
    shooter->setInitialSpeedRange(new_range);
}





void ParticleSystem::incMinSpeed(){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    osgParticle::rangef new_range(
        old_range.minimum + SMALL_INCREMENT,
        old_range.maximum
    );
    shooter->setInitialSpeedRange(new_range);
}
void ParticleSystem::incMaxSpeed(){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    osgParticle::rangef new_range(
        old_range.minimum,
        old_range.maximum + SMALL_INCREMENT
    );
    shooter->setInitialSpeedRange(new_range);
}

void ParticleSystem::decMinSpeed(){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    if(old_range.minimum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum - SMALL_INCREMENT,
            old_range.maximum
        );
        shooter->setInitialSpeedRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            0.0,
            old_range.maximum
        );
        shooter->setInitialSpeedRange(new_range);    
    }
}

void ParticleSystem::decMaxSpeed(){
    const osgParticle::rangef& old_range = shooter->getInitialSpeedRange();
    if(old_range.maximum > 0.01){
        osgParticle::rangef new_range(
            old_range.minimum,
            old_range.maximum - SMALL_INCREMENT
        );
        shooter->setInitialSpeedRange(new_range);
    }
    else{
        osgParticle::rangef new_range(
            old_range.minimum,
            0.0
        );
        shooter->setInitialSpeedRange(new_range);    
    }
}

osgParticle::rangef ParticleSystem::getSpeed() const{
    return shooter->getInitialSpeedRange();
}

