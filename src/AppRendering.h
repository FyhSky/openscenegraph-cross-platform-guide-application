
/*
This file is part of OpenSceneGraph cross-platform guide:
  https://github.com/OGStudio/openscenegraph-cross-platform-guide

Copyright (C) 2017 Opensource Game Studio

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef OPENSCENEGRAPH_CROSS_PLATFORM_GUIDE_APP_RENDERING_H
#define OPENSCENEGRAPH_CROSS_PLATFORM_GUIDE_APP_RENDERING_H

#include "Rendering.h"

#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>

// Base class to manager application rendering.
// Use platform specific derivatives.
class AppRendering
{
    public:
        void frame()
        {
            mViewer->frame();
        }
        void setScene(osg::Node *scene)
        {
            mViewer->setSceneData(scene);
        }

    protected:
        AppRendering()
        {
            // Create OpenSceneGraph viewer.
            mViewer = new osgViewer::Viewer;
            // Use single thread: CRITICAL for web.
            // TODO: Move to specific platform?
            mViewer->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
            // Create manipulator: CRITICAL for mobile.
            // TODO: Move to specific platform?
            mViewer->setCameraManipulator(new osgGA::TrackballManipulator);
        }
        virtual ~AppRendering()
        {
            // Tear down the viewer.
            delete mViewer;
        }

    protected:
        osgViewer::Viewer *mViewer;
};

#endif // OPENSCENEGRAPH_CROSS_PLATFORM_GUIDE_APP_RENDERING_H

