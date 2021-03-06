/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef _VCL_UNOWRAP_HXX
#define _VCL_UNOWRAP_HXX

#include <tools/solar.h>
#include <vcl/dllapi.h>
#include <com/sun/star/uno/Reference.h>

class XWindowPeer;
class XToolkit; 
class XVclToolkit; 
class EventList; 
class Window;
class OutputDevice; 
class MouseEvent;
class CommandEvent;
class KeyEvent;
class Rectangle;
class XVclComponentPeer;
class Menu; 

namespace com {
namespace sun {
namespace star {
namespace awt {
	class XGraphics;
	class XToolkit;
	class XWindowPeer;
}
namespace lang {
	class XMultiServiceFactory;
}
} } }

namespace com {
namespace sun {
namespace star {
namespace accessibility {
    class XAccessible;
}}}}

class VCL_DLLPUBLIC UnoWrapperBase
{
public:	
	virtual void 				Destroy() = 0;

	// Toolkit
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::awt::XToolkit > GetVCLToolkit() = 0;

	// Graphics
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::awt::XGraphics >	CreateGraphics( OutputDevice* pOutDev ) = 0;
	virtual void				ReleaseAllGraphics( OutputDevice* pOutDev ) = 0;

	// Window
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindowPeer> GetWindowInterface( Window* pWindow, sal_Bool bCreate ) = 0;
	virtual void				SetWindowInterface( Window* pWindow, ::com::sun::star::uno::Reference< ::com::sun::star::awt::XWindowPeer > xIFace ) = 0;

	virtual void				WindowDestroyed( Window* pWindow ) = 0;

	// Accessibility
	virtual ::com::sun::star::uno::Reference< ::com::sun::star::accessibility::XAccessible >
								CreateAccessible( Menu* pMenu, sal_Bool bIsMenuBar ) = 0;
};

#endif	// _VCL_UNOWRAP_HXX
