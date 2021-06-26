#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>

using namespace ci;
using namespace ci::app;

class BasicApp : public App {
  public:
	void draw() override;
};

void BasicApp::draw(){
	gl::clear();

    gl::enableDepthRead();
    gl::enableDepthWrite();

    CameraPersp camera;
    camera.lookAt(vec3(3, 3, 3), vec3());
    gl::setMatrices(camera);

    auto lambert = gl::ShaderDef().lambert();
    auto shader = gl::getStockShader(lambert);
    shader->bind();

    //gl::drawCube(vec3(), vec3(2));
    gl::drawSphere(vec3(), 1.0, 40);
}

CINDER_APP( BasicApp, RendererGl )
